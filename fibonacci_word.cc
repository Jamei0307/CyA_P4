#include <iostream>

#include "fibonacci_word.h"

FibonacciWord::FibonacciWord() {}
FibonacciWord::FibonacciWord(std::string palabra, int tam) {
  palabra_ = palabra;
  tam_palabra_ = tam;
  posicion_ = 0;
}

FibonacciWord::~FibonacciWord() {}

std::string FibonacciWord::get_palabra() { return palabra_; }
int FibonacciWord::get_tam() { return tam_palabra_; }
bool FibonacciWord::get_is_fibonacci() { return is_fibonacci_; }
int FibonacciWord::get_pos() { return posicion_; }
 
void FibonacciWord::set_palabra(std::string palabra) { palabra_ = palabra; }
void FibonacciWord::set_tam(int tam) { tam_palabra_ = tam; }
void FibonacciWord::set_is_fibonacci(bool check) { is_fibonacci_ = check; }
void FibonacciWord::set_pos(int pos) { posicion_ = pos; }

bool FibonacciWord::IsFibonacci(int tam) { 
  std::string kF1 = "a";
  std::string kF2 = "b";
  std::string tmp;

  if (palabra_ == kF1) {
    posicion_ = 1;
    is_fibonacci_ = true;
    return true;
  } else if (palabra_ == kF2){
    posicion_ = 2;
    is_fibonacci_ = true;
    return true;
  }

  int count = 2;
  do {
    tmp = kF2;
    kF2 = kF1 + kF2;
    kF1 = tmp;
    count++;
  }while (tam > kF2.length());

  if (kF2 == palabra_) {
    posicion_ = count;
    is_fibonacci_ = true;
    return true;
  } else {
    is_fibonacci_ = false;
    return false;
  }
}

void FibonacciWord::write(std::string output) {
  std::cout << palabra_;
  if (is_fibonacci_) {
    std::cout << " is the word number " << posicion_ << "\n";
  } else {
    std::cout << " is not a Fibonacci word\n";
  }
}


