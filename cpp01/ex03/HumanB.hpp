#include "Weapon.hpp"

class HumanB
{
private:
    std::string name_;
    Weapon *weapon_;

public:
    HumanB(std::string name);
    void setWeapon(Weapon& weapon);
    void attack(void);
};