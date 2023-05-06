#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{
	return ;
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other)
{
	*this = other;
	return ;
}

BitcoinExchange	&BitcoinExchange::operator=(const BitcoinExchange &other)
{
	this->M = other.M;
	return (*this);
}

BitcoinExchange::~BitcoinExchange()
{
	return ;
}

bool	BitcoinExchange::dataParse(std::string	str, float *flo)
{
	std::istringstream	iss(str);
	int	year, month, day;
	char	seperator1, seperator2, seperator3;
	bool	boo;

	iss >> year >> seperator1 >> month >> seperator2 >> day >> seperator3 >> *flo;
	boo = !iss.fail() && iss.eof() && seperator1 == '-' && seperator2 == '-' && seperator3 == ','
		&& month >= 1 && month <= 12 && day >= 1 && day <= 31;
	return (boo && *flo >= 0);
}

bool	BitcoinExchange::txtParse(std::string	str, float *flo)
{
	int	year, month, day;
	char	seperator1, seperator2, seperator3;
	bool	boo;

	while (std::isspace(str[str.length() - 1]))
		str.erase(str.length() - 1);
	std::istringstream	iss(str);
	iss >> year >> seperator1 >> month >> seperator2 >> day >> seperator3 >> *flo;
	boo = iss.eof() && seperator1 == '-' && seperator2 == '-' && seperator3 == '|'
		&& month >= 1 && month <= 12 && day >= 1 && day <= 31;
	if (!boo || iss.fail())
		std::cout << "Error: bad input => " << str << std::endl;
	if (*flo < 0)
		std::cout << "Error: not a positive number." << std::endl;
	if (*flo > 1000)
		std::cout << "Error: too large a number." << std::endl;
	return (boo && *flo >= 0 && *flo <= 1000);
}

void	BitcoinExchange::fillMap(std::string s, float f)
{
	M.insert(std::make_pair(s, f));
}

void	BitcoinExchange::print(std::string str, float f)
{
	std::map<std::string, float>::iterator	it = M.upper_bound(str);
	if (it == M.begin())
		it++;
	it--;
	std::cout << str << " => " << f << " = " << f * it->second << std::endl;
}
