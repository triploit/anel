//
// Created by survari on 07.05.18.
//

#ifndef ANEL_CREATE_H
#define ANEL_CREATE_H

#include <iostream>
#include "variables.hpp"

int __func_create(std::vector<Token> ins, int line)
{
    // create new a as integer is 12;

    if (ins.size() != 7)
    {
        std::cout << "error: line " << line << ": create: wrong number of arguments: " << ins.size() << std::endl;
        std::cout << "usage: create new x as integer is 12." << std::endl;
        exit(1);
    }

    std::string name = "";
    std::string type = "";
    std::string ltype = "";
    std::string value = "";

    for (int i = 0; i < ins.size(); i++)
    {
        if (ins[i].value == "as")
        {
            i++;
            bool found = false;

            for (int j = 0; j < Env.VARIABLE_TYPE_NAME.size(); j++)
            {
                if (found) break;
                type = Env.VARIABLE_TYPE_NAME[j];
                // std::cout << ins[i].value << " ?= " << Env.VARIABLE_TYPE_NAME[j] << std::endl;

                if (ins[i].value == Env.VARIABLE_TYPE_NAME[j])
                {
                    type = Env.VARIABLE_TYPE_CPP_EQ[j];
                    ltype = Env.VARIABLE_TYPE_NAME[j];
                    found = true;
                }
            }

            if (!found)
            {
                std::cout << "error: line " << line << ": create: type \"" << ins[i].value << "\" not found!" << std::endl;
                exit(1);
            }

            continue;
        }

        if (ins[i].value == "is")
        {
            i++;

            if (type == "integer" && ins[i].type != "number")
            {
                std::cout << "error: line " << line << ": create: value has wrong type!" << std::endl;
                exit(1);
            }

            value = ins[i].value;
        }

        if (ins[i].value == "new")
        {
            i++;

            if (ins[i].type != "word")
            {
                std::cout << "error: line " << line << ": create: invalid variable name!" << std::endl;
                exit(1);
            }

            name = ins[i].value;
        }
    }

    if (Variables.existsName(name))
    {
        std::cout << "error: line " << line << ": create: variable name already taken!" << std::endl;
        exit(1);
    }
    else
        Variables.addName(Name(name, "variable_"+ltype));

    Env.code += type + " " + name + "=" + value + ";\n";
}

#endif //ANEL_CREATE_H
