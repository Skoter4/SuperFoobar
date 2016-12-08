#pragma once
#include <SFML/Audio.hpp>
#include "Character filer\Foobar\Foobar.h"
#include "Make_track.h"
#include <SFML/Graphics.hpp>

void update_sprite(std::shared_ptr<Map_object> MO)
{
	MO->get_sprite()->setPosition(MO->get_x_pos(), MO->get_y_pos());
}
int main()
{

	//skapa foobar
	std::shared_ptr<Foobar> Foobar_obj{ make_Foobar() };
	
	//Saker som tillhör utritning

	sf::Texture Pictures;
	Pictures.loadFromFile("Pictures/Fiender_Mario_Block.png");
	sf::IntRect Foobar_R_pic(0, 46, 43, 56);
	sf::IntRect Foobar_L_pic(43, 46, 43, 56);
	sf::IntRect Foobar_HR_pic(86, 46, 60, 78);
	sf::IntRect Foobar_HL_pic(146, 46, 60, 78);
	sf::IntRect Foobar_DR_pic(0, 102, 43, 28);
	sf::IntRect Foobar_DL_pic(43, 102, 43, 28);
	sf::IntRect Enemy1_pic(88, 0, 44, 46);
	sf::IntRect Enemy2_pic(0, 0, 44, 46);
	sf::IntRect Enemy3_pic(44, 0, 44, 46);
	sf::IntRect Proj_L_pic(35, 130, 35, 17);
	sf::IntRect Proj_R_pic(0, 130, 35, 17);
	sf::IntRect Floor_pic(0, 147, 70, 70);
	sf::IntRect Breakable_pic(0, 217, 70, 70);
	sf::IntRect Non_Breakable_pic(140, 217, 70, 70);
	sf::IntRect Generator_pic(70, 217, 70, 70);
	sf::IntRect Used_Generator_pic(210, 217, 70, 70);

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
	
	std::shared_ptr<sf::Sprite> x{ new sf::Sprite(Pictures, Foobar_R_pic) };
	x->setPosition(Foobar_obj->get_x_pos(), Foobar_obj->get_y_pos());
	Foobar_obj->setSprite(x);
	
	std::list<std::shared_ptr<Block>> Floor_list{ make_floor_seg(70 * 8, 0) };
	std::list<std::shared_ptr<Block>> Rectangle_list{ make_rect_seg(70 * 3, 70 * 3, 70 * 9, 7 * 70) };
	std::list<std::shared_ptr<Block>> Other_Rectangle_list{ make_one_line_breakable_seg(70 * 3, 1 * 70, 4 * 70) };
	std::list<std::shared_ptr<Interactable>> Coins_list{make_coin_row_seg(70 * 3, 1 * 70, 3 * 70) };

	
	for (auto it = Floor_list.begin(); it != Floor_list.end(); ++it)
	{
		std::shared_ptr<sf::Sprite> Floor{ new sf::Sprite(Pictures,Floor_pic) };
		(*it)->setSprite(Floor);
		update_sprite((*it));
	}

	for (auto it = Rectangle_list.begin(); it != Rectangle_list.end(); ++it)
	{
		std::shared_ptr<sf::Sprite> Blocks{ new sf::Sprite(Pictures,Non_Breakable_pic) };
		(*it)->setSprite(Blocks);
		update_sprite((*it));
	}

	for (auto it = Other_Rectangle_list.begin(); it != Other_Rectangle_list.end(); ++it)
	{
		std::shared_ptr<sf::Sprite> Blocks{ new sf::Sprite(Pictures,Breakable_pic) };
		(*it)->setSprite(Blocks);
		update_sprite((*it));
	}

	for (auto it = Coins_list.begin(); it != Coins_list.end(); ++it)
	{
		std::shared_ptr<sf::Sprite> Coins{ new sf::Sprite(Pictures,Proj_L_pic) };
		(*it)->setSprite(Coins);
		update_sprite((*it));
	}

	add_to_block_list(Floor_list, Rectangle_list);

	add_to_block_list(Floor_list, Other_Rectangle_list);


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
					Foobar_obj->set_x_velocity(-Foobar_obj->get_max_speed_x());
				}

				if (event.key.code == sf::Keyboard::Right)
				{
					//ska även ändra bild
					Foobar_obj->set_x(Foobar_obj->get_x_pos() + 8);

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
					Foobar_obj->set_x_velocity(1);
				}

				if (event.key.code == sf::Keyboard::Right)
				{
					Foobar_obj->set_x_velocity(1);
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
		update_sprite(Foobar_obj);
		for (auto it = Floor_list.begin(); it != Floor_list.end(); ++it)
		{
			GameWindow.draw(*(*it)->get_sprite());
		}
		for (auto it = Coins_list.begin(); it != Coins_list.end(); ++it)
		{
			GameWindow.draw(*(*it)->get_sprite());
		}
		GameWindow.display();

/*
	void run_game()
	{

	}
	*/
	}
}