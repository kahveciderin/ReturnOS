.PHONY: build
C_SRC=$(wildcard *.c)
ASM_SRC=$(wildcard *.asm)
C_OBJS=$(C_SRC:.c=.co)
ASM_OBJS=$(ASM_SRC:.asm=.asmo)
build: ${C_OBJS} ${ASM_OBJS}
	i686-elf-gcc -T linker.ld -o kernel.bin -ffreestanding -O2 -nostdlib -lgcc $^
	make clean
clean:
	rm *.co
	rm *.asmo
%.asmo: %.asm
	i686-elf-as $< -o $@
%.co: %.c
	i686-elf-gcc -c $< -o $@ -std=gnu99 -ffreestanding -O2 -Wall -Wextra