#include<iostream>
#include <vector>

struct Card
{
	char value;
	int quantity;
	int score;
};
constexpr int n{ 13 };
constexpr int same_rank{ 4 };
constexpr int ten_value{ 10 };
constexpr int max_vallue{ 11 };

Card* NewDeck()
{
	Card* deck{ new Card[n] };

	// card    2 3 4 5 6 7 8 9 10 J Q  K  T
	// i       0 1 2 3 4 5 6 7 8  9 10 11 12

	for (int i = 0; i < n; i++)
	{
		deck[i].quantity = same_rank;
		if (i < 8)
		{
			deck[i].value = i + 2 + '0';
			deck[i].score = 2 + i;
		}
		else if (i == 8)
		{
			deck[i].value = '1';
			deck[i].score = ten_value;
		}
		else if (i == 9)
		{
			deck[i].value = 'J';
			deck[i].score = ten_value;
		}
		else if (i == 10)
		{
			deck[i].value = 'Q';
			deck[i].score = 10;
		}
		else if (i == 11)
		{
			deck[i].value = 'K';
			deck[i].score = ten_value;
		}
		else if (i == 12)
		{
			deck[i].value = 'T';
			deck[i].score = max_vallue;
		}
	}
	std::cout << '\n';
	return deck;
}

void SayHi()
{
	static int k = 0;
	std::cout << "\n";
	if (k == 0) std::cout << "Hello player! Let's play Blacj-Jack!";
	else std::cout << "Hello player! You are playing Black-Jack for the " << k + 1 << " time!";
	std::cout << "\n";
	k++;
}

int main()
{
	do
	{
		SayHi();
		std::srand(time(0));
		Card* deck = NewDeck();
		std::vector<int> player{}, dealer{};
		auto scPlayer{ 0 }, scDealer{ 0 };
		int cardPl, cardDl1, cardDl2;
		int k = 1, size = 1;

		cardPl = std::rand() % n;
		cardDl1 = std::rand() % n;
		cardDl2 = std::rand() % n;

		for (int i = 0; i < n; ++i)
		{
			if (i == cardPl)
			{
				player.push_back(i);
				deck[i].quantity--;
				scPlayer += deck[i].score;
			}
			if (i == cardDl1)
			{
				dealer.push_back(i);
				deck[i].quantity--;
				scDealer += deck[i].score;
			}
			if (i == cardDl2) deck[i].quantity--;
		}

		std::cout << "--------------------------------\n";
		std::cout << "Your cards:\tDealer's cards:\n";
		std::cout << deck[cardPl].value;
		if (deck[cardPl].value == '1') std::cout << '0';
		std::cout << "\t\t" << deck[cardDl1].value << '\n';
		if (deck[cardDl1].value == '1') std::cout << '0';
		std::cout << "Your score:\tDealer's score\n";
		std::cout << scPlayer << "\t\t" << scDealer << '\n';
		std::cout << "--------------------------------\n\n";

		while (k)
		{
			std::cout << "To take card, enter 1. To end game, enter 0\n";
			std::cin >> k;
			if (k == 0) break;
			else if (k != 1) continue;
			size++;
			cardPl = std::rand() % n;
			while (deck[cardPl].quantity == 0)
			{
				cardPl = std::rand() % n;
			}

			player.push_back(cardPl);
			deck[cardPl].quantity--;
			scPlayer += deck[cardPl].score;

			if (scDealer < 17)
			{
				cardDl1 = std::rand() % n;
				while (deck[cardDl1].quantity == 0)
				{
					cardDl1 = std::rand() % n;
				}
				dealer.push_back(cardDl1);
				deck[cardDl1].quantity--;
				scDealer += deck[cardDl1].score;
			}
			else dealer.push_back(13);

			std::cout << "--------------------------------\n";
			std::cout << "Your cards:\tDealer's cards:\n";
			for (int i = 0; i < size; ++i)
			{
				std::cout << deck[player[i]].value;
				if (deck[player[i]].value == '1') std::cout << '0';
				if (dealer[i] < n)
				{
					std::cout << "\t\t" << deck[dealer[i]].value;
					if (deck[dealer[i]].value == '1') std::cout << '0';
				}
				std::cout << '\n';
			}
			std::cout << "Your score:\tDealer's score\n";
			std::cout << scPlayer << "\t\t" << scDealer << '\n';
			std::cout << "--------------------------------\n\n";

			if (scPlayer >= 21 || scDealer >= 21) break;
		}
		if (scDealer < 21 && scPlayer <= 21)
		{
			std::cout << "Dealer's close card:\n" << deck[cardDl2].value;
			scDealer += deck[cardDl2].score;
		}
		delete deck;
		std::cout << "\n\nYour score:\tDealer's score\n";
		std::cout << scPlayer << "\t\t" << scDealer << '\n';
		std::cout << "\n==============\n||";
		if (scPlayer > 21) std::cout << " YOU LOSE ";
		else if (scDealer > 21) std::cout << " YOU  WIN ";
		else if (scPlayer > scDealer) std::cout << " YOU  WIN ";
		else if (scPlayer == scDealer) std::cout << "   DRAW   ";
		else std::cout << " YOU LOSE ";
		std::cout << "||\n==============\n";
		std::cout << "\nEnter 1 to play another time\n";
		int ans;
		std::cin >> ans;
		if (ans != 1) break;
	} while (true);
	std::cout << "Goodbye!";
}