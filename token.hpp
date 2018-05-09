#ifndef TOKEN_HPP
#define TOKEN_HPP

class Token
{
public:
    std::string value;
    std::string type;
    int line;

    Token(std::string v, std::string t, int l)
    {
        value = v;
        type = t;
        line = l;
    }
};

#endif