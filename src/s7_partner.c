#include "snap7.h"
#include "erlcmd.h"
#include <err.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <poll.h>
#include <stdio.h>
#define MAX_READ 1023

int MyDB32[256]; // byte is a portable type of snap7.h
ei_x_buff x;

S7Object Client;

int main()
{
    struct erlcmd handler;
    Client = Cli_Create();
    void *param;
    int result = Cli_ConnectTo(Client,"192.168.0.1",0,1);
    printf("r = %d", result);

    Cli_DBRead(Client, 1, 2, 4, MyDB32);

    result = Cli_GetParam(Client, 2, param);
    printf("r = %d", result);
    printf("r = %d", (int16_t)param);
    // printf("0x");
    // printf("%04x", MyDB32[0]);
    printf("\n");
    
    Cli_Destroy(&Client);    
}