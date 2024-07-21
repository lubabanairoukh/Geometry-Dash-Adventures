#include "Floor.h"

Floor::Floor(b2World& world, sf::Vector2f center)
{


    b2PolygonShape polygonShape;
    b2FixtureDef fixtureDef;
    b2BodyDef bodyDef;

    bodyDef.type = b2_staticBody;
    bodyDef.position.Set((center.x + FLOORBODYPOSITIONX) * MPP, (center.y + FLOORBODYPOSITIONY) * MPP);

    polygonShape.SetAsBox(WIDTHWINDOW / TWO * MPP, 140 / TWO * MPP);
  
    fixtureDef.shape = &polygonShape;
    fixtureDef.userData.pointer = (uintptr_t)this;

    m_body = world.CreateBody(&bodyDef);
    m_body->CreateFixture(&fixtureDef);
   

    m_shape.setTexture(*Texture::instance().getStaticObject(FLOOR));
    m_shape.setScale(WIDTHWINDOW / m_shape.getGlobalBounds().width, 140 / m_shape.getGlobalBounds().height);
    m_shape.setPosition(center);


}

void Floor::draw(sf::RenderWindow& window)
{

    window.draw(m_shape);
}
