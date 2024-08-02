#include <iostream>
using namespace std;
#ifndef PET_H
#define PET_H

class Pet{
private:
  string petName, petType;
  int moodbar, hungerbar, sleepbar;
public:
  Pet(){
    petName = "";
    petType = "";
    moodbar = 0;
    hungerbar = 0;
    sleepbar = 0;
  }
  Pet(string inName, string inType, int mbar, int hbar, int sbar){
    petName = inName;
    petType = inType;
    moodbar = mbar;
    hungerbar = hbar;
    sleepbar = sbar;
  }
  void setName(string inName);
  void setType(string inType);
  string getName();
  string getType();

  void setMood(int);
  void setHunger(int);
  void setSleep(int);
  int GetMood();
	int GetHunger();
	int GetSleep();

  void PrintStatus();
  void OutStatus();

  void AddMood(int h);
	void AddHunger(int m);
	void AddSleep(int s);
};

#endif