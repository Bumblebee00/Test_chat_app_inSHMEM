#include "gtest/gtest.h"
#include "ExampleClass.hpp"

// This is an example test for the ExampleLibrary
// You can google for "google test" to learn more


TEST(ExampleCheck, Factorial) {
    ExampleClass test;
    test.setNumber(1);
    EXPECT_EQ(test.factorial(), 1);

    test.setNumber(2);
    EXPECT_EQ(test.factorial(), 2);

    test.setNumber(3);
    EXPECT_EQ(test.factorial(), 6);
}

TEST(ExampleCheck, SpecialSum) {
    ExampleClass test;
    test.setNumber(1);
    EXPECT_EQ(test.specialSum(), 1);

    test.setNumber(2);
    EXPECT_EQ(test.specialSum(), 3);

    test.setNumber(3);
    EXPECT_EQ(test.specialSum(), 6);
}