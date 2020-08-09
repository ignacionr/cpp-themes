#include <iostream>

// THEME: Object Oriented Programming
// 1) The most important concepts, are objects/their classes
// 2) classes are UDT, they add:
// ENCAPSULATION
//              a) behavior - methods
//              b) constructor / destructors
//                  because we want the class to be responsible of having a valid state all through its life
//              c) access levels (adding modifiers private/protected/public)
//              d) operator overloading

//              e) virtual methods
//              f) inheritance

struct GameData
{
#define TOTAL_SHIPS 5

    // Constructor will get the object into an initial valid state
    GameData()
    {
        for (auto i{0}; i < 7; ++i)
            for (auto j{0}; j < 7; ++j)
            {
                _user_board[i][j] = false;
                _computer_board[i][j] = false;
            }
    }

    // Destructor has the opportunity of freeing resources or doing things when the object goes out of scope
    ~GameData()
    {
    }

    // behavior - methods
    int count_user_ships()
    {
        auto result{0};
        for (auto i{0}; i < 7; ++i)
            for (auto j{0}; j < 7; ++j)
            {
                if (_user_board[i][j])
                    ++result;
            }
        return result;
    }

    void set_user_ship_at(int i, int j)
    // side-effects: things that modify the values that we're passed-in
    {
        if (count_user_ships() < TOTAL_SHIPS)
        {
            _user_board[i][j] = true;
        }
    }

    bool operator()(bool userBoard, int i, int j) const
    {
        if (userBoard)
            return _user_board[i][j];
        return _computer_board[i][j];
    }

private:
    bool _user_board[7][7];
    bool _computer_board[7][7];
};

bool operator==(GameData const &a, GameData const &b)
{
    auto result{true};
    for (int i{0}; i < 7 && result; ++i)
    {
        for (int j{0}; j < 7 && result; ++j)
        {
            result = a(true, i, j) == b(true, i, j) &&
                     a(false, i, j) == b(false, i, j);
        }
    }
    return result;
}

int main()
{
    GameData g1, g2;
    g1.set_user_ship_at(1, 1);
    g1.set_user_ship_at(1, 1);
    g1.set_user_ship_at(2, 1);
    g1.set_user_ship_at(2, 2);
    g1.set_user_ship_at(2, 3);
    g1.set_user_ship_at(2, 4);
    g1.set_user_ship_at(3, 1);
    g1.set_user_ship_at(3, 2);
    g1.set_user_ship_at(3, 3);
    g1.set_user_ship_at(4, 1);
    std::cout << "the user has " << g1.count_user_ships() << " ships." << std::endl;
    g2.set_user_ship_at(1, 1);
    g2.set_user_ship_at(1, 1);
    // g2.set_user_ship_at(2, 1);
    g2.set_user_ship_at(2, 2);
    g2.set_user_ship_at(2, 3);
    g2.set_user_ship_at(2, 4);
    g2.set_user_ship_at(3, 1);
    g2.set_user_ship_at(3, 2);
    g2.set_user_ship_at(3, 3);
    g2.set_user_ship_at(4, 1);
    std::cout << "g2 " << (g1 == g2 ? "is" : "is not") << " equal to g1." << std::endl;
}
