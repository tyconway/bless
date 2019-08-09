#include<iostream>
#include<vector>
#include<fstream>
#include<sstream>
#include<string>
using namespace std;

// Take all couts into .h file and call from here as commands.

int getCount() {
  // TODO: Turn this into function that returns  int count
  ifstream countFile("./count.txt", ios_base::app);
  string input;
  getline(countFile, input);
  istringstream stream(input);
  string countString;
  stream >> countString;
  int count = atoi(countString.c_str());
  return count;
}

void setCount(int newCount) {
  ofstream countFileOut;
  countFileOut.open("./count.txt");
  countFileOut << newCount;

}

void appendBlessing(string text) {
  int count = getCount();

  // Appends text to hist.txt
  // If count is 0, start a new file.
  // Else, append.
  ofstream hist_file;
  if (count == 0) {
    // open without flag
    hist_file.open("./hist.txt");
    hist_file << "(" << getCount() + 1 << ") " << text << endl;
  } else if (count > 0) {
    hist_file.open("./hist.txt", ios_base::app);
    hist_file << "(" << getCount() + 1 << ") " << text << endl;
  }

  count += 1;
  setCount(count);
}

void readBlessings() {
  ifstream hist_file("./hist.txt", ios_base::app);
  cout << hist_file.rdbuf();
}

void clearBlessings() {
  ofstream hist_file;
  hist_file.open("./hist.txt");
  hist_file << "You have not counted any blessings yet.\n"
               "Give it a try with:  bless me \"<description>\"\n";

  cout << "Your list was cleared.\n";
  setCount(0);
}

int main(int argc, char *argv[]) {
  if (!argv[1]) { // No passed arguments.
    cout << "~~~~~~~~~~ Welcome to bless! ~~~~~~~~~~\n"
            "A command line implementation of the\n"
            "old hymn \"Count Your Many Blessings\".\n";
    cout << "\nusage: bless <command> [args]"
            "\n\n"
            "Add a new blessing to your list:\n"
            "bless me \"<description of blessing>\"" 
            "\n\n"
            "See all your blessings counted:\n"
            "bless me\n"
            "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
  } 
  
  else if (argv[1] && string(argv[1]) == "me" && !argv[2]) { // If we don't check, next line will access something that doesn't exist.
    // Reads blessings
    readBlessings();
  } 
  else if (argv[1] && string(argv[1]) == "clear") {
    clearBlessings();
  }
  
  else if (argv[2]) {
      appendBlessing(string(argv[2]));
      cout << "Your blessing was counted.\n";

      // Loop here that if there are more than two args, 
      // loops through them and adds them to the list.
      for (
  } 
  
  else {
      cout << "Oops!\n\n"
              "Either an invalid command or too many arguments!\n"
              "We're still working on allowing you to add as many\n"
              "at one time as you'd like.\n";
  }
}  
