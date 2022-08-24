#pragma once
#include <iostream>
#include <cassert>
	using namespace std;

class Polynomial
{

private:

	const static int SIZE = 1000;
	static int degreeArr[SIZE];
	static int _size;
	int static maxDegree;

	int degree;
	double coeff[100] = { 0 };

public:

	Polynomial();
	Polynomial(int);
	Polynomial(const double*, int);

	void print();

	//gets
	int getDegree(bool)const;
	int static getMaxDegree();
	double getCoeff(int)const;

	//sets
	void setCoeff(int, double);
	void setDegree(int);

	//operators
	Polynomial operator +(const Polynomial&);
	Polynomial operator *(const Polynomial&);
	Polynomial operator -(const Polynomial&); 
	friend Polynomial operator *(double index , const Polynomial&p1)
	{
		Polynomial temp(p1.coeff,p1.degree);
		for (int i = 0; i < p1.getDegree(true); i++)
		{
			temp.setCoeff(i, index * p1.getCoeff(i));
		}
		return temp;
	}
	friend ostream& operator <<(ostream& , const Polynomial&);
	bool operator==(const Polynomial&);
	//void operator=(const Polynomial&);
};


