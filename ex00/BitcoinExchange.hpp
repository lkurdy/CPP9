#ifndef BITCOINEXCHANGE_H
# define BITCOINEXCHANGE_H

# include <iostream>
# include <string>
# include <fstream>
# include <sstream>
# include <map>

class   BitcoinExchange
{
	private:
		std::map<std::string, float>	M;

	public:
		BitcoinExchange();
		BitcoinExchange(const BitcoinExchange &other);
		BitcoinExchange	&operator=(const BitcoinExchange &other);
		~BitcoinExchange();
	public:
		bool	dataParse(std::string	str, float *flo);
		bool	txtParse(std::string	str, float *flo);
		void	fillMap(std::string s, float f);
		void	print(std::string str, float f);
};

#endif
