#include "heap.h"
#include <iostream>
using namespace std;
int main(){
  Heap<int,greater<int>> h(3,greater<int>());
  h.push(1);
  h.push(2);
  h.push(3);
  h.push(4);
  h.push(5);
  cout<<h.top()<<endl;
  h.pop();
  cout<<h.top()<<endl;
  h.pop();
  cout<<h.top()<<endl;
  h.pop();
  cout<<h.top()<<endl;
  h.pop();
  cout<<h.top()<<endl;
}