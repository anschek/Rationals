#include <iostream>
#include <numeric>
#include <vector>

using namespace std;

class Rational {
public:
	Rational() = default;

	Rational(int integer)
		:numerator_(integer)
	{
	}

	Rational(int numerator, int denominator)
		:numerator_(numerator), denominator_(denominator)
	{
		Normalize();
	}

	int Numerator()const {
		return numerator_;
	}

	int Denominator() const {
		return denominator_;
	}

	Rational operator++(void) {
		++numerator_;
		Normalize();
		return *this;
	}

	~Rational() {
	}

private:
	void Normalize() {
		if (denominator_ < 0) {
			numerator_ *= -1;
			denominator_ *= -1;
		}
		const int divisor = gcd(numerator_, denominator_);
		numerator_ /= divisor;
		denominator_ /= divisor;
	}

	int numerator_ = 0;
	int denominator_ = 1;
};

int main() {
	return 0;
}