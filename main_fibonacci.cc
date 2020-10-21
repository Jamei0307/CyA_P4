#include <iostream>
#include <fstream>

#include <vector>
#include <string>
#include "fibonacci_word.h"

int main(int argc, char *argv[]) {
  const std::string kInput = argv[1];
  const std::string kOutput = argv[2];
  std::vector<FibonacciWord> FibonacciVector;

  std::ifstream reader(kInput);
  if (! reader) {
    std::cout << "Error opening file" << std::endl;
    return -1;
  } else {
    for (std::string line; getline(reader,line);) {
      FibonacciVector.push_back(FibonacciWord(line, line.length()));
    }
  }
  reader.close();


  for (int i = 0; i < FibonacciVector.size(); i++) {
    FibonacciVector[i].IsFibonacci(FibonacciVector[i].get_tam());
    //FibonacciVector[i].write(kOutput);
  }

  std::ofstream writer(kOutput);
  if (! writer) {
    std::cout << "Error opening file" << std::endl;
    return -1;
  } else {
    for (int i = 0; i < FibonacciVector.size(); i++) {
      writer << FibonacciVector[i].get_palabra();
      if (FibonacciVector[i].get_is_fibonacci()) {
      writer << " is the word number " << FibonacciVector[i].get_pos() << "\n";
      } else {
      writer << " is not a Fibonacci word\n";
      } 
    }
  }
}
