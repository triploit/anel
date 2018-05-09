//
// Created by survari on 07.05.18.
//

#ifndef ANEL_WHILE_H
#define ANEL_WHILE_H

#include <vector>
#include "token.hpp"

int __func_while(std::vector<Token> ins, int line)
{
    if (ins.size() != 6 && ins.size() != 7)
    {
        std::cout << "error: line " << line << ": create: wrong number of arguments (6 or 7 expected): " << ins.size() << std::endl;
        std::cout << "usage: if a is equal to b." << std::endl;
        std::cout << "usage: if a is less than b." << std::endl;
        std::cout << "usage: if a is not less than b." << std::endl;
        exit(1);
    }

    std::string type;
    std::string v1;
    std::string v2;
    bool no = false;

    for (int i = 0; i < ins.size(); i++)
    {
        if (ins[i].value == "is")
        {
            v1 = ins[i-1].value;
            continue;
        }

        if (ins[i].value == "to" || ins[i].value == "than")
        {
            i++;
            v2 = ins[i].value;
            continue;
        }

        if (ins[i].value == "equal")
        {
            type = "==";
            continue;
        }

        if (ins[i].value == "less")
        {
            type = "<";
            continue;
        }

        if (ins[i].value == "greater")
        {
            type = ">";
            continue;
        }

        if (ins[i].value == "not")
        {
            no = true;
            continue;
        }
    }

    if (no)
    {
        Env.code += "\nwhile (!("+v1+type+v2+")) ";
    }
    else
    {
        Env.code += "\nwhile ("+v1+type+v2+") ";
    }
}


#endif //ANEL_WHILE_H
