#include <iostream>
using namespace std;

struct RationalNumber
{
	int boonja, boonmo;
	RationalNumber(int bj, int bm) : boonja(bj), boonmo(bm) {
	}

	RationalNumber Add(RationalNumber rhs)
	{
		boonja = boonja * rhs.boonmo + boonmo * rhs.boonja;
		boonmo = boonmo * rhs.boonmo;
		return *this;
	}

	RationalNumber Subtract(RationalNumber rhs)
	{
		boonja = boonja * rhs.boonmo - boonmo * rhs.boonja;
		boonmo = boonmo * rhs.boonmo;
		return *this;
	}

	RationalNumber Mutiply(RationalNumber rhs)
	{
		boonmo *=  rhs.boonmo;
		boonja *= rhs.boonja;
		return *this;
	}

	RationalNumber Divide(RationalNumber rhs)
	{
		RationalNumber tmp(rhs.boonmo, rhs.boonja);
		tmp.Mutiply(*this);
		boonja = tmp.boonja;
		boonmo = tmp.boonmo;
		return *this;
	}

	int gcd(int a, int b)
	{
		if ( b == 0 )
		{
			return a;
		}
		else
		{
			return gcd(b, a % b);
		}
	}

	void YakBoon()
	{
		int GCD = gcd(boonja, boonmo);
		boonmo /= GCD;
		boonja /= GCD;
	}
	
	friend ostream& operator<<(ostream &os, RationalNumber &rm)
	{
		os << "(" << rm.boonja << "/" << rm.boonmo << ")";
		return os;
	}
};


int main()
{
	RationalNumber a(1, 2);
	RationalNumber b(2, 3);
	
	a.Add(b);
	a.YakBoon();
	cout << a << endl;

	a = RationalNumber(1, 2);
	a.Subtract(b);
	a.YakBoon();
	cout << a << endl;

	a = RationalNumber(1, 2);
	a.Mutiply(b);
	a.YakBoon();
	cout << a << endl;

	a = RationalNumber(1, 2);
	a.Divide(b);
	a.YakBoon();
	cout << a << endl;

	return 0;
}