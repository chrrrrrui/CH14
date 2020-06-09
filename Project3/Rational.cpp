#include"Rational.h"
#include<sstream>
#include<cstdlib>
using namespace std;

Rational::Rational()
{
	numerator = 0;
	denominator = 1;
}
Rational::Rational(int numerator, int denominator)
{
	int factor = gcd(numerator, denominator);
	this->numerator = ((denominator > 0) ? 1 : -1)*numerator / factor;
	this->denominator = abs(denominator) / factor;
}
int Rational::getNumerator() const
{
	return numerator;
}
int Rational::getDenominator() const
{
	return denominator;
}
int Rational::gcd(int n, int d)
{
	int n1 = abs(n);
	int n2 = abs(d);
	int gcd = 1;

	for (int k = 1; k <= n1 && k <= n2; k++)
	{
		if (n1%k == 0 && n2%k == 0)
		{
			gcd = k;
		}
	}
	return gcd;
}

Rational Rational::operator+(const Rational& secondRational)const
{
	int n = numerator * secondRational.getDenominator() + denominator * secondRational.getNumerator();
	int d = denominator * secondRational.getDenominator();
	return Rational(n, d);
}

Rational Rational::operator-(const Rational& secondRational)const
{
	int n = numerator * secondRational.getDenominator() - denominator * secondRational.getNumerator();
	int d = denominator * secondRational.getDenominator();
	return Rational(n, d);
}
Rational Rational::operator*(const Rational& secondRational)const
{
	int n = numerator * secondRational.getNumerator();
	int d = denominator * secondRational.getDenominator();
	return Rational(n, d);
}
Rational Rational::operator/(const Rational& secondRational)const
{
	int n = numerator * secondRational.getDenominator();
	int d = denominator * secondRational.numerator;
	return Rational(n, d);
}
int Rational::compareTo(const Rational& secondRational)const
{
	Rational temp = *this - (secondRational);
	if (temp.getNumerator() < 0)
		return -1;
	else if (temp.getNumerator() == 0)
		return 0;
	else
		return 1;
}
string Rational::toString()const
{
	stringstream ss;
	ss << numerator;

	if (denominator > 1)
		ss << "/" << denominator;

	return ss.str();
}
bool Rational::operator<(const Rational& r2)const
{
	return (compareTo(r2) < 0);
}
bool Rational::operator>(const Rational& r2)const
{
	return (compareTo(r2) > 0);
}
bool Rational::operator<=(const Rational& r2)const
{
	return (compareTo(r2) <= 0);
}
bool Rational::operator>=(const Rational& r2)const
{
	return (compareTo(r2) >= 0);
}
bool Rational::operator==(const Rational& r2)const
{
	return (compareTo(r2) == 0);
}
bool Rational::operator!=(const Rational& r2)const
{
	return(compareTo(r2) != 0);
}
bool Rational::operator<<(const Rational& r2)const
{
	return(compareTo(r2) << 0);
}
bool Rational::operator>>(const Rational& r2)const
{
	return(compareTo(r2) >> 0);
}
int Rational::operator[](int index)
{
	if (index == 0)
		return numerator;
	else
		return denominator;
}
/*Rational& Rational::operator+=(const Rational& r2)
{
	Rational temp = *this + r2;
	return temp;
}
Rational& Rational::operator-=(const Rational& r2)
{
	Rational temp = *this - r2;
	return temp;
}
Rational& Rational::operator*=(const Rational& r2)
{
	Rational temp = *this * r2;
	return temp;
}
Rational& Rational::operator/=(const Rational& r2)
{
	Rational temp = *this / r2;
	return temp;
}*/
Rational& Rational::operator++()
{
	numerator += denominator;
	return *this;
}
Rational Rational::operator++(int dummy)
{
	Rational temp(numerator, denominator);
	numerator += denominator;
	return temp;
}
Rational& Rational::operator--()
{
	numerator -= denominator;
	return *this;
}
Rational Rational::operator--(int dummy)
{
	Rational temp(numerator, denominator);
	numerator -= denominator;
	return temp;
}
