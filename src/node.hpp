
#ifndef SKENTAGON_LINKED_LIST_TEST_NODE_HEADER_INCLUDED
#define SKENTAGON_LINKED_LIST_TEST_NODE_HEADER_INCLUDED
#pragma once

#include <cmath>

template<class T>
class Node {
  public:
    T val;
    Node* next = nullptr;
    bool isPrime(){
      if ( val < 2 ) return false;
      if ( val == 2 ) return true;
      if ( val%2 == 0 ) return false;
      double max = std::sqrt(val);
    }
};

#endif