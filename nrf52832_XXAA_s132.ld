ENTRY(Reset_HandlerSys)

MEMORY
{
	FLASH_SOFTDEVICE (RX) : ORIGIN = 0x00000000, LENGTH = 124K
	FLASH (RX)            : ORIGIN = 0x0001f000, LENGTH = 388K
	SRAM_SOFTDEVICE (RWX) : ORIGIN = 0x20000000, LENGTH = 0x1fc0
	SRAM (RWX)            : ORIGIN = 0x20001fc0, LENGTH = 0xe040
}

_estack = 0x20010000;

SECTIONS
{
	__STACK_SIZE__ = 4096;
	__HEAP_SIZE__ = 512;
	
	.softdevice :
	{
		KEEP(*(.softdevice))
		FILL(0xFFFFFFFF);
		. = 0x1f000;
	} > FLASH_SOFTDEVICE

	.softdevice_sram :
	{
		FILL(0x00000000);
		. = 0x1fc0;
	} > SRAM_SOFTDEVICE

	.isr_vector :
	{
		. = ALIGN(4);
		KEEP(*(.isr_vector))
		. = ALIGN(4);
	} > FLASH

	.text :
	{
		. = ALIGN(4);
		_stext = .;

		*(.text)
		*(.text*)
		*(.rodata)
		*(.rodata*)
		*(.glue_7)
		*(.glue_7t)
		KEEP(*(.init))
		KEEP(*(.fini))
		. = ALIGN(4);
		_etext = .;

	} > FLASH

	.ARM.extab :
	{
		. = ALIGN(4);
		*(.ARM.extab)
		*(.gnu.linkonce.armextab.*)
		. = ALIGN(4);
	} > FLASH

	.exidx :
	{
		. = ALIGN(4);
		PROVIDE(__exidx_start = .);
		*(.ARM.exidx*)
		. = ALIGN(4);
		PROVIDE(__exidx_end = .);
	} > FLASH

	.ARM.attributes :
	{
		*(.ARM.attributes)
	} > FLASH

	.preinit_array :
	{
		PROVIDE(__preinit_array_start = .);
		KEEP(*(.preinit_array*))
		PROVIDE(__preinit_array_end = .);
	} > FLASH

	.init_array :
	{
		PROVIDE(__init_array_start = .);
		KEEP(*(SORT(.init_array.*)))
		KEEP(*(.init_array*))
		PROVIDE(__init_array_end = .);
	} > FLASH

	.fini_array :
	{
		PROVIDE(__fini_array_start = .);
		KEEP(*(.fini_array*))
		KEEP(*(SORT(.fini_array.*)))
		PROVIDE(__fini_array_end = .);
	} > FLASH

	. = ALIGN(4);
	_sidata = .;

	.data : AT(_sidata)
	{
		. = ALIGN(4);
		_sdata = .;

		PROVIDE(__data_start__ = _sdata);
		*(.data)
		*(.data*)
		
		. = ALIGN(4);
		PROVIDE(__start_fs_data = .);
		KEEP(*(.fs_data))
		PROVIDE(__stop_fs_data = .);
		. = ALIGN(4);
		
		. = ALIGN(4);
		PROVIDE(__start_pwr_mgmt_data = .);
		KEEP(*(.pwr_mgmt_data))
		PROVIDE(__stop_pwr_mgmt_data = .);
		. = ALIGN(4);
		
		. = ALIGN(4);
		_edata = .;

		PROVIDE(__data_end__ = _edata);
	} > SRAM

	.bss :
	{
		. = ALIGN(4);
		_sbss = .;

		PROVIDE(__bss_start__ = _sbss);
		*(.bss)
		*(.bss*)
		*(COMMON)
		. = ALIGN(4);
		_ebss = .;

		PROVIDE(__bss_end__ = _ebss);
	} > SRAM

	PROVIDE(end = .);

	.heap (NOLOAD) :
	{
		. = ALIGN(4);
		PROVIDE(__heap_start__ = .);
		KEEP(*(.heap))
		. = . + __HEAP_SIZE__;
		. = ALIGN(4);
		PROVIDE(__heap_end__ = .);
	} > SRAM

	.reserved_for_stack (NOLOAD) :
	{
		. = ALIGN(4);
		_sstack = .;
		PROVIDE(__reserved_for_stack_start__ = .);
		KEEP(*(.reserved_for_stack))
		. = . + __STACK_SIZE__;
		. = ALIGN(4);
		PROVIDE(__reserved_for_stack_end__ = .);
	} > SRAM

}

PROVIDE(__isr_vector = g_pfnVectors);
PROVIDE(__StackLimit = _estack);
PROVIDE(__StackTop = __reserved_for_stack_start__);
PROVIDE(__etext = _etext);
