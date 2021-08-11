#include <SFML/Graphics.hpp>
#include <iostream>
#include "menu.h"

using namespace sf;

std::string menu (sf::RenderWindow& window) {
	bool isMenu = true; //переменная для отслеживания истинности условия отображения меню
	const int font_size = 40; //размер шрифта

	//обьекты для отображения ссылок меню
	Font font;
	font.loadFromFile("fonts\\Pixel_Times.ttf");
	Text pos_menu("", font, font_size);
	pos_menu.setFillColor(Color::Black);
	pos_menu.setStyle(sf::Text::Bold);

	//горизонтальная линия при наведении на ссылку
	RectangleShape underlined;
	underlined.setFillColor(Color::Black);

	//для отображения по центру по оси x
	Vector2f centerPos = Vector2f(window.getSize().x / 2, window.getSize().y / 2);
	int pos_height; //высота вкладок меню
	std::string links[3] = { Menu::Continue, Menu::New_game, Menu::Exit };

	while (isMenu) {

		window.clear(Color::White);
		pos_height = 120;

		//отображение ссылок меню
		for (int link = 0; link < 3; link++, pos_height += 80) {
			//установление ссылки в окне игры
			pos_menu.setString(links[link]); 
			pos_menu.setPosition(centerPos.x - pos_menu.getGlobalBounds().width / 2, pos_height);
			window.draw(pos_menu);

			//прямоугольник отображаемой ссылки
			if (IntRect(centerPos.x - pos_menu.getGlobalBounds().width / 2, pos_height, pos_menu.getGlobalBounds().width, font_size).contains(Mouse::getPosition(window))) {
				//настройка и вывод подстрочной линии при наведении мыши на ссылку
				underlined.setSize(Vector2f(pos_menu.getGlobalBounds().width, 3));
				underlined.setPosition(centerPos.x - pos_menu.getGlobalBounds().width / 2, pos_height + font_size + 3);
				window.draw(underlined);

				if (Mouse::isButtonPressed(Mouse::Left)) {
					isMenu = false;
					return links[link];
				}
			}
		}

		//отслеживание нажатия на крестик
		Event event;
		while (window.pollEvent(event)) {
			if (event.type == Event::Closed) {
				window.close();
				return Menu::Exit;
			}
		}

		window.display();	
	}
}