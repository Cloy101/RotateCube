#ifndef CONNECTION_H
#define CONNECTION_H

#include <vector>


class Connection
{
public:
	Connection(int a=0, int b=0)
	{
		setA(a);
		setB(b);
	};

	void setA(int a) { this->a = a; };
	void setB(int b) { this->b = b; };

	int getA() { return a; };
	int getB() { return b; };

private:
	int a, b;

};

#endif // !CONNECTION_H