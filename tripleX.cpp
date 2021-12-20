#include <iostream>

int main()
{
	// Print welcome messages to start game
	std::cout << "You are a secret agent breaking into a secure server room";
	std::cout << std::endl;
	std::cout << "Enter the correct code to continue...";

	// Declare our code
	const int CodeA = 4;
	const int CodeB = 8;
	const int CodeC = 6;

	const int CodeSum = CodeA + CodeB + CodeC;
	const int CodeProduct = CodeA * CodeB * CodeC;

	// Print results
	std::cout << std::endl;
	std::cout << "There are 3 numbers in the code" << std::endl;
	std::cout << "The codes add up to a total of: " << CodeSum << std::endl;
	std::cout << "The numbers multiply to a total of: " << CodeProduct << std::endl;

	// store player guess
	int GuessA, GuessB, GuessC;
	std::cin >> GuessA >> std::cin >> GuessB >> std::cin >> GuessC;

	// validate player guess
	int GuessSum = GuessA + GuessB + GuessC;
	int GuessProduct = GuessA * GuessB * GuessC;

	// print guess results
	if (GuessSum == CodeSum && GuessProduct == CodeProduct)
	{
		std::cout << "You found the right code! You enter the server room. You're a winner!";
	} else {
		std::cout << "Immediately upon entering the incorrect code, the hallway is exposed to searing flames. You have died a horrible and painful death.";
	}

	return 0;
}