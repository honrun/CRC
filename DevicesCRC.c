#include "stdint.h"
#include "DevicesCRC.h"



uint32_t uiReflect(uint32_t uiData, uint8_t ucLength)
{
    uint32_t uiMask = 1 << (ucLength - 1), uiMaskRef = 1, uiDataReturn = 0;

    for(; uiMask; uiMask >>= 1)
    {
        if(uiData & uiMask)
            uiDataReturn |= uiMaskRef;

        uiMaskRef <<= 1;
    }

    return uiDataReturn;
}

uint32_t uiCRC32(uint32_t *puiInitCRC, uint8_t *pucDataBuff, uint32_t uiLength)
{
    uint32_t uiPolynomial = 0x04C11DB7, uiInputCRC = 0xFFFFFFFF, i = 0;
    uint8_t ucMask = 0;

    if(puiInitCRC != NULL)
        uiInputCRC = *puiInitCRC;

    uiPolynomial = uiReflect(uiPolynomial, 32);

    for(i = 0; i < uiLength; ++i)
    {
        uiInputCRC ^= *pucDataBuff++;

        for(ucMask = 1; ucMask; ucMask <<= 1)
        {
            if(uiInputCRC & 1)
                uiInputCRC = (uiInputCRC >> 1) ^ uiPolynomial;
            else
                uiInputCRC >>= 1;
        }
    }

    return ~uiInputCRC;
}

uint32_t uiCRC32_BZIP2(uint32_t *puiInitCRC, uint8_t *pucDataBuff, uint32_t uiLength)
{
    uint32_t uiPolynomial = 0x04C11DB7, uiInputCRC = 0xFFFFFFFF, i = 0;
    uint8_t ucMask = 0;

    if(puiInitCRC != NULL)
        uiInputCRC = *puiInitCRC;

    for(i = 0; i < uiLength; ++i)
    {
        uiInputCRC ^= (uint32_t)(*pucDataBuff++) << 24;

        for(ucMask = 1; ucMask; ucMask <<= 1)
        {
            if(uiInputCRC & 0x80000000)
                uiInputCRC = (uiInputCRC << 1) ^ uiPolynomial;
            else
                uiInputCRC <<= 1;
        }
    }

    return ~uiInputCRC;
}

uint32_t uiCRC32_MPEG2(uint32_t *puiInitCRC, uint8_t *pucDataBuff, uint32_t uiLength)
{
    uint32_t uiPolynomial = 0x04C11DB7, uiInputCRC = 0xFFFFFFFF, i = 0;
    uint8_t ucMask = 0;

    if(puiInitCRC != NULL)
        uiInputCRC = *puiInitCRC;

    for(i = 0; i < uiLength; ++i)
    {
        uiInputCRC ^= (uint32_t)(*pucDataBuff++) << 24;

        for(ucMask = 1; ucMask; ucMask <<= 1)
        {
            if(uiInputCRC & 0x80000000)
                uiInputCRC = (uiInputCRC << 1) ^ uiPolynomial;
            else
                uiInputCRC <<= 1;
        }
    }

    return uiInputCRC;
}

uint32_t uiCRC32_POSIX(uint32_t *puiInitCRC, uint8_t *pucDataBuff, uint32_t uiLength)
{
    uint32_t uiPolynomial = 0x04C11DB7, uiInputCRC = 0, i = 0;
    uint8_t ucMask = 0;

    if(puiInitCRC != NULL)
        uiInputCRC = *puiInitCRC;

    for(i = 0; i < uiLength; ++i)
    {
        uiInputCRC ^= (uint32_t)(*pucDataBuff++) << 24;

        for(ucMask = 1; ucMask; ucMask <<= 1)
        {
            if(uiInputCRC & 0x80000000)
                uiInputCRC = (uiInputCRC << 1) ^ uiPolynomial;
            else
                uiInputCRC <<= 1;
        }
    }

    return ~uiInputCRC;
}

uint32_t uiCRC32_JAMCRC(uint32_t *puiInitCRC, uint8_t *pucDataBuff, uint32_t uiLength)
{
    uint32_t uiPolynomial = 0x04C11DB7, uiInputCRC = 0xFFFFFFFF, i = 0;
    uint8_t ucMask = 0;

    if(puiInitCRC != NULL)
        uiInputCRC = *puiInitCRC;

    uiPolynomial = uiReflect(uiPolynomial, 32);

    for(i = 0; i < uiLength; ++i)
    {
        uiInputCRC ^= *pucDataBuff++;

        for(ucMask = 1; ucMask; ucMask <<= 1)
        {
            if(uiInputCRC & 1)
                uiInputCRC = (uiInputCRC >> 1) ^ uiPolynomial;
            else
                uiInputCRC >>= 1;
        }
    }

    return uiInputCRC;
}

uint32_t uiCRC32_STM32(uint32_t *puiInitCRC, uint32_t *pucDataBuff, uint32_t uiLength)
{
    uint32_t uiPolynomial = 0x04C11DB7, uiInputCRC = 0xFFFFFFFF, i = 0, xbit = 0x80000000, uiMask = 0, uiDataTemp = 0;

    if(puiInitCRC != NULL)
        uiInputCRC = *puiInitCRC;

    for(i = 0; i < uiLength; ++i)
    {
        uiDataTemp = *pucDataBuff++;
        xbit = 0x80000000;

        for(uiMask = 1; uiMask; uiMask <<= 1)
        {
            if(uiInputCRC & 0x80000000)
                uiInputCRC = (uiInputCRC << 1) ^ uiPolynomial;
            else
                uiInputCRC <<= 1;

            if(uiDataTemp & xbit)
                uiInputCRC ^= uiPolynomial;

            xbit >>= 1;
        }
    }

    return uiInputCRC;
}
