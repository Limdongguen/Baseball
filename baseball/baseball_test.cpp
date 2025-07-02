#include <iostream>
#include "baseball.cpp"
#include "gmock/gmock.h"
using namespace std;

class BaseBallFixture : public testing::Test {
public:
	Baseball game{ "123" };
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
	assertIllegalArgument("121");
}

TEST_F(BaseBallFixture, AnswerCase) {
	GuessResult result = game.guess("123");

	EXPECT_TRUE(result.solved);
	EXPECT_EQ(3, result.strikes);
	EXPECT_EQ(0, result.balls);

}

TEST_F(BaseBallFixture, TwoStrikeZeroballCase) {
	GuessResult result = game.guess("129");

	EXPECT_FALSE(result.solved);
	EXPECT_EQ(2, result.strikes);
	EXPECT_EQ(0, result.balls);
}

TEST_F(BaseBallFixture, OneStrikeTwoballCase) {
	GuessResult result = game.guess("132");

	EXPECT_FALSE(result.solved);
	EXPECT_EQ(1, result.strikes);
	EXPECT_EQ(2, result.balls);
}

int main() {
	testing::InitGoogleMock();
	return RUN_ALL_TESTS();
}