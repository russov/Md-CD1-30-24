#include <algorithm>
#include <iostream>
#include <limits>
#include <string>
#include <vector>
#include "Player.h"

using namespace std;

const int kBlackjack = 21;
const int kFirstDeal = 2;
const int kMinDealerValue = 17;
const int kHighCard = 10;
const int kAceValue = 11;

int ValueCounter(const vector<string>& hand) {
    int value_buffer = 0;
    for (const auto& card : hand) {
        if (card == "Jack" || card == "Queen" || card == "King") {
            value_buffer += kHighCard;
        }
        else if (card == "Ace") {
            value_buffer += kAceValue;
        }
        else {
            value_buffer += stoi(card);
        }
    }
    return value_buffer;
}

int Input() {
    int num;
    while (true) {
        cin >> num;
        if (!cin.fail()) {
            break;
        }
        cout << "Incorrect type\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    return num;
}

bool EndGameNewGame() {
    cout << "For a new game enter 1, for exit enter 0" << endl;
    int new_game_choice = Input();
    while (new_game_choice != 0 && new_game_choice != 1) {
        cout << "Incorrect input" << endl;
        new_game_choice = Input();
    }
    return new_game_choice == 1;
}

void DisplayPlayerHand(const Player& player) {
    cout << player.GetName() << ':' << endl;
    cout << "Hand:";
    for (const auto& card : player.GetHand()) {
        cout << '|' << card << '|' << ' ';
    }
    cout << "\nValue: " << player.GetValue() << endl;
}

int main() {
    Player dealer("Tom");
    Player player;

    while (true) {
        bool check_end_game = false;
        vector<string> deck{
            "2", "3", "4", "5", "6", "7", "8", "9", "10", "Jack", "Queen", "King", "Ace",
            "2", "3", "4", "5", "6", "7", "8", "9", "10", "Jack", "Queen", "King", "Ace",
            "2", "3", "4", "5", "6", "7", "8", "9", "10", "Jack", "Queen", "King", "Ace",
            "2", "3", "4", "5", "6", "7", "8", "9", "10", "Jack", "Queen", "King", "Ace"
        };
        random_shuffle(deck.begin(), deck.end());

        dealer.ResetHand();
        dealer.ResetValue();
        player.ResetHand();
        player.ResetValue();

        for (int i = 0; i < kFirstDeal; ++i) {
            dealer.SetHand(deck.back());
            deck.pop_back();
            player.SetHand(deck.back());
            deck.pop_back();
        }

        // Calculate the value of the player's hand right after the initial deal
        player.ResetValue();
        player.SetValue(ValueCounter(player.GetHand()));

        while (true) {
            system("cls");
            cout << "Dealer " << dealer.GetName() << ':' << endl;
            cout << "Hand: ";
            cout << '|' << dealer.GetHand()[0] << '|' << '|' << '?' << '|' << endl;
            cout << "Value: Unknown" << endl;

            cout << "Player ";
            DisplayPlayerHand(player);

            if (player.GetValue() > kBlackjack) {
                cout << "You lose!" << endl;
                check_end_game = true;
                break;
            }
            else if (player.GetValue() == kBlackjack) {
                cout << "You win!" << endl;
                check_end_game = true;
                break;
            }

            cout << "Enter 1 for Hit, or 2 for Stand, enter 0 to exit game" << endl;
            int choice = Input();
            if (choice == 2) {
                break;
            }
            else if (choice == 0) {
                return 0;
            }
            else if (choice != 1) {
                continue;
            }

            player.SetHand(deck.back());
            deck.pop_back();

            player.ResetValue();
            player.SetValue(ValueCounter(player.GetHand()));
        }

        if (check_end_game) {
            if (!EndGameNewGame()) {
                return 0;
            }
            continue;
        }

        while (true) {
            system("cls");
            cout << "Dealer ";
            DisplayPlayerHand(dealer);

            dealer.ResetValue();
            dealer.SetValue(ValueCounter(dealer.GetHand()));

            cout << "Player ";
            DisplayPlayerHand(player);

            if (dealer.GetValue() > kBlackjack) {
                cout << "You win!" << endl;
                check_end_game = true;
                break;
            }
            else if (dealer.GetValue() >= kMinDealerValue) {
                break;
            }
            else if (dealer.GetValue() == kBlackjack) {
                cout << "You lose!" << endl;
                check_end_game = true;
                break;
            }

            dealer.SetHand(deck.back());
            deck.pop_back();
        }

        if (!check_end_game) {
            if (dealer.GetValue() > player.GetValue()) {
                cout << "You lose!" << endl;
                check_end_game = true;
            }
            else {
                cout << "You win!" << endl;
                check_end_game = true;
            }
        }

        if (check_end_game) {
            if (!EndGameNewGame()) {
                return 0;
            }
        }
    }
}


