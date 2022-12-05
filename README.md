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

# Emulate
Personally, I use [qemu](https://qemu.weilnetz.de/w64/2020/qemu-w64-setup-20200201.exe), but you can feel free to use something easier such as [Virtual Box](https://www.virtualbox.org/wiki/Downloads)

# Real hardware/Barebones
This is a pretty basic thing still if you've ever installed an OS before. 
<br>
* Download [rufus](https://github.com/pbatard/rufus/releases/download/v3.20/rufus-3.20.exe)
* Open rufus
* For boot selection, select kernel.iso inside \dist\x86_64
* Set partition scheme and select MBR
* For target system, select BIOS (or UEFI-CSM) 
* Leave the rest as default, then just click START
<br>
Please note: Your CPU requires intergrated graphics since there is no graphics card driver

## Licensing 
Permissions
* ✔️ Commercial use
* ✔️ Modification
* ✔️ Distribution
* ✔️ Private use
<br></br>

Conditions
* ❕ License and copyright notice
* ❕ State changes
* ❕ Disclose source
* ❕ Same license
<br></br>

Limitations
* ❌ Liability
* ❌ Warranty
<br></br>

License being used: **GNU General Public License v2.0 license**
