
#ifndef SKENTAGON_LINKED_LIST_TEST_HEADER_INCLUDED
#define SKENTAGON_LINKED_LIST_TEST_HEADER_INCLUDED
#pragma once

#include "node.hpp"

template<class T>
class Linked_List {
  public:
    ~Linked_List(){ clear(); }

    Node<T>* at( unsigned int index ) {
      if ( length <= index ) return nullptr;
      Node<T>* ptr = head;
      for( unsigned int i=0; i<index; ++i ){
        ptr = ptr->next;
      }
      return ptr;
    }
    int get_length() const { return length; }
    bool empty() const { return length==0; }
    void print() const {
      for( Node<T>* ptr = head; ptr!=nullptr; ptr=ptr->next ){
        std::cout << ptr->val << " ";
      }
    }

    unsigned int push_front( const T& v ){
      Node<T>* n = new Node<T>();
      n->val = v;
      n->next = head;
      head = n;
      ++length;
    }
    unsigned int push_back( const T& v ){}
    unsigned int insert( const T& val, unsigned int index );
    unsigned int pop_front(){
      if (!empty()){
        Node<T>* tmp = head;
        head = head->next;
        --length;
        delete tmp;
      }
      return length;
    }
    void clear() { while(empty()){ pop_front(); } }
    void sort_ascending() {
      sort_merge( 0, length, [](const T& a, const T&b){ return a<b; } );
    }
    void sort_descending() {
      sort_merge( 0, length, [](const T& a, const T&b){ return a>b; } );
    }
  private:
    template<class Comp>
    void sort_merge( unsigned int first, unsigned int last, Comp comp ){}
    template<class Comp>
    void sort_selection( Comp comp ){
      for( Node<T>* ptr = head; ptr!=nullptr; ptr=ptr->next ){
        Node<T>* min = ptr;
        for( Node<T>* dx = ptr; dx!=nullptr; dx=dx->next ){
          if ( comp( min->val, dx->val ) ){
            min = dx;
          }
        }
        if ( comp( ptr->val, min->next->val ) ) continue;
        // swap;
        //ptr = 
        //min->next = 
      }
    }
    unsigned int length;
    Node<T>* head;
};

#endif