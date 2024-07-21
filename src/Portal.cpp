#include "Portal.h"

Portal::Portal(b2World& world, sf::Vector2f center)
{
   
    m_shape.setPosition(center.x + (ICONSIZE/TWO), center.y - (ICONSIZE / TWO));
    m_shape.setOrigin(55 / 2, 110 / 2);
    m_shape.setSize(sf::Vector2f(ICONSIZE, ICONSIZE*TWO));
    m_shape.setTexture(Texture::instance().getStaticObject(PORTAL));
    m_shapee = &m_shape;


    // Create body Box2D
    b2PolygonShape polygonShape;
    b2FixtureDef fixtureDef;
    b2BodyDef bodyDef;

    polygonShape.SetAsBox((ICONSIZE / TWO) * MPP, 25 * MPP);
    bodyDef.type = b2_staticBody;
    bodyDef.position.Set((center.x + (ICONSIZE / TWO)) * MPP, (center.y - (ICONSIZE / TWO)) * MPP);
    m_body = world.CreateBody(&bodyDef);

    fixtureDef.shape = &polygonShape;
    fixtureDef.userData.pointer = (uintptr_t)this;

    m_body->CreateFixture(&fixtureDef);

}


void Portal::draw(sf::RenderWindow& window)
{

    window.draw(m_shape);
}
