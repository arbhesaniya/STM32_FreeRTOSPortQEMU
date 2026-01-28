#include "FreeRTOS.h"
#include "task.h"


unsigned int a=10,b=20,c;

static void vTask1(void *pvParameters){
    volatile int x=0;
    while(1){
        x++;
        vTaskDelay(100);
    } 
}

static void vTask2(void *pvParameters){
    volatile int y=0;
    while(1){
        y++;
        vTaskDelay(100);
    }
}


int main(){

    //Call HWInit() to perform any HW Setup

    BaseType_t xReturn;

    xReturn = xTaskCreate(vTask1, "T1", configMINIMAL_STACK_SIZE, NULL , 2 , NULL);
    xReturn = xTaskCreate(vTask2, "T2", configMINIMAL_STACK_SIZE, NULL , 3 , NULL);
    
    vTaskStartScheduler();

    c = a+b;

    while(1); 
    
    return 0;
}