#include "Scoreboard.h"

using namespace std;

// Reads txt file and returns a sorted string
string Scoreboard::read()
{
	string sorted_str{};
	string temp_str{};
	vector<int> score_vector{};
	ifstream input("Scoreboard.txt");

	// Coverts highscores to a vector
	while (!input.eof())
	{
		temp_str = "";
		getline(input, temp_str, ' ');
		if (temp_str != "") {
			score_vector.push_back(stoi(temp_str));
		}
	}
	input.close();

	// Sorts vector in descending order
	std::sort(score_vector.begin(), score_vector.end(), greater<int>()); 

	// Vector to string
	for (int i{ (int)score_vector.size() }; i > 0; i--) {
		sorted_str = to_string(score_vector.back()) + " " + sorted_str;
		score_vector.pop_back();
	}

	return sorted_str + " ";
}

std::string Scoreboard::read_top5()
{
	string top_5_str{};
	stringstream ss{ read() };
	for (int i{1}; i <= 5; i++) {
		string temp_str{};
		getline(ss, temp_str, ' ');
		top_5_str = top_5_str + to_string(i) + ". " +  temp_str + " ";
	}
	return top_5_str;
}

// Appends new_score to end of txt file
void Scoreboard::write(string new_score)
{
	// Space to separate highscores
	string new_score_space{ new_score + " " };
	ofstream output;
	
	output.open("Scoreboard.txt", std::ios_base::app);
	output << new_score_space;
	output.close();
}