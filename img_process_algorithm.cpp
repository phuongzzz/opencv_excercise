#include <iostream>
#include <string>

using namespace std;

int selection = 0;
int k = 0;
void menu();
void laplace();
void canny();
void exit();

int main()
{
 while (true) {
   cout << endl;
   if (k == 1) {
     break;
   }
   menu ();
 }
 return 0;
}

void menu() {
  cout << endl;
  selection = 0;
  cout << " Please choose from the following options - \n";
  cout << " 1. Set username and password.\n";
  cout << " 2. Set launch codes.\n";
  cout << " 3. Exit.\n";
  cout << "Your selection:\t";
  cin >> selection;

  switch (selection) {
    case 1: {
      laplace();
      menu();
      break;
    }
    case 2: {
      canny();
      menu();
      break;
    }
    case 3: {
      exit();
    }
  }
}

void laplace() {
  cout << "Laplace" << endl;
  cin.get();
}

void canny() {
  cout << "canny" << endl;
}

void exit() {
  cout << endl;
  cout << "See you soon!\n";
  k = 1;
}
