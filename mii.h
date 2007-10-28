// mii.h - Contains a list of Mii related constants.
// Mii functions should probably be moved here later.

#define MII_DATA_START 0xFCA
#define MII_DATA_END 0x15AA
#define MII_BLOCK_SIZE 0x2F0
// Replaced with a function (So that GM can re-use the same code)
// #define MII_BLOCK_ADDRESS(b) (MII_DATA_START + (b) * MII_BLOCK_SIZE)
#define MII_DATA_LENGTH (MII_BLOCK_SIZE * 2)
#define MII_LENGTH 0x4a

#define MII_NAME_LENGTH				10
#define MII_CREATOR_NAME_LENGTH		10

#define MII_HEIGHT_MIN				0x00
#define MII_HEIGHT_MAX				0x7F

#define MII_WEIGHT_MIN				0x00
#define MII_WEIGHT_MAX				0x7F

#define poly 0x1021 // crc-ccitt mask
