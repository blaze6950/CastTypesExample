#include <iostream>

using namespace std;

class A{
public:
	int f = 10;
	virtual void show()
	{
		cout << f << endl;
	}
};

class B : public A{
public:
	int g = 12;
	virtual void show() override
	{
		A::show();
		cout << g << endl;
	}
};

void cCast()
{
	double d = 23.4;
	int i = 123;

	cout << i + (int)d << endl;

	int* p = &i;
	double* pd = (double*)p;
	cout << *pd << endl;


	A a;
	B b;
	A a1 = (A)b;
	//B b1 = (B)a;
}

//static_cast < результирующий тип > ( выражение )
void staticCast()
{
	int i = 123;
	double d = 12.4;

	cout << static_cast<int>(d)+i << endl;

	void* p = static_cast<void*>(&d);

	B* pb = new B;
	A* pa = static_cast<A*>(pb);
	pa->f = 13;

	A* pa1 = new A;
	B* pb1 = static_cast<B*>(pa1);
	cout << pb1->f << endl;
	cout << pb1->g << endl;//error
}

void dynamicCast()
{
	A* pa = new B;
	
	B* pb = dynamic_cast<B*>(pa);

	if (pb == nullptr)
	{
		cout << "error" << endl;
		return;
	}
	pb->f = 10;
	pb->g = 12;

	pb->show();	

	try
	{
		A obj;
		B& rb = dynamic_cast<B&>(obj);
	}
	catch (bad_cast& ex)
	{
		cout << ex.what() << endl;
	}
}

void constSast(){
	
	int a = 10;

	const int& cr = a;

	
	int& r = const_cast<int&>(cr);

	r = 20;

	cout << a << endl;
}

unsigned short Hash(void *p) {
	unsigned int val = reinterpret_cast<unsigned int>(p);
	return (unsigned short)(val ^ (val >> 16));
}

void reinterpretCast()
{
	int a[20];
	for (int i = 0; i < 20; i++)
		cout << Hash(a + i) << endl;
}

int main()
{
	//cCast();
	//staticCast();
	//dynamicCast();	
	//constSast();
	reinterpretCast();
}