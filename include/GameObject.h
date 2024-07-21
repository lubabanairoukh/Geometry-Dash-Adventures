#pragma once
#include <SFML/Graphics.hpp>
#include "box2d/box2d.h"
#include "utils.h"
#include "Texture.h"
#include "Level.h"
static const float PPM = 64.f;
static const float MPP = 0.015625f;
class GameObject {
public:

    GameObject();
    virtual ~GameObject() {};
    virtual void draw(sf::RenderWindow& window);

    void    setBody(b2Body* body);

    b2Body* getBody();


   

protected:

    
    b2Body* m_body;
	
    int m_id;
    float m_frication;
private:
};
