#include "Pet.h"
void Pet::setName(string inName){
    petName = inName;
  }
void Pet::setType(string inType){
    petType = inType;
  }
string Pet::getName(){
    return petName;
}
string Pet::getType(){
  return petType;
}
void Pet::setMood(int m){
  moodbar = m;
}
void Pet::setHunger(int h){
  hungerbar = h;
}
void Pet::setSleep(int s){
  sleepbar = s;
}

int Pet::GetMood(){
  return moodbar;
}
int Pet::GetHunger(){
  return hungerbar;
}
int Pet::GetSleep(){
  return sleepbar;
}
void Pet::AddMood(int m){
  moodbar += m;
  cout << "Mood changed by " << m << endl;
  if (moodbar < 5){
    cout << "Mood too low. Too sad and died >:(" << endl;
  }
}
void Pet::AddHunger(int h){
  hungerbar += h;
  setHunger(hungerbar);
  cout << "Fullness changed by " << h << endl;
  if (hungerbar < 5){
    cout << "Starved to death." << endl;
  }
}
void Pet::AddSleep(int s){
  sleepbar += s;
  setSleep(sleepbar);
  cout << "Rest changed by " << s << endl;
  if (sleepbar < 5){
    cout << "Didn't sleep enough. So sleeping forever now. Crashed from exhaustion." << endl;
  }
}
void Pet::PrintStatus(){
  cout << getName() << ", the " << getType() 
          << "\nMood Status: " << GetMood() << "\nHunger Status: " << GetHunger() << "\nSleep Status: " << GetSleep() << endl;
        cout << "----------------------" << endl;
}
void Pet::OutStatus(){
  cout << "\nMood Status: " << GetMood() << "\nHunger Status: " << GetHunger() << "\nSleep Status: " << GetSleep() << endl;
        cout << "----------------------" << endl;
}