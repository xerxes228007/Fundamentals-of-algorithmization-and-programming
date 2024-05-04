#include "Number.h"
#include <iostream>


Number::Number(double _val) { val = _val; }

Number::~Number(){
  // std::cout << "Number destroyed" << std::endl;
};

double Number::evaluate() { return val; }