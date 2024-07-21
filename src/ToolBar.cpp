#pragma once

#include "Toolbar.h"
#include "Texture.h"
#include "Define.h"


Toolbar::Toolbar()
{



}

Toolbar::~Toolbar()
{
}

void Toolbar::load()
{


}

void Toolbar::updateLevel()
{
	
}

void Toolbar::updateplayer()
{

	

}

void Toolbar::draw(sf::RenderWindow& window)
{


}

void Toolbar::resetLevelNum()
{
	
}

void Toolbar::update()
{
	
}

int Toolbar::GetCountDown()
{
	
}

void Toolbar::setCountDown(int timer)
{
}

Toolbar& Toolbar::instance()
{
	/*
	*
	* make an static object of class and return it
	*
	*/

	static Toolbar toolbar;
	return toolbar;
}

