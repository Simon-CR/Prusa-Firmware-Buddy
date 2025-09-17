# Prusa MK4 Family 12-Filament MMU3 Firmware v6.4.0-alpha

## 🎯 **What is this?**

This is a **modified Prusa Firmware 6.4.0-alpha** that adds **12-filament support** for the Prusa MK4 family printers with MMU3 unit.

## ✨ **Features**

- ✅ **12 filament slots** instead of the standard 5
- ✅ **Proper GUI display** showing tools 01-12 with consistent 2-digit formatting  
- ✅ **Complete MMU configuration** based on proven cjbaar 12-tool hardware parameters
- ✅ **Temperature handling** for all 12 extruders
- ✅ **All original 6.4.0-alpha features** preserved

## 📦 **Files**

### MK4 Family (Current Release)
- **`firmware-mk4s-12-filament-mmu3-v6.4.0+11775.bbf`** - Main firmware file for flashing via USB/PrusaLink
- **`firmware-mk4s-12-filament-mmu3-v6.4.0+11775.bin`** - Binary firmware file for advanced users

### MK3.5 Family (Coming Soon)
- MK3.5 and MK3.5S builds will be available in a separate release

## 🚨 **Compatibility**

### Supported Printers (MK4 Family)
- **✅ Prusa MK4** - Compatible via Extended Printer Type system
- **✅ Prusa MK4S** - **Tested and verified** ⭐
- **✅ Prusa MK3.9** - Compatible via Extended Printer Type system  
- **✅ Prusa MK3.9S** - Compatible via Extended Printer Type system

**Note**: This build was **tested on MK4S only**. Other MK4 family printers (MK4, MK3.9, MK3.9S) should work due to firmware compatibility architecture, but have not been physically tested.

### Requirements
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

### MK4 Family Build
- **Version**: 6.4.0+11775
- **Build**: Release with bootloader
- **Base**: Official Prusa Firmware 6.4.0-alpha
- **MMU Config**: Based on proven cjbaar 12-tool parameters
- **Memory Usage**: 91.16% flash, 56.17% RAM
- **SHA256**: `ed66b8d82863563432bf5f24f932b412ac91849f1304c0745fad8e400d1783a1`
- **Testing Status**: ⭐ **Verified on MK4S**, compatible with MK4/MK3.9/MK3.9S via Extended Printer Type system

### Architecture Notes
- Uses Prusa's Extended Printer Type system for automatic motor detection
- MK4/MK4S use 400-step motors, MK3.9/MK3.9S use 200-step motors
- Single firmware binary supports all variants through runtime detection

## 🤝 **Credits**

- **Base Firmware**: Prusa Research (Prusa Firmware 6.4.0-alpha)
- **12-tool MMU3 Hardware**: Based on cjbaar's proven configuration
- **Display Formatting**: Fixed 2-digit tool display across all GUI elements
- **Integration**: Custom modifications for 12-filament support

## ⚠️ **Disclaimer**

This is modified firmware based on official Prusa sources. Use at your own risk. Always have a backup plan to restore original firmware if needed.

## 📄 **License**

This firmware maintains the same license as the original Prusa Firmware. See the original repository for license details.
