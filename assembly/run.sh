#!/bin/bash

# brew install nasm

nasm -f macho64 x.asm -o x.o
ld -macosx_version_min 10.5.8 x.o -o x
./x
