#ifndef PARSER_HPP
#define PARSER_HPP

#include <iostream>
#include <vector>
#include "token.hpp"
#include "instruction.hpp"

class Parser
{
private:
    std::vector<Token> tokens;

public:
    Parser(std::vector<Token> tokens)
    {
        this->tokens = tokens;
    }

    std::vector<Instruction> parse()
    {
        std::vector<Instruction> instructions;
        Instruction tmp;
        bool function = false;

        for (int i = 0; i < tokens.size(); i++)
        {
            if (tokens[i].type == "keyword")
            {
                if (tokens[i].value == "do")
                {
                    tmp.addInstruction(tokens[i]);
                    instructions.push_back(tmp);

                    tmp.clear();
                    continue;
                }

                if (!function)
                {
                    if (tokens[i].value == "here" || tokens[i].value == "create")
                    {
                        if (tokens[i].value == "here") 
                            function = true;

                        while (tokens[i].value != ".")
                        {
                            tmp.addInstruction(tokens[i]);
                            i++;
                        }

                        instructions.push_back(tmp);
                        tmp.clear();
                        continue;
                    }
                }
                else
                {
                    while (tokens[i].value != ".")
                    {
                        tmp.addInstruction(tokens[i]);
                        i++;
                    }

                    instructions.push_back(tmp);
                    tmp.clear();
                    continue;
                }
            }
            else
            {
                std::cout << "parser: error: syntax error line " << tokens[i].line << ": " << tokens[i].value << std::endl;
                exit(1);
            }
        }   

        return instructions;
    }
};

#endif /* PARSER_HPP */
