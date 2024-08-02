#include <fstream>
#include <iostream>
#include <string>
#include <map>
using namespace std;
#include "Pig.h"

void PrintMenu() {
  cout << "--------------------------------------------------------------"
       << endl;
  cout << "Please make your choice:" << endl;
  cout << " 0 - Exit" << endl;
  cout << " 1 - Create New Pet" << endl;
  cout << " 2 - Check Pet Status and Play with Pet" << endl;
  cout << "--------------------------------------------------------------"
       << endl;
}
void PrintPetOptions() {
  cout << "--------------------------------------------------------------"
       << endl;
  cout << "Which type of pet would you like?" << endl;
  cout << " 1 - A dragon" << endl;
  cout << " 2 - A chihuahua" << endl;
  cout << " 3 - A pig" << endl;
  cout << "--------------------------------------------------------------"
       << endl;
}

int main() {
  int menuchoice, petchoice, playChoice, i;
  Chichi chichi; //make objects of classes
  Dragon dragon;
  Pig pig;
  string petname, choosepet;
  Pet pet;
  int SIZE = 5;
  Pet petplay[SIZE]; //make an array object of pet
  
  map<int, string> map1 = //create a dictionary of pet options
            {{1, "Dragon",},{2, "Chihuahua"}, {3, "Pig"}};
  if (menuchoice == 0) { //exit button
    return -1;
  }
  while (menuchoice != 0) {
    PrintMenu();
    cin >> menuchoice;
    if (menuchoice == 1) { //Creates new pet
      cout << "Creating new pet..." << endl;
      PrintPetOptions();
      cin >> petchoice;
      cout << "You've selected a " << map1.at(petchoice) << endl;
      cout << "Please name your new pet." << endl;
      cin >> petname;
      cout << "You've adopted " << petname << ", the " << map1.at(petchoice) << "!"<< endl; //uses dictionary key:value to match the option chosen to the pet type of that value (refer to line 39)
      fstream myfile;
      myfile.open("currentpets.txt", ios::app); //opens new file to store the pets you just created
      myfile << petname << " " << map1.at(petchoice) << " "; //stores info with a space in between
      srand(time(NULL)); //seed the random number so that it's different every time
      for (int i = 0; i < 3; i++){ //3 values for mood, hunger, and sleep so i < 3 would make sense
        int randNum = rand()%(100) + 1; //generate a random number between 0 and 100 inclusive
        myfile << randNum << " "; //put the 3 numbers into the file. this corresponds to their health out of 100
      }
      myfile << endl;
    } 
    else if (menuchoice == 2) { //Play and interact with pets
      cout << "Loading all pets..." << endl;
      string name, type;
      int m, h, s, i = 0;
      ifstream myfile;
      myfile.open("currentpets.txt"); //loading all the pets from the file
      while(myfile >> name >> type >> m >> h >> s){ //retrieving it into variables since this way we don't have to convert string to int or vice versa and everything is nicely distributed
        cout << "----------------------" << endl;
        petplay[i].setName(name);
        petplay[i].setType(type);
        petplay[i].setMood(m);
        petplay[i].setHunger(h);
        petplay[i].setSleep(s);
        petplay[i].PrintStatus(); //after retrieving the info, output all of the pets and their current stats
        i++;
      }
      cout << "Type 0 to exit. 1 to play with pet" << endl;
      cin >> playChoice;
      if (playChoice == 0) { //if type 0 then exit and return to main menu
        return -1;
      }
      while (playChoice != 0) {
        cout << "Type the name of the pet you want to play with! Type exit to quit." << endl;
        cin >> choosepet;
        if (choosepet == "exit" || choosepet == "Exit"){ //type exit to quit here. this loops so if it gets tiring theres also an option to quit here.
          break;
        }
        else{
          for (i = 0; i < 5; i++){
            if (petplay[i].getName() == choosepet){ //if the input text of the pet name indeed matches...
              if (petplay[i].getType() == "Dragon"){ //and if the type of that pet name matches one of these 3...
                dragon.DragonPlay(); //then carry out these switch cases inside inherited classes
              }
              if (petplay[i].getType() == "Chihuahua"){
                chichi.ChichiPlay();
              }
              if (petplay[i].getType() == "Pig"){
                pig.PigPlay();
              }
            }
          }
        }
      }
    }
  }
  
  return 0;
}
