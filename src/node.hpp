
#ifndef SKENTAGON_LINKED_LIST_TEST_NODE_HEADER_INCLUDED
#define SKENTAGON_LINKED_LIST_TEST_NODE_HEADER_INCLUDED
#pragma once

#include <cmath>

template<class T>
class Node {
  public:
    T val;
    Node* next = nullptr;
    Node* prev = nullptr;
    bool isPrime(){
      if ( val < 2 ) return false;
      if ( val == 2 ) return true;
      if ( val%2 == 0 ) return false;
      long long max = static_cast<long long>(std::sqrt(val));
      for( long long i=3; i<max; i+=2 ){
        if ( val%i == 0 ) return false;
      }
      return true;
    }
};

#endif