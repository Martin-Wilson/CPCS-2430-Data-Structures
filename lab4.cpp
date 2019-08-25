//Martin Wilson
//lab4.cpp

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <iomanip>

using namespace std;

const int SIZE = 25;
const int MAXRAND = 60;
const int WIDTH = 3;

void insert(int value, int arr[], int& size);

int remove(int arr[], int& size);

void percDown(int arr[], int size, int start);

int main()
{
  unsigned seed = time(0);
  srand(seed);
  
  int heap[SIZE + 1];
  int value;
  int curSize = 0;

  cout << endl << endl << "Inputing values into the heap" << endl;
  
  for(int i = 1; i <= 15; i++){
    value = rand() % MAXRAND;
    cout << setw(WIDTH) << value << ' ';
    if(i%5 == 0){
      cout << endl;
    }
    insert(value, heap, curSize);
  }

  cout << endl << endl << "Removing and printing all the values from the heap"
       << endl;

  for(int i = 1; i <= 15; i++){
    cout << setw(WIDTH) << remove(heap, curSize) << ' ';
    if(i%5 == 0)
      cout << endl;
  }

  cout << endl << endl << "Inputing new values into the heap" << endl;

  for(int i = 1; i <= 15; i++){
    value = rand() % MAXRAND;
    cout << setw(WIDTH) << value << ' ';
    if(i%5 == 0)
      cout << endl;
    insert(value, heap, curSize);
  }

  cout << endl << endl << "Removing and printing all the values from the heap"
       << endl;

  for(int i = 1; i <= 15; i++){
    cout << setw(WIDTH) << remove(heap, curSize) << ' ';
    if(i%5 == 0)
      cout << endl;
  }
  
  return 0;
}

void insert(int value, int arr[], int& size)
{
  size += 1;
  int hole = size;
  int temp;
  
  arr[hole] = value;

  while(hole > 1 && arr[hole] < arr[hole/2]){
    temp = arr[hole/2];
    arr[hole/2] = arr[hole];
    arr[hole] = temp;
    hole = hole/2;
  }
}

int remove(int arr[], int& size)
{
  int temp = arr[1];
  arr[1] = arr[size];
  size--;
  percDown(arr,size,1);
  return temp;
}

void percDown(int arr[], int size, int start)
{
  int temp = arr[start];

  while((start * 2 <= size && temp > arr[start*2]) ||
        (start*2+1 <= size && temp > arr[start*2+1])){
    if(start*2+1 <= size && arr[start*2+1] < arr[start*2]){
      arr[start] = arr[start*2+1];
      start = start*2+1;
    } else {
      arr[start] = arr[start*2];
      start = start*2;
    }
  }
  arr[start] = temp;
}
