#!/bin/sh
set -e
. ./iso.sh

qemu-system-$(./target-triplet-to-arch.sh $HOST) -cdrom returnos.iso -m 512 -display vnc=localhost:5900 -daemonize
gvncviewer localhost:5900
killall qemu-system-$(./target-triplet-to-arch.sh $HOST)
echo "Killed QEMU"
