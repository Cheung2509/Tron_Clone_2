#pragma once

#include <vector>
#include <memory>

#include "ClientData.h"

class BaseState
{
public:
	BaseState();
	virtual ~BaseState();

	void tick(ClientData* data);
	void render(sf::RenderWindow* windwo);
private:

	//std::vector<std::unique_ptr<GameObject>>;
};