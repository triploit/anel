#ifndef EVALUATOR_HPP
#define EVALUATOR_HPP

#include <vector>
#include <iostream>

#include "_return.h"
#include "_while.h"
#include "_here.h"
#include "_if.h"
#include "_lets.h"
#include "_do.h"
#include "_done.h"
#include "_create.h"

#include "instruction.hpp"

class Evaluator
{
private:
    std::vector<Instruction> ins;

    struct functions
    {
        int (*value[8]) (std::vector<Token> ins, int line) =
        {
                &__func_return,
                &__func_if,
                &__func_here,
                &__func_while,
                &__func_lets,
                &__func_do,
                &__func_create,
                &__func_done
        };

        std::string name[8] = {
                "return",
                "if",
                "here",
                "while",
                "lets",
                "do",
                "create",
                "done"
        };
    } functions;

public:
    Evaluator(const std::vector<Instruction> &instructions)
    {
        ins = instructions;
    }

    void evaluate()
    {
        for (int i = 0; i < ins.size(); i++)
        {
            // std::cout << "EXEC: " << ins[i].getInstructions()[0].value << std::endl;

            if (ins[i].getInstructions()[0].type != "keyword")
            {
                std::cout << "evaluator: error: syntax error line " << ins[i].getInstructions()[0].line << std::endl;
                exit(1);
            }
            else
            {
                for (int j = 0; j < 8; j++)
                {
                    // std::cout << functions.name[j] << " =? " << ins[i].getInstructions()[0].value << std::endl;
                    if (ins[i].getInstructions()[0].value == functions.name[j])
                    {
                        functions.value[j](ins[i].getInstructions(), ins[i].getInstructions()[0].line);
                    }
                }
            }
        }

        if (Env.OPEN_CLOSE_COUNT != 0)
        {
            std::cout << "error: one statement didn't closed/opened fine." << std::endl;
            exit(1);
        }
    }
};

#endif /* EVALUATOR_HPP */
