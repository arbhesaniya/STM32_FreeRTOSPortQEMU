MEMORY
{
    FLASH (rx) : ORIGIN =0x00000000, LENGTH = 128K
    RAM   (rwx): ORIGIN =0x20000000, LENGTH = 8K
}

ENTRY(Reset_Handler)

SECTIONS
{
    .text :
    {
        *(.isr_vector) /* .isr_vector will also work as only one section of that name is available*/
        *(.text)
        *(.text*)
        *(.rodata)
        *(.rodata*)
        . = ALIGN(4);/*before end of each section make location counter allignment*/
    }> FLASH

    _end_text = LOADADDR(.data);

    .data :
    {
        _start_data = .;
        *(.data)
        *(.data*)
        . = ALIGN(4);
        _end_data = .;
    }> RAM AT>FLASH

    .bss :
    {
        _start_bss = .;
        *(.bss)
        *(.bss*)
        *(COMMON)
        . = ALIGN(4);
        _end_bss = .;
    }> RAM

    
    __StackTop = ORIGIN(RAM) + LENGTH(RAM);
    PROVIDE( __stack = __StackTop - 4);

}