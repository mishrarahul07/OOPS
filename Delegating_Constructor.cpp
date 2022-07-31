// Section 13
// Delegating Constructors
#include <iostream>
#include <string>

using namespace std;


// in this we are just using the three args constructor to do the job
// of all the constructor as a result of which we do not need to separately
// assign stuff to each constructor
// it only works through the constructor initialiser list

class Player
{
private:
   string name;
   int health;
   int xp;
public:
// Overloaded Constructors
    Player();
    Player(string name_val);
    Player(string name_val, int health_val, int xp_val);
};

Player::Player() 
    : Player {"None",0,0} 
    //here no args constructor calls 3 args constructor
    {
        cout << "No-args constructor" << endl;
    }

Player::Player(std::string name_val) 
   : Player {name_val,0, 0}  
    //here one args constructor calls 3 args constructor
   {
           cout << "One-arg constructor" << endl;
}
  
Player::Player(std::string name_val, int health_val, int xp_val) 
    : name{name_val}, health{health_val}, xp{xp_val} 
    //here only one constructor needs to be called
    {
            cout << "Three-args constructor" << endl;
}

int main() {
    
    Player empty;
    Player frank {"Frank"};
    Player villain {"Villain", 100, 55};
    
    return 0;
}

