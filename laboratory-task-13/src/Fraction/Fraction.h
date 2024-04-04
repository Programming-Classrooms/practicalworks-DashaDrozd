#ifndef FRACTION
#define FRACTION
#include <iostream>


class Fraction {
private:
	int32_t n;
	int32_t d;
    
public:
	Fraction();
	Fraction(int32_t n, int32_t d);
	Fraction(const Fraction&);
	~Fraction();

	int32_t gcd(int32_t, int32_t);
	void SetN(int32_t n);
	void SetD(int32_t d);

	int32_t GetN();
	int32_t GetD();

	Fraction& operator=(const Fraction&);

	Fraction& simplify();
	Fraction operator-();
	Fraction operator+(const Fraction&);
	Fraction operator+(int32_t k);
	Fraction operator+=(const Fraction&);
	Fraction operator-(Fraction&);
	Fraction operator*(const Fraction&);
	Fraction operator/(const Fraction&);

	bool operator==(const Fraction&) const;
	bool operator<(const Fraction&) const;
	bool operator!=(const Fraction&) const;
	bool operator>(const Fraction&) const;

	Fraction operator++(int32_t k);
	Fraction& operator++();
	Fraction operator--(int32_t k);
	Fraction& operator--();
	Fraction operator~() const;
	Fraction cast();


	friend std::ostream& operator<<(std::ostream& out, const Fraction& rhs);
	friend std::istream& operator>>(std::istream& in, Fraction& c);

};
#endif
