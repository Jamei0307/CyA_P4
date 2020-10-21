#include <iostream>
#include <fstream>

#include <string>

class FibonacciWord {
  private:
    std::string palabra_;
    int tam_palabra_;
    bool is_fibonacci_;
    int posicion_;
  
  public:
    FibonacciWord();
    FibonacciWord(std::string, int);
    ~FibonacciWord();

    std::string get_palabra();
    int get_tam();
    bool get_is_fibonacci();
    int get_pos();

    void set_palabra(std::string);
    void set_tam(int);
    void set_is_fibonacci(bool);
    void set_pos(int);

    bool IsFibonacci(int);
    void write(std::string);
};