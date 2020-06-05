
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
    int getPrimeNum() const {
      int cnt = 0;
      for( Node<T>* ptr = head; ptr!=nullptr; ptr=ptr->next ){
        if ( ptr->isPrime() ) ++cnt;
      }
      return cnt;
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
      if (empty()) return;
      sort_merge( head, last/*, [](const T& a, const T&b){ return a<b; }*/ );
    }
    void sort_descending() {
      sort_selection( head/*, [](const T& a, const T&b){ return a>b; }*/ );
    }
  private:
    Node<T>** refByPrev( Node<T>* p ){ return p->prev==nullptr ? &head : &(p->prev->next); }
    Node<T>** refByNext( Node<T>* p ){ return p->next==nullptr ? &head : &(p->next->prev); }
    void swap( Node<T>* first, Node<T>* second ){
      if ( first->prev == nullptr ){
        std::swap( head, second->prev->next );
      } else if ( second->prev == nullptr ) {
        std::swap( first->prev->next, head );
      } else {
        std::swap( first->prev->next, second->prev->next );
      }
      if ( first->next == nullptr ){
        std::swap( last, second->next->prev );
      } else if ( second->prev == nullptr ) {
        std::swap( first->next->prev, last );
      } else {
        std::swap( first->next->prev, second->next->prev );
      }
      std::swap( first->prev, second->prev );
      std::swap( first->next, second->next );
      return;
    }
    //template<class Comp>
    Node<T>* sort_merge( Node<T>* first, Node<T>* end/*, Comp comp*/ ){
      if ( first == end ) {
        first->prev = first->next = nullptr;
        return last = first;
      }
      if ( first->next == end ){
        if ( first->val > end->val ){
          first->next = end->prev = nullptr;
          first->prev = end;
          last = end->next = first;
          return end;
        }
        first->prev = end->next = nullptr;
        last = first->next = end;
        end->prev = first;
        return first;
      }
      auto ptr1 = first;
      auto ptr2 = end;
      while(true){
        if ( ptr1 == ptr2 || ptr1->next == ptr2 ){ break; }
        ptr1 = ptr1->next;
        ptr2 = ptr2->prev;
      }
      auto base1_end = ptr1->next;
      auto base1 = sort_merge( first, ptr1 );
      auto base2 = sort_merge( base1_end, end );
      auto base = base1->prev;
      auto return_val = base1->val<base2->val ? base1 : base2;
      while(true){
        if ( base1 != nullptr && ( base2 == nullptr || base1->val < base2->val ) ){
          if ( base != nullptr ) {
            base->next = base1;
          }
          base1->prev = base;
          base = base1;
          base1 = base1->next;
        } else if ( base2 != nullptr ) {
          if ( base != nullptr ) {
            base->next = base2;
          } else {
            head = base2;
          }
          base2->prev = base;
          base = base2;
          base2 = base2->next;
        } else {
          base->next = nullptr;
          last = base;
          return return_val;
        }
      }
    }
    //template<class Comp>
    void sort_selection( Node<T>* begin/*, Comp comp*/ ){
      //print();
      //std::cout << std::endl;
      if ( begin == nullptr ) return;
      auto max_ptr = begin;
      for( Node<T>* ptr = begin; ptr!=nullptr; ptr=ptr->next ){
        if ( max_ptr->val < ptr->val ){
          max_ptr = ptr;
        }
      }
      if ( max_ptr != begin ) swap( max_ptr, begin );
      //std::cout << "swapped " << begin->val << " " << max_ptr->val << std::endl;
      sort_selection( max_ptr->next );
    }
    unsigned int length;
    Node<T>* head = nullptr;
    Node<T>* last = nullptr;
};

#endif