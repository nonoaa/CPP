#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "Brain.hpp"

int main()
{
    const Animal* j = new Dog();
    const Animal* i = new Cat();

    delete j;
    delete i;
    
    Animal *animals[10];

    for (int i = 0; i < 10; i++)
    {
        if (i < 5)
            animals[i] = new Dog();
        else
            animals[i] = new Cat();
    }
    Dog copy1(*(Dog *)animals[0]);
    Cat copy2(*(Cat *)animals[0]);

    copy1.getBrain()->setIdea(0, "laugh");
    copy2.getBrain()->setIdea(0, "cry");

    copy1.getBrain()->getIdea(0);
    copy2.getBrain()->getIdea(0);
    ((Dog *)animals[0])->getBrain()->getIdea(0);
    ((Cat *)animals[1])->getBrain()->getIdea(0);

    std::cout << &copy1 << std::endl;
    std::cout << animals[0] << std::endl;

    for (int i = 0; i < 10; i++)
    {
        delete animals[i];
    }
    return 0;
}