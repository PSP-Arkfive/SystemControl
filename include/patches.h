#ifndef PATCHES_H
#define PATCHES_H

#include <psptypes.h>

u32 _findJAL(u32 addr, int reversed, int skip);
#define findFirstJAL(addr) _findJAL(addr, 0, 0)
#define findFirstJALReverse(addr) _findJAL(addr, 1, 0)
#define findJAL(addr, pos) _findJAL(addr, 0, pos)
#define findJALReverse(addr, pos) _findJAL(addr, 1, pos)
#define findFirstJALForFunction(modname, libname, uid) findFirstJAL(FindFunction(modname, libname, uid))
#define findJALForFunction(modname, libname, uid, pos) findJAL(FindFunction(modname, libname, uid), pos)
#define findFirstJALReverseForFunction(modname, libname, uid) findFirstJALReverse(FindFunction(modname, libname, uid))
#define findJALReverseForFunction(modname, libname, uid, pos) findJALReverse(FindFunction(modname, libname, uid), pos)

u32 FindFirstBEQ(u32 addr);
u32 findRefInGlobals(char* libname, u32 addr, u32 ptr);

#endif