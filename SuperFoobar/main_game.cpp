#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Map_object.h"
#include "Make_track.h"
#include <memory>
#include "Collision_sfml.h"

int main()
{
	try
	{

		//Saker som tillhör utritning
		// initiering av texturerna
		::SUPER_FOOBAR_TEXTURES.loadFromFile("Pictures/SuperFoobarTransTextures.png");

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

		// Bakgrundsmusik och ljud
		sf::Music background_music;
		background_music.openFromFile("Sounds/smb_theme.wav");
		background_music.setLoop(true);
		background_music.setVolume(10);
		background_music.play();

		// xxx_sound.play() för att spela ljuden
		sf::SoundBuffer coin_buffer;
		sf::SoundBuffer pup_buffer;
		sf::SoundBuffer pup_appear_buffer;
		sf::SoundBuffer bump_block_buffer;
		sf::SoundBuffer break_block_buffer;
		sf::SoundBuffer jump_small_buffer;
		sf::SoundBuffer jump_big_buffer;
		sf::SoundBuffer foobar_dies_buffer;
		sf::SoundBuffer game_over_buffer;
		sf::SoundBuffer kill_enemy_buffer;
		sf::SoundBuffer time_warning_buffer;
		sf::SoundBuffer finish_line_buffer;

		coin_buffer.loadFromFile("Sounds/smb_coin.wav");
		pup_buffer.loadFromFile("Sounds/smb_powerup.wav");
		pup_appear_buffer.loadFromFile("Sounds/smb_powerup_appears.wav");
		bump_block_buffer.loadFromFile("Sounds/smb_bump.wav");
		break_block_buffer.loadFromFile("Sounds/smb_breakblock.wav");
		jump_small_buffer.loadFromFile("Sounds/smb_jump-small.wav");
		jump_big_buffer.loadFromFile("Sounds/smb_jump-super.wav");
		foobar_dies_buffer.loadFromFile("Sounds/smb_mariodie.wav");
		game_over_buffer.loadFromFile("Sounds/smb_gameover.wav");
		kill_enemy_buffer.loadFromFile("Sounds/smb_stomp.wav");
		time_warning_buffer.loadFromFile("Sounds/smb_warning.wav");
		finish_line_buffer.loadFromFile("Sounds/smb_stage_clear.wav");

		sf::Sound coin_sound;
		sf::Sound pup_sound;
		sf::Sound pup_appear_sound; // Efter bump (bump = interaktion med generatorblock)
		sf::Sound bump_block_sound;
		sf::Sound break_block_sound;
		sf::Sound jump_small_sound;
		sf::Sound jump_big_sound;
		sf::Sound foobar_dies_sound;
		sf::Sound game_over_sound;
		sf::Sound kill_enemy_sound;
		sf::Sound time_warning_sound; // Lite tid kvar
		sf::Sound finish_line_sound;

		coin_sound.setBuffer(coin_buffer);
		pup_sound.setBuffer(pup_buffer);
		pup_appear_sound.setBuffer(pup_appear_buffer);
		bump_block_sound.setBuffer(bump_block_buffer);
		break_block_sound.setBuffer(break_block_buffer);
		jump_small_sound.setBuffer(jump_small_buffer);
		jump_big_sound.setBuffer(jump_big_buffer);
		foobar_dies_sound.setBuffer(foobar_dies_buffer);
		game_over_sound.setBuffer(game_over_buffer);
		kill_enemy_sound.setBuffer(kill_enemy_buffer);
		time_warning_sound.setBuffer(time_warning_buffer);
		finish_line_sound.setBuffer(finish_line_buffer);

		//Skapa Bana
		SUPER_FOOBAR_TEXTURES.setRepeated(true);
		std::shared_ptr<Foobar> Foobar_obj{ make_foobar() };



		std::list<std::shared_ptr<Character>> character_list{};
		character_list + Foobar_obj;



		std::shared_ptr<Track> track{ make_track(make_floor_seg(200, 0), character_list, make_coin_row_seg(200, 200, 280)) };

		*track + (make_non_breakable(150, 450));

		track->get_interactable_list() + make_pup(140, 140, "power_up_1") + make_coin(350, 140);



		sf::Event event;

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
						//Foobar_obj->set_x_velocity(-1);
						Foobar_obj->set_desx_pos(Foobar_obj->get_x_pos() - 20);
					}

					if (event.key.code == sf::Keyboard::Right)
					{
						//ska även ändra bild
						//Foobar_obj->set_x_velocity(Foobar_obj->get_max_speed_x());
						//	Foobar_obj->set_x_velocity(1);
						Foobar_obj->set_desx_pos(Foobar_obj->get_x_pos() + 20);
					}

					if (event.key.code == sf::Keyboard::Up)
					{
						Foobar_obj->set_desy_pos(Foobar_obj->get_y_pos() - 20);
						//Foobar hoppar
					}

					if (event.key.code == sf::Keyboard::Down)
					{
						/*if(!Foobar_obj->get_is_ducking())
						{
							Foobar_obj->duck();
							Foobar_obj->flip_is_ducking();
						}*/
						//Ska även ändra bild
						Foobar_obj->set_desy_pos(Foobar_obj->get_y_pos() + 20);
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
			/*
			Foobar_obj->set_y_velocity(Foobar_obj->get_gravity());

			Foobar_obj->set_desx_pos(Foobar_obj->get_x_pos() + Foobar_obj->get_x_velocity());
			Foobar_obj->set_desy_pos(Foobar_obj->get_y_pos() + Foobar_obj->get_y_velocity());
			
			*/

			for (auto it = track->get_block_list().begin(); it != track->get_block_list().end(); ++it)
			{
				block_collision(Foobar_obj, *it);
			}
			



			//Så att kameran följer med Foobar men inte går till vänster om start-position

			int camera_x = Foobar_obj->get_x_pos();

			if (Foobar_obj->get_x_pos() > 512)
			{
				sf::View view(sf::FloatRect(static_cast<float>(camera_x - 512), 0, 1024, 592));
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


			draw_track(track, GameWindow);
			update_sprite(track);
			GameWindow.display();

			/*
				void run_game()
				{

				}
				*/
		}

	}
	catch (std::exception& e)
	{
		std::cout << e.what() <<  "Måste göra en foobar!";
	}
}