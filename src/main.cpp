#include "SFML/Audio.hpp"
#include "SFML/Graphics.hpp"
#include <stdlib.h>

int main(int argc, char** argv){
	sf::RenderWindow window(sf::VideoMode(640 * 1.5, 360 * 1.5), "SFML-Test");

	sf::Event event;
	int ghettoTime = 300;

	sf::Font font;
  font.loadFromFile("/usr/share/fonts/truetype/liberation/LiberationSerif-Regular.ttf");

	sf::Text text("SMOKE WEED EVERYDAY", font, 18);
	text.setColor(sf::Color::White);

	sf::Texture cocoTexture;
	cocoTexture.loadFromFile("../assets/images/cocoGuy.png");
	sf::Sprite cocoGuy(cocoTexture);
	cocoGuy.setPosition(0,0);

	sf::Texture logoTexture;
	logoTexture.loadFromFile("../assets/images/VersatileVelociraptors.png");
	sf::Sprite logo(logoTexture);

	sf::Music coco;
	coco.openFromFile("../assets/music/coco.mp3");
	coco.play();

	while (window.isOpen()){
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed) {
				// allow window to be closed
				window.close();
			}
		}

		// use timer and random number generator
		if (ghettoTime == 0){
			text.setPosition(rand() % (int) (640 * 1.5), rand() % (int) (360 * 1.5));
			sf::Color randomColor(rand() % 255, rand() % 255, rand() % 255);
			text.setColor(randomColor);
			ghettoTime = 300;
		}

		// move coco guy sprite
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
			cocoGuy.move(-1, 0);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
			cocoGuy.move(1, 0);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
			cocoGuy.move(0, 1);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
			cocoGuy.move(0, -1);
		}

		// logo stays with mouse
		logo.setPosition(static_cast<sf::Vector2f>(sf::Mouse::getPosition(window)));

		window.clear(sf::Color::Black);
		window.draw(logo);
		window.draw(cocoGuy);
		window.draw(text);
		window.display();
		ghettoTime--;
	}

	return 0;
}
