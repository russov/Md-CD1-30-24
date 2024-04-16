#include <iostream>
#include <vector>
#include <ctime>
#include <string>

using namespace std;

double getRandomCard(vector<double>& cards) {

	double card = cards[rand() % cards.size()];

	for (int y = 0; y < cards.size(); y++)
	{
		if (cards[y] == card) {
			cards.erase(cards.begin() + y);
			break;
		}
	}

	return card;
}

string getAnimationCard(double card) {
	if (card == 10.1) return "J";
	else if (card == 10.2) return "Q";
	else if (card == 10.3) return "K";
	else if (card == 11) return "A";
	else if (card <= 10) return to_string(int(card));
}

void getWin(string person, double rezDealer, double rezPlayer) {
	cout << "The " << person << " Win :" << endl;
	cout << "Dealer : " + to_string(int(rezDealer)) + " points" << endl;
	cout << "Player : " + to_string(int(rezPlayer)) + " points" << endl;
}

void getDraw(double rezDealer, double rezPlayer) {
	cout << "A Draw!" << endl;
	cout << "Dealer : " + to_string(int(rezDealer)) + " points" << endl;
	cout << "Player : " + to_string(int(rezPlayer)) + " points" << endl;
}


void main() {
	srand(time(0));

	vector<double>cards =
	{
		2,2,2,2,
		3,3,3,3,
		4,4,4,4,
		5,5,5,5,
		6,6,6,6,
		7,7,7,7,
		8,8,8,8,
		9,9,9,9,
		10,10,10,10,
		10.1,10.1,10.1,10.1,
		10.2,10.2,10.2,10.2,
		10.3,10.3,10.3,10.3,
		11,11,11,11
	};

	double firstCardDealer = getRandomCard(cards);
	double secondCardDealer = getRandomCard(cards);
	int rezDealer = int(firstCardDealer + secondCardDealer);
	bool rezDealerBlackJack = rezDealer == 22 ? true : false;

	double firstCardPlayer = getRandomCard(cards);
	double secondCardPlayer = getRandomCard(cards);
	int rezPlayer = int(firstCardPlayer + secondCardPlayer);
	bool rezPlayerBlackJack = rezPlayer == 22 ? true : false;

	bool stand = false;

	string outTextDealer = "cards Dealer : |" + getAnimationCard(firstCardDealer) + "|\t|" + getAnimationCard(secondCardDealer) + "|";
	string outTextPlayer = "cards Player : |" + getAnimationCard(firstCardPlayer) + "|\t|" + getAnimationCard(secondCardPlayer) + "|";

	cout << "\t Blackjack" << endl << endl;
	cout << "cards Dealer : |" + getAnimationCard(firstCardDealer) + "|\t|*|" << endl;
	cout << outTextPlayer << endl << endl;


	while (true) {
		double hitCardPlayer{ 0 };
		double hitCardDealer{ 0 };
		bool game = true;
		double pick{ 0 };

		cout << "1: hit 2: stand : ";

		cin >> pick;

		if (pick != int(pick) || (pick != 1 && pick != 2) || !cin) {
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			cout << "ENTER ERROR NUMBER" << endl;
			continue;
		}

		if (pick == 1) {
			hitCardPlayer = getRandomCard(cards);
			rezPlayer += hitCardPlayer;
			outTextPlayer += "\t|" + getAnimationCard(hitCardPlayer) + "|";
			cout << outTextPlayer << endl << endl;
		}
		else if (pick == 2) {
			stand = true;

			while (game == true) {

				if (rezDealer >= 17) {
					cout << outTextDealer << endl << endl;
					game = false;
				}

				if (rezDealer < 17) {
					cout << outTextDealer << endl << endl;

					hitCardDealer = getRandomCard(cards);
					rezDealer += hitCardDealer;
					outTextDealer += "\t|" + getAnimationCard(hitCardDealer) + "|";

					if (rezDealer >= 17) {
						cout << outTextDealer << endl << endl;
						game = false;
					}
				}
			}
		}

		if (rezPlayer >= 22 && rezPlayerBlackJack == false) {
			cout << "The player loser :" + to_string(int(rezPlayer)) + " points" << endl;
			break;
		}

		if (rezDealer >= 22) {
			getWin("Player", rezDealer, rezPlayer);
			break;
		}

		if (21 == rezDealer < 22 || rezDealerBlackJack == true) {
			getWin("Dealer", 21.0, rezPlayer);
			break;
		}

		if (rezPlayerBlackJack == true && rezDealerBlackJack == true) {
			getDraw(rezDealer, rezPlayer);
			break;
		}

		if (rezPlayer == rezDealer && stand == true) {
			getDraw(rezDealer, rezPlayer);
			break;
		}

		if (rezPlayer < rezDealer && stand == true) {
			getWin("Dealer", rezDealer, rezPlayer);
			break;
		}

		if (rezDealer < rezPlayer && stand == true) {
			getWin("Player", rezDealer, rezPlayer);
			break;
		}
	}
}
