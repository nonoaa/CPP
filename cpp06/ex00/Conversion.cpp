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

	const char *str = value_.c_str();
	char *stopstr = NULL;

	n = static_cast<int>(strtod(str, &stopstr));
	if (str != stopstr && !isinf(n) && !isnan(n) && n >= 0 && n <= 255)
	{
		if (!isprint(n))
			throw NonDisplayableException();
		return static_cast<char>(n);
	}
	else
		throw ImpossibleException();
}

int Conversion::toInt() const
{
	double n;

	if (value_.length() == 1 && (value_[0] < '0' || value_[0] > '9'))
	{
		return value_[0];
	}
	if (value_.length() == 1 && value_[0] == '0')
		return 0;
	const char *str = value_.c_str();
	char *stopstr = NULL;

	n = strtod(str, &stopstr);
	if (str != stopstr && !isinf(n) && !isnan(n) && n >= -2147483648 && n <= 2147483647)
		return static_cast<int>(n);
	else
		throw ImpossibleException();
}

float Conversion::toFloat() const
{
	double n;

	if (value_.length() == 1 && (value_[0] < '0' || value_[0] > '9'))
	{
		return value_[0];
	}
	if (value_.length() == 1 && value_[0] == '0')
		return 0;
	const char *str = value_.c_str();
	char *stopstr = NULL;

	n = strtod(str, &stopstr);
	if (str != stopstr)
		return static_cast<double>(n);
	else
		throw ImpossibleException();
}

double Conversion::toDouble() const
{
	double n;

	if (value_.length() == 1 && (value_[0] < '0' || value_[0] > '9'))
	{
		return value_[0];
	}
	if (value_.length() == 1 && value_[0] == '0')
		return 0;
	const char *str = value_.c_str();
	char *stopstr = NULL;

	n = strtod(str, &stopstr);
	if (str != stopstr)
		return n;
	else
		throw ImpossibleException();
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
