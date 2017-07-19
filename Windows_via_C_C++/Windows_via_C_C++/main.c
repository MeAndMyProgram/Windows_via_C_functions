#include "BookExamples.h"
#include <stdio.h>

void main(int32_t argc, char* argv[])
{
  if (argc == 2)
  {
    char* errorDescription = DescribeError(atoi(argv[1]));
    printf("%s\n", errorDescription);
    if (strcmp(errorDescription, NO_DESCRIPTION_MESSAGE) != 0)
    {
      LocalFree(errorDescription);
    }
  }
  else
  {
    printf("You must provide error code as an argument\n");
  }
}