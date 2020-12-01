include make.config
build: clean headers
	for PROJECT in ${PROJECTS}; do DESTDIR="${SYSROOT}" ${MAKE} -C $${PROJECT} install; done
headers:
	
	mkdir -p "${SYSROOT}"
	for PROJECT in ${SYSTEM_HEADER_PROJECTS}; do DESTDIR="${SYSROOT}" ${MAKE} -C $${PROJECT} install-headers; done
run: iso
	qemu-system-${ARCH} -cdrom returnos.iso -m 512 -display vnc=localhost:5900 -daemonize
	gvncviewer localhost:5900
	killall qemu-system-${ARCH}
	echo "Killed QEMU"

iso: build
	mkdir -p isodir
	mkdir -p isodir/boot
	mkdir -p isodir/boot/grub
	cp -r sysroot/* isodir/
	cp -r misc-sysroot/* isodir/
	grub-mkrescue -o returnos.iso isodir
clean:
	# make -C ${PR} clean
	for PR in ${PROJECTS}; do make -C $${PR} clean; done
	rm -rf sysroot
	rm -rf isodir
	rm -rf returnos.iso
