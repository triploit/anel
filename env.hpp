//
// Created by survari on 09.05.18.
//

#ifndef ANEL_ENV_H
#define ANEL_ENV_H

#include <iostream>
#include <vector>

class Env
{
public:
    int OPEN_CLOSE_COUNT = 0;
    std::string code;
    std::vector<std::string> VARIABLE_TYPE_NAME;
    std::vector<std::string> VARIABLE_TYPE_CPP_EQ;

    Env()
    {
        VARIABLE_TYPE_NAME.push_back("integer");
        VARIABLE_TYPE_CPP_EQ.push_back("long");

        VARIABLE_TYPE_NAME.push_back("string");
        VARIABLE_TYPE_CPP_EQ.push_back("std::string");
    }
} Env;


#endif //ANEL_ENV_H
