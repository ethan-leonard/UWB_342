#include "MyCo.h"

int main() {
	MyCo m(11), m2;
	MyCo me = m;
	m = m.Foo(m2, me, 13);
}
