#include <SFML/Graphics.hpp>
 
using namespace sf;
const int H = 21;
const int W = 19;

const int ts = 25;

int q = 0;
bool life = true;

String TileMap[H] = {
"AAAAAAAAAAAAAAAAAAA",
"A        A        A",
"A AA AAA A AAA AA A",
"A        A        A",
"A AA A AAAAA A AA A",
"A    A   A   A    A",
"AAAA AAA A AAA AAAA",
"BBBA A       A ABBB",
"AAAA A AA4AA A AAAA",
"BBBB   A123A   BBBB",
"AAAA A AAAAA A AAAA",
"BBBA A       A ABBB",
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


class Player {
public:
	float frame = 0;
	int x = 9, y = 15;
	int newx = 0, newy = 0;
	int rotate = 1, ti = 0;

	void update() {
		frame += 0.1;
		if (frame > 5)
			frame -= 5;

		ti++;
		if (ti >= 300) {
			switch (rotate)
			{
			case 1:
				if (TileMap[y][newx + 1] != 'A')
					newx += 1;
				break;
			case 2:
				if (TileMap[y][newx - 1] != 'A')
					newx -= 1;
				break;
			case 3:
				if (TileMap[newy - 1][x] != 'A')
					newy -= 1;
				break;
			case 4:
				if (TileMap[newy + 1][x] != 'A')
					newy += 1;
				break;
			}

			ti = 0;
		}

		if (TileMap[newy][newx] == ' ' || TileMap[newy][newx] == 'B') {
			if (TileMap[newy][newx] == ' ')
				q++;
			
			if (TileMap[newy][newx] == '1'
				|| TileMap[newy][newx] == '2' || TileMap[newy][newx] == '3' || TileMap[newy][newx] == '4')
				life = false;

			TileMap[y][x] = 'B';

			TileMap[newy][newx] = 'C';

			x = newx;
			y = newy;
		}

		if (newy == 9 && (newx == 0 || newx == 18)) {
			if (newx == 0)
				newx = 17;
			else
				newx = 1;

			TileMap[y][x] = 'B';
			TileMap[newy][newx] = 'C';

			x = newx;
			y = newy;
		}
	}
};

class Enemy {
public:
	int x[4] = { 8, 9, 10, 9}, y[4] = {9, 9, 9, 8};
	int newx[4] = { 0 , 0 , 0, 0 }, newy[4] = { 0, 0, 0, 0 };
	int rotate[4] = { 1, 1, 1, 1 }, ti = 0;

	void update() {
		ti++;

		if (ti >= 300) {
			for (int i = 0; i < 4; i++) {
				rotate[i] = rand() % 4 + 1;

				newx[i] = x[i];
				newy[i] = y[i];

				switch (rotate[i])
				{
				case 1:
					if (TileMap[y[i]][newx[i] + 1] != 'A')
						newx[i] += 1;
					break;
				case 2:
					if (TileMap[y[i]][newx[i] - 1] != 'A')
						newx[i] -= 1;
					break;
				case 3:
					if (TileMap[newy[i] - 1][x[i]] != 'A')
						newy[i] -= 1;
					break;
				case 4:
					if (TileMap[newy[i] + 1][x[i]] != 'A')
						newy[i] += 1;
					break;
				}
			}

			ti = 0;
		}

		for (int i = 0; i < 4; i++) {
			if (TileMap[newy[i]][newx[i]] == ' ' || TileMap[newy[i]][newx[i]] == 'B' ||
				TileMap[newy[i]][newx[i]] == 'C') {
				if (TileMap[newy[i]][newx[i]] == 'B')
					TileMap[y[i]][x[i]] = 'B';
				else if (TileMap[newy[i]][newx[i]] == ' ')
					TileMap[y[i]][x[i]] = ' ';
				else if (TileMap[newy[i]][newx[i]] == 'C')
					life = false;

				if (i == 0)
					TileMap[newy[i]][newx[i]] = '1';
				if (i == 1)
					TileMap[newy[i]][newx[i]] = '2';
				if (i == 2)
					TileMap[newy[i]][newx[i]] = '3';
				if (i == 3)
					TileMap[newy[i]][newx[i]] = '4';

				x[i] = newx[i];
				y[i] = newy[i];
			}

			if (newy[i] == 9 && (newx[i] == 0 || newx[i] == 18)) {
				if (newx[i] == 0)
					newx[i] = 17;
				else
					newx[i] = 1;

				TileMap[y[i]][x[i]] = 'B';
				
				if (i == 0)
					TileMap[newy[i]][newx[i]] = '1';
				if (i == 1)
					TileMap[newy[i]][newx[i]] = '2';
				if (i == 2)
					TileMap[newy[i]][newx[i]] = '3';
				if (i == 3)
					TileMap[newy[i]][newx[i]] = '4';

				x[i] = newx[i];
				y[i] = newy[i];
			}
		}
	}
};

int main()
{
	RenderWindow window(VideoMode(W * ts, H * ts), "PacWoman"); 
 
	Player p;
	Enemy en;
 
	Texture herotexture;
	herotexture.loadFromFile("C:\\Users\\VivoBook\\Desktop\\new.png");
	Sprite plat(herotexture);
 
	Sprite herosprite;
	herosprite.setTexture(herotexture);
	herosprite.setTextureRect(IntRect(0, 0, 25, 25));//получили нужный нам прямоугольник с котом
    int ts = 25;
	while (window.isOpen())	
	{
		sf::Event event;
		while (window.pollEvent(event))
		{   
			if (event.type == sf::Event::Closed)
				window.close();
		}

		if (q < 171 && life) {
			p.update();
			en.update();
		}
        window.clear(Color::Black);

        for (int i = 0; i < H; i++) {
			for (int j = 0; j < W; j++) {
				if (TileMap[i][j] == 'A') herosprite.setTextureRect(IntRect(0,0,25,25));
				if (TileMap[i][j] == 'C') herosprite.setTextureRect(IntRect(ts * int(p.frame), ts * p.rotate, ts, ts));
                if (TileMap[i][j] == ' ') herosprite.setTextureRect(IntRect(25, 0, 50, 25));
				if (TileMap[i][j] == '1') herosprite.setTextureRect(IntRect(ts * 5, ts * en.rotate[0], ts, ts));
				if (TileMap[i][j] == '2') herosprite.setTextureRect(IntRect(ts * 6, ts * en.rotate[1], ts, ts));
				if (TileMap[i][j] == '3') herosprite.setTextureRect(IntRect(ts * 7, ts * en.rotate[1], ts, ts));
				if (TileMap[i][j] == '4') herosprite.setTextureRect(IntRect(ts * 8, ts * en.rotate[1], ts, ts));
                if (TileMap[i][j] == 'B') continue;
                herosprite.setPosition(j * ts, i * ts);
				window.draw(herosprite);
            }
        }
		window.display();
	}

	return 0;
}
