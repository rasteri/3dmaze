#include <windows.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "sscommon.h"

BOOL andy_BGRAImageLoad(char *filename, TEXTURE* ptex)
{
    DWORD compress;
    DWORD size;
    DWORD* pal;
    DWORD* pdwA8;

    FILE* fp;

    fp = fopen(filename, "rb");
    if (!fp) return FALSE;

    // assume images are always 256x256
    // can't see that biting me on the arse in any way
    ptex->width = 256;
    ptex->height = 256;
    size = ptex->width * ptex->height;

    // Allocate data for final image
    ptex->data = malloc(size * 4);

    if (ptex->data == NULL)
    {
        return FALSE;
    }



    ptex->pal_size = 0;
    ptex->pal = NULL;

    // Unpack 8bpp data into final image

    if (fread(ptex->data, size * 4, 1, fp) != 1) {
        fclose(fp);
        return NULL;
    }

    fclose(fp);

    ptex->format = GL_BGRA_EXT;
    ptex->components = 4;

    return TRUE;
}
