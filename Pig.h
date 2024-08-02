#ifndef PIG
#define PIG
#include "Dragon.h"

class Pig: public Pet{
public:
void MudBath();
void Swim();
void Gossip();
void PigPlay();
};
#endif
void Pig::PigPlay(){
  cout << "What would you like your pet to do?" << endl;
  cout << " 1 - Take a mud bath. They're kinda stinky.\n" << " 2 - Take a swim. Did you know they do that?\n" << " 3 - Gossip with the spider on the door.\n"; 
  int input = 0;
  cin >> input;
  switch (input)
    {
      case 1:
        MudBath();
        break;
      case 2:
        Swim();
        break;
      case 3:
        Gossip();
        break;
    }
}
void Pig::MudBath(){
  cout << "I'm going to attract all the boys to the yard after this bath. Just watch." << endl;
  AddMood(10);
  AddHunger(-5);
  AddSleep(10);
}
void Pig::Swim(){
  cout << "I was trained by Phelps himself." << endl;
  AddMood(10);
  AddHunger(-10);
}
void Pig::Gossip(){
  cout << "Did you hear what Johnny said the other day?" << endl;
  AddMood(15);
  AddHunger(-5);
  AddSleep(5);
}