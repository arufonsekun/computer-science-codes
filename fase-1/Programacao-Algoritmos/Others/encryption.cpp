#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
using namespace std;

string shiftRight(string message){
  string out = "";
  char letter;
  for (int i = 0; i < message.size(); i++){
    letter = message[i];
    if (letter >= 'a' & letter <= 'z' | letter >= 'A' & letter <= 'Z'){
      letter += 3;
    }
    out.append(letter);
  }
  return out;
}

string reverseShiftHalfLeft(string encryted){
  string reversed = "";
  string shiftReversed = "";
  char output;
  int middle = 0;

  for(int i = encryted.size(); i >= 0; i--){
    output = encryted[i];
    reversed.append(output);
  }

  if (reversed.size() % 2 == 0){
    middle = reversed.size() / 2;
  }
  else{
    middle = reversed.size() / 2 +1;
  }

  shiftReversed.append(reversed.substr(0, middle));

  for(int index = middle; index < reversed.size(); index ++){
    output = reversed[index] -1;
    shiftReversed.append(output);
  }

  return shiftReversed;
}

int main() {
  int cases = 0;
  vector<string> strings;
  char message[1000];
  string outMessage = "";
  cin >> cases;
  for (int i = 0; i <= cases ; i++){
    getline(cin, outMessage);
    outMessage = shiftRight(outMessage);
    outMessage = reverseShiftHalfLeft(outMessage);
    strings.push_back(outMessage);
  }
