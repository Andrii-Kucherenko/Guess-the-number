//Guess the number
#include <iostream>
#include <ctime>
#include <string>
#include <sstream>
#include <cctype>

bool theNumberIsCorrect(const std::string& string)
{
    if (string.size() != 3)
    {
        return false;
    }

    for (int i = 0; i < string.size(); ++i)
    {
        if (!std::isdigit(string[i]))
        {
            return false;
        }
    }

    return true;
}

void compareGuessingAndNumber(const int original, const int guessed, bool& guess)
{
    int counterDigit = 0;
    int counterPlace = 0;

    int originalArr[3]{ original / 100, original % 100 / 10, original % 10 };
    int guessedArr[3]{ guessed / 100, guessed % 100 / 10, guessed % 10 };

    for (int i = 0; i < 3; ++i)
    {
        if (originalArr[i] == guessedArr[i])
        {
            ++counterPlace;
        }
    }

    for (int i = 0; i < 3; ++i)
    {
        for (int j = 0; j < 3; ++j)
        {
            if (guessedArr[i] == originalArr[j])
            {
                ++counterDigit;
                originalArr[j] = -1;
                break;
            }
        }
    }

    std::cout << "Guessed: " << counterDigit << ". In their place: " << counterPlace << '\n';

    if (original == guessed)
    {
        guess = true;
        return;
    }
}

int main()
{
    srand(time(0));
    int number = rand() % 900 + 100;

    std::cout << "\tThe computer guessed a three-digit number. "
        << "You have to guess it. After the next number, "
        << "you will be informed how many numbers were guessed and how many of them are in their places.\n";

    bool isGuessed = false;
    std::string guessing;

    do
    {
        std::cout << "Your option: ";
        std::cin >> guessing;

        if (!theNumberIsCorrect(guessing))
        {
            std::cout << "Incorrect input! Try again.\n";
            continue;
        }

        std::stringstream guessingStream(guessing.c_str());
        int guessingNumber;
        guessingStream >> guessingNumber;

        compareGuessingAndNumber(number, guessingNumber, isGuessed);

    } while (!isGuessed);

    std::cout << "***You guessed the number " << number << "!***\n";

    return 0;
}