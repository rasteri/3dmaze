#ifndef __GLMAZE_H__
#define __GLMAZE_H__

#include "sscommon.h"
#include "maze_std.h"

#ifdef __cplusplus
extern "C" {
#endif

enum {
    TEX_WALL  = 0,
    TEX_FLOOR,
    TEX_CEILING,
    TEX_START,
    TEX_END,
    TEX_RAT,
    TEX_AD,
    TEX_COVER,
    TEX_SHTG0,
    TEX_SHTG1,
    TEX_SHTG2,
    TEX_SHTG3,
    TEX_SHTG4,
    TEX_SHTG5,
    NUM_TEXTURES
};

void UseTextureEnv( TEX_ENV *pTexEnv );

#define MAX_RATS 10

extern MazeOptions maze_options;
extern TEX_RES gTexResSurf[];

#ifdef __cplusplus
}
#endif

#endif
