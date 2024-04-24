#pragma once
#include <string>
#include <vector>

class Player
{
private:
	std::string name_;
	std::vector <std::string> hand_;
	int value_;
public:
	explicit Player(std::string);
	Player();

	void setName();
	std::string getName() const;

	void setHand(std::string);
	const std::vector<std::string>& getHand() const;

	void setValue(int);
	int getValue() const;

	void resetHandAndValues();
	void resetValue();
};

