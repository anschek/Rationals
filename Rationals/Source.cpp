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

ostream& operator<<(ostream& out, const Rational& r) {
	if (r.Numerator() < 0) out << '(' << r.Numerator() << ')';
	else out << r.Numerator();
	out << '/' << r.Denominator();
	return out;
}

istream& operator>>(istream& input, Rational& r) {
	int numerator, denominator;
	char slash;
	input >> numerator >> slash >> denominator;
	r = { numerator, denominator };
	return input;
}

int main() {
	return 0;
}