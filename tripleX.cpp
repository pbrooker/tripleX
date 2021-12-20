#include <iostream>

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
	const int CodeA = 4;
	const int CodeB = 8;
	const int CodeC = 6;

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
		std::cout << "\n\nImmediately upon entering the incorrect code, the hallway is exposed to searing flames. You have died a horrible and painful death.\n";
		return false;
	}

}

int main()
{
	int LevelDifficulty = 1;
	while (true)
	{
		bool bLevelComplete = PlayGame(LevelDifficulty);
		std::cin.clear(); // clear any error
		std::cin.ignore(); // empty buffer

		if (bLevelComplete) {
			++LevelDifficulty;
		}
	}

	return 0;
}