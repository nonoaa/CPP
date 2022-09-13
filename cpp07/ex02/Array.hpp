#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>

template <typename T>
class Array
{
private:
	T *array_;
	unsigned int size_;

public:
	Array() : array_(new T[0]), size_(0)
	{
		std::cout << "------empty array created------" << std::endl;
	};
	Array(unsigned int n) : array_(new T[n]), size_(n)
	{
		std::cout << "------array created------" << std::endl;
		std::cout << *this;
	};
	Array(const Array &src) : array_(new T[src.size_]), size_(src.size_)
	{
		for (unsigned int i = 0; i < size_; i++)
		{
			array_[i] = src.array_[i];
		}
	};

	T getValue(unsigned int idx) const
	{
		return array_[idx];
	}

	unsigned int size() const
	{
		return size_;
	}

	T operator[](unsigned int idx) const
	{
		if (static_cast<int>(idx) < 0 || idx >= size_)
		{
			throw IndexOutOfBoundException();
		}
		return array_[idx];
	};

	T &operator[](unsigned int idx)
	{
		if (static_cast<int>(idx) < 0 || idx >= size_)
		{
			throw IndexOutOfBoundException();
		}
		return array_[idx];
	};

	class IndexOutOfBoundException : public std::exception 
	{
	public:
		const char *what() const throw()
		{
			return ("Array index out of bound exception.");
		}
	};
	
	~Array()
	{
		delete[] array_;
	};
};

template <typename T>
std::ostream& operator<<(std::ostream &out, const Array<T> &ref)
{
	out << "----------array---------" << std::endl;
	for (unsigned int i = 0; i < ref.size(); i++)
	{
		out << ref.getValue(i) << std::endl;
	}
	return out;
};

#endif