#ifndef VARIABLES_HPP
#define VARIABLES_HPP

#include <iostream>
#include <vector>
#include "name.hpp"

class Variables
{
    std::vector<Name> names;

public:
    bool existsName(const std::string &name)
    {
        for (Name n : names)
        {
            if (n.value == name)
                return true;
        }

        return false;
    }

    Name getName(const std::string &name)
    {
        for (Name n : names)
        {
            if (n.value == name)
                return n;
        }

        return Name("", "");
    }

    void addName(const Name &name)
    {
        names.push_back(name);
    }
} Variables;

#endif /* VARIABLES_HPP */
