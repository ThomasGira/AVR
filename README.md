# AVR
Testing space for learning about AVR microcontrollers

## How To
Note I Havent Actually tested this so it might not work
### Software & Libraries
1. binutils : for getting tools like assembler, linker
2. gcc-avr : a GNU C cross-compiler specifically for AVR
3. avr-libc : it is a package for AVR C library
4. avrdude : it is a utility that trasnfers codes from the UBUNTU to the microcontroller. Here we we'll be using the CLI tool of avrdude.
5. gdb-avr : Utility for in-system debugging and emulation
5. uisp, flex, bison and byacc : Not sure

### How to code
Use C. Need to learn how to actually do it

### Compiling
FIrst you need to make a document that contains all of the compiler tags. This is done by the following command line.
```bash
sudo nano compile_script
```

"compile_script" can be replaced by whatever name you want.

Whithin this script you need to have the following tags.
```bash
avr-gcc -g -Os -mmcu=atmega32 -c led.c
avr-gcc -g -mmcu=atmega32 -o led.elf led.o
avr-objcopy -j .text -j .data -O ihex led.elf led.hex
avr-size --format=avr --mcu=atmega32 led.elf 
```

Make sure to have the appropriate file tags and avr board labeled.

You then can give the script the required permissions with the commandline.
```bash
sudo chmod 755 compile_script
```

Once again replacing compile_script with whatever you named the file.

Finally the code can be compiled with:
```bash
sudo ./compile_script
```

### Programming Controller
This follows similar suit to the compile script but basically you need to make a file with all the correct compiler tags using the command line.
```bash
sudo nano upload_script
```

This file will have the following content.
```bash
avrdude -v -p atmega2560 -c wiring -P /dev/ttyACM0 -b115200 -D -Uflash:w:led.hex:i
```
There are a lot of other tags you can include but the easiest way to find them is to upload an arduino script including "verbose" output and then copying the tags that are used. Heres a quick overview of what is included.
*-v : Includes verbose output (Gives more information upon compiling)
*-p : Signifies which microcontroller is being used
*-c : Signifies which programmer is being used
*-P : Signifies which port is being used
*-b : Sets the baudrate of the RS-232 connection (Kinda confused on why it is this number but it works)
*-D : Disables autoerase
*-U : Performs a memory operation, in this case flashing the rom
..*flash : Flashes the ROM
..*i : Signifies that Intel Hex is used

Another potential issue is that the correct permissiond are not given to the port that is writing data. This can be fixed by the following command line arguments.

```bash 
sudo chmod a+rw /dev/ttyACM0
sudo chmod +x upload_script
```
