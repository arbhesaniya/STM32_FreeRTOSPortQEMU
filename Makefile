all : main.o startup.o final.elf

main.o : main.c
	arm-none-eabi-gcc -c -mcpu=cortex-m3 -mthumb -O0 -g -o $@ $^

startup.o : startup.c
	arm-none-eabi-gcc -c -mcpu=cortex-m3 -mthumb -O0 -g -o $@ $^

final.elf : main.o startup.o
	arm-none-eabi-gcc -nostdlib -T linkerscript.ld -Wl,-Map=final.map -o $@ $^
	arm-none-eabi-readelf -a final.elf > final.elf.debug
	arm-none-eabi-objcopy -O binary final.elf final.bin

clean :
	rm -rf *.o *.elf *.map *.debug *.bin

qemu:
	qemu-system-arm -M stm32vldiscovery -nographic -kernel final.elf -S -s

gdb:
	arm-none-eabi-gdb -tui -q final.elf -ex "target remote localhost:1234" 
