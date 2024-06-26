#pragma once
#include <iostream>
using namespace std;

class Pir {
protected:
	int a, b, h;
public:
	Pir();
	Pir(const Pir& r);
	Pir(int a, int b, int h);
	virtual float v() const;
	virtual int s() const;
	virtual void print() const;
	int get_h() const;
	void set_h(int new_h);
	void compare_s(Pir& r1);
	void scalar(int n);
	
	friend istream& operator>>(istream& is, Pir& r);
};

class Pr : public Pir {
public:
	Pr();
	Pr(const Pr& r);
	Pr(int a, int h);
	int s() const override ;
	void print() const override;
	float apo() const;
	
	friend istream& operator>>(istream& is, Pr& r);
};