#pragma once
#include <string>
#include <vector>

class Player
{
public:
	explicit Player(std::string);
	Player();

	void setName();
	std::string getName() const;

	void setHand(std::string);
	const std::vector<std::string>& getHand() const;

	void setValue(int);
	int getValue() const;

	void resetHand();
	void resetValue();
private:
	std::string name_;
	std::vector <std::string> hand_;
	int value_;
};

