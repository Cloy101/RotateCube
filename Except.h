#ifndef EXCEPT_H
#define EXCEPT_H

#include <iostream>
#include <stdexcept>

class Except
{
public:
	const float EPS = 0.00001f;
	
	template <typename T>
	bool exception_less_EPS(T value);

	template <typename T>
	bool exception_less_1(T value);


	//std::invalid_argument except;

};

#endif //FEXCEPT_H
