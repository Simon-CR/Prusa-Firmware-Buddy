/**
 * Marlin 3D Printer Firmware
 * Copyright (c) 2019 MarlinFirmware [https://github.com/MarlinFirmware/Marlin]
 *
 * Based on Sprinter and grbl.
 * Copyright (c) 2011 Camiel Gubbels / Erik van der Zalm
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 */

#include "../../inc/MarlinConfig.h"

#include "../gcode.h"
#include "../../module/motion.h"
#include "../../module/stepper.h"

#if ENABLED(M114_DETAIL)

  #if HAS_DRIVER(L6470)
    //C:\Users\bobku\Documents\GitHub\Marlin-Bob-2\Marlin\src\gcode\host\M114.cpp
    //C:\Users\bobku\Documents\GitHub\Marlin-Bob-2\Marlin\src\module\bob_L6470.cpp
    #include "../../libs/L6470/L6470_Marlin.h"
    #define DEBUG_OUT ENABLED(L6470_CHITCHAT)
    #include "../../core/debug_out.h"
  #endif

  void report_xyze(const xyze_pos_t &pos, const uint8_t n=4, const uint8_t precision=3) {
    char str[12];
    for (uint8_t a = 0; a < n; a++) {
      SERIAL_CHAR(' ');
      SERIAL_CHAR(axis_codes[a]);
      SERIAL_CHAR(':');
      SERIAL_ECHO(dtostrf(pos[a], 1, precision, str));
    }
    SERIAL_EOL();
  }

  void report_xyz(const xyz_pos_t &pos, const uint8_t precision=3) {
    char str[12];
    for (uint8_t a = X_AXIS; a <= Z_AXIS; a++) {
      SERIAL_CHAR(' ');
      SERIAL_CHAR(axis_codes[a]);
      SERIAL_CHAR(':');
      SERIAL_ECHO(dtostrf(pos[a], 1, precision, str));
    }
    SERIAL_EOL();
  }
  inline void report_xyz(const xyze_pos_t &pos) { report_xyze(pos, 3); }

  void report_current_position_detail() {

    SERIAL_ECHOPGM("\nLogical:");
    report_xyz(current_position.asLogical());

    SERIAL_ECHOPGM("Raw:    ");
    report_xyz(current_position);

    xyze_pos_t leveled = current_position;

    #if HAS_LEVELING
      SERIAL_ECHOPGM("Leveled:");
      planner.apply_leveling(leveled);
      report_xyz(leveled);

      SERIAL_ECHOPGM("UnLevel:");
      xyze_pos_t unleveled = leveled;
      planner.unapply_leveling(unleveled);
      report_xyz(unleveled);
    #endif

    #if IS_KINEMATIC
      #if IS_SCARA
        SERIAL_ECHOPGM("ScaraK: ");
      #else
        SERIAL_ECHOPGM("DeltaK: ");
      #endif
      inverse_kinematics(leveled);  // writes delta[]
      report_xyz(delta);
    #endif

    planner.synchronize();

    #if HAS_DRIVER(L6470)
      char temp_buf[80];
      int32_t temp;
      //#define ABS_POS_SIGN_MASK 0b1111 1111 1110 0000 0000 0000 0000 0000
      #define ABS_POS_SIGN_MASK 0b11111111111000000000000000000000
      #define REPORT_ABSOLUTE_POS(Q) do{                            \
          L6470.say_axis(Q, false);                                 \
          temp = L6470_GETPARAM(L6470_ABS_POS,Q);                   \
          if (temp & ABS_POS_SIGN_MASK) temp |= ABS_POS_SIGN_MASK;  \
          sprintf_P(temp_buf, PSTR(":%8ld   "), temp);              \
          DEBUG_ECHO(temp_buf);                                     \
        }while(0)

      DEBUG_ECHOPGM("\nL6470:");
      #if AXIS_DRIVER_TYPE_X(L6470)
        REPORT_ABSOLUTE_POS(X);
      #endif
      #if AXIS_DRIVER_TYPE_X2(L6470)
        REPORT_ABSOLUTE_POS(X2);
      #endif
      #if AXIS_DRIVER_TYPE_Y(L6470)
        REPORT_ABSOLUTE_POS(Y);
      #endif
      #if AXIS_DRIVER_TYPE_Y2(L6470)
        REPORT_ABSOLUTE_POS(Y2);
      #endif
      #if AXIS_DRIVER_TYPE_Z(L6470)
        REPORT_ABSOLUTE_POS(Z);
      #endif
      #if AXIS_DRIVER_TYPE_Z2(L6470)
        REPORT_ABSOLUTE_POS(Z2);
      #endif
      #if AXIS_DRIVER_TYPE_Z3(L6470)
        REPORT_ABSOLUTE_POS(Z3);
      #endif
      #if AXIS_DRIVER_TYPE_E0(L6470)
        REPORT_ABSOLUTE_POS(E0);
      #endif
      #if AXIS_DRIVER_TYPE_E1(L6470)
        REPORT_ABSOLUTE_POS(E1);
      #endif
      #if AXIS_DRIVER_TYPE_E2(L6470)
        REPORT_ABSOLUTE_POS(E2);
      #endif
      #if AXIS_DRIVER_TYPE_E3(L6470)
        REPORT_ABSOLUTE_POS(E3);
      #endif
      #if AXIS_DRIVER_TYPE_E4(L6470)
        REPORT_ABSOLUTE_POS(E4);
      #endif
      #if AXIS_DRIVER_TYPE_E5(L6470)
        REPORT_ABSOLUTE_POS(E5);
      #endif
      SERIAL_EOL();
    #endif // HAS_DRIVER(L6470)

    SERIAL_ECHOPGM("Stepper:");
    LOOP_XYZE(i) {
      SERIAL_CHAR(' ');
      SERIAL_CHAR(axis_codes[i]);
      SERIAL_CHAR(':');
      SERIAL_ECHO(stepper.position((AxisEnum)i));
    }
    SERIAL_EOL();

    #if IS_SCARA
      const xy_float_t deg = {
        planner.get_axis_position_degrees(A_AXIS),
        planner.get_axis_position_degrees(B_AXIS)
      };
      SERIAL_ECHOPGM("Degrees:");
      report_xyze(deg, 2);
    #endif

    SERIAL_ECHOPGM("FromStp:");
    get_cartesian_from_steppers();  // writes 'cartes' (with forward kinematics)
    xyze_pos_t from_steppers = { cartes.x, cartes.y, cartes.z, planner.get_axis_position_mm(E_AXIS) };
    report_xyze(from_steppers);

    const xyze_float_t diff = from_steppers - leveled;
    SERIAL_ECHOPGM("Diff: ");
    report_xyze(diff);
  }

#endif // M114_DETAIL

/** \addtogroup G-Codes
 * @{
 */

/**
 *### M114: Report current position to host <a href="https://reprap.org/wiki/G-code#M114:_Get_Current_Position">M114: Get Current Position</a>
 *
 *#### Usage
 *
 *    M114 [ D ]
 *
 *#### Parameters
 *
 * - `D` - Detailed (not active)
 */
void GcodeSuite::M114() {

  #if ENABLED(M114_DETAIL)
    if (parser.seen('D')) {
      report_current_position_detail();
      return;
    }
  #endif

  planner.synchronize();
  report_current_position();
}

/** @}*/
