#ifndef RUNTIME_HPP
#define RUNTIME_HPP

#include <iostream>
#include "compiler.hpp"

class Runtime
{
public:
    Compiler compiler;
    std::string ocode;
    int OPEN_CLOSE_COUNT = 0;
} Runtime;

#endif