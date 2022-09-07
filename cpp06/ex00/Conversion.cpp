#include "Conversion.hpp"

Conversion &Conversion::operator=(Conversion const &src)
{
	value_ = src.value_;
	return *this;
}

char Conversion::toChar() const
{
	int n;

	if (value_.length() == 1 && (value_[0] < '0' || value_[0] > '9'))
	{
		return value_[0];
	}

	try
	{
		n = std::stoi(value_);
		if (n < 0 || n > 255)
			throw ImpossibleException();
	}
	catch (...)
	{
		throw ImpossibleException();
	}
	if (!isprint(n))
		throw NonDisplayableException();
	return static_cast<char>(n);
}

int Conversion::toInt() const
{
	int n;

	if (value_.length() == 1 && (value_[0] < '0' || value_[0] > '9'))
	{
		return value_[0];
	}
	try
	{
		n = std::stoi(value_);
	}
	catch (...)
	{
		throw ImpossibleException();
	}
	return n;
}

float Conversion::toFloat() const
{
	float n;

	if (value_.length() == 1 && (value_[0] < '0' || value_[0] > '9'))
	{
		return value_[0];
	}
	try
	{
		n = std::stof(value_);
	}
	catch (...)
	{
		throw ImpossibleException();
	}
	return n;
}

double Conversion::toDouble() const
{
	double n;

	if (value_.length() == 1 && (value_[0] < '0' || value_[0] > '9'))
	{
		return value_[0];
	}
	try
	{
		n = std::stod(value_);
	}
	catch (...)
	{
		throw ImpossibleException();
	}
	return n;
}

std::ostream& operator<<(std::ostream &out, const Conversion &ref)
{
    out << "char: ";
	try {
		char c = ref.toChar();
		out << "'" << c << "'" << std::endl;
	}
	catch (const std::exception &e)
	{
		out << e.what() << std::endl;
	}

	out << "int: ";
	try {
		out << ref.toInt() << std::endl;
	}
	catch (const std::exception &e)
	{
		out << e.what() << std::endl;
	}

	out << "float: ";
	try {
		float n = ref.toFloat();
		out << n;
		if (n - (int)n == 0)
			out << ".0";
		out << "f" << std::endl;
	}
	catch (const std::exception &e)
	{
		out << e.what() << std::endl;
	}

	out << "double: ";
	try {
		double n = ref.toDouble();
		out << n;
		if (n - (int)n == 0)
			out << ".0";
		out << std::endl;
	}
	catch (const std::exception &e)
	{
		out << e.what() << std::endl;
	}
	return out;
}
