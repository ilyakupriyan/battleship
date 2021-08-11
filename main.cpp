#include <SFML/Graphics.hpp>
#include "menu.h"

using namespace sf;

int main()
{
	// ������, ������� �������� ������� ����� ����������
	RenderWindow window(VideoMode(900, 600), "Battleship");

	//��� ������ � ����� ����
	bool open_menu = false;
	std::string res_menu; //������ ���������� ��� �������� ����

	// ������� ���� ����������. �����������, ���� ������� ����
	while (window.isOpen())
	{
		// ������������ ������� ������� � �����
		Event event;
		while (window.pollEvent(event))
		{
			//�������� ���� �� ������� �� �������
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

		// ��������� ����	
		window.display();
	}

	return 0;
}