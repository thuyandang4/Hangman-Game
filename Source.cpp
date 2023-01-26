#include <iostream>
#include <vector>
using namespace std;

// introduces the game
void greet();

// displays hangman visual
void display_misses(int);

// displays incorrect and correct answers
void display_status(vector<char> incorrect, string);

// displays if user won or lost
void endgame(string, string);


int main()
{
	string codeword = "hangman";
	string answer = "_______";
	int misses = 0;
	vector<char> incorrect; // holds incorrect answers
	bool guess = false;
	char letter;

    greet();

	while (answer != codeword && misses < 7)
	{
		display_misses(misses);
        display_status(incorrect, answer);

        // receive user input
        cout << "Enter your guess: ";
        cin >> letter;

        // runs through codeword to check if guess is correct
        for (int i = 0; i < codeword.length(); i++) // length for string
        {
            if (letter == codeword[i])
            {
                answer[i] = letter; // stores correct guess in answer string
                guess = true;
            }
        }

        if (guess == true)
        {
            cout << "============================" << endl;
            cout << "Correct!" << endl;
        }

        else
        {
            cout << "============================" << endl;
            cout << "Incorrect. A portion of the person has been drawn." << endl;
            incorrect.push_back(letter);    // push_back inserts char into vector, changes size
            misses++;
        }
        guess = false;
	}

    endgame(answer, codeword);

	return 0;
}



void greet()
{
	cout << "=================" << endl;
	cout << "Hangman: The Game" << endl;
	cout << "=================" << endl;
	cout << "Instructions: Save the person from"
		"being hanged by guessing the letters of the unknown word. Good luck! \n";
    cout << endl;
    cout << endl;
}

void display_misses(int misses)
{
	if (misses == 0)
	{
		cout << "  +---+ \n";
		cout << "  |   | \n";
		cout << "  |     \n";
		cout << "  |     \n";
		cout << "  |     \n";
		cout << "  |     \n";
		cout << " ========= \n";
	}

    else if (misses == 1)
    {
        cout << "  +---+ \n";
        cout << "  |   | \n";
        cout << "  |   O \n";
        cout << "  |     \n";
        cout << "  |     \n";
        cout << "  |     \n";
        cout << " ========= \n";
    }
    else if (misses == 2)
    {
        cout << "  +---+ \n";
        cout << "  |   | \n";
        cout << "  |   O \n";
        cout << "  |   | \n";
        cout << "  |     \n";
        cout << "  |     \n";
        cout << " ========= \n";
    }
    else if (misses == 3)
    {
        cout << "  +---+ \n";
        cout << "  |   | \n";
        cout << "  |   O \n";
        cout << "  |  /| \n";
        cout << "  |     \n";
        cout << "  |     \n";
        cout << " ========= \n";
    }
    else if (misses == 4)
    {
        cout << "  +---+ \n";
        cout << "  |   | \n";
        cout << "  |   O \n";
        cout << "  |  /|\\ \n";
        cout << "  |     \n";
        cout << "  |     \n";
        cout << " ========= \n";
    }
    else if (misses == 5)
    {
        cout << "  +---+ \n";
        cout << "  |   | \n";
        cout << "  |   O \n";
        cout << "  |  /|\\ \n";
        cout << "  |  /  \n";
        cout << "  |     \n";
        cout << " ========= \n";
    }
    else if (misses == 6)
    {
        cout << "  +---+ \n";
        cout << "  |   | \n";
        cout << "  |   O \n";
        cout << "  |  /|\\ \n";
        cout << "  |  / \\ \n";
        cout << "  |     \n";
        cout << " ========= \n";
    }
}



void display_status(vector<char> incorrect, string answer)
{
    cout << "Incorrect guesses: " << endl;

    // displays incorrect letters
    for (int i = 0; i < incorrect.size(); i++)  // size for vector
    {
        cout << incorrect[i] << " ";
    }

    cout << endl;

    // displays correct letters in blank space
    cout << "Unknown word:" << endl;
    for (int i = 0; i < answer.length(); i++)
    {
        cout << answer[i] << " ";
    }
    cout << endl;
}

void endgame(string answer, string codeword)
{
    if (answer == codeword)
    {
        cout << "Horray! You just saved the dude from being hanged." << endl;
    }

    else
    {
        cout << "Uh oh! The dude just died. " << endl;
    }
}
