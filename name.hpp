//
// Created by survari on 09.05.18.
//

#ifndef ANEL_NAME_H
#define ANEL_NAME_H


#include <string>

class Name
{
public:
    std::string value;
    std::string type;

    Name() {}

    Name (std::string value, std::string type)
    {
        this->value = value;
        this->type = type;
    }
};


#endif //ANEL_NAME_H
