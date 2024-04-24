#include "Player.h"
#include <string>
#include <iostream>
#include <vector>

Player::Player()
{
	setName();
	value_ = 0;
	hand_.clear();
}

Player::Player(std::string name)
{
	name_ = name;
	value_ = 0;
	hand_.clear();
}

void Player::setName()
{
	std::cout << "Enter your name:";
	std::string name;
	std::cin >> name;
	name_ = name;
}

std::string Player::getName() const
{
	return name_;
}

void Player::setHand(std::string card)
{
	hand_.push_back(card);
}

const std::vector<std::string>& Player::getHand() const
{
	return hand_;
}

void Player::setValue(int cardValue)
{
	Player::value_ += cardValue;
}

int Player::getValue() const
{
	return value_;
}

void Player::resetHandAndValues()
{
	value_ = 0;
	hand_.clear();
}

void Player::resetValue()
{
	value_ = 0;
}