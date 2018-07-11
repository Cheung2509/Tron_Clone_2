#pragma once

#include <memory>
#include <thread>
#include <atomic>

#include <SFML\Graphics.hpp>

#include "ClientData.h"

class Application
{
public:
	Application();
	~Application();

	void runApplication();

private:
	//Function to render scene
	void render();

private:
	//Client state
	std::unique_ptr<ClientData> m_clientData;

	//Threads
	std::unique_ptr<std::thread> m_renderingThread = nullptr;
	std::unique_ptr<std::thread> m_networkThread = nullptr;

	sf::CircleShape testShape;
};