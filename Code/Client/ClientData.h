#pragma once

#include <SFML\Graphics.hpp>

#include <atomic>

#include "ClientState.h"

struct ClientData
{
	std::atomic<sf::RenderWindow*> m_renderWindow;
	std::atomic<sf::Event*> m_events;

	std::atomic<ClientState> m_state = ClientState::CS_MENU;

	sf::Time m_deltaTime;

	//Destructor to fee memory
	~ClientData()
	{
		if (m_renderWindow.load())
		{
			delete m_renderWindow.load();
		}

		if (m_events.load())
		{
			delete m_events.load();
		}
	}
};