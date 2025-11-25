OBJ = main.o\
	  startup.o\

all : main.elf

%.o : %.c
	arm-none-eabi-gcc -c -mcpu=cortex-m3 -mthumb -O0 -g -o $@ $^


main.elf : $(OBJ)
	arm-none-eabi-ld -Tlinkerscript.ld $^ -o $@
	arm-none-eabi-readelf -a $@ > $@.debug
	arm-none-eabi-objdump -D -S $@ > $@.lst

clean :
	rm -rf *.o *.elf *.map *.debug *.bin *.lst

qemu:
	qemu-system-arm -M stm32vldiscovery -cpu cortex-m3 -nographic -kernel main.elf -S -gdb tcp::1234

gdb:
	arm-none-eabi-gdb -tui -q main.elf -ex "target remote localhost:1234" 
