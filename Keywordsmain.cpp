#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
    char playAgain = 'y';
    do
    {
        enum fields {WORD, HINT, NUM_FIELDS};//creates an enumeration to hold the word and their hints
        const int NUM_WORDS = 10; //denotes how many words are in the list of possible words
        const string WORDS[NUM_WORDS][NUM_FIELDS] =//sets the words and the corresponding hints.
        {
            {"judas", "The most famous betrayer in history."},
            {"enigma", "Code breaker."},
            {"deepthroat", "Famous whistle blower in Watergate."},
            {"spook", "What ghosts do."},
            {"sleeper", "A cell of terrorists."},
            {"mole", "Leak in a department."},
            {"backstab", "What rogues do."},
            {"radical", "Far left or right."},
            {"betray", "Violate confidence."},
            {"operative", "Person in the field."},

        };

        srand(time(NULL)); //

        int guessesMade = 0;
        int hintsUsed = 0;

        cout << "Welcome to the Code Breaker Training Simulation Program for CIA Recruits.\n\n";
        cout << "The current automated programs that the CIA uses to decode enemy transmissions "
             << "have always worked well until recently. Recently the enemy is using single scrambled "
             << "Low-tech keywords to signal other enemies to start attacks which our current code decryption "
             << "programs have not been successful against. Here at the CIA, we are developing a new code breaking "
             << "team which relies on human expertise to detect these low tech scrambled keywords. "
             << "We are turning back the clock with this new team of human code breakers. "
             << "This is your chance to prove you deserve to be on this team.\n\n";

        for (int word = 0; word < 3; word++)// runs the program for 3 words
        {
            int choice = (rand() % NUM_WORDS);// randomly chooses a word from the list
            string theWord = WORDS[choice][WORD];  // word to guess
            string theHint = WORDS[choice][HINT];  // hint for word
            string jumble = theWord;  // jumbled version of word
            int length = jumble.size();//sets the length of the word

            for (int letter=0; letter<length; ++letter)//scrambles the word
            {
                int index1 = (rand() % length);//choses the first letter of the word randomly
                int index2 = (rand() % length);//choses the first second of the word randomly
                char temp = jumble[index1];//creates and sets the first letter in a holder
                jumble[index1] = jumble[index2];//reassigns the first letter to have the value of the second letter
                jumble[index2] = temp;//reassigns the second letter to have the value of the first letter
            }
            cout << "The scrambled word is: " << jumble
                 << "\nEnter 'hint' for a hint.\n"
                 << "Enter 'quit' to quit the game.";

            string guess; // variable to hold the users guess
            cout << "\n\nYour guess: ";
            cin >> guess;
            cout << "\n";

            while ((guess != theWord) && (guess != "quit"))// checks to see if user made a guess that wrong and didn't quit
            {
                if (guess == "hint")// checks to see if the user guessed correctly
                {
                    cout << theHint << "\n";
                    hintsUsed++;//adds to the running total of guesses made
                }
                else
                {
                    cout << "\nSorry, that's not it.\n";
                    guessesMade++;//adds to the running total of guesses made
                }

                cout << "\nYou have made: " << guessesMade << " guess(es)."
                     << "\nYou have made: " << hintsUsed << " hint(s).\n\n"
                     << "The scrambled word is: \n" << jumble << ".\n\nYour guess: ";
                cin >> guess;
            }

            if (guess == theWord)//checks to see if the user guessed correctly
            {
                cout << "\nThat's it!  You guessed it!\n"
                     << "****************************************************\n";
                guessesMade++;//adds to the running total of guesses made
            }
            if (guess == "quit" || guess == "Quit")//checks to see if the user wants to quit
            {
                exit(0);//exits the console
            }
        }

        cout << "\nThanks for playing.\nIt took you " << guessesMade << " guesses to get all three code words.\n"
             << "It took you " << hintsUsed << " hint(s) to guess.\n\n"
             << "Would you like to try again? (Y/N) \n";
        cin >> playAgain;
    } while (playAgain == 'y' || playAgain == 'Y'); //will restart the game if the user wants to
    system("pause");
    return 0;
}

