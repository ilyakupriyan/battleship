#include <SFML/Graphics.hpp>
#include "menu.h"

using namespace sf;

int main()
{
	// Объект, который является главным окном приложения
	RenderWindow window(VideoMode(900, 600), "Battleship");

	//для работы с окном меню
	bool open_menu = false;
	std::string res_menu; //строка результата при закрытии меню

	// Главный цикл приложения. Выполняется, пока открыто окно
	while (window.isOpen())
	{
		// Обрабатываем очередь событий в цикле
		Event event;
		while (window.pollEvent(event))
		{
			//Закрытие окна по нажатию на крестик
			if (event.type == Event::Closed)
				window.close();
			if (event.type == Event::KeyPressed) {
				if (event.key.code == Keyboard::Escape)
					open_menu = true;
			}

		}

		if (open_menu) {
			open_menu = false;
			res_menu = menu(window);
		}

		window.clear(Color::White);

		// Отрисовка окна	
		window.display();
	}

	return 0;
}