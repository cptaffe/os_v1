
CC = i686-elf-gcc
CFLAGS = -I. -std=gnu99 -ffreestanding -O2 -Wall -Wextra

LNKFILE = linker.ld
SRC = kernel.c io/tty.c string.c
HDR = io/io.h io/tty.h string.h
OBJ = $(SRC:.c=.o)

all: boot.o $(OBJ) link grub

boot.o: boot.s
	i686-elf-as boot.s -o boot.o

$(OBJ): $(SRC)

$(SRC): $(HDR)

link:
	i686-elf-gcc -T linker.ld -o os.bin -ffreestanding -O2 -nostdlib boot.o $(SRC:.c=.o) -lgcc

# iso creation
grub:
	mkdir -p isodir/boot/grub
	cp os.bin isodir/boot/
	cp grub.cfg isodir/boot/grub/
	grub-mkrescue -o os.iso isodir

clean:
	$(RM) $(OBJ)
