#include <iostream>
#include <ctime>
#include <vector>
#include <string>

const int Ace = 11;
const int PictureCard = 10;
const int DealerStand = 16;
const int WinStand = 21;

std::string TakeCard(std::vector<std::string>& DeckCards) { 
	int randomIndex = rand() % DeckCards.size();
	const auto CardTaken = DeckCards[randomIndex];
	DeckCards.erase(DeckCards.begin() + randomIndex);
	std::cout << "|" << CardTaken << "|" << " ";
	return CardTaken;
}

int DeckSum(std::vector<std::string>& AnyDeck) {
	int sum = 0;
	for (const auto& card : AnyDeck) {
		std::string value = card.substr(0, card.size() - 1);
		if (value == "A") {
			sum += Ace;
		}
		else if (value == "K" || value == "Q" || value == "J") {
			sum += PictureCard;
		}
		else {
			sum += std::stoi(value);
		}
	}
	return sum;
}

int main() {
	srand(static_cast<unsigned int>(time(0)));
	std::string AnswerQuestion;
	std::string Card;
	std::vector<std::string> DealerCards;
	std::vector<std::string> PlayerCards;
	std::vector<std::string> DeckCards;
	std::vector<std::string> SuitsCards = { "S", "H", "D", "C" };
	std::vector<std::string> cardValues = {"2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K", "A"};
	for (const auto& card : cardValues) {
		for (const auto& suit : SuitsCards) {
			DeckCards.push_back(card + suit);
		}
	}

	std::cout << "Dealer: "; 
	Card = TakeCard(DeckCards);
	DealerCards.push_back(Card);
	int DSum = DeckSum(DealerCards);
	std::cout << std::endl << "Player: ";
	for (int i = 0; i < 2; ++i) {
		Card = TakeCard(DeckCards);
		PlayerCards.push_back(Card);
	}
	int PSum = DeckSum(PlayerCards);
	std::cout << std::endl << "Sum of cards in dealer's hand: " << DSum << std::endl;
	std::cout << "Sum of cards in player's hand: " << PSum;

	while (true) { //Цикл hit stand 
		std::cout << std::endl << "hit or stand? ";
		std::getline(std::cin, AnswerQuestion);
		if (AnswerQuestion == "hit") {
			std::cout << "You take: ";
			Card = TakeCard(DeckCards);
			PlayerCards.push_back(Card);
			PSum = DeckSum(PlayerCards);
			if (DSum <= DealerStand) {
				std::cout << std::endl << "Dealer take: ";
				Card = TakeCard(DeckCards);
				DealerCards.push_back(Card);
				DSum = DeckSum(DealerCards);
			}
			std::cout << std::endl << "Sum of cards in dealer's hand: " << DSum << std::endl;
			std::cout << "Sum of cards in player's hand: " << PSum;
			if (DSum > WinStand && PSum > WinStand) {
				std::cout << std::endl << "DRAW!" << std::endl;
				break;
			}
			else if (PSum > WinStand) {
				std::cout << std::endl << "Player LOSE!" << std::endl;
				break;
			}
		}
		else if (AnswerQuestion == "stand") {
			while (DSum <= DealerStand) {
				std::cout << "Dealer take: ";
				Card = TakeCard(DeckCards);
				DealerCards.push_back(Card);
				DSum = DeckSum(DealerCards);
				std::cout << std::endl;
			}
			std::cout << "Sum of cards in dealer's hand: " << DSum << std::endl;
			std::cout << "Sum of cards in player's hand: " << PSum << std::endl;
			if (DSum > WinStand) {
				std::cout << "Dealer LOSE!" << std::endl;
				break;
			}
			if (PSum > DSum) {
				std::cout << "Player WIN!" << std::endl;
			}
			else if (DSum > PSum) {
				std::cout << "Dealer WIN!" << std::endl;
			}
			else {
				std::cout << "DRAW!" << std::endl;
			}
			break;
		}
		else {
			std::cout << "Enter hit or stand!";
			continue;
		}
	}
	system("pause");
	return 0;
}