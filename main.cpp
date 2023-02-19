#include <SFML/Graphics.hpp>
#include <iostream>
#include "settings.h"
#include "roadObj.h"
#include "player.h"
#include "enemy.h"
#include "explosion.h"
using namespace sf;


int main()
{
	RenderWindow window(VideoMode(window_width, window_height),
		".",
		Style::Close|Style::Titlebar
	);
	window.setPosition(Vector2i{(1920-(int)window_width)/2,0});
	window.setFramerateLimit(fps);

	RoadObj grass;
	RoadObj road;
	RoadObj grass1;
	RoadObj road1;
	Player car;
	Enemy barier;
	Explosion exp;
	roadObj_init(grass, grass_start_pos, grass_file_name, 0.f);
	roadObj_init(road, road_start_pos, road_file_name, 100.f);
	roadObj_init(grass1, grass1_start_pos, grass_file_name,0.f);
	roadObj_init(road1, road1_start_pos, road_file_name,100.f);
	player_init(car, car_start_pos, car_file_name);
	enemy_init(barier, enemy_file_name);
	exp_init(exp, sf::Vector2f(400.f, 400.f));
	while (window.isOpen())
	{

		Event event;
		while (window.pollEvent(event))
		{

			if (event.type == Event::Closed) {

				window.close();
			}
		}
		roadObj_update(road);
		roadObj_update(grass);
		roadObj_update(road1);
		roadObj_update(grass1);
		player_update(car,road);
		enemy_update(barier);
		if (car.sprite.getGlobalBounds().intersects(barier.sprite.getGlobalBounds()))break;

		window.clear();
		roadObj_draw(grass, window);
		roadObj_draw(road, window);
		roadObj_draw(grass1, window);
		roadObj_draw(road1, window);
		player_draw(car, window);
		enemy_draw(barier, window);
		exp_draw(exp, window);
		window.display();
	}
	return 0;
}
