#include <iostream>
#include "baseball.cpp"
#include "gmock/gmock.h"
using namespace std;

class BaseBallFixture : public testing::Test {
public:
	Baseball game;
	void assertIllegalArgument(string guessNumber) {
		try {
			game.guess(guessNumber);
			FAIL();
		}
		catch (const exception &e)
		{

		}
	}
};

TEST_F(BaseBallFixture, ThrowExceptionWhenInvalidCase) {
	assertIllegalArgument("12");
	assertIllegalArgument("12s");
}

int main() {
	testing::InitGoogleMock();
	return RUN_ALL_TESTS();
}