#pragma once
#include <iostream>
#include <cassert>
#include "Polynomial.h"
using namespace std;

class Rational
{
private:
	Polynomial nom;
	Polynomial denom;

public:

	Rational();
	Rational(const Polynomial& P1, const Polynomial& P2);

	//gets
	Polynomial getNom();
	Polynomial getDenom();

	void print();

	//operators
	Rational operator +(const Rational&);
	Rational operator *(const Rational&);
	bool operator==(const Rational&);
	friend ostream& operator <<(ostream&, const Rational&);


};

