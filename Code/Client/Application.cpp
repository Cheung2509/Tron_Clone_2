#include "Application.h"

#include <iostream>


Application::Application()
{
	//Initialise client data 
	m_clientData = std::make_unique<ClientData>();

	m_clientData->m_renderWindow.store(new sf::RenderWindow(sf::VideoMode(500, 500), "SFML works!"));
	m_clientData->m_renderWindow.load()->setActive(false);

	m_clientData->m_events.store(new sf::Event());

	testShape.setRadius(100.0f);
	testShape.setFillColor(sf::Color::Green);
}

Application::~Application()
{
	if (m_clientData->m_renderWindow.load())
	{
		delete m_clientData->m_renderWindow.load();
		m_clientData->m_renderWindow = nullptr;
	}

	if (m_clientData->m_events.load())
	{
		delete m_clientData->m_events.load();
		m_clientData->m_events = nullptr;
	}
}

void Application::runApplication()
{
	//Initialise rendering thread
	if (!m_renderingThread)
	{
		m_renderingThread = std::make_unique<std::thread>(&Application::render, this);
	}

	//Run game logic and events
	while (m_clientData->m_renderWindow.load()->isOpen())
	{
		while (m_clientData->m_renderWindow.load()->pollEvent(*m_clientData->m_events.load()))
		{
			if (m_clientData->m_events.load()->type == sf::Event::Closed)
			{
				m_clientData->m_renderWindow.load()->close();
			}
		}

		switch (m_clientData->m_state)
		{
		case ClientState::CS_MENU:
			break;
		case ClientState::CS_LOBBY:
			break;
		case ClientState::CS_PLAY:
			break;
		case ClientState::CS_NULL:
		default:
			break;
		}
	}

	//If thread is joinable join thread
	if (m_renderingThread->joinable())
	{
		m_renderingThread->join();
	}
}

void Application::render()
{
	//While render window is open
	while (m_clientData->m_renderWindow.load()->isOpen())
	{
		//Render objects here
		m_clientData->m_renderWindow.load()->clear();

		switch (m_clientData->m_state)
		{
		case ClientState::CS_MENU:
			break;
		case ClientState::CS_LOBBY:
			break;
		case ClientState::CS_PLAY:
			break;
		case ClientState::CS_NULL:
		default:
			break;
		}

		m_clientData->m_renderWindow.load()->display();
	}
}