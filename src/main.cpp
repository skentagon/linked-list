
#include <iostream>
#include <string>
#include "linked_list.hpp"

template<class T>
bool work(){

  std::string s;
  Linked_List<T> list;
  while(true){
    std::cout << "Please enter a number: " << std::flush;
    std::cin >> s;
    list.push_back(std::stol(s));
    std::cout << "Do you want another num (y or n): " << std::flush;
    std::cin >> s;
    if ( s == "n" ) break;
  }

  std::cout << "Your linked list is: ";
  list.print();
  std::cout << std::endl;

  std::cout << "Sort ascending or descending (a or d)? " << std::flush;
  std::cin >> s;
  if ( s == "a" ){
    list.sort_ascending();
  } else {
    list.sort_descending();
  }

  std::cout << "Your linked list is: ";
  list.print();
  std::cout << std::endl;

  std::cout << "You have " << list.getPrimeNum() << " prime number(s) in your list." << std::endl;

  std::cout << "Do you want to do this again (y or n)? " << std::flush;
  std::cin >> s;
  if ( s == "n" ) return true;
  return false;

}

int main() {

  while(true){

    std::string s;
    std::cout << "Do you want to use unsigned int mode? (y or n): " << std::flush;
    std::cin >> s;
    if ( s == "y" ){
      if (work<unsigned int>()) break;
    } else {
      if (work<int>()) break;
    }

  }
}