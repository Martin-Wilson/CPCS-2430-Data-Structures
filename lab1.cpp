//Martin Wilson
//lab1.cpp

#include <iostream>

using namespace std;

const int MAX = 100;
const int MIN = 10;
const int AMOUNT = 13;
const char YES = 'y';

int findMax(int arr[]);

int main()
{
  char again = 'y';
  int arr[AMOUNT];
  int count;
  int ans;

  cout << endl << "Hello and welcome to lab 1 in CPSC 2430!!" << endl << endl;

  while(again == YES){
    ans = -1;
    count = 0;
    for(int i = 0; i < AMOUNT; i++)
      arr[i] = 0;
    
    while(count < AMOUNT){
      cout << "Input an even number from "
           << MIN << " to " << MAX << ": ";
      cin >> ans;
      if(ans >= MIN && ans <= MAX && ans%2 == 0){
        arr[count] = ans;
        count++;
      }
    }
    
    cout << endl << "Printing array values. ";
    
    for(int i = 0; i < AMOUNT; i++)
      cout << endl << i << ' ' << arr[i];
    
    cout << endl << endl << "The maximum value is " << findMax(arr);

    cout << endl << "Would you like to repeat?(y/n) ";
    cin >> again;
  }

  cout << endl << "End of lab 1" << endl;
  return 0;
}

int findMax(int arr[])
{
  int counter = 0;
  int max = arr[counter];

  while(counter < AMOUNT){
    counter++;
    if(arr[counter] > max)
      max = arr[counter];
    
  }

  return max;
}

