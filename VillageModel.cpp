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

struct bilding
{
    int bildingType = bilding_type::none;
    int square = 0;
    bool enable_oven = false;
};

struct room
{
    int roomType = room_type::none;
    int square = 0;
};

struct flOOr
{
    int ceilingHeight = 0; 
    int rooms = 0;
    std::vector<room> availableRooms;
};

struct house
{
    int floors = 0;
    int square = 0;
    std::vector<flOOr> availableFloors;
    bool enable_oven = false;
};

struct site
{
    int number;
    house theHouse;
    std::vector<bilding> availableBildings;
    
};

void fill_house(house&);
void fill_floor(std::vector<flOOr>&);
void fill_room(std::vector<room>&);
void check_oven(house&);

int main()
{
    int amount;
    std::vector<site> model;
    std::cout << "Enter amount of sites:" << std::endl;
    std::cin >> amount;
    for (int i = 0; i < amount; i++)
    {
        std::cout << "Enter site's " << i << " information: " << std::endl;
        site current;
        current.number << i;
        fill_house(current.theHouse);
        model.push_back(current);
    }
}

void fill_house(house& theHouse)
{
    std::cout << "Enter information of the house:" << std::endl;
    std::cout << "1. Enter square of the house: ";
    std::cin >> theHouse.square;
    std::cout << "2. Enter number of floors: ";
    std::cin >> theHouse.floors;
    for (int i = 0; i < theHouse.floors; i++)
    {
        fill_floor(theHouse.availableFloors);
    }
    check_oven(theHouse);
}

void fill_floor(std::vector<flOOr>& availableFloors)
{
    flOOr current;
    availableFloors.push_back(current);
}

void fill_room(std::vector<room>& availableRooms)
{
    room current;
    availableRooms.push_back(current);
}

void check_oven(house& theHouse)
{
    int answer = 0;
    std::cout << "Is the oven in this bilding? (1 - Yes/ 0 - No): ";
    std::cin >> answer;
    if (answer == 1)
    {
        theHouse.enable_oven == true;
    }
}