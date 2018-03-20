#ifndef _NRF52832_S132_MEMMAP_H
#define _NRF52832_S132_MEMMAP_H

#include "nrf_mbr.h"
#include "nrf_sdm.h"

// nRF52832 MBR Section 4KB
#define MBR_START (0)
#define MBR_END (0x1000)
#define MBR_MAX_SIZE (MBR_END - MBR_START)

#if (SD_MAJOR_VERSION == 5)
// nRF52832 Bootloader Settings 4KB
#define BOOTLOADER_SETTINGS_START	(0x7F000)
#define BOOTLOADER_SETTINGS_END		(0x80000)
#define BOOTLOADER_SETTINGS_MAX_SIZE	(BOOTLOADER_SETTINGS_END - BOOTLOADER_SETTINGS_START)

// nRF52832 Bootloader MBR Parameter Storage 4KB
#define BOOTLOADER_MBRPARAM_START	(0x7E000)
#define BOOTLOADER_MBRPARAM_END		(0x7F000)
#define BOOTLOADER_MBRPARAM_MAX_SIZE	(BOOTLOADER_MBRPARAM_END - BOOTLOADER_MBRPARAM_START)

// nRF52832 Bootloader Region including MBR Param 28KB
#define BOOTLOADER_REGION_START		(0x78000)
#define BOOTLOADER_REGION_END		(0x7F000)
#define BOOTLOADER_MAX_SIZE			(BOOTLOADER_REGION_END - BOOTLOADER_REGION_START)

// nRF52832 Application Area 352KB
#define APPLICATION_ADDRESS_START   (0x20000)
#define APPLICATION_ADDRESS_END		(0x78000)
#define APPLICATION_MAX_SIZE		(APPLICATION_ADDRESS_END - APPLICATION_ADDRESS_START)

// nRF52832 Softdevice Area 124KB
#define SD_ADDRESS_START			(0x1000)
#define SD_ADDRESS_END				(0x20000)
#define SD_MAX_SIZE					(SD_ADDRESS_END - SD_ADDRESS_START)

// nRF52832 FLASH 512KB / 4KB Pages / 512B Blocks
#define NRF52832_FLASHSIZE			(512 * 1024)
#define NRF52832_PAGESIZE			(4096)
#define NRF52832_BLOCKSIZE			(512)
#define FIRMWARE_LAST_BLOCK_INDEX	(959 * 512) // 4096 byte sectors, 960 is bootloader
#elif (SD_MAJOR_VERSION == 4)
// nRF52832 Bootloader Settings 4KB
#define BOOTLOADER_SETTINGS_START	(0x7F000)
#define BOOTLOADER_SETTINGS_END		(0x80000)
#define BOOTLOADER_SETTINGS_MAX_SIZE	(BOOTLOADER_SETTINGS_END - BOOTLOADER_SETTINGS_START)

// nRF52832 Bootloader MBR Parameter Storage 4KB
#define BOOTLOADER_MBRPARAM_START	(0x7E000)
#define BOOTLOADER_MBRPARAM_END		(0x7F000)
#define BOOTLOADER_MBRPARAM_MAX_SIZE	(BOOTLOADER_MBRPARAM_END - BOOTLOADER_MBRPARAM_START)

// nRF52832 Bootloader Region including MBR Param 28KB
#define BOOTLOADER_REGION_START		(0x78000)
#define BOOTLOADER_REGION_END		(0x7F000)
#define BOOTLOADER_MAX_SIZE			(BOOTLOADER_REGION_END - BOOTLOADER_REGION_START)

// nRF52832 Application Area 356KB
#define APPLICATION_ADDRESS_START   (0x1F000)
#define APPLICATION_ADDRESS_END		(0x78000)
#define APPLICATION_MAX_SIZE		(APPLICATION_ADDRESS_END - APPLICATION_ADDRESS_START)

// nRF52832 Softdevice Area 120KB
#define SD_ADDRESS_START			(0x1000)
#define SD_ADDRESS_END				(0x1F000)
#define SD_MAX_SIZE					(SD_ADDRESS_END - SD_ADDRESS_START)

// nRF52832 FLASH 512KB / 4KB Pages / 512B Blocks
#define NRF52832_FLASHSIZE			(512 * 1024)
#define NRF52832_PAGESIZE			(4096)
#define NRF52832_BLOCKSIZE			(512)
#define FIRMWARE_LAST_BLOCK_INDEX	(959 * 512) // 4096 byte sectors, 960 is bootloader
#elif (SD_MAJOR_VERSION == 3)
// nRF52832 Bootloader Settings 4KB
#define BOOTLOADER_SETTINGS_START	(0x7F000)
#define BOOTLOADER_SETTINGS_END		(0x80000)
#define BOOTLOADER_SETTINGS_MAX_SIZE	(BOOTLOADER_SETTINGS_END - BOOTLOADER_SETTINGS_START)

// nRF52832 Bootloader MBR Parameter Storage 4KB
#define BOOTLOADER_MBRPARAM_START	(0x7E000)
#define BOOTLOADER_MBRPARAM_END		(0x7F000)
#define BOOTLOADER_MBRPARAM_MAX_SIZE	(BOOTLOADER_MBRPARAM_END - BOOTLOADER_MBRPARAM_START)

// nRF52832 Bootloader Region including MBR Param 28KB
#define BOOTLOADER_REGION_START		(0x78000)
#define BOOTLOADER_REGION_END		(0x7F000)
#define BOOTLOADER_MAX_SIZE			(BOOTLOADER_REGION_END - BOOTLOADER_REGION_START)

// nRF52832 Application Area 356KB
#define APPLICATION_ADDRESS_START   (0x1F000)
#define APPLICATION_ADDRESS_END		(0x78000)
#define APPLICATION_MAX_SIZE		(APPLICATION_ADDRESS_END - APPLICATION_ADDRESS_START)

// nRF52832 Softdevice Area 120KB
#define SD_ADDRESS_START			(0x1000)
#define SD_ADDRESS_END				(0x1F000)
#define SD_MAX_SIZE					(SD_ADDRESS_END - SD_ADDRESS_START)

// nRF52832 FLASH 512KB / 4KB Pages / 512B Blocks
#define NRF52832_FLASHSIZE			(512 * 1024)
#define NRF52832_PAGESIZE			(4096)
#define NRF52832_BLOCKSIZE			(512)
#define FIRMWARE_LAST_BLOCK_INDEX	(959 * 512) // 4096 byte sectors, 960 is bootloader
#else
#error "Soft Device Version Not Supported for This Bootloader!"
#endif

#endif // _NRF52832_S132_MEMMAP_H