![SofleKeyboard default keymap](https://github.com/josefadamcik/SofleKeyboard/raw/master/Images/soflekeyboard.png)
![SofleKeyboard adjust layer](https://github.com/josefadamcik/SofleKeyboard/raw/master/Images/soflekeyboard_layout_adjust.png)


#  keymap for Sofle Keyboard

Layout in [Keyboard Layout Editor](http://www.keyboard-layout-editor.com/#/gists/76efb423a46cbbea75465cb468eef7ff) and [adjust layer](http://www.keyboard-layout-editor.com/#/gists/4bcf66f922cfd54da20ba04905d56bd4)


Features:

- Symmetric modifiers (CMD/Super, Alt/Opt, Ctrl, Shift)
- Various modes, can be switched (using Adjust layer and the selected one is stored in EEPROM.
- Modes for Mac vs Linux/Win support -> different order of modifiers and different action shortcuts on the "UPPER" layer (the red one in the image). Designed to simplify transtions when switching between operating systems often.
- The OLED on master half shows selected mode and caps lock state and is rotated.
- Left encoder controls volume up/down/mute. Right encoder PGUP/PGDOWN.


## Compiling


```
nix-shell
qmk compile -kb sofle/rev1 -km ericmoritz
```

## Flashing

My keyboard has different micros on each hand. To flash them it is a little different:

Start with both sides disconnected from the computer

Plug in the left side's USB-C connector to the computer, and run the following:

```
nix-shell
sudo qmk flash -kb sofle/rev1 -km ericmoritz -bl dfu
```

Press the reset button on the left hand side to trigger the install

Uplug the left side's USB-C cable and plug in the right hand side's USB-Micro connector into the computer. Run the following

```sh
nix-shell
sudo qmk flash -kb sofle/rev1 -km ericmoritz
```

Press the reset button on the right hand side to trigger the install
