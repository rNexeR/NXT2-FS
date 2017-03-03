#ifndef _DEVICE_H_
#define _DEVICE_H_

#ifdef __cplusplus
extern "C" {
#endif

#include "structures.h"

static struct s_superblock es;
static uint32 size_of_block;
static uint32 size_of_fragment;

int device_open(const char *path);
void device_close();
void device_flush();

#ifdef __cplusplus
}
#endif

#endif
