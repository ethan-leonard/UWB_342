#include "MyCo.h" 
#include <iostream>

MyCo::MyCo() {
	count = 1;
}

MyCo::MyCo(const MyCo& m) {
	this->count = m.count + 3;
}

MyCo::MyCo(int i) {
	count = i;
}

MyCo& MyCo::Foo(MyCo m1, MyCo& m2, int c) {
	MyCo m = m1;
	m.count += c;
	m2.count += c;
	return m2;
}

MyCo::~MyCo() {
	std::cout << count << std::endl;
}
