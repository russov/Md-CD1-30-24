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
    
    int card = std::rand()%10 + 1;
    while(deck[card] == 0){
        card = rand()%10 + 1;
    }
    deck[card] -= 1;
    return card;
}

void showCards(std::stack<int> *cards, int amount){
    while (cards->size()){
        std::cout << cards->top() << ' ';
        cards->pop();
    }
    std::cout << std::endl;
    std::cout << "Total amount: " << amount;
    if (amount > 21){
        std::cout << " - Overdrawn.";
    }
    else if (amount == 21){
        std::cout << " - Blackjack.";
    }
    std::cout << std::endl;
}

bool checkForEnd(int *curS, int lastI, int cardCount){
    if (cardCount >= 5)
        return true;
    if (*curS == 22 && lastI == 11)
        *curS = 21;
    if (*curS >= 21)
        return true;
    return false;
}

int main() {
    std::srand(std::time(nullptr));
    std::cout << "Game starts" << std::endl;
    // Dealer init
    std::stack<int> dealer_cards;
    int dealer_last = drawCard();
    int dealer_sum = dealer_last;
    int dealer_cnt = 1, player_cnt = 2;
    dealer_cards.push(dealer_last);
    // Player init
    std::stack<int> player_cards;
    
    int player_sum = drawCard();
    int player_last = drawCard();
    player_cards.push(player_sum);
    player_cards.push(player_last);
    std::cout << "Dealer points: " << dealer_last << std::endl;
    std::cout << "Your points: " << player_sum << " " << player_last << std::endl;
    player_sum += player_last;
    char curchar;
    bool player_end;
    while (true) {
        player_end = checkForEnd(&player_sum, player_last, player_cnt);
        if (player_end)
            break;
        std::cout << "Press \'h\' to hit. Press \'s\' to stand" << std::endl;
        std::cin >> curchar;
        if (curchar == 'h' || curchar == 'H'){
            player_last = drawCard();
            player_sum += player_last;
            player_cards.push(player_last);
            player_cnt++;
            std::cout << "Current value: " << player_last << std::endl;
        }
        else if (curchar == 's' || curchar == 'S'){
            break;
        }
        else
            std::cout << "Wrong input: " << curchar << std::endl;
    }
    while (dealer_sum < 17 && dealer_cnt < 5){
        dealer_last = drawCard();
        dealer_sum += dealer_last;
        dealer_cards.push(dealer_last);
        dealer_cnt++;
        if (checkForEnd(&dealer_sum, dealer_last, dealer_cnt))
            break;
    }
    std::cout << "Game over" << std::endl;
    std::cout << "Your cards: ";
    showCards(&player_cards, player_sum);
    std::cout << "Dealer cards: ";
    showCards(&dealer_cards, dealer_sum);
    if (dealer_sum > 21 && player_sum > 21 || dealer_sum == player_sum){
        std::cout << "Draw" << std::endl;
    }
    else if (dealer_sum > 21 || player_sum > dealer_sum  && player_sum <=21 ){
        std::cout << "You win" << std::endl;
    }
    else{
        std::cout << "Dealer wins" << std::endl;
    }
    return 0;
}