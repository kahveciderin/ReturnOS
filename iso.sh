#!/bin/sh
set -e
. ./build.sh

mkdir -p isodir
mkdir -p isodir/boot
mkdir -p isodir/boot/grub

cp sysroot/boot/returnos.kernel isodir/boot/returnos.kernel
cat > isodir/boot/grub/grub.cfg << EOF
menuentry "returnos" {
	multiboot /boot/returnos.kernel
}
EOF
grub-mkrescue -o returnos.iso isodir
