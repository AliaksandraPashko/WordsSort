#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

#include <boost/algorithm/string.hpp>

void wordsSort(std::ifstream &fin, std::ofstream &fout, const std::string &wordToErase)
{
    std::vector<std::string> words;

    std::string currentString;

    while (std::getline(fin, currentString)) {

        std::istringstream istringStream(currentString);

        std::copy(std::istream_iterator<std::string>(istringStream), std::istream_iterator<std::string>(),
                  std::back_inserter(words));

        words.erase(std::remove(words.begin(), words.end(), wordToErase), words.end());

        std::sort(words.begin(), words.end(), [](const std::string& a, const std::string& b )
        {
            return boost::algorithm::ilexicographical_compare(a, b);
        });

        std::copy(words.begin(), words.end(), std::ostream_iterator<std::string>(fout, " "));
        fout << std::endl;
    }
}

int main() {
    std::ifstream fin("input.txt");
    std::ofstream fout("output.txt");

    std::string wordToErase;
    std::cin >> wordToErase;

    wordsSort(fin, fout, wordToErase);

    fin.close();
    fout.close();

    return 0;
}