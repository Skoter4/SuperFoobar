#include "Scoreboard.h"

using namespace std;

string Scoreboard::read()
{
	string str{};
	ifstream input ("Scoreboard.txt");
	while (!input.eof())
	{
		getline(input, str);
	}
	input.close();
	return str;
}

void Scoreboard::write(string new_str)
{
	string current_str = read();
	ofstream output ("Scoreboard.txt");
	output << current_str << new_str << " ";
	output.close();
}

/*

void Scoreboard::sort()
{

}

*/