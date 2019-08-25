#include <iostream>
#include <cstdlib>
#include <ctime>
#include <list>
#include <iterator>

using namespace std;


bool isPrime(int num);

bool isFive(const int& value);

//bool removePrimes(list<int>& aList);
//IN: Takes in a list of integers
//MODIFY: Will remove all primes sandwiched between an even and odd number
//OUT: Return true if prime was removed and false if no prime was removed

int main()
{

  //unsigned seed = time(0);
  // srand(seed);
  
  //int arr[1000] = {(rand() % (-999 - 999 +1)) + -999};
  int arr[100]; 
  
  for(int i = 0; i < 100; i++){
    arr[i] = i;
  }

  /*for(int i = 0; i < 100; i++){
    if(isPrime(arr[i]))
      cout << endl << i << " Prime.";
    else
      cout << endl << i << '.';
  }
  */

  list<int> intList(arr, arr+100);
  list<int>::iterator listItr;
  list<int>::iterator last;
  list<int>::iterator forward;
  
  ostream_iterator<int> screen(cout, " ");
  copy(intList.begin(), intList.end(), screen);

  intList.remove_if(isFive);

  cout << endl << endl;

  copy(intList.begin(), intList.end(), screen);

  /*  listItr = intList.begin();
  listItr++;
  listItr++;
  listItr++;
  listItr++;
  */
  
  //intList.insert(listItr,5);

  //  intList.erase(intList.begin()++);
  for(listItr = intList.begin(); listItr != intList.end(); listItr++){
       if(listItr != intList.begin() && listItr != intList.end()){    
    last = listItr;
    forward = listItr;

    last--;
    forward++;
      
    /* if((isPrime(*listItr)) &&
         (((*last %2 ==0) && (*forward % 2 != 0))
          ||((*last %2 !=0 && *forward%2 ==0)))){
       listItr =  intList.erase(listItr);
      }
    */
    if(isPrime(*listItr))
      listItr = intList.erase(listItr);
       }
  }
    /*if(isPrime(*listItr))
     listItr =  intList.erase(listItr);
     }*/

    //if(*listItr %2 == 0)
  //intList.erase(listItr);

  //}


  cout << endl << endl;
  
  copy(intList.begin(), intList.end(), screen);
  
  return 0;
}

bool isFive(const int& value)
{
  return (value%5 == 0);
}


bool isPrime(int num)
{
  bool isPrime = true;

  for(int i = 2; i <= num / 2; i++){
    if(num % i == 0){
        isPrime = false;
    }
  }

  return isPrime;
}

