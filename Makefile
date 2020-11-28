build:
	./clean.sh
	./headers.sh

run: iso
	./qemu.sh

iso: build
	./iso.sh

clean:
	./clean.sh
