#include "Triangle.h"

Triangle::Triangle(b2World& world, sf::Vector2f center, Staticobject_t symbol)
{
  
    m_shape.setPointCount(3);
    switch (symbol) {
    case TRIANGLE:
        initTriangle();
        break;
    case MINTRIANGKE:
        initMINTriangle();

        break;
    case BACKTRIANGLE:
        initBackTraingle();
        break;
    }
   

    m_shape.setPosition(center.x + m_size / TWO, center.y);
    m_shape.setTexture(Texture::instance().getStaticObject(symbol));
    m_shape.setOrigin(m_size / TWO, m_size);

    


    // Create body Box2D
    b2PolygonShape polygonShape;
    b2FixtureDef fixtureDef;
    b2BodyDef bodyDef;

    b2Vec2 vertex[3];

    float size_t = (m_size / TWO) * MPP;


    if (symbol == BACKTRIANGLE) {
        vertex[ZERO].Set(ZERO, size_t);
        vertex[1].Set(size_t, -size_t);
        vertex[TWO].Set(-size_t, -size_t);
        bodyDef.position.Set((center.x + (ICONSIZE/TWO)) * MPP, (center.y + (ICONSIZE / TWO)) * MPP);
    }
    else
    {
        vertex[ZERO].Set(ZERO, -size_t);
        vertex[1].Set(-size_t, size_t);
        vertex[TWO].Set(size_t, size_t);
        bodyDef.position.Set((center.x + m_size / TWO) * MPP, (center.y - m_size / TWO) * MPP);
    }


    polygonShape.Set(vertex, 3);
    bodyDef.type = b2_staticBody;
    m_body = world.CreateBody(&bodyDef);

    fixtureDef.shape = &polygonShape;
    fixtureDef.userData.pointer = (uintptr_t)this;

    m_body->CreateFixture(&fixtureDef);
}


void Triangle::initTriangle()
{
    m_size = 60;
    m_shape.setPoint(0, sf::Vector2f((m_size / TWO), ZERO));
    m_shape.setPoint(1, sf::Vector2f(ZERO, m_size));
    m_shape.setPoint(2, sf::Vector2f(m_size, m_size));
}

void Triangle::initMINTriangle()
{
    m_size = 45;
    m_shape.setPoint(0, sf::Vector2f((m_size / TWO), ZERO));
    m_shape.setPoint(1, sf::Vector2f(ZERO - 10, m_size));
    m_shape.setPoint(2, sf::Vector2f(m_size + 10, m_size));
}

void Triangle::initBackTraingle()
{
    m_size = 60;
    m_shape.setPoint(0, sf::Vector2f(30, (m_size * TWO)));
    m_shape.setPoint(1, sf::Vector2f(ZERO, m_size));
    m_shape.setPoint(2, sf::Vector2f(m_size, m_size));
}
void Triangle::draw(sf::RenderWindow& window)
{

    window.draw(m_shape);
}