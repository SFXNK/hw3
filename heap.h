#ifndef HEAP_H
#define HEAP_H
#include <functional>
#include <stdexcept>
#include <vector>
#include <algorithm>//for swap() only

template <typename T, typename PComparator = std::less<T> >
class Heap
{
public:
  /**
   * @brief Construct a new Heap object
   * 
   * @param m ary-ness of heap tree (default to 2)
   * @param c binary predicate function/functor that takes two items
   *          as an argument and returns a bool if the first argument has
   *          priority over the second.
   */
  Heap(int m=2, PComparator c = PComparator());

  /**
  * @brief Destroy the Heap object
  * 
  */
  //~Heap();

  /**
   * @brief Push an item to the heap
   * 
   * @param item item to heap
   */
  void push(const T& item);

  /**
   * @brief Returns the top (priority) item
   * 
   * @return T const& top priority item
   * @throw std::underflow_error if the heap is empty
   */
  T const & top() const;

  /**
   * @brief Remove the top priority item
   * 
   * @throw std::underflow_error if the heap is empty
   */
  void pop();

  /// returns true if the heap is empty

  /**
   * @brief Returns true if the heap is empty
   * 
   */
  bool empty() const;

    /**
   * @brief Returns size of the heap
   * 
   */
  size_t size() const;

private:
  /// Add whatever helper functions and data members you need below
  PComparator c_;
  std::vector<T> vec;
  int k_;


};

// Add implementation of member functions here
/*
Parent of the node at index i (except root node) is located at index (i-1)/k
Children of the node at index i are at indices (k*i)+1 , (k*i)+2 …. (k*i)+k
The last non-leaf node of a heap of size n is located at index (n-2)/k
*/
template <typename T, typename PComparator>
Heap<T,PComparator>::Heap(int m, PComparator c){
  c_=c;
  k_=m;
}

template <typename T, typename PComparator>
bool Heap<T,PComparator>::empty()const{
  return vec.empty();
}

template <typename T, typename PComparator>
size_t Heap<T,PComparator>::size()const{
  return vec.size();
}


template <typename T, typename PComparator>
void Heap<T,PComparator>::push(const T& item)
{
  vec.push_back(item);
  int p=vec.size()-1;
  if(p!=0)
    while(c_(vec[p],vec[(p-1)/k_])){
      std::swap(vec[p],vec[(p-1)/k_]);
      p=(p-1)/k_;
      if(p==0)
        break;
    }


}


// We will start top() for you to handle the case of 
// calling top on an empty heap
template <typename T, typename PComparator>
T const & Heap<T,PComparator>::top() const
{
  // Here we use exceptions to handle the case of trying
  // to access the top element of an empty heap
  if(empty()){
    // ================================
    // throw the appropriate exception
    // ================================
    throw std::underflow_error("");

  }
  // If we get here we know the heap has at least 1 item
  // Add code to return the top element
  return vec[0];


}

/*
Parent of the node at index i (except root node) is located at index (i-1)/k
Children of the node at index i are at indices (k*i)+1 , (k*i)+2 …. (k*i)+k
The last non-leaf node of a heap of size n is located at index (n-2)/k
*/

// We will start pop() for you to handle the case of 
// calling top on an empty heap
template <typename T, typename PComparator>
void Heap<T,PComparator>::pop()
{
  if(empty()){
    // ================================
    // throw the appropriate exception
    // ================================
    throw std::underflow_error("");

  }
  vec[0]=vec.back();
  vec.pop_back();
  int p=0;
  while(1){
    T bestchild;
    int besti=-1;
    for(int i=1;i<=k_;i++){
      if( (p*k_)+i >= vec.size() )
        break;
      if( !c_( vec[p] , vec[(p*k_)+i] ) ){

        if(besti==-1){

          bestchild=vec[(p*k_)+i];
          besti=(p*k_)+i;

        }
        else if( c_( vec[(p*k_)+i] , bestchild ) ){
          
          bestchild=vec[(p*k_)+i];
          besti=(p*k_)+i;
          
        }
          
      }
    }
    if(besti==-1){
      break;
    }
    std::swap(vec[p],vec[besti]);
    p=besti;
  }
  

}



#endif

