#ifndef MOSCLIB_HAS_MIKEOS_COLOURS
#define MOSCLIB_HAS_MIKEOS_COLOURS

/** \name Foreground Colours
  * \anchor fgcolours
  *
  * @{
  */
#define  BLACK         0x0
#define  BLUE          0x1
#define  GREEN         0x2
#define  CYAN          0x3
#define  RED           0x4
#define  MAGENTA       0x5
#define  BROWN         0x6
#define  LIGHTGREY     0x7
#define  GREY          0x8
#define  LIGHTBLUE     0x9
#define  LIGHTGREEN    0xA
#define  LIGHTCYAN     0xB
#define  LIGHTRED      0xC
#define  LIGHTMAGENTA  0xD
#define  YELLOW        0xE
#define  WHITE         0xF
/**@}*/

/** \name Background Colours
  * \anchor bgcolours
  * @{
  */
#define  BLACK_BG         BLACK         <<  4
#define  BLUE_BG          BLUE          <<  4
#define  GREEN_BG         GREEN         <<  4
#define  CYAN_BG          CYAN          <<  4
#define  RED_BG           RED           <<  4
#define  MAGENTA_BG       MAGENTA       <<  4
#define  BROWN_BG         BROWN         <<  4
#define  LIGHTGREY_BG     LIGHTGREY     <<  4
#define  GREY_BG          GREY          <<  4
#define  LIGHTBLUE_BG     LIGHTBLUE     <<  4
#define  LIGHTGREEN_BG    LIGHTGREEN    <<  4
#define  LIGHTCYAN_BG     LIGHTCYAN     <<  4
#define  LIGHTRED_BG      LIGHTRED      <<  4
#define  LIGHTMAGENTA_BG  LIGHTMAGENTA  <<  4
#define  YELLOW_BG        YELLOW        <<  4
#define  WHITE_BG         WHITE         <<  4
/**@}*/


/** \name Colour Combinations
  * \anchor dblcolours
  * @{
  */
#define  BLACK_ON_BLACK                BLACK         |  BLACK_BG
#define  BLUE_ON_BLACK                 BLUE          |  BLACK_BG
#define  GREEN_ON_BLACK                GREEN         |  BLACK_BG
#define  CYAN_ON_BLACK                 CYAN          |  BLACK_BG
#define  RED_ON_BLACK                  RED           |  BLACK_BG
#define  MAGENTA_ON_BLACK              MAGENTA       |  BLACK_BG
#define  BROWN_ON_BLACK                BROWN         |  BLACK_BG
#define  LIGHTGREY_ON_BLACK            LIGHTGREY     |  BLACK_BG
#define  GREY_ON_BLACK                 GREY          |  BLACK_BG
#define  LIGHTBLUE_ON_BLACK            LIGHTBLUE     |  BLACK_BG
#define  LIGHTGREEN_ON_BLACK           LIGHTGREEN    |  BLACK_BG
#define  LIGHTCYAN_ON_BLACK            LIGHTCYAN     |  BLACK_BG
#define  LIGHTRED_ON_BLACK             LIGHTRED      |  BLACK_BG
#define  LIGHTMAGENTA_ON_BLACK         LIGHTMAGENTA  |  BLACK_BG
#define  YELLOW_ON_BLACK               YELLOW        |  BLACK_BG
#define  WHITE_ON_BLACK                WHITE         |  BLACK_BG
#define  BLACK_ON_BLUE                 BLACK         |  BLUE_BG
#define  BLUE_ON_BLUE                  BLUE          |  BLUE_BG
#define  GREEN_ON_BLUE                 GREEN         |  BLUE_BG
#define  CYAN_ON_BLUE                  CYAN          |  BLUE_BG
#define  RED_ON_BLUE                   RED           |  BLUE_BG
#define  MAGENTA_ON_BLUE               MAGENTA       |  BLUE_BG
#define  BROWN_ON_BLUE                 BROWN         |  BLUE_BG
#define  LIGHTGREY_ON_BLUE             LIGHTGREY     |  BLUE_BG
#define  GREY_ON_BLUE                  GREY          |  BLUE_BG
#define  LIGHTBLUE_ON_BLUE             LIGHTBLUE     |  BLUE_BG
#define  LIGHTGREEN_ON_BLUE            LIGHTGREEN    |  BLUE_BG
#define  LIGHTCYAN_ON_BLUE             LIGHTCYAN     |  BLUE_BG
#define  LIGHTRED_ON_BLUE              LIGHTRED      |  BLUE_BG
#define  LIGHTMAGENTA_ON_BLUE          LIGHTMAGENTA  |  BLUE_BG
#define  YELLOW_ON_BLUE                YELLOW        |  BLUE_BG
#define  WHITE_ON_BLUE                 WHITE         |  BLUE_BG
#define  BLACK_ON_GREEN                BLACK         |  GREEN_BG
#define  BLUE_ON_GREEN                 BLUE          |  GREEN_BG
#define  GREEN_ON_GREEN                GREEN         |  GREEN_BG
#define  CYAN_ON_GREEN                 CYAN          |  GREEN_BG
#define  RED_ON_GREEN                  RED           |  GREEN_BG
#define  MAGENTA_ON_GREEN              MAGENTA       |  GREEN_BG
#define  BROWN_ON_GREEN                BROWN         |  GREEN_BG
#define  LIGHTGREY_ON_GREEN            LIGHTGREY     |  GREEN_BG
#define  GREY_ON_GREEN                 GREY          |  GREEN_BG
#define  LIGHTBLUE_ON_GREEN            LIGHTBLUE     |  GREEN_BG
#define  LIGHTGREEN_ON_GREEN           LIGHTGREEN    |  GREEN_BG
#define  LIGHTCYAN_ON_GREEN            LIGHTCYAN     |  GREEN_BG
#define  LIGHTRED_ON_GREEN             LIGHTRED      |  GREEN_BG
#define  LIGHTMAGENTA_ON_GREEN         LIGHTMAGENTA  |  GREEN_BG
#define  YELLOW_ON_GREEN               YELLOW        |  GREEN_BG
#define  WHITE_ON_GREEN                WHITE         |  GREEN_BG
#define  BLACK_ON_CYAN                 BLACK         |  CYAN_BG
#define  BLUE_ON_CYAN                  BLUE          |  CYAN_BG
#define  GREEN_ON_CYAN                 GREEN         |  CYAN_BG
#define  CYAN_ON_CYAN                  CYAN          |  CYAN_BG
#define  RED_ON_CYAN                   RED           |  CYAN_BG
#define  MAGENTA_ON_CYAN               MAGENTA       |  CYAN_BG
#define  BROWN_ON_CYAN                 BROWN         |  CYAN_BG
#define  LIGHTGREY_ON_CYAN             LIGHTGREY     |  CYAN_BG
#define  GREY_ON_CYAN                  GREY          |  CYAN_BG
#define  LIGHTBLUE_ON_CYAN             LIGHTBLUE     |  CYAN_BG
#define  LIGHTGREEN_ON_CYAN            LIGHTGREEN    |  CYAN_BG
#define  LIGHTCYAN_ON_CYAN             LIGHTCYAN     |  CYAN_BG
#define  LIGHTRED_ON_CYAN              LIGHTRED      |  CYAN_BG
#define  LIGHTMAGENTA_ON_CYAN          LIGHTMAGENTA  |  CYAN_BG
#define  YELLOW_ON_CYAN                YELLOW        |  CYAN_BG
#define  WHITE_ON_CYAN                 WHITE         |  CYAN_BG
#define  BLACK_ON_RED                  BLACK         |  RED_BG
#define  BLUE_ON_RED                   BLUE          |  RED_BG
#define  GREEN_ON_RED                  GREEN         |  RED_BG
#define  CYAN_ON_RED                   CYAN          |  RED_BG
#define  RED_ON_RED                    RED           |  RED_BG
#define  MAGENTA_ON_RED                MAGENTA       |  RED_BG
#define  BROWN_ON_RED                  BROWN         |  RED_BG
#define  LIGHTGREY_ON_RED              LIGHTGREY     |  RED_BG
#define  GREY_ON_RED                   GREY          |  RED_BG
#define  LIGHTBLUE_ON_RED              LIGHTBLUE     |  RED_BG
#define  LIGHTGREEN_ON_RED             LIGHTGREEN    |  RED_BG
#define  LIGHTCYAN_ON_RED              LIGHTCYAN     |  RED_BG
#define  LIGHTRED_ON_RED               LIGHTRED      |  RED_BG
#define  LIGHTMAGENTA_ON_RED           LIGHTMAGENTA  |  RED_BG
#define  YELLOW_ON_RED                 YELLOW        |  RED_BG
#define  WHITE_ON_RED                  WHITE         |  RED_BG
#define  BLACK_ON_MAGENTA              BLACK         |  MAGENTA_BG
#define  BLUE_ON_MAGENTA               BLUE          |  MAGENTA_BG
#define  GREEN_ON_MAGENTA              GREEN         |  MAGENTA_BG
#define  CYAN_ON_MAGENTA               CYAN          |  MAGENTA_BG
#define  RED_ON_MAGENTA                RED           |  MAGENTA_BG
#define  MAGENTA_ON_MAGENTA            MAGENTA       |  MAGENTA_BG
#define  BROWN_ON_MAGENTA              BROWN         |  MAGENTA_BG
#define  LIGHTGREY_ON_MAGENTA          LIGHTGREY     |  MAGENTA_BG
#define  GREY_ON_MAGENTA               GREY          |  MAGENTA_BG
#define  LIGHTBLUE_ON_MAGENTA          LIGHTBLUE     |  MAGENTA_BG
#define  LIGHTGREEN_ON_MAGENTA         LIGHTGREEN    |  MAGENTA_BG
#define  LIGHTCYAN_ON_MAGENTA          LIGHTCYAN     |  MAGENTA_BG
#define  LIGHTRED_ON_MAGENTA           LIGHTRED      |  MAGENTA_BG
#define  LIGHTMAGENTA_ON_MAGENTA       LIGHTMAGENTA  |  MAGENTA_BG
#define  YELLOW_ON_MAGENTA             YELLOW        |  MAGENTA_BG
#define  WHITE_ON_MAGENTA              WHITE         |  MAGENTA_BG
#define  BLACK_ON_BROWN                BLACK         |  BROWN_BG
#define  BLUE_ON_BROWN                 BLUE          |  BROWN_BG
#define  GREEN_ON_BROWN                GREEN         |  BROWN_BG
#define  CYAN_ON_BROWN                 CYAN          |  BROWN_BG
#define  RED_ON_BROWN                  RED           |  BROWN_BG
#define  MAGENTA_ON_BROWN              MAGENTA       |  BROWN_BG
#define  BROWN_ON_BROWN                BROWN         |  BROWN_BG
#define  LIGHTGREY_ON_BROWN            LIGHTGREY     |  BROWN_BG
#define  GREY_ON_BROWN                 GREY          |  BROWN_BG
#define  LIGHTBLUE_ON_BROWN            LIGHTBLUE     |  BROWN_BG
#define  LIGHTGREEN_ON_BROWN           LIGHTGREEN    |  BROWN_BG
#define  LIGHTCYAN_ON_BROWN            LIGHTCYAN     |  BROWN_BG
#define  LIGHTRED_ON_BROWN             LIGHTRED      |  BROWN_BG
#define  LIGHTMAGENTA_ON_BROWN         LIGHTMAGENTA  |  BROWN_BG
#define  YELLOW_ON_BROWN               YELLOW        |  BROWN_BG
#define  WHITE_ON_BROWN                WHITE         |  BROWN_BG
#define  BLACK_ON_LIGHTGREY            BLACK         |  LIGHTGREY_BG
#define  BLUE_ON_LIGHTGREY             BLUE          |  LIGHTGREY_BG
#define  GREEN_ON_LIGHTGREY            GREEN         |  LIGHTGREY_BG
#define  CYAN_ON_LIGHTGREY             CYAN          |  LIGHTGREY_BG
#define  RED_ON_LIGHTGREY              RED           |  LIGHTGREY_BG
#define  MAGENTA_ON_LIGHTGREY          MAGENTA       |  LIGHTGREY_BG
#define  BROWN_ON_LIGHTGREY            BROWN         |  LIGHTGREY_BG
#define  LIGHTGREY_ON_LIGHTGREY        LIGHTGREY     |  LIGHTGREY_BG
#define  GREY_ON_LIGHTGREY             GREY          |  LIGHTGREY_BG
#define  LIGHTBLUE_ON_LIGHTGREY        LIGHTBLUE     |  LIGHTGREY_BG
#define  LIGHTGREEN_ON_LIGHTGREY       LIGHTGREEN    |  LIGHTGREY_BG
#define  LIGHTCYAN_ON_LIGHTGREY        LIGHTCYAN     |  LIGHTGREY_BG
#define  LIGHTRED_ON_LIGHTGREY         LIGHTRED      |  LIGHTGREY_BG
#define  LIGHTMAGENTA_ON_LIGHTGREY     LIGHTMAGENTA  |  LIGHTGREY_BG
#define  YELLOW_ON_LIGHTGREY           YELLOW        |  LIGHTGREY_BG
#define  WHITE_ON_LIGHTGREY            WHITE         |  LIGHTGREY_BG
#define  BLACK_ON_GREY                 BLACK         |  GREY_BG
#define  BLUE_ON_GREY                  BLUE          |  GREY_BG
#define  GREEN_ON_GREY                 GREEN         |  GREY_BG
#define  CYAN_ON_GREY                  CYAN          |  GREY_BG
#define  RED_ON_GREY                   RED           |  GREY_BG
#define  MAGENTA_ON_GREY               MAGENTA       |  GREY_BG
#define  BROWN_ON_GREY                 BROWN         |  GREY_BG
#define  LIGHTGREY_ON_GREY             LIGHTGREY     |  GREY_BG
#define  GREY_ON_GREY                  GREY          |  GREY_BG
#define  LIGHTBLUE_ON_GREY             LIGHTBLUE     |  GREY_BG
#define  LIGHTGREEN_ON_GREY            LIGHTGREEN    |  GREY_BG
#define  LIGHTCYAN_ON_GREY             LIGHTCYAN     |  GREY_BG
#define  LIGHTRED_ON_GREY              LIGHTRED      |  GREY_BG
#define  LIGHTMAGENTA_ON_GREY          LIGHTMAGENTA  |  GREY_BG
#define  YELLOW_ON_GREY                YELLOW        |  GREY_BG
#define  WHITE_ON_GREY                 WHITE         |  GREY_BG
#define  BLACK_ON_LIGHTBLUE            BLACK         |  LIGHTBLUE_BG
#define  BLUE_ON_LIGHTBLUE             BLUE          |  LIGHTBLUE_BG
#define  GREEN_ON_LIGHTBLUE            GREEN         |  LIGHTBLUE_BG
#define  CYAN_ON_LIGHTBLUE             CYAN          |  LIGHTBLUE_BG
#define  RED_ON_LIGHTBLUE              RED           |  LIGHTBLUE_BG
#define  MAGENTA_ON_LIGHTBLUE          MAGENTA       |  LIGHTBLUE_BG
#define  BROWN_ON_LIGHTBLUE            BROWN         |  LIGHTBLUE_BG
#define  LIGHTGREY_ON_LIGHTBLUE        LIGHTGREY     |  LIGHTBLUE_BG
#define  GREY_ON_LIGHTBLUE             GREY          |  LIGHTBLUE_BG
#define  LIGHTBLUE_ON_LIGHTBLUE        LIGHTBLUE     |  LIGHTBLUE_BG
#define  LIGHTGREEN_ON_LIGHTBLUE       LIGHTGREEN    |  LIGHTBLUE_BG
#define  LIGHTCYAN_ON_LIGHTBLUE        LIGHTCYAN     |  LIGHTBLUE_BG
#define  LIGHTRED_ON_LIGHTBLUE         LIGHTRED      |  LIGHTBLUE_BG
#define  LIGHTMAGENTA_ON_LIGHTBLUE     LIGHTMAGENTA  |  LIGHTBLUE_BG
#define  YELLOW_ON_LIGHTBLUE           YELLOW        |  LIGHTBLUE_BG
#define  WHITE_ON_LIGHTBLUE            WHITE         |  LIGHTBLUE_BG
#define  BLACK_ON_LIGHTGREEN           BLACK         |  LIGHTGREEN_BG
#define  BLUE_ON_LIGHTGREEN            BLUE          |  LIGHTGREEN_BG
#define  GREEN_ON_LIGHTGREEN           GREEN         |  LIGHTGREEN_BG
#define  CYAN_ON_LIGHTGREEN            CYAN          |  LIGHTGREEN_BG
#define  RED_ON_LIGHTGREEN             RED           |  LIGHTGREEN_BG
#define  MAGENTA_ON_LIGHTGREEN         MAGENTA       |  LIGHTGREEN_BG
#define  BROWN_ON_LIGHTGREEN           BROWN         |  LIGHTGREEN_BG
#define  LIGHTGREY_ON_LIGHTGREEN       LIGHTGREY     |  LIGHTGREEN_BG
#define  GREY_ON_LIGHTGREEN            GREY          |  LIGHTGREEN_BG
#define  LIGHTBLUE_ON_LIGHTGREEN       LIGHTBLUE     |  LIGHTGREEN_BG
#define  LIGHTGREEN_ON_LIGHTGREEN      LIGHTGREEN    |  LIGHTGREEN_BG
#define  LIGHTCYAN_ON_LIGHTGREEN       LIGHTCYAN     |  LIGHTGREEN_BG
#define  LIGHTRED_ON_LIGHTGREEN        LIGHTRED      |  LIGHTGREEN_BG
#define  LIGHTMAGENTA_ON_LIGHTGREEN    LIGHTMAGENTA  |  LIGHTGREEN_BG
#define  YELLOW_ON_LIGHTGREEN          YELLOW        |  LIGHTGREEN_BG
#define  WHITE_ON_LIGHTGREEN           WHITE         |  LIGHTGREEN_BG
#define  BLACK_ON_LIGHTCYAN            BLACK         |  LIGHTCYAN_BG
#define  BLUE_ON_LIGHTCYAN             BLUE          |  LIGHTCYAN_BG
#define  GREEN_ON_LIGHTCYAN            GREEN         |  LIGHTCYAN_BG
#define  CYAN_ON_LIGHTCYAN             CYAN          |  LIGHTCYAN_BG
#define  RED_ON_LIGHTCYAN              RED           |  LIGHTCYAN_BG
#define  MAGENTA_ON_LIGHTCYAN          MAGENTA       |  LIGHTCYAN_BG
#define  BROWN_ON_LIGHTCYAN            BROWN         |  LIGHTCYAN_BG
#define  LIGHTGREY_ON_LIGHTCYAN        LIGHTGREY     |  LIGHTCYAN_BG
#define  GREY_ON_LIGHTCYAN             GREY          |  LIGHTCYAN_BG
#define  LIGHTBLUE_ON_LIGHTCYAN        LIGHTBLUE     |  LIGHTCYAN_BG
#define  LIGHTGREEN_ON_LIGHTCYAN       LIGHTGREEN    |  LIGHTCYAN_BG
#define  LIGHTCYAN_ON_LIGHTCYAN        LIGHTCYAN     |  LIGHTCYAN_BG
#define  LIGHTRED_ON_LIGHTCYAN         LIGHTRED      |  LIGHTCYAN_BG
#define  LIGHTMAGENTA_ON_LIGHTCYAN     LIGHTMAGENTA  |  LIGHTCYAN_BG
#define  YELLOW_ON_LIGHTCYAN           YELLOW        |  LIGHTCYAN_BG
#define  WHITE_ON_LIGHTCYAN            WHITE         |  LIGHTCYAN_BG
#define  BLACK_ON_LIGHTRED             BLACK         |  LIGHTRED_BG
#define  BLUE_ON_LIGHTRED              BLUE          |  LIGHTRED_BG
#define  GREEN_ON_LIGHTRED             GREEN         |  LIGHTRED_BG
#define  CYAN_ON_LIGHTRED              CYAN          |  LIGHTRED_BG
#define  RED_ON_LIGHTRED               RED           |  LIGHTRED_BG
#define  MAGENTA_ON_LIGHTRED           MAGENTA       |  LIGHTRED_BG
#define  BROWN_ON_LIGHTRED             BROWN         |  LIGHTRED_BG
#define  LIGHTGREY_ON_LIGHTRED         LIGHTGREY     |  LIGHTRED_BG
#define  GREY_ON_LIGHTRED              GREY          |  LIGHTRED_BG
#define  LIGHTBLUE_ON_LIGHTRED         LIGHTBLUE     |  LIGHTRED_BG
#define  LIGHTGREEN_ON_LIGHTRED        LIGHTGREEN    |  LIGHTRED_BG
#define  LIGHTCYAN_ON_LIGHTRED         LIGHTCYAN     |  LIGHTRED_BG
#define  LIGHTRED_ON_LIGHTRED          LIGHTRED      |  LIGHTRED_BG
#define  LIGHTMAGENTA_ON_LIGHTRED      LIGHTMAGENTA  |  LIGHTRED_BG
#define  YELLOW_ON_LIGHTRED            YELLOW        |  LIGHTRED_BG
#define  WHITE_ON_LIGHTRED             WHITE         |  LIGHTRED_BG
#define  BLACK_ON_LIGHTMAGENTA         BLACK         |  LIGHTMAGENTA_BG
#define  BLUE_ON_LIGHTMAGENTA          BLUE          |  LIGHTMAGENTA_BG
#define  GREEN_ON_LIGHTMAGENTA         GREEN         |  LIGHTMAGENTA_BG
#define  CYAN_ON_LIGHTMAGENTA          CYAN          |  LIGHTMAGENTA_BG
#define  RED_ON_LIGHTMAGENTA           RED           |  LIGHTMAGENTA_BG
#define  MAGENTA_ON_LIGHTMAGENTA       MAGENTA       |  LIGHTMAGENTA_BG
#define  BROWN_ON_LIGHTMAGENTA         BROWN         |  LIGHTMAGENTA_BG
#define  LIGHTGREY_ON_LIGHTMAGENTA     LIGHTGREY     |  LIGHTMAGENTA_BG
#define  GREY_ON_LIGHTMAGENTA          GREY          |  LIGHTMAGENTA_BG
#define  LIGHTBLUE_ON_LIGHTMAGENTA     LIGHTBLUE     |  LIGHTMAGENTA_BG
#define  LIGHTGREEN_ON_LIGHTMAGENTA    LIGHTGREEN    |  LIGHTMAGENTA_BG
#define  LIGHTCYAN_ON_LIGHTMAGENTA     LIGHTCYAN     |  LIGHTMAGENTA_BG
#define  LIGHTRED_ON_LIGHTMAGENTA      LIGHTRED      |  LIGHTMAGENTA_BG
#define  LIGHTMAGENTA_ON_LIGHTMAGENTA  LIGHTMAGENTA  |  LIGHTMAGENTA_BG
#define  YELLOW_ON_LIGHTMAGENTA        YELLOW        |  LIGHTMAGENTA_BG
#define  WHITE_ON_LIGHTMAGENTA         WHITE         |  LIGHTMAGENTA_BG
#define  BLACK_ON_YELLOW               BLACK         |  YELLOW_BG
#define  BLUE_ON_YELLOW                BLUE          |  YELLOW_BG
#define  GREEN_ON_YELLOW               GREEN         |  YELLOW_BG
#define  CYAN_ON_YELLOW                CYAN          |  YELLOW_BG
#define  RED_ON_YELLOW                 RED           |  YELLOW_BG
#define  MAGENTA_ON_YELLOW             MAGENTA       |  YELLOW_BG
#define  BROWN_ON_YELLOW               BROWN         |  YELLOW_BG
#define  LIGHTGREY_ON_YELLOW           LIGHTGREY     |  YELLOW_BG
#define  GREY_ON_YELLOW                GREY          |  YELLOW_BG
#define  LIGHTBLUE_ON_YELLOW           LIGHTBLUE     |  YELLOW_BG
#define  LIGHTGREEN_ON_YELLOW          LIGHTGREEN    |  YELLOW_BG
#define  LIGHTCYAN_ON_YELLOW           LIGHTCYAN     |  YELLOW_BG
#define  LIGHTRED_ON_YELLOW            LIGHTRED      |  YELLOW_BG
#define  LIGHTMAGENTA_ON_YELLOW        LIGHTMAGENTA  |  YELLOW_BG
#define  YELLOW_ON_YELLOW              YELLOW        |  YELLOW_BG
#define  WHITE_ON_YELLOW               WHITE         |  YELLOW_BG
#define  BLACK_ON_WHITE                BLACK         |  WHITE_BG
#define  BLUE_ON_WHITE                 BLUE          |  WHITE_BG
#define  GREEN_ON_WHITE                GREEN         |  WHITE_BG
#define  CYAN_ON_WHITE                 CYAN          |  WHITE_BG
#define  RED_ON_WHITE                  RED           |  WHITE_BG
#define  MAGENTA_ON_WHITE              MAGENTA       |  WHITE_BG
#define  BROWN_ON_WHITE                BROWN         |  WHITE_BG
#define  LIGHTGREY_ON_WHITE            LIGHTGREY     |  WHITE_BG
#define  GREY_ON_WHITE                 GREY          |  WHITE_BG
#define  LIGHTBLUE_ON_WHITE            LIGHTBLUE     |  WHITE_BG
#define  LIGHTGREEN_ON_WHITE           LIGHTGREEN    |  WHITE_BG
#define  LIGHTCYAN_ON_WHITE            LIGHTCYAN     |  WHITE_BG
#define  LIGHTRED_ON_WHITE             LIGHTRED      |  WHITE_BG
#define  LIGHTMAGENTA_ON_WHITE         LIGHTMAGENTA  |  WHITE_BG
#define  YELLOW_ON_WHITE               YELLOW        |  WHITE_BG
#define  WHITE_ON_WHITE                WHITE         |  WHITE_BG
/**@}*/

#endif
