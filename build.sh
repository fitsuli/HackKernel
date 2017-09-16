#!/bin/bash

LOCAL_DIR=`pwd`
mkdir -p out
echo "Paths and Toolchain loaded!"
make ARCH=arm64 O=out hisi_hi6210sft_defconfig
make ARCH=arm64 O=out -j4
printf "\nDone! Path to image: ../out/arch/arm64/boot/Image"
printf "\nThe Path modules out/(device)/*.ko\n"
