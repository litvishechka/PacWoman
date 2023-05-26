#ifndef SOME_FILE_H
#define SOME_FILE_H
#include <string>
const int height  = 21;
const int width = 19;

const int ts = 25;

int counter = 0;
bool life = true;
int restartTime = 5000;

std::string TileMap[height] = {
"AAAAAAAAAAAAAAAAAAA",
"A        A        A",
"A AA AAA A AAA AA A",
"A        A        A",
"A AA A AAAAA A AA A",
"A    A   A   A    A",
"AAAA AAA A AAA AAAA",
"   A A       A A   ",
"AAAA A AA4AA A AAAA",
"       A123A       ",
"AAAA A AAAAA A AAAA",
"   A A       A A   ",
"AAAA A AAAAA A AAAA",
"A        A        A",
"A AA AAA A AAA AA A",
"A  A     C     A  A",
"AA A A AAAAA A A AA",
"A    A   A   A    A",
"A AAAAAA A AAAAAA A",
"A                 A",
"AAAAAAAAAAAAAAAAAAA",
};

void clearing_card() {
	for (int i = 0; i <= 2; i++)
		for (int j = 0; j <= 2; j++) {
			for (int x = 0; x < 2; x++) {
				TileMap[7 + j * 2][i + 16 * x] = 'B';

				TileMap[9][3 + 12 * x] = 'B';
			}

			TileMap[9][8 + j] = 'B';
		}
}

#endif
