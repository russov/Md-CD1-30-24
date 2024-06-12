#include <iostream>
#include <ctime>
#include <vector>
#include <string>
#include <array>

void CreateDeck(std::vector<std::string>& EmptyDeck) {
	const std::array<std::string, 4> SuitsCards = { "S", "H", "D", "C" };
	const std::array<std::string, 13> cardValues = { "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K", "A" };
	for (const auto& card : cardValues) {
		for (const auto& suit : SuitsCards) {
			EmptyDeck.push_back(card + suit);
		}
	}
}

void TakeCard(std::vector<std::string>& DeckCards, int& SumDeck) {
	const int Ace = 11;
	const int PictureCard = 10;
	size_t randomIndex{ static_cast<size_t>(rand()) % DeckCards.size() };
	const auto CardTaken = DeckCards[randomIndex];
	DeckCards.erase(DeckCards.begin() + randomIndex);
	std::cout << "|" << CardTaken << "|" << " ";
	const auto ValueCard{ CardTaken.substr(0, CardTaken.size() - 1) };
	if (ValueCard == "A") {
		SumDeck += Ace;
	}
	else if (ValueCard == "K" || ValueCard == "Q" || ValueCard == "J") {
		SumDeck += PictureCard;
	}
	else {
		SumDeck += std::stoi(ValueCard);
	}
}

void StartGame(std::vector<std::string>& DeckCards, int& DealerSum, int& PlayerSum) {
	std::cout << "You cards : ";
	for (int i = 0; i < 2; ++i) {
		TakeCard(DeckCards, PlayerSum);
	}
	std::cout << std::endl << "Dealer cards: ";
	TakeCard(DeckCards, DealerSum);
	std::cout << std::endl << "Sum of cards in you hand: " << PlayerSum;
	std::cout << std::endl << "Sum of cards in dealer's hand: " << DealerSum;
}

void LogicGame(std::vector<std::string>& DeckCards, int& DealerSum, int& PlayerSum) {
	const int DealerStand = 16;
	const int WinStand = 21;
	const std::string Take = "hit";
	const std::string NotTake = "stand";
	std::string AnswerQuestion{};
	while (true) {
		if (PlayerSum > WinStand) {
			std::cout << std::endl << "|Dealer win, you lose!|";
			break;
		}
		std::cout << std::endl << "hit or stand? ";
		std::getline(std::cin, AnswerQuestion);
		if (AnswerQuestion == Take) {
			std::cout << "You take: ";
			TakeCard(DeckCards, PlayerSum);
			if (DealerSum <= DealerStand) {
				std::cout << std::endl << "Dealer take: ";
				TakeCard(DeckCards, DealerSum);
			}
			std::cout << std::endl << "Sum of cards in you hand: " << PlayerSum;
			std::cout << std::endl << "Sum of cards in dealer's hand: " << DealerSum;
			if (DealerSum > WinStand && PlayerSum > WinStand) {
				std::cout << std::endl << "|Draw!|" << std::endl;
				break;
			}
			else if (PlayerSum > WinStand) {
				std::cout << std::endl << "|Dealer win, you lose!|" << std::endl;
				break;
			}
		}
		else if (AnswerQuestion == NotTake) {
			while (DealerSum <= DealerStand) {
				std::cout << "Dealer take: ";
				TakeCard(DeckCards, DealerSum);
				std::cout << std::endl;
			}
			std::cout << "Sum of cards in you hand: " << PlayerSum << std::endl;
			std::cout << "Sum of cards in dealer's hand: " << DealerSum << std::endl;
			if (DealerSum > WinStand) {
				std::cout << "|You win, dealer lose!|" << std::endl;
				break;
			}
			if (PlayerSum > DealerSum) {
				std::cout << "|You win, dealer lose!|" << std::endl;
			}
			else if (DealerSum > PlayerSum) {
				std::cout << "|Dealer win, you lose!|" << std::endl;
			}
			else {
				std::cout << "|Draw!|" << std::endl;
			}
			break;
		}
		else {
			std::cout << "Enter: hit or stand!";
			continue;
		}
	}
}

int main() {
	srand(static_cast<unsigned int>(time(0)));
	std::vector<std::string> DeckCards{};
	int DealerSum = 0;
	int PlayerSum = 0;
	std::string PlayAgain = "yes";

	while (PlayAgain == "yes") {
		DeckCards.clear();
		DealerSum = 0;
		PlayerSum = 0;

		CreateDeck(DeckCards);
		StartGame(DeckCards, DealerSum, PlayerSum);
		LogicGame(DeckCards, DealerSum, PlayerSum);

		std::cout << "Play Again? (Enter: yes)";
		std::getline(std::cin, PlayAgain);
	}
	std::cin.get();
	return 0;
}