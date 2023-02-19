#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <ctime>




const float fps = 60.f;

const float window_height = 1000;
const float window_width = 900;

const sf::Vector2f grass_start_pos(0.f, 0.f);

const std::string grass_file_name("grass.png");
const sf::Vector2f road_start_pos(100.f, 0.f);
const sf::Vector2f grass1_start_pos(0.f, -window_height);
const sf::Vector2f road1_start_pos(100.f, -window_height);



const std::string road_file_name("road.png");
const std::string car_file_name("car.png");
const std::string enemy_file_name("hhh.png");
const std::string exp_file_name_temp("regularExplosion0");
float roadObj_speedy = 5.f;

const sf::Vector2f car_start_pos(window_width/2-200.f/2,window_height-250.f);
const float car_speed = 7.f;
