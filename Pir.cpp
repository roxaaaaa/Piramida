#include "Pir.h"

Pir::Pir()
{
	a = 1;
	b = 1;
	h = 1;
}

Pir::Pir(const Pir& r)
{
	a = r.a;
	b = r.b;
	h = r.h;
}

Pir::Pir(int a, int b, int h) : a(a), b(b), h(h) {}

float Pir::v() const
{
	float v = (s() * h)/3;
	return v;
}

int Pir::s() const
{
	return a*b;
}

void Pir::print() const
{
	cout << "piramida : a = " << a << " b = " << b << " h = " << h << endl;
}

int Pir::get_h() const
{
	return h;
}

void Pir::set_h(int new_h)
{
	h = new_h;
}

void Pir::compare_s(Pir& r1)
{
	if (s() > r1.s()) {
		
	}
	else if (s() < r1.s()) {
		r1.print();
		cout << "is bigger than ";
		print();
	}
	else if (s() == r1.s()) {
		r1.print();
		cout << " has the same s as ";
		print();
	}
}

void Pir::scalar(int n)
{
	a *= n;
	b *= n;
	h *= n;
}


istream& operator>>(istream& is, Pir& r)
{
	is >> r.a >> r.b >> r.h;
	return is;
}

istream& operator>>(istream& is, Pr& r)
{
	is >> r.a >> r.h;
	return is;
}
Pr::Pr() : Pir(1, 1, 1) {}

Pr::Pr(const Pr& r) : Pir(r.a, r.a, r.h) {}

Pr::Pr(int a, int h) : Pir(a, a, h) {}

int Pr::s() const
{
	return a*a;
}

void Pr::print() const
{
	cout << "pravylna piramida : a = " << a  << " h = " << h << endl;
}

float Pr::apo() const
{
	float b = (a * a) / 4;
	float c = h * h * b;
	return h/c;
}
