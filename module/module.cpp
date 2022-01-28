#include "../module.h"

#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;

static char buf[4096];
char *ptr = NULL;


int encodeRequest(char* data, int maxLen)
{
    const char * ping = "ping";
    auto size = strlen(ping);

    //只做一次初始化
    if (ptr == NULL)
    {

        memset(buf, 0, 4096);
        memcpy(buf, &size, sizeof(uint16_t));
        memcpy(buf + sizeof(uint16_t), ping, size);

        ptr = buf;
    }

    int len = sizeof(uint16_t) + size;
       
    if (len > maxLen) 
        return -1;

    memcpy(data, ptr, len);

    return len;
}

int decodeResponse(char* data, int len)
{
    return 0;
}

