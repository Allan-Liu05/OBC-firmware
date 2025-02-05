#pragma once

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

uint8_t unpackUint8(const uint8_t* buffer, uint32_t* offset);

uint16_t unpackUint16(const uint8_t* buffer, uint32_t* offset);

uint32_t unpackUint32(const uint8_t* buffer, uint32_t* offset);

int8_t unpackInt8(const uint8_t* buffer, uint32_t* offset);

int16_t unpackInt16(const uint8_t* buffer, uint32_t* offset);

int32_t unpackInt32(const uint8_t* buffer, uint32_t* offset);

float unpackFloat(const uint8_t* buffer, uint32_t* offset);

#ifdef __cplusplus
}
#endif
