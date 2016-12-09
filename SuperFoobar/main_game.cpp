
#include <SFML/Audio.hpp>
#include "Map_object.h"
#include "Make_track.h"
#include <memory>

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
	sf::IntRect Pu1_pic(212, 122, 43, 42);
	sf::IntRect Pu2_pic(102, 173, 43, 43);

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

	
	std::list<std::shared_ptr<Block>> Floor_list{ make_floor_seg(4000, 0) };
	std::list < std::shared_ptr<Interactable>> Interactable_list{ make_coin_row_seg(200, 200, 280) };
	std::shared_ptr<Interactable> SHROOM{ make_pup(300, 300, "power_up_1") };
	std::shared_ptr<Interactable> STAR{ make_pup(400, 300, "power_up_2") };

	for (auto it = Floor_list.begin(); it != Floor_list.end(); ++it)
	{
		update_sprite(*it, Pictures, Floor_pic);
	}

	for (auto it = Interactable_list.begin(); it != Interactable_list.end(); ++it)
	{
		update_sprite(*it, Pictures, Coin_pic);
	}

	update_sprite_texture(Foobar_obj, Pictures, Foobar_R_pic);

	update_sprite_texture(SHROOM, Pictures, Pu1_pic);

	add_to_interactable_list(Interactable_list, SHROOM);
	update_sprite_position(SHROOM);

	STAR->get_sprite()->setTexture(Pictures);
	STAR->get_sprite()->setTextureRect(Pu2_pic);

	add_to_interactable_list(Interactable_list, STAR);
	update_sprite_position(STAR);

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
				{	//ska även ändra bild
					//Foobar_obj->set_x_velocity(Foobar_obj->get_max_speed_x());
					Foobar_obj->get_sprite()->setTextureRect(Foobar_L_pic);
					Foobar_obj->set_x(Foobar_obj->get_x_pos() - 20);
				}

				if (event.key.code == sf::Keyboard::Right)
				{
					//ska även ändra bild
					//Foobar_obj->set_x_velocity(Foobar_obj->get_max_speed_x());
					Foobar_obj->get_sprite()->setTextureRect(Foobar_R_pic);
					Foobar_obj->set_x(Foobar_obj->get_x_pos() + 20);
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
		GameWindow.draw(*Foobar_obj->get_sprite());
		update_sprite_position(Foobar_obj);
		for (auto it = Floor_list.begin(); it != Floor_list.end(); ++it)
		{
			GameWindow.draw(*(*it)->get_sprite());
		}
		
		for (auto it = Interactable_list.begin(); it != Interactable_list.end(); ++it)
		{
			GameWindow.draw(*(*it)->get_sprite());
		}

		GameWindow.display();

	}
}