#include <SFML/Graphics.hpp>
 
using namespace sf;
const int H = 21;
const int W = 19;

const int ts = 25;

String TileMap[H] = {
"AAAAAAAAAAAAAAAAAAA",
"A        A        A",
"A AA AAA A AAA AA A",
"A        A        A",
"A AA A AAAAA A AA A",
"A    A   A   A    A",
"AAAA AAA A AAA AAAA",
"BBBA A       A ABBB",
"AAAA A AAAAA A AAAA",
"BBBB   ABBBA   BBBB",
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

int main()
{
	RenderWindow window(VideoMode(W * ts, H * ts), "PacWoman"); 
 
	
 
	Texture herotexture;
	herotexture.loadFromFile("C:\\Users\\VivoBook\\Desktop\\tt.png");
 
	Sprite herosprite;
	herosprite.setTexture(herotexture);
	herosprite.setTextureRect(IntRect(20,20,45,45));//получили нужный нам прямоугольник с котом
    int ts = 25;
	while (window.isOpen())	
	{
		sf::Event event;
		while (window.pollEvent(event))
		{   
			if (event.type == sf::Event::Closed)
				window.close();
		}

        window.clear(Color::Black);

        for (int i = 0; i < H; i++) {
			for (int j = 0; j < W; j++) {
				if (TileMap[i][j] == 'A') herosprite.setTextureRect(IntRect(20, 20, 45, 45));
                if (TileMap[i][j] == ' ') herosprite.setTextureRect(IntRect(45, 25, 70, 50));
                if (TileMap[i][j] == 'B') continue;
                herosprite.setPosition(j * ts, i * ts);
				window.draw(herosprite);
            }
        }
		window.display();
	}

 
	return 0;
}
