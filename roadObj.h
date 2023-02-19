#pragma once
#include <SFML/Graphics.hpp>
#include "settings.h"

struct RoadObj {
	sf::Texture texture;
	sf::Sprite sprite;
	float offset;
};
void roadObj_init(RoadObj& obj, sf::Vector2f pos,std::string filename, float offset) {
	obj.texture.loadFromFile(filename);
	obj.sprite.setTexture(obj.texture);
	obj.sprite.setPosition(pos);
	obj.offset = offset;
}
void roadObj_update(RoadObj& obj) {
	/*if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))*/
		obj.sprite.move(0, roadObj_speedy);
	
	if (obj.sprite.getPosition().y >= window_height) {
		obj.sprite.setPosition(obj.offset, -window_height+2.f);
	}
	
}
void roadObj_draw(RoadObj& obj, sf::RenderWindow& window) {
	window.draw(obj.sprite);
}