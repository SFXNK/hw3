#ifndef STACK_H
#define STACK_H

#include <vector>
#include <stdexcept>

// Use inheritance from std::vector (choose public/private) as appropriate
template <typename T>
class Stack : private std::vector<T> {

public:
    bool empty() const;
    size_t size() const;
    void push(const T& item);
    void pop();  // throws std::underflow_error if empty
    const T& top() const; // throws std::underflow_error if empty
    // Add other members only if necessary
private:
    std::vector<T> vec_;

};

template <typename T>
bool Stack<T>::empty() const{
    return vec_.empty();
}

template <typename T>
size_t Stack<T>::size() const{
    return vec_.size();
}

template <typename T>
void Stack<T>::push(const T& item){
    vec_.push_back(item);
}

template <typename T>
void Stack<T>::pop(){
    if(vec_.empty())
        throw std::underflow_error("");
    else
        vec_.pop_back();
}

template <typename T>
const T& Stack<T>::top() const{
    if(vec_.empty())
        throw std::underflow_error("");
    else
        return vec_.back();
}

#endif