#include "Pir.h"
#include <fstream>
#include <vector>
#include <algorithm>
float v = 0.0;
vector<Pir> p;
vector<Pr> r;
template <typename T>
bool byh(T& t, T& t1) {
	return t.get_h() > t1.get_h();
}
template <typename T>
void change(T& t) {
	t.set_h(1);
}
int main()
{
	ifstream file("file.txt");
	char x;
	while (file >> x) {
		switch (x) {
		case '1': {
			Pir t;
			file >> t;
			v += t.v();
			p.push_back(t);
			break;
		}case '2': {
			Pr t;
			file >> t;
			v += t.v();
			r.push_back(t);
			break;
		}
		}
	}
	file.close();
	for (const auto& i : p) {
		i.print();
	}
	for (const auto& i : r) {
		i.print();
	}
	sort(p.begin(), p.end(), byh<Pir>);
	auto max = p.begin();
	sort(r.begin(), r.end(), byh<Pr>);
	auto max1 = r.begin();
	cout << "the highest is : ";
	if (max->get_h() > max1->get_h()) max->print();
	else if (max->get_h() < max1->get_h()) max1->print();
	cout << " update : " << endl;
	
	for_each(p.begin(), p.end(), change<Pir>);
	for_each(r.begin(), r.end(), change<Pr>);
	for (const auto& i : p) {
		i.print();
	}
	for (const auto& i : r) {
		i.print();
	}
	cout << " overall v = " << v;

    return 0;
	
}
