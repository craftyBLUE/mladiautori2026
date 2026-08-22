#include <SFML/Graphics.hpp>

int main()
{
	sf::RenderWindow window( sf::VideoMode( { 800, 800 } ), "SFML works!" );
	sf::CircleShape krug( 100.f );
	krug.setFillColor(sf::Color::Green);

	sf::RectangleShape pravokutnik({10.0f, 10.0f});
	pravokutnik.setFillColor(sf::Color::Red);
	pravokutnik.setPosition({20.0f, 40.0f});

	sf::Texture tekstura("assets/zaruljko.png");
  sf::Sprite sprajt(tekstura);
  sprajt.setPosition({40.0f, 80.0f});
	sprajt.setScale({0.5f, 0.5f});
	
	sf::Clock frameClock;

	while ( window.isOpen() )
	{
		while ( const std::optional event = window.pollEvent() )
		{
			if ( event->is<sf::Event::Closed>() )
				window.close();
		}

		sf::Time dt = frameClock.restart();

		krug.move({1.0f * dt.asSeconds(), 0.0f});

		window.clear();
		window.draw(krug);
		window.draw(pravokutnik);
		window.draw(sprajt);
		window.display();
	}
}
