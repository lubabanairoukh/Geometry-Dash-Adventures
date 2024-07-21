#include "OnCollision.h"

OnCollision::OnCollision()

{
}

void OnCollision::BeginContact(b2Contact* contact)
{
	auto data = (GameObject*)contact->GetFixtureA()->GetUserData().pointer;
	auto data1 = (GameObject*)contact->GetFixtureB()->GetUserData().pointer;

	if (data && data1)
	{
		processCollision(*data, *data1);
	}

}

void OnCollision::EndContact(b2Contact* contact)
{
	auto data = (GameObject*)contact->GetFixtureA()->GetUserData().pointer;
	auto data1 = (GameObject*)contact->GetFixtureB()->GetUserData().pointer;

	if (data && data1)
	{
		if ((typeid(data) == typeid(Player)) && (typeid(data1) == typeid(Floor)))
		{
			dynamic_cast<Player*>(data)->has_ground = false;
			std::cout << " bybybyby" << std::endl;
		}
		else
		{
			if (typeid(data) == typeid(Floor) && typeid(data1) == typeid(Player))
			{
				dynamic_cast<Player*>(data1)->has_ground = false;
				std::cout << " bybyby" << std::endl;
			}
		}
	}
}
