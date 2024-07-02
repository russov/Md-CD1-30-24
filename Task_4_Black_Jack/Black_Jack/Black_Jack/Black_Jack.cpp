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

int give_a_cards(int) {
    Give_a_card = Deck[top_card];
    --top_card;
    return Give_a_card;
}

void Show_card() {
    switch (Give_a_card) {
    case 1:
        std::cout << "2 пик\n";
        std::cout << " __________ \n";
        break;
    case 2:
        std::cout << "2 треф\n";
        std::cout << " __________ \n";
        break;
    case 3:
        std::cout << "2 черви\n";
        std::cout << " __________ \n";
        break;
    case 4:
        std::cout << "2 бубны\n";
        std::cout << " __________ \n";
        break;
    case 5:
        std::cout << "3 пик\n";
        std::cout << " __________ \n";
        break;
    case 6:
        std::cout << "3 треф\n";
        std::cout << " __________ \n";
        break;
    case 7:
        std::cout << "3 черви\n";
        std::cout << " __________ \n";
        break;
    case 8:
        std::cout << "3 бубны\n";
        std::cout << " __________ \n";
        break;
    case 9:
        std::cout << "4 пик\n";
        std::cout << " __________ \n";
        break;
    case 10:
        std::cout << "4 треф\n";
        std::cout << " __________ \n";
        break;
    case 11:
        std::cout << "4 черви\n";
        std::cout << " __________ \n";
        break;
    case 12:
        std::cout << "4 бубны\n";
        std::cout << " __________ \n";
        break;
    case 13:
        std::cout << "5 пик\n";
        std::cout << " __________ \n";
        break;
    case 14:
        std::cout << "5 треф\n";
        std::cout << " __________ \n";
        break;
    case 15:
        std::cout << "5 черви\n";
        std::cout << " __________ \n";
        break;
    case 16:
        std::cout << "5 бубны\n";
        std::cout << " __________ \n";
        break;
    case 17:
        std::cout << "6 пик\n";
        std::cout << " __________ \n";
        break;
    case 18:
        std::cout << "6 треф\n";
        std::cout << " __________ \n";
        break;
    case 19:
        std::cout << "6 черви\n";
        std::cout << " __________ \n";
        break;
    case 20:
        std::cout << "6 бубны\n";
        std::cout << " __________ \n";
        break;
    case 21:
        std::cout << "7 пик\n";
        std::cout << " __________ \n";
        break;
    case 22:
        std::cout << "7 треф\n";
        std::cout << " __________ \n";
        break;
    case 23:
        std::cout << "7 черви\n";
        std::cout << " __________ \n";
        break;
    case 24:
        std::cout << "7 бубны\n";
        std::cout << " __________ \n";
        break;
    case 25:
        std::cout << "8 пик\n";
        std::cout << " __________ \n";
        break;
    case 26:
        std::cout << "8 треф\n";
        std::cout << " __________ \n";
        break;
    case 27:
        std::cout << "8 черви\n";
        std::cout << " __________ \n";
        break;
    case 28:
        std::cout << "8 бубны\n";
        std::cout << " __________ \n";
        break;
    case 29:
        std::cout << "9 пик\n";
        std::cout << " __________ \n";
        break;
    case 30:
        std::cout << "9 треф\n";
        std::cout << " __________ \n";
        break;
    case 31:
        std::cout << "9 черви\n";
        std::cout << " __________ \n";
        break;
    case 32:
        std::cout << "9 бубны\n";
        std::cout << " __________ \n";
        break;
    case 33:
        std::cout << "10 пик\n";
        std::cout << " __________ \n";
        break;
    case 34:
        std::cout << "10 треф\n";
        std::cout << " __________ \n";
        break;
    case 35:
        std::cout << "10 черви\n";
        std::cout << " __________ \n";
        break;
    case 36:
        std::cout << "10 бубны\n";
        std::cout << " __________ \n";
        break;
    case 37:
        std::cout << "Валет пик\n";
        std::cout << " __________ \n";
        break;
    case 38:
        std::cout << "Валет треф\n";
        std::cout << " __________ \n";
        break;
    case 39:
        std::cout << "Валет черви\n";
        std::cout << " __________ \n";
        break;
    case 40:
        std::cout << "Валет бубны\n";
        std::cout << " __________ \n";
        break;
    case 41:
        std::cout << "Дама пик\n";
        std::cout << " __________ \n";
        break;
    case 42:
        std::cout << "Дама треф\n";
        std::cout << " __________ \n";
        break;
    case 43:
        std::cout << "Дама черви\n";
        std::cout << " __________ \n";
        break;
    case 44:
        std::cout << "Дама бубны\n";
        std::cout << " __________ \n";
        break;
    case 45:
        std::cout << "Король пик\n";
        std::cout << " __________ \n";
        break;
    case 46:
        std::cout << "Король треф\n";
        std::cout << " __________ \n";
        break;
    case 47:
        std::cout << "Король черви\n";
        std::cout << " __________ \n";
        break;
    case 48:
        std::cout << "Король бубны\n";
        std::cout << " __________ \n";
        break;
    case 49:
        std::cout << "Туз пик\n";
        std::cout << " __________ \n";
        break;
    case 50:
        std::cout << "Туз треф\n";
        std::cout << " __________ \n";
        break;
    case 51:
        std::cout << "Туз черви\n";
        std::cout << " __________ \n";
        break;
    case 52:
        std::cout << "Туз бубны\n";
        std::cout << " __________ \n";
        break;
    default:
        break;
    }
}

int Count_value_of_card(int) {
    bool цикл = true;
    while (цикл) {
        if (Give_a_card < 5 && Give_a_card > 0) {
            card_value = 2;
            break;
            цикл = false;
        }
        else if (Give_a_card < 9 && Give_a_card > 4) {
            card_value = 3;
            break;
            цикл = false;
        }
        else if (Give_a_card < 13 && Give_a_card > 8) {
            card_value = 4;
            break;
            цикл = false;
        }
        else if (Give_a_card < 17 && Give_a_card > 12) {
            card_value = 5;
            break;
            цикл = false;
        }
        else if (Give_a_card < 21 && Give_a_card > 16) {
            card_value = 6;
            break;
            цикл = false;
        }
        else if (Give_a_card < 25 && Give_a_card > 20) {
            card_value = 7;
            break;
            цикл = false;
        }
        else if (Give_a_card < 29 && Give_a_card > 24) {
            card_value = 8;
            break;
            цикл = false;
        }
        else if (Give_a_card < 33 && Give_a_card > 28) {
            card_value = 9;
            break;
            цикл = false;
        }
        else if (Give_a_card < 37 && Give_a_card > 32) {
            card_value = 10;
            break;
            цикл = false;
        }
        else if (Give_a_card < 41 && Give_a_card > 36) {
            card_value = 10;
            break;
            цикл = false;
        }
        else if (Give_a_card < 45 && Give_a_card > 40) {
            card_value = 10;
            break;
            цикл = false;
        }
        else if (Give_a_card < 49 && Give_a_card > 44) {
            card_value = 10;
            break;
            цикл = false;
        }
        else {
            card_value = 11;
            break;
            цикл = false;
        }
    }
    return card_value;
}

void generate_Diller_hend() {
    give_a_cards(Give_a_card);
    Count_value_of_card(card_value);
    temp = Give_a_card;
    value_of_diller_hend = 0;
    value_of_diller_hend += card_value;
    give_a_cards(Give_a_card);
    Count_value_of_card(card_value);
    temp2 = Give_a_card;
    Show_card();
    value_of_diller_hend += card_value;
}

void ho_is_wine() {
    if ((value_of_plaer_hend == 21 && value_of_plaer_hend != value_of_diller_hend) || (value_of_plaer_hend < 21 && (value_of_plaer_hend > value_of_diller_hend || value_of_diller_hend > 21))) {
        std::cout << "ПОБЕДА ПОЗДРАВЛЕМ!\n";
    }
    else {
        std::cout << "ПРОИЙГРЫШ СЛЕДУЮЩИЙ РАЗ ПОВЕЗЕТ!\n";
    }
    std::cout << "Хотите сыграть новую игру? введите y/n\n";
    std::cout << "\n ******************************************************************** \n";

    string Y = "Y", y = "y";
    string N = "N", n = "n";
    string plaer_answer_2;
    std::cin >> plaer_answer_2;
    bool incorrect = true;

    while (incorrect) {
        if ((plaer_answer_2 == Y) || (plaer_answer_2 == y)) {
            game_mode = true;
            incorrect = false;
        }
        else if ((plaer_answer_2 == N) || (plaer_answer_2 == n)) {
            std::cout << "До свидания\n";
            incorrect = false;
        }
        else {
            std::cout << "Неправильно, попробуйте снова\n";
            std::cin >> plaer_answer_2;
        }
    }
}

int end_game(int) {
    if ((value_of_diller_hend < 17)) {
        std::cout << "Рука дилера: \n";
        Give_a_card = temp;
        Show_card();
        Give_a_card = temp2;
        Show_card();
        give_a_cards(Give_a_card);
        Count_value_of_card(card_value);
        value_of_diller_hend += card_value;
        std::cout << "Дилер берет следующую карту: \n";
        Show_card();
        std::cout << "Значение руки дилера: " << value_of_diller_hend << "\n";
        return value_of_diller_hend;
    }
    else {
        std::cout << "Рука дилера: \n";
        Give_a_card = temp;
        Show_card();
        Give_a_card = temp2;
        Show_card();
        std::cout << "Значение руки дилера: " << value_of_diller_hend << "\n";
        return value_of_diller_hend;
    }
}

void generate_Plaer_hend() {
    give_a_cards(Give_a_card);
    Count_value_of_card(card_value);
    value_of_plaer_hend = 0;
    value_of_plaer_hend += card_value;
    Show_card();
    give_a_cards(Give_a_card);
    Count_value_of_card(card_value);
    value_of_plaer_hend += card_value;
    Show_card();
    std::cout << "Ваше значение: " << value_of_plaer_hend << "\n" << "Что вы хотите сделать дальше?\n" << "введите 'hit' если хотите взять новую карту или 'stand' если хотите завершить игру\n";
    string hit = "hit", stand = "stand";
    string new_answer;
    std::cin >> new_answer;
    bool chose_cards_at_deck = true;
    while (chose_cards_at_deck) {
        if (new_answer == hit) {
            bool chose_cards = true;
            while (chose_cards) {
                give_a_cards(Give_a_card);
                Count_value_of_card(card_value);
                value_of_plaer_hend += card_value;
                std::cout << "Ваша следующая карта: \n";
                Show_card();
                std::cout << "Ваше значение: " << value_of_plaer_hend << "\n" << "Что вы хотите сделать дальше?\n" << "введите 'хит' если хотите взять новую карту или 'стенд' если хотите завершить игру\n";
                std::cin >> new_answer;
                if (new_answer == hit) {
                    chose_cards = true;
                }
                else {
                    chose_cards = false;
                }
            }
        }
        else if (new_answer == stand) {
            end_game(value_of_diller_hend);
            ho_is_wine();
            chose_cards_at_deck = false;
        }
        else {
            std::cout << "Неверная команда, попробуйте снова!\n";
            std::cin.clear();
            chose_cards_at_deck = true;
            std::cin >> new_answer;
        }
    }
}

int main() {
    srand(time(0));
    generateRandomNumbers();

    setlocale(LC_ALL, "Russian");
    std::cout << "Добро пожаловать в игру. Если хотите продолжить, нажмите Y, если нет - любую другую кнопку\n";
    string answer_of_plaer;
    std::cin >> answer_of_plaer;
    string Y = "Y", y = "y";
    string N = "N", n = "n";
    bool incorrect_aswer = true;

    while (game_mode) {
        while (incorrect_aswer) {
            if ((answer_of_plaer == Y) || (answer_of_plaer == y)) {
                std::cout << "Дилер взял 2 карты, одна из них: \n";
                generate_Diller_hend();
                std::cout << "Это ваши карты, посмотрите: \n";
                generate_Plaer_hend();
                incorrect_aswer = true;
            }
            else if ((answer_of_plaer == N) || (answer_of_plaer == n)) {
                std::cout << "До свидания\n";
                incorrect_aswer = false;
            }
            else {
                std::cout << "Неправильно, попробуйте снова\n";
                std::cin >> answer_of_plaer;
            }
        }
    }

    return 0;
}
