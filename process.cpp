//Martin Wilson
//process.cpp
//Program to test string processing

#include <iostream>
#include <cstring>
#include <cctype>

using namespace std;

int main()
{
  string ans;
  int length;
  
  cout << endl << "Word please";
  cin >> ans;

  length = strlen(ans);
  
  for(int i = 0; i < length; i++){
    ans[i] = tolower(ans[i]);

    if(ispunct(ans[i])){
      ans.erase(i);
    }
  }

  cout << endl << endl << ans;
  
  return 0;
}
