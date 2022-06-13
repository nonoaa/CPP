#include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap
{
public:
    FragTrap();
    FragTrap(const std::string &name);
    FragTrap(const FragTrap &src);
    FragTrap &operator=(const FragTrap &src);
    virtual ~FragTrap();

    void attack(const std::string& target);
    void highFiveGuys(void);
};