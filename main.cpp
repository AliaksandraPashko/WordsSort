#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <iterator>

int main() {
    std::ifstream fin("input.txt");
    std::ofstream fout("output.txt");
    std::string wordToErase;

    std::vector<std::string> words;

    std::cin >> wordToErase;

    std::string currentString;

    while (std::getline(fin, currentString)) {
        std::istringstream iss(currentString);
        std::copy(std::istream_iterator<std::string>(iss), std::istream_iterator<std::string>(),
                  std::back_inserter(words));
        words.erase(std::remove(words.begin(), words.end(), wordToErase), words.end());
        std::sort(words.begin(), words.end(), [](const std::string& a, const std::string& b )
        {

        });
        std::copy(words.begin(), words.end(), std::ostream_iterator<std::string>(fout, " "));
        fout << std::endl;

    }

    fout.close();
    return 0;
}