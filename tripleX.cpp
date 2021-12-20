#include <iostream>
#include <ctime>

void PrintIntroduction(int LevelDifficulty)
{
	// Print welcome messages to start game
	std::cout << "\n\n<<<<<<<<<<<<<<<<<<<<|[|]|>>>>>>>>>>>>>>>>>>>>\n\n";
	std::cout << "You are a secret agent breaking into a level " << LevelDifficulty;
	std::cout << " secure server room\nEnter the correct code to continue...\n\n";
	std::cout << "  -------\n";
	std::cout << "  |1 2 3|\n";
	std::cout << "  |4 5 6|\n";
	std::cout << "  |7 8 9|\n";
	std::cout << "  |* 0 #|\n";
	std::cout << "  -------\n\n";
}

bool PlayGame(int LevelDifficulty)
{
	PrintIntroduction(LevelDifficulty);

	// Declare our code
	const int CodeA = rand() % LevelDifficulty + LevelDifficulty;
	const int CodeB = rand() % LevelDifficulty + LevelDifficulty;
	const int CodeC = rand() % LevelDifficulty + LevelDifficulty;

	const int CodeSum = CodeA + CodeB + CodeC;
	const int CodeProduct = CodeA * CodeB * CodeC;

	// Print results
	std::cout << std::endl;
	std::cout << "There are 3 numbers in the code";
	std::cout << "\nThe codes add up to a total of: " << CodeSum;
	std::cout << "\nThe numbers multiply to a total of: " << CodeProduct;
	std::cout << std::endl << std::endl;

	// store player guess
	int GuessA, GuessB, GuessC;
	std::cin >> GuessA >> GuessB >> GuessC;

	// validate player guess
	int GuessSum = GuessA + GuessB + GuessC;
	int GuessProduct = GuessA * GuessB * GuessC;

	// print guess results
	if (GuessSum == CodeSum && GuessProduct == CodeProduct)
	{
		std::cout << "\n\nYou found the right code! You enter the server room. You're a winner!\n";
		return true;
	}
	else {
		std::cout << "\n\nImmediately upon entering the incorrect code, omninus warning beeps sound. Try again.\n";
		return false;
	}

}

int main()
{
	srand(time(NULL));  // create new random sequence

	const int MaxLevels = 5;
	const int NumberOfTries = 5;
	int LevelDifficulty = 1;
	int Tries = 1;

	while (LevelDifficulty <= MaxLevels && Tries <= NumberOfTries)
	{
		bool bLevelComplete = PlayGame(LevelDifficulty);
		std::cin.clear(); // clear any error
		std::cin.ignore(); // empty buffer

		if (bLevelComplete) {
			++LevelDifficulty;
		}
		else {
			++Tries;
		}
	}
	if (Tries <= MaxLevels) {
		std::cout << "You have mastered all levels. Congratulations, you are an expert secret agent!";
	}
	else {
		std::cout << "The owners of the server room have been alterted to your clumsy attempts at access\n\n";
		std::cout << "Searing flames descend from openings that appeared in the ceiling. You have died a horrible and painful death.\n\nYou lose";
	}

	return 0;
}