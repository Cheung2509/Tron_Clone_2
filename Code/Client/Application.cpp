#include "Application.h"

Application::Application()
{
	m_renderWindow = std::make_unique<sf::RenderWindow>(sf::VideoMode(200, 200), "SFML works!");
	m_events = std::make_unique<sf::Event>();

	shape.setRadius(100.0f);
	shape.setFillColor(sf::Color::Green);
}

Application::~Application()
{
}

void Application::runApplication()
{
	while (m_renderWindow->isOpen())
	{
		while (m_renderWindow->pollEvent(*m_events.get()))
		{
			if (m_events->type == sf::Event::Closed)
				m_renderWindow->close();
		}

		render();
	}
}

void Application::render()
{
	m_renderWindow->clear();
	m_renderWindow->draw(shape);
	m_renderWindow->display();
}				  
