#include <iostream>
#include <fstream>

std::string ft_replace(std::string str, std::string s1, std::string s2)
{
	std::string::size_type idx = 0;
	std::string::size_type n;

	while ((n = str.find(s1,idx)) != std::string::npos)
	{
		str.erase(n, s1.length());
		str.insert(n, s2);
		idx = n + s2.length();
	}
	return (str);
}

int main(int ac, char *av[])
{
	if (ac != 4)
	{
		std::cerr << "Error: Wrong Arguments." << std::endl;
		return (1); 
	}

	std::string filename = av[1];
	std::string s1 = av[2];
	std::string s2 = av[3];

	std::ifstream ifile(filename);
	if (!ifile.is_open())
	{
		std::cerr << "Error: File open error." << std::endl;
		return (1);
	}
	std::ofstream ofile(filename + ".replace");
	if (!ofile.is_open())
	{
		ifile.close();
		std::cerr << "Error: File open error." << std::endl;
		return (1);
	}

	while (true)
	{
		std::string line;
		getline(ifile, line);
		
		ofile << ft_replace(line, s1, s2);
		if (ifile.eof())
		{
			break;
		}
		ofile << std::endl;
	}
	ifile.close();
	ofile.close();
	return (0);
}