#include <iostream>

// THEME: Structured Programming
// 1) break down responsibilities into smaller tasks
// <return type> <fn name> <paramater list>
// 2) each sub-program has a single point of entry, single point of exit
// 3) we define UDT to hold significant data
// UDT = User Defined Types
// struct { <fields> }

struct GameData
{
    bool _user_board[7][7]{false};
    bool _computer_board[7][7]{false};
};

int count_user_ships(GameData &data)
{
    auto result{0};
    for (auto i{0}; i < 7; ++i)
    {
        for (auto j{0}; j < 7; ++j)
        {
            if (data._user_board[i][j])
            {
                ++result;
            }
        }
    }
    data._user_board[6][6] = true;
    return result;
}

int add(int const &a, int const &b)
{
    int c{a};
    c += b;
    return c;
}

int main()
{
    int i{3}, j{5};
    std::cout << "the addition is " << add(i, j) << std::endl;
    std::cout << "i is " << i << std::endl;
    std::cout << "j is " << j << std::endl;
}