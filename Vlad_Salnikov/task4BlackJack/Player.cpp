#include "Player.h"
#include <iostream>
#include <string>
#include <vector>

Player::Player() {
    SetName();
    value_ = 0;
    hand_.clear();
}

Player::Player(const std::string& name) {
    name_ = name;
    value_ = 0;
    hand_.clear();
}

void Player::SetName() {
    std::cout << "Enter your name:";
    std::cin >> name_;
}

std::string Player::GetName() const {
    return name_;
}

void Player::SetHand(const std::string& card) {
    hand_.push_back(card);
}

const std::vector<std::string>& Player::GetHand() const {
    return hand_;
}

void Player::SetValue(int card_value) {
    value_ += card_value;
}

int Player::GetValue() const {
    return value_;
}

void Player::ResetHand() {
    hand_.clear();
}

void Player::ResetValue() {
    value_ = 0;
}