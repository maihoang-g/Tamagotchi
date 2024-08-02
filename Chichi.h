#include "Pet.h"
#ifndef CHICHI
#define CHICHI

class Chichi : public Pet{
public:
void ChichiPlay();
void Fetch();
void RollOver();
void MakeEvilPlan();
};
#endif
void Chichi::ChichiPlay(){
  cout << "What would you like your pet to do?" << endl;
  cout << " 1 - Fetch\n" << " 2 - Roll Over\n" << " 3 - Make a secret evil plan to take over the world\n"; 
  int input = 0;
  cin >> input;
  switch (input)
    {
      case 1:
        Fetch();
        break;
      case 2:
        RollOver();
        break;
      case 3:
        MakeEvilPlan();
        break;
    }
}
void Chichi::Fetch(){
  cout << "\nResponse: Running's pretty fun. Throw better though." << endl;
  AddMood(10);
  AddHunger(-10);
  AddSleep(-5);
}
void Chichi::RollOver(){
  cout << "\nResponse: This is actually nice. Don't get me dizzy now." << endl;
  AddMood(10);
}
void Chichi::MakeEvilPlan(){
  cout << "\nResponse: Not a single thought behind these eyes. Don't worry. But also, don't cross me, sweet human." << endl;
  AddMood(20);
}
