typedef unsigned int uint32_t;

#define SRAM_START 0x20000000U
#define SRAM_SIZE  (64U * 1024U) /*64kB*/
#define SRAM_END ((SRAM_START)+(SRAM_SIZE))

#define STACK_TOP  SRAM_END

void Reset_Handler(void);
void Default_Handler(void);

void NMI_Handler(void)                __attribute__((weak, alias("Default_Handler")));
void HardFault_Handler(void)          __attribute__((weak, alias("Default_Handler")));
void MemManage_Handler(void)          __attribute__((weak, alias("Default_Handler")));
void BusFault_Handler(void)           __attribute__((weak, alias("Default_Handler")));
void UsageFault_Handler(void)         __attribute__((weak, alias("Default_Handler")));

uint32_t vectors[] __attribute__((section(".isr_vector")))={
    STACK_TOP,
    (uint32_t)&Reset_Handler,
    (uint32_t)&NMI_Handler,
    (uint32_t)&HardFault_Handler,
    (uint32_t)&MemManage_Handler,
    (uint32_t)&BusFault_Handler,
    (uint32_t)&UsageFault_Handler,
    0,  // Reserved
    0,  // Reserved
    0,  // Reserved
    0   // Reserved
};

void Default_Handler(void) {
    while(1);  // Trap if any exception occurs
}

/* symbols from Linker Script*/
extern  char _end_text;
extern  char _start_data;
extern  char _end_data;

extern  char _start_bss;
extern  char _end_bss;

int main(void);
void Reset_Handler(void){  

        uint32_t *e_text = (uint32_t *)&_end_text;
        uint32_t *s_data = (uint32_t *)&_start_data;
        uint32_t *e_data = (uint32_t *)&_end_data;

        while(s_data!=e_data){
            *s_data++ = *e_text++;
        }

        uint32_t *s_bss = (uint32_t *)&_start_bss;
        uint32_t *e_bss = (uint32_t *)&_end_bss;

        while(s_bss!=e_bss){
            *s_bss++ = 0;
        }

        main();
        while(1);
    }
