#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Character filer\Foobar\Foobar.h"

int main()
{

	//skapa foobar
	Foobar Foobar(45,35,12,80);
	
	sf::Texture texture1;
	texture1.loadFromFile("Pictures/Generator.png");
	std::shared_ptr<sf::Sprite> x{new sf::Sprite};
	x->setTexture(texture1);
	Foobar.setSprite(x);

	//Skapa spelfönstret
	sf::ContextSettings settings;
	settings.antialiasingLevel = 8;

	sf::RenderWindow GameWindow(sf::VideoMode(1024, 592), "TEST");

	sf::Texture texture;
	texture.setRepeated(true);
	texture.loadFromFile("Pictures/Background.png");

	sf::Sprite sprite(texture);
	sprite.setTexture(texture);
	sprite.setTextureRect(sf::IntRect(0, 0, 4096, 592));


	


	sf::Event event;

	//Skapa alla objekt så de blir ritabara.

	while (GameWindow.isOpen())
	{
		while (GameWindow.pollEvent(event))
		{
			if (event.type == sf::Event::EventType::Closed)
			{
				GameWindow.close();
			}

			if (event.type == sf::Event::KeyPressed)
			{

				if (event.key.code == sf::Keyboard::LShift)
				{
					Foobar.run();
				}

				if (event.key.code == sf::Keyboard::Left)
				{
					//Ska även ändra bild
					Foobar.set_x_velocity(-Foobar.get_max_speed_x());
				}

				if (event.key.code == sf::Keyboard::Right)
				{
					//ska även ändra bild
					Foobar.set_x_velocity(Foobar.get_max_speed_x());
				}

				if (event.key.code == sf::Keyboard::Up)
				{
					//Foobar hoppar
				}

				if (event.key.code == sf::Keyboard::Down)
				{	
					if(!Foobar.get_is_ducking())
					{ 
						Foobar.duck();
						Foobar.flip_is_ducking();
					}
					//Ska även ändra bild
				}
			}

			if (event.type == sf::Event::KeyReleased)
			{
				if (event.key.code == sf::Keyboard::Up)
				{
					//Foobar "avbryter" sitt hopp
				}

				if (event.key.code == sf::Keyboard::Left)
				{
					Foobar.set_x_velocity(0);
				}

				if (event.key.code == sf::Keyboard::Right)
				{
					Foobar.set_x_velocity(0);
				}

				if (event.key.code == sf::Keyboard::Down)
				{
					if (Foobar.get_is_ducking())
					{
						Foobar.stand_up();
						Foobar.flip_is_ducking();
					}
					//Ska även ändra tillbaka bilden
				}

				if (event.key.code == sf::Keyboard::LShift)
				{
					Foobar.set_max_speed_x(50);
				}
			}
		}


		//Så att kameran följer med Foobar men inte går till vänster om start-position

		int camera_x = Foobar.get_x_pos();

		if (Foobar.get_x_pos() > 512)
		{
			sf::View view(sf::FloatRect(camera_x - 512, 0, 1024, 592));
			GameWindow.setView(view);
		}
		else
		{
			sf::View view(sf::FloatRect(0, 0, 1024, 592));
			GameWindow.setView(view);
		}


		/*Funktion så att Foobar inte kan gå utanför fönstret till vänster om startposition*/
		if (Foobar.get_x_pos() == 0 && Foobar.get_x_velocity() < 0)
		{
			Foobar.set_x_velocity(0);
		}

		//if (/*Foobar y-pos*/ < /*markens nivå*/)
		//{
			//Game over
		//}


		/* Funktion för game-over om tiden tar slut*/

		// Kolla kollisioner så att Foobar kan förflytta sig eller plocka upp coins/powerups

		// Kolla kollisioner för fiender också

		// Vid interaktion med mållinjen ska spelet avslutas och poängen räknas ihop

		// Rita ut det som är aktivt

		GameWindow.clear();
		GameWindow.draw(sprite);
		GameWindow.draw(*Foobar.get_sprite());
		GameWindow.display();
/*
	void run_game()
	{

	}
	*/
	}
}