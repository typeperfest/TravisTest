#include <arithmetics.hpp>
#include <gtest/gtest.h>
#include <fstream>


TEST(SUM, InFileStream)
{
    std::string filepath = "file.txt";
    std::string text = "5";

    std::ofstream out(filepath);

    out << sum(2, 3);
    out.close();

    std::string result;
    std::ifstream in(filepath);
    in >> result;

    EXPECT_EQ(result, text);
}

