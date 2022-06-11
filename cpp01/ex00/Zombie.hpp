#include <string>
#include <iostream>

class Zombie
{
private:
    std::string name_;
public:
    Zombie(std::string _name);
    ~Zombie();
    void announce(void);
};

Zombie* newZombie(std::string name);
void randomChump(std::string name);