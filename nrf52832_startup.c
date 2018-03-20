/*
	This file contains the entry point (Reset_HandlerSys) of your firmware project.
	The reset handled initializes the RAM and calls system library initializers as well as
	the platform-specific initializer and the main() function.
*/

extern void *_estack;

#define NULL ((void *)0)

void Reset_HandlerSys();
void Default_HandlerIRQ();

void NMI_Handler()                                   __attribute__ ((weak, alias ("Default_HandlerIRQ")));
void HardFault_Handler()                             __attribute__ ((weak, alias ("Default_HandlerIRQ")));
void MemoryManagement_Handler()                      __attribute__ ((weak, alias ("Default_HandlerIRQ")));
void BusFault_Handler()                              __attribute__ ((weak, alias ("Default_HandlerIRQ")));
void UsageFault_Handler()                            __attribute__ ((weak, alias ("Default_HandlerIRQ")));
void SVC_Handler()                                   __attribute__ ((weak, alias ("Default_HandlerIRQ")));
void DebugMon_Handler()                              __attribute__ ((weak, alias ("Default_HandlerIRQ")));
void PendSV_Handler()                                __attribute__ ((weak, alias ("Default_HandlerIRQ")));
void SysTick_Handler()                               __attribute__ ((weak, alias ("Default_HandlerIRQ")));
void POWER_CLOCK_IRQHandler()                        __attribute__ ((weak, alias ("Default_HandlerIRQ")));
void RADIO_IRQHandler()                              __attribute__ ((weak, alias ("Default_HandlerIRQ")));
void UARTE0_UART0_IRQHandler()                       __attribute__ ((weak, alias ("Default_HandlerIRQ")));
void SPIM0_SPIS0_TWIM0_TWIS0_SPI0_TWI0_IRQHandler()  __attribute__ ((weak, alias ("Default_HandlerIRQ")));
void SPIM1_SPIS1_TWIM1_TWIS1_SPI1_TWI1_IRQHandler()  __attribute__ ((weak, alias ("Default_HandlerIRQ")));
void NFCT_IRQHandler()                               __attribute__ ((weak, alias ("Default_HandlerIRQ")));
void GPIOTE_IRQHandler()                             __attribute__ ((weak, alias ("Default_HandlerIRQ")));
void SAADC_IRQHandler()                              __attribute__ ((weak, alias ("Default_HandlerIRQ")));
void TIMER0_IRQHandler()                             __attribute__ ((weak, alias ("Default_HandlerIRQ")));
void TIMER1_IRQHandler()                             __attribute__ ((weak, alias ("Default_HandlerIRQ")));
void TIMER2_IRQHandler()                             __attribute__ ((weak, alias ("Default_HandlerIRQ")));
void RTC0_IRQHandler()                               __attribute__ ((weak, alias ("Default_HandlerIRQ")));
void TEMP_IRQHandler()                               __attribute__ ((weak, alias ("Default_HandlerIRQ")));
void RNG_IRQHandler()                                __attribute__ ((weak, alias ("Default_HandlerIRQ")));
void ECB_IRQHandler()                                __attribute__ ((weak, alias ("Default_HandlerIRQ")));
void CCM_AAR_IRQHandler()                            __attribute__ ((weak, alias ("Default_HandlerIRQ")));
void WDT_IRQHandler()                                __attribute__ ((weak, alias ("Default_HandlerIRQ")));
void RTC1_IRQHandler()                               __attribute__ ((weak, alias ("Default_HandlerIRQ")));
void QDEC_IRQHandler()                               __attribute__ ((weak, alias ("Default_HandlerIRQ")));
void COMP_LPCOMP_IRQHandler()                        __attribute__ ((weak, alias ("Default_HandlerIRQ")));
void SWI0_EGU0_IRQHandler()                          __attribute__ ((weak, alias ("Default_HandlerIRQ")));
void SWI1_EGU1_IRQHandler()                          __attribute__ ((weak, alias ("Default_HandlerIRQ")));
void SWI2_EGU2_IRQHandler()                          __attribute__ ((weak, alias ("Default_HandlerIRQ")));
void SWI3_EGU3_IRQHandler()                          __attribute__ ((weak, alias ("Default_HandlerIRQ")));
void SWI4_EGU4_IRQHandler()                          __attribute__ ((weak, alias ("Default_HandlerIRQ")));
void SWI5_EGU5_IRQHandler()                          __attribute__ ((weak, alias ("Default_HandlerIRQ")));
void TIMER3_IRQHandler()                             __attribute__ ((weak, alias ("Default_HandlerIRQ")));
void TIMER4_IRQHandler()                             __attribute__ ((weak, alias ("Default_HandlerIRQ")));
void PWM0_IRQHandler()                               __attribute__ ((weak, alias ("Default_HandlerIRQ")));
void PDM_IRQHandler()                                __attribute__ ((weak, alias ("Default_HandlerIRQ")));
void MWU_IRQHandler()                                __attribute__ ((weak, alias ("Default_HandlerIRQ")));
void PWM1_IRQHandler()                               __attribute__ ((weak, alias ("Default_HandlerIRQ")));
void PWM2_IRQHandler()                               __attribute__ ((weak, alias ("Default_HandlerIRQ")));
void SPIM2_SPIS2_SPI2_IRQHandler()                   __attribute__ ((weak, alias ("Default_HandlerIRQ")));
void RTC2_IRQHandler()                               __attribute__ ((weak, alias ("Default_HandlerIRQ")));
void I2S_IRQHandler()                                __attribute__ ((weak, alias ("Default_HandlerIRQ")));
void FPU_IRQHandler()                                __attribute__ ((weak, alias ("Default_HandlerIRQ")));

void * g_pfnVectors[0x80] __attribute__ ((section (".isr_vector"), used)) = 
{
	&_estack,
	&Reset_HandlerSys,
	&NMI_Handler,
	&HardFault_Handler,
	&MemoryManagement_Handler,
	&BusFault_Handler,
	&UsageFault_Handler,
	NULL,
	NULL,
	NULL,
	NULL,
	&SVC_Handler,
	&DebugMon_Handler,
	NULL,
	&PendSV_Handler,
	&SysTick_Handler,
	&POWER_CLOCK_IRQHandler,
	&RADIO_IRQHandler,
	&UARTE0_UART0_IRQHandler,
	&SPIM0_SPIS0_TWIM0_TWIS0_SPI0_TWI0_IRQHandler,
	&SPIM1_SPIS1_TWIM1_TWIS1_SPI1_TWI1_IRQHandler,
	&NFCT_IRQHandler,
	&GPIOTE_IRQHandler,
	&SAADC_IRQHandler,
	&TIMER0_IRQHandler,
	&TIMER1_IRQHandler,
	&TIMER2_IRQHandler,
	&RTC0_IRQHandler,
	&TEMP_IRQHandler,
	&RNG_IRQHandler,
	&ECB_IRQHandler,
	&CCM_AAR_IRQHandler,
	&WDT_IRQHandler,
	&RTC1_IRQHandler,
	&QDEC_IRQHandler,
	&COMP_LPCOMP_IRQHandler,
	&SWI0_EGU0_IRQHandler,
	&SWI1_EGU1_IRQHandler,
	&SWI2_EGU2_IRQHandler,
	&SWI3_EGU3_IRQHandler,
	&SWI4_EGU4_IRQHandler,
	&SWI5_EGU5_IRQHandler,
	&TIMER3_IRQHandler,
	&TIMER4_IRQHandler,
	&PWM0_IRQHandler,
	&PDM_IRQHandler,
	NULL,
	NULL,
	&MWU_IRQHandler,
	&PWM1_IRQHandler,
	&PWM2_IRQHandler,
	&SPIM2_SPIS2_SPI2_IRQHandler,
	&RTC2_IRQHandler,
	&I2S_IRQHandler,
	&FPU_IRQHandler,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
};

extern void SystemInit(void);
void __libc_init_array();
int main();

extern void *_sidata, *_sdata, *_edata;
extern void *_sbss, *_ebss;
extern void *_sstack;

void __attribute__((naked, noreturn)) Reset_HandlerSys()
{
	//Normally the CPU should will setup the based on the value from the first entry in the vector table.
	//If you encounter problems with accessing stack variables during initialization, ensure the line below is enabled.
	#ifdef sram_layout
	asm ("ldr sp, =_estack");
	#endif

	// Copy data
	void **pSource, **pDest;
	for (pSource = &_sidata, pDest = &_sdata; pDest != &_edata; pSource++, pDest++)
		*pDest = *pSource;
	
	// Zero-out the BSS
	for (pDest = &_sbss; pDest != &_ebss; pDest++)
		*pDest = 0;

	// Watermark the stack so we can track usage when debugging
	for (pDest = &_sstack; pDest != &_estack; pDest++)
		*pDest = (void*)0xAA;
	
	SystemInit();
	__libc_init_array();
	(void)main();
	for (;;) ;
}

void __attribute__((naked, noreturn)) Default_HandlerIRQ()
{
	//If you get stuck here, your code is missing a handler for some interrupt.
	for (;;) ;
}
