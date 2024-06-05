#pragma once

#include <string>
#include <vector>

class Player {
public:
    explicit Player(const std::string& name);
    Player();

    void SetName();
    std::string GetName() const;

    void SetHand(const std::string& card);
    const std::vector<std::string>& GetHand() const;

    void SetValue(int card_value);
    int GetValue() const;

    void ResetHand();
    void ResetValue();

private:
    std::string name_;
    std::vector<std::string> hand_;
    int value_;
};