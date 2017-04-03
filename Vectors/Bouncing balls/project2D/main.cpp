#include "Application2D.h"

int main() {
	
	auto app = new Application2D();
	app->run("Bouncy balls", 1280, 720, false);
	delete app;

	return 0;
}