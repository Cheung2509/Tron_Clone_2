#pragma once

#include <memory>
#include <thread>
#include <atomic>

#include <SFML\Graphics.hpp>

#include "ClientState.h"

class Application
{
public:
	Application();
	~Application();

	void runApplication();


private:
	void render();

private:
	std::atomic<sf::RenderWindow*> m_renderWindow =  nullptr;
	std::unique_ptr<sf::Event> m_events = nullptr;

	ClientState state = ClientState::CS_MENU;

	std::unique_ptr<std::thread> m_renderingThread = nullptr;

	sf::CircleShape shape;
};