#include "BookExamples.h"

void getFormatMessageUseNetMsgLibrary(uint32_t errorCode, uint32_t languageIdentifier, char* errorDescription, uint32_t* isSuccess);

char* DescribeError(uint32_t errorCode)
{
  char* errorDescription = NULL;
  uint32_t languageIdentifier = MAKELANGID(LANG_ENGLISH, SUBLANG_ENGLISH_US);
  uint32_t isSuccess = FormatMessageA
  (
    FORMAT_MESSAGE_FROM_SYSTEM | FORMAT_MESSAGE_IGNORE_INSERTS 
    | FORMAT_MESSAGE_ALLOCATE_BUFFER,
    NULL,
    errorCode,
    languageIdentifier,
    (LPSTR)&errorDescription,
    0,
    NULL
  );
  if (!isSuccess)
  {
    getFormatMessageUseNetMsgLibrary(errorCode, languageIdentifier, errorDescription, &isSuccess);
  }
  if (isSuccess)
  {
    return errorDescription;
  }
  else 
  {
    return NO_DESCRIPTION_MESSAGE;
  }
}

void getFormatMessageUseNetMsgLibrary(uint32_t errorCode, uint32_t languageIdentifier, char* errorDescription, uint32_t* isSuccess)
{
  const void* hDll = LoadLibraryExA("netmsg.dll", NULL,
    DONT_RESOLVE_DLL_REFERENCES);
  if (hDll != NULL)
  {
    *isSuccess = FormatMessageA
    (
      FORMAT_MESSAGE_FROM_HMODULE | FORMAT_MESSAGE_IGNORE_INSERTS
      | FORMAT_MESSAGE_ALLOCATE_BUFFER,
      hDll,
      errorCode,
      languageIdentifier,
      (LPSTR)&errorDescription,
      0,
      NULL
    );
    FreeLibrary((HMODULE)hDll);
  }
}