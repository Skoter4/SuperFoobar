#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Map_object.h"
#include "Make_track.h"
#include <memory>
#include "Collision_sfml.h"

void update_sprite(std::shared_ptr<Map_object> MO)
{
	MO->get_sprite()->setPosition(MO->get_x_pos(), MO->get_y_pos());
}

int main()
{

	//skapa foobar
	std::shared_ptr<Foobar> Foobar_obj{ make_Foobar()};
	
	//Saker som tillhör utritning

	sf::Texture Pictures;
	Pictures.loadFromFile("Pictures/SuperFoobarTransTextures.png");
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
	sf::IntRect Coin_pic(172, 122, 40, 48);

	//Skapa spelfönstret
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

	
	std::list<std::shared_ptr<Block>> Floor_list{ make_floor_seg(200, 0) };
	add_to_block_list(Floor_list, make_non_breakable(150, 450));
	std::list < std::shared_ptr<Interactable>> Interactable_list{ make_coin_row_seg(200, 200, 280) };


	for (auto it = Floor_list.begin(); it != Floor_list.end(); ++it)
	{
		(*it)->get_sprite()->setTexture(Pictures);
		(*it)->get_sprite()->setTextureRect(Floor_pic);
		update_sprite(*it);
	}

	for (auto it = Interactable_list.begin(); it != Interactable_list.end(); ++it)
	{
		(*it)->get_sprite()->setTexture(Pictures);
		(*it)->get_sprite()->setTextureRect(Coin_pic);
		update_sprite(*it);
	}

	Foobar_obj->get_sprite()->setTexture(Pictures);
	Foobar_obj->get_sprite()->setTextureRect(Foobar_R_pic);


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
					Foobar_obj->run();
				}

				if (event.key.code == sf::Keyboard::Left)
				{
					//Ska även ändra bild
					Foobar_obj->set_x_velocity(-1);
				}

				if (event.key.code == sf::Keyboard::Right)
				{
					//ska även ändra bild
					//Foobar_obj->set_x_velocity(Foobar_obj->get_max_speed_x());
					Foobar_obj->set_x_velocity(1);
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
					//Ska även ändra tillbaka bilden
				}

				if (event.key.code == sf::Keyboard::LShift)
				{
					Foobar_obj->set_max_speed_x(50);
				}
			}
		}

		Foobar_obj->set_y_velocity(Foobar_obj->get_gravity());

		Foobar_obj->set_desx_pos(Foobar_obj->get_x_pos() + Foobar_obj->get_x_velocity());
		Foobar_obj->set_desy_pos(Foobar_obj->get_y_pos() + Foobar_obj->get_y_velocity());


		for (auto it = Floor_list.begin(); it != Floor_list.end(); ++it)
		{
			block_collision(Foobar_obj, *it);
		}


		
		//Så att kameran följer med Foobar men inte går till vänster om start-position

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


		//Funktion så att Foobar inte kan gå utanför fönstret till vänster om startposition
		if (Foobar_obj->get_x_pos() == 0 && Foobar_obj->get_x_velocity() < 0)
		{
			Foobar_obj->set_x_velocity(0);
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
		GameWindow.draw(Background);
		std::cout << Foobar_obj->get_y_pos()<<std::endl;
		for (auto it = Floor_list.begin(); it != Floor_list.end(); ++it)
		{
			GameWindow.draw(*(*it)->get_sprite());
			//std::cout << (*it)->get_x_pos() << std::endl;
		}
		for (auto it = Interactable_list.begin(); it != Interactable_list.end(); ++it)
		{
			GameWindow.draw(*(*it)->get_sprite());
			//std::cout << (*it)->get_x_pos() << std::endl;
		}
		GameWindow.draw(*Foobar_obj->get_sprite());
		update_sprite(Foobar_obj);
		GameWindow.display();

/*
	void run_game()
	{

	}
	*/
	}
}