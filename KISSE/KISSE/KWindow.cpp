#include "KWindow.h"

/*
Construct the renderwindow here
*/
KWindow::KWindow() : sf::RenderWindow::RenderWindow()
{

}
/*
Poll for user input of some form, retrieved and
interperted by the main loop
*/
char KWindow::keypoll(){
	return 'a';
}
/*
Perform all drawing required by 
the engine, whatever the tasks may be
*/
void KWindow::drawframe(unsigned char * whatever){

}
KWindow::~KWindow()
{

}
