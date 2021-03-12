#!/bin/bash
# Let's build the kernel

# Check if folders exists
if [ ! -d "bin" ]; then
    mkdir -p bin
fi
if [ ! -d "obj" ]; then
    mkdir -p obj
fi

echo "> Assembling..."
nasm -f elf -o obj/start.o src/start.asm # assemble into object in elf_i386 / x32 format 

echo "> Compiling..."
gcc -fno-pie -m32 -Wall -O -fstrength-reduce -fomit-frame-pointer -finline-functions -nostdinc -fno-builtin -I./src/include -c -o obj/main.o src/main.c
gcc -fno-pie -m32 -Wall -O -fstrength-reduce -fomit-frame-pointer -finline-functions -nostdinc -fno-builtin -I./src/include -c -o obj/screen.o src/screen.c

echo "> Linking..."
ld -m elf_i386 -T src/link.ld obj/start.o obj/main.o obj/screen.o -o bin/kernel_must-kast.bin -nostdlib

echo "> Script done!"