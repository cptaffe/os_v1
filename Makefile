
LNKFILE = linker.ld
SRC = kernel.c tty.c
OBJ = $(SRC:.c=.o)

all: boot.o $(OBJ) link

boot.o: boot.s
	i686-elf-as boot.s -o boot.o

$(OBJ):
	i686-elf-gcc -c $(SRC) -std=gnu99 -ffreestanding -O2 -Wall -Wextra

link:
	i686-elf-gcc -T linker.ld -o myos.bin -ffreestanding -O2 -nostdlib boot.o $(SRC:.c=.o) -lgcc

# iso creation
grub:
	mkdir -p isodir/boot/grub
	cp myos.bin isodir/boot/
	cp grub.cfg isodir/boot/grub/
	grub-mkrescue -o myos.iso isodir

boot:
	qemu-system-i386 -kernel myos.bin

clean:
	$(RM) $(OBJ)
