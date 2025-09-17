# Prusa MK3.5 Family 12-Filament MMU3 Firmware v6.4.0-alpha

## 🎯 **What is this?**

This is a **modified Prusa Firmware 6.4.0-alpha** that adds **12-filament support** for the Prusa MK3.5 family printers with MMU3 unit.

## ✨ **Features**

- ✅ **12 filament slots** instead of the standard 5
- ✅ **Proper GUI display** showing tools 01-12 with consistent 2-digit formatting  
- ✅ **Complete MMU configuration** based on proven cjbaar 12-tool hardware parameters
- ✅ **Temperature handling** for all 12 extruders
- ✅ **All original 6.4.0-alpha features** preserved
- ✅ **Optimized memory usage** - fits comfortably within MK3.5 limits

## 📦 **Files**

- **`firmware-mk3.5-12-filament-mmu3-v6.4.0+11776.bbf`** - Main firmware file for flashing via USB/PrusaLink
- **`firmware-mk3.5-12-filament-mmu3-v6.4.0+11776.bin`** - Binary firmware file for advanced users

## 🚨 **Compatibility**

### Supported Printers (MK3.5 Family)
- **✅ Prusa MK3.5** - Compatible via Extended Printer Type system
- **✅ Prusa MK3.5S** - Compatible via Extended Printer Type system

**Note**: This build was compiled specifically for MK3.5 family and has **NOT been physically tested**. It should work based on firmware compatibility architecture, but use with caution.

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

### MK3.5 Family Build
- **Version**: 6.4.0+11776
- **Build**: Release with bootloader
- **Base**: Official Prusa Firmware 6.4.0-alpha
- **MMU Config**: Based on proven cjbaar 12-tool parameters
- **Memory Usage**: 83.82% flash, 53.79% RAM, 97.41% CCMRAM
- **SHA256**: `ca49d555ade458710e5f80e6ebd27d484addb62b3d88181a84c7e88de7dfe077`
- **Testing Status**: ⚠️ **Compiled but not physically tested**

### Architecture Notes
- Uses Prusa's Extended Printer Type system for automatic detection
- MK3.5 and MK3.5S share the same firmware binary
- Single firmware supports both variants through runtime detection
- Much better memory efficiency compared to Core One builds

### Memory Comparison
- **MK3.5**: 97.41% CCMRAM usage ✅ **Fits comfortably**
- **Core One**: 103.14% CCMRAM usage ❌ **Overflows by 2KB**
- **MK4**: 98%+ CCMRAM usage ✅ **Just fits**

## 🤝 **Credits**

- **Base Firmware**: Prusa Research (Prusa Firmware 6.4.0-alpha)
- **12-tool MMU3 Hardware**: Based on cjbaar's proven configuration
- **Display Formatting**: Fixed 2-digit tool display across all GUI elements
- **Integration**: Custom modifications for 12-filament support

## ⚠️ **Disclaimer**

This is modified firmware based on official Prusa sources. **This build has not been physically tested** on MK3.5 hardware. Use at your own risk. Always have a backup plan to restore original firmware if needed.

**Recommendation**: Test thoroughly with non-critical prints before relying on this firmware for important projects.

## 📄 **License**

This firmware maintains the same license as the original Prusa Firmware. See the original repository for license details.
