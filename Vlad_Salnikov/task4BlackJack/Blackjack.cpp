#include <iostream>
#include <vector>
#include <string>
#include "Player.h"
#include <algorithm>
using namespace std;

const int blackjack{ 21 };
const int firstDeal{ 2 };
const int minDealerValue{ 17 };
const int highСard{ 10 };
const int aceValue{ 11 };

int valueCounter(const vector<string>& hand)
{
	int valueBuffer{0};
	for (auto n: hand)
	{
		if (n == "Jack" || n == "Queen" || n == "King")
		{
			valueBuffer += highСard;
		}
		else if (n == "Ace")
		{
			valueBuffer += aceValue;
		}else 
			valueBuffer += stoi(n);
	}
	return valueBuffer;
}
int input(int num)
{
	std::cin >> num;
	while (std::cin.fail())
	{
		std::cout << "Incorrect type\n";
		std::cin.clear();
		std::cin.ignore(100000000, '\n');
		std::cin >> num;
	}
	return num;
}

int main()
{
	Player dealer("Tom");
	Player player;

	while (true)
	{
		bool checkEndGame = false;
		vector <string> deck{
	     "2","3","4","5","6","7","8","9","10","Jack","Queen","King","Ace",
	     "2","3","4","5","6","7","8","9","10","Jack","Queen","King","Ace",
	     "2","3","4","5","6","7","8","9","10","Jack","Queen","King","Ace",
	     "2","3","4","5","6","7","8","9","10","Jack","Queen","King","Ace" };
		random_shuffle(deck.begin(), deck.end());

		dealer.resetHand();
		dealer.resetValue();
		player.resetHand();
		player.resetValue();

		for (int i = 0; i < firstDeal; i++)
		{
			dealer.setHand(deck.back());
			deck.pop_back();
			player.setHand(deck.back());
			deck.pop_back();
		}

		while (true)
		{
			system("cls");
			cout << "Dealer " << dealer.getName() << ':' << endl;
			cout << "Hand:";
			for (auto n: dealer.getHand())
			{
				cout << '|' << n << '|' << ' ';
				break;
			}
			cout << '|' << '?' << '|' << ' ' << endl;
			cout << "Value:" << "Unknown" << endl;

			cout << "Player " << player.getName() << ':' << endl;
			cout << "Hand:";
			for (auto n : player.getHand())
			{
				cout << '|' << n << '|' << ' ';
			}
			cout << "\nValue:";
			player.resetValue();
			player.setValue(valueCounter(player.getHand()));
			cout << player.getValue() << endl;

			if (player.getValue() > blackjack)
			{
				cout << "You lose!" << endl;
				checkEndGame = true;
				break;
			}
			else if (player.getValue() == blackjack)
			{
				cout << "You win!" << endl;
				checkEndGame = true;
				break;
			}

			cout << "Enter 1 for Hit, or 2 for Stand, enter 0 to exit game" << endl;
			int choice{0};
			choice = input(choice);
			if (choice == 2)
			{
				break;
			}
			else if (choice == 0)
			{
				return 0;
			}

			player.setHand(deck.back());
			deck.pop_back();
		}

		if (checkEndGame)
		{
			cout << "For a new game enter 1, for exit enter 0" << endl;
			int newGameChoice{ 0 };
			newGameChoice = input(newGameChoice);
			while (newGameChoice != 0 && newGameChoice != 1)
			{
				cout << "Incorrect input" << endl;
				newGameChoice = input(newGameChoice);
			}
			if (newGameChoice == 1)
			{
				continue;
			}
			else if (newGameChoice == 0)
			{
				return 0;
			}
		}

		while (true)
		{
			system("cls");
			cout << "Dealer " << dealer.getName() << ':' << endl;
			cout << "Hand:";
			for (auto n : dealer.getHand())
			{
				cout << '|' << n << '|' << ' ';
			}
			cout << "\nValue:";
			dealer.resetValue();
			dealer.setValue(valueCounter(dealer.getHand()));
			cout << dealer.getValue() << endl;

			cout << "Player " << player.getName() << ':' << endl;
			cout << "Hand:";
			for (auto n : player.getHand())
			{
				cout << '|' << n << '|' << ' ';
			}
			cout << "\nValue:";
			cout << player.getValue() << endl;

			if (dealer.getValue() > blackjack)
			{
				cout << "You win!" << endl;
				checkEndGame = true;
				break;
			}
			else if (dealer.getValue() >= minDealerValue)
			{
				break;
			}
			else if (dealer.getValue() == blackjack)
			{
				cout << "You lose!" << endl;
				checkEndGame = true;
				break;
			}

			dealer.setHand(deck.back());
			deck.pop_back();
		}

		if (!checkEndGame)
		{
			if (dealer.getValue() > player.getValue())
			{
				cout << "You lose!" << endl;
				checkEndGame = true;
			}
			else
			{
				cout << "You win!" << endl;
				checkEndGame = true;
			}
		}

		if (checkEndGame)
		{
			cout << "For a new game enter 1, for exit enter 0" << endl;
			int newGameChoice{ 0 };
			newGameChoice = input(newGameChoice);
			while (newGameChoice != 0 && newGameChoice != 1)
			{
				cout << "Incorrect input" << endl;
				newGameChoice = input(newGameChoice);
			}
			if (newGameChoice == 1)
			{
				continue;
			}
			else if (newGameChoice == 0)
			{
				return 0;
			}
		}
	}
}

