#include <SFML/Graphics.hpp>

int(main)
{
	//Skapa spelf�nstret
	sf::ContextSettings settings;
	settings.antialiasingLevel = 8;

	sf::RenderWindow GameWindow(sf::VideoMode(1024,592));

	sf::Texture texture;
	texture.setRepeated(true);
	texture.loadFromFile("Pictures/Background.png");
	
	sf::Sprite sprite(texture);
	sprite.setTexture(texture);
	sprite.setTextureRect(sf::IntRect(0, 0, 4096, 592));
	
	sf::Event event;

	//Skapa alla objekt s� de blir ritabara.

	while (GameWindow.isOpen())
	{
		while (GameWindow.pollEvent(event))
		{
			if (event.type == sf::Event::EventType::Closed)
			{
				window.close();
			}

			if (event.type == sf::Event::KeyPressed)
			{
				if (event.key.code == sf::Keyboard::Left)
				{
					//Foobars hastighet i x-led �ndras
				}

				if (event.key.code == sf::Keyboard::Right)
				{
					//Foobars hastighet i x-led �ndras
				}

				if (event.key.code == sf::Keyboard::Up)
				{
					//Foobar hoppar
				}

				if (event.key.code == sf::Keyboard::Down)
				{
					//Foobars duckar
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
					//Foobar stannar
				}

				if (event.key.code == sf::Keyboard::Right)
				{
					//Foobar stannar
				}

				if (event.key.code == sf::Keyboard::Down)
				{
					//Foobar slutar ducka
				}
			}
		}


		//S� att kameran f�ljer med Foobar men inte g�r till v�nster om start-position
	 
		int camera_x = //Foobars x-pos;

		if (/*Foobars x pos*/ > 512)
		{
			sf::View view(sf::FloatRect(camera_x - 512, 0, 1024, 592));
			window.setView(view);
		}
		else
		{
			sf::View view(sf::FloatRect(0, 0, 1024, 592));
			window.setView(view);
		}


		/*Funktion s� att Foobar inte kan g� utanf�r f�nstret till v�nster om startposition*/
		if (/*Foobar x.pos*/ == 0)
		{
			/*S�tt Foobars x-hastighet till 0*/
		}

		if (/*Foobar y-pos*/ < /*markens niv�*/)
		{
			//Game over
		}


		/* Funktion f�r game-over om tiden tar slut*/

		// Kolla kollisioner s� att Foobar kan f�rflytta sig eller plocka upp coins/powerups

		// Kolla kollisioner f�r fiender ocks�

		// Vid interaktion med m�llinjen ska spelet avslutas och po�ngen r�knas ihop

		// Rita ut det som �r aktivt

	void run_game()
	{

	}

}