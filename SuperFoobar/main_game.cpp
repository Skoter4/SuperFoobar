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
		// initiering av texturerna
		::SUPER_FOOBAR_TEXTURES.loadFromFile("Pictures/AllTextures.png");

		// Bakgrundsmusik och ljud
		float game_volume{ 10.0f };

		sf::Music background_music;
		background_music.openFromFile("Sounds/smb_theme.wav");
		background_music.setLoop(true);
		background_music.setVolume(game_volume);

		// xxx_sound.play() för att spela ljuden
		// xxx_sound.setVolume(game_volume); 
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

		// Trappor
		block_list + make_one_line_breakable_seg(3, 130, 10) + make_one_line_breakable_seg(2, 131, 9) + make_one_line_breakable_seg(1, 132, 8) +
			make_one_line_breakable_seg(3, 135, 10) + make_one_line_breakable_seg(2, 135, 9) + make_one_line_breakable_seg(1, 135, 8) +
			make_one_line_breakable_seg(4, 142, 10) + make_one_line_breakable_seg(3, 143, 9) + make_one_line_breakable_seg(2, 144, 8) +
			make_one_line_breakable_seg(3, 148, 10) + make_one_line_breakable_seg(2, 148, 9) + make_one_line_breakable_seg(1, 148, 8) +
			make_one_line_breakable_seg(9, 167, 10) + make_one_line_breakable_seg(8, 168, 9) + make_one_line_breakable_seg(7, 169, 8) +
			make_one_line_breakable_seg(6, 170, 7) + make_one_line_breakable_seg(5, 171, 6) + make_one_line_breakable_seg(4, 172, 5) +
			make_one_line_breakable_seg(3, 173, 4) + make_one_line_breakable_seg(2, 174, 3);

		character_list + make_foobar() + make_enemy_1(15, 10) + make_enemy_3(35, 10) + make_enemy_3(48, 10) + make_enemy_3(50, 10) +
			make_enemy_3(90, 10) + make_enemy_3(92, 10) + make_enemy_3(107, 10) + make_enemy_3(109, 10)
			+ make_enemy_2(100, 10) + make_enemy_1(162, 6) + make_enemy_1(163, 10);

		interactable_list + make_Finish_Line(185, 10);

		std::shared_ptr<Track> track{ make_track(block_list, character_list, interactable_list) };
		init_sprite(track);

		//Skapa spelfönstret
		sf::ContextSettings settings;
		settings.antialiasingLevel = 8;

		sf::RenderWindow GameWindow(sf::VideoMode(16 * 70, 12 * 70), "TEST");

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
		bool first_time{ true }; // Förhindrar att kvarvarande tid adderas till score flera gånger vid game-over

		sf::Event event;

		sf::View view(sf::FloatRect(0, 0, 16 * 70, 12 * 70));
		GameWindow.setView(view);

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
						if ((Mouse_x > 233 && Mouse_x < 553) && (Mouse_y > 429 && Mouse_y < 516)) { // Clicked play game
							if (!play_game) {
								play_game = true;
								Timer new_timer{};
								track->set_timer(new_timer);
								background_music.play();
							}
						}
						else if ((Mouse_x > 562 && Mouse_x < 883) && (Mouse_y > 429 && Mouse_y < 516)) { // Clicked show scoreboard
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
				} // event mouse

				if (play_game) { // innanför event, om man klickat play_game
					if (event.type == sf::Event::KeyPressed)
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
								jump_small_sound.setVolume(game_volume);
								jump_small_sound.play();
							}
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
			}  // event

			if (play_game) { // utanför event, om man klickat play_game

				track->get_foobar()->set_y_velocity(track->get_foobar()->get_y_velocity() + track->get_foobar()->get_gravity());

				track->get_foobar()->move_x(track->get_foobar()->get_x_velocity());
				track->get_foobar()->move_y(track->get_foobar()->get_y_velocity());

				float f_time = track->get_timer().get_time_remaining();
				int i_time = round(f_time);
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

				for (auto it = track->get_character_list().begin(); it != track->get_character_list().end(); ++it)
				{
					if ((*it)->type_str() != "foobar" && (*it)->type_str() != "enemy_1")
					{
						if ((*it)->type_str() != "foobar" && (*it)->type_str() == "projectile") {
							(*it)->move_x((*it)->get_x_velocity());
							block_collision(track->get_foobar(), *it);
							for (auto it2 = track->get_block_list().begin(); it2 != track->get_block_list().end(); ++it2)
							{
								block_collision(*it, *it2);
							}
						}
						else {
							(*it)->move_x((*it)->get_x_velocity());
							(*it)->move_y((*it)->get_y_velocity());
							block_collision(track->get_foobar(), *it);
							for (auto it2 = track->get_block_list().begin(); it2 != track->get_block_list().end(); ++it2)

							{
								block_collision(*it, *it2);
							}
						}
					}
				}

				for (auto it = track->get_block_list().begin(); it != track->get_block_list().end(); ++it)
				{
					block_collision(track->get_foobar(), *it);
				}

				for (auto it = track->get_interactable_list().begin(); it != track->get_interactable_list().end(); ++it)
				{
					block_collision(track->get_foobar(), *it);
				}

				for (auto it = track->get_character_list().begin(); it != track->get_character_list().end(); ++it)
				{
					block_collision(track->get_foobar(), *it);
				}

				GameWindow.clear();
				GameWindow.draw(Background);
				draw_track(track, GameWindow);
				GameWindow.draw(timerText);
				GameWindow.draw(timerInfo);
				GameWindow.draw(scoreText);
				GameWindow.draw(scoreInfo);
				GameWindow.draw(postgame_text);
				GameWindow.display();

				if (time_up) { // Time-up or death
					if (first_time) {
						postgame_text.setString("Time Up");
						background_music.stop();
						game_over_sound.setVolume(game_volume);
						game_over_sound.play();
						first_time = !first_time;
					}
				}
				else if (track->get_foobar()->is_dead()) {
					if (first_time) {
						postgame_text.setString("Game Over");
						background_music.stop();
						foobar_dies_sound.setVolume(game_volume);
						foobar_dies_sound.play();
						first_time = !first_time;
					}
				}
				else if (track->is_end_of_game()) { // Finish_line
					if (first_time) {
						postgame_text.setString("gg");
						(track->get_scoreboard()).write(std::to_string(static_cast<int>((track->get_timer()).get_time_remaining() + (track->get_score()).get_score())));
						background_music.stop();
						finish_line_sound.setVolume(game_volume);
						finish_line_sound.play();
						first_time = !first_time;
					}
				}
				else { // utanför event, man har klickat play game, man är inte död/slut på tid
					//Timer countdown
					if ((track->get_timer()).get_time_remaining() > 0.0f)
					{
						if (static_cast<int>((track->get_timer()).get_time_remaining()) == 60) {
							time_warning_sound.setVolume(game_volume);
							time_warning_sound.play();
						}
						(track->get_timer()).countdown();
						timerText.setString(std::to_string(static_cast<int>((track->get_timer()).get_time_remaining())));
					}
					else {
						time_up = true; // Timer hits 0 => game-over
					}

					//Så att kameran följer med Foobar men inte går till vänster om start-position
					int camera_x = track->get_foobar()->get_x_pos();

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

					update_sprite(track);
					scoreText.setString(std::to_string(static_cast<int>(track->get_score().get_score())));
					track->handle_map_object_flags();
				}
			}
			else { //utanför event, inte klickat på play game = main menu
				GameWindow.clear();
				GameWindow.draw(main_menu_background);
				GameWindow.draw(scoreboard_text);
				GameWindow.display();
			}
		} // window is open
	} // try
	catch (std::exception& e)
	{
		std::cout << e.what() << "Måste göra en foobar!";
	}
} // main