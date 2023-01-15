#include <iostream>
#include <vector>

int totalSiteSquare = 0;
int totalBildingSquare = 0;

enum bilding_type
{
    no,
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
    int bildingType = bilding_type::no;
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
    int number = 0;
    int amountOfBildings = 0;
    int square = 0;
    house theHouse;
    std::vector<bilding> availableBildings;
    
};

void fill_house(house&);
void fill_floor(std::vector<flOOr>&, int);
void fill_room(std::vector<room>&, int);
void fill_bilding(std::vector<bilding>&, int);
void check_oven(bilding&);


int main()
{
    int amount;
    std::vector<site> model;
    std::cout << "Enter amount of sites:" << std::endl;
    std::cin >> amount;
    for (int i = 1; i <= amount; i++)
    {
        std::cout << "Enter site's " << i << " information: " << std::endl;
        site current;
        current.number = i;
        std::cout << "I. Enter square of the site: ";
        std::cin >> current.square;
        totalSiteSquare += current.square;
        std::cout << "II. Enter amount of bildings of the site: ";
        std::cin >> current.amountOfBildings;
        fill_house(current.theHouse);
        if (current.amountOfBildings > 1)
        {
            std::cout << "IV. Enter information of other bildings: " << std::endl;
            fill_bilding(current.availableBildings, current.amountOfBildings - 1);
        }
        model.push_back(current);
    }
    std::cout << "Total square of sites is " << totalSiteSquare << std::endl;
    std::cout << "Total bildings square is " << totalBildingSquare << std::endl;
}

void fill_house(house& theHouse)
{
    std::cout << "III. Enter information of the house:" << std::endl;
    std::cout << "1. Enter square of the house: ";
    std::cin >> theHouse.square;
    totalBildingSquare += theHouse.square;
    std::cout << "2. Enter number of floors: ";
    std::cin >> theHouse.floors;
    std::cout << "3. Enter information of floors: " << std::endl;
    for (int i = 0; i < theHouse.floors; i++)
    {
        fill_floor(theHouse.availableFloors, i);
    }
    char answer;
    std::cout << "4. Is the oven in this bilding? (Y/N): ";
    std::cin >> answer;
    if (answer == 'Y' || answer == 'y')
    {
        theHouse.enable_oven = true;
    }
    
}

void fill_floor(std::vector<flOOr>& availableFloors, int i)
{
    flOOr current;
    std::cout << " " << i + 1 << " floor: " << std::endl;
    std::cout << " Enter ceiling height: ";
    std::cin >> current.ceilingHeight;
    std::cout << " Enter amount of rooms: ";
    std::cin >> current.rooms;
    std::cout << " Enter information of rooms: " << std::endl;
    for (int j = 0; j < current.rooms; j++)
    {
        fill_room(current.availableRooms, j);
    }
    availableFloors.push_back(current);
}

void fill_room(std::vector<room>& availableRooms, int j)
{
    room current;
    int type;
    
    std::cout << "  " << j+1 << " room: " << std::endl;
    std::cout << "  Enter type of the room (1 - 5): ";
    std::cin >> type;
    if (type < 1 || type > 5)
    {
        std::cerr << "Error! Imvalid type!" << std::endl;
    }
    else
    {

        switch (type)
        {
        case room_type::bedroom:
            current.roomType = bedroom;
            break;
        case room_type::kitchen:
            current.roomType = kitchen;
            break;
        case room_type::bathroom:
            current.roomType = bathroom;
            break;
        case room_type::nursery:
            current.roomType = nursery;
            break;
        case room_type::livingRoom:
            current.roomType = livingRoom;
            break;
        }
        std::cout << "  Enter square of room: ";
        std::cin >> current.square;
    }
    
    availableRooms.push_back(current);
}

void fill_bilding(std::vector<bilding>& availableBildings, int i)
{
    bilding current;
    int type;
    std::string typeOf;
    std::cout << " Enter type of the bilding (1 - 3): ";
    std::cin >> type;
    switch (type)
    {
    case bilding_type::garage:
        current.bildingType = garage;
        typeOf = " garage";
        break;
    case bilding_type::barn:
        current.bildingType = barn;
        typeOf = " barn";
        break;
    case bilding_type::bath:
        current.bildingType = bath;
        typeOf = " bath";
        break;
    }

    std::cout << " Enter square of the" << typeOf << ": ";
    std::cin >> current.square;
    totalBildingSquare += current.square;
    if (current.bildingType == bath)
    {
        check_oven(current);
    }
    availableBildings.push_back(current);
}

void check_oven(bilding& current)
{
    char answer;
    std::cout << "Is the oven in this bilding? (Y/N): ";
    std::cin >> answer;
    if (answer == 'Y' || answer == 'y')
    {
        current.enable_oven = true;
    }
}
