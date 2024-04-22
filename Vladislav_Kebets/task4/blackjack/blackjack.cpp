#include <iostream> 
#include <array> 
#include <vector> 
#include <conio.h> 
#define CARD_AMOUNT 52 
void mixDeck(std::array<int, CARD_AMOUNT>& deck);
int getBet(const int& score);
void giveCard(std::vector<int>& someone_cards, int& used_cards, std::array<int, CARD_AMOUNT>& deck, int& someone_sum);
void giveCard(std::vector<int>& someone_cards, int& used_cards, std::array<int, CARD_AMOUNT>& deck, int& someone_sum, int amount);
void printCards(std::vector<int>& someone_cards, int someone_sum); 
void printGameInformation(std::vector<int>& dealer_cards, int dealer_sum, std::vector<int>& player_cards, int player_sum, int used_cards, int bet);


enum Cards {
    JACK = 11,
    QUEEN = 12,
    KING = 13,
    ACE = 14
};

int main()
{
    srand(time(0));
    int used_cards = 0;
    std::array<int, CARD_AMOUNT> deck{ 2,2,2,2,3,3,3,3,4,4,4,4,5,5,5,5,6,6,6,6,7,7,7,7,8,8,8,8,9,9,9,9,10,10,10,10,JACK,JACK,JACK,JACK,QUEEN,QUEEN,QUEEN,QUEEN,KING,KING,KING,KING,ACE,ACE,ACE,ACE };
    mixDeck(deck);

    int score = 500;
    int bet;
    int player_sum, dealer_sum;

    bool game_over = 0;
    do {
        system("cls");
        bet = getBet(score);
        score -= bet;

        std::vector<int> player_cards, dealer_cards;
        player_sum = 0;
        dealer_sum = 0;

        giveCard(dealer_cards, used_cards, deck, dealer_sum);
        giveCard(player_cards, used_cards, deck, player_sum, 2);

        bool player_turn = 1;
        while (player_turn) {
            
            printGameInformation(dealer_cards, dealer_sum, player_cards, player_sum, used_cards, bet);

            std::cout << "\n1. hit\t\t2. stand" << std::endl;
            switch (_getch()) {
            case'1':
                giveCard(player_cards, used_cards, deck, player_sum);

                if (player_sum > 21) {
                    player_turn = 0;
                }

                break;

            case'2':
                player_turn = 0;
                break;
            }

        }

        if (player_sum < 22) {

            while (dealer_sum < 17) {
                giveCard(dealer_cards, used_cards, deck, dealer_sum);
            }

            printGameInformation(dealer_cards, dealer_sum, player_cards, player_sum, used_cards, bet);

            if (dealer_sum == player_sum) {
                std::cout << "\tDraw!\n";
                score += bet;
            }
            else {
                if (dealer_sum > 21 || dealer_sum < player_sum) {
                    std::cout << "\tYou Win!\n";
                    score += 2 * bet;
                }
                else std::cout << "\tYou lose!\n";
            }

        }
        else {
            printGameInformation(dealer_cards, dealer_sum, player_cards, player_sum, used_cards, bet);
            std::cout << "You lose!";
        }

        std::cout << "\tWant to continue?(y/n)";
        switch (_getch())
        {
            case 'y': game_over = 0;  break;
            
            case 'n': game_over = 1;  break;
        }
    } while (!game_over);
}

void mixDeck(std::array<int, CARD_AMOUNT>& deck) {
    for (int i = 0; i < CARD_AMOUNT; ++i) {
        std::swap(deck[i], deck[rand() % CARD_AMOUNT]);
    }
}

int getBet(const int& score) {

    int bet;
    bool bet_is_ok = 1;
    
    std::cout << "Your score - " << score << "\n";
    std::cout << "Enter your bet:  ";

    do {

        std::cin >> bet;

        if (score - bet < 0) {
            bet_is_ok = 0;
            std::cout << "You can't make that kind of bet! Enter another bet:  ";
        }
        else bet_is_ok = 1;

    } while (!bet_is_ok);

    return bet;
}

void giveCard(std::vector<int>& someone_cards, int& used_cards, std::array<int, CARD_AMOUNT>& deck, int& someone_sum) {

    someone_cards.push_back(deck[used_cards]);
    
    if (deck[used_cards] < 10) {
        someone_sum += deck[used_cards];
    }
    else {
        if (deck[used_cards] == ACE) {
            someone_sum += 11;
        }
        else { someone_sum += 10; }
    }
    
    ++used_cards;
    if (used_cards + 1 == CARD_AMOUNT) {
        used_cards = 0;
        mixDeck(deck);
    }
}

void giveCard(std::vector<int>& someone_cards, int& used_cards, std::array<int, CARD_AMOUNT>& deck, int& someone_sum, int amount) {
    
    for (int i = 0; i < amount; ++i) {
        
        someone_cards.push_back(deck[used_cards]);
        
        if (deck[used_cards] < 10) {
            someone_sum += deck[used_cards];
        }
        else {
            if (deck[used_cards] == ACE) {
                someone_sum += 11;
            }
            else { someone_sum += 10; }
        }
        
        ++used_cards;
        if (used_cards + 1 == CARD_AMOUNT) {
            used_cards = 0;
            mixDeck(deck);
        }
    }
}

void printCards(std::vector<int>& someone_cards, int someone_sum) {
    
    for (int card : someone_cards) {
        switch (card)
        {
        case JACK:
            std::cout << "[" << "J" << "]\t";
            break;
        case QUEEN:
            std::cout << "[" << "Q" << "]\t";
            break;
        case KING:
            std::cout << "[" << "K" << "]\t";
            break;
        case ACE:
            std::cout << "[" << "A" << "]\t";
            break;
        default:
            std::cout << "[" << card << "]\t";
            break;
        }
    }

    std::cout << "\nSum:  " << someone_sum << std::endl;
}

void printGameInformation(std::vector<int>& dealer_cards, int dealer_sum, std::vector<int>& player_cards, int player_sum,int used_cards,int bet) {
    system("cls");
    std::cout << "dealer cards:  ";
    printCards(dealer_cards, dealer_sum);
    std::cout << "\t\t\t" << CARD_AMOUNT - used_cards << " cards left\n" << "\t\t\tBet: " << bet << std::endl;
    std::cout << "\nplayer cards:  ";
    printCards(player_cards, player_sum);
}
