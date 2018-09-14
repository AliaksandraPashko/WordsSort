#pragma once

#include <fstream>

class Formatter {
public:
    std::ifstream fin_;
    std::ofstream fout_;
    std::string wordToErase_;

public:
    Formatter(const std::string&, const std::string&, const std::string&);

    void sort();

    ~Formatter();
};

