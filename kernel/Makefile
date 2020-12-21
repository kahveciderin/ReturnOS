PREFDIR=..
include ../make.config
CFLAGS?=-O2 -g
CPPFLAGS?=
LDFLAGS?=
LIBS?=

DESTDIR?=
PREFIX?=/usr/local
EXEC_PREFIX?=$(PREFIX)
BOOTDIR?=$(EXEC_PREFIX)/boot
INCLUDEDIR?=$(PREFIX)/include

CFLAGS+=-ffreestanding -Wall -Wextra
CPPFLAGS+=-D__is_kernel -Iinclude
LDFLAGS+=
LIBS+= -nostdlib -lk -lgcc

ARCHDIR=arch/${ARCH}
include ${ARCHDIR}/make.config

CFLAGS:=$(CFLAGS) $(KERNEL_ARCH_CFLAGS)
CPPFLAGS:=$(CPPFLAGS) $(KERNEL_ARCH_CPPFLAGS)
LDFLAGS:=$(LDFLAGS) $(KERNEL_ARCH_LDFLAGS)
LIBS:=$(LIBS) $(KERNEL_ARCH_LIBS)
K_C_SRC=$(shell find ./kernel -name *.c)
K_ASM_SRC=$(shell find ./kernel -name *.S)
KERNEL_OBJS=\
$(KERNEL_ARCH_OBJS) \
$(K_C_SRC:.c=.o) \
$(K_ASM_SRC:.S=.o) \

OBJS=\
${ARCH_CRT}\
$(KERNEL_OBJS) \

LINK_LIST=\
$(LDFLAGS) \
$(KERNEL_OBJS) \
$(LIBS) \
${ARCH_CRT}\

.PHONY: all clean install install-headers install-kernel
.SUFFIXES: .o .c .S

all: returnos.kernel
	
returnos.kernel: $(OBJS) ${ARCHDIR}/linker.ld
	$(CC) -T ${ARCHDIR}/linker.ld -o $@ $(CFLAGS) $(LINK_LIST)
	grub-file --is-x86-multiboot returnos.kernel
${ARCHDIR}/crtstuff/01_crtbegin.o: ${ARCHDIR}/crtstuff/01_crtbegin.rawbin
	cp $< $@
${ARCHDIR}/crtstuff/02_crtend.o: ${ARCHDIR}/crtstuff/02_crtend.rawbin
	cp $< $@
.c.o:
	$(CC) -MD -c $< -o $@ -std=gnu11 $(CFLAGS) $(CPPFLAGS)

.S.o:
	nasm $< -o $@
.rawbin.o:
	cp $< $@
clean:
	rm -f returnos.kernel
	rm -f $(OBJS) *.o */*.o */*/*.o
	rm -f $(OBJS:.o=.d) *.d */*.d */*/*.d

install: install-headers install-kernel

install-headers:
	mkdir -p $(DESTDIR)$(INCLUDEDIR)
	cp -R --preserve=timestamps include/. $(DESTDIR)$(INCLUDEDIR)/.

install-kernel: returnos.kernel
	mkdir -p $(DESTDIR)$(BOOTDIR)
	cp returnos.kernel $(DESTDIR)$(BOOTDIR)

-include $(OBJS:.o=.d)
