#ifndef POKEHEARTGOLD_UNK_0201660C_H
#define POKEHEARTGOLD_UNK_0201660C_H

#include "heap.h"
#include "bg_window.h"

typedef struct Unk122_021E6900 {
    BgConfig *bgConfig;
    int unk4;
    int unk8;
    int unkC;
    u8 unk10;
    u8 unk11;
    u8 unk12_0 : 4;
    u8 unk12_4 : 4;
    u8 unk13;
} Unk122_021E6900;

void sub_020166FC(void *, Unk122_021E6900 *);
int sub_020168F4(void *);
void sub_020169CC(void *);
void *sub_0201660C(HeapID);
void sub_02016624(void *);
void sub_02016704(void *, Unk122_021E6900 *, PaletteData *);
u32 sub_02016748(void *);
int sub_020169C0(void *);

#endif //POKEHEARTGOLD_UNK_0201660C_H
