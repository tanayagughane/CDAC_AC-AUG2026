//============================================================================
// Name        : Question4.cpp
// Author      : Tanaya Gughane
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================


#include <iostream>
#include <string>
using namespace std;

class Entity
{
private:
    string name;
    int health;
    int level;
    string type;

public:

    // Setter for name
    Entity& setName(const string& name)
    {
        this->name = name;
        return *this;
    }

    // Setter for health
    Entity& setHealth(int health)
    {
        this->health = health;
        return *this;
    }

    // Setter for level
    Entity& setLevel(int level)
    {
        this->level = level;
        return *this;
    }

    // Setter for type
    Entity& setType(const string& type)
    {
        this->type = type;
        return *this;
    }

    // Getters
    string getName() const
    {
        return name;
    }

    int getHealth() const
    {
        return health;
    }

    int getLevel() const
    {
        return level;
    }

    string getType() const
    {
        return type;
    }

    // Display information
    void displayInfo() const
    {
        cout << "Name   : " << name << endl;
        cout << "Health : " << health << endl;
        cout << "Level  : " << level << endl;
        cout << "Type   : " << type << endl;
        cout << endl;
    }
};

int main4()
{
    // Create 3 entities
    Entity player, enemy, item;

    // Method Chaining
    player.setName("Aragorn")
          .setHealth(100)
          .setLevel(10)
          .setType("Player");

    enemy.setName("Orc")
         .setHealth(60)
         .setLevel(5)
         .setType("Enemy");

    item.setName("HealthPotion")
        .setHealth(0)
        .setLevel(1)
        .setType("Item");


    // Display all entities
    cout << "===== GAME ENTITIES =====" << endl;

    player.displayInfo();
    enemy.displayInfo();
    item.displayInfo();


    // Getters
    cout << "Player Name  : " << player.getName() << endl;
    cout << "Player Health: " << player.getHealth() << endl;
    cout << "Player Level : " << player.getLevel() << endl;
    cout << "Player Type  : " << player.getType() << endl;

    return 0;
}




