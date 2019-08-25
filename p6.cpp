//Martin Wilson
//p6.cpp
//Program that uses the STL to store integers and remove integers that meet
//certain criteria

#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <ctime>
#include <list>
#include <iterator>

using namespace std;

const int MIN = 100;
const int MAX = 999;
const int SIZE = 1000;
const int NUMOFVALS = 6;
const int WIDTH = 8;

bool isMFive(const int& value);
//IN: Takes in an int to check if it is a multiple of five
//MODIFY: Does not modify anything
//OUT: Will return true if the value is a multiple of 5 and false if it is not

bool isEven(int num);
//IN: Takes in an int to check if it is even
//MODIFY: Will not modify anything
//OUT: Will return true if the number is even and false if the number is odd

bool isPrime(int num);
//IN: Takes in a number to check if it is prime
//MODIFY: Will not modify anything
//OUT: Will return a true if the number given is prime and false if it is not 

void removeMFives(list<int>& aList);
//IN: Takes in a list of integers
//MODIFY: Will remove all multiples of 5 
//OUT: Will not return anything

bool removePrimes(list<int>& aList);
//IN: Takes in a list of integers
//MODIFY: Will remove all primes sandwiched between an even and odd number
//OUT: Return true if prime was removed and false if no prime was removed

void printValues(list<int> aList);
//IN: Takes in a list of integers
//MODIFY: Will not modify the list
//OUT: Will print all the values in the list

int main()
{
  unsigned seed = time(0);
  srand(seed);

  int arr[SIZE];
  bool cont = true;
  
  for(int i = 0; i < SIZE; i++){
    arr[i] = (rand() % (MAX - MIN + 1)+ MIN);
  }

  list<int> numList(arr, arr + SIZE);
  
  cout << endl << "Numbers with an * indicate it is a prime."
       << endl << "Completed insertion."
       << endl << "Printing values." << endl << endl;

  printValues(numList);

  cout << endl << endl << "Removing all multiples of five.";
  
  removeMFives(numList);

  cout << endl << "Printing values."
       << endl << endl;
  
  printValues(numList);

  cout << endl << endl << "Removing all primes with parity.";

  while(cont){
   cont = removePrimes(numList);
  }

  cout << endl << "Printing values." << endl << endl;
  
  printValues(numList);

  cout << endl;
  
  return 0;
}

bool isMFive(const int& value)
{
  return (value % 5 ==0);
}

bool isEven(int num)
{
  if(num % 2 == 0)
    return true;
  else
    return false;
}

bool isPrime(int num)
{
  bool isPrime = true;

  if(num == 0)
    return false;
  else if(num == 1)
    return false;
  else if(num == 2)
    return false; 
  else {
    for(int i = 2; i <= num / 2; i++){
      if(num % i == 0)
        isPrime = false;
    }
  }

  return isPrime;
}

void removeMFives(list<int>& aList)
{
  aList.remove_if(isMFive);
}

bool removePrimes(list<int>& aList)
{
  list<int>::iterator walkerTemp;
  list<int>::iterator prev;
  list<int>::iterator next;
  bool primeSwitch = false;
  
  for(walkerTemp = aList.begin(); walkerTemp != aList.end(); walkerTemp++){
    if(walkerTemp != aList.begin()){
        prev = walkerTemp;
        next = walkerTemp;
        prev--;
        next++;
    
        if(isPrime(*walkerTemp) && (((isEven(*prev))
               && (!isEven(*next))) ||
               (!isEven(*prev) && isEven(*next)))){
          walkerTemp = aList.erase(walkerTemp);
          primeSwitch = true; 
        }
      }
  }
    
  return primeSwitch;
}

void printValues(list<int> aList)
{
  int counter = 0;
  list<int>::iterator walkerTemp = aList.begin();
  
  while(walkerTemp != aList.end()){

    counter++;
    
    if(counter % NUMOFVALS == 0){
      cout << endl;
      counter = 0;
    }
    
    if(isPrime(*walkerTemp)){
      cout << setw(WIDTH - 1) << *walkerTemp << '*';
    } else {
      cout << setw(WIDTH) << *walkerTemp;
    }
    
    walkerTemp++;
  }
}
