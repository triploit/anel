//
// Created by survari on 07.05.18.
//

#ifndef ANEL_DONE_H
#define ANEL_DONE_H

#include <vector>
#include "token.hpp"

int __func_done(std::vector<Token> ins, int line)
{
    Env.code += "}\n";
    Env.OPEN_CLOSE_COUNT--;
}


#endif //ANEL_DONE_H
