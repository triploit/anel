#ifndef FILEREADER_HPP
#define FILEREADER_HPP

#include <iostream>
#include <fstream>
#include "tstring.hpp"

class FileReader
{
private:
    std::string f;
public:
    FileReader(std::string file)
    {
        f = file;
    }

    std::string readCompleteFile()
    {
        std::ifstream ifs(f);
        std::string line;
        std::string file;

        if (ifs.is_open())
        {
            while (std::getline(ifs, line))
            {
                line = tri::string(line).trim().cxs();

                if (line[0] == '#')
                    continue;
                else if (line[0] == '!')
                {
                    file += FileReader(line.substr(1, line.size())).readCompleteFile()+"\n";
                }
                else
                    file += line + "\n";
            }

        }
        else
        {
            std::cout << "error: file not found: " << f << std::endl;
            exit(1);
        }

        return file;
    }
};

#endif /* FILEREADER_HPP */
