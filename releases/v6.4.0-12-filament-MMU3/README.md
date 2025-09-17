# Prusa MK4S 12-Filament MMU3 Firmware v6.4.0-alpha

## 🎯 **What is this?**

This is a **modified Prusa Firmware 6.4.0-alpha** that adds **12-filament support** for the Prusa MK4S with MMU3 unit.

## ✨ **Features**

- ✅ **12 filament slots** instead of the standard 5
- ✅ **Proper GUI display** showing tools 01-12 with consistent 2-digit formatting  
- ✅ **Complete MMU configuration** based on proven cjbaar 12-tool hardware parameters
- ✅ **Temperature handling** for all 12 extruders
- ✅ **All original 6.4.0-alpha features** preserved

## 📦 **Files**

- **`firmware-mk4s-12-filament-mmu3-v6.4.0+11775.bbf`** - Main firmware file for flashing via USB/PrusaLink
- **`firmware-mk4s-12-filament-mmu3-v6.4.0+11775.bin`** - Binary firmware file for advanced users

## 🚨 **Compatibility**

- **Printer**: Prusa MK4S only
- **MMU**: MMU3 unit required
- **Hardware**: Must have 12-slot MMU3 hardware modification
- **Original firmware**: Based on official Prusa Firmware 6.4.0-alpha

## 🛠️ **Hardware Requirements**

This firmware is designed for custom 12-slot MMU3 hardware modifications. Standard 5-slot MMU3 units will not work correctly with this firmware.

Required hardware modifications include:
- Extended selector mechanism for 12 positions
- Proper slot spacing (6.06mm based on cjbaar config)
- Extended idler mechanism
- Longer filament path management

## 📋 **Technical Details**

- **Version**: 6.4.0+11775
- **Build**: Release with bootloader
- **Base**: Official Prusa Firmware 6.4.0-alpha
- **MMU Config**: Based on proven cjbaar 12-tool parameters
- **Memory Usage**: 91.16% flash, 56.17% RAM
- **SHA256**: `ed66b8d82863563432bf5f24f932b412ac91849f1304c0745fad8e400d1783a1`

## 🤝 **Credits**

- **Base Firmware**: Prusa Research (Prusa Firmware 6.4.0-alpha)
- **12-tool MMU3 Hardware**: Based on cjbaar's proven configuration
- **Display Formatting**: Fixed 2-digit tool display across all GUI elements
- **Integration**: Custom modifications for 12-filament support

## ⚠️ **Disclaimer**

This is modified firmware based on official Prusa sources. Use at your own risk. Always have a backup plan to restore original firmware if needed.

## 📄 **License**

This firmware maintains the same license as the original Prusa Firmware. See the original repository for license details.
