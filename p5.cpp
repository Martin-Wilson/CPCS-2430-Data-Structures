//Martin Wilson
//p5.cpp
//Program that generates a table of distinct words from a natural text
//User will be able to search through the table to find words.

#include <iostream>
#include <cstring>
#include <cctype>
#include <fstream>

using namespace std;

const char YES = 'y';
const string FNAME = "/home/st/wilsonmartin/ds2430/ulyss12.txt";
const int FIVE = 5;
const int TSIZE = 30000;

struct Node
{
  int key;
  int count;
  string value;
  Node* next;
};

void search(string word, Node* table[]);
//IN: Takes in a string and the table
//MODIFY: Does not modify anything, searches the list for instances of the
//word
//OUT: Does not return anything, prints out wether the word is in the table or
//not, if found will print the count

void insert(string word, Node* table[], int length, int& numOfCollisions);
//IN: Takes in a string, the hash table of pointers, and the length of the
//string and a pass by refernece int to count the number of collisions
//MODIFY: Will add the word into the hash table
//OUT: Does not return anything

void preProcess(string& input, int length);
//IN: Takes in a pass by reference string to process and the length of the
//string
//MODIFY: Will remove unnecessary punctuation and convert all letters to
//lowercase
//OUT: Will not return anything

unsigned long hashFunction(string input, int length);
//IN: Takes in a string and the length of the string
//MODIFY: Hashes the string
//OUT: Returns the hashed string number

void statChecker(int& numOfUniqueWords, int& totalWords,
                 int& maxNodes, Node* table[]);
//IN:Takes in pass by reference integers to tally the number of collisions,
//the number of unique words, the total words, the maximum number of nodes
//in the table and the table
//MODIFY: Does not modify the table
//OUT: Does no return anything

int main()
{
  char ans = 'y';
  string word;
  string searchWord;
  int maxNodes = 0;
  int numOfCollisions = 0;
  int numOfUniqueWords = 0;
  int totalWords = 0;
  int length;

  Node* table[TSIZE] = {nullptr};
  Node* delptr;
  Node* walker;
  
  ifstream infile;
  infile.open(FNAME.c_str());

  if(infile.fail()){
    cout << "File error please press enter to exit program.";
    cin.get();
    return 0;
  }

  while(infile >> word){
    length = word.size();
    if(length > FIVE){
      preProcess(word, length);
      insert(word, table, length, numOfCollisions); 
    }
  }

  infile.close();
  
  statChecker(numOfUniqueWords, totalWords, maxNodes, table);

  cout << endl << endl << "Number of collisions: " << numOfCollisions
       << endl << "Number of unique words: " << numOfUniqueWords
       << endl << "Total number of words: " << totalWords
       << endl << "Max number of nodes: " << maxNodes
       << endl << "Load factor: " << static_cast<float>(totalWords)/TSIZE; 

  while(tolower(ans) == YES){
    cout << endl << endl << "Type in a word to search for in Ulyss: ";
    cin >> searchWord;

    search(searchWord, table);

    cout << endl << "Again?(y/n): ";
    cin >> ans;
    
  }

  
  for(int i = 0; i < TSIZE; i++){
    if(table[i] != nullptr){
      walker = table[i];
      while(walker != nullptr){
        delptr = walker;
        walker = walker -> next;
        delete delptr;
      }
      table[i] = nullptr;
    }
  }

  
  
  return 0;
}

void search(string word, Node* table[])
{
  int length =  word.size();

  unsigned long key = hashFunction(word, length);
  
  if(table[key] != nullptr){
    cout << endl << "The word " << word << " was in Ulyss"
         << endl << "The word count was " << table[key] -> count << '.';

  } else {
    cout << endl << "The word was not found in Ulyss";
  }
}

void insert(string word, Node* table[], int length, int& numOfCollisions)
{
  unsigned long key1 = hashFunction(word, length);

  Node* walker = table[key1];

  if(table[key1] == nullptr){

    table[key1] = new Node;
    table[key1] -> count = 1;
    table[key1] -> value = word;
    table[key1] -> key = key1;
    table[key1] -> next = nullptr;
  } else {
    numOfCollisions++;
    
    while(walker -> next != nullptr && walker -> value != word)
      walker = walker -> next;

    if(walker -> next == nullptr){
      walker  = new Node;
      walker -> count = 1;
      walker -> value = word;
      walker -> key = key1;
      walker -> next = nullptr;
    }
    if(walker -> value != word){
      walker -> count ++;
    }

    walker = walker -> next;
  }
  
}

void preProcess(string& input, int length)
{
  for(int i = 0; i < length; i++){
    input[i] = tolower(input[i]);
    if(!isalpha(input[i])){
      input.erase(i--, 1);
      length = input.size();
    }
  }
 
}

unsigned long hashFunction(string input, int length)
{
  unsigned long val = 17;

  for(int i = 0; i < length; i++)
    val = val * 33 + input[i];

  val = val%TSIZE;
  return val;
}


void statChecker(int& numOfUniqueWords, int& totalWords,
                 int& maxNodes, Node* table[])
{
  Node* walker;
  int nodeNum = 0;
  
  for(int i = 0; i < TSIZE; i++){
    if(table[i] != nullptr){
      walker = table[i];
      nodeNum = 1;
      while(walker != nullptr){
        totalWords += walker -> count;
        numOfUniqueWords++;
        nodeNum++;
        walker = walker ->next;
      }
            
      if(nodeNum > maxNodes)
        maxNodes = nodeNum;

      nodeNum = 0;
    }
  }
}

