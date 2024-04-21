#include <iostream>
#include <ctime>
#include <string>

using namespace std;

const int Deck_size = 52;
int Deck[Deck_size];
int top_card = 51;
int Give_a_card = 0;
int value_of_diller_hend = 0, value_of_plaer_hend = 0, card_value = 0, temp = 0, temp2 = 0;
bool game_mode = true;
auto generateRandomNumbers() {

	for (int i = 0; i < Deck_size; ++i) {
		Deck[i] = i + 1;
	}

	std::srand(std::time(0));

	for (int i = Deck_size - 1; i > 0; --i) {
		int j = std::rand() % (i + 1);
		std::swap(Deck[i], Deck[j]);
	}

	for (int i = 0; i < Deck_size; ++i) {
	}
	return Deck[Deck_size];
}
int give_a_cards(int)
{
	Give_a_card = Deck[top_card];
	--top_card;
	return Give_a_card;

}

void Show_card()
{
	switch (Give_a_card)
	{
	case 1:
		std::cout << "2 peak\n";
		std::cout << " __________ \n";
		
		break;
	case 2:
		std::cout << "2 club \n";
		std::cout << " __________ \n";
		
		break;
	case 3:
		std::cout << "2 heart\n";
		std::cout << " __________ \n";
		
		break;
	case 4:
		std::cout << "2 diamond \n";
		std::cout << " __________ \n";
		
		break;
	case 5:
		std::cout << "3 peak \n";
		std::cout << " __________ \n";
		
		break;
	case 6:
		std::cout << "3 club \n";
		std::cout << " __________ \n";
		
		break;
	case 7:
		std::cout << "3 heart\n";
		std::cout << " __________ \n";
		
		break;
	case 8:
		std::cout << "3 diamond \n";
		std::cout << " __________ \n";
	
		break;
	case 9:
		std::cout << "4 peak\n";
		std::cout << " __________ \n";
		break;
	case 10:
		std::cout << "4 club \n";
		std::cout << " __________ \n";
		
		break;
	case 11:
		std::cout << "4 heart\n";
		std::cout << " __________ \n";
		
		break;
	case 12:
		std::cout << "4 diamond \n";
		std::cout << " __________ \n";
		
		break;
	case 13:
		std::cout << "5 peak\n";
		std::cout << " __________ \n";
		
		break;
	case 14:
		std::cout << "5 club \n";
		std::cout << " __________ \n";
		
		break;
	case 15:
		std::cout << "5 heart\n";
		std::cout << " __________ \n";
		
		break;
	case 16:
		std::cout << "5 diamond \n";
		std::cout << " __________ \n";
		
		break;
	case 17:
		std::cout << "6 peak\n";
		std::cout << " __________ n";
		
		break;
	case 18:
		std::cout << "6 club \n";
		std::cout << " __________ \n";
		
		break;
	case 19:
		std::cout << "6 heart\n";
		std::cout << " __________ \n";
		
		break;
	case 20:
		std::cout << "6 diamond \n";
		std::cout << " __________ \n";
		
		break;
	case 21:
		std::cout << "7 peak\n";
		std::cout << " __________ \n";
		break;
	case 22:
		std::cout << "7 club \n";
		std::cout << " __________ \n";
		
		break;
	case 23:
		std::cout << "7 heart\n";
		std::cout << " __________ \n";
		
		break;
	case 24:
		std::cout << "7 diamond \n";
		std::cout << " __________ \n";
		
		break;
	case 25:
		std::cout << "8 peak\n";
		std::cout << " __________ \n";
		
		break;
	case 26:
		std::cout << "8 club \n";
		std::cout << " __________ \n";
		
		break;
	case 27:
		std::cout << "8 heart\n";
		std::cout << " __________ \n";
		
		break;
	case 28:
		std::cout << "8 diamond \n";
		std::cout << " __________ \n";
		
		break;
	case 29:
		std::cout << "9 peak\n";
		std::cout << " __________ \n";
		
		break;
	case 30:
		std::cout << "9 club \n";
		std::cout << " __________ \n";
		
		break;
	case 31:
		std::cout << "9 heart\n";
		std::cout << " __________ \n";
		
		break;
	case 32:
		std::cout << "9 diamond \n";
		std::cout << " __________ \n";
		
		break;
	case 33:
		std::cout << "10 peak\n";
		std::cout << " __________\n";
		
		break;
	case 34:
		std::cout << "club \n";
		std::cout << " __________\n";
		
		break;
	case 35:
		std::cout << "10 heart\n";
		std::cout << " __________\n";
		
		break;
	case 36:
		std::cout << "10 diamond \n";
		std::cout << " __________\n";
		
		break;
	case 37:
		std::cout << "Jeak peak\n";
		std::cout << " __________\n";
		
		break;
	case 38:
		std::cout << "Jeak club \n";
		std::cout << " __________\n";
		
		break;
	case 39:
		std::cout << "Jeak heart\n";
		std::cout << " __________\n";
		
		break;
	case 40:
		std::cout << "Jeak diamond \n";
		std::cout << " __________\n";
		
		break;
	case 41:
		std::cout << "Queen peak\n";
		std::cout << " __________\n";
		
		break;
	case 42:
		std::cout << "Queen club \n";
		std::cout << " __________\n";
		
		break;
	case 43:
		std::cout << "Queen heart\n";
		std::cout << " __________\n";
		break;
	case 44:
		std::cout << "Queen diamond \n";
		std::cout << " __________\n";
		
		break;
	case 45:
		std::cout << "King peak\n";
		std::cout << " __________\n";
		
		break;
	case 46:
		std::cout << "King club \n";
		std::cout << " __________\n";
		
		break;
	case 47:
		std::cout << "King heart\n";
		std::cout << " __________\n";
		
		break;
	case 48:
		std::cout << "King diamond \n";
		std::cout << " __________\n";
		
		break;
	case 49:
		std::cout << "Ace peak\n";
		std::cout << " __________\n";
		
		break;
	case 50:
		std::cout << "Ace club \n";
		std::cout << " __________\n";
		
		break;
	case 51:
		std::cout << "Ace heart\n";
		std::cout << " __________\n";
		
		break;
	case 52:
		std::cout << "Ace diamond \n";
		std::cout << " __________\n";
		
		break;
	default:
		break;
	}
}

int Count_value_of_card(int)
{
	bool sicle = true;
	while (sicle)
	{
		if (Give_a_card < 5 && Give_a_card > 0)
		{
			card_value = 2;
			break;
			sicle = false;
		}
		else if (Give_a_card < 9 && Give_a_card > 4)
		{
			card_value = 3;
			break;
			sicle = false;
		}
		else if (Give_a_card < 13 && Give_a_card > 8)
		{
			card_value = 4;
			break;
			sicle = false;
		}
		else if (Give_a_card < 17 && Give_a_card > 12)
		{
			card_value = 5;
			break;
			sicle = false;
		}
		else if (Give_a_card < 21 && Give_a_card > 16)
		{
			card_value = 6;
			break;
			sicle = false;
		}
		else if (Give_a_card < 25 && Give_a_card > 20)
		{
			card_value = 7;
			break;
			sicle = false;
		}
		else if (Give_a_card < 29 && Give_a_card > 24)
		{
			card_value = 8;
			break;
			sicle = false;
		}
		else if (Give_a_card < 33 && Give_a_card > 28)
		{
			card_value = 9;
			break;
			sicle = false;
		}
		else if ( Give_a_card < 37 && Give_a_card > 32)
		{
			card_value = 10;
			break;
			sicle = false;
		}
		else if ( Give_a_card < 41 && Give_a_card > 36)
		{
			card_value = 10;
			break;
			sicle = false;
		}
		else if (Give_a_card < 45 && Give_a_card > 40)
		{
			card_value = 10;
			break;
			sicle = false;
		}
		else if ( Give_a_card < 49 && Give_a_card > 44)
		{
			card_value = 10;
			break;
			sicle = false;
		}
		else
		{
			card_value = 11;
			break;
			sicle = false;
		}
	}
	return card_value;
}

void generate_Diller_hend()
{
	give_a_cards(Give_a_card);
	Count_value_of_card(card_value);
	temp = Give_a_card;
	value_of_diller_hend =0;
	value_of_diller_hend += card_value;
	give_a_cards(Give_a_card);
	Count_value_of_card(card_value);
	temp2 = Give_a_card;
	Show_card();
	value_of_diller_hend += card_value;
}

void ho_is_wine()
{
	if ((value_of_plaer_hend == 21 && value_of_plaer_hend != value_of_diller_hend) || (value_of_plaer_hend < 21 && (value_of_plaer_hend > value_of_diller_hend || value_of_diller_hend > 21)) )
	{
		std:: cout << "YOU WIN!!!! :)\n";
	} 
	else
	{
		std::cout << " YOU LOOSE :( !!! \n";
	}
	std::cout << "do you want to play new game? ener y/n \n";
	std::cout << "\n ******************************************************************** \n";

	string Y = "Y", y = "y";
	string N = "N", n = "n";
	string plaer_answer_2;
	std::cin >> plaer_answer_2;
	bool incorrect = false;

		while (incorrect)
		{
			if ((plaer_answer_2 == Y) || (plaer_answer_2 == y))
			{
				game_mode = true;
				incorrect = false;
			}
			else if ((plaer_answer_2 == N) || (plaer_answer_2 == n))
			{
				std::cout << "good by \n";
				incorrect = false;
			}
			else
			{
				std::cout << "incorrect, pleas try again \n";
				std::cin >> plaer_answer_2;
			}
		}
}

int end_game(int)
{
	if ((value_of_diller_hend < 17))
	{
		std::cout << "Diller hend: \n";
		Give_a_card = temp;
		Show_card();
		Give_a_card = temp2;
		Show_card();
		give_a_cards(Give_a_card);
		Count_value_of_card(card_value);
		value_of_diller_hend += card_value;
		std::cout << "Diller pik app next card: \n";
		Show_card();
		std::cout << "Diller hend value is:" << value_of_diller_hend << "\n";
		return value_of_diller_hend;
	}
	else
	{
		std::cout << "Diller hend: \n";
		Give_a_card = temp;
		Show_card();
		Give_a_card = temp2;
		Show_card();
		std::cout << "Diller hend value is:" << value_of_diller_hend << "\n";
		return value_of_diller_hend;
	}
}
void generate_Plaer_hend()
{
	give_a_cards(Give_a_card);
	Count_value_of_card(card_value);
	value_of_plaer_hend = 0;
	value_of_plaer_hend += card_value;
	Show_card();
	give_a_cards(Give_a_card);
	Count_value_of_card(card_value);
	value_of_plaer_hend += card_value;
	Show_card();
	std::cout << "Yor value is: " << value_of_plaer_hend << "\n" << "What do you want to do now?\n" << "enter 'hite' if you whonna kip new card or 'stend' if you wonna end the game \n";
	string hite = "hite", stand = "stend";
	string new_answer;
	std::cin >> new_answer;
	bool chose_cards_at_deck = true;
	while (chose_cards_at_deck)
	{
		if (new_answer == hite)
		{
			bool chose_cards = true;
			while (chose_cards)
			{
				give_a_cards(Give_a_card);
				Count_value_of_card(card_value);
				value_of_plaer_hend += card_value;
				std::cout << "Your next card is: \n";
				Show_card();
				std::cout << "Yor value is: " << value_of_plaer_hend << "\n" << "Whot do you wont to do now?\n" << "enter 'hite' if you whonna kip new card or 'stend' if you wonna end the game \n";
				std::cin >> new_answer;
				if (new_answer == hite)
				{
					chose_cards = true;
				}
				else
				{
					chose_cards = false;
				}
			}
		}
		else if (new_answer == stand)
		{
			end_game(value_of_diller_hend);
			ho_is_wine();
			chose_cards_at_deck = false;
		}
		else
		{
			std::cout << "invalid command,pleas, try again! \n";
			std::cin.clear();
			chose_cards_at_deck = true;
			std::cin >> new_answer;
		}
	}
	}
	

int main()
{
	srand(time(0));
	generateRandomNumbers();
	
	std::cout << "If you want start the game, enter Y, if you want to end game, press samsing other \n";
	string answer_of_plaer;
	std::cin >> answer_of_plaer;
	string Y = "Y", y = "y";
	string N = "N", n = "n";
	bool incorrect_aswer = true;
	
	while (game_mode)
	{
		while (incorrect_aswer)
		{
			if ((answer_of_plaer == Y) || (answer_of_plaer == y))
			{
				std::cout << "Diller kept 2 carts, one of them is: \n";
				generate_Diller_hend();
				std::cout << "this is your hend cards, look: \n";
				generate_Plaer_hend();
				incorrect_aswer = true;
			}
			else if ((answer_of_plaer == N) || (answer_of_plaer == n))
			{
				std::cout << "good by \n";
				incorrect_aswer = false;
			}
			else
			{
				std::cout << "incorrect, pleas try again \n";
				std::cin >> answer_of_plaer;
			}
		}
	}
	
	
	return 0;	
}