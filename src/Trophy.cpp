#include "Trophy.h"

Trophy::Trophy(b2World& world, sf::Vector2f center)
{
    m_size.first = 100;
    m_size.second = 100;
    m_center = ICONSIZE / TWO;

    m_shape.setPosition(center.x, center.y - m_center);
    m_shape.setOrigin(m_size.first / TWO, m_size.second / TWO);
    m_shape.setSize(sf::Vector2f(m_size.second, m_size.first));
    m_shape.setTexture(Texture::instance().getStaticObject(TROPHY));


    // Create body Box2D
    b2PolygonShape polygonShape;
    b2FixtureDef fixtureDef;
    b2BodyDef bodyDef;

    polygonShape.SetAsBox(m_size.second / TWO * MPP, m_size.first / TWO * MPP);

    bodyDef.type = b2_staticBody;
    bodyDef.position.Set(center.x * MPP, (center.y - m_center) * MPP);
    m_body = world.CreateBody(&bodyDef);

    fixtureDef.shape = &polygonShape;
    fixtureDef.userData.pointer = (uintptr_t)this;

    m_body->CreateFixture(&fixtureDef);
}

void Trophy::draw(sf::RenderWindow& window)
{

    window.draw(m_shape);
}