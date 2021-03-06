/*
* FILENAME:      main_game.cpp
* PROGRAMMERS:   Ludvig Danielsson 951221-7937 MED3
*                Alexander Eriksson 950405-9552 MED3
*                Martin Allander 951218-6215 Y2b
*                Tobias Nilsson 950103-6736 MED3
*                Tomas Widfeldt 940121-2015 MED3
* DATE:          2016-12-14
*/

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Window/Mouse.hpp>
#include "Map_object.h"
#include "Make_track.h"
#include "Timer.h"
#include "Score.h"
#include <memory>
#include <math.h>
#include "Collision_sfml.h"

int main()
{
	try
	{
		// Initializing textures and sound
		::SUPER_FOOBAR_TEXTURES.loadFromFile("Pictures/AllTextures.png");

		float game_volume{ 20.0f };

		sf::Music background_music;
		background_music.openFromFile("Sounds/smb_theme.wav");
		background_music.setLoop(true);
		background_music.setVolume(game_volume);

		sf::SoundBuffer jump_buffer;
		sf::SoundBuffer foobar_dies_buffer;
		sf::SoundBuffer game_over_buffer;
		sf::SoundBuffer time_warning_buffer;
		sf::SoundBuffer finish_line_buffer;

		jump_buffer.loadFromFile("Sounds/smb_jump-small.wav");
		foobar_dies_buffer.loadFromFile("Sounds/smb_mariodie.wav");
		game_over_buffer.loadFromFile("Sounds/smb_gameover.wav");
		time_warning_buffer.loadFromFile("Sounds/smb_warning.wav");
		finish_line_buffer.loadFromFile("Sounds/smb_stage_clear.wav");

		sf::Sound jump_sound;
		sf::Sound foobar_dies_sound;
		sf::Sound game_over_sound;
		sf::Sound time_warning_sound;
		sf::Sound finish_line_sound;

		jump_sound.setBuffer(jump_buffer);
		foobar_dies_sound.setBuffer(foobar_dies_buffer);
		game_over_sound.setBuffer(game_over_buffer);
		time_warning_sound.setBuffer(time_warning_buffer);
		finish_line_sound.setBuffer(finish_line_buffer);

		// Creation of track with the help of make_track
		SUPER_FOOBAR_TEXTURES.setRepeated(true);

		std::list<std::shared_ptr<Character>> character_list{};
		std::list<std::shared_ptr<Block>> block_list{};
		std::list<std::shared_ptr<Interactable>> interactable_list{};

		block_list + make_floor_seg(66, 0) + make_floor_seg(14, 68) + make_floor_seg(62, 84) + make_floor_seg(45, 148); // golv

		block_list + make_rect_seg(2, 1, 22, 10) + make_rect_seg(2, 2, 31, 9) + make_rect_seg(2, 3, 43, 8) + make_rect_seg(2, 3, 56, 8) + // Hinder
			make_rect_seg(2, 3, 155, 8) + make_rect_seg(2, 2, 165, 9);

		block_list + make_coin_generator(10, 7) + make_coin_generator(17, 7) + make_coin_generator(62, 6) + make_coin_generator(88, 7) +
			make_coin_generator(99, 7) + make_coin_generator(102, 7) + make_coin_generator(105, 7) +
			make_coin_generator(123, 4) + make_coin_generator(124, 4) + make_coin_generator(161, 7);

		block_list + make_pup_generator(15, 7, "power_up_shroom") + make_pup_generator(73, 7, "power_up_shroom") +
			make_pup_generator(94, 7, "power_up_star") + make_pup_generator(102, 4, "power_up_shroom");

		block_list + make_breakable(14, 7) + make_breakable(16, 7) + make_breakable(18, 7) + make_breakable(72, 7) + make_breakable(74, 7) +
			make_breakable(93, 7) + make_breakable(113, 7) + make_breakable(122, 4) + make_breakable(125, 4) + make_breakable(162, 7);

		block_list + make_one_line_breakable_seg(8, 75, 4) + make_one_line_breakable_seg(4, 116, 4) +
			make_one_line_breakable_seg(2, 123, 7) + make_one_line_breakable_seg(2, 159, 7);

		block_list + make_one_line_breakable_seg(3, 130, 10) + make_one_line_breakable_seg(2, 131, 9) + make_one_line_breakable_seg(1, 132, 8) +
			make_one_line_breakable_seg(3, 135, 10) + make_one_line_breakable_seg(2, 135, 9) + make_one_line_breakable_seg(1, 135, 8) +
			make_one_line_breakable_seg(4, 142, 10) + make_one_line_breakable_seg(3, 143, 9) + make_one_line_breakable_seg(2, 144, 8) +
			make_one_line_breakable_seg(3, 148, 10) + make_one_line_breakable_seg(2, 148, 9) + make_one_line_breakable_seg(1, 148, 8) +
			make_one_line_breakable_seg(9, 167, 10) + make_one_line_breakable_seg(8, 168, 9) + make_one_line_breakable_seg(7, 169, 8) +
			make_one_line_breakable_seg(6, 170, 7) + make_one_line_breakable_seg(5, 171, 6) + make_one_line_breakable_seg(4, 172, 5) +
			make_one_line_breakable_seg(3, 173, 4) + make_one_line_breakable_seg(2, 174, 3);

		character_list + make_foobar() + make_enemy_3(15, 10) + make_enemy_3(35, 10) + make_enemy_3(48, 10) + make_enemy_3(50, 10) +
			make_enemy_3(90, 10) + make_enemy_3(92, 10) + make_enemy_3(107, 10) + make_enemy_3(109, 10)
			+ make_enemy_2(100, 10) + make_enemy_1(162, 6) + make_enemy_1(163, 10);

		interactable_list + make_Finish_Line(185, 10);

		std::shared_ptr<Track> track{ make_track(block_list, character_list, interactable_list) };
		init_sprite(track);

		track->get_block_list().sort([](std::shared_ptr<Block> lhs, std::shared_ptr<Block> rhs) {return (lhs->get_x_pos() < rhs->get_x_pos()); });

		// GameWindow and initialization of its textures
		sf::ContextSettings settings;
		settings.antialiasingLevel = 8;

		sf::RenderWindow GameWindow(sf::VideoMode(16 * 70, 12 * 70), "TEST");

		sf::Event event;

		sf::View view(sf::FloatRect(0, 0, 16 * 70, 12 * 70));
		GameWindow.setView(view);

		sf::Texture Background_pic;
		Background_pic.setRepeated(true);
		Background_pic.loadFromFile("Pictures/New_Background.png");

		sf::Sprite Background(Background_pic);
		Background.setTexture(Background_pic);
		Background.setTextureRect(sf::IntRect(0, 0, track->get_width(), track->get_height()));

		sf::Texture main_menu_background_pic;
		main_menu_background_pic.setRepeated(true);
		main_menu_background_pic.loadFromFile("Pictures/main_menu_background.png");

		sf::Sprite main_menu_background(main_menu_background_pic);
		main_menu_background.setTexture(main_menu_background_pic);
		main_menu_background.setTextureRect(sf::IntRect(0, 0, track->get_width(), track->get_height()));

		// Initializing textures and sounds

		sf::Font font;
		if (!font.loadFromFile("smb.ttf"))
		{
			std::cout << "Error loading from file" << std::endl;
		}

		// Score, top-left corner
		Score score{};
		sf::Text scoreText;
		scoreText.setFont(font);
		scoreText.setString(std::to_string(static_cast<int>(score.get_score())));
		scoreText.setPosition(15, 70);
		scoreText.setCharacterSize(50);

		sf::Text scoreInfo;
		scoreInfo.setFont(font);
		scoreInfo.setString("Foobar");
		scoreInfo.setPosition(15, 15);
		scoreInfo.setCharacterSize(50);

		// Used to write score to when completing the game
		Scoreboard scoreboard{};
		track->set_score(score);
		track->set_scoreboard(scoreboard);

		// Timer, top-right corner
		sf::Text timerText;
		timerText.setFont(font);
		timerText.setPosition(16 * 70 - 100, 70);
		timerText.setCharacterSize(50);

		sf::Text timerInfo;
		timerInfo.setFont(font);
		timerInfo.setPosition(16 * 70 - 100, 15);
		timerInfo.setCharacterSize(50);
		timerInfo.setString("Time");

		sf::Text postgame_text;
		postgame_text.setFont(font);
		postgame_text.setPosition(500, 350);
		postgame_text.setCharacterSize(50);
		postgame_text.setString("");

		sf::Text scoreboard_text;
		scoreboard_text.setFont(font);
		scoreboard_text.setPosition(243, 530);
		scoreboard_text.setCharacterSize(50);

		bool time_up{ false };
		bool play_game{ false };
		bool show_scoreboard{ false };
		bool first_time{ true };

		while (GameWindow.isOpen())
		{
			while (GameWindow.pollEvent(event))
			{
				if (event.type == sf::Event::EventType::Closed)
				{
					GameWindow.close();
				}
				if (event.type == sf::Event::MouseButtonPressed)
				{
					if (event.mouseButton.button == sf::Mouse::Left)
					{
						sf::Vector2i Mouse = sf::Mouse::getPosition(GameWindow);
						float Mouse_x{ (float)Mouse.x };
						float Mouse_y{ (float)Mouse.y };
						// Clicked play game
						if ((Mouse_x > 233 && Mouse_x < 553) && (Mouse_y > 429 && Mouse_y < 516)) 
						{ 
							if (!play_game) {
								play_game = true;
								Timer new_timer{};
								track->set_timer(new_timer);
								background_music.play();
							}
						}
						// Clicked show scoreboard
						else if ((Mouse_x > 562 && Mouse_x < 883) && (Mouse_y > 429 && Mouse_y < 516)) { 
							if (!play_game) {
								if (!show_scoreboard) {
									scoreboard_text.setString((track->get_scoreboard()).read_top5());
								}
								else {
									scoreboard_text.setString("");
								}
								show_scoreboard = !show_scoreboard;
							}
						}
					}
				} // Mouse event

				  // Inside event, if play game is pressed
				if (play_game) { 
					if (event.type == sf::Event::KeyPressed && (!track->get_foobar()->is_dead() && !track->is_end_of_game()))
					{
						if (event.key.code == sf::Keyboard::LShift)
						{
							if (track->get_foobar()->get_on_ground()) {
								track->get_foobar()->run();
							}
						}

						if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
						{
							track->get_foobar()->set_x_velocity(-1);
						}

						if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
						{
							track->get_foobar()->set_x_velocity(1);
						}

						if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
						{
							if (track->get_foobar()->get_on_ground())
							{
								track->get_foobar()->jump();
								jump_sound.setVolume(game_volume);
								jump_sound.play();
							}
						}

						if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
						{
							if (track->get_foobar()->get_on_ground())
							{
								track->get_foobar()->jump();
							}
							track->get_foobar()->set_x_velocity(1);
						}


						if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
						{
							if (track->get_foobar()->get_on_ground())
							{
								track->get_foobar()->jump();
							}
							track->get_foobar()->set_x_velocity(-1);
						}

					}
					if (event.type == sf::Event::KeyReleased)
					{
						if (event.key.code == sf::Keyboard::Left)
						{
							track->get_foobar()->set_x_velocity(0);
						}

						if (event.key.code == sf::Keyboard::Right)
						{
							track->get_foobar()->set_x_velocity(0);
						}

						if (event.key.code == sf::Keyboard::LShift)
						{
							track->get_foobar()->set_max_speed_x(5);
						}
					}
				}
			}  // Event

			if (play_game) // Outside event, if play game is pressed
			{
				// If Foobar is alive and playing
				if (!(track->get_foobar()->is_dead()) && !(time_up) && !(track->is_end_of_game()))
				{
					// Moves Foobar
					track->get_foobar()->set_y_velocity(track->get_foobar()->get_y_velocity() + track->get_foobar()->get_gravity());
					track->get_foobar()->move_x(track->get_foobar()->get_x_velocity());
					track->get_foobar()->move_y(track->get_foobar()->get_y_velocity());

					// Fires projectiles
					float f_time = track->get_timer().get_time_remaining();
					int i_time = static_cast<int>(round(f_time));
					if (i_time % 7 == 0)
						for (auto it = track->get_character_list().begin(); it != track->get_character_list().end(); ++it)
						{
							if ((*it)->type_str() == "enemy_1") {
								std::shared_ptr<Enemy_1> enemy_ptr{ std::dynamic_pointer_cast<Enemy_1>(*it) };

								if (enemy_ptr->get_prev_time() != i_time) {
									enemy_ptr->flip_ready();
									enemy_ptr->set_prev_time(i_time);
								}
							}
						}

					// Applies collision to character list on Foobar
					for (auto it = track->get_character_list().begin(); it != track->get_character_list().end(); ++it)
					{
						block_collision(track->get_foobar(), *it);
						if ((*it)->type_str() != "foobar" && (*it)->type_str() != "enemy_1")
						{
							// Applies collision between enemies and blocks
							if ((*it)->type_str() == "projectile")
							{
								(*it)->move_x((*it)->get_x_velocity());
								for (auto it2 = track->get_block_list().begin(); (*it2)->get_x_pos() < (*it)->get_x_pos() + ((*it)->get_width() * 2); ++it2)
								{
									block_collision(*it, *it2);
								}
							}
							else
							{
								(*it)->move_x((*it)->get_x_velocity());
								(*it)->move_y((*it)->get_y_velocity());
								for (auto it2 = track->get_block_list().begin(); (*it2)->get_x_pos() < (*it)->get_x_pos() + ((*it)->get_width() * 2); ++it2)

								{
									block_collision(*it, *it2);
								}
							}
						}
					}

					// Applies collision between Foobar and Block
					for (auto it = track->get_block_list().begin(); (*it)->get_x_pos() < track->get_foobar()->get_x_pos() + track->get_foobar()->get_width(); ++it)
					{
						block_collision(track->get_foobar(), *it);
					}
					if (track->get_interactable_list().size() > 0)
					{
						for (auto it = track->get_interactable_list().begin(); it != track->get_interactable_list().end(); ++it)
						{
							block_collision(track->get_foobar(), *it);
						}
					}

					// Timer countdown
					if ((track->get_timer()).get_time_remaining() > 0.0f)
					{
						if (static_cast<int>((track->get_timer()).get_time_remaining()) == 30)
						{
							time_warning_sound.setVolume(game_volume);
							time_warning_sound.play();
						}
						timerText.setString(std::to_string((track->get_timer()).get_time_remaining()));
						(track->get_timer()).countdown();
						timerText.setString(std::to_string(static_cast<int>((track->get_timer()).get_time_remaining())));
					}
					else
					{
						time_up = true;
					}

					// Counteracts the camera moving to the left of Foobars starting position
					int camera_x = track->get_foobar()->get_x_pos(); 

					// Moves view of GameWindow and all Texts
					if (track->get_foobar()->get_x_pos() > 512)
					{
						sf::View view(sf::FloatRect(static_cast<float>(camera_x - 512), 0, 16 * 70, 12 * 70));
						timerText.setPosition((static_cast<float>(16 * 70 - 100 + (camera_x - 512))), timerText.getPosition().y);
						timerInfo.setPosition((static_cast<float>(16 * 70 - 100 + (camera_x - 512))), timerInfo.getPosition().y);
						scoreText.setPosition((static_cast<float>(15 + (camera_x - 512))), scoreText.getPosition().y);
						scoreInfo.setPosition((static_cast<float>(15 + (camera_x - 512))), scoreInfo.getPosition().y);
						postgame_text.setPosition((static_cast<float>(500 + (camera_x - 512))), postgame_text.getPosition().y);
						GameWindow.setView(view);
					}

					// Updates sprites, 
					update_sprite(track);
					scoreText.setString(std::to_string(static_cast<int>(track->get_score().get_score())));
					track->handle_map_object_flags();
				} // Foobar alive and playing

				// Clears, draws and displays everything on the GameWindow
				GameWindow.clear();
				GameWindow.draw(Background);
				draw_track(track, GameWindow);
				GameWindow.draw(timerText);
				GameWindow.draw(timerInfo);
				GameWindow.draw(scoreText);
				GameWindow.draw(scoreInfo);
				GameWindow.draw(postgame_text);
				GameWindow.display();

				// If Timer has hit 0
				if (time_up) 
				{
					// Changes text and plays music only once
					if (first_time) 
					{
						postgame_text.setString("Time Up");
						background_music.stop();
						game_over_sound.setVolume(game_volume);
						game_over_sound.play();
						first_time = !first_time;
					}
				}
				// Foobar have died enemy, projectile or fallen off the map
				else if (track->get_foobar()->is_dead()) 
				{
					if (first_time)
					{
						postgame_text.setString("Game Over");
						background_music.stop();
						foobar_dies_sound.setVolume(game_volume);
						foobar_dies_sound.play();
						first_time = !first_time;
					}
				}
				// Foobar have reached the finish line
				else if (track->is_end_of_game()) 
				{
					// Writes score to a txt file only once
					if (first_time) 
					{
						postgame_text.setString("There");
						(track->get_scoreboard()).write(std::to_string(static_cast<int>((track->get_timer()).get_time_remaining() + (track->get_score()).get_score())));
						background_music.stop();
						finish_line_sound.setVolume(game_volume);
						finish_line_sound.play();
						first_time = !first_time;
					}
				}
			}
			else  //utanf�r event, inte klickat p� play game = main menu
			{
				GameWindow.clear();
				GameWindow.draw(main_menu_background);
				GameWindow.draw(scoreboard_text);
				GameWindow.display();
			}
		} // Window is open
	} // Try
	catch (std::exception& e)
	{
		std::cout << e.what() << "M�ste g�ra en foobar!";
	}
} // Main