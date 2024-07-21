#include "Thorns.h"

Thorns::Thorns(b2World& world, sf::Vector2f center)
{
    // Create body Box2D
    b2PolygonShape polygonShape;
    b2FixtureDef fixtureDef;
    b2BodyDef bodyDef;

  

    m_shape.setPosition(center.x + ICONSIZE, center.y - (ICONSIZE / TWO));
    m_shape.setOrigin(ICONSIZE, (ICONSIZE / TWO));
    m_shape.setSize(sf::Vector2f(ICONSIZE * TWO, ICONSIZE));
    m_shape.setTexture(Texture::instance().getStaticObject(THORNS));

    






    polygonShape.SetAsBox(ICONSIZE * MPP, 25 * MPP);
    bodyDef.type = b2_staticBody;
    bodyDef.position.Set((center.x + ICONSIZE) * MPP, (center.y - (ICONSIZE / TWO)) * MPP);
    m_body = world.CreateBody(&bodyDef);

    fixtureDef.shape = &polygonShape;
    fixtureDef.userData.pointer = (uintptr_t)this;

    m_body->CreateFixture(&fixtureDef);



}



void Thorns::draw(sf::RenderWindow& window)
{

    window.draw(m_shape);
}
