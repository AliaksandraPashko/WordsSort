#include "formatter.h"

#include <string>
#include <sstream>
#include <vector>

#include <boost/algorithm/string.hpp>

Formatter::Formatter(const std::string &inputFile, const std::string &outputFile, const std::string &wordToErase)
        : wordToErase_(wordToErase) {
    fin_.open(inputFile);
    fout_.open(outputFile);
}


void Formatter::sort()
{
    std::vector<std::string> strings;

    std::string currentString;

    if (fin_)
    {
        while (std::getline(fin_, currentString))
        {
            size_t pos = currentString.find(wordToErase_);

            while(pos != std::string::npos)
            {
                currentString.erase(pos, wordToErase_.size());

                pos = currentString.find(wordToErase_);
            }

            strings.push_back(currentString);
        }

        std::sort(strings.begin(), strings.end(), [](const std::string &str1, const std::string &str2) {
            return boost::algorithm::ilexicographical_compare(str1, str2);
        });
    }

    std::copy(strings.begin(), strings.end(), std::ostream_iterator<std::string>(fout_, "\n"));
}


Formatter::~Formatter()
{
    fin_.close();
    fout_.close();
}
