#include <iostream>
#include "baseball.cpp"
#include "gmock/gmock.h"

TEST(TS, TC1) {
	Baseball baseball;
	EXPECT_EQ(1, 1);	
}

int main() {
	testing::InitGoogleMock();
	return RUN_ALL_TESTS();
}