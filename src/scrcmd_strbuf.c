#include "scrcmd.h"
#include "event_data.h"
#include "filesystem.h"
#include "item.h"
#include "msgdata/msg.naix"
#include "party.h"
#include "player_data.h"
#include "pokemon_storage_system.h"
#include "save_arrays.h"

static STRING* _get_species_name(u16 species, HeapID heap_id);
extern u16 GetStarterFromScriptState(SCRIPT_STATE*);
extern u16 DPPtLeftover_GetRivalSpecies(SCRIPT_STATE*);
extern u16 DPPtLeftover_GetFriendStarterSpecies(SCRIPT_STATE*);
extern u32 sub_0208E55C(u8, u32);
extern u8 sub_0205B46C(u32 gender, u32 avatar, u32 attr);
extern u32 sub_0205BB1C(u32 num);
extern void sub_02068F98(u32 map_sec, u32 attr, STRING *dest);

BOOL ScrCmd_BufferStatName(SCRIPTCONTEXT* ctx) {
    MSGFMT** msg_fmt = FieldSysGetAttrAddr(ctx->fsys, UNK80_10_C_MSGFMT);
    u8 idx = ScriptReadByte(ctx);
    u8 stat_id = ScriptGetVar(ctx);

    BufferStatName(*msg_fmt, idx, stat_id);

    return FALSE;
}

BOOL ScrCmd_BufferPlayersName(SCRIPTCONTEXT* ctx) {
    FieldSystem* fsys = ctx->fsys;
    MSGFMT** msg_fmt = FieldSysGetAttrAddr(ctx->fsys, UNK80_10_C_MSGFMT);
    u8 idx = ScriptReadByte(ctx);
    PLAYERPROFILE* profile = Sav2_PlayerData_GetProfileAddr(ScriptEnvironment_GetSav2Ptr(fsys));

    BufferPlayersName(*msg_fmt, idx, profile);

    return FALSE;
}

BOOL ScrCmd_BufferRivalsName(SCRIPTCONTEXT* ctx) {
    FieldSystem* fsys = ctx->fsys;
    MSGFMT** msg_fmt = FieldSysGetAttrAddr(ctx->fsys, UNK80_10_C_MSGFMT);
    u8 idx = ScriptReadByte(ctx);

    BufferRivalsName(*msg_fmt, idx, fsys->savedata);

    return FALSE;
}

BOOL ScrCmd_BufferFriendsName(SCRIPTCONTEXT* ctx) {
    FieldSystem* fsys = ctx->fsys;
    MSGFMT** msg_fmt = FieldSysGetAttrAddr(ctx->fsys, UNK80_10_C_MSGFMT);
    u8 idx = ScriptReadByte(ctx);

    BufferFriendsName(*msg_fmt, idx, fsys->savedata);

    return FALSE;
}

BOOL ScrCmd_BufferMonSpeciesName(SCRIPTCONTEXT* ctx) {
    FieldSystem* fsys = ctx->fsys;
    MSGFMT** msg_fmt = FieldSysGetAttrAddr(fsys, UNK80_10_C_MSGFMT);
    u8 idx = ScriptReadByte(ctx);
    u16 party_mon_idx = ScriptGetVar(ctx);

    PARTY* party = SavArray_PlayerParty_get(fsys->savedata);
    POKEMON* party_mon = GetPartyMonByIndex(party, party_mon_idx);
    BufferBoxMonSpeciesName(*msg_fmt, idx, &party_mon->box);

    return FALSE;
}

BOOL ScrCmd_BufferTypeName(SCRIPTCONTEXT* ctx) {
    MSGFMT** msg_fmt = FieldSysGetAttrAddr(ctx->fsys, UNK80_10_C_MSGFMT);
    u8 idx = ScriptReadByte(ctx);
    u16 type_id = ScriptGetVar(ctx);

    BufferTypeName(*msg_fmt, idx, type_id);

    return FALSE;
}

BOOL ScrCmd_BufferItemName(SCRIPTCONTEXT* ctx) {
    MSGFMT** msg_fmt = FieldSysGetAttrAddr(ctx->fsys, UNK80_10_C_MSGFMT);
    u8 idx = ScriptReadByte(ctx);
    u16 item_id = ScriptGetVar(ctx);

    BufferItemName(*msg_fmt, idx, item_id);

    return FALSE;
}

BOOL ScrCmd_BufferPocketName(SCRIPTCONTEXT* ctx) {
    MSGFMT** msg_fmt = FieldSysGetAttrAddr(ctx->fsys, UNK80_10_C_MSGFMT);
    u8 idx = ScriptReadByte(ctx);
    u16 pocket_id = ScriptGetVar(ctx);

    BufferPocketName(*msg_fmt, idx, pocket_id);

    return FALSE;
}

BOOL ScrCmd_BufferTMHMMoveName(SCRIPTCONTEXT* ctx) {
    MSGFMT** msg_fmt = FieldSysGetAttrAddr(ctx->fsys, UNK80_10_C_MSGFMT);
    u8 idx = ScriptReadByte(ctx);
    u16 move_id = ScriptGetVar(ctx);

    BufferMoveName(*msg_fmt, idx, TMHMGetMove(move_id));

    return FALSE;
}

BOOL ScrCmd_BufferMoveName(SCRIPTCONTEXT* ctx) {
    MSGFMT** msg_fmt = FieldSysGetAttrAddr(ctx->fsys, UNK80_10_C_MSGFMT);
    u8 idx = ScriptReadByte(ctx);
    u16 move_id = ScriptGetVar(ctx);

    BufferMoveName(*msg_fmt, idx, move_id);

    return FALSE;
}

BOOL ScrCmd_BufferInt(SCRIPTCONTEXT* ctx) {
    MSGFMT** msg_fmt = FieldSysGetAttrAddr(ctx->fsys, UNK80_10_C_MSGFMT);
    u8 idx = ScriptReadByte(ctx);
    u16 number = ScriptGetVar(ctx);

    BufferIntegerAsString(*msg_fmt, idx, number, sub_0205BB1C(number), STRCONVMODE_RIGHT_ALIGN, TRUE);

    return FALSE;
}

BOOL ScrCmd_BufferIntEx(SCRIPTCONTEXT* ctx) {
    MSGFMT** msg_fmt = FieldSysGetAttrAddr(ctx->fsys, UNK80_10_C_MSGFMT);
    u8 idx = ScriptReadByte(ctx);
    u16 number = ScriptGetVar(ctx);
    u8 str_conv_mode = ScriptReadByte(ctx);
    u8 unk2 = ScriptReadByte(ctx);

    u8 digits = unk2;
    if (str_conv_mode == STRCONVMODE_LEFT_ALIGN) {
        digits = sub_0205BB1C(number);
    }

    BufferIntegerAsString(*msg_fmt, idx, number, digits, str_conv_mode, TRUE);

    return FALSE;
}

BOOL ScrCmd_661(SCRIPTCONTEXT* ctx) {
    MSGFMT** msg_fmt = FieldSysGetAttrAddr(ctx->fsys, UNK80_10_C_MSGFMT);
    u8 idx = ScriptReadByte(ctx);
    u32 number = ScriptReadWord(ctx);
    u8 str_conv_mode = ScriptReadByte(ctx);
    u8 unk2 = ScriptReadByte(ctx);

    u8 digits = unk2;
    if (str_conv_mode == STRCONVMODE_LEFT_ALIGN) {
        digits = sub_0205BB1C(number);
    }

    BufferIntegerAsString(*msg_fmt, idx, number, digits, str_conv_mode, TRUE);

    return FALSE;
}

BOOL ScrCmd_BufferPartyMonNick(SCRIPTCONTEXT* ctx) {
    FieldSystem* fsys = ctx->fsys;
    MSGFMT** msg_fmt = FieldSysGetAttrAddr(fsys, UNK80_10_C_MSGFMT);
    u8 idx = ScriptReadByte(ctx);
    u16 party_mon_idx = ScriptGetVar(ctx);

    PARTY* party = SavArray_PlayerParty_get(fsys->savedata);
    POKEMON* party_mon = GetPartyMonByIndex(party, party_mon_idx);
    BufferBoxMonNickname(*msg_fmt, idx, &party_mon->box);

    return FALSE;
}

BOOL ScrCmd_BufferBoxMonNick(SCRIPTCONTEXT* ctx) {
    FieldSystem* fsys = ctx->fsys;
    PC_STORAGE* pc = GetStoragePCPointer(fsys->savedata);
    MSGFMT** msg_fmt = FieldSysGetAttrAddr(fsys, UNK80_10_C_MSGFMT);
    u8 idx = ScriptReadByte(ctx);
    u16 box_mon_slot = ScriptGetVar(ctx);

    BOXMON* box_mon = PCStorage_GetMonByIndexPair(pc, box_mon_slot / MONS_PER_BOX, box_mon_slot % MONS_PER_BOX);
    BufferBoxMonNickname(*msg_fmt, idx, box_mon);

    return FALSE;
}

BOOL ScrCmd_BufferTrainerClassName(SCRIPTCONTEXT* ctx) {
    MSGFMT** msg_fmt = FieldSysGetAttrAddr(ctx->fsys, UNK80_10_C_MSGFMT);
    u8 idx = ScriptReadByte(ctx);
    u16 trainer_class_id = ScriptGetVar(ctx);

    BufferTrainerClassName(*msg_fmt, idx, trainer_class_id);

    return FALSE;
}

BOOL ScrCmd_BufferPlayerUnionAvatarClassName(SCRIPTCONTEXT* ctx) {
    FieldSystem* fsys = ctx->fsys;
    SAVEDATA* savedata = ScriptEnvironment_GetSav2Ptr(fsys);
    PLAYERPROFILE* profile = Sav2_PlayerData_GetProfileAddr(savedata);
    MSGFMT** msg_fmt = FieldSysGetAttrAddr(fsys, UNK80_10_C_MSGFMT);
    u8 idx = ScriptReadByte(ctx);
    u32 gender = PlayerProfile_GetTrainerGender(profile);
    u8 avatar = PlayerProfile_GetAvatar(profile);

    BufferTrainerClassNameWithArticle(*msg_fmt, idx, sub_0205B46C(gender, avatar, 2));

    return FALSE;
}

BOOL ScrCmd_BufferSpeciesName(SCRIPTCONTEXT* ctx) {
    MSGFMT** msg_fmt = FieldSysGetAttrAddr(ctx->fsys, UNK80_10_C_MSGFMT);
    u8 idx = ScriptReadByte(ctx);
    u16 species = ScriptGetVar(ctx);
    u16 unk2 = ScriptReadHalfword(ctx);
    u8 unk3 = ScriptReadByte(ctx);

    STRING* species_name = _get_species_name(species, 4);
    BufferString(*msg_fmt, idx, species_name, unk2, unk3, 2);
    String_dtor(species_name);

    return FALSE;
}

STRING* _get_species_name(u16 species, HeapID heap_id) {
    MSGDATA* msg_data = NewMsgDataFromNarc(MSGDATA_LOAD_LAZY, NARC_msgdata_msg, NARC_msg_msg_0237_bin, heap_id);
    STRING* name = NewString_ReadMsgData(msg_data, species);
    DestroyMsgData(msg_data);
    return name;
}

BOOL ScrCmd_BufferStarterSpeciesName(SCRIPTCONTEXT* ctx) {
    MSGFMT** msg_fmt = FieldSysGetAttrAddr(ctx->fsys, UNK80_10_C_MSGFMT);
    u8 idx = ScriptReadByte(ctx);
    u16 species = GetStarterFromScriptState(SavArray_Flags_get(ctx->fsys->savedata));

    STRING* species_name = _get_species_name(species, 4);
    BufferString(*msg_fmt, idx, species_name, 0, 1, 2);
    String_dtor(species_name);

    return FALSE;
}

BOOL ScrCmd_BufferDPPtRivalStarterSpeciesName(SCRIPTCONTEXT* ctx) {
    MSGFMT** msg_fmt = FieldSysGetAttrAddr(ctx->fsys, UNK80_10_C_MSGFMT);
    u8 idx = ScriptReadByte(ctx);
    u16 species = DPPtLeftover_GetRivalSpecies(SavArray_Flags_get(ctx->fsys->savedata));

    STRING* species_name = _get_species_name(species, 4);
    BufferString(*msg_fmt, idx, species_name, 0, 1, 2);
    String_dtor(species_name);

    return FALSE;
}

BOOL ScrCmd_BufferDPPtFriendStarterSpeciesName(SCRIPTCONTEXT* ctx) {
    MSGFMT** msg_fmt = FieldSysGetAttrAddr(ctx->fsys, UNK80_10_C_MSGFMT);
    u8 idx = ScriptReadByte(ctx);
    u16 species = DPPtLeftover_GetFriendStarterSpecies(SavArray_Flags_get(ctx->fsys->savedata));

    STRING* species_name = _get_species_name(species, 4);
    BufferString(*msg_fmt, idx, species_name, 0, 1, 2);
    String_dtor(species_name);

    return FALSE;
}

BOOL ScrCmd_BufferDecorationName(SCRIPTCONTEXT* ctx) {
    MSGFMT** msg_fmt = FieldSysGetAttrAddr(ctx->fsys, UNK80_10_C_MSGFMT);
    u8 idx = ScriptReadByte(ctx);
    u16 decoration_id = ScriptGetVar(ctx);

    BufferDecorationName(*msg_fmt, idx, decoration_id);

    return FALSE;
}

// This may be what's left of ScrCmd_GetUndergroundTrapName from D/P/Pt.
BOOL ScrCmd_208(SCRIPTCONTEXT* ctx) {
    MSGFMT** msg_fmt = FieldSysGetAttrAddr(ctx->fsys, UNK80_10_C_MSGFMT);
    u8 idx = ScriptReadByte(ctx);
    u16 unused_id = ScriptGetVar(ctx);

    return FALSE;
}

// This may be what's left of ScrCmd_GetUndergroundItemName from D/P/Pt.
BOOL ScrCmd_209(SCRIPTCONTEXT* ctx) {
    MSGFMT** msg_fmt = FieldSysGetAttrAddr(ctx->fsys, UNK80_10_C_MSGFMT);
    u8 idx = ScriptReadByte(ctx);
    u16 unused_id = ScriptGetVar(ctx);

    return FALSE;
}

BOOL ScrCmd_BufferMapSecName(SCRIPTCONTEXT* ctx) {
    STRING* str = String_ctor(22, 4);
    MSGFMT** msg_fmt = FieldSysGetAttrAddr(ctx->fsys, UNK80_10_C_MSGFMT);
    u8 idx = ScriptReadByte(ctx);
    u16 map_sec = ScriptGetVar(ctx);

    sub_02068F98(map_sec, 4, str);
    BufferString(*msg_fmt, idx, str, 0, 1, 2);
    String_dtor(str);

    return FALSE;
}

BOOL ScrCmd_BufferBerryName(SCRIPTCONTEXT* ctx) {
    MSGFMT** msg_fmt = FieldSysGetAttrAddr(ctx->fsys, UNK80_10_C_MSGFMT);
    u8 idx = ScriptReadByte(ctx);
    u16 berry_id = ScriptGetVar(ctx);
    u16 unk = ScriptGetVar(ctx);

    STRING* str = GetNutName((u16)(berry_id - FIRST_BERRY_IDX), 32);
    BufferString(*msg_fmt, idx, str, 0, unk < 2, 2);
    String_dtor(str);

    return FALSE;
}

BOOL ScrCmd_BufferNatureName(SCRIPTCONTEXT* ctx) {
    MSGFMT** msg_fmt = FieldSysGetAttrAddr(ctx->fsys, UNK80_10_C_MSGFMT);
    u8 idx = ScriptReadByte(ctx);
    u16 nature_id = ScriptGetVar(ctx);

    BufferNatureName(*msg_fmt, idx, nature_id);

    return FALSE;
}

BOOL ScrCmd_BufferFashionName(SCRIPTCONTEXT* ctx) {
    MSGFMT** msg_fmt = FieldSysGetAttrAddr(ctx->fsys, UNK80_10_C_MSGFMT);
    u8 idx = ScriptReadByte(ctx);
    u16 fashion_id = ScriptGetVar(ctx);

    BufferFashionName(*msg_fmt, idx, fashion_id);

    return FALSE;
}

BOOL ScrCmd_BufferPartyMonMoveName(SCRIPTCONTEXT* ctx) {
    FieldSystem* fsys = ctx->fsys;
    MSGFMT** msg_fmt = FieldSysGetAttrAddr(fsys, UNK80_10_C_MSGFMT);
    u8 idx = ScriptReadByte(ctx);
    u16 party_slot = ScriptGetVar(ctx);
    u16 move_slot = ScriptGetVar(ctx);

    PARTY* party = SavArray_PlayerParty_get(fsys->savedata);
    POKEMON* party_mon = GetPartyMonByIndex(party, party_slot);
    u16 move_id = GetMonData(party_mon, MON_DATA_MOVE1 + move_slot, NULL);
    BufferMoveName(*msg_fmt, idx, move_id);

    return FALSE;
}

BOOL ScrCmd_BufferRibbonName(SCRIPTCONTEXT* ctx) {
    MSGFMT** msg_fmt = FieldSysGetAttrAddr(ctx->fsys, UNK80_10_C_MSGFMT);
    u8 idx = ScriptReadByte(ctx);
    u8 unk = ScriptGetVar(ctx);

    u16 ribbon_id = sub_0208E55C(unk, 3);
    BufferRibbonNameOrDesc(*msg_fmt, idx, ribbon_id);

    return FALSE;
}

BOOL ScrCmd_BufferSealName(SCRIPTCONTEXT* ctx) {
    MSGFMT** msg_fmt = FieldSysGetAttrAddr(ctx->fsys, UNK80_10_C_MSGFMT);
    u8 idx = ScriptReadByte(ctx);
    u16 seal_id = ScriptGetVar(ctx);

    BufferSealName(*msg_fmt, idx, seal_id);

    return FALSE;
}

BOOL ScrCmd_BufferTrainerName(SCRIPTCONTEXT* ctx) {
    MSGFMT** msg_fmt = FieldSysGetAttrAddr(ctx->fsys, UNK80_10_C_MSGFMT);
    u8 idx = ScriptReadByte(ctx);
    u16 trainer_id = ScriptGetVar(ctx);

    BufferTrainerName(*msg_fmt, idx, trainer_id);

    return FALSE;
}

BOOL ScrCmd_BufferApricornName(SCRIPTCONTEXT* ctx) {
    MSGFMT** msg_fmt = FieldSysGetAttrAddr(ctx->fsys, UNK80_10_C_MSGFMT);
    u8 idx = ScriptReadByte(ctx);
    u8 apricorn_id = ScriptGetVar(ctx);

    BufferApricornName(*msg_fmt, idx, apricorn_id);

    return FALSE;
}

BOOL ScrCmd_BufferItemNameIndef(SCRIPTCONTEXT* ctx) {
    MSGFMT** msg_fmt = FieldSysGetAttrAddr(ctx->fsys, UNK80_10_C_MSGFMT);
    u8 idx = ScriptReadByte(ctx);
    u16 item_id = ScriptGetVar(ctx);

    BufferItemNameWithIndefArticle(*msg_fmt, idx, item_id);

    return FALSE;
}

BOOL ScrCmd_BufferItemNamePlural(SCRIPTCONTEXT* ctx) {
    MSGFMT** msg_fmt = FieldSysGetAttrAddr(ctx->fsys, UNK80_10_C_MSGFMT);
    u8 idx = ScriptReadByte(ctx);
    u16 item_id = ScriptGetVar(ctx);

    BufferItemNamePlural(*msg_fmt, idx, item_id);

    return FALSE;
}

BOOL ScrCmd_BufferPartyMonSpeciesNameIndef(SCRIPTCONTEXT* ctx) {
    FieldSystem* fsys = ctx->fsys;
    MSGFMT** msg_fmt = FieldSysGetAttrAddr(fsys, UNK80_10_C_MSGFMT);
    u8 idx = ScriptReadByte(ctx);
    u16 party_mon_slot = ScriptGetVar(ctx);

    PARTY* party = SavArray_PlayerParty_get(fsys->savedata);
    POKEMON* party_mon = GetPartyMonByIndex(party, party_mon_slot);
    BufferBoxMonSpeciesNameWithArticle(*msg_fmt, idx, &party_mon->box);

    return FALSE;
}

BOOL ScrCmd_BufferSpeciesNameIndef(SCRIPTCONTEXT* ctx) {
    MSGFMT** msg_fmt = FieldSysGetAttrAddr(ctx->fsys, UNK80_10_C_MSGFMT);
    u8 idx = ScriptReadByte(ctx);
    u16 item_id = ScriptGetVar(ctx);
    u16 unused1 = ScriptReadHalfword(ctx);
    u8 unused2 = ScriptReadByte(ctx);

    BufferSpeciesNameWithArticle(*msg_fmt, idx, item_id);

    return FALSE;
}

BOOL ScrCmd_BufferDPPtFriendStarterSpeciesNameIndef(SCRIPTCONTEXT* ctx) {
    MSGFMT** msg_fmt = FieldSysGetAttrAddr(ctx->fsys, UNK80_10_C_MSGFMT);
    u8 idx = ScriptReadByte(ctx);
    u16 species = DPPtLeftover_GetFriendStarterSpecies(SavArray_Flags_get(ctx->fsys->savedata));

    BufferSpeciesNameWithArticle(*msg_fmt, idx, species);

    return FALSE;
}

BOOL ScrCmd_BufferFashionNameIndef(SCRIPTCONTEXT* ctx) {
    MSGFMT** msg_fmt = FieldSysGetAttrAddr(ctx->fsys, UNK80_10_C_MSGFMT);
    u8 idx = ScriptReadByte(ctx);
    u16 fashion_id = ScriptGetVar(ctx);

    BufferFashionNameWithArticle(*msg_fmt, idx, fashion_id);

    return FALSE;
}

BOOL ScrCmd_BufferTrainerClassNameIndef(SCRIPTCONTEXT* ctx) {
    MSGFMT** msg_fmt = FieldSysGetAttrAddr(ctx->fsys, UNK80_10_C_MSGFMT);
    u8 idx = ScriptReadByte(ctx);
    u16 trainer_class_id = ScriptGetVar(ctx);

    BufferTrainerClassNameWithArticle(*msg_fmt, idx, trainer_class_id);

    return FALSE;
}

BOOL ScrCmd_BufferSealNamePlural(SCRIPTCONTEXT* ctx) {
    MSGFMT** msg_fmt = FieldSysGetAttrAddr(ctx->fsys, UNK80_10_C_MSGFMT);
    u8 idx = ScriptReadByte(ctx);
    u16 seal_id = ScriptGetVar(ctx);

    BufferSealNamePlural(*msg_fmt, idx, seal_id);

    return FALSE;
}

BOOL ScrCmd_Capitalize(SCRIPTCONTEXT* ctx) {
    MSGFMT** msg_fmt = FieldSysGetAttrAddr(ctx->fsys, UNK80_10_C_MSGFMT);
    u8 idx = ScriptReadByte(ctx);

    ScrStrBufs_UpperFirstChar(*msg_fmt, idx);

    return FALSE;
}
