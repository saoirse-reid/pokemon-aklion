#ifndef POKEHEARTGOLD_CONSTANTS_ITEMS_H
#define POKEHEARTGOLD_CONSTANTS_ITEMS_H

#define POCKET_ITEMS        0
#define POCKET_MEDICINE     1
#define POCKET_BALLS        2
#define POCKET_TMHMS        3
#define POCKET_BERRIES      4
#define POCKET_MAIL         5
#define POCKET_BATTLE_ITEMS 6
#define POCKET_KEY_ITEMS    7
#define POCKETS_COUNT       8

// Where the item will be listed in the battle bag
// Encoded in a bitfield in item_data.narc
#define BTLPOCKET_BALLS_F          (1<<0)
#define BTLPOCKET_BATTLE_ITEMS_F   (1<<1)
#define BTLPOCKET_HP_RESTORE_F     (1<<2)
#define BTLPOCKET_STATUS_RESTORE_F (1<<3)
#define BTLPOCKET_PP_RESTORE_F     (1<<4)

// The above is remapped in overlay_08
#define BTLPOCKETLIST_HP_PP_RESTORE  0
#define BTLPOCKETLIST_STATUS_RESTORE 1
#define BTLPOCKETLIST_BALLS          2
#define BTLPOCKETLIST_BATTLE_ITEMS   3

#define BPOCKET_BALLS_F      0
#define BPOCKET_

#define POCKET_BAG_VIEW_END 0xFF

#define NUM_BAG_ITEMS        165
#define NUM_BAG_MEDICINE      40
#define NUM_BAG_BALLS         24
#define NUM_BAG_TMS_HMS      101
#define NUM_BAG_BERRIES       64
#define NUM_BAG_MAIL          12
#define NUM_BAG_BATTLE_ITEMS  30
#define NUM_BAG_KEY_ITEMS     50

#define BAG_SLOT_QUANTITY_MAX                    999
#define BAG_TMHM_QUANTITY_MAX                     99

#define ITEMNARC_PARAM                             0
#define ITEMNARC_NCGR                              1
#define ITEMNARC_NCLR                              2
#define ITEMNARC_AGBCODE                           3

#define ITEMATTR_PRICE                             0
#define ITEMATTR_HOLD_EFFECT                       1
#define ITEMATTR_HOLD_EFFECT_PARAM                 2
#define ITEMATTR_PREVENT_TOSS                      3
#define ITEMATTR_SELECTABLE                        4
#define ITEMATTR_FIELD_POCKET                      5
#define ITEMATTR_FIELDUSEFUNC                      6
#define ITEMATTR_BATTLEUSEFUNC                     7
#define ITEMATTR_PLUCK_EFFECT                      8
#define ITEMATTR_FLING_EFFECT                      9
#define ITEMATTR_FLING_POWER                      10
#define ITEMATTR_NATURAL_GIFT_POWER               11
#define ITEMATTR_NATURAL_GIFT_TYPE                12
#define ITEMATTR_BATTLE_POCKET                    13
#define ITEMATTR_PARTY_USE                        14
#define ITEMATTR_SLP_HEAL                         15
#define ITEMATTR_PSN_HEAL                         16
#define ITEMATTR_BRN_HEAL                         17
#define ITEMATTR_FRZ_HEAL                         18
#define ITEMATTR_PRZ_HEAL                         19
#define ITEMATTR_CFS_HEAL                         20
#define ITEMATTR_INF_HEAL                         21
#define ITEMATTR_GUARD_SPEC                       22
#define ITEMATTR_REVIVE                           23
#define ITEMATTR_REVIVE_ALL                       24
#define ITEMATTR_LEVEL_UP                         25
#define ITEMATTR_EVOLVE                           26
#define ITEMATTR_ATK_STAGES                       27
#define ITEMATTR_DEF_STAGES                       28
#define ITEMATTR_SPATK_STAGES                     29
#define ITEMATTR_SPDEF_STAGES                     30
#define ITEMATTR_SPEED_STAGES                     31
#define ITEMATTR_ACCURACY_STAGES                  32
#define ITEMATTR_CRITRATE_STAGES                  33
#define ITEMATTR_PP_UP                            34
#define ITEMATTR_PP_MAX                           35
#define ITEMATTR_PP_RESTORE                       36
#define ITEMATTR_PP_RESTORE_ALL                   37
#define ITEMATTR_HP_RESTORE                       38
#define ITEMATTR_HP_EV_UP                         39
#define ITEMATTR_ATK_EV_UP                        40
#define ITEMATTR_DEF_EV_UP                        41
#define ITEMATTR_SPEED_EV_UP                      42
#define ITEMATTR_SPATK_EV_UP                      43
#define ITEMATTR_SPDEF_EV_UP                      44
#define ITEMATTR_FRIENDSHIP_MOD_LO                45
#define ITEMATTR_FRIENDSHIP_MOD_MED               46
#define ITEMATTR_FRIENDSHIP_MOD_HI                47
#define ITEMATTR_HP_EV_UP_PARAM                   48
#define ITEMATTR_ATK_EV_UP_PARAM                  49
#define ITEMATTR_DEF_EV_UP_PARAM                  50
#define ITEMATTR_SPEED_EV_UP_PARAM                51
#define ITEMATTR_SPATK_EV_UP_PARAM                52
#define ITEMATTR_SPDEF_EV_UP_PARAM                53
#define ITEMATTR_HP_RESTORE_PARAM                 54
#define ITEMATTR_PP_RESTORE_PARAM                 55
#define ITEMATTR_FRIENDSHIP_MOD_LO_PARAM          56
#define ITEMATTR_FRIENDSHIP_MOD_MED_PARAM         57
#define ITEMATTR_FRIENDSHIP_MOD_HI_PARAM          58

#define PARTYUSE_NO              0
#define PARTYUSE_YES             1

#define PP_RESTORE_ALL  127
#define HP_RESTORE_ALL  255
#define HP_RESTORE_HALF 254
#define HP_RESTORE_QTR  253

#define HOLD_EFFECT_NONE                    0
#define HOLD_EFFECT_HP_RESTORE              1
#define HOLD_EFFECT_GIRATINA_BOOST          2
#define HOLD_EFFECT_DIALGA_BOOST            3
#define HOLD_EFFECT_PALKIA_BOOST            4
#define HOLD_EFFECT_PRZ_RESTORE             5
#define HOLD_EFFECT_SLP_RESTORE             6
#define HOLD_EFFECT_PSN_RESTORE             7
#define HOLD_EFFECT_BRN_RESTORE             8
#define HOLD_EFFECT_FRZ_RESTORE             9
#define HOLD_EFFECT_PP_RESTORE             10
#define HOLD_EFFECT_CONFUSE_RESTORE        11
#define HOLD_EFFECT_STATUS_RESTORE         12
#define HOLD_EFFECT_HP_PCT_RESTORE         13
#define HOLD_EFFECT_HP_RESTORE_SPICY       14
#define HOLD_EFFECT_HP_RESTORE_DRY         15
#define HOLD_EFFECT_HP_RESTORE_SWEET       16
#define HOLD_EFFECT_HP_RESTORE_BITTER      17
#define HOLD_EFFECT_HP_RESTORE_SOUR        18
#define HOLD_EFFECT_WEAKEN_SE_FIRE         19
#define HOLD_EFFECT_WEAKEN_SE_WATER        20
#define HOLD_EFFECT_WEAKEN_SE_ELECTRIC     21
#define HOLD_EFFECT_WEAKEN_SE_GRASS        22
#define HOLD_EFFECT_WEAKEN_SE_ICE          23
#define HOLD_EFFECT_WEAKEN_SE_FIGHT        24
#define HOLD_EFFECT_WEAKEN_SE_POISON       25
#define HOLD_EFFECT_WEAKEN_SE_GROUND       26
#define HOLD_EFFECT_WEAKEN_SE_FLYING       27
#define HOLD_EFFECT_WEAKEN_SE_PSYCHIC      28
#define HOLD_EFFECT_WEAKEN_SE_BUG          29
#define HOLD_EFFECT_WEAKEN_SE_ROCK         30
#define HOLD_EFFECT_WEAKEN_SE_GHOST        31
#define HOLD_EFFECT_WEAKEN_SE_DRAGON       32
#define HOLD_EFFECT_WEAKEN_SE_DARK         33
#define HOLD_EFFECT_WEAKEN_SE_STEEL        34
#define HOLD_EFFECT_WEAKEN_NORMAL          35
#define HOLD_EFFECT_PINCH_ATK_UP           36
#define HOLD_EFFECT_PINCH_DEF_UP           37
#define HOLD_EFFECT_PINCH_SPEED_UP         38
#define HOLD_EFFECT_PINCH_SPATK_UP         39
#define HOLD_EFFECT_PINCH_SPDEF_UP         40
#define HOLD_EFFECT_PINCH_CRITRATE_UP      41
#define HOLD_EFFECT_PINCH_RANDOM_UP        42
#define HOLD_EFFECT_HP_RESTORE_SE          43
#define HOLD_EFFECT_PINCH_ACC_UP           44
#define HOLD_EFFECT_PINCH_PRIORITY         45
#define HOLD_EFFECT_RECOIL_PHYSICAL        46
#define HOLD_EFFECT_RECOIL_SPECIAL         47
#define HOLD_EFFECT_ACC_REDUCE             48
#define HOLD_EFFECT_STATDOWN_RESTORE       49
#define HOLD_EFFECT_EXP_UP_SPEED_DOWN      50
#define HOLD_EFFECT_EXP_SHARE              51
#define HOLD_EFFECT_SOMETIMES_PRIORITY     52
#define HOLD_EFFECT_FRIENDSHIP_UP          53
#define HOLD_EFFECT_HEAL_INFATUATION       54
#define HOLD_EFFECT_CHOICE_ATK             55
#define HOLD_EFFECT_CRIT_UP                56
#define HOLD_EFFECT_STRENGTHEN_BUG         57
#define HOLD_EFFECT_MONEY_UP               58
#define HOLD_EFFECT_ENCOUNTERS_DOWN        59
#define HOLD_EFFECT_LATI_SPECIAL           60
#define HOLD_EFFECT_CLAMPERL_SPATK         61
#define HOLD_EFFECT_CLAMPERL_SPDEF         62
#define HOLD_EFFECT_FLEE                   63
#define HOLD_EFFECT_NO_EVOLVE              64
#define HOLD_EFFECT_MAYBE_ENDURE           65
#define HOLD_EFFECT_EXP_UP                 66
#define HOLD_EFFECT_CRITRATE_UP            67
#define HOLD_EFFECT_STRENGTHEN_STEEL       68
#define HOLD_EFFECT_HP_RESTORE_GRADUAL     69
#define HOLD_EFFECT_EVOLVE_SEADRA          70
#define HOLD_EFFECT_PIKA_SPATK_UP          71
#define HOLD_EFFECT_STRENGTHEN_GROUND      72
#define HOLD_EFFECT_STRENGTHEN_ROCK        73
#define HOLD_EFFECT_STRENGTHEN_GRASS       74
#define HOLD_EFFECT_STRENGTHEN_DARK        75
#define HOLD_EFFECT_STRENGTHEN_FIGHT       76
#define HOLD_EFFECT_STRENGTHEN_ELECTRIC    77
#define HOLD_EFFECT_STRENGTHEN_WATER       78
#define HOLD_EFFECT_STRENGTHEN_FLYING      79
#define HOLD_EFFECT_STRENGTHEN_POISON      80
#define HOLD_EFFECT_STRENGTHEN_ICE         81
#define HOLD_EFFECT_STRENGTHEN_GHOST       82
#define HOLD_EFFECT_STRENGTHEN_PSYCHIC     83
#define HOLD_EFFECT_STRENGTHEN_FIRE        84
#define HOLD_EFFECT_STRENGTHEN_DRAGON      85
#define HOLD_EFFECT_STRENGTHEN_NORMAL      86
#define HOLD_EFFECT_EVOLVE_PORYGON         87
#define HOLD_EFFECT_HP_RESTORE_ON_DMG      88
#define HOLD_EFFECT_CHANSEY_CRITRATE_UP    89
#define HOLD_EFFECT_DITTO_DEF_UP           90
#define HOLD_EFFECT_CUBONE_ATK_UP          91
#define HOLD_EFFECT_FARFETCHD_CRITRATE_UP  92
#define HOLD_EFFECT_ACCURACY_UP            93
#define HOLD_EFFECT_POWER_UP_PHYS          94
#define HOLD_EFFECT_POWER_UP_SPEC          95
#define HOLD_EFFECT_POWER_UP_SE            96
#define HOLD_EFFECT_EXTEND_SCREENS         97
#define HOLD_EFFECT_HP_DRAIN_ON_ATK        98
#define HOLD_EFFECT_CHARGE_SKIP            99
#define HOLD_EFFECT_PSN_USER              100
#define HOLD_EFFECT_BRN_USER              101
#define HOLD_EFFECT_DITTO_SPEED_UP        102
#define HOLD_EFFECT_ENDURE                103
#define HOLD_EFFECT_CRITRATE_UP_SLOWER    104
#define HOLD_EFFECT_BOOST_REPEATED        105
#define HOLD_EFFECT_SPEED_DOWN_GROUNDED   106
#define HOLD_EFFECT_SPEED_DOWN            107
#define HOLD_EFFECT_RECIPROCATE_INFAT     108
#define HOLD_EFFECT_HP_RESTORE_PSN_TYPE   109
#define HOLD_EFFECT_EXTEND_SNOWSTORM      110
#define HOLD_EFFECT_EXTEND_SANDSTORM      111
#define HOLD_EFFECT_EXTEND_SUN            112
#define HOLD_EFFECT_EXTEND_RAIN           113
#define HOLD_EFFECT_EXTEND_TRAPPING       114
#define HOLD_EFFECT_CHOICE_SPEED          115
#define HOLD_EFFECT_DMG_USER_CONTACT_XFR  116
#define HOLD_EFFECT_LVLUP_ATK_EV_UP       117
#define HOLD_EFFECT_LVLUP_DEF_EV_UP       118
#define HOLD_EFFECT_LVLUP_SPATK_EV_UP     119
#define HOLD_EFFECT_LVLUP_SPDEF_EV_UP     120
#define HOLD_EFFECT_LVLUP_SPEED_EV_UP     121
#define HOLD_EFFECT_LVLUP_HP_EV_UP        122
#define HOLD_EFFECT_SWITCH                123
#define HOLD_EFFECT_LEECH_BOOST           124
#define HOLD_EFFECT_CHOICE_SPATK          125
#define HOLD_EFFECT_ARCEUS_FIRE           126
#define HOLD_EFFECT_ARCEUS_WATER          127
#define HOLD_EFFECT_ARCEUS_ELECTRIC       128
#define HOLD_EFFECT_ARCEUS_GRASS          129
#define HOLD_EFFECT_ARCEUS_ICE            130
#define HOLD_EFFECT_ARCEUS_FIGHT          131
#define HOLD_EFFECT_ARCEUS_POISON         132
#define HOLD_EFFECT_ARCEUS_GROUND         133
#define HOLD_EFFECT_ARCEUS_FLYING         134
#define HOLD_EFFECT_ARCEUS_PSYCHIC        135
#define HOLD_EFFECT_ARCEUS_BUG            136
#define HOLD_EFFECT_ARCEUS_ROCK           137
#define HOLD_EFFECT_ARCEUS_GHOST          138
#define HOLD_EFFECT_ARCEUS_DRAGON         139
#define HOLD_EFFECT_ARCEUS_DARK           140
#define HOLD_EFFECT_ARCEUS_STEEL          141
#define HOLD_EFFECT_EVOLVE_RHYDON         142
#define HOLD_EFFECT_EVOLVE_ELECTABUZZ     143
#define HOLD_EFFECT_EVOLVE_MAGMAR         144
#define HOLD_EFFECT_EVOLVE_PORYGON2       145
#define HOLD_EFFECT_EVOLVE_DUSCLOPS       146

#define ITEM_NONE                  0

// Balls
#define ITEM_MASTER_BALL           1
#define ITEM_ULTRA_BALL            2
#define ITEM_GREAT_BALL            3
#define ITEM_POKE_BALL             4
#define ITEM_SAFARI_BALL           5
#define ITEM_NET_BALL              6
#define ITEM_DIVE_BALL             7
#define ITEM_NEST_BALL             8
#define ITEM_REPEAT_BALL           9
#define ITEM_TIMER_BALL           10
#define ITEM_LUXURY_BALL          11
#define ITEM_PREMIER_BALL         12
#define ITEM_DUSK_BALL            13
#define ITEM_HEAL_BALL            14
#define ITEM_QUICK_BALL           15
#define ITEM_CHERISH_BALL         16

// Pokemon Items
#define ITEM_POTION               17
#define ITEM_ANTIDOTE             18
#define ITEM_BURN_HEAL            19
#define ITEM_ICE_HEAL             20
#define ITEM_AWAKENING            21
#define ITEM_PARLYZ_HEAL          22
#define ITEM_FULL_RESTORE         23
#define ITEM_MAX_POTION           24
#define ITEM_HYPER_POTION         25
#define ITEM_SUPER_POTION         26
#define ITEM_FULL_HEAL            27
#define ITEM_REVIVE               28
#define ITEM_MAX_REVIVE           29
#define ITEM_FRESH_WATER          30
#define ITEM_SODA_POP             31
#define ITEM_LEMONADE             32
#define ITEM_MOOMOO_MILK          33

#define ITEM_ENERGYPOWDER         34
#define ITEM_ENERGY_ROOT          35
#define ITEM_HEAL_POWDER          36
#define ITEM_REVIVAL_HERB         37

#define ITEM_ETHER                38
#define ITEM_MAX_ETHER            39
#define ITEM_ELIXIR               40
#define ITEM_MAX_ELIXIR           41
#define ITEM_LAVA_COOKIE          42
#define ITEM_BERRY_JUICE          43
#define ITEM_SACRED_ASH           44
#define ITEM_HP_UP                45
#define ITEM_PROTEIN              46
#define ITEM_IRON                 47
#define ITEM_CARBOS               48
#define ITEM_CALCIUM              49
#define ITEM_RARE_CANDY           50
#define ITEM_PP_UP                51
#define ITEM_ZINC                 52
#define ITEM_PP_MAX               53
#define ITEM_OLD_GATEAU           54
#define ITEM_GUARD_SPEC_          55
#define ITEM_DIRE_HIT             56
#define ITEM_X_ATTACK             57
#define ITEM_X_DEFENSE            58
#define ITEM_X_SPEED              59
#define ITEM_X_ACCURACY           60
#define ITEM_X_SPECIAL            61
#define ITEM_X_SP__DEF            62
#define ITEM_POKE_DOLL            63
#define ITEM_FLUFFY_TAIL          64
#define ITEM_BLUE_FLUTE           65
#define ITEM_YELLOW_FLUTE         66
#define ITEM_RED_FLUTE            67
#define ITEM_BLACK_FLUTE          68
#define ITEM_WHITE_FLUTE          69
#define ITEM_SHOAL_SALT           70
#define ITEM_SHOAL_SHELL          71
#define ITEM_RED_SHARD            72
#define ITEM_BLUE_SHARD           73
#define ITEM_YELLOW_SHARD         74
#define ITEM_GREEN_SHARD          75
#define ITEM_SUPER_REPEL          76
#define ITEM_MAX_REPEL            77
#define ITEM_ESCAPE_ROPE          78
#define ITEM_REPEL                79
#define ITEM_SUN_STONE            80
#define ITEM_MOON_STONE           81
#define ITEM_FIRE_STONE           82
#define ITEM_THUNDERSTONE         83
#define ITEM_WATER_STONE          84
#define ITEM_LEAF_STONE           85

// Unusable
#define ITEM_TINYMUSHROOM         86
#define ITEM_BIG_MUSHROOM         87
#define ITEM_PEARL                88
#define ITEM_BIG_PEARL            89
#define ITEM_STARDUST             90
#define ITEM_STAR_PIECE           91
#define ITEM_NUGGET               92
#define ITEM_HEART_SCALE          93
#define ITEM_HONEY                94
#define ITEM_GROWTH_MULCH         95
#define ITEM_DAMP_MULCH           96
#define ITEM_STABLE_MULCH         97
#define ITEM_GOOEY_MULCH          98
#define ITEM_ROOT_FOSSIL          99
#define ITEM_CLAW_FOSSIL         100
#define ITEM_HELIX_FOSSIL        101
#define ITEM_DOME_FOSSIL         102
#define ITEM_OLD_AMBER           103
#define ITEM_ARMOR_FOSSIL        104
#define ITEM_SKULL_FOSSIL        105
#define ITEM_RARE_BONE           106
#define ITEM_SHINY_STONE         107
#define ITEM_DUSK_STONE          108
#define ITEM_DAWN_STONE          109
#define ITEM_OVAL_STONE          110
#define ITEM_ODD_KEYSTONE        111
#define ITEM_GRISEOUS_ORB        112

#define FIRST_MULCH_IDX ITEM_GROWTH_MULCH
#define LAST_MULCH_IDX ITEM_GOOEY_MULCH
#define NUM_MULCHES (LAST_MULCH_IDX - FIRST_MULCH_IDX + 1)
#define MULCH_IDX(mulch) ((mulch) - FIRST_MULCH_IDX + 1)
#define MULCH_NONE 0

// Unused
#define ITEM_UNUSED_113          113
#define ITEM_UNUSED_114          114
#define ITEM_UNUSED_115          115
#define ITEM_UNUSED_116          116
#define ITEM_UNUSED_117          117
#define ITEM_UNUSED_118          118
#define ITEM_UNUSED_119          119
#define ITEM_UNUSED_120          120
#define ITEM_UNUSED_121          121
#define ITEM_UNUSED_122          122
#define ITEM_UNUSED_123          123
#define ITEM_UNUSED_124          124
#define ITEM_UNUSED_125          125
#define ITEM_UNUSED_126          126
#define ITEM_UNUSED_127          127
#define ITEM_UNUSED_128          128
#define ITEM_UNUSED_129          129
#define ITEM_UNUSED_130          130
#define ITEM_UNUSED_131          131
#define ITEM_UNUSED_132          132
#define ITEM_UNUSED_133          133
#define ITEM_UNUSED_134          134

#define ITEM_ADAMANT_ORB         135
#define ITEM_LUSTROUS_ORB        136

// Mails
#define ITEM_GRASS_MAIL          137
#define ITEM_FLAME_MAIL          138
#define ITEM_BUBBLE_MAIL         139
#define ITEM_BLOOM_MAIL          140
#define ITEM_TUNNEL_MAIL         141
#define ITEM_STEEL_MAIL          142
#define ITEM_HEART_MAIL          143
#define ITEM_SNOW_MAIL           144
#define ITEM_SPACE_MAIL          145
#define ITEM_AIR_MAIL            146
#define ITEM_MOSAIC_MAIL         147
#define ITEM_BRICK_MAIL          148

#define FIRST_MAIL_IDX ITEM_GRASS_MAIL
#define LAST_MAIL_IDX ITEM_BRICK_MAIL
#define NUM_MAILS (LAST_MAIL_IDX - FIRST_MAIL_IDX + 1)

// Berries
#define ITEM_CHERI_BERRY         149
#define ITEM_CHESTO_BERRY        150
#define ITEM_PECHA_BERRY         151
#define ITEM_RAWST_BERRY         152
#define ITEM_ASPEAR_BERRY        153
#define ITEM_LEPPA_BERRY         154
#define ITEM_ORAN_BERRY          155
#define ITEM_PERSIM_BERRY        156
#define ITEM_LUM_BERRY           157
#define ITEM_SITRUS_BERRY        158
#define ITEM_FIGY_BERRY          159
#define ITEM_WIKI_BERRY          160
#define ITEM_MAGO_BERRY          161
#define ITEM_AGUAV_BERRY         162
#define ITEM_IAPAPA_BERRY        163
#define ITEM_RAZZ_BERRY          164
#define ITEM_BLUK_BERRY          165
#define ITEM_NANAB_BERRY         166
#define ITEM_WEPEAR_BERRY        167
#define ITEM_PINAP_BERRY         168
#define ITEM_POMEG_BERRY         169
#define ITEM_KELPSY_BERRY        170
#define ITEM_QUALOT_BERRY        171
#define ITEM_HONDEW_BERRY        172
#define ITEM_GREPA_BERRY         173
#define ITEM_TAMATO_BERRY        174
#define ITEM_CORNN_BERRY         175
#define ITEM_MAGOST_BERRY        176
#define ITEM_RABUTA_BERRY        177
#define ITEM_NOMEL_BERRY         178
#define ITEM_SPELON_BERRY        179
#define ITEM_PAMTRE_BERRY        180
#define ITEM_WATMEL_BERRY        181
#define ITEM_DURIN_BERRY         182
#define ITEM_BELUE_BERRY         183
#define ITEM_OCCA_BERRY          184
#define ITEM_PASSHO_BERRY        185
#define ITEM_WACAN_BERRY         186
#define ITEM_RINDO_BERRY         187
#define ITEM_YACHE_BERRY         188
#define ITEM_CHOPLE_BERRY        189
#define ITEM_KEBIA_BERRY         190
#define ITEM_SHUCA_BERRY         191
#define ITEM_COBA_BERRY          192
#define ITEM_PAYAPA_BERRY        193
#define ITEM_TANGA_BERRY         194
#define ITEM_CHARTI_BERRY        195
#define ITEM_KASIB_BERRY         196
#define ITEM_HABAN_BERRY         197
#define ITEM_COLBUR_BERRY        198
#define ITEM_BABIRI_BERRY        199
#define ITEM_CHILAN_BERRY        200
#define ITEM_LIECHI_BERRY        201
#define ITEM_GANLON_BERRY        202
#define ITEM_SALAC_BERRY         203
#define ITEM_PETAYA_BERRY        204
#define ITEM_APICOT_BERRY        205
#define ITEM_LANSAT_BERRY        206
#define ITEM_STARF_BERRY         207
#define ITEM_ENIGMA_BERRY        208
#define ITEM_MICLE_BERRY         209
#define ITEM_CUSTAP_BERRY        210
#define ITEM_JABOCA_BERRY        211
#define ITEM_ROWAP_BERRY         212

#define FIRST_BERRY_IDX ITEM_CHERI_BERRY
#define LAST_BERRY_IDX ITEM_ROWAP_BERRY
#define NUM_BERRIES (LAST_BERRY_IDX - FIRST_BERRY_IDX + 1)
#define BERRY_IDX(berry) ((berry) - FIRST_BERRY_IDX + 1)
#define BERRY_NONE 0

// Battle Held items
#define ITEM_BRIGHTPOWDER        213
#define ITEM_WHITE_HERB          214
#define ITEM_MACHO_BRACE         215
#define ITEM_EXP__SHARE          216
#define ITEM_QUICK_CLAW          217
#define ITEM_SOOTHE_BELL         218
#define ITEM_MENTAL_HERB         219
#define ITEM_CHOICE_BAND         220
#define ITEM_KINGS_ROCK          221
#define ITEM_SILVERPOWDER        222
#define ITEM_AMULET_COIN         223
#define ITEM_CLEANSE_TAG         224
#define ITEM_SOUL_DEW            225
#define ITEM_DEEPSEATOOTH        226
#define ITEM_DEEPSEASCALE        227
#define ITEM_SMOKE_BALL          228
#define ITEM_EVERSTONE           229
#define ITEM_FOCUS_BAND          230
#define ITEM_LUCKY_EGG           231
#define ITEM_SCOPE_LENS          232
#define ITEM_METAL_COAT          233
#define ITEM_LEFTOVERS           234
#define ITEM_DRAGON_SCALE        235
#define ITEM_LIGHT_BALL          236
#define ITEM_SOFT_SAND           237
#define ITEM_HARD_STONE          238
#define ITEM_MIRACLE_SEED        239
#define ITEM_BLACKGLASSES        240
#define ITEM_BLACK_BELT          241
#define ITEM_MAGNET              242
#define ITEM_MYSTIC_WATER        243
#define ITEM_SHARP_BEAK          244
#define ITEM_POISON_BARB         245
#define ITEM_NEVERMELTICE        246
#define ITEM_SPELL_TAG           247
#define ITEM_TWISTEDSPOON        248
#define ITEM_CHARCOAL            249
#define ITEM_DRAGON_FANG         250
#define ITEM_SILK_SCARF          251
#define ITEM_UPGRADE             252
#define ITEM_SHELL_BELL          253
#define ITEM_SEA_INCENSE         254
#define ITEM_LAX_INCENSE         255
#define ITEM_LUCKY_PUNCH         256
#define ITEM_METAL_POWDER        257
#define ITEM_THICK_CLUB          258
#define ITEM_STICK               259

// Contest held items
#define ITEM_RED_SCARF           260
#define ITEM_BLUE_SCARF          261
#define ITEM_PINK_SCARF          262
#define ITEM_GREEN_SCARF         263
#define ITEM_YELLOW_SCARF        264

// New battle held items
#define ITEM_WIDE_LENS           265
#define ITEM_MUSCLE_BAND         266
#define ITEM_WISE_GLASSES        267
#define ITEM_EXPERT_BELT         268
#define ITEM_LIGHT_CLAY          269
#define ITEM_LIFE_ORB            270
#define ITEM_POWER_HERB          271
#define ITEM_TOXIC_ORB           272
#define ITEM_FLAME_ORB           273
#define ITEM_QUICK_POWDER        274
#define ITEM_FOCUS_SASH          275
#define ITEM_ZOOM_LENS           276
#define ITEM_METRONOME           277
#define ITEM_IRON_BALL           278
#define ITEM_LAGGING_TAIL        279
#define ITEM_DESTINY_KNOT        280
#define ITEM_BLACK_SLUDGE        281
#define ITEM_ICY_ROCK            282
#define ITEM_SMOOTH_ROCK         283
#define ITEM_HEAT_ROCK           284
#define ITEM_DAMP_ROCK           285
#define ITEM_GRIP_CLAW           286
#define ITEM_CHOICE_SCARF        287
#define ITEM_STICKY_BARB         288
#define ITEM_POWER_BRACER        289
#define ITEM_POWER_BELT          290
#define ITEM_POWER_LENS          291
#define ITEM_POWER_BAND          292
#define ITEM_POWER_ANKLET        293
#define ITEM_POWER_WEIGHT        294
#define ITEM_SHED_SHELL          295
#define ITEM_BIG_ROOT            296
#define ITEM_CHOICE_SPECS        297

// Arceus plates
#define ITEM_FLAME_PLATE         298
#define ITEM_SPLASH_PLATE        299
#define ITEM_ZAP_PLATE           300
#define ITEM_MEADOW_PLATE        301
#define ITEM_ICICLE_PLATE        302
#define ITEM_FIST_PLATE          303
#define ITEM_TOXIC_PLATE         304
#define ITEM_EARTH_PLATE         305
#define ITEM_SKY_PLATE           306
#define ITEM_MIND_PLATE          307
#define ITEM_INSECT_PLATE        308
#define ITEM_STONE_PLATE         309
#define ITEM_SPOOKY_PLATE        310
#define ITEM_DRACO_PLATE         311
#define ITEM_DREAD_PLATE         312
#define ITEM_IRON_PLATE          313

// Incenses
#define ITEM_ODD_INCENSE         314
#define ITEM_ROCK_INCENSE        315
#define ITEM_FULL_INCENSE        316
#define ITEM_WAVE_INCENSE        317
#define ITEM_ROSE_INCENSE        318
#define ITEM_LUCK_INCENSE        319
#define ITEM_PURE_INCENSE        320

// Evolution held items
#define ITEM_PROTECTOR           321
#define ITEM_ELECTIRIZER         322
#define ITEM_MAGMARIZER          323
#define ITEM_DUBIOUS_DISC        324
#define ITEM_REAPER_CLOTH        325
#define ITEM_RAZOR_CLAW          326
#define ITEM_RAZOR_FANG          327

// TMs/HMs
#define ITEM_TM01                328
#define ITEM_TM02                329
#define ITEM_TM03                330
#define ITEM_TM04                331
#define ITEM_TM05                332
#define ITEM_TM06                333
#define ITEM_TM07                334
#define ITEM_TM08                335
#define ITEM_TM09                336
#define ITEM_TM10                337
#define ITEM_TM11                338
#define ITEM_TM12                339
#define ITEM_TM13                340
#define ITEM_TM14                341
#define ITEM_TM15                342
#define ITEM_TM16                343
#define ITEM_TM17                344
#define ITEM_TM18                345
#define ITEM_TM19                346
#define ITEM_TM20                347
#define ITEM_TM21                348
#define ITEM_TM22                349
#define ITEM_TM23                350
#define ITEM_TM24                351
#define ITEM_TM25                352
#define ITEM_TM26                353
#define ITEM_TM27                354
#define ITEM_TM28                355
#define ITEM_TM29                356
#define ITEM_TM30                357
#define ITEM_TM31                358
#define ITEM_TM32                359
#define ITEM_TM33                360
#define ITEM_TM34                361
#define ITEM_TM35                362
#define ITEM_TM36                363
#define ITEM_TM37                364
#define ITEM_TM38                365
#define ITEM_TM39                366
#define ITEM_TM40                367
#define ITEM_TM41                368
#define ITEM_TM42                369
#define ITEM_TM43                370
#define ITEM_TM44                371
#define ITEM_TM45                372
#define ITEM_TM46                373
#define ITEM_TM47                374
#define ITEM_TM48                375
#define ITEM_TM49                376
#define ITEM_TM50                377
#define ITEM_TM51                378
#define ITEM_TM52                379
#define ITEM_TM53                380
#define ITEM_TM54                381
#define ITEM_TM55                382
#define ITEM_TM56                383
#define ITEM_TM57                384
#define ITEM_TM58                385
#define ITEM_TM59                386
#define ITEM_TM60                387
#define ITEM_TM61                388
#define ITEM_TM62                389
#define ITEM_TM63                390
#define ITEM_TM64                391
#define ITEM_TM65                392
#define ITEM_TM66                393
#define ITEM_TM67                394
#define ITEM_TM68                395
#define ITEM_TM69                396
#define ITEM_TM70                397
#define ITEM_TM71                398
#define ITEM_TM72                399
#define ITEM_TM73                400
#define ITEM_TM74                401
#define ITEM_TM75                402
#define ITEM_TM76                403
#define ITEM_TM77                404
#define ITEM_TM78                405
#define ITEM_TM79                406
#define ITEM_TM80                407
#define ITEM_TM81                408
#define ITEM_TM82                409
#define ITEM_TM83                410
#define ITEM_TM84                411
#define ITEM_TM85                412
#define ITEM_TM86                413
#define ITEM_TM87                414
#define ITEM_TM88                415
#define ITEM_TM89                416
#define ITEM_TM90                417
#define ITEM_TM91                418
#define ITEM_TM92                419
#define ITEM_HM01                420
#define ITEM_HM02                421
#define ITEM_HM03                422
#define ITEM_HM04                423
#define ITEM_HM05                424
#define ITEM_HM06                425
#define ITEM_HM07                426
#define ITEM_HM08                427

#define TM_FOCUS_PUNCH  ITEM_TM01
#define TM_DRAGON_CLAW  ITEM_TM02
#define TM_WATER_PULSE  ITEM_TM03
#define TM_CALM_MIND    ITEM_TM04
#define TM_ROAR         ITEM_TM05
#define TM_TOXIC        ITEM_TM06
#define TM_SNOWSTORM    ITEM_TM07
#define TM_BULK_UP      ITEM_TM08
#define TM_BULLET_SEED  ITEM_TM09
#define TM_HIDDEN_POWER ITEM_TM10
#define TM_SUNNY_DAY    ITEM_TM11
#define TM_TAUNT        ITEM_TM12
#define TM_ICE_BEAM     ITEM_TM13
#define TM_BLIZZARD     ITEM_TM14
#define TM_HYPER_BEAM   ITEM_TM15
#define TM_LIGHT_SCREEN ITEM_TM16
#define TM_PROTECT      ITEM_TM17
#define TM_RAIN_DANCE   ITEM_TM18
#define TM_GIGA_DRAIN   ITEM_TM19
#define TM_SAFEGUARD    ITEM_TM20
#define TM_FRUSTRATION  ITEM_TM21
#define TM_SOLAR_BEAM   ITEM_TM22
#define TM_IRON_TAIL    ITEM_TM23
#define TM_THUNDERBOLT  ITEM_TM24
#define TM_THUNDER      ITEM_TM25
#define TM_EARTHQUAKE   ITEM_TM26
#define TM_RETURN       ITEM_TM27
#define TM_DIG          ITEM_TM28
#define TM_PSYCHIC      ITEM_TM29
#define TM_SHADOW_BALL  ITEM_TM30
#define TM_BRICK_BREAK  ITEM_TM31
#define TM_DOUBLE_TEAM  ITEM_TM32
#define TM_REFLECT      ITEM_TM33
#define TM_SHOCK_WAVE   ITEM_TM34
#define TM_FLAMETHROWER ITEM_TM35
#define TM_SLUDGE_BOMB  ITEM_TM36
#define TM_SANDSTORM    ITEM_TM37
#define TM_FIRE_BLAST   ITEM_TM38
#define TM_ROCK_TOMB    ITEM_TM39
#define TM_AERIAL_ACE   ITEM_TM40
#define TM_TORMENT      ITEM_TM41
#define TM_FACADE       ITEM_TM42
#define TM_SECRET_POWER ITEM_TM43
#define TM_REST         ITEM_TM44
#define TM_ATTRACT      ITEM_TM45
#define TM_THIEF        ITEM_TM46
#define TM_STEEL_WING   ITEM_TM47
#define TM_SKILL_SWAP   ITEM_TM48
#define TM_SNATCH       ITEM_TM49
#define TM_OVERHEAT     ITEM_TM50
#define TM_ROOST        ITEM_TM51
#define TM_FOCUS_BLAST  ITEM_TM52
#define TM_ENERGY_BALL  ITEM_TM53
#define TM_FALSE_SWIPE  ITEM_TM54
#define TM_BRINE        ITEM_TM55
#define TM_FLING        ITEM_TM56
#define TM_CHARGE_BEAM  ITEM_TM57
#define TM_ENDURE       ITEM_TM58
#define TM_DRAGON_PULSE ITEM_TM59
#define TM_DRAIN_PUNCH  ITEM_TM60
#define TM_WILL_O_WISP  ITEM_TM61
#define TM_SILVER_WIND  ITEM_TM62
#define TM_EMBARGO      ITEM_TM63
#define TM_EXPLOSION    ITEM_TM64
#define TM_SHADOW_CLAW  ITEM_TM65
#define TM_PAYBACK      ITEM_TM66
#define TM_RECYCLE      ITEM_TM67
#define TM_GIGA_IMPACT  ITEM_TM68
#define TM_ROCK_POLISH  ITEM_TM69
#define TM_FLASH        ITEM_TM70
#define TM_STONE_EDGE   ITEM_TM71
#define TM_AVALANCHE    ITEM_TM72
#define TM_THUNDER_WAVE ITEM_TM73
#define TM_GYRO_BALL    ITEM_TM74
#define TM_SWORDS_DANCE ITEM_TM75
#define TM_STEALTH_ROCK ITEM_TM76
#define TM_PSYCH_UP     ITEM_TM77
#define TM_CAPTIVATE    ITEM_TM78
#define TM_DARK_PULSE   ITEM_TM79
#define TM_ROCK_SLIDE   ITEM_TM80
#define TM_X_SCISSOR    ITEM_TM81
#define TM_SLEEP_TALK   ITEM_TM82
#define TM_NATURAL_GIFT ITEM_TM83
#define TM_POISON_JAB   ITEM_TM84
#define TM_DREAM_EATER  ITEM_TM85
#define TM_GRASS_KNOT   ITEM_TM86
#define TM_SWAGGER      ITEM_TM87
#define TM_PLUCK        ITEM_TM88
#define TM_U_TURN       ITEM_TM89
#define TM_SUBSTITUTE   ITEM_TM90
#define TM_FLASH_CANNON ITEM_TM91
#define TM_TRICK_ROOM   ITEM_TM92
#define HM_CUT          ITEM_HM01
#define HM_FLY          ITEM_HM02
#define HM_SURF         ITEM_HM03
#define HM_STRENGTH     ITEM_HM04
#define HM_DEFOG        ITEM_HM05
#define HM_ROCK_SMASH   ITEM_HM06
#define HM_WATERFALL    ITEM_HM07
#define HM_ROCK_CLIMB   ITEM_HM08

#define NUM_TMS 92
#define NUM_HMS 8

// Key Items
#define ITEM_EXPLORER_KIT        428
#define ITEM_LOOT_SACK           429
#define ITEM_RULE_BOOK           430
#define ITEM_POKE_RADAR          431
#define ITEM_POINT_CARD          432
#define ITEM_JOURNAL             433
#define ITEM_SEAL_CASE           434
#define ITEM_FASHION_CASE        435
#define ITEM_SEAL_BAG            436
#define ITEM_PAL_PAD             437
#define ITEM_WORKS_KEY           438
#define ITEM_OLD_CHARM           439
#define ITEM_GALACTIC_KEY        440
#define ITEM_RED_CHAIN           441
#define ITEM_TOWN_MAP            442
#define ITEM_VS__SEEKER          443
#define ITEM_COIN_CASE           444
#define ITEM_OLD_ROD             445
#define ITEM_GOOD_ROD            446
#define ITEM_SUPER_ROD           447
#define ITEM_SPRAYDUCK           448
#define ITEM_POFFIN_CASE         449
#define ITEM_BICYCLE             450
#define ITEM_SUITE_KEY           451
#define ITEM_OAKS_LETTER         452
#define ITEM_LUNAR_WING          453
#define ITEM_MEMBER_CARD         454
#define ITEM_AZURE_FLUTE         455
#define ITEM_S_S__TICKET         456
#define ITEM_CONTEST_PASS        457
#define ITEM_MAGMA_STONE         458
#define ITEM_PARCEL              459
#define ITEM_COUPON_1            460
#define ITEM_COUPON_2            461
#define ITEM_COUPON_3            462
#define ITEM_STORAGE_KEY         463
#define ITEM_SECRETPOTION        464
// New to Platinum
#define ITEM_VS__RECORDER        465
#define ITEM_GRACIDEA            466
#define ITEM_SECRET_KEY          467
// New to HGSS
#define ITEM_APRICORN_BOX        468
#define ITEM_UNOWN_REPORT        469
#define ITEM_BERRY_POTS          470
#define ITEM_DOWSING_MCHN        471
#define ITEM_BLUE_CARD           472
#define ITEM_SLOWPOKETAIL        473
#define ITEM_CLEAR_BELL          474
#define ITEM_CARD_KEY            475
#define ITEM_BASEMENT_KEY        476
#define ITEM_SQUIRTBOTTLE        477
#define ITEM_RED_SCALE           478
#define ITEM_LOST_ITEM           479
#define ITEM_PASS                480
#define ITEM_MACHINE_PART        481
#define ITEM_SILVER_WING         482
#define ITEM_RAINBOW_WING        483
#define ITEM_MYSTERY_EGG         484
#define ITEM_RED_APRICORN        485
#define ITEM_YLW_APRICORN        486
#define ITEM_BLU_APRICORN        487
#define ITEM_GRN_APRICORN        488
#define ITEM_PNK_APRICORN        489
#define ITEM_WHT_APRICORN        490
#define ITEM_BLK_APRICORN        491
#define ITEM_FAST_BALL           492
#define ITEM_LEVEL_BALL          493
#define ITEM_LURE_BALL           494
#define ITEM_HEAVY_BALL          495
#define ITEM_LOVE_BALL           496
#define ITEM_FRIEND_BALL         497
#define ITEM_MOON_BALL           498
#define ITEM_SPORT_BALL          499
#define ITEM_PARK_BALL           500
#define ITEM_PHOTO_ALBUM         501
#define ITEM_GB_SOUNDS           502
#define ITEM_TIDAL_BELL          503
#define ITEM_RAGECANDYBAR        504
#define ITEM_DATA_CARD_01        505
#define ITEM_DATA_CARD_02        506
#define ITEM_DATA_CARD_03        507
#define ITEM_DATA_CARD_04        508
#define ITEM_DATA_CARD_05        509
#define ITEM_DATA_CARD_06        510
#define ITEM_DATA_CARD_07        511
#define ITEM_DATA_CARD_08        512
#define ITEM_DATA_CARD_09        513
#define ITEM_DATA_CARD_10        514
#define ITEM_DATA_CARD_11        515
#define ITEM_DATA_CARD_12        516
#define ITEM_DATA_CARD_13        517
#define ITEM_DATA_CARD_14        518
#define ITEM_DATA_CARD_15        519
#define ITEM_DATA_CARD_16        520
#define ITEM_DATA_CARD_17        521
#define ITEM_DATA_CARD_18        522
#define ITEM_DATA_CARD_19        523
#define ITEM_DATA_CARD_20        524
#define ITEM_DATA_CARD_21        525
#define ITEM_DATA_CARD_22        526
#define ITEM_DATA_CARD_23        527
#define ITEM_DATA_CARD_24        528
#define ITEM_DATA_CARD_25        529
#define ITEM_DATA_CARD_26        530
#define ITEM_DATA_CARD_27        531
#define ITEM_JADE_ORB            532
#define ITEM_LOCK_CAPSULE        533
#define ITEM_RED_ORB             534
#define ITEM_BLUE_ORB            535
#define ITEM_ENIGMA_STONE        536
#define ITEMS_COUNT              537

#define ITEM_MIN                1
#define ITEM_MAX  ITEMS_COUNT - 1

//Item Variables
#define ITEM_VAR_HOLD_EFFECT            1
#define ITEM_VAR_MODIFIER               2 //general variable for HP thresholds, damage increase percentages, etc
#define ITEM_VAR_8                      8
#define ITEM_VAR_9                      9
#define ITEM_VAR_10                    10
#define ITEM_NATURAL_GIFT_POWER        11
#define ITEM_NATURAL_GIFT_TYPE         12

//Bug Bite/Pluck/Fling Effects
#define STEAL_EFFECT_CURE_PARALYSIS      1
#define STEAL_EFFECT_CURE_SLEEP          2
#define STEAL_EFFECT_CURE_POISON         3
#define STEAL_EFFECT_CURE_BURN           4
#define STEAL_EFFECT_CURE_FREEZE         5
#define STEAL_EFFECT_RESTORE_PP          6
#define STEAL_EFFECT_RESTORE_HP          7
#define STEAL_EFFECT_CURE_CONFUSION      8
#define STEAL_EFFECT_CURE_ALL            9
#define STEAL_EFFECT_RESTORE_HP_PRCT    10
#define STEAL_EFFECT_RESTORE_SPICY      11
#define STEAL_EFFECT_RESTORE_DRY        12
#define STEAL_EFFECT_RESTORE_SWEET      13
#define STEAL_EFFECT_RESTORE_BITTER     14
#define STEAL_EFFECT_RESTORE_SOUR       15
#define STEAL_EFFECT_ATK_UP             16
#define STEAL_EFFECT_DEF_UP             17    
#define STEAL_EFFECT_SPEED_UP           18    
#define STEAL_EFFECT_SPATK_UP           19    
#define STEAL_EFFECT_SPDEF_UP           20    
#define STEAL_EFFECT_CRITRATE_UP        21
#define STEAL_EFFECT_RANDOM_UP          22
#define STEAL_EFFECT_ACC_UP             23
//The below effects are fling only
#define STEAL_EFFECT_RESET_STATS        24
#define STEAL_EFFECT_CURE_INFATUATION   25
#define STEAL_EFFECT_FLINCH             26
#define STEAL_EFFECT_PARALYZE           27
#define STEAL_EFFECT_POISON             28
#define STEAL_EFFECT_BAD_POISON         29
#define STEAL_EFFECT_BURN               30

#endif //POKEHEARTGOLD_CONSTANTS_ITEMS_H
