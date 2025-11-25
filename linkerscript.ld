MEMORY
{
    FLASH (rx) : ORIGIN =0x00000000, LENGTH = 256K
    RAM   (rwx): ORIGIN =0x20000000, LENGTH = 64K
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
        . = ALIGN(4);/*before end of each section make location counter allignment*/
        _end_text = .;
    }> FLASH

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

}