#include <stdexcept>
#include <string>
using namespace std;

struct GuessResult {
	bool solved;
	int strikes;
	int balls;
};

class Baseball {
public:
	explicit Baseball(const string& answer) : answer{ answer } {};
	GuessResult guess(const string& guessNumber) {
		GuessResult result{ false, 0,0 };
		auto answer_size = answer.size();
		assertIllegalArgument(guessNumber);
		if (answer == guessNumber) return { true,3,0 };
		for (int i = 0; i < answer_size; i++) {
			if (answer[i] == guessNumber[i]) 
				result.strikes++;
			else if (answer[i] == guessNumber[(i + 1) % answer_size] ||
				answer[i] == guessNumber[(i + 2) % answer_size]) 
				result.balls++;
		}
		return result;
	}

private:
	string answer;
	void assertIllegalArgument(const std::string& guessNumber)
	{
		if (guessNumber.length() != 3) {
			throw length_error("Must be three letters.");
		}

		for (char ch : guessNumber) {
			if (ch >= '0' && ch <= '9') continue;
			throw invalid_argument("Must be number");
		}

		if (isDuplicateNumber(guessNumber))
			throw invalid_argument("Must be three numbers are different");
	}

	bool isDuplicateNumber(const std::string& guessNumber)
	{
		return guessNumber[0] == guessNumber[1] ||
			guessNumber[1] == guessNumber[2] ||
			guessNumber[0] == guessNumber[2];
	}
};