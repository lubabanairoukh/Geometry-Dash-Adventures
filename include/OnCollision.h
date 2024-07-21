#pragma once
#include "box2d/box2d.h"
#include "GameObject.h"
#include "Player.h"
#include <iostream>
#include "CollisionHandling.h"

class OnCollision :public b2ContactListener
{
public:
	OnCollision();
	void BeginContact(b2Contact* contact)override;
	void EndContact(b2Contact* contact)override;
private:

};