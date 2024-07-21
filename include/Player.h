#pragma once
#include "GameObject.h"
#include "Texture.h"
#include "utils.h"

class Player :public GameObject {
public:

	static bool m_gameover;
	static bool m_winGame;
	static bool m_plane;
	static bool has_ground;

	Player() = default;
	Player(b2World& world, sf::Vector2f center);

	void handleMovement();
	void resetVelocity();
	void draw(sf::RenderWindow& window)override;
	sf::Vector2f getposition();
	void setPosition(sf::Vector2f position);
	int numberOfContacts;
	float walk_speed;
	float jump_force;
	bool double_jump;
	
	const int FOOT_ID = 2;
private:
	float desired_velocity;
	sf::RectangleShape m_shape;


};