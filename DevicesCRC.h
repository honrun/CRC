#ifndef _DevicesCRC_H_
#define _DevicesCRC_H_


#define CRC16           1
#define CRC16_MODBUS    2
#define CRC16_USB       3
#define CRC16_CCITT     4
#define CRC16_XMODEM    5
#define CRC16_ZMODEM    6
#define CRC16_IBM       7


#define CRC32           1
#define CRC32_JAMCRC    2
#define CRC32_MPEG2     3
#define CRC32_BZIP2     4
#define CRC32_SCTP      5



uint32_t uiCRC32(uint32_t *puiInitCRC, uint8_t *pucDataBuff, uint32_t uiLength);
uint32_t uiCRC32_BZIP2(uint32_t *puiInitCRC, uint8_t *pucDataBuff, uint32_t uiLength);
uint32_t uiCRC32_MPEG2(uint32_t *puiInitCRC, uint8_t *pucDataBuff, uint32_t uiLength);
uint32_t uiCRC32_POSIX(uint32_t *puiInitCRC, uint8_t *pucDataBuff, uint32_t uiLength);
uint32_t uiCRC32_JAMCRC(uint32_t *puiInitCRC, uint8_t *pucDataBuff, uint32_t uiLength);
uint32_t uiCRC32_STM32(uint32_t *puiInitCRC, uint32_t *pucDataBuff, uint32_t uiLength);


#endif
