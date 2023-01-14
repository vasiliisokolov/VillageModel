#include <iostream>
#include <vector>

enum bilding_type
{
    none,
    garage,
    barn,
    bath
};

enum room_type
{
    none,
    bedroom,
    kitchen,
    bathroom,
    nursery,
    livingRoom
};

struct floor
{
    bool enable = false;
    int ceilingHeight = 0;
};

struct room
{
    bool enable = false;
    int roomType = room_type::none;
    int square = 0;
};

struct house
{

};

struct bilding
{
    bool enable = false;
    int bildingType = bilding_type::none;
    int square = 0;
    bool enable_oven = false;
};

struct site
{
    int number;
    house theHouse;
};

int main()
{
    int amount;
    std::vector<site> model;
    std::cout << "Enter amount of sites:" << std::endl;
    std::cin >> amount;
    for (int i = 0; i < amount; i++)
    {
        std::cout << "Enter site's " << i << " information: " << std::endl;
    }
}