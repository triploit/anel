#ifndef COMPILER_HPP
#define COMPILER_HPP

#include <iostream>
#include "filereader.hpp"
#include "tokenizer.hpp"
#include "parser.hpp"
#include "evaluator.hpp"

class Compiler
{
public:
    std::string input_file;
    std::string output_file;
    
    bool keep_cpp_source;
    bool verbose;
    bool static_linking;

    Compiler(){}

    Compiler(std::string ifile, std::string ofile, bool _keep, bool _static, bool _verbose)
    {
        verbose = _verbose;
        keep_cpp_source = _keep;
        static_linking = _static;

        input_file = ifile;
        output_file = ofile;
    }

    void compile()
    {
        (Evaluator(Parser(Tokenizer(FileReader(input_file).readCompleteFile()).tokenize()).parse())).evaluate();

        std::ofstream of(input_file+".cpp");
        of << Env.code;
        of.close();

        if (system(std::string("g++ "+input_file+".cpp"+" -o "+output_file+" > /dev/null").c_str()) != 0)
        {
            std::cout << "error: error at compiling with g++." << std::endl;
            return;
        }

        if (!keep_cpp_source)
            remove(std::string(input_file+".cpp").c_str());
    }
};

#endif /* COMPILER_HPP */
