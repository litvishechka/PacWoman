#include <SFML/Graphics.hpp>
#include <time.h>
#include <sstream>
#include "menu.cpp"
#include "map.h"
#include "player.cpp"
#include "enemy.cpp"
 
using namespace sf;

int main() {
	srand(time(0));
	RenderWindow window(VideoMode(width * ts, height * ts + 40), "PacWoman"); 
	menu(window);

	Font font;//шрифт 
 	font.loadFromFile("C:\\OOP\\PacWoman\\font\\score.ttf");//передаем нашему шрифту файл шрифта
 	Text text("", font, 40);//создаем объект текст. закидываем в объект текст строку, шрифт, размер шрифта(в пикселях);//сам объект текст (не строка)
	text.setStyle(sf::Text::Bold);
 
	Player p;
	Enemy en;

	Texture yw;
	yw.loadFromFile("C:\\OOP\\PacWoman\\picture\\win.png");
	Sprite youwin(yw);
	youwin.setPosition(-50, 100);

	Texture yl;
	yl.loadFromFile("C:\\OOP\\PacWoman\\picture\\lose.png");
	Sprite youlose(yl);
	youlose.setPosition(-50, 100);
 
	Texture herotexture;
	herotexture.loadFromFile("C:\\OOP\\PacWoman\\picture\\element.png");
	Sprite plat(herotexture);

	clearing_card();
 
	while (window.isOpen())	{	
		Event event;
		while (window.pollEvent(event)) {
			if (event.type == Event::Closed) window.close();

			if (counter < 175 && life) {
				if (event.type == Event::KeyPressed) {
					p.new_x = p.x;
					p.new_y = p.y;

					if (event.key.code == Keyboard::Right) p.direction_movement = 1;
					if (event.key.code == Keyboard::Left) p.direction_movement = 2;
					if (event.key.code == Keyboard::Up) p.direction_movement = 3;
					if (event.key.code == Keyboard::Down) p.direction_movement = 4;
				}
			}
		}

		if ((counter == 175 || !life) && restartTime != 0) {
			restartTime--;
				if (restartTime == 0) {
					for (int i = 0; i < height; i++)
						for (int j = 0; j < width; j++)
							if (TileMap[i][j] == 'B')
								TileMap[i][j] = ' ';

					p.player_restart = true;
					en.restart_enemy = true;

					clearing_card();

					counter = 0;
					p.score = 0;
					life = true;
					p.direction_movement = 4;
					
					restartTime = 5000;
					menu(window);
				}
		}
		
		if (!life) {
			if (restartTime == 100) 
				for (int i = 0; i < height; i++)
					for (int j = 0; j < width; j++)
						if (TileMap[i][j] != 'A')
							TileMap[i][j] = 'B';	
		}

		if (counter < 175 && life) {
			p.update();
			en.update();
		}
        window.clear(Color::Black);

        for (int i = 0; i < height; i++) {
			for (int j = 0; j < width; j++) {
				if (TileMap[i][j] == 'A') plat.setTextureRect(IntRect(0, 0, ts, ts));
				if (TileMap[i][j] == 'C') plat.setTextureRect(IntRect(ts * int(p.frame), ts * p.direction_movement, ts, ts));
                if (TileMap[i][j] == ' ') plat.setTextureRect(IntRect(ts, 0, 2 * ts, ts));
				if (TileMap[i][j] == '1') plat.setTextureRect(IntRect(ts * 5, ts * en.direction_movement[0], ts, ts));
				if (TileMap[i][j] == '2') plat.setTextureRect(IntRect(ts * 6, ts * en.direction_movement[1], ts, ts));
				if (TileMap[i][j] == '3') plat.setTextureRect(IntRect(ts * 7, ts * en.direction_movement[2], ts, ts));
				if (TileMap[i][j] == '4') plat.setTextureRect(IntRect(ts * 8, ts * en.direction_movement[3], ts, ts));
                if (TileMap[i][j] == 'B') continue;

                plat.setPosition(j * ts, i * ts);
				window.draw(plat);
            }
			std::ostringstream playerScoreString;    // объявили переменную
			playerScoreString << p.score;		//занесли в нее число очков, то есть формируем строку
			text.setString("Score: " + playerScoreString.str());//задаем строку тексту и вызываем сформированную выше строку методом .str() 
			text.setPosition(0, 515);//задаем позицию текста
			window.draw(text);//рисую этот текст
        }
		if (counter == 175) window.draw(youwin);
		if (!life) {
			window.draw(youlose);
		}
		window.display();
	}
	return 0;
}
