#pragma once

#include <SFML\Graphics.hpp>
#include <Vector>
#include <string>
#include <fstream> 
#include <iostream>
#include <cstdlib>
#include "Texture.h"
#include "GameObject.h"
#include "Define.h"




class StaticObject :public GameObject
{
public:
	StaticObject();
	
protected:
	sf::Shape* m_shapee;

};