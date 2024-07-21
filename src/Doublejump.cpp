#include "Doublejump.h"

Doublejump::Doublejump(b2World& world, sf::Vector2f center)
{
    m_radius =40 / 2;

    // Create body Box2D
    b2CircleShape circleShape;
    b2BodyDef bodyDef;
    b2FixtureDef fixtureDef;

    circleShape.m_p.Set(ZERO, ZERO);
    circleShape.m_radius = m_radius * MPP;

    bodyDef.type = b2_staticBody;
    bodyDef.position.Set((center.x+(ICONSIZE/TWO)) * MPP, (center.y-25) * MPP);
    m_body = world.CreateBody(&bodyDef);

    fixtureDef.shape = &circleShape;
    fixtureDef.userData.pointer = (uintptr_t)this;
    m_body->CreateFixture(&fixtureDef);

    // Create shape SFML
    m_shape.setOrigin(40 / 2, 40 / 2);
    m_shape.setRadius(m_radius);
    m_shape.setFillColor(sf::Color(173, 255, 47));

}

void Doublejump::draw(sf::RenderWindow& window)
{
    m_shape.setPosition((m_body->GetPosition().x * PPM), m_body->GetPosition().y  * PPM);
	window.draw(m_shape);
}
