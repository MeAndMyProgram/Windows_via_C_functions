#pragma once
#include <stdint.h>
#include <windows.h>

#define NO_DESCRIPTION_MESSAGE "No description found to this error number"

char* DescribeError(uint32_t errorCode);
void getFormatMessageUseNetMsgLibrary(uint32_t errorCode, uint32_t languageIdentifier, char* errorDescription, uint32_t* isSuccess);