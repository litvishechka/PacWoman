#include <SFML/Graphics.hpp>

using namespace sf;

void menu(RenderWindow & window) {

	Texture menuTexture, menuTexture1, menuTexture2, menuTexture3, aboutTexture, menuBackground, decorationTexture;
	menuTexture.loadFromFile("C:\\OOP\\PacWoman\\picture\\menu.png"); 
	menuTexture1.loadFromFile("C:\\OOP\\PacWoman\\picture\\play.png");
	menuTexture2.loadFromFile("C:\\OOP\\PacWoman\\picture\\description_game.png");
	menuTexture3.loadFromFile("C:\\OOP\\PacWoman\\picture\\exit.png");
	aboutTexture.loadFromFile("C:\\OOP\\PacWoman\\picture\\aboutgame.png");
	menuBackground.loadFromFile("C:\\OOP\\PacWoman\\picture\\pacwoman.png");
	decorationTexture.loadFromFile("C:\\OOP\\PacWoman\\picture\\decoration.png");

	Sprite menuText(menuTexture), menu1(menuTexture1), menu2(menuTexture2), menu3(menuTexture3), about(aboutTexture), menuBg(menuBackground);
	Sprite decor(decorationTexture);

	bool isMenu = true;
	int menuNum = 0;

	menuText.setPosition(75, 10);
	menu1.setPosition(160, 120);
	menu2.setPosition(145, 190);
	menu3.setPosition(164, 260);
	menuBg.setPosition(0, 370);
	decor.setPosition(0, 0);
 
	while (isMenu)
	{
		menu1.setColor(Color::White); //чтобы кнопка не горела красным, когда на неё не наведена мышь
		menu2.setColor(Color::White);
		menu3.setColor(Color::White);
		menuNum = 0;
		window.clear(Color(0, 0, 0));
 
		if (IntRect(160, 120, 155, 57).contains(Mouse::getPosition(window))) { 
			menu1.setColor(Color::Magenta); 
			menuNum = 1; 
		}
		if (IntRect(145, 190, 185, 46).contains(Mouse::getPosition(window))) { 
			menu2.setColor(Color::Magenta); 
			menuNum = 2; 
		}
		if (IntRect(150, 260, 150, 34).contains(Mouse::getPosition(window))) { 
			menu3.setColor(Color::Magenta); 
			menuNum = 3; 
		}
 
		if (Mouse::isButtonPressed(Mouse::Left))
		{
			if (menuNum == 1) isMenu = false; //если нажали первую кнопку, то выходим из меню 
			if (menuNum == 2) { 
				window.draw(about); 
				window.display(); 
				while (!Keyboard::isKeyPressed(Keyboard::Escape)); 
			}
			if (menuNum == 3)  { 
				window.close();  
				isMenu = false; 
			}
 
		}
 
		window.draw(decor);
		window.draw(menuText);
		window.draw(menuBg);
		window.draw(menu1);
		window.draw(menu2);
		window.draw(menu3);
		window.display();
	}
}