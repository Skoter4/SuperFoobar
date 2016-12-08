#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Character filer\Foobar\Foobar.h"
#include "Make_track.h"


int main()
{

	//skapa foobar
	std::shared_ptr<Foobar> Foobar_obj{new Foobar(450,35,50,50) };
	
	//Saker som tillh�r utritning

	sf::Texture Pictures;
	Pictures.loadFromFile("Pictures/Fiender_Foobar_Blocks.png");
	sf::IntRect Foobar_R_pic(150, 0, 50, 50);
	sf::IntRect Foobar_L_pic(200, 0, 50, 50);
	sf::IntRect Foobar_HR_pic(0, 190, 50, 100);
	sf::IntRect Foobar_HL_pic(50, 190, 50, 100);
	sf::IntRect Foobar_DR_pic(70, 120, 50, 25);
	sf::IntRect Foobar_DL_pic(120, 120, 50, 25);
	sf::IntRect Enemy1_pic(100, 0, 50, 50);
	sf::IntRect Enemy2_pic(0, 0, 50, 50);
	sf::IntRect Enemy3_pic(50, 0, 50, 50);
	sf::IntRect Proj_L_pic(120, 145, 50, 25);
	sf::IntRect Proj_R_pic(70, 145, 50, 25);
	sf::IntRect Floor_pic(70, 50, 70, 70);
	sf::IntRect Breakable_pic(0, 50, 70, 70);
	sf::IntRect Non_Breakable_pic(210, 50, 70, 70);
	sf::IntRect Generator_pic(140, 50, 70, 70);
	sf::IntRect Used_Generator_pic(0, 120, 70, 70);

	//Skapa spelf�nstret
	sf::ContextSettings settings;
	settings.antialiasingLevel = 8;

	sf::RenderWindow GameWindow(sf::VideoMode(1024, 592), "TEST");

	sf::Texture Background_pic;
	Background_pic.setRepeated(true);
	Background_pic.loadFromFile("Pictures/Background.png");

	sf::Sprite Background(Background_pic);
	Background.setTexture(Background_pic);
	Background.setTextureRect(sf::IntRect(0, 0, 4096, 592));

	//Skapa Bana
	Pictures.setRepeated(true);
	
	std::shared_ptr<sf::Sprite> x{ new sf::Sprite(Pictures, Foobar_R_pic) };
	x->setPosition(Foobar_obj->get_x_pos(), Foobar_obj->get_y_pos());
	Foobar_obj->setSprite(x);
	
	std::list<std::shared_ptr<Block>> Floor_list{ make_floor_seg(4000, 0) };

	for (auto it = Floor_list.begin(); it != Floor_list.end(); ++it)
	{
		std::shared_ptr<sf::Sprite> Floor{ new sf::Sprite(Pictures,Floor_pic) };
		Floor->setPosition((*it)->get_x_pos(), (*it)->get_y_pos());
		(*it)->setSprite(Floor);
	}

	





	sf::Event event;

	//Skapa alla objekt s� de blir ritabara.

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
					Foobar_obj->run();
				}

				if (event.key.code == sf::Keyboard::Left)
				{
					//Ska �ven �ndra bild
					Foobar_obj->set_x_velocity(-Foobar_obj->get_max_speed_x());
				}

				if (event.key.code == sf::Keyboard::Right)
				{
					//ska �ven �ndra bild
					Foobar_obj->set_x_velocity(Foobar_obj->get_max_speed_x());
				}

				if (event.key.code == sf::Keyboard::Up)
				{
					//Foobar hoppar
				}

				if (event.key.code == sf::Keyboard::Down)
				{
					if(!Foobar_obj->get_is_ducking())
					{
						Foobar_obj->duck();
						Foobar_obj->flip_is_ducking();
					}
					//Ska �ven �ndra bild
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
					Foobar_obj->set_x_velocity(0);
				}

				if (event.key.code == sf::Keyboard::Right)
				{
					Foobar_obj->set_x_velocity(0);
				}

				if (event.key.code == sf::Keyboard::Down)
				{
					if (Foobar_obj->get_is_ducking())
					{
						Foobar_obj->stand_up();
						Foobar_obj->flip_is_ducking();
					}
					//Ska �ven �ndra tillbaka bilden
				}

				if (event.key.code == sf::Keyboard::LShift)
				{
					Foobar_obj->set_max_speed_x(50);
				}
			}
		}


		//S� att kameran f�ljer med Foobar men inte g�r till v�nster om start-position

		int camera_x = Foobar_obj->get_x_pos();

		if (Foobar_obj->get_x_pos() > 512)
		{
			sf::View view(sf::FloatRect(camera_x - 512, 0, 1024, 592));
			GameWindow.setView(view);
		}
		else
		{
			sf::View view(sf::FloatRect(0, 0, 1024, 592));
			GameWindow.setView(view);
		}


		//Funktion s� att Foobar inte kan g� utanf�r f�nstret till v�nster om startposition
		if (Foobar_obj->get_x_pos() == 0 && Foobar_obj->get_x_velocity() < 0)
		{
			Foobar_obj->set_x_velocity(0);
		}

		

		//if (/*Foobar y-pos*/ < /*markens niv�*/)
		//{
			//Game over
		//}


		/* Funktion f�r game-over om tiden tar slut*/

		// Kolla kollisioner s� att Foobar kan f�rflytta sig eller plocka upp coins/powerups

		// Kolla kollisioner f�r fiender ocks�

		// Vid interaktion med m�llinjen ska spelet avslutas och po�ngen r�knas ihop

		// Rita ut det som �r aktivt
		
		GameWindow.clear();
		GameWindow.draw(Background);
		GameWindow.draw(*Foobar_obj->get_sprite());
		
		for (auto it = Floor_list.begin(); it != Floor_list.end(); ++it)
		{
			GameWindow.draw(*(*it)->get_sprite());
			std::cout << (*it)->get_x_pos() << std::endl;
		}
		GameWindow.display();

/*
	void run_game()
	{

	}
	*/
	}
}