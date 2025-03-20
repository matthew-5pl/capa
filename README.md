# capa
a two-key capacitive keypad for osu!

# case
i once again made the case with tinkercad, just like i did for the [cvntpad](https://github.com/matthew-5pl/cvntpad)  
will i ever manage to learn how to use an actual CAD software that's not made for elementary school children? only time will tell. (i won't :P)  
the case should print fine with any 3D printer and PLA filament combo.

i printed mine using [this filament](https://overture3d.com/products/overture-rock-pla-filament-1-75mm?variant=39594811621564)
on my (beloved/despised) ender 3, using CURA's 2mm preset.  
i recommend printing the top case button-side up with tree supports.  
the bottom case can be printed normally, but you should probably use standard supports for the USB-C port cutout.

*TBD: case redesign: rounded edges, slots for weights, screwholes and more*

# building
this keypad is handwired, so there's no PCB. these are the components you'll need:

- any RP2040 based microcontroller;
- 2x 1MΩ resistors;
- some wire;
- 2x sensing plates, basically just metal plates cut down to size (around 2.4x2.4 cm);  
**i recommend using copper for this, as it's decently cheap to acquire in sheet form, can be cut to size with household scissors and is also easy to solder to.**
- a USB-C breakout board.

you'll need to solder a wire and a resistor for each of the sensing plates, tying the other ends of the resistors together and connecting them to a ground pin on the microcontroller.  
then connect the wires you soldered to the plates to pins `GP27` and `GP26` for the left and right plates respectively.  

finally, solder four wires from your microcontroller's USB pins to the USB-C breakout board, push it into the case's dedicated slot and glue it in place.  

the case design is very generic, there's just holes to solder resistors and wires to the sensing plates, and there are no screws yet, so sadly you'll have to glue the keypad shut.  
you can still access the bootloader when the case is glued together by holding the left key and plugging the keypad into your computer.

# firmware
this keypad runs on QMK and supports VIA, so you can remap the keys to the ones you use on osu!

i also recycled the build scripts from the cvntpad, so building works the same way:  
either run `build.sh` or `make` in the repo's root directory.

to use VIA you'll need to import the `via/capa-via.json` file by going to the Design tab and clicking the `Load` button next to the Load Draft Definitions label.