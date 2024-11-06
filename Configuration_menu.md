# Simulator Configuration Menu

The simulator configuration menu can be accessed by holding **STOP** up and raising **AUX1**. The settings available are as follows:

### 1. Enable Profiling
- If enabled and the simulator is running (i.e., not in STOP mode), a message showing the current performance of the simulator is written to the primary serial output.

### 2. Set Throttle Delay (Arduino Due Only)
- Allows throttling of the simulator performance. Throttling is done by busy-waiting, i.e., an empty loop counting down from the selected value to zero.
- If set to **"auto adjust"**, the simulator evaluates performance about 40 times per second and adjusts the throttle delay to approximate 100% of the original 2MHz clock frequency.
- When profiling is also enabled, the effect of throttle delay changes can be observed.

### 3. Enable Serial Panel
- Shows a simple representation of the front panel lights and switches on the primary serial output.
- Mostly useful when **STANDALONE** mode is enabled.

### 4. Enable Serial Input
- When stopped, the simulator processes inputs as described in the **Debugging Capabilities** section.

### 5. Enable Serial Debug
- Prints processor status and disassembled opcode during single stepping.

### 6. Processor (only if Processor Switching is Enabled in `config.h`)
- Switch between Intel 8080 and Zilog Z80 processor.

### 7. Configure Memory
- See the **Memory Configuration** section for details.

### 8. Aux1 Shortcut Program
- Sets the program to be run when the **AUX1** switch is raised. This can be any built-in program available via **AUX1** down or a disk.
- If a disk is selected, pushing up **AUX1** will mount the disk and then install and run the disk boot loader.

### 9. Configure Host Serial
- See the **Host Serial Interface Configuration** section for details.

### 10. Configure Serial Cards
- See the **Serial Device Configuration** section for details.

### 11. Configure Printer
- See the **Printer Configuration** section for details.

### 12. Configure Disk Drives (only if Disk Drive Emulation is Enabled in `config.h`)
- See the **Disk Drive Configuration** section for details.

### 13. Configure Hard Disks (only if Hard Disk Emulation is Enabled in `config.h`)
- See the **Hard Disk Configuration** section for details.

### 14. Configure Dazzler (only if Dazzler Emulation is Enabled in `config.h`)
- See the **Cromemco Dazzler Support** section.

### 15. Configure VDM-1 (only if VDM-1 Emulation is Enabled in `config.h`)
- See the **VDM-1 Support** section.

### 16. Configure Interrupts
- See the **Interrupts Configuration** section for details.

### 17. Manage Filesystem
- Starts the file system manager. See the **File System Manager** section for details.

### 18. File System Manager for SD Card (only if SD Card is Attached)
- Starts a file system manager to modify the contents of the SD card.
- The file manager allows transferring files to and from the card via the XMODEM protocol.

### 19. Save Configuration
- Saves the current configuration. Up to 256 different configurations can be saved.
- **Configuration #0** is automatically loaded when the simulator starts.

### 20. Load Configuration
- Loads a saved configuration.

### 21. Reset to Defaults
- Resets all settings to their default values.
