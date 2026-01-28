#ifndef FREERTOS_CONFIG_H
#define FREERTOS_CONFIG_H

#define configTICK_TYPE_WIDTH_IN_BITS          TICK_TYPE_WIDTH_32_BITS

#define configMAX_SYSCALL_INTERRUPT_PRIORITY   160 //for Cortex-M

#define configMINIMAL_STACK_SIZE               0x100

#define configMAX_PRIORITIES                   10

#define configUSE_PREEMPTION                   1

#define configUSE_IDLE_HOOK                    0

#define configUSE_TICK_HOOK                    0

#define configTOTAL_HEAP_SIZE                  0x1000

#define configCPU_CLOCK_HZ                     8000000 //STM32VLDiscovery clock is 8- 24MHz

#define configTICK_RATE_HZ                     100

#define INCLUDE_vTaskDelete                    1

#define INCLUDE_vTaskDelay                     1

#define INCLUDE_vTaskSuspend                   1

#define INCLUDE_xTaskDelayUntil                1

#endif /* FREERTOS_CONFIG_H */
