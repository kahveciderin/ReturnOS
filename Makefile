include ./config.sh
build: clean headers
	for PROJECT in ${PROJECTS}; do DESTDIR="${SYSROOT}" ${MAKE} -C $${PROJECT} install; done
headers:
	
	mkdir -p "${SYSROOT}"
	for PROJECT in ${SYSTEM_HEADER_PROJECTS}; do DESTDIR="${SYSROOT}" ${MAKE} -C $${PROJECT} install-headers; done
run: iso
	qemu-system-$(./target-triplet-to-arch.sh $HOST) -cdrom returnos.iso -m 512 -display vnc=localhost:5900 -daemonize
	gvncviewer localhost:5900
	killall qemu-system-$(./target-triplet-to-arch.sh $HOST)
	echo "Killed QEMU"

iso: build
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
clean:
	# make -C ${PR} clean
	for PR in ${PROJECTS}; do make -C $${PR} clean; done
	rm -rf sysroot
	rm -rf isodir
	rm -rf returnos.iso
