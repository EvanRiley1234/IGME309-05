// Hi Low - Evan.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

int main()
{
    //variables
    bool exit = true;
    int rNum;
    int guess;
    int sentNum = 2;
    int exitNum;
    int numGuesses = 0;
    bool endLoop = true;
    srand(time(NULL));

    //randomize the number
    rNum = rand() % 100 + 1;

    std::cout << "Welcome to Hi Low!\nPlease guess a whole number from 1 to 100.\n";

    //game loop
    while (exit)
    {
        std::cout << "Enter a number (enter -1 to quit): ";
        std::cin >> guess;
        numGuesses++;
        //exit if -1 is entered or if the player won
        if (guess == -1 || guess == rNum)
        {
            if (guess == rNum)
            {
                std::cout << "You won! \nYou had " << numGuesses << " Guesses\n";
            }
            std::cout << "Would you like to play again (enter 1 for yes or 2 for no): ";
            std::cin >> exitNum;
            if (exitNum == sentNum)
            {
                exit = false;
            }
            else if (exitNum == 1)
            {
                //randomize the number
                rNum = rand() % 100 + 1;
                numGuesses = 0;
            }
        }
        //check if the number is higher
        else if (guess > rNum)
        {
            std::cout << "Your guess is higher then the target number\n";
        }
        //check if the number is lower
        else if (guess < rNum)
        {
            std::cout << "Your guess is lower then the target number\n";
        }
        //answer wants a number form 1 to 100
        else
        {
            std::cout << "Your answer wasn't a number from 1 to 100 please try again \n";
            numGuesses--;
        }
    }

    
}
