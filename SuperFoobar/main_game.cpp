#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Map_object.h"
#include "Make_track.h"
#include "Timer.h"
#include "Score.h"
#include <memory>
#include "Collision_sfml.h"

int main()
{
	try
	{
		// initiering av texturerna
		::SUPER_FOOBAR_TEXTURES.loadFromFile("Pictures/SuperFoobarTransTextures.png");


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

		//Font kek
		sf::Font font;
		if (!font.loadFromFile("arial.ttf")) 
		{
			std::cout << "Error loading from file" << std::endl;
		}

		//Skapa Bana
		SUPER_FOOBAR_TEXTURES.setRepeated(true);

		std::list<std::shared_ptr<Character>> character_list{};
		std::list<std::shared_ptr<Block>> block_list{};
		std::list<std::shared_ptr<Interactable>> interactable_list{};

		block_list + make_floor_seg(16, 0) + make_one_line_breakable_seg(4, 4, 5) + make_coin_generator(12, 5);
		character_list + make_foobar() + make_enemy_1(5, 6);
		interactable_list + make_coin_row_seg(4, 4, 4);


		std::shared_ptr<Track> track{ make_track(block_list, character_list, interactable_list) };
		init_sprite(track);

		//Skapa spelfönstret
		sf::ContextSettings settings;
		settings.antialiasingLevel = 8;

		sf::RenderWindow GameWindow(sf::VideoMode(16 * 70, 12 * 70) , "TEST");

		sf::Texture Background_pic;
		Background_pic.setRepeated(true);
		Background_pic.loadFromFile("Pictures/Background.png");

		sf::Sprite Background(Background_pic);
		Background.setTexture(Background_pic);
		Background.setTextureRect(sf::IntRect(0, 0, track->get_width(), track->get_height()));


		// Score, top-left corner
		Score score{};
		sf::Text scoreText;
		scoreText.setFont(font);
		scoreText.setString(std::to_string(static_cast<int>(score.get_score()))); // Conversion to int to get rid of decimals
		scoreText.setPosition(15, 5);
		scoreText.setCharacterSize(50); // Default = 30
		
											  // Timer, top-right corner
		float timer{}; // Used to count down
		sf::Text timerText;
		timerText.setFont(font);
		timerText.setPosition(16* 70 - 140, 5);
		timerText.setCharacterSize(50);
		//timerText.setColor(sf::Color::White);
		sf::Clock clock; // Starts the clock

		sf::Event event;
		Timer new_timer{};

		track->set_timer(new_timer);

		bool gameover{ false }; // Hur ska game-over hanteras? Gjorde detta som en temporär lösning
		bool first_time{ true }; // Förhindrar att kvarvarande tid adderas till score flera gånger vid game-over


		track->set_score( score );

		while (GameWindow.isOpen())
		{
			//Timer countdown
			if ((track->get_timer()).get_time_remaining() > 0.0f) 
			{
				timer = clock.getElapsedTime().asSeconds();
				(track->get_timer()).set_time_remaining((track->get_timer()).get_time_remaining() - timer);
				timerText.setString(std::to_string(static_cast<int>((track->get_timer()).get_time_remaining())));
				clock.restart();
			}

			if (!gameover) 
			{

				// Timer countdown
				if (new_timer.get_time_remaining() > 0.0f) {
					new_timer.countdown();
					timerText.setString(std::to_string(static_cast<int>(new_timer.get_time_remaining())));
				}
				else {
					gameover = true; // Timer hits 0 => game-over
				}

			}
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
						track->get_foobar()->run();
					}



					if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) )
					{
						//Ska även ändra bild
						//Foobar_obj->set_x_velocity(-1);
						track->get_foobar()->set_desx_pos(track->get_foobar()->get_x_pos() - 20);
					}

					if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
					{
						//ska även ändra bild
						//Foobar_obj->set_x_velocity(Foobar_obj->get_max_speed_x());
						//	Foobar_obj->set_x_velocity(1);
						track->get_foobar()->set_desx_pos(track->get_foobar()->get_x_pos() + 20);
					}

					if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
					{
						track->get_foobar()->set_desy_pos(track->get_foobar()->get_y_pos() - 20);
						//Foobar hoppar
					}

					if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
					{
						/*if(!Foobar_obj->get_is_ducking())
						{
							Foobar_obj->duck();
							Foobar_obj->flip_is_ducking();
						}*/
						//Ska även ändra bild
						track->get_foobar()->set_desy_pos(track->get_foobar()->get_y_pos() + 20);
					}
				}

				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
				{
					//Ska även ändra bild
					//Foobar_obj->set_x_velocity(-1);
					track->get_foobar()->set_desx_pos(track->get_foobar()->get_x_pos() - 20);

					track->get_foobar()->set_desy_pos(track->get_foobar()->get_y_pos() - 20);
				}

				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
				{
					//Ska även ändra bild
					//Foobar_obj->set_x_velocity(-1);
					track->get_foobar()->set_desx_pos(track->get_foobar()->get_x_pos() + 20);

					track->get_foobar()->set_desy_pos(track->get_foobar()->get_y_pos() - 20);
				}

				if (event.type == sf::Event::KeyReleased)
				{
					if (event.key.code == sf::Keyboard::Up)
					{
						//Foobar "avbryter" sitt hopp
					}

					if (event.key.code == sf::Keyboard::Left)
					{
						track->get_foobar()->set_x_velocity(0);
					}

					if (event.key.code == sf::Keyboard::Right)
					{
						track->get_foobar()->set_x_velocity(0);
					}

					if (event.key.code == sf::Keyboard::Down)
					{
						if (track->get_foobar()->get_is_ducking())
						{
							track->get_foobar()->stand_up();
							track->get_foobar()->flip_is_ducking();
						}
						//Ska även ändra tillbaka bilden
					}

					if (event.key.code == sf::Keyboard::LShift)
					{
						track->get_foobar()->set_max_speed_x(50);
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
				block_collision(track->get_foobar(), *it);
			}

			for (auto it = track->get_interactable_list().begin(); it != track->get_interactable_list().end(); ++it)
			{
				block_collision(track->get_foobar(), *it);
			}


			//Så att kameran följer med Foobar men inte går till vänster om start-position

			int camera_x = track->get_foobar()->get_x_pos();

			if (track->get_foobar()->get_x_pos() > 512)
			{
				sf::View view(sf::FloatRect(static_cast<float>(camera_x - 512), 0, 16 * 70, 12 * 70));
				timerText.setPosition((static_cast<float>(16 * 70 - 140 + (camera_x - 512))), timerText.getPosition().y);
				scoreText.setPosition((static_cast<float>(15 + (camera_x - 512))), scoreText.getPosition().y);
				GameWindow.setView(view);
			}
			else
			{
				sf::View view(sf::FloatRect(0, 0, 16 * 70, 12 * 70));
				GameWindow.setView(view);
			}


			//Funktion så att Foobar inte kan gå utanför fönstret till vänster om startposition
			if (track->get_foobar()->get_x_pos() == 0 && track->get_foobar()->get_x_velocity() < 0)
			{
				track->get_foobar()->set_x_velocity(0);
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
			GameWindow.draw(timerText);
			GameWindow.draw(scoreText);
			update_sprite(track);
			scoreText.setString(std::to_string(static_cast<int>(track->get_score().get_score())));
			track->handle_map_object_flags();
			GameWindow.display();

		}

	}
	catch (std::exception& e)
	{
		std::cout << e.what() <<  "Måste göra en foobar!";
	}
}