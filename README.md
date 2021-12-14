# AVR
Testing space for learning about AVR microcontrollers

## How To
Note I Havent Actually tested this so it might not work
### Software & Libraries
1. binutils : for getting tools like assembler, linker
2. gcc-avr : a GNU C cross-compiler specifically for AVR
3. avr-libc : it is a package for AVR C library
4. avrdude : it is a utility that trasnfers codes from the UBUNTU to the microcontroller. Here we weill be using the CLI tool of avrdude.
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
