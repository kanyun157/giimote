# Introduction #

Wii Sports, the Everybody Votes Channel, and many other games and channels make use of Mii data. Some games and channels store Mii data on the Wii Remote in a special two-block file system. The Mii Channel, for instance, stores Mii Parade data on the Wii Remote and can also store Mii data at the user's request.


# Details #

Mii data is stored on the Wii Remote in two blocks of 750 bytes a piece each followed by a two byte CRC checksum. The second block functions as a backup. If the data in the first block does not match the CRC the second block is used. If the second block does not match the checksum, then no Mii data will be available. These 752 byte blocks are stored consecutively in memory starting at address 0x0fca.


## Block Format ##

Each block starts with the four bytes "RNCD". The next two bytes determine which slots are Mii parade slots. To set a Mii slot as a parade slot, left shift 0x0001 by the slot number. Any empty (or non-parade Mii) slot should have its corresponding bit set to 0.
Following this is the raw Mii Data, which in turn is followed by a two byte CRC-16 CCITT of the previous 750 bytes.


## Mii Format ##

Each Mii is stored as 0x4a bytes. Strings in the Mii data are stored in big-endian Unicode format (UTF-16) and are padded with zeros.

A rudimentary Mii data structure (taken from WiiLi) can be found below:

```
typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

#define MII_NAME_LENGTH			10
#define MII_CREATOR_NAME_LENGTH	10

#define MII_HEIGHT_MIN			0x00
#define MII_HEIGHT_MAX			0x7F

#define MII_WEIGHT_MIN			0x00
#define MII_WEIGHT_MAX			0x7F

typedef struct
{
// addr: 0x00 & 0x01
	u16 invalid:1;
	u16 isGirl:1;
	u16 month:4;
	u16 day:5;
	u16 favColor:4;		// 0 - 11
	u16 unknown:1;

// addr: 0x02 through 0x15
	u16 name[MII_NAME_LENGTH];

// addr: 0x16
	u8 height;

// addr: 0x17
	u8 weight;

// addr: 0x18 - 0x1B
 	u8 miiID1; 	// Unique Mii identifier
 	u8 miiID2;
 	u8 miiID3;
 	u8 miiID4;

// addr: 0x1C & 0x1D & 0x1E & 0x1F
	u8 systemID0;	// Checksum8 of first 3 bytes of mac addr
	u8 systemID1;	// mac addr 3rd-to-last byte
	u8 systemID2;	// mac addr 2nd-to-last byte
	u8 systemID3;	// mac addr last byte

// addr: 0x20
	u16 faceshape:3;
	u16 skinColor:3;     // 0 - 5
	u16 unknown:?;
	u16 facialFeature:4; // 0 - 11

// addr: 0x22 & 0x23
	u16 unknown:7;       // Hair type falls in here
	u16 hairColor:3;
	u16 hairPart:1;

// addr: 0x24 & 0x25
	u16 unknown:?;       // Eyebrow type falls in here
	u16 eyebrowrotation:?;
	u16 unknown:?;

// addr: 0x26 & 0x27
	u16 eyebrowColor:3;
	u16 eyebrowSize:5;	// min 0, max 16 (depends on eyebrow type?)
	u16 eyebrowVOffset:?;
	u16 eyebrowSpacing:?;

// addr: 0x28 & 0x29
	u16 unknown:8;        // Eye type falls in here
	u16 eyeRotation:3;
	u16 unknown:1;
	u16 eyeHeight:4;      // 12 == mid, 0 == highest

// addr: 0x2A & 0x2B
	u16	eyeColor:3;
	u16	unknown:13;

// addr: 0x2C & 0x2D
	u16 noseType:4;			// 0 - 11
	u16 noseSize:4;			// 0 - 8
	u16 noseHeight:4;		// 0 - 9?
	u16 unknown:3;

// addr: 0x2E & 2F
	u16 lipType:5;
	u16 unknown:11;

// addr: 0x30
	u8 unknown:1;
	u8 glassesType:3;
	u8 glassesColor:3;
	u8 unknown:1;

// addr: 0x31 & 32
	u16 glassesSize:3;
	u16 unknown:1;
	u16 glassesHeight:4;
	u16 mustacheType:2;
	u16 beardType:2;
	u16 facialHairColor:3;
	u16 unknown:2;

// addr: 0x33
	u8 mustacheSize:3;	// 0 (max) -�? (min)
	u8 unknown:1;
	u8 mustacheHeight:4;	// 0 (high) - 16 (low)

// addr: 0x34 & 0x35
	u16 moleOn:1;
	u16 moleSize:3;		//�? - 8
	u16 moleHeight:5;		// 0 - 
	u16 unknown:4;
	u16 moleHorizontal:3;	// 0 (left) -�? (right)

// addr: 0x36
	u16 creatorName[MII_CREATOR_NAME_LENGTH];
} MII_DATA_STRUCT;
```