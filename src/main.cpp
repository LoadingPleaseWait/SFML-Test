#include "SFML/Audio.hpp"
#include "SFML/Graphics.hpp"
#include <stdlib.h>

sf::Color randomColor();

int main(int argc, char** argv){
	sf::RenderWindow window(sf::VideoMode(640 * 1.5, 360 * 1.5), "SFML-Test");

	sf::Event event;
	sf::Clock clock;

	sf::Color background = sf::Color::Black;

	sf::Font font;
	font.loadFromFile("../assets/fonts/LiberationSerif-Regular.ttf");

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
	coco.openFromFile("../assets/music/coco.ogg");
	coco.setLoop(true);
	coco.play();

	sf::Music eclipse;
	eclipse.openFromFile("../assets/music/eclipse.ogg");
	eclipse.setLoop(true);

	while (window.isOpen()){
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed) {
				// allow window to be closed
				window.close();
			} else if (event.type == sf::Event::KeyReleased) {
				if (event.key.code == sf::Keyboard::Space) {
					// change music
					if (coco.getStatus() != sf::SoundSource::Stopped) {
						coco.stop();
						eclipse.play();
					} else {
						eclipse.stop();
						coco.play();
					}
				}
			}
		}

		// use timer and random number generator
		if (clock.getElapsedTime().asSeconds() >= 0.5) {
			text.setPosition(rand() % (int) (640 * 1.5), rand() % (int) (360 * 1.5));
			text.setColor(randomColor());
			background = randomColor();
			clock.restart();
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

		window.clear(background);
		window.draw(logo);
		window.draw(cocoGuy);
		window.draw(text);
		window.display();
	}

	return 0;
}

sf::Color randomColor() {
	sf::Color color(rand() % 255, rand() % 255, rand() % 255);
	return color;
}
