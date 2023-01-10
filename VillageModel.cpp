#include <iostream>
#include <vector>

struct site
{

};
enum bilding_type
{
    house,
    grage,
    barn,
    bath
};
enum room_type
{
    bedroom,
    kitchen,
    bathroom,
    nursery,
    livingRoom
};
int main()
{
    int amount;
    std::cout << "Enter amount of sites:" << std::endl;
    std::cin >> amount;
    for (int i = 0; i < amount; i++)
    {
        std::cout << "Enter site's " << i << " information: " << std::endl;
    }
}