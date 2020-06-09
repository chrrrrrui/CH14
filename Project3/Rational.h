#ifndef RATIONAL_H
#define RATIONAL_H
#include<string>
using namespace std;
class Rational
{
private:
	int numerator, denominator;
	static int gcd(int n, int d);

public:
	Rational();
	Rational(int, int);
	int getNumerator()const;
	int getDenominator() const;

	int compareTo(const Rational& secondRational)const;
	string toString()const;

	bool operator<(const Rational& secondRational)const;
	bool operator>(const Rational& secondRational)const;
	bool operator<=(const Rational& secondRational)const;
	bool operator>=(const Rational& secondRational)const;
	bool operator==(const Rational& secondRational)const;
	bool operator!=(const Rational& secondRational)const;
	bool operator<<(const Rational& secondRational)const;
	bool operator>>(const Rational& secondRational)const;

	int operator[](int index);

	Rational& operator+=(const Rational& secondRational);
	Rational& operator-=(const Rational& secondRational);
	Rational& operator*=(const Rational& secondRational);
	Rational& operator/=(const Rational& secondRational);

	Rational operator+(const Rational& secondRational)const;
	Rational operator-(const Rational& secondRational)const;
	Rational operator*(const Rational& secondRational)const;
	Rational operator/(const Rational& secondRational)const;

	Rational& operator++();
	Rational operator++(int dummy);
	Rational& operator--();
	Rational operator--(int dummy);


};
#endif // !RATIONAL_H

