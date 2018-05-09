//
// Created by survari on 07.05.18.
//

#ifndef ANEL_DO_H
#define ANEL_DO_H

#include <vector>
#include "token.hpp"
#include "env.hpp"

int __func_do(std::vector<Token> ins, int line)
{
    Env.code += "{\n";
    Env.OPEN_CLOSE_COUNT++;
}


#endif //ANEL_DO_H
