#pragma once
#include "C:\SFML-2.2\include\SFML\Graphics\RenderWindow.hpp"
class KWindow :
	public sf::RenderWindow
{
public:
	KWindow();
	char keypoll();
	void drawframe(unsigned char*);
	~KWindow();
};

