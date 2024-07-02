#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <string>


int TakeCard (std::vector<int>& cards);

std::string DataInput();

void CheckingGameConditions(int PlayersSum, int DealersSum);

main(){ 

    std::cout << "Welcom to the game BlackJack 🂡 \n";

    enum BroadwayCards {
        
        J = 10,
        Q = 10,
        K = 10,
        A = 11
    };

    std::vector<int> cards {2, 2, 2, 2, 3, 3, 3, 3, 4, 4, 4, 4, 5, 5, 5, 5, 6, 6, 6 ,6, 7, 7, 7, 7, 8, 8, 8, 8, 9, 9, 9, 9, 10, 10, 10, 10, J, J, J, J, Q, Q, Q, Q, K, K, K, K, A, A, A, A};

    int DealersCardOne = TakeCard(cards);
    std::cout << "Dealer took his card: " << DealersCardOne << "\nYour turn\n";

    int PlayersCardOne = TakeCard(cards);
    int PlayersCardTwo = TakeCard(cards);
    int PlayersSum = PlayersCardOne + PlayersCardTwo;
    std::cout << "You took 2 cards: " << PlayersCardOne << " and " << PlayersCardTwo << "\nSum of cards = " << PlayersSum << "\n";

    std::string PlayersChoise = DataInput();

    while (PlayersChoise == "hit" || PlayersChoise == "Hit"){
        int PlayersNextCards = TakeCard(cards);
        PlayersSum += PlayersNextCards;
        std::cout  << "You took: " << PlayersNextCards << "\nSum of cards = " << PlayersSum << "\n";
        PlayersChoise = DataInput();
    }

    int DealersCardTwo = TakeCard(cards);  
    int DealersSum = DealersCardOne + DealersCardTwo;

    int const MaxDealerPoints = 17;
    if (DealersSum < MaxDealerPoints){
        int DealersCardThree = TakeCard(cards);
        DealersSum += DealersCardThree;
    }

CheckingGameConditions(PlayersSum, DealersSum);   

std::cout << "The sum of your cards = " << PlayersSum << ", the dealer's card sum = " << DealersSum;

    return 0;
}

int TakeCard (std::vector<int>& cards){
   
    srand(time(NULL));
    int RandomIndex = rand() % cards.size();
    int TakenCard = cards[RandomIndex];
    cards.erase(cards.begin() + RandomIndex);

    return TakenCard ;
}

std::string DataInput(){

    std::string PlayersChoise;

    while(!(PlayersChoise == "hit" || PlayersChoise == "Hit" || PlayersChoise == "stand" || PlayersChoise == "Stand")){
        std::cout << "Hit or stand? Write your choise: ";
        std::cin >> PlayersChoise;
    }

    return PlayersChoise;
}

void CheckingGameConditions(int PlayersSum, int DealersSum){

    if(PlayersSum > 21){
        std::cout << "Unfortunately, you LOSE. Your sum of cards is more than 21 🙁\n";
    }
    else {
        if(PlayersSum == DealersSum){
            std::cout << "You have a draw 🤝\n";
        }
        else {
            if(PlayersSum > DealersSum){
                std::cout << "YOU WON, congrats! 🏆\n";
            }
            else {
                std::cout << "Unfortunately, you LOSE. The sum of your cards is less than the sum of the dealer's cards 🙁\n";
            }
        }
    }
    return;
}

