#ifndef TOKENIZER_HPP
#define TOKENIZER_HPP

#include <iostream>
#include <vector>
#include <regex>
#include "token.hpp"

class Tokenizer
{
private:
    std::string code;
    std::vector<Token> tokens;

    std::string keyword_or_word(const std::string &s)
    {
        if (s == "lets" ||
            s == "create" ||
            s == "here" ||
            s == "while" ||
            s == "if" ||
            s == "do" ||
            s == "done" ||
            s == "return")
        {
            return "keyword";
        }

        std::smatch match;
        std::regex re("(-|)[0-9]+(.[0-9]+|)");

        if (std::regex_match(s, match, re))
        {
            return "number";
        }

        return "word";
    }

public:
    Tokenizer(const std::string &c)
    {
        code = c;
    }

    std::vector<Token> tokenize()
    {
        std::string tmp = "";
        std::string type = "";
        std::vector<Token> tokens;
        int l = 0;

        for (int i = 0; i < code.size(); i++)
        {
            if ((code[i] == ' ' || code[i] == '\n' || code[i] == '\t') && type == "")
            {
                if (code[i] == '\n')
                    l++;

                while (code[i+1] == ' ' || code[i+1] == '\n' || code[i+1] == '\t')
                {
                    i++;

                    if (code[i] == '\n')
                        l++;
                }

                if (tmp != "")
                    tokens.push_back(Token(tmp, keyword_or_word(tmp), l+1));

                tmp = "";
                continue;
            }


            if (code[i] == '"' && type != "string")
            {
                type = "string";
                continue;
            }

            if (code[i] == '\\' && type == "string")
            {
                if (code[i+1] == '"')
                {
                    tmp += "\"";
                    i++;
                }
                else
                    tmp += "\\";

                continue;
            }

            if (code[i] == '"' && type == "string")
            {
                if (tmp != "")
                    tokens.push_back(Token(tmp, "string", l+1));
                type = "";
                tmp = "";        
                continue;
            }

            if (code[i] == '.' && type == "")
            {
                while (code[i+1] == ' ' || code[i+1] == '\n' || code[i+1] == '\t')
                {
                    i++;

                    if (code[i] == '\n')
                        l++;
                }

                if (tmp != "")
                    tokens.push_back(Token(tmp, keyword_or_word(tmp), l));
                tmp = "";


                tokens.push_back(Token(".", "point", l+1));
                continue;
            }

            tmp += code[i];
        }

        return tokens;
    }
};

#endif /* TOKENIZER_HPP */
