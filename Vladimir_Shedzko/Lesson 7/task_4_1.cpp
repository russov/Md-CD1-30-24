#include <map>
#include <iostream>
#include <stack>
#include <ctime>
/*
This is a simple simulation of a blackjack 
We "shuffle" our deck after each game
Sum of cards equal to 21 or combination of two aces give a "BlackJack"
win condition and finish the game ahead of schedule. Also game finishes
if player/dealer has number of points bigger than 21 or 5 cards in hand.
Starting from player.
*/
const int hand_max {5};
const int game_max {21};
const int dealer_max {17};
const int card_min {2};
const int card_max {11};

std::map<int, int> deck = {
    { 2, 4 },
    { 3, 4 },
    { 4, 4 },
    { 5, 4 },
    { 6, 4 },
    { 7, 4 },
    { 8, 4 },
    { 9, 4 },
    { 10, 16 }, // 4 tens, 4 jacks, 4 queens and 4 kings
    { 11, 4 }
};

int drawCard(){
    
    int card;
    do {
        card = rand()%(card_max - card_min + 1) + card_min;
    } while(deck[card] == 0);
    deck[card] -= 1;
    return card;
}

void showCards(std::stack<int> *cards, int amount){
    while (cards->size()) {
        std::cout << cards->top() << ' ';
        cards->pop();
    }
    std::cout << std::endl;
    std::cout << "Total amount: " << amount;
    if (amount > game_max) {
        std::cout << " - Overdrawn.";
    }
    else if (amount == game_max) {
        std::cout << " - Blackjack.";
    }
    std::cout << std::endl;
}

bool checkForEnd(int *curS, int lastI, int cardCount){
    if (cardCount >= hand_max) {
        return true;
    }
    if (*curS == game_max + 1 && lastI == card_max) {
        *curS = game_max;
    }
    if (*curS >= game_max) {
        return true;
    }
        
    return false;
}

int main() {

    
    std::srand(std::time(nullptr));
    std::cout << "Game starts" << std::endl;
    // Dealer init
    std::stack<int> dealer_cards {};
    auto dealer_last = drawCard();
    auto dealer_sum = dealer_last;
    auto dealer_cnt = 1;
    dealer_cards.push(dealer_last);
    // Player init
    std::stack<int> player_cards {};
    auto player_cnt = 2;
    auto player_sum = drawCard();
    auto player_last = drawCard();
    player_cards.push(player_sum);
    player_cards.push(player_last);
    std::cout << "Dealer points: " << dealer_last << std::endl;
    std::cout << "Your points: " << player_sum << " " << player_last << std::endl;
    player_sum += player_last;
    char curchar;
    while (true) {
        const auto player_end = checkForEnd(&player_sum, player_last, player_cnt);
        if (player_end) {
            break;
        }
        std::cout << "Press \'h\' to hit. Press \'s\' to stand" << std::endl;
        std::cin >> curchar;
        if (curchar == 'h' || curchar == 'H'){
            player_last = drawCard();
            player_sum += player_last;
            player_cards.push(player_last);
            player_cnt++;
            std::cout << "Current value: " << player_last << std::endl;
        }
        else if (curchar == 's' || curchar == 'S') {
            break;
        }
        else {
            std::cout << "Wrong input: " << curchar << std::endl;
        }
    }
    while (dealer_sum < dealer_max && dealer_cnt < hand_max){
        dealer_last = drawCard();
        dealer_sum += dealer_last;
        dealer_cards.push(dealer_last);
        dealer_cnt++;
        if (checkForEnd(&dealer_sum, dealer_last, dealer_cnt)) {
            break;
        }
    }
    std::cout << "Game over" << std::endl;
    std::cout << "Your cards: ";
    showCards(&player_cards, player_sum);
    std::cout << "Dealer cards: ";
    showCards(&dealer_cards, dealer_sum);
    if (dealer_sum > game_max && player_sum > game_max || dealer_sum == player_sum){
        std::cout << "Draw" << std::endl;
    }
    else if (dealer_sum > game_max || player_sum > dealer_sum  && player_sum <= game_max){
        std::cout << "You win" << std::endl;
    }
    else{
        std::cout << "Dealer wins" << std::endl;
    }
    return 0;
}