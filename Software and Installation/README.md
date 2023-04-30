# Installing software for the GlowDuino boards

## Arduino IDE integration

The files in the **IDE files** folder can be used to add the GlowDuino boards to the Arduino IDE enviroment.
Entries for **GlowDuino Boards** will appear in the **Boards** menu
when you do this.

For most people, we recommend setting up Arduino IDE by
installing our boards package through the Boards Manager.

1.  In the Arduino IDE, open the **File** menu (Windows/Linux) or the
    **Arduino** menu (macOS) and select "Preferences".

2.  In the Preferences dialog, find the "Additional Boards Manager URLs" text
    box. Copy and paste the following URL into this box:

    **`https://raw.githubusercontent.com/GlowDuino/GlowDuino/main/Software%20and%20Installation/IDE%20files/package_GlowDuino_index.json`**

    If there are already other URLs in the box, you can either add this one
    separated by a comma or click the button next to the box to open an input
    dialog where you can add the URL on a new line.

3.  Click the "OK" button to close the Preferences dialog.

4.  In the **Tools > Board** menu, select "Boards Manager..." (at the top of the
    menu).

5.  In the Boards Manager dialog, search for "GlowDuino Boards".

6.  Select the "GlowDuino Boards" entry in the list, and click the
    "Install" button.
	
## USB driver installation

In case your computer does not already have drivers for the CH340 serial chip, you will need to
install it manually.

Before installing the driver, check if your GlowDuino board needs it. Check your board variant
on the underside of the board: If it says **CH340 variant**, then you need to install drivers.

Drivers can be downloaded from the **Drivers** folder

### Windows

1.  Download the **CH340_Windows_driver.zip** file.

2.  Unzip the downloaded file

3.  Run the installer from the unzipped file

### Mac

1.  Download the **CH340_Macintosh_driver.pkg** file.

2.  Unpack the downloaded file

3.  Run the installer from the unpacked file

### Linux

Drivers are almost certainly built into your Linux kernel already and it will probably just work
as soon as you plug it in.  If not you can download the **CH340_Linux_driver** (but I’d recommend
just upgrading your Linux install so that you get the  “built-in” one).
