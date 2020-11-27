build:
	make -C kernel build
run: build
	qemu-system-x86_64 -m 512 -kernel ./kernel/kernel.bin -display vnc=localhost:5900 -daemonize
	gvncviewer localhost:5900
	killall qemu-system-x86_64