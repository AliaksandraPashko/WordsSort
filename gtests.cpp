#include <gtest/gtest.h>
#include "formatter/formatter.h"

/*
namespace {
    class TestClass : public testing::Test {
    private:
        Formatter formatter;

        TestClass() {
            formatter;
        }
    };
}
*/

TEST(TestCase, check_no_string_to_erase) {
    Formatter formatter("input.txt", "output.txt", "al");

    formatter.sort();

    std::ifstream fout_result("output.txt");

    std::string currentString;

    std::vector<std::string> fin_words, fout_words;

    while (std::getline(formatter.fin_, currentString)) {
        std::istringstream istringStream(currentString);

        std::copy(std::istream_iterator<std::string>(istringStream), std::istream_iterator<std::string>(),
                  std::back_inserter(fin_words));
    }

    while (std::getline(fout_result, currentString)) {
        std::istringstream istringStream(currentString);

        std::copy(std::istream_iterator<std::string>(istringStream), std::istream_iterator<std::string>(),
                  std::back_inserter(fout_words));
    }

    ASSERT_NE(fin_words.size(), fout_words.size());
}
