# The default keymap for Ploopyco Trackball

# Compiling

```sh
nix-shell
qmk compile -kb ploopyco/trackball/rev1_005 -km ericmoritz
```

# Flashing

To put the trackball into bootloader mode:
1. Unplug the trackball
2. Hold the button directly to the right to the ball 
3. Plug in the trackball
4. Release the button

```sh
nix-shell
sudo qmk flash -kb ploopyco/trackball/rev1_005 -km ericmoritz
```
