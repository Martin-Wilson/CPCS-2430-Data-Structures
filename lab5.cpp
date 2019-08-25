//Martin Wilson
//lab6.cpp

#include <fstream>
#include <iostream>

using namespace std;

const string INPUTFILE = "/home/fac/sreeder/class/cs2430/countyPop.dat";

struct Node
{
  int pop;
  string place;
};

void print(Node arr[], int counter);

void mergeSort(Node arr[], int s, int e);

void merge(Node arr[], int s, int e, int mid);

int main()
{
  
  Node arr[3200];
  int counter = 0;
  
  ifstream infile;
  infile.open(INPUTFILE.c_str());

  if(infile.fail()){
    cout << "File error press enter to exit program.";
    cin.get();
    return 0;
  }

  while(infile >> arr[counter].pop){

    getline(infile, arr[counter].place);
    
    counter++;
  }

  cout << endl << "Unsorted first ten values and last ten values." << endl;

  print(arr, counter);

  infile.close();

  mergeSort(arr, 0, counter);

  cout << endl << endl << "Sorted first ten values and last ten values."
       << endl;

  print(arr, counter);

  cout << endl;
  
  return 0;
}

void print(Node arr[], int counter)
{
  int last = counter - 10;
  
  for(int i = 0; i < 10; i++){
    cout << endl << i << ". " << arr[i].pop;
  }

  cout << endl;
  
  for(int i = last; i < counter; i++){
    cout << endl << i << ". " << arr[i].pop; 
  }

}

void mergeSort(Node arr[], int s, int e)
{
  if(s >= e)
    return;

  int mid = (s+e) / 2;

  mergeSort(arr, s, mid);
  mergeSort(arr, mid + 1, e);

  merge(arr, s, e, mid);

} 

void merge(Node arr[], int s, int e, int mid)
{
  
  int i;
  int j;
  int k;
  int leftsize = mid;
  int rightsize = (e - mid);
  
  Node *leftarr = new Node[leftsize];
  Node *rightarr = new Node[rightsize];

  for(int i = 0; i < leftsize; i++)
    leftarr[i].pop = arr[1 + i].pop;

  for(int j = 0; j < rightsize; j++)
    rightarr[j].pop = arr[mid + 1 + j].pop;

  i = 0;
  j = 0;
  k = 1;

  while(i < leftsize && j < rightsize){

    if(leftarr[i].pop <= rightarr[j].pop){
      arr[k].pop = leftarr[i].pop;
      i++;
    } else {
      arr[k].pop = rightarr[j].pop;
      j++;
    }
    k++;
  }

  while(i < leftsize){
    arr[k].pop = leftarr[i].pop;
    i++;
    k++;
  }

  while(j < rightsize){
    arr[k].pop = rightarr[j].pop;
    j++;
    k++;
  }

}
