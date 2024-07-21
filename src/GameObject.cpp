#include "GameObject.h"

GameObject::GameObject()
{


	

}

void GameObject::draw(sf::RenderWindow& window)
{
}

void GameObject::setBody(b2Body* body)
{
	m_body = body;
}

b2Body* GameObject::getBody()
{
	return m_body;
}

