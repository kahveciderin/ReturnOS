export SYSTEM_HEADER_PROJECTS=libc kernel
export PROJECTS=libc kernel

export MAKE=make
export HOST=i686-elf

export AR=${HOST}-ar
export AS=${HOST}-as
export CC=${HOST}-gcc

export PREFIX=/usr
export EXEC_PREFIX=${PREFIX}
export BOOTDIR=/boot
export LIBDIR=${EXEC_PREFIX}/lib
export INCLUDEDIR=${PREFIX}/include

export CFLAGS=-O2 -g
export CPPFLAGS=

# Configure the cross-compiler to use the desired system root.
export SYSROOT=$(shell pwd)/sysroot
export CC+=--sysroot=${SYSROOT}

export CC+=-isystem=${INCLUDEDIR}