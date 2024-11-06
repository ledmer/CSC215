
# Guide to Uploading Files to the Altair-Duino with MITS Disk Images

This guide provides step-by-step instructions to create, format, and upload `.DSK` disk images to your Altair-Duino using a specific MITS-compatible naming convention.

---

## Table of Contents
1. [Requirements](#requirements)
2. [Step 1: Create the Disk Image with Correct Naming](#step-1-create-the-disk-image-with-correct-naming)
3. [Step 2: Format the Disk Image](#step-2-format-the-disk-image)
4. [Step 3: Add Files to the MITS Disk Image](#step-3-add-files-to-the-mits-disk-image)
5. [Step 4: Load the Disk Image onto the Altair-Duino](#step-4-load-the-disk-image-onto-the-altair-duino)
6. [Troubleshooting](#troubleshooting)

---

## Requirements

To complete this process, you’ll need:
- **Altair-Duino**: Connected to your computer with a micro SD card slot.
- **altair_tools**: A utility for creating and managing MITS-compatible `.DSK` images, available at [altair_tools GitHub repository](https://github.com/phatchman/altair_tools).
- **Terminal emulator**: PuTTY or similar to interact with the Altair-Duino.

---

## Step 1: Create the Disk Image with Correct Naming

MITS disk images require specific naming: `CDISK**.DSK`, where `**` is a two-digit hexadecimal number (e.g., `CDISK01.DSK`).

1. **Choose a Disk Number**: Decide on the two-digit hex number for your disk (e.g., `01` for the first disk).
2. **Create a Disk Image with the Correct Name**:
   ```bash
   altair_tools create CDISK01.DSK
   ```
   This will create a blank MITS-compatible `.DSK` image with the appropriate naming.

---

## Step 2: Format the Disk Image

With `altair_tools`, you can format the `.DSK` file for MITS CP/M compatibility.

1. **Format the Disk Image**:
   ```bash
   altair_tools format CDISK01.DSK
   ```
   This ensures compatibility with MITS CP/M, verified for CP/M version 2.2mits.

---

## Step 3: Add Files to the MITS Disk Image

With the disk image created and formatted, you can add files to it using `altair_tools`.

1. **List Directory Contents**:
   ```bash
   altair_tools dir CDISK01.DSK
   ```
   This lists the contents of the `.DSK` image to verify it’s ready for new files.

2. **Add Files to the Disk Image**:
   ```bash
   altair_tools write CDISK01.DSK localfile.ext REMOTEFILE.EXT
   ```
   Replace `localfile.ext` with the file from your computer and `REMOTEFILE.EXT` with the name on the disk image.

3. **Read Files (Optional)**: 
   To retrieve files from the disk image, use:
   ```bash
   altair_tools read CDISK01.DSK REMOTEFILE.EXT localfile.ext
   ```

---

## Step 4: Load the Disk Image onto the Altair-Duino

1. **Insert the SD Card**: Place the micro SD card into your computer.

2. **Copy the Disk Image to the SD Card**:
   - Ensure `CDISK01.DSK` is copied to the SD card root directory, as needed by the Altair-Duino.

3. **Insert the SD Card into the Altair-Duino**.

4. **Access the Disk Image**:
   - Use your terminal emulator (e.g., PuTTY) to connect to the Altair-Duino.
   - Boot the disk image while SW 12 up setup the SW's as needed to match the hex number of the file (other switches need to be down)
   - AUX 2 down to load the disk.
   - To run bootable disk – switch 3 up (all others down).
   - AUX1 down.


5. **Verify Files**: Run a directory listing (e.g., `DIR` in CP/M) to confirm the files are correctly loaded on the Altair-Duino.

---

## Troubleshooting

- **Disk Image Not Recognized**:
  - Confirm the `.DSK` file is formatted and populated with files correctly using `altair_tools`.
- **Files Not Accessible**:
  - Ensure files were added using MITS-compatible formats (e.g., CP/M format for compatibility).
- **Repair SD card**:
   - If your SD card is broken, unusable or just want to reset it to default, go to the <a href="https://github.com/ledmer/CSC215/blob/main/presentations/AltairDuino/Configuration_menu.md">Configuration_Menu.md</a>.
