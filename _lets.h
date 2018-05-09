//
// Created by survari on 07.05.18.
//

#ifndef ANEL_LETS_H
#define ANEL_LETS_H

#include <vector>
#include "token.hpp"
#include "variables.hpp"

int __func_lets(std::vector<Token> ins, int line)
{
    if (ins[1].value == "print")
    {
        Env.code += "std::cout";

        for (int i = 2; i < ins.size(); i++)
        {
            if (ins[i].value == "and" && ins[i].type == "word")
                continue;

            if (ins[i].value == "newline" && ins[i].type == "word")
            {
                Env.code += " << std::endl";
                continue;
            }

            if (ins[i].type == "string")
                Env.code += " << \"" + ins[i].value + "\"";
            else
                Env.code += " << " + ins[i].value;
        }

        Env.code += " << \"\";\n";
    }
    else if (ins[1].value == "move")
    {
        if (ins.size() != 5)
        {
            std::cout << "error: line " << line << ": lets: sub: to few arguments!" << std::endl;
            exit(1);
        }

        Token t1 = Token("", "", 0);
        Token t2 = Token("", "", 0);

        for (int i = 1; i < ins.size(); i++)
        {
            if (i == 1)
            {
                i++;
                t1 = ins[i];
                continue;
            }

            if (ins[i].value == "to")
            {
                i++;
                t2 = ins[i];
                continue;
            }
        }

        if (!Variables.existsName(t1.value) && (Variables.getName(t1.value).type != "variable_integer" || Variables.getName(t1.value).type != "variable_string"))
        {
            std::cout << "error: line " << line << ": lets: move: variable \"" << t1.value << "\" not found." << std::endl;
            exit(1);
        }

        if (t2.type == "word")
        {
            if (Variables.getName(t2.value).type != Variables.getName(t1.value).type)
            {
                std::cout << "error: line " << line << ": lets: move: wrong type of \"" << t2.value << "\". can't convert." << std::endl;
            }
        }
        else
        {
            if (Variables.getName(t1.value).type != ("variable_"+t2.type))
            {
                std::cout << "error: line " << line << ": lets: move: wrong type of \"" << t2.value << "\". can't convert." << std::endl;
            }
        }


        Env.code += t1.value + "=" + t2.value + ";\n";
    }
    else if (ins[1].value == "set")
    {
        // lets sub a from b.
        if (ins.size() != 5)
        {
            std::cout << "error: line " << line << ": lets: sub: to few arguments!" << std::endl;
            exit(1);
        }

        Token t1 = Token("", "", 0);
        Token t2 = Token("", "", 0);

        for (int i = 1; i < ins.size(); i++)
        {
            if (i == 1)
            {
                i++;
                t1 = ins[i];
                continue;
            }

            if (ins[i].value == "to")
            {
                i++;
                t2 = ins[i];
                continue;
            }
        }

        if (!Variables.existsName(t1.value) && (Variables.getName(t1.value).type != "variable_integer" || Variables.getName(t1.value).type != "variable_string"))
        {
            std::cout << "error: line " << line << ": lets: set: variable \"" << t1.value << "\" not found." << std::endl;
            exit(1);
        }

        if (Variables.getName(t1.value).type == "variable_integer")
        {
            if (Variables.existsName(t2.value))
            {
                if (Variables.getName(t2.value).type != "variable_integer")
                {
                    std::cout << "error: line " << line << ": lets: set: wrong type of \"" << t1.value << "\". must be integer variable!" << std::endl;
                    exit(1);
                }

                if (Variables.getName(t2.value).type != "variable_integer" && t2.type != "number")
                {
                    std::cout << "error: line " << line << ": lets: set: error with first argument \"" << t2.value << "\"." << std::endl;
                    exit(1);
                }
            }
            else if (t2.type != "number")
            {
                std::cout << "error: line " << line << ": lets: set: error with first argument \"" << t2.value << "\"." << std::endl;
                exit(1);
            }
        }
        else
        {
            if (Variables.existsName(t2.value))
            {
                if (Variables.getName(t2.value).type != "variable_integer")
                {
                    std::cout << "error: line " << line << ": lets: set: wrong type of \"" << t1.value << "\". must be string variable!" << std::endl;
                    exit(1);
                }

                if (Variables.getName(t2.value).type != "variable_integer" && t2.type != "number")
                {
                    std::cout << "error: line " << line << ": lets: set: error with first argument \"" << t2.value << "\"." << std::endl;
                    exit(1);
                }
            }
        }

        Env.code += t1.value + "=" + t2.value + ";\n";
    }
    else if (ins[1].value == "sub")
    {
        // lets sub a from b.
        if (ins.size() != 5)
        {
            std::cout << "error: line " << line << ": lets: sub: to few arguments!" << std::endl;
            exit(1);
        }

        Token t1 = Token("", "", 0);
        Token t2 = Token("", "", 0);

        for (int i = 1; i < ins.size(); i++)
        {
            if (i == 1)
            {
                i++;
                t2 = ins[i];
                continue;
            }

            if (ins[i].value == "from")
            {
                i++;
                t1 = ins[i];
                continue;
            }
        }

        if (!Variables.existsName(t1.value))
        {
            std::cout << "error: line " << line << ": lets: sub: variable \"" << t1.value << "\" not found." << std::endl;
            exit(1);
        }

        if (Variables.getName(t1.value).type != "variable_integer")
        {
            std::cout << "error: line " << line << ": lets: sub: wrong type of \"" << t1.value << "\". must be integer variable!" << std::endl;
            exit(1);
        }

        if (Variables.getName(t2.value).type != "variable_integer" && t2.type != "number")
        {
            std::cout << "error: line " << line << ": lets: sub: error with first argument \"" << t2.value << "\"." << std::endl;
            exit(1);
        }

        Env.code += t1.value + "=" + t1.value + "-" + t2.value + ";\n";
    }
    else if (ins[1].value == "add")
    {
        // lets sub a from b.
        if (ins.size() != 5)
        {
            std::cout << "error: line " << line << ": lets: add: to few arguments!" << std::endl;
            exit(1);
        }

        Token t1 = Token("", "", 0);
        Token t2 = Token("", "", 0);

        for (int i = 1; i < ins.size(); i++)
        {
            if (i == 1)
            {
                i++;
                t2 = ins[i];
                continue;
            }

            if (ins[i].value == "to")
            {
                i++;
                t1 = ins[i];
                continue;
            }
        }

        if (!Variables.existsName(t1.value))
        {
            std::cout << "error: line " << line << ": lets: add: variable \"" << t1.value << "\" not found." << std::endl;
            exit(1);
        }

        Env.code += t1.value + "=" + t1.value + "+" + t2.value + ";\n";
    }
    else if (ins[1].value == "mul")
    {
        // lets sub a from b.
        if (ins.size() != 5)
        {
            std::cout << "error: line " << line << ": lets: mul: to few arguments!" << std::endl;
            exit(1);
        }

        Token t1 = Token("", "", 0);
        Token t2 = Token("", "", 0);

        for (int i = 1; i < ins.size(); i++)
        {
            if (i == 1)
            {
                i++;
                t2 = ins[i];
                continue;
            }

            if (ins[i].value == "to")
            {
                i++;
                t1 = ins[i];
                continue;
            }
        }

        if (!Variables.existsName(t1.value))
        {
            std::cout << "error: line " << line << ": lets: mul: variable \"" << t1.value << "\" not found." << std::endl;
            exit(1);
        }

        if (Variables.getName(t1.value).type != "variable_integer")
        {
            std::cout << "error: line " << line << ": lets: mul: wrong type of \"" << t1.value << "\". must be integer variable!" << std::endl;
            exit(1);
        }

        if (Variables.getName(t2.value).type != "variable_integer" && t2.type != "number")
        {
            std::cout << "error: line " << line << ": lets: mul: error with first argument \"" << t2.value << "\"." << std::endl;
            exit(1);
        }

        Env.code += t1.value + "=" + t1.value + "*" + t2.value + ";\n";
    }
    else if (ins[1].value == "div")
    {
        // lets sub a from b.
        if (ins.size() != 5)
        {
            std::cout << "error: line " << line << ": lets: div: to few arguments!" << std::endl;
            exit(1);
        }

        Token t1 = Token("", "", 0);
        Token t2 = Token("", "", 0);

        for (int i = 1; i < ins.size(); i++)
        {
            if (i == 1)
            {
                i++;
                t2 = ins[i];
                continue;
            }

            if (ins[i].value == "from")
            {
                i++;
                t1 = ins[i];
                continue;
            }
        }

        if (!Variables.existsName(t1.value))
        {
            std::cout << "error: line " << line << ": lets: div: variable \"" << t1.value << "\" not found." << std::endl;
            exit(1);
        }

        if (Variables.getName(t1.value).type != "variable_integer")
        {
            std::cout << "error: line " << line << ": lets: div: wrong type of \"" << t1.value << "\". must be integer variable!" << std::endl;
            exit(1);
        }

        if (Variables.getName(t2.value).type != "variable_integer" && t2.type != "number")
        {
            std::cout << "error: line " << line << ": lets: div: error with first argument \"" << t2.value << "\"." << std::endl;
            exit(1);
        }

        Env.code += t1.value + "=" + t1.value + "/" + t2.value + ";\n";
    }
    else if (ins[1].value == "input")
    {
        if (ins.size() != 3)
        {
            std::cout << "error: line " << line << ": lets: input: to few/much arguments!" << std::endl;
            exit(1);
        }

        if (!Variables.existsName(ins[2].value))
        {
            std::cout << "error: line " << line << ": lets: input: field \"" << ins[2].value << "\" does'nt exist!" << std::endl;
            exit(1);
        }

        if (Variables.getName(ins[2].value).type != "variable_string" && Variables.getName(ins[2].value).type != "variable_integer")
        {
            std::cout << "error: line " << line << ": lets: input: field \"" << ins[2].value << "\" is not a variable." << std::endl;
            exit(1);
        }

        Env.code += "std::cin >> " + ins[2].value + ";\n";
    }
    else if (ins[1].value == "run")
    {
        if (ins.size() != 3)
        {
            std::cout << "error: line " << line << ": lets: run: to few/much arguments!" << std::endl;
            exit(1);
        }

        if (!Variables.existsName(ins[2].value))
        {
            std::cout << "error: line " << line << ": lets: run: field \"" << ins[2].value << "\" does'nt exist!" << std::endl;
            exit(1);
        }

        if (Variables.getName(ins[2].value).type != "function")
        {
            std::cout << "error: line " << line << ": lets: run: field \"" << ins[2].value << "\" is not a function." << std::endl;
            exit(1);
        }

        Env.code += ins[2].value + "();\n";
    }
}


#endif //ANEL_LETS_H
