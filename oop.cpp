#include <iostream>

// THEME: Object Oriented Programming
// 1) The most important concepts, are objects/their classes
// 2) classes are UDT, they add:
//              a) behavior - methods
//              b) constructor / destructors
//                  because we want the class to be responsible of having a valid state all through its life
//              c) access levels
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
        std::cout << "This game has ended!" << std::endl;
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
    {
        if (count_user_ships() < TOTAL_SHIPS)
        {
            _user_board[i][j] = true;
        }
    }

private:
    bool _user_board[7][7];
    bool _computer_board[7][7];
};

int main()
{
    {
        GameData game;

        game.set_user_ship_at(3, 5);
        game.set_user_ship_at(3, 3);
        game.set_user_ship_at(3, 1);
        game.set_user_ship_at(2, 3);
        game.set_user_ship_at(2, 1);
        game.set_user_ship_at(2, 2); // will be ignored

        std::cout << game.count_user_ships() << std::endl;
    }
    std::cout << "The program is ending..." << std::endl;
}