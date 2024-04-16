#include <iostream>
#include <vector>

#define CARD_DECK_BLACKJACK 2,2,2,2,3,3,3,3,4,4,4,4,6,6,6,6,7,7,7,7,8,8,8,8,9,9,9,9,10,10,10,10,11,11,11,11

enum BlackJackMoves
{
	START_GAME,
	HIT_PLAYER,
	STAND_PLAYER,
	HIT_DILLER,
	STAND_DILLER,
	END_GAME
};

int getCard(std::vector<int> &card_deck)
{
		srand(time(NULL));
		int index = rand() % card_deck.size();
		int rand_card = card_deck[index];
		card_deck.erase(card_deck.begin() + index);
		return rand_card;
}

void runDialog(BlackJackMoves &move)
{
	std::cout << "ИГРОК, ВЗЯТЬ еще (yes/no)? ";
	std::string answer("");
	while (!(answer == "yes" || answer == "no"))
	{
		std::cin >> answer;
		if (answer == "yes")
			move = BlackJackMoves::HIT_PLAYER;
		else if (answer == "no")
			move = BlackJackMoves::STAND_PLAYER;
		else
			std::cout << "Неверный ввод" << std::endl;
	}
}

int main()
{
	setlocale(LC_ALL, "rus");
	std::vector<int> card_deck{ CARD_DECK_BLACKJACK };
	int player_points(0), diller_points(0);
	auto move = BlackJackMoves::START_GAME;
	do
	{
		switch (move)
		{
			case BlackJackMoves::START_GAME:
			{
				diller_points += getCard(card_deck);
				player_points += getCard(card_deck);
				player_points += getCard(card_deck);
				std::cout << "ИГРОК: сумма очков = " << player_points << std::endl;
				runDialog(move);
				break;
			}
			case BlackJackMoves::HIT_PLAYER:
			{
				player_points += getCard(card_deck);
				std::cout << "ИГРОК: сумма очков = " << player_points << std::endl;
				if (player_points > 21)
				{
					std::cout << "ИГРОК - ПРОИГРАЛ, повезет в другой раз! " << std::endl;
					move = BlackJackMoves::END_GAME;
				}
				else
					runDialog(move);
				break;
			}
			case BlackJackMoves::STAND_PLAYER:
			{
				std::cout << "В игру вступает ДИЛЛЕР" << std::endl;
				move = BlackJackMoves::HIT_DILLER;
				break;
			}
			case BlackJackMoves::HIT_DILLER:
			{
				diller_points += getCard(card_deck);
				std::cout << "ДИЛЛЕР: сумма очков = " << diller_points << std::endl;
				if(diller_points < 17)
					move = BlackJackMoves::HIT_DILLER;
				else if(diller_points > 21)
				{
					std::cout << "ИГРОК - ПОБЕДИЛ, поздравляем! " << std::endl;
					move = BlackJackMoves::END_GAME;
				}
				else
					move = BlackJackMoves::STAND_DILLER;
				break;

			}
			case BlackJackMoves::STAND_DILLER:
			{
				if (player_points > diller_points)
				{
					std::cout << "ИГРОК - ПОБЕДИЛ, поздравляем! " << std::endl;
					move = BlackJackMoves::END_GAME;
				}
				else if (player_points < diller_points)
				{
					std::cout << "ИГРОК - ПРОИГРАЛ, повезет в другой раз! " << std::endl;
					move = BlackJackMoves::END_GAME;
				}
				else
				{
					std::cout << "ИГРА ВНИЧЬЮ, так совпало! " << std::endl;
					move = BlackJackMoves::END_GAME;
				}
				break;
			}
		}
	} while (move != BlackJackMoves::END_GAME);

	return 0;
}
