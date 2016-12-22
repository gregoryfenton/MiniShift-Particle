Minishift-Particle

Particle library for the @ArachnidLabs Minishift

Ported by Gregory Fenton, http://labby.co.uk

Minishift pinout (Pin 1 at top, 5 at bottom, bottom signified by black dot matrix letters/numbers on white plastic):
1	Power (3v3 or 5v)
2	Gnd
3	SCK		(Clock)
4	CS		(Latch)
5	MOSI	(Data)

All lines go to the female header, the male header is for the next Minishift module.

Usage:
Ensure you set the minishift pins to OUTPUT in setup()
Create a MiniShift object using
MiniShift ms(dataPin, clockPin, latchPin);

Display the message using
ms.writeString(String message);
To add a delay between columns (slow the text down) use
ms.writeString(String message, int delayMS);
To add a gap between columns (so characters do not abut) use
ms.writeString(String message, int delayMS, int columns);

To output raw data (such as a picture) to the minishift use:
ms.writeColumns()
for example:
int i;
unsigned const char smileyFace[] = {
	0b00111100, //  XXXX 
	0b01000010, // X    X
	0b10101001, //X X X  X
	0b10000101, //X    X X
	0b10000101,	//X    X X
	0b10101001, //X X X  X
	0b01000010, // X    X
	0b00111100	//  XXXX 
}; //Note the face is sideways, the data gets read in a column at a time not a row at a time
for(i = 0; i < 8; i++)//Fill 8 minishift modules with smiley faces
{
	ms.writeColumns(smileyFace, 8 /* 8 bytes of data */, 40 /* 40ms gap between columns */);
}

Have fun, and let me (@gregoryfenton) and ArachnidLabs (@ArachnidLabs) know what you get up to [:)]