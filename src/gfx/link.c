#include "link.h"
#include <fileioc.h>

#define link_HEADER_SIZE 4

unsigned char *link_appvar[33] =
{
    (unsigned char*)4,
    (unsigned char*)456,
    (unsigned char*)872,
    (unsigned char*)1324,
    (unsigned char*)1794,
    (unsigned char*)2282,
    (unsigned char*)2734,
    (unsigned char*)3150,
    (unsigned char*)3602,
    (unsigned char*)4072,
    (unsigned char*)4560,
    (unsigned char*)5082,
    (unsigned char*)5564,
    (unsigned char*)6072,
    (unsigned char*)6599,
    (unsigned char*)7121,
    (unsigned char*)7643,
    (unsigned char*)8120,
    (unsigned char*)8626,
    (unsigned char*)9128,
    (unsigned char*)9650,
    (unsigned char*)10102,
    (unsigned char*)10536,
    (unsigned char*)10988,
    (unsigned char*)11494,
    (unsigned char*)11982,
    (unsigned char*)12434,
    (unsigned char*)12868,
    (unsigned char*)13320,
    (unsigned char*)13826,
    (unsigned char*)14314,
    (unsigned char*)14766,
    (unsigned char*)15243,
};

unsigned char link_init(void)
{
    unsigned int data, i;
    uint8_t appvar;

    appvar = ti_Open("link", "r");
    if (appvar == 0)
    {
        return 0;
    }

    data = (unsigned int)ti_GetDataPtr(appvar) - (unsigned int)link_appvar[0] + link_HEADER_SIZE;
    for (i = 0; i < 33; i++)
    {
        link_appvar[i] += data;
    }

    ti_Close(appvar);

    return 1;
}

