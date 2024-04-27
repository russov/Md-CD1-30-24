#include <iostream>
#include <cstdlib>
#include <ctime>

int createCard()
{
    return 2 + rand() % 11;
}

int sumOfCards(int f, int s)
{
    return f + s;
}

int main()
{
    srand(time(0));
    int firstPlayerCard = createCard();
    int secondPlayerCard = createCard();
    int firstDealerCard = createCard();
    int secondDealerCard = createCard();

    std::cout << "\nDEALER\n? " << secondDealerCard << "\n\n";
    std::cout << "YOU\n"
              << firstPlayerCard << " " << secondPlayerCard << std::endl;

    char choice;
    std::cout << "Hit or pass card(h/p)?"
              << "\n";
    std::cin >> choice;

    int sum = sumOfCards(firstPlayerCard, secondPlayerCard);
    int sumD = sumOfCards(firstDealerCard, secondDealerCard);

    while (choice == 'h')
    {
        sum += createCard();
        std::cout << "your sum: " << sum << "\n";

        if (sum > 21)
        {
            std::cout << "Your lose! Dealer win\nDealer sum: " << sumD << "\n";
            return 0;
        }
        std::cout << "Hit or pass card (h/p)?\n";
        std::cin >> choice;
    }
    std::cout << "your sum: " << sum << "\n";

    while (sumD <= 17)
    {
        sumD += createCard();
        std::cout << "Dealer takes a card\nDealer sum: " << sumD << std::endl;
        if (sumD > 21)
        {
            std::cout << "Dealer lose! You win "
                      << "\n";
            return 0;
        }
    }

    if (sum > sumD)
    {
        std::cout << "You win!"
                  << "\n";
    }
    else if (sum < sumD)
    {
        std::cout << "Dealer win!\nDealer sum: " << sumD << "\n";
    }
    else if (sum == sumD)
    {
        std::cout << "Tie!"
                  << "\n";
    }

    return 0;
}
