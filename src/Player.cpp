#include "Player.h"
#include <Windows.h>
#include <iostream>
bool Player::m_gameover = false;
bool Player::m_winGame = false;
bool Player::m_plane = false;
bool Player::has_ground = false;
Player::Player(b2World& world, sf::Vector2f center)
{

	jump_force = 14.7f;
	walk_speed = 9.0f;
	numberOfContacts = 0;

	double_jump = false;



	b2BodyDef body_def;
	body_def.type = b2_dynamicBody;
	body_def.position.Set((center.x + 40) * MPP, (center.y + 40) * MPP);
	m_body = world.CreateBody(&body_def);
	m_body->SetGravityScale(7.0f);
	

	m_shape.setSize(sf::Vector2f(ICONSIZE, ICONSIZE));
	m_shape.setPosition(center);
	 m_shape.setOrigin(ICONSIZE / TWO, ICONSIZE / TWO);

	m_shape.setTexture(Texture::instance().getPlayerObject());







	b2PolygonShape polygonShape;

	polygonShape.SetAsBox(30*MPP,30*MPP);

	//fixture definition
	b2FixtureDef myFixtureDef;
	myFixtureDef.shape = &polygonShape;
	myFixtureDef.density = 1;
	myFixtureDef.friction = 0;
	//myFixtureDef.isSensor = true;
	myFixtureDef.userData.pointer = (uintptr_t)this;
	m_body->CreateFixture(&myFixtureDef);

	m_body->SetFixedRotation(true);

	

}


void Player::handleMovement()
{
	

	desired_velocity = walk_speed;
	
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && has_ground)
	{
		if (m_plane) {
			has_ground = true;
			jump_force = 1.0f;
			walk_speed = 10.0f;
		}
		else {
			has_ground = false;
			jump_force = 14.7f;
			walk_speed = 9.0f;
		}
		auto mass = m_body->GetMass();
		auto force = b2Vec2(0.0f, -jump_force);
		force *= mass;
		
		m_body->ApplyLinearImpulse(force, m_body->GetWorldCenter(), true);
		

	}
	if (double_jump)
	{
		
		jump_force = 19.0f;
		auto mass = m_body->GetMass();
		auto force = b2Vec2(0.0f, -jump_force);
		force *= mass;
		m_body->ApplyLinearImpulse(force, m_body->GetWorldCenter(), true);
		double_jump = false;
		jump_force = 14.7f;
	}

	auto current_velocity = m_body->GetLinearVelocity();
	

	auto delta_velocity = desired_velocity - current_velocity.x;
	auto impluse = m_body->GetMass() * delta_velocity;
	m_body->ApplyLinearImpulse(b2Vec2(impluse, 0.0f), m_body->GetWorldCenter(), true);
}

void Player::resetVelocity()
{
	desired_velocity = 0.0f;
}

void Player::draw(sf::RenderWindow& window)
{
	
	float angle = m_body->GetAngle();
	b2Vec2 position = m_body->GetPosition();
	m_shape.setPosition(position.x * PPM, position.y * PPM);
	window.draw(m_shape);
}

sf::Vector2f Player::getposition()
{
	return m_shape.getPosition();
}
void Player::setPosition(sf::Vector2f position)
{
	m_body->SetTransform(utils::convertSfmlVecToB2vec(position), m_body->GetAngle());
}