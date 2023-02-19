
#pragma once
#include <SFML/Graphics.hpp>
#include "settings.h"

struct Enemy {
	sf::Texture texture;
	sf::Sprite sprite;
};
void enemy_init(Enemy& obj, std::string filename) {
	obj.texture.loadFromFile(filename);
	obj.sprite.setTexture(obj.texture);
}
void enemy1_update(Enemy & obj) {
		srand(time(0));
		int c = rand() % 5;
		obj.sprite.move(0, roadObj_speedy);
		
	}
void enemy_update(Enemy& obj) {
	srand(time(0));
	int c = rand() % 5;
	obj.sprite.move(0, roadObj_speedy);
	if (obj.sprite.getPosition().y >= window_height) {
		if (c == 1) {
			float y = -rand() % 200;
			obj.sprite.setPosition(110.f, y);
		}if (c == 2) {
			float y = -rand() % 200;
			obj.sprite.setPosition(220.f, y);
			
		}if (c == 3) {
			float y = -rand() % 200;
			obj.sprite.setPosition(305.f, y);
			
		}if (c == 4) {
			float y = -rand() % 200;
			obj.sprite.setPosition(405.f, y);
			
		}
	}
	
}
void enemy_draw(Enemy& obj, sf::RenderWindow& window) {
	window.draw(obj.sprite);
}