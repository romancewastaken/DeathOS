# Visibility
This is private for now, so if you have access to this you're my bitch

# DeathOS
Boot loader written in assembly, checks for 64 bit support and then checks for long_mode

# File/Folder navigation 
* src/impl/kernel/main.c
**This is the main kernel file, this gets ran after the boot loader**
* src/impl/x86_64/print.c
**This contains all of the printing functions, including printf**
* src/impl/x86_64/boot
**This folder contains all the files for when the os boots, including the 32 bit boot loader & 64 bit version, and the header**

# Setup 
* docker build buildenv -t deathos-buildenv

# Load env
* Linux/Mac: docker run --rm -v $pwd:/root/env deathos-buildenv
* Windows cmd: docker run --rm -it -v %cd%:/root/env deathos-buildenv
* Windows PS: docker run --rm -it -v "${pwd}:/root/env" deathos-buildenv

# Build
* make build-x86_64
