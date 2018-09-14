#include <gtest/gtest.h>
#include "formatter/formatter.h"
#include <numeric>


void readFile(const std::string& filePath, std::vector<std::string>& words)
{
    std::ifstream file(filePath);

    std::string currentString;

    while (std::getline(file, currentString)) {
        std::istringstream istringStream(currentString);

        std::copy(std::istream_iterator<std::string>(istringStream), std::istream_iterator<std::string>(),
                  std::back_inserter(words));
    }

    file.close();
}

void writeTheFile(const std::string& filePath, const std::string& inputText )
{
    std::ofstream fin;
    fin.open(filePath, std::ofstream::trunc);
    fin << inputText;
    fin.close();
}


TEST(Tests, check_word_deleted)
{
    std::string inputFilePath = "input.txt";
    std::string outputFilePath = "output.txt";
    std::string wordToErase = "al";

    std::string inputText = "al al sas\ndd Af zxa";

    writeTheFile(inputFilePath, inputText);

    Formatter formatter(inputFilePath, outputFilePath, wordToErase);

    formatter.sort();

    std::vector<std::string> fin_words, fout_words;

    readFile(inputFilePath, fin_words);
    readFile(outputFilePath, fout_words);

    EXPECT_NE(fin_words.size(), fout_words.size());
}


TEST(Tests, check_nothing_deleted)
{
    std::string inputFilePath = "input.txt";
    std::string outputFilePath = "output.txt";
    std::string wordToErase = "";

    std::string inputText = "al al\ndd Af zxa";

    writeTheFile(inputFilePath, inputText);

    Formatter formatter(inputFilePath, outputFilePath, wordToErase);

    formatter.sort();

    std::vector<std::string> fin_words, fout_words;

    readFile(inputFilePath, fin_words);
    readFile(outputFilePath, fout_words);

    EXPECT_EQ(fin_words.size(), fout_words.size());
}

TEST(Tests, upper_case_ignored)
{
    std::string inputFilePath = "input.txt";
    std::string outputFilePath = "output.txt";
    std::string wordToErase = "";

    std::string inputText = "aba Al";

    writeTheFile(inputFilePath, inputText);

    Formatter formatter(inputFilePath, outputFilePath, wordToErase);
    formatter.sort();

    std::vector<std::string> fout_words;

    readFile(outputFilePath, fout_words);

    std::string sortResult = std::accumulate(fout_words.begin(), fout_words.end(), std::string(""));

    EXPECT_NE(inputText, sortResult);
}



