#ifndef TOKEN_HPP
#define TOKEN_HPP

class Token
{
public:
    std::string value;
    std::string type;
    int line;

    Token(const std::string &v, const std::string &t, const int &l)
    {
        value = v;
        type = t;
        line = l;
    }
};

#endif