#ifndef CONVERSION_HPP
#define CONVERSION_HPP

#include <iostream>
#include <string>

class Conversion
{
private:
	std::string value_;
	Conversion();

public:
	Conversion(std::string const &input) : value_(input) {};
	Conversion(Conversion const &src) : value_(src.value_) {};
	Conversion &operator=(Conversion const &src);
	~Conversion() {};
	char toChar() const;
	int toInt() const;
	float toFloat() const;
	double toDouble() const;

	class ImpossibleException : public std::exception
	{
		const char *what() const throw()
		{
			return "impossible";
		}
	};
	class NonDisplayableException : public std::exception
	{
		const char *what() const throw()
		{
			return "Non displayable";
		}
	};
};

std::ostream& operator<<(std::ostream &out, const Conversion &ref);

#endif