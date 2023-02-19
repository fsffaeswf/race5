#pragma once
#include "settings.h"

struct Explosion {
	static const int size = 9;
	sf::Texture texture_arr[size];
	sf::Sprite sprite_arr[size];
	sf::Clock clock;
	float time;
	int frame;
	sf::Vector2f pos;
};

void exp_init(Explosion& exp,sf::Vector2f position) {
	for (int i = 0; i < Explosion::size; i++) {
		std::string file_name = exp_file_name_temp + std::to_string(i) + ".png";
		exp.texture_arr[i].loadFromFile(file_name);
		exp.sprite_arr[i].setTexture(exp.texture_arr[i]);
	}
	exp.clock.restart();
	exp.frame = 0;
	exp.pos = position;
}

void exp_update(Explosion& exp){}
 
void exp_draw(Explosion& exp, sf::RenderWindow& window) {
	exp.time = exp.clock.getElapsedTime().asMilliseconds();
	if (exp.time > 100) {
		
		exp.frame++;
		if (exp.frame > 8)exp.frame = 0;
		exp.clock.restart();
	}
	sf::FloatRect bounds = exp.sprite_arr[exp.frame].getGlobalBounds();
	exp.sprite_arr[exp.frame].setPosition(
		exp.pos.x - bounds.width/2,
		exp.pos.y - bounds.height / 2);
	window.draw(exp.sprite_arr[exp.frame]);
}