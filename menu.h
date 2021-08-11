#ifndef MENU_H
#define MENU_H

#include <SFML/Graphics.hpp>

//строки названий позиций в меню
namespace Menu {
	const std::string New_game = "New game";
	const std::string Continue = "Continue";
	const std::string Exit = "Exit";
}

std::string menu(sf::RenderWindow& window);

#endif
