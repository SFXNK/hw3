#include "stack.h"
#include <iostream>
using namespace std;
int main(){
  Stack<int> tmp;
  tmp.push(1);
  tmp.push(2);
  tmp.push(3);
  tmp.pop();
  cout<<tmp.top()<<endl;
  
}