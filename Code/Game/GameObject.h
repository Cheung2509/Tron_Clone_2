#pragma once

#include <SFML\System.hpp>

class GameData;

class GameObject
{
public:
	GameObject();
	virtual ~GameObject();

	virtual void tick(GameData* data);
private:
	sf::Vector2f position;

};