#include <SFML/Graphics.hpp>

using namespace sf;

void menu(RenderWindow & window) {
	Texture menuTexture1, menuTexture2, menuTexture3, aboutTexture, menuBackground;
	menuTexture1.loadFromFile("C:\\OOP\\PacWoman\\picture\\level1.png");
	menuTexture2.loadFromFile("C:\\OOP\\PacWoman\\picture\\level2.png");
	menuTexture3.loadFromFile("C:\\OOP\\PacWoman\\picture\\description_game.png");
	aboutTexture.loadFromFile("C:\\OOP\\PacWoman\\picture\\aboutgame.png");
	menuBackground.loadFromFile("C:\\OOP\\PacWoman\\picture\\pacwoman.png");
	Sprite menu1(menuTexture1), menu2(menuTexture2), menu3(menuTexture3), about(aboutTexture), menuBg(menuBackground);
	bool isMenu = true;
	int menuNum = 0;
	menu1.setPosition(150, 50);
	menu2.setPosition(155, 100);
	menu3.setPosition(155, 160);
	menuBg.setPosition(0, 370);
 
	while (isMenu)
	{
		menu1.setColor(Color::White); //чтобы кнопка не горела красным, когда на неё не наведена мышь
		menu2.setColor(Color::White);
		menu3.setColor(Color::White);
		menuNum = 0;
		window.clear(Color(0, 0, 0));
 
		if (IntRect(150, 50, 200, 70).contains(Mouse::getPosition(window))) { menu1.setColor(Color::Magenta); menuNum = 1; }
		if (IntRect(155, 100, 200, 100).contains(Mouse::getPosition(window))) { menu2.setColor(Color::Magenta); menuNum = 2; }
		if (IntRect(155, 130, 180, 150).contains(Mouse::getPosition(window))) { menu3.setColor(Color::Magenta); menuNum = 3; }
 
		if (Mouse::isButtonPressed(Mouse::Left))
		{
			if (menuNum == 1) isMenu = false;//если нажали первую кнопку, то выходим из меню 
			if (menuNum == 2) isMenu = false;  
			//window.draw(about); window.display(); while (!Keyboard::isKeyPressed(Keyboard::Escape)); }
			//if (menuNum == 3)  { window.close(); isMenu = false; }
			if (menuNum == 3) { window.draw(about); window.display(); while (!Keyboard::isKeyPressed(Keyboard::Escape)); }
 
		}
 
 
		window.draw(menuBg);
		window.draw(menu1);
		window.draw(menu2);
		window.draw(menu3);
		
		window.display();
	}
}