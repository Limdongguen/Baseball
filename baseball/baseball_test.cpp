#include <iostream>
#include "baseball.cpp"
#include "gmock/gmock.h"
using namespace std;

TEST(TS, ThrowExceptionWhenInputLengthIsUnmatched) {
	Baseball game;
	EXPECT_THROW(game.guess(string("12")), length_error);
}

int main() {
	testing::InitGoogleMock();
	return RUN_ALL_TESTS();
}