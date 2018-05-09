#ifndef INSTRUCTION_HPP
#define INSTRUCTION_HPP

#include <iostream>
#include <vector>
#include "token.hpp"

class Instruction
{
private:
    std::vector<Token> tokens;

public:
    std::vector<Token> getInstructions()
    {
        return tokens;
    }

    void clear()
    {
        tokens.clear();
    }

    void addInstruction(Token t)
    {
        tokens.push_back(t);
    }

    Instruction() {}

    Instruction(std::vector<Token> toks)
    {
        tokens = toks;
    }
};

#endif /* INSTRUCTION_HPP */
