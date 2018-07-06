#include "Application.h"

Application::Application()
{
	m_renderWindow = new sf::RenderWindow(sf::VideoMode(500, 500), "SFML works!");
	m_renderWindow.load()->setActive(false);

	m_events = std::make_unique<sf::Event>();

	shape.setRadius(100.0f);
	shape.setFillColor(sf::Color::Green);
}

Application::~Application()
{
	delete m_renderWindow.load();
}

void Application::runApplication()
{
	if (!m_renderingThread)
	{
		m_renderingThread = std::make_unique<std::thread>(&Application::render, this);
		m_renderingThread->detach();
	}

	while (m_renderWindow.load()->isOpen())
	{
		while (m_renderWindow.load()->pollEvent(*m_events.get()))
		{
			if (m_events->type == sf::Event::Closed)
			{
				m_renderWindow.load()->close();
			}
		}
	}
}

void Application::render()
{
	while (m_renderWindow.load()->isOpen())
	{
		m_renderWindow.load()->clear();
		m_renderWindow.load()->draw(shape);
		m_renderWindow.load()->display();
	}
}