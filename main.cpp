#include <iostream>
#include "runtime.hpp"
#include "compiler.hpp"

void help();
std::string A_VERSION = "v0.0.1";

int main(int argc, char const *argv[])
{
    std::string ifile = "";
    std::string ofile = "";

    Env.code = "#include <iostream>\n#include <vector>\n\n";

    bool verbose = false;
    bool keep = false;
    bool _static = false;

    for (int i = 0; i < argc; i++)
    {
        std::string arg = argv[i];

        if (arg == "-o")
        {
            if (i+1 < argc)
                i++;
            else
                std::cout << "error: to few arguments: -o needs a filename.\n       see \"anel -h\"" << std::endl;


            ofile = argv[i];
            continue;
        }
        else if (arg == "-h")
        {
            help();
        }
        else if (arg == "-k")
        {
            keep = true;
        }
        else if (arg == "-v")
        {
            verbose = true;
        }
        else if (arg == "-s")
        {
            _static = true;
        }
        else
        {
            ifile = arg;
        }
    }

    if (verbose)
    {
        std::cout << "info: now compiling file : " << ifile << std::endl;
        std::cout << "info: this output file   : " << ofile << std::endl;
        std::cout << "info: compiling verbose? : " << (verbose ? "enabled" : "disabled") << std::endl;
        std::cout << "info: compile static?    : " << (_static ? "enabled" : "disabled") << std::endl;
        std::cout << "info: keep c++ file?     : " << (keep ? "enabled" : "disabled") << std::endl;
    }

    if (ifile == "")
    {
        std::cout << "error: no input file given." << std::endl;
        exit(1);
    }

    if (ofile == "")
    {
        std::cout << "error: no output file given." << std::endl;
        exit(1);
    }

    Runtime.compiler = Compiler(ifile, ofile, keep, _static, verbose);
    Runtime.compiler.compile();

    return 99;
}

void help()
{
    std::cout << "Anel Version " << A_VERSION << std::endl 
    << R"VOGON(
    -o [output]  - set name for binary output file
    -v           - enable verbose compiling
    -k           - keep c++ source
    -s           - compile in static mode (add all libraries to executable)

Examples:

    anel test.anl -o a.out     - compiles the file "test.anl" to "a.out"
    anel -o a.out test.anl     - does the same thing
    anel test.anl -o a.out -k  - keeps c++ file
    )VOGON" << std::endl;
}