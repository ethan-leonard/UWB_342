#ifndef MyCo_H_
#define MyCo_H_

class MyCo {
	public: 
		MyCo();
		MyCo(const MyCo& m);
		~MyCo();
		MyCo(int i);
		MyCo& Foo(MyCo m1, MyCo &m2, int c);

	private:
		int count;
};

#endif