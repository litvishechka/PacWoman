#include <SFML/Graphics.hpp>
#include <time.h>
 
using namespace sf;
const int height  = 21;
const int width = 19;

const int ts = 25;

int counter = 0;
bool life = true;

String TileMap[height] = {
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
	int new_x = 0, new_y = 0;
	int direction_movement = 1, delay = 0;

	void update() {
		frame += 0.1;
		if (frame > 5)
			frame -= 5;

		delay++;
		if (delay >= 500) {
			switch (direction_movement)
			{
			case 1:
				if (TileMap[y][new_x + 1] != 'A')
					new_x += 1;
				break;
			case 2:
				if (TileMap[y][new_x - 1] != 'A')
					new_x -= 1;
				break;
			case 3:
				if (TileMap[new_y - 1][x] != 'A')
					new_y -= 1;
				break;
			case 4:
				if (TileMap[new_y + 1][x] != 'A')
					new_y += 1;
				break;
			}

			delay = 0;
		}

		if (TileMap[new_y][new_x] == ' ' || TileMap[new_y][new_x] == 'B') {
			if (TileMap[new_y][new_x] == ' ')
				counter++;
			
			if (TileMap[new_y][new_x] == '1'
				|| TileMap[new_y][new_x] == '2' || TileMap[new_y][new_x] == '3' || TileMap[new_y][new_x] == '4')
				life = false;

			TileMap[y][x] = 'B';

			TileMap[new_y][new_x] = 'C';

			x = new_x;
			y = new_y;
		}

		if (new_y == 9 && (new_x == 0 || new_x == 18)) {
			if (new_x == 0)
				new_x = 17;
			else
				new_x = 1;

			TileMap[y][x] = 'B';
			TileMap[new_y][new_x] = 'C';

			x = new_x;
			y = new_y;
		}
	}
};

class Enemy {
public:
	int x[4] = { 8, 9, 10, 9}, y[4] = {9, 9, 9, 8};
	int new_x[4] = {0 , 0, 0, 0 }, new_y[4] = {0, 0, 0, 0};
	int rotate[4] = {1, 1, 1, 1}, ti = 0;

	void update() {
		ti++;

		if (ti >= 500) {
			for (int i = 0; i < 4; i++) {
				rotate[i] = rand() % 4 + 1;

				new_x[i] = x[i];
				new_y[i] = y[i];

				switch (rotate[i])
				{
				case 1:
					if (TileMap[y[i]][new_x[i] + 1] != 'A')
						new_x[i] += 1;
					break;
				case 2:
					if (TileMap[y[i]][new_x[i] - 1] != 'A')
						new_x[i] -= 1;
					break;
				case 3:
					if (TileMap[new_y[i] - 1][x[i]] != 'A')
						new_y[i] -= 1;
					break;
				case 4:
					if (TileMap[new_y[i] + 1][x[i]] != 'A')
						new_y[i] += 1;
					break;
				}
			}

			ti = 0;
		}

		for (int i = 0; i < 4; i++) {
			if (TileMap[new_y[i]][new_x[i]] == ' ' || TileMap[new_y[i]][new_x[i]] == 'B' ||
				TileMap[new_y[i]][new_x[i]] == 'C') {
				if (TileMap[new_y[i]][new_x[i]] == 'B')
					TileMap[y[i]][x[i]] = 'B';
				else if (TileMap[new_y[i]][new_x[i]] == ' ')
					TileMap[y[i]][x[i]] = ' ';
				else if (TileMap[new_y[i]][new_x[i]] == 'C')
					life = false;

				if (i == 0)
					TileMap[new_y[i]][new_x[i]] = '1';
				if (i == 1)
					TileMap[new_y[i]][new_x[i]] = '2';
				if (i == 2)
					TileMap[new_y[i]][new_x[i]] = '3';
				if (i == 3)
					TileMap[new_y[i]][new_x[i]] = '4';

				x[i] = new_x[i];
				y[i] = new_y[i];
			}

			if (new_y[i] == 9 && (new_x[i] == 0 || new_x[i] == 18)) {
				if (new_x[i] == 0)
					new_x[i] = 17;
				else
					new_x[i] = 1;

				TileMap[y[i]][x[i]] = 'B';
				
				if (i == 0)
					TileMap[new_y[i]][new_x[i]] = '1';
				if (i == 1)
					TileMap[new_y[i]][new_x[i]] = '2';
				if (i == 2)
					TileMap[new_y[i]][new_x[i]] = '3';
				if (i == 3)
					TileMap[new_y[i]][new_x[i]] = '4';

				x[i] = new_x[i];
				y[i] = new_y[i];
			}
		}
	}
};

int main()
{
	srand(time(0));
	RenderWindow window(VideoMode(width * ts, height * ts), "PacWoman"); 
 
	Player p;
	Enemy en;
 
	Texture herotexture;
	herotexture.loadFromFile("C:\\Users\\VivoBook\\Desktop\\new.png");
	Sprite plat(herotexture);
 
	while (window.isOpen())	{	
		Event event;
		while (window.pollEvent(event)) {
			if (event.type == Event::Closed)
				window.close();

			if (counter < 171 && life)
				if (event.type == Event::KeyPressed) {
					p.new_x = p.x;
					p.new_y = p.y;

					if (event.key.code == Keyboard::Right)
						p.direction_movement = 1;
					if (event.key.code == Keyboard::Left)
						p.direction_movement = 2;
					if (event.key.code == Keyboard::Up)
						p.direction_movement = 3;
					if (event.key.code == Keyboard::Down)
						p.direction_movement = 4;
				}
		}

		if (counter < 171 && life) {
			p.update();
			en.update();
		}
        window.clear(Color::Black);

        for (int i = 0; i < height; i++) {
			for (int j = 0; j < width; j++) {
				if (TileMap[i][j] == 'A') plat.setTextureRect(IntRect(0,0,25,25));
				if (TileMap[i][j] == 'C') plat.setTextureRect(IntRect(ts * int(p.frame), ts * p.direction_movement, ts, ts));
                if (TileMap[i][j] == ' ') plat.setTextureRect(IntRect(25, 0, 50, 25));
				if (TileMap[i][j] == '1') plat.setTextureRect(IntRect(ts * 5, ts * en.rotate[0], ts, ts));
				if (TileMap[i][j] == '2') plat.setTextureRect(IntRect(ts * 6, ts * en.rotate[1], ts, ts));
				if (TileMap[i][j] == '3') plat.setTextureRect(IntRect(ts * 7, ts * en.rotate[1], ts, ts));
				if (TileMap[i][j] == '4') plat.setTextureRect(IntRect(ts * 8, ts * en.rotate[1], ts, ts));
                if (TileMap[i][j] == 'B') continue;
                plat.setPosition(j * ts, i * ts);
				window.draw(plat);
            }
        }
		window.display();
	}

	return 0;
}
