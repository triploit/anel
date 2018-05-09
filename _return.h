//
// Created by survari on 07.05.18.
//

#ifndef ANEL_RETURN_H
#define ANEL_RETURN_H

#include <vector>
#include "token.hpp"
#include "env.hpp"

int __func_return(std::vector<Token> ins, int line)
{
    Env.code += "return 0;\n";
}

#endif //ANEL_CREATE_H
