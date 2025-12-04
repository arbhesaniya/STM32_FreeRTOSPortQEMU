OBJ = main.o \
	  startup.o \
	  UserFunc.o \
	  FreeRTOS-Kernel/tasks.o  \
	  FreeRTOS-Kernel/list.o  \
	  FreeRTOS-Kernel/portable/MemMang/heap_4.o \
	  FreeRTOS-Kernel/portable/GCC/ARM_CM3/port.o \

INC = -IFreeRTOS-Kernel/include/ \
	  -IFreeRTOS-Kernel/portable/GCC/ARM_CM3/ \
	  -I.


all : main.elf

%.o : %.c
	arm-none-eabi-gcc $(INC) -mthumb -mcpu=cortex-m3 -c -O0 -g -Wall $^ -o $@


main.elf : $(OBJ)
	arm-none-eabi-ld -Tlinkerscript.ld $^ -o $@
	arm-none-eabi-readelf -a $@ > $@.debug
	arm-none-eabi-objdump -D -S $@ > $@.lst
	arm-none-eabi-objcopy -O binary main.elf main.bin

clean :
	rm -rf *.o *.elf *.map *.debug *.bin *.lst $(OBJ)

qemu:
	qemu-system-arm -M stm32vldiscovery -cpu cortex-m3 -nographic -kernel main.elf -S -gdb tcp::1234

gdb:
	arm-none-eabi-gdb -tui -q main.elf -ex "target remote localhost:1234" 
