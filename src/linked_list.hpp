
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
      if ( head == nullptr ){
        head = last = n; 
      } else {
        n->next = head;
        head->prev = n;
        head = n;
      }
      return ++length;
    }
    unsigned int push_back( const T& v ){
      Node<T>* n = new Node<T>();
      n->val = v;
      if ( last == nullptr ){
        head = last = n; 
      } else {
        last->next = n;
        n->prev = last;
        head->prev = n;
        last = n;
      }
      return ++length;
    }
    unsigned int insert( const T& val, unsigned int index ){
      if ( index == 0 ){ return push_front(val); }
      Node<T>* n = new Node<T>();
      Node<T>* pre = at(index);
      n->val = val;
      n->next = pre->next;
      n->prev = pre;
      pre->next->prev = n;
      pre->next = n;
      return ++length;
    }
    unsigned int pop_front(){
      if (!empty()){
        Node<T>* tmp = head;
        if ( head->next == nullptr ){
          head = last = nullptr;
        } else {
          head->next->prev = nullptr;
          head = head->next;
        }
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
    void sort_merge( Node<T>* first, Node<T>* last, Comp comp ){
      if ( first == last ) return;
      if ( first->next == last){
        if ( first->val > last->val ){
          first->prev->next = last;
          last->next->prev = fist;
          auto t1 = first->prev;
          first->prev = last;
          first->next = last->next;
          last->prev = t1;
          last->next = first;
        }
        return;
      }
      auto ptr1 = first;
      auto ptr2 = last;
      while(true){
        ptr1 = ptr1->next;
        ptr2 = ptr2->prev;
        if ( ptr1 == ptr2 || ptr1->next == ptr2 ){ break; }
      }
      sort_merge( first, ptr1 );
      sort_merge( ptr1->next, last );
      // merge
      auto base = first->prev;
      auto base1 = first;
      auto base2 = pre1->next1;
      while(true){
        if ( (base1->val < base2->val && base1 != ptr1->next) ||  base2 == ptr1->next ){
          base->next = base1;
          base1->prev = base->next;
          base = base->next;
          base1 = base1->next;
        } else if ( base2 != ptr1->next ) {
          base->next = base2;
          base2->prev = base->next;
          base = base->next;
          base2 = base2->next;
        } else {
          break;
        }
      }
    }
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
    Node<T>* last;
};

#endif