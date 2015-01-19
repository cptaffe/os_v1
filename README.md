# os
Toy operating system from OsDev's barebones [wiki](http://wiki.osdev.org)

## Compilation

As of now requires an i686 cross compiler, binutils, and grub-mkrescue for iso creation. Alternatively, boot from the os.bin file. (`i686-elf-gcc`, `i686-elf-as`, `grub-mkrescue`).  To compile with that use:

```sh
make
qemu-system-i386 -cdrom os.iso
```
