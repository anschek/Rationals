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

	Rational& operator+=(const Rational& right) {
		numerator_ *= right.denominator_ + right.numerator_ * denominator_;
		denominator_ *= right.denominator_;
		Normalize();
		return *this;
	}

	Rational& operator-=(const Rational& right) {
		numerator_ *= right.denominator_ - right.numerator_ * denominator_;
		denominator_ *= right.denominator_;
		Normalize();
		return *this;
	}

	Rational& operator*=(const Rational& right) {
		numerator_ *= right.numerator_;
		denominator_ *= right.denominator_;
		Normalize();
		return *this;
	}

	Rational& operator/=(const Rational& right) {
		numerator_ *= right.denominator_;
		denominator_ *= right.numerator_;
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

Rational operator+(Rational r1, const Rational& r2) {
	return r1+=r2;
}

Rational operator-(Rational r1, const Rational& r2) {
	return r1-=r2;
}

Rational operator*(Rational r1, const Rational& r2) {
	return r1 *= r2;
}

Rational operator/(Rational r1, const Rational& r2) {
	return r1 /= r2;
}

Rational operator+(const Rational& r) {
	return r;
}

Rational operator-(const Rational& r1) {
	return { -r1.Numerator(), -r1.Denominator() };
}

bool operator==(const Rational& r1, const Rational& r2) {
	return r1.Numerator() == r2.Numerator() 
		&& r1.Denominator() == r2.Denominator();
}

bool operator!=(const Rational& r1, const Rational& r2) {
	return !(r1==r2);
}

bool operator<(const Rational& r1, const Rational& r2) {
	return r1.Numerator()*r2.Denominator()
		<r2.Numerator()*r1.Denominator();
}

bool operator>(const Rational& r1, const Rational& r2) {
	return r1.Numerator()*r2.Denominator()
		>r2.Numerator()*r1.Denominator();
}

bool operator<=(const Rational& r1, const Rational& r2) {
	return !(r1>r2);
}

bool operator>=(const Rational& r1, const Rational& r2) {
	return !(r1<r2);
}
int main() {
	Rational r1{ 1,2 }, r2{ 1,3 };
	r1 += r2;
	cout << r1;

	Rational r3{ 1,10 }, r4{ 1,100 };

	cout << '\n' << r3 + r4;
	return 0;
}