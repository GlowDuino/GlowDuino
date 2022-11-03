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

    **...**

    If there are already other URLs in the box, you can either add this one
    separated by a comma or click the button next to the box to open an input
    dialog where you can add the URL on a new line.

3.  Click the "OK" button to close the Preferences dialog.

4.  In the **Tools > Board** menu, select "Boards Manager..." (at the top of the
    menu).

5.  In the Boards Manager dialog, search for "GlowDuino Boards".

6.  Select the "GlowDuino Boards" entry in the list, and click the
    "Install" button.