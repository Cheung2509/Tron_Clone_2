#pragma once

#include <SFML\Graphics.hpp>

#include <atomic>

#include "ClientState.h"

struct ClientData
{
	std::atomic<sf::RenderWindow*> m_renderWindow;
	std::atomic<sf::Event*> m_events;

	std::atomic<ClientState> m_state = ClientState::CS_MENU;
};