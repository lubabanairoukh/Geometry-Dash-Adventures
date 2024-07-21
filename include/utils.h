#pragma once
#include <SFML/Graphics.hpp>
#include "box2d/box2d.h"

namespace utils {
	const float WORLDSCALE = 55.0f;
	const int GROUND_ID = 0;
	b2Vec2 convertSfmlVecToB2vec(sf::Vector2f vec);
	sf::Vector2f convertB2vecToSfml(b2Vec2 vec);
}