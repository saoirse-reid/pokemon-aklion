#include "global.h"
#include "heap.h"
#include "map_section.h"
#include "message_format.h"
#include "msgdata.h"
#include "pokemon.h"
#include "string_util.h"
#include "trainer_memo.h"
#include "constants/events.h"
#include "constants/map_sections.h"
#include "constants/pokemon.h"
#include "msgdata/msg.naix"
#include "msgdata/msg/msg_0302.h"

typedef enum MetCondition {
    MET_CONDITION_WILD_ENCOUNTER,
    MET_CONDITION_WILD_ENCOUNTER_TRADED,
    MET_CONDITION_WILD_GIFT,
    MET_CONDITION_EGG_HATCHED,
    MET_CONDITION_EGG_HATCHED_TRADED,
    MET_CONDITION_EGG_HATCHED_GIFT,
    MET_CONDITION_EGG_HATCHED_GIFT_TRADED,
    MET_CONDITION_FATEFUL_ENCOUNTER,
    MET_CONDITION_FATEFUL_ENCOUNTER_TRADED,
    MET_CONDITION_FATEFUL_EGG_HATCHED,
    MET_CONDITION_FATEFUL_EGG_HATCHED_TRADED,
    MET_CONDITION_FATEFUL_EGG_HATCHED_ARRIVED,
    MET_CONDITION_FATEFUL_EGG_HATCHED_ARRIVED_TRADED,
    MET_CONDITION_FATEFUL_EGG_HATCHED_GIFT,
    MET_CONDITION_FATEFUL_EGG_HATCHED_GIFT_TRADED,
    MET_CONDITION_MIGRATED,
    MET_CONDITION_EGG,
    MET_CONDITION_EGG_TRADED,
    MET_CONDITION_FATEFUL_EGG,
    MET_CONDITION_FATEFUL_EGG_TRADED,
    MET_CONDITION_FATEFUL_EGG_ARRIVED,
} MetCondition;


static const u16 sFlavorMsgs[6] = {
    msg_0302_00070, msg_0302_00065, msg_0302_00066, msg_0302_00067, msg_0302_00068, msg_0302_00069,
};

static const u16 sCharactersticMsgs[6][5] = {
    { msg_0302_00071, msg_0302_00072, msg_0302_00073, msg_0302_00074, msg_0302_00075 },
    { msg_0302_00076, msg_0302_00077, msg_0302_00078, msg_0302_00079, msg_0302_00080 },
    { msg_0302_00081, msg_0302_00082, msg_0302_00083, msg_0302_00084, msg_0302_00085 },
    { msg_0302_00086, msg_0302_00087, msg_0302_00088, msg_0302_00089, msg_0302_00090 },
    { msg_0302_00091, msg_0302_00092, msg_0302_00093, msg_0302_00094, msg_0302_00095 },
    { msg_0302_00096, msg_0302_00097, msg_0302_00098, msg_0302_00099, msg_0302_00100 },
};

static MetCondition MonMetCondition(Pokemon *mon, BOOL isMine);
static void FormatNature(Unk0208E600 *a0);
static void FormatDateAndLocationMet(Unk0208E600 *a0, int msgNo);
static void FormatDateAndLocation_Migrated(Unk0208E600 *a0, int msgNo);
static void FormatFlavorPreference(Unk0208E600 *a0);
static void FormatDateAndLocation_Egg(Unk0208E600 *a0, int msgNo, BOOL hatched);
static void FormatEggWatch(Unk0208E600 *a0);
static void sub_0208F5C8(BoxPokemon *boxMon, BOOL isEgg);
static void sub_0208F550(BoxPokemon *boxMon, int mapsec, BOOL isNotEgg);
static void SetFatefulEncounter(BoxPokemon *boxMon);
static void CopyLevelToMetLevel(BoxPokemon *boxMon);
static void SetOriginalTrainerData(BoxPokemon *boxMon, PlayerProfile *profile, HeapID heapId);

Unk0208E600 *sub_0208E600(Pokemon *mon, BOOL isMine, HeapID heapId, int a3) {
    Unk0208E600 *ptr = AllocFromHeap(heapId, sizeof(Unk0208E600));
    ptr->heapId = heapId;
    ptr->msgData = NewMsgDataFromNarc(MSGDATA_LOAD_LAZY, NARC_msgdata_msg, NARC_msg_msg_0302_bin, heapId);
    ptr->msgFmt = MessageFormat_New_Custom(9, 32, ptr->heapId);
    ptr->mon = mon;
    ptr->isMine = isMine;
    ptr->notepad.natureLine = 0;
    ptr->notepad.nature = NULL;
    ptr->notepad.dateLocationMetLine = 0;
    ptr->notepad.dateLocationMet = NULL;
    ptr->notepad.flavorPreferenceLine = 0;
    ptr->notepad.flavorPreference = NULL;
    ptr->notepad.eggWatchLine = 0;
    ptr->notepad.eggWatch = NULL;

    int metCondition = MonMetCondition(ptr->mon, ptr->isMine);
    switch (metCondition) {
    case MET_CONDITION_WILD_ENCOUNTER:
        ptr->notepad.natureLine = 1;
        FormatNature(ptr);
        ptr->notepad.dateLocationMetLine = 2;
        FormatDateAndLocationMet(ptr, msg_0302_00049);
        ptr->notepad.flavorPreferenceLine = 6;
        FormatFlavorPreference(ptr);
        break;
    case MET_CONDITION_WILD_ENCOUNTER_TRADED:
        ptr->notepad.natureLine = 1;
        FormatNature(ptr);
        ptr->notepad.dateLocationMetLine = 2;
        FormatDateAndLocationMet(ptr, msg_0302_00050);
        ptr->notepad.flavorPreferenceLine = 6;
        FormatFlavorPreference(ptr);
        break;
    case MET_CONDITION_WILD_GIFT:
        ptr->notepad.natureLine = 1;
        FormatNature(ptr);
        ptr->notepad.dateLocationMetLine = 2;
        FormatDateAndLocationMet(ptr, msg_0302_00051);
        ptr->notepad.flavorPreferenceLine = 6;
        FormatFlavorPreference(ptr);
        break;
    case MET_CONDITION_EGG_HATCHED:
        ptr->notepad.natureLine = 1;
        FormatNature(ptr);
        ptr->notepad.dateLocationMetLine = 2;
        FormatDateAndLocationMet(ptr, msg_0302_00052);
        ptr->notepad.flavorPreferenceLine = 8;
        FormatFlavorPreference(ptr);
        break;
    case MET_CONDITION_EGG_HATCHED_TRADED:
        ptr->notepad.natureLine = 1;
        FormatNature(ptr);
        ptr->notepad.dateLocationMetLine = 2;
        FormatDateAndLocationMet(ptr, msg_0302_00053);
        ptr->notepad.flavorPreferenceLine = 8;
        FormatFlavorPreference(ptr);
        break;
    case MET_CONDITION_EGG_HATCHED_GIFT:
        ptr->notepad.natureLine = 1;
        FormatNature(ptr);
        ptr->notepad.dateLocationMetLine = 2;
        FormatDateAndLocationMet(ptr, msg_0302_00054);
        ptr->notepad.flavorPreferenceLine = 8;
        FormatFlavorPreference(ptr);
        break;
    case MET_CONDITION_EGG_HATCHED_GIFT_TRADED:
        ptr->notepad.natureLine = 1;
        FormatNature(ptr);
        ptr->notepad.dateLocationMetLine = 2;
        FormatDateAndLocationMet(ptr, msg_0302_00055);
        ptr->notepad.flavorPreferenceLine = 8;
        FormatFlavorPreference(ptr);
        break;
    case MET_CONDITION_FATEFUL_ENCOUNTER:
        ptr->notepad.natureLine = 1;
        FormatNature(ptr);
        ptr->notepad.dateLocationMetLine = 2;
        FormatDateAndLocationMet(ptr, msg_0302_00056);
        ptr->notepad.flavorPreferenceLine = 7;
        FormatFlavorPreference(ptr);
        break;
    case MET_CONDITION_FATEFUL_ENCOUNTER_TRADED:
        ptr->notepad.natureLine = 1;
        FormatNature(ptr);
        ptr->notepad.dateLocationMetLine = 2;
        FormatDateAndLocationMet(ptr, msg_0302_00057);
        ptr->notepad.flavorPreferenceLine = 7;
        FormatFlavorPreference(ptr);
        break;
    case MET_CONDITION_FATEFUL_EGG_HATCHED:
        ptr->notepad.natureLine = 1;
        FormatNature(ptr);
        ptr->notepad.dateLocationMetLine = 2;
        FormatDateAndLocationMet(ptr, msg_0302_00058);
        break;
    case MET_CONDITION_FATEFUL_EGG_HATCHED_TRADED:
        ptr->notepad.natureLine = 1;
        FormatNature(ptr);
        ptr->notepad.dateLocationMetLine = 2;
        FormatDateAndLocationMet(ptr, msg_0302_00059);
        break;
    case MET_CONDITION_FATEFUL_EGG_HATCHED_ARRIVED:
        ptr->notepad.natureLine = 1;
        FormatNature(ptr);
        ptr->notepad.dateLocationMetLine = 2;
        FormatDateAndLocationMet(ptr, msg_0302_00060);
        break;
    case MET_CONDITION_FATEFUL_EGG_HATCHED_ARRIVED_TRADED:
        ptr->notepad.natureLine = 1;
        FormatNature(ptr);
        ptr->notepad.dateLocationMetLine = 2;
        FormatDateAndLocationMet(ptr, msg_0302_00061);
        break;
    case MET_CONDITION_FATEFUL_EGG_HATCHED_GIFT:
        ptr->notepad.natureLine = 1;
        FormatNature(ptr);
        ptr->notepad.dateLocationMetLine = 2;
        FormatDateAndLocationMet(ptr, msg_0302_00062);
        break;
    case MET_CONDITION_FATEFUL_EGG_HATCHED_GIFT_TRADED:
        ptr->notepad.natureLine = 1;
        FormatNature(ptr);
        ptr->notepad.dateLocationMetLine = 2;
        FormatDateAndLocationMet(ptr, msg_0302_00063);
        break;
    case MET_CONDITION_MIGRATED:
        ptr->notepad.natureLine = 1;
        FormatNature(ptr);
        ptr->notepad.dateLocationMetLine = 2;
        FormatDateAndLocation_Migrated(ptr, msg_0302_00064);
        ptr->notepad.flavorPreferenceLine = 6;
        FormatFlavorPreference(ptr);
        break;
    case MET_CONDITION_EGG:
        ptr->notepad.dateLocationMetLine = 1;
        FormatDateAndLocation_Egg(ptr, msg_0302_00101, FALSE);
        ptr->notepad.eggWatchLine = 6;
        FormatEggWatch(ptr);
        break;
    case MET_CONDITION_EGG_TRADED:
        ptr->notepad.dateLocationMetLine = 1;
        FormatDateAndLocation_Egg(ptr, msg_0302_00102, TRUE);
        ptr->notepad.eggWatchLine = 6;
        FormatEggWatch(ptr);
        break;
    case MET_CONDITION_FATEFUL_EGG:
        ptr->notepad.dateLocationMetLine = 1;
        FormatDateAndLocation_Egg(ptr, msg_0302_00103, FALSE);
        ptr->notepad.eggWatchLine = 6;
        FormatEggWatch(ptr);
        break;
    case MET_CONDITION_FATEFUL_EGG_TRADED:
        ptr->notepad.dateLocationMetLine = 1;
        FormatDateAndLocation_Egg(ptr, msg_0302_00103, TRUE);
        ptr->notepad.eggWatchLine = 6;
        FormatEggWatch(ptr);
        break;
    case MET_CONDITION_FATEFUL_EGG_ARRIVED:
        ptr->notepad.dateLocationMetLine = 1;
        FormatDateAndLocation_Egg(ptr, msg_0302_00104, 0);
        ptr->notepad.eggWatchLine = 6;
        FormatEggWatch(ptr);
        break;
    }
    return ptr;
}

void sub_0208E994(Unk0208E600 *a0) {
    if (a0->notepad.nature) {
        FreeToHeap(a0->notepad.nature);
    }
    if (a0->notepad.dateLocationMet) {
        FreeToHeap(a0->notepad.dateLocationMet);
    }
    if (a0->notepad.flavorPreference) {
        FreeToHeap(a0->notepad.flavorPreference);
    }
    if (a0->notepad.eggWatch) {
        FreeToHeap(a0->notepad.eggWatch);
    }
    MessageFormat_Delete(a0->msgFmt);
    DestroyMsgData(a0->msgData);
    FreeToHeap(a0);
}

// Returns true if the Pokemon has the proper metadata to trigger the event.
BOOL MonMetadataMatchesEvent(u8 eventNo, Pokemon *mon, BOOL isMine) {
    u8 metCondition = MonMetCondition(mon, isMine);
    u8 version = GetMonData(mon, MON_DATA_GAME_VERSION, NULL);

    if ((metCondition == MET_CONDITION_FATEFUL_ENCOUNTER || metCondition == MET_CONDITION_FATEFUL_ENCOUNTER_TRADED) &&
        (eventNo != EVENT_ARCEUS_HALL_OF_ORIGIN)) {
            return TRUE;
    }

    switch (eventNo) {
    case EVENT_SPIKY_EARED_PICHU:
        break;
    case EVENT_ARCEUS_HALL_OF_ORIGIN:
        if (metCondition == 1) {
            switch (version) {
            case VERSION_DIAMOND:
            case VERSION_PEARL:
            case VERSION_PLATINUM:
                if (GetMonData(mon, MON_DATA_MET_LOCATION, NULL) == sub_02017FE4(MAPSECTYPE_NORMAL, MAPSEC_HALL_OF_ORIGIN)) {
                    return TRUE;
                }
            }
        }
        break;
    case EVENT_ARCEUS_MOVIE_GIFT:
    case EVENT_CELEBI:
        break;
  }
  return FALSE;
}

static void FormatNature(Unk0208E600 *a0) {
    int nature = GetMonNature(a0->mon);
    if (nature <= NATURE_QUIRKY) {
        a0->notepad.nature = String_New(0x48, a0->heapId);
        ReadMsgDataIntoString(a0->msgData, msg_0302_00024 + nature, a0->notepad.nature);
    }
}

static void FormatDateAndLocationMet(Unk0208E600 *a0, int msgNo) {
    String *str = String_New(0x240, a0->heapId);
    a0->notepad.dateLocationMet = String_New(0x240, a0->heapId);

    ReadMsgDataIntoString(a0->msgData, msgNo, str);

    BufferIntegerAsString(a0->msgFmt, 0, GetMonData(a0->mon, MON_DATA_MET_YEAR, NULL), 2, PRINTING_MODE_LEADING_ZEROS, TRUE);
    BufferMonthNameAbbr(a0->msgFmt, 1, GetMonData(a0->mon, MON_DATA_MET_MONTH, NULL));
    BufferIntegerAsString(a0->msgFmt, 2, GetMonData(a0->mon, MON_DATA_MET_DAY, NULL), 2, PRINTING_MODE_LEFT_ALIGN, TRUE);
    BufferIntegerAsString(a0->msgFmt, 3, GetMonData(a0->mon, MON_DATA_MET_LEVEL, NULL), 3, PRINTING_MODE_LEFT_ALIGN, TRUE);
    BufferLocationName(a0->msgFmt, 4, GetMonData(a0->mon, MON_DATA_MET_LOCATION, NULL));
    BufferIntegerAsString(a0->msgFmt, 5, GetMonData(a0->mon, MON_DATA_EGG_MET_YEAR, NULL), 2, PRINTING_MODE_LEADING_ZEROS, TRUE);
    BufferMonthNameAbbr(a0->msgFmt, 6, GetMonData(a0->mon, MON_DATA_EGG_MET_MONTH, NULL));
    BufferIntegerAsString(a0->msgFmt, 7, GetMonData(a0->mon, MON_DATA_EGG_MET_DAY, NULL), 2, PRINTING_MODE_LEFT_ALIGN, TRUE);
    BufferLocationName(a0->msgFmt, 8, GetMonData(a0->mon, MON_DATA_EGG_MET_LOCATION, NULL));

    StringExpandPlaceholders(a0->msgFmt, a0->notepad.dateLocationMet, str);
    String_Delete(str);
}

static void FormatDateAndLocation_Migrated(Unk0208E600 *a0, int msgNo) {
    int version;

    String *str = String_New(0x120, a0->heapId);
    a0->notepad.dateLocationMet = String_New(0x120, a0->heapId);

    ReadMsgDataIntoString(a0->msgData, msgNo, str);

    BufferIntegerAsString(a0->msgFmt, 0, GetMonData(a0->mon, MON_DATA_MET_YEAR, NULL), 2, PRINTING_MODE_LEADING_ZEROS, TRUE);
    BufferMonthNameAbbr(a0->msgFmt, 1, GetMonData(a0->mon, MON_DATA_MET_MONTH, NULL));
    BufferIntegerAsString(a0->msgFmt, 2, GetMonData(a0->mon, MON_DATA_MET_DAY, NULL), 2, PRINTING_MODE_LEFT_ALIGN, TRUE);
    BufferIntegerAsString(a0->msgFmt, 3, GetMonData(a0->mon, MON_DATA_MET_LEVEL, NULL), 3, PRINTING_MODE_LEFT_ALIGN, TRUE);

    version = GetMonData(a0->mon, MON_DATA_GAME_VERSION, NULL);
    switch (version) {
    case 0:
    case 6:
    case 9:
    case 13:
    case 14:
    default:
        BufferLocationName(a0->msgFmt, 4, sub_02017FE4(MAPSECTYPE_GIFT, 7));
        break;
    case VERSION_FIRE_RED:
    case VERSION_LEAF_GREEN:
        BufferLocationName(a0->msgFmt, 4, sub_02017FE4(MAPSECTYPE_GIFT, 3));
        break;
    case VERSION_HEARTGOLD:
    case VERSION_SOULSILVER:
        BufferLocationName(a0->msgFmt, 4, sub_02017FE4(MAPSECTYPE_GIFT, 4));
        break;
    case VERSION_SAPPHIRE:
    case VERSION_RUBY:
    case VERSION_EMERALD:
        BufferLocationName(a0->msgFmt, 4, sub_02017FE4(MAPSECTYPE_GIFT, 5));
        break;
    case VERSION_GAMECUBE:
        BufferLocationName(a0->msgFmt, 4, sub_02017FE4(MAPSECTYPE_GIFT, 8));
        break;
    case VERSION_DIAMOND:
    case VERSION_PEARL:
    case VERSION_PLATINUM:
        BufferLocationName(a0->msgFmt, 4, sub_02017FE4(MAPSECTYPE_GIFT, 7));
        break;
    }

    StringExpandPlaceholders(a0->msgFmt, a0->notepad.dateLocationMet, str);
    String_Delete(str);
}

static void FormatDateAndLocation_Egg(Unk0208E600 *a0, int msgNo, BOOL hatched) {
    String *str = String_New(0x168, a0->heapId);
    a0->notepad.dateLocationMet = String_New(0x168, a0->heapId);

    ReadMsgDataIntoString(a0->msgData, msgNo, str);

    if (!hatched) {
        BufferIntegerAsString(a0->msgFmt, 5, GetMonData(a0->mon, MON_DATA_EGG_MET_YEAR, NULL), 2, PRINTING_MODE_LEADING_ZEROS, TRUE);
        BufferMonthNameAbbr(a0->msgFmt, 6, GetMonData(a0->mon, MON_DATA_EGG_MET_MONTH, NULL));
        BufferIntegerAsString(a0->msgFmt, 7, GetMonData(a0->mon, MON_DATA_EGG_MET_DAY, NULL), 2, PRINTING_MODE_LEFT_ALIGN, TRUE);
        BufferLocationName(a0->msgFmt, 8, GetMonData(a0->mon, MON_DATA_EGG_MET_LOCATION, NULL));
    } else {
        BufferIntegerAsString(a0->msgFmt, 5, GetMonData(a0->mon, MON_DATA_MET_YEAR, NULL), 2, PRINTING_MODE_LEADING_ZEROS, TRUE);
        BufferMonthNameAbbr(a0->msgFmt, 6, GetMonData(a0->mon, MON_DATA_MET_MONTH, NULL));
        BufferIntegerAsString(a0->msgFmt, 7, GetMonData(a0->mon, MON_DATA_MET_DAY, NULL), 2, PRINTING_MODE_LEFT_ALIGN, TRUE);
        BufferLocationName(a0->msgFmt, 8, GetMonData(a0->mon, MON_DATA_MET_LOCATION, NULL));
    }

    StringExpandPlaceholders(a0->msgFmt, a0->notepad.dateLocationMet, str);
    String_Delete(str);
}

static void FormatFlavorPreference(Unk0208E600 *a0) {
    a0->notepad.flavorPreference = String_New(0x48, a0->heapId);
    int index = 0;
    for (int flavor = FLAVOR_START; flavor < FLAVOR_MAX; flavor++) {
        int preference = MonGetFlavorPreference(a0->mon, flavor);
        if (preference == 1) {
            index = flavor + 1;
        }
    }
    ReadMsgDataIntoString(a0->msgData, sFlavorMsgs[index], a0->notepad.flavorPreference);
}

static void FormatEggWatch(Unk0208E600 *a0) {
    int msgNo;

    int eggCycles = GetMonData(a0->mon, MON_DATA_FRIENDSHIP, NULL);
    a0->notepad.eggWatch = String_New(0x120, a0->heapId);
    if (eggCycles <= 5) {
        msgNo = msg_0302_00105;
    } else if (eggCycles <= 10) {
        msgNo = msg_0302_00106;
    } else if (eggCycles <= 40) {
        msgNo = msg_0302_00107;
    } else {
        msgNo = msg_0302_00108;
    }
    ReadMsgDataIntoString(a0->msgData, msgNo, a0->notepad.eggWatch);
}

static MetCondition MonMetCondition(Pokemon *mon, BOOL isMine) {
    if (!GetMonData(mon, MON_DATA_IS_EGG, NULL)) {
        if (GetMonData(mon, MON_DATA_EGG_MET_LOCATION, NULL) == 0) {
            if (GetMonData(mon, MON_DATA_MET_LOCATION, NULL) == sub_02017FE4(MAPSECTYPE_NORMAL, MAPSEC_PAL_PARK)) {
                return MET_CONDITION_MIGRATED;
            }
            if (GetMonData(mon, MON_DATA_FATEFUL_ENCOUNTER, NULL) == TRUE) {
                if (isMine == TRUE) {
                    return MET_CONDITION_FATEFUL_ENCOUNTER;
                }
                return MET_CONDITION_FATEFUL_ENCOUNTER_TRADED;
            }

            if (GetMonData(mon, MON_DATA_MET_LOCATION, NULL) == sub_02017FE4(MAPSECTYPE_GIFT, 1)) {
                return MET_CONDITION_WILD_GIFT;
            }
            if (isMine == TRUE) {
                return MET_CONDITION_WILD_ENCOUNTER;
            }
            return MET_CONDITION_WILD_ENCOUNTER_TRADED;
        }
        if (GetMonData(mon, MON_DATA_FATEFUL_ENCOUNTER, NULL) == TRUE) {
            if (GetMonData(mon, MON_DATA_EGG_MET_LOCATION, NULL) == sub_02017FE4(MAPSECTYPE_GIFT, 2)) {
                if (isMine == TRUE) {
                    return MET_CONDITION_FATEFUL_EGG_HATCHED_GIFT;
                }
                return MET_CONDITION_FATEFUL_EGG_HATCHED_GIFT_TRADED;
            }
            if (GetMonData(mon, MON_DATA_EGG_MET_LOCATION, NULL) == sub_02017FE4(MAPSECTYPE_EXTERNAL, 1)) {
                if (isMine == TRUE) {
                    return MET_CONDITION_FATEFUL_EGG_HATCHED_ARRIVED;
                }
                return MET_CONDITION_FATEFUL_EGG_HATCHED_ARRIVED_TRADED;
            }
            if (isMine == TRUE) {
                return MET_CONDITION_FATEFUL_EGG_HATCHED;
            }
            return MET_CONDITION_FATEFUL_EGG_HATCHED_TRADED;
        }

        if ((GetMonData(mon, MON_DATA_EGG_MET_LOCATION, NULL) == sub_02017FE4(MAPSECTYPE_GIFT, 1)) ||
            (GetMonData(mon, MON_DATA_EGG_MET_LOCATION, NULL) == sub_02017FE4(MAPSECTYPE_GIFT, 0)) ||
            (GetMonData(mon, MON_DATA_EGG_MET_LOCATION, NULL) == sub_02017FE4(MAPSECTYPE_GIFT, 9)) ||
            (GetMonData(mon, MON_DATA_EGG_MET_LOCATION, NULL) == sub_02017FE4(MAPSECTYPE_GIFT, 10)) ||
            (GetMonData(mon, MON_DATA_EGG_MET_LOCATION, NULL) == sub_02017FE4(MAPSECTYPE_GIFT, 11)) ||
            (GetMonData(mon, MON_DATA_EGG_MET_LOCATION, NULL) == sub_02017FE4(MAPSECTYPE_GIFT, 13)) ||
            (GetMonData(mon, MON_DATA_EGG_MET_LOCATION, NULL) == sub_02017FE4(MAPSECTYPE_GIFT, 14))) {
                if (isMine == TRUE) {
                    return MET_CONDITION_EGG_HATCHED_GIFT;
                }
                return MET_CONDITION_EGG_HATCHED_GIFT_TRADED;
        }

        if (isMine == TRUE) {
            return MET_CONDITION_EGG_HATCHED;
        }
        return MET_CONDITION_EGG_HATCHED_TRADED;
    }

    if (isMine == TRUE) {
        if (GetMonData(mon, MON_DATA_FATEFUL_ENCOUNTER, NULL) == TRUE) {
            if (GetMonData(mon, MON_DATA_EGG_MET_LOCATION, NULL) == sub_02017FE4(MAPSECTYPE_EXTERNAL, 1)) {
                return MET_CONDITION_FATEFUL_EGG_ARRIVED;
            }
            return MET_CONDITION_FATEFUL_EGG;
        }
        return MET_CONDITION_EGG;
    }
    if (GetMonData(mon, MON_DATA_FATEFUL_ENCOUNTER, NULL) == TRUE) {
        return MET_CONDITION_FATEFUL_EGG_TRADED;
    }
    return MET_CONDITION_EGG_TRADED;
}

void MonSetTrainerMemo(Pokemon *mon, PlayerProfile *profile, int strat, int mapsec, HeapID heapId) {
    BoxMonSetTrainerMemo(&mon->box, profile, strat, mapsec, heapId);
}

void BoxMonSetTrainerMemo(BoxPokemon *boxMon, PlayerProfile *profile, int strat, int mapsec, HeapID heapId) {
    int var;

    switch (strat) {
    case 0:
        if (mapsec > sub_02017FE4(MAPSECTYPE_GIFT, 0)) {
            mapsec = sub_02017FE4(MAPSECTYPE_EXTERNAL, 2);
        }
        if (!GetBoxMonData(boxMon, MON_DATA_IS_EGG, NULL)) {
            sub_0208F5C8(boxMon, FALSE);
            sub_0208F550(boxMon, mapsec, TRUE);
            CopyLevelToMetLevel(boxMon);
        } else {
            sub_0208F550(boxMon, mapsec, FALSE);
            sub_0208F5C8(boxMon, TRUE);
        }
        SetOriginalTrainerData(boxMon, profile, heapId);
        break;
    case 7:
        if (mapsec > sub_02017FE4(MAPSECTYPE_GIFT, 0)) {
            mapsec = sub_02017FE4(MAPSECTYPE_EXTERNAL, 2);
        }
        if (!GetBoxMonData(boxMon, MON_DATA_IS_EGG, NULL)) {
            sub_0208F5C8(boxMon, FALSE);
            sub_0208F550(boxMon, mapsec, TRUE);
            CopyLevelToMetLevel(boxMon);
            break;
        }
        sub_0208F550(boxMon, mapsec, FALSE);
        sub_0208F5C8(boxMon, TRUE);
        break;
    case 1:
        if (!GetBoxMonData(boxMon, MON_DATA_IS_EGG, NULL)) {
            sub_0208F5C8(boxMon, FALSE);
            sub_0208F550(boxMon, sub_02017FE4(MAPSECTYPE_GIFT, 1), TRUE);
            CopyLevelToMetLevel(boxMon);
            break;
        }
        sub_0208F5C8(boxMon, FALSE);
        sub_0208F550(boxMon, sub_02017FE4(MAPSECTYPE_GIFT, 1), TRUE);
        break;
    case 2:
        sub_0208F5C8(boxMon, FALSE);
        sub_0208F550(boxMon, sub_02017FE4(MAPSECTYPE_NORMAL, MAPSEC_PAL_PARK), TRUE);
        CopyLevelToMetLevel(boxMon);
        break;
    case 3:
        sub_0208F550(boxMon, mapsec, FALSE);
        sub_0208F5C8(boxMon, TRUE);
        SetOriginalTrainerData(boxMon, profile, heapId);
        break;
    case 4:
        if (BoxmonBelongsToPlayer(boxMon, profile, heapId) == TRUE) {
            if (!GetBoxMonData(boxMon, MON_DATA_IS_EGG, NULL)) {
                sub_0208F5C8(boxMon, FALSE);
                sub_0208F550(boxMon, mapsec, TRUE);
                CopyLevelToMetLevel(boxMon);
            } else {
                sub_0208F550(boxMon, mapsec, 0);
                sub_0208F5C8(boxMon, TRUE);
            }
        } else if (!GetBoxMonData(boxMon, MON_DATA_IS_EGG, NULL)) {
                sub_0208F5C8(boxMon, FALSE);
                sub_0208F550(boxMon, mapsec, TRUE);
                CopyLevelToMetLevel(boxMon);
        } else {
            sub_0208F5C8(boxMon, FALSE);
            sub_0208F550(boxMon, mapsec, TRUE);
        }
        SetFatefulEncounter(boxMon);
        break;
    case 5:
        if (GetBoxMonData(boxMon, MON_DATA_IS_EGG, NULL)) {
            sub_0208F550(boxMon, sub_02017FE4(MAPSECTYPE_GIFT, 2), TRUE);
        }
        break;
    case 6:
        if (mapsec > sub_02017FE4(MAPSECTYPE_GIFT, 0)) {
            mapsec = 0;
        }
        if (!BoxmonBelongsToPlayer(boxMon, profile, heapId)) {
            var = GetBoxMonData(boxMon, MON_DATA_MET_LOCATION, NULL);
            SetBoxMonData(boxMon, MON_DATA_EGG_MET_LOCATION, &var);

            var = GetBoxMonData(boxMon, MON_DATA_MET_YEAR, NULL);
            SetBoxMonData(boxMon, MON_DATA_EGG_MET_YEAR, &var);

            var = GetBoxMonData(boxMon, MON_DATA_MET_MONTH, NULL);
            SetBoxMonData(boxMon, MON_DATA_EGG_MET_MONTH, &var);

            var = GetBoxMonData(boxMon, MON_DATA_MET_DAY, NULL);
            SetBoxMonData(boxMon, MON_DATA_EGG_MET_DAY, &var);
        }
        sub_0208F550(boxMon, mapsec, TRUE);
        SetOriginalTrainerData(boxMon, profile, heapId);
        break;
    }
}

static void SetOriginalTrainerData(BoxPokemon *boxMon, PlayerProfile *profile, HeapID heapId) {
    u32 otId = PlayerProfile_GetTrainerID(profile);
    u32 gender = PlayerProfile_GetTrainerGender(profile);
    String *name = PlayerProfile_GetPlayerName_NewString(profile, heapId);

    SetBoxMonData(boxMon, MON_DATA_OTID, &otId);
    SetBoxMonData(boxMon, MON_DATA_MET_GENDER, &gender);
    SetBoxMonData(boxMon, MON_DATA_OT_NAME_2, name);

    String_Delete(name);
}

static void sub_0208F550(BoxPokemon *boxMon, int mapsec, BOOL isNotEgg) {
    RTCDate date;

    GF_RTC_CopyDate(&date);
    if (!isNotEgg) {
        SetBoxMonData(boxMon, MON_DATA_EGG_MET_LOCATION, &mapsec);
        SetBoxMonData(boxMon, MON_DATA_EGG_MET_YEAR, &date.year);
        SetBoxMonData(boxMon, MON_DATA_EGG_MET_MONTH, &date.month);
        SetBoxMonData(boxMon, MON_DATA_EGG_MET_DAY, &date.day);
        return;
    }
    SetBoxMonData(boxMon, MON_DATA_MET_LOCATION, &mapsec);
    SetBoxMonData(boxMon, MON_DATA_MET_YEAR, &date.year);
    SetBoxMonData(boxMon, MON_DATA_MET_MONTH, &date.month);
    SetBoxMonData(boxMon, MON_DATA_MET_DAY, &date.day);
}

static void sub_0208F5C8(BoxPokemon *boxMon, BOOL isEgg) {
    int zero = 0;
    if (!isEgg) {
        SetBoxMonData(boxMon, MON_DATA_EGG_MET_LOCATION, &zero);
        SetBoxMonData(boxMon, MON_DATA_EGG_MET_YEAR, &zero);
        SetBoxMonData(boxMon, MON_DATA_EGG_MET_MONTH, &zero);
        SetBoxMonData(boxMon, MON_DATA_EGG_MET_DAY, &zero);
        return;
    }
    SetBoxMonData(boxMon, MON_DATA_MET_LOCATION, &zero);
    SetBoxMonData(boxMon, MON_DATA_MET_YEAR, &zero);
    SetBoxMonData(boxMon, MON_DATA_MET_MONTH, &zero);
    SetBoxMonData(boxMon, MON_DATA_MET_DAY, &zero);
}

static void CopyLevelToMetLevel(BoxPokemon *boxMon) {
    int level = GetBoxMonData(boxMon, MON_DATA_LEVEL, NULL);
    SetBoxMonData(boxMon, MON_DATA_MET_LEVEL, &level);
}

static void SetFatefulEncounter(BoxPokemon *boxMon) {
    int var = 1;
    SetBoxMonData(boxMon, MON_DATA_FATEFUL_ENCOUNTER, &var);
}
