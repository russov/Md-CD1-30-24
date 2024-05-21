#include <iostream>
#include <vector>
#include <ctime>
#include <string>

using namespace std;

double getRandomCard(vector<double>& cards) {

	auto card = cards[rand() % cards.size()];

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

	double j = 10.1;
	double q = 10.2;
	double k = 10.3;
	double a = 11.0;

	int cardDig = 10;

 if (fabs(card - j) <= fmax(fabs(card), fabs(j))*DBL_EPSILON) return "J";
 else if (fabs(card - q) <= fmax(fabs(card), fabs(q)) * DBL_EPSILON) return "Q";
 else if (fabs(card - k) <= fmax(fabs(card), fabs(k)) * DBL_EPSILON) return "K";
 else if (fabs(card - a) <= fmax(fabs(card), fabs(a)) * DBL_EPSILON) return "A";
 else if (int(card) <= 10) return to_string(int(card));
}

void getWin(string person, int rezDealer, int rezPlayer) {
	cout << "The " << person << " Win :" << endl;
	cout << "Dealer : " + to_string(rezDealer) + " points" << endl;
	cout << "Player : " + to_string(rezPlayer) + " points" << endl;
}

void getDraw(int rezDealer, int rezPlayer) {
	cout << "A Draw!" << endl;
	cout << "Dealer : " + to_string(rezDealer) + " points" << endl;
	cout << "Player : " + to_string(rezPlayer) + " points" << endl;
}


void main() {
	srand((unsigned int)time(NULL));

	const int checkHit = 1;
	const int checkPick = 2;
	const int dealerMaxPoint = 17;
	const int blackJackAA = 22;
	const int blackJack21=  21;
	

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

	const double firstCardDealer = getRandomCard(cards);
	const double secondCardDealer = getRandomCard(cards);
	int rezDealer = int(firstCardDealer + secondCardDealer);
	bool rezDealerBlackJack = rezDealer == blackJackAA ? true : false;

	const double firstCardPlayer = getRandomCard(cards);
	const double secondCardPlayer = getRandomCard(cards);
	int rezPlayer = int(firstCardPlayer + secondCardPlayer);
	bool rezPlayerBlackJack = rezPlayer == blackJackAA ? true : false;

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

		if (pick != int(pick) || (pick != checkHit && pick != checkPick) || !cin) {
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			cout << "ENTER ERROR NUMBER" << endl;
			continue;
		}

		if (pick == checkHit) {
			hitCardPlayer = getRandomCard(cards);
			rezPlayer += int(hitCardPlayer);
			outTextPlayer += "\t|" + getAnimationCard(hitCardPlayer) + "|";
			cout << outTextPlayer << endl << endl;
		}
		else if (pick == checkPick) {
			stand = true;

			while (game == true) {

				if (rezDealer >= dealerMaxPoint) {
					cout << outTextDealer << endl << endl;
					game = false;
				}

				if (rezDealer < dealerMaxPoint) {
					cout << outTextDealer << endl << endl;

					hitCardDealer = getRandomCard(cards);
					rezDealer += int(hitCardDealer);
					outTextDealer += "\t|" + getAnimationCard(hitCardDealer) + "|";

					if (rezDealer >= dealerMaxPoint) {
						cout << outTextDealer << endl << endl;
						game = false;
					}
				}
			}
		}

		if (rezPlayer >= blackJackAA && rezPlayerBlackJack == false) {
			cout << "The player loser :" + to_string(int(rezPlayer)) + " points" << endl;
			break;
		}

		if (rezDealer >= blackJackAA) {
			getWin("Player", rezDealer, rezPlayer);
			break;
		}

		if ((blackJack21 == (rezDealer < blackJackAA)) || rezDealerBlackJack == true) {
			getWin("Dealer", blackJack21, rezPlayer);
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
