#ifndef PSNFIX_H
#define PSNFIX_H

void patch_npsignup(SceModule2* mod);
void patch_npsignin(SceModule2* mod);
void patch_np(SceModule2* mod, u8 major, u8 minor);

#endif