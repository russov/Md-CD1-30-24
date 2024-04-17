#include <iostream>
#include <cstdlib>
#include <ctime>

int rnadomValue(int min, int max){
    static bool initiate = false;
    if(!initiate){
        srand(time(0));
        initiate = true;
    }
    return min + rand() % (max - min + 1);


}
 int getCard(){
    return rnadomValue(2, 11);
 }


 void Blackjack(){  
    int dealer = getCard();
    int player = getCard() + getCard(); 

    std::cout<<"DEALER \n" <<dealer<<'\n';
    std::cout<<"------ "<<'\n';
    std::cout<<player<<"\nYOU"<<'\n';

    char choice;
    do {
    std::cout<<"npress h(hit) or s(stand)"<<std::endl;
    std::cin >> choice;
    if(choice == 'h'){
        player += getCard();
          std::cout<<" "<<'\n';
        std::cout<<"DEALER \n" <<dealer<<'\n';
    std::cout<<"------ "<<'\n';
    std::cout<<player<<"\nYOU"<<'\n';
    }
    } while (choice == 'h' && player <=21);
    
        while (dealer < 17)
        {
          dealer +=getCard();
            std::cout<<" "<<'\n';
            std::cout<<"DEALER \n" <<dealer<<'\n';
            std::cout<<"------ "<<'\n';
            std::cout<<player<<"\nYOU"<<'\n';
        }
          std::cout<<" "<<'\n';
        if(player > 21 || (dealer<=21 && dealer > player)){
            std::cout<<"DEALER win"<<std::endl;
        } else if (dealer > 21 || player > dealer){
            std::cout<<"PLAYER win"<<std::endl;
        }else{
            std::cout <<"DRAW"<<std::endl;
        }
 }
    
    
    


int main(){
    Blackjack();


}


