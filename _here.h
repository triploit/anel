//
// Created by survari on 07.05.18.
//

#ifndef ANEL_HERE_H
#define ANEL_HERE_H

#include <vector>
#include "token.hpp"
#include "variables.hpp"

int __func_here(std::vector<Token> ins, int line)
{
    if (ins.size() != 3)
    {
        std::cout << "error: line " << line << ": here: to few/many arguments." << std::endl;
        std::cout << "usage: here starts main." << std::endl;
        exit(1);
    }

    bool starts = false;
    std::string name;

    for (Token t : ins)
    {
        if (t.value == "starts")
        {
            starts = true;
        }
        else
            name = t.value;
    }

    if (starts)
    {
        if (Variables.existsName(name))
        {
            std::cout << "error: line " << line << ": here: function \"" << name << "\" already exists." << std::endl;
            exit(1);
        }

        Variables.addName(Name(name, "function"));
        Env.code += "\nint "+name+"() ";
    }
}


#endif //ANEL_HERE_H
