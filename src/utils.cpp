#include "utils.h"

b2Vec2 utils::convertSfmlVecToB2vec(sf::Vector2f vec)
{
	auto p =b2Vec2(vec.x / WORLDSCALE, vec.y / WORLDSCALE);
	return p;
}
sf::Vector2f utils::convertB2vecToSfml(b2Vec2 vec)
{
	auto p=sf::Vector2f(vec.x * WORLDSCALE, vec.y * WORLDSCALE);
	return p;
}