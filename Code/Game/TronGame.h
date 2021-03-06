#pragma once
#include <SFML\System.hpp>

namespace sf {
	class Packet;
}

class TronGame
{
public:
	TronGame() = default;
	~TronGame() = default;

	friend sf::Packet& operator <<(sf::Packet& packet, const TronGame& game);
	friend sf::Packet& operator >>(sf::Packet& packet, const TronGame& game);
};