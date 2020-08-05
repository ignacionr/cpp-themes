#include <iostream>

// THEME: Structured Programming
// 1) break down responsibilities into smaller tasks
// <return type> <fn name> <paramater list>
// 2) each sub-program has a single point of entry, single point of exit
// 3) we define UDT to hold significant data
// UDT = User Defined Types
// struct { <fields> }

typedef struct TGameData
{
    bool _user_board[7][7]{false};
    bool _computer_board[7][7]{false};
} GameData;

int count_user_ships(GameData &data)
{
    auto result{0};
    for (auto i{0}; i < 7; ++i)
        for (auto j{0}; j < 7; ++j)
        {
            if (data._user_board[i][j])
                ++result;
        }
    return result;
}

int main()
{
    GameData game;
    game._user_board[3][5] = true;
    game._user_board[3][3] = true;
    std::cout << count_user_ships(game) << std::endl;
}