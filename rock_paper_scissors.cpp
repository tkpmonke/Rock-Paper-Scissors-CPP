#include <iostream>
#include <string>
#include <chrono>
#include <thread>

enum Object {
	Rock = 1,
	Paper = 2,
	Scissors = 3
};

std::string otos(Object o)
{
	if (o == Rock) return "Rock";
	if (o == Paper) return "Paper";
	if (o == Scissors) return "Scissors";
	return "";
}

void printwdelay(std::string message)
{
	std::cout << message;
	std::this_thread::sleep_for(std::chrono::seconds(1));
}

#define WIN()   std::cout << "You Win!\n";  \
				return 0;

#define LOSE()   std::cout << "You Lose\n";  \
				return -1;

#define TIE()   std::cout << "Tie\n";  \
				return 0;

int main()
{
	std::cout << "Choose your Object\n\n";

	// Get Input
	std::string s;
	std::cin >> s;
	
	Object type;
	if (s == "Rock" || s == "r" || s == "rock") { type = Rock; }
	else if (s == "Paper" || s == "p" || s == "paper") { type = Paper; }
	else if (s == "Scissors" || s == "s" || s == "scissors") { type = Scissors; }
	else
	{
		std::cout << s << " ain't no object\n";
		return 0;
	}

	time_t current_time = time(NULL);
	srand((unsigned int)current_time);
	Object r = (Object)(1 + (rand() % 3));

	printwdelay("\n\nROCK\n");
	printwdelay("PAPER\n");
	printwdelay("SCISSORS\n");
	printwdelay("SHOOT\n");

	std::cout << otos(type) << " VS " << otos(r) << "\n";

	if (type == r) { TIE(); }
	else if (type == Rock && r == Scissors) { WIN(); }
	else if (type == Scissors && r == Paper) { WIN(); }
	else if (type == Paper && r == Rock) { WIN(); }
	else if (type == Scissors && r == Rock) { LOSE(); }
	else if (type == Rock && r == Paper) { LOSE(); }
	else if (type == Paper && r == Scissors) { LOSE(); }
	
	return 0;
}