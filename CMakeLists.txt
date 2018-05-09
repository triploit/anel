cmake_minimum_required(VERSION 3.10)
project(anel)

set(CMAKE_CXX_STANDARD 11)

include_directories(.)

add_executable(anel
        compiler.hpp
        evaluator.hpp
        file.hpp
        filereader.hpp
        functions.hpp
        instruction.hpp
        main.cpp
        parser.hpp
        runtime.hpp
        token.hpp
        tokenizer.hpp
        tstring.hpp
        variables.hpp
        _here.h
        _while.h
        _do.h
        _done.h
        _lets.h
        _create.h
        _if.h
        _return.h env.hpp name.hpp)
