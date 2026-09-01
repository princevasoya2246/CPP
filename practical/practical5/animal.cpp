#include <iostream>
#include <string>

using namespace std;

class Animal
{
public:
    virtual void sound() = 0;
    virtual void move() = 0;
};

class Dog : public Animal
{
public:
    void sound()
    {
        cout << "Dog says: Woof Woof" << endl;
    }
    void move()
    {
        cout << "Dog is running" << endl;
    }
};

class Bird : public Animal
{
public:
    void sound()
    {
        cout << "Bird says: Chirp Chirp" << endl;
    }
    void move()
    {
        cout << "Bird is flying" << endl;
    }
};

int main()
{
    Animal *animals[2];
    Dog d;
    Bird b;
    animals[0] = &d;
    animals[1] = &b;

    for (int i = 0; i < 2; i++)
    {
        animals[i]->sound();
        animals[i]->move();
        cout << endl;
    }

    return 0;
}