#ifndef DRAGON
#define DRAGON
#include "Chichi.h"

class Dragon : public Pet{
public:
void DragonPlay();
void MakeSmores();
void GrillSteak();
void FireTricks();
};
#endif
void Dragon::DragonPlay(){
  cout << "What would you like your pet to do?" << endl;
  cout << " 1 - Make S'mores\n" << " 2 - Hold a whole barbeque grilled steak\n" << " 3 - Perform fire tricks\n"; 
  int input = 0;
  cin >> input;
  switch (input)
    {
      case 1:
        MakeSmores();
        break;
      case 2:
        GrillSteak();
        break;
      case 3:
        FireTricks();
        break;
    }
}
void Dragon::MakeSmores(){
  cout << "Response: They might be a little burnt. I got carried away." << endl;
  AddMood(10);
  AddHunger(30);
}
void Dragon::GrillSteak(){
  cout << "Response: I did forget to season it. Bon appetit" << endl;
  AddMood(10);
  AddHunger(35);
}
void Dragon::FireTricks(){
  cout << "Response: I'm literally too good for the amount of enthusiasm I'm getting. Look at this." << endl;
  AddMood(10);
  AddHunger(-10);
  AddSleep(-10);
}