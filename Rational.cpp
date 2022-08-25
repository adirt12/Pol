#include "Rational.h"


Rational::Rational()
{
	//this->denom.setDegree(2);
	this->denom=1;
	this->nom = 0;
}

Rational::Rational(const Polynomial& P1, const Polynomial& P2)
{
	this->nom = P1;
	this->denom = P2;
}

//gets
Polynomial Rational::getNom()
{
	return nom;
}

Polynomial Rational::getDenom()
{
	return denom;
}

void Rational::print()
{
	nom.print();
	cout << "--------------------------" << endl;
	/*if (denom.getDegree(true) == 0 && nom.getDegree(false) == 0)
	{
		cout << "1";
	}*/
	if (this->denom.getDegree(false) == 1)
	{
		cout<<"Polynomial: "<<"1"<<endl;
	}
	else 
	{
		denom.print();
	}
}

bool Rational::operator==(const Rational& r1)
{
	int flag = 0, i=0; 
	if (r1.denom.getDegree(true) == this->denom.getDegree(true))
	{
		for (i = 0; i < r1.denom.getDegree(true); i++)
		{
			if (this->denom.getCoeff(i) != r1.denom.getCoeff(i))
			{
				return false;
			}
		}
		return true;
	}
	return false;
}

Rational Rational:: operator +(const Rational&r1)
{
	Rational temp;
	if (this->denom.getDegree(true) > r1.denom.getDegree(true))
	{
		temp.denom.setDegree(this->denom.getDegree(true)*2);
	}
	else {
		temp.denom.setDegree(r1.denom.getDegree(true)*2);
	}

	if (this->nom.getDegree(true) > r1.nom.getDegree(true))
	{
		temp.nom.setDegree(this->nom.getDegree(true)*2 );
	}
	else {
		temp.nom.setDegree(r1.nom.getDegree(true)*2 );
	}

	if (this->denom == r1.denom)
	{
		for(int i=0;i<r1.denom.getDegree(true);i++)
		{
			temp.denom.setCoeff(i, r1.denom.getCoeff(i)) ;
		}
		for (int i = 0; i < r1.nom.getDegree(true); i++)
		{
			temp.nom.setCoeff(i,this->nom.getCoeff(i) + r1.nom.getCoeff(i) );
		}
		
	}
	else
	{
		for (int i = 0; i < r1.denom.getDegree(true); i++) 
		{
			temp.denom.setCoeff(i, this->denom.getCoeff(i) * r1.denom.getCoeff(i)) ;
		}
		for (int i = 0; i < r1.nom.getDegree(true); i++)
		{
			temp.nom.setCoeff(i, (this->nom.getCoeff(i) * r1.denom.getCoeff(i)) + (this->denom.getCoeff(i) * r1.nom.getCoeff(i)) ) ;
		}
		
	}
	return temp;
}

Rational Rational:: operator *(const Rational& r1)
{
	Rational temp(r1.nom,r1.denom);
	for (int i = 0; i < r1.nom.getDegree(true); i++)
	{
		temp.nom.setCoeff(i, this->nom.getCoeff(i) * r1.nom.getCoeff(i)) ;
	}
	for (int i = 0; i < r1.denom.getDegree(true); i++)
	{
		temp.denom.setCoeff(i, this->denom.getCoeff(i) * r1.denom.getCoeff(i));
	}
	return temp;
}

ostream& operator <<(ostream& out, const Rational&r1)
{
	if (r1.denom.getDegree(false) == 1)
	{
		out << "nominator=" << r1.nom << endl << "------------------"
			<< endl << "denominator=" << 1 <<endl;
	}
	else{
		out <<"nominator="<< r1.nom << endl << "------------------" 
			<< endl <<"denominator=" << r1.denom <<endl;
	}
	return out;
}

void Rational::operator =(const Rational& r1)
{
	//Rational temp(r1);
	this->denom.setDegree(r1.denom.getDegree(true)*2);
	this->nom.setDegree(r1.nom.getDegree(true) * 2);

	for (int i = 0; i < r1.denom.getDegree(true) * 2; i++)
	{
		this->denom.setCoeff(i, r1.denom.getCoeff(i));
	}
	for (int i = 0; i < r1.nom.getDegree(true) * 2; i++)
	{
		this->nom.setCoeff(i, r1.nom.getCoeff(i));
	}

	//return temp;
}