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
    std::vector<std::string> words;

    std::string currentString;

    if (fin_)
    {
        while (std::getline(fin_, currentString))
        {

            std::istringstream istringStream(currentString);

            words.clear();

            std::copy(std::istream_iterator<std::string>(istringStream), std::istream_iterator<std::string>(),
                      std::back_inserter(words));

            assert(words.empty() == false);

            words.erase(std::remove(words.begin(), words.end(), wordToErase_), words.end());

            std::sort(words.begin(), words.end(), [](const std::string &str1, const std::string &str2) {
                return boost::algorithm::ilexicographical_compare(str1, str2);
            });

            std::copy(words.begin(), words.end(), std::ostream_iterator<std::string>(fout_, " "));

            fout_ << std::endl;
        }
    }
}


Formatter::~Formatter()
{
    fin_.close();
    fout_.close();
}
