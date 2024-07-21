#include "Rectangle.h"

Rectangle::Rectangle(b2World& world, sf::Vector2f center, Staticobject_t symbol)
{
    initAllTriangles(symbol);
    b2PolygonShape polygonShape;
    b2FixtureDef fixtureDef;
    b2BodyDef bodyDef;

  

   
    m_shape.setPosition(center.x + m_center, center.y - m_center);
    m_shape.setOrigin(m_size.second / TWO, m_size.first / TWO);
    m_shape.setSize(sf::Vector2f(m_size.second, m_size.first));
    m_shape.setTexture(Texture::instance().getStaticObject(symbol));

    m_shapee = &m_shape;

   
    polygonShape.SetAsBox(m_size.second / TWO * MPP, m_size.first / TWO * MPP);

    bodyDef.type = b2_staticBody;
    bodyDef.position.Set((center.x + m_center) * MPP, (center.y - m_center) * MPP);
    m_body = world.CreateBody(&bodyDef);

    fixtureDef.shape = &polygonShape;
    fixtureDef.userData.pointer = (uintptr_t)this;
    m_body->CreateFixture(&fixtureDef);



}


void Rectangle::initRectangle()
{
    m_size.first = ICONSIZE;
    m_size.second = ICONSIZE;
    m_center = ICONSIZE / TWO;

}

void Rectangle::initFloorState()
{

    m_size.first = ICONSIZE;
    m_size.second = 540;
    m_center = ICONSIZE / TWO;
}

void Rectangle::initBigFloorState()
{

    m_size.first = ICONSIZE *TWO;
    m_size.second = 600;
    m_center = ICONSIZE;
}

void Rectangle::initSmallRectangle()
{

    m_size.first = ICONSIZE;
    m_size.second = ICONSIZE;
    m_center = ICONSIZE/TWO;
}

void Rectangle::initStairs()
{
    m_size.first = ICONSIZE / TWO;
    m_size.second = ICONSIZE;
    m_center = ICONSIZE / 4;
}

void Rectangle::initTriangleStairs()
{

    m_size.first = 90;
    m_size.second = ICONSIZE;
    m_center = 45;
}

void Rectangle::initAllTriangles(Staticobject_t symbol)
{
    switch (symbol)
    {
    case RECTANGLE:
        initRectangle();
        break;

    case FLOORSTATE:
        initFloorState();
        break;

    case BIGFLOORSTATE:
        initBigFloorState();
        break;

    case SMALLRECTANGLE:
        initSmallRectangle();
        break;

    case STAIRS:
        initStairs();
        break;

    case TRIANGLESTAIRS:
        initTriangleStairs();
        break;

    default:
        break;
    }
}

void Rectangle::draw(sf::RenderWindow& window)
{

    window.draw(m_shape);
}
