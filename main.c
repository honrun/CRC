#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include "DevicesCRC.h"



uint8_t buff[] = "Hello honrun";


int main(void)
{
    printf("CRC test.\r\n\n");

    printf("CRC32:\t%08X\r\n",        uiCRC32(NULL, buff, strlen((char *)buff)));
    printf("CRC32_BZIP2:\t%08X\r\n",  uiCRC32_BZIP2(NULL, buff, strlen((char *)buff)));
    printf("CRC32_MPEG2:\t%08X\r\n",  uiCRC32_MPEG2(NULL, buff, strlen((char *)buff)));
    printf("CRC32_POSIX:\t%08X\r\n",  uiCRC32_POSIX(NULL, buff, strlen((char *)buff)));
    printf("CRC32_JAMCRC:\t%08X\r\n", uiCRC32_JAMCRC(NULL, buff, strlen((char *)buff)));
    printf("CRC32_STM32:\t%08X\r\n",  uiCRC32_STM32(NULL, (uint32_t *)buff, strlen((char *)buff)));

    return 0;
}
