#include "Fraction.h"
#include <cmath>

Fraction::Fraction() : n(0), d(1)
{
}

Fraction::Fraction(int32_t n, int32_t d) : n(n), d(d)
{
	this->simplify();
}

Fraction::Fraction(const Fraction &rhs) : n(rhs.n), d(rhs.d)
{
	this->simplify();
}

Fraction::~Fraction()
{
}
Fraction& Fraction::simplify()
{
	int divisor = gcd(this->n, this->d);
	if(divisor == 0)
	{
		this->n =  0;
	}
	else{
		this->n /= divisor;
		this->d /= divisor;
	}
	
	return *this;
}

int32_t Fraction::gcd(int32_t n, int32_t m)
{
	if (m > n) {
		std::swap(n, m);
	}
	if(n == 0 || m==0)
	{
		return 0;
	}
	
	while(n % m != 0){
		n = n % m;
		std::swap(n, m);
	}

	return m;
}


void Fraction::SetN(int32_t n)
{
	this->n = n;
}

void Fraction::SetD(int32_t d)
{
	if (d <= 0)
	{
		throw std::invalid_argument("wrong denominator\n");
	}
	this->d = d;
}

int32_t Fraction::GetN()
{
	return n;
}

int32_t Fraction::GetD()
{
	return d;
}

Fraction &Fraction::operator=(const Fraction &rhs)
{
	if (this != &rhs)
	{
		this->n = rhs.n;
		this->d = rhs.d;
	}
	return *this;
}

Fraction Fraction::operator-()
{
	return Fraction(-n, d);
}

Fraction Fraction::operator+(const Fraction &rhs)
{
	return Fraction(n * rhs.d + rhs.n * d, d * rhs.d).simplify();
}

Fraction Fraction::operator-(Fraction &rhs)
{
	return Fraction(*this + (-rhs)).simplify();
}

Fraction Fraction::operator+(int32_t k)
{
	return Fraction(n + k * d, d).simplify();
}

Fraction Fraction::operator+=(const Fraction &rhs)
{
	*this = *this + rhs;
	return *this;
}

Fraction Fraction::operator*(const Fraction &rhs)
{
	return Fraction(n * rhs.n, d * rhs.d).simplify();
}

Fraction Fraction::operator/(const Fraction &rhs)
{
	if (rhs.n == 0)
	{
		throw std::invalid_argument("division by zero!!!\n");
	}
	return Fraction(n * rhs.d, d * rhs.n).simplify();
}

bool Fraction::operator==(const Fraction &rhs) const
{
	return (n * rhs.d == d * rhs.n);
}

bool Fraction::operator<(const Fraction &rhs) const
{
	return (n * rhs.d < d * rhs.n);
}

bool Fraction::operator!=(const Fraction &rhs) const
{
	return !(n * rhs.d == d * rhs.n);
}

bool Fraction::operator>(const Fraction &rhs) const
{
	return (n * rhs.d > d * rhs.n);
}

Fraction Fraction::operator++(int32_t k)
{
	Fraction result(*this);
	++n;
	++d;
	return result;
}

Fraction &Fraction::operator++()
{
	++n;
	++d;
	return *this;
}

Fraction Fraction::operator--(int32_t k)
{
	Fraction result(*this);
	--n;
	--d;
	return result;
}

Fraction &Fraction::operator--()
{
	--n;
	--d;
	return *this;
}

Fraction Fraction::operator~() const
{
	return Fraction(d, n);
}

Fraction Fraction::cast()
{
	return Fraction(static_cast<double>(n), static_cast<double>(d));
}

std::ostream &operator<<(std::ostream &out, const Fraction &rhs)
{
	out << rhs.n << "/" << rhs.d << '\n';
	return out;
}

std::istream &operator>>(std::istream &in, Fraction &c)
{
	std::cout << "Input numinator and denaminator:\n";
	in >> c.n >> c.d;
	c.simplify();
	return in;
}
