//Proggram code for a game "Unravel the word".
//The computer gives user a "confusing" word and user should unravel it.
//Console-prog
//By Viktor Sadovyi

#include <iostream>
#include <vector>
#include <string>
#include <ctime>
#include <algorithm>

using namespace std;

#define EASY_POINTS 100
#define NORMAL_POINTS 200

int Points(int);

void main()
{
	cout << "----Welcome my dear friend! Today you ll get a challenge. Interested?----\n";
	char k;
	do
	{
		cout << "y/n: ";
		cin >> k;

	} while (k != 'y' && k != 'n');
	if (k == 'n')
	{
		cout << "\nGood bye!!!\n";
		system("pause");
		return;
	}
	cout << "Okay! Let's start the game." << endl;

	vector<string> WORDS = { "plane"  , "mother", "violet", "car", "computer", "explorer", "sister", "fridge",
		"boy","window","dog"};
	enum coef { EASY, NORMAL };

	srand(static_cast<unsigned int>(time(0)));

	string secret;
	string answer;
	int POINTS = 0;

	do
	{
		if (WORDS.empty())
		{
			cout << "\nThere is no words left. Sorry!\n";
			break;
		}
		random_shuffle(WORDS.begin(), WORDS.end());
		secret = WORDS[0];
		for (int i = 0; i < secret.length(); i++)
		{
			int j = rand() % secret.length();
			char tmp = secret[i];
			secret[i] = secret[j];
			secret[j] = tmp;
		}
		cout << "Here is the word: " << secret << ".\nYour answer: ";
		cin >> answer;
		if (answer == WORDS[0])
		{
			cout << "Well done! You got +" << Points(WORDS[0].length()<4 ? EASY : NORMAL) << " points.\n";
			cout << "Your points now: " << (POINTS += Points(WORDS[0].length() < 4 ? EASY : NORMAL)) << ".\n";
			WORDS.erase(WORDS.begin());
		}
		else cout << "Wrong answer. Try better this time.\n";
		try {
			cout << "\nAre you sure to go on??\n(y/n): ";
			cin >> k;
			if (k != 'y' && k != 'n') throw 0;
		}
		catch (int)
		{
			cout << "\n\nFail input!\nProgram ends.\n\n";
			system("pause");
			return;
		}

	} while (k != 'n');

	cout << "Your final score is: " << POINTS << ".\nGood bye.\n";
	system("pause");
}

int Points(int c)
{
	return c == 0 ? EASY_POINTS : NORMAL_POINTS;
}