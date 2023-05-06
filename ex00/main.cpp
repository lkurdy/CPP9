#include "BitcoinExchange.hpp"

int	main(int argc, char **argv)
{
	if (argc != 2)
		return (std::cout << "Invalid arguments\n", 1);
	std::ifstream	fcsv("data.csv");
	std::ifstream	ftxt(argv[1]);
	if (!fcsv.is_open())
		return (std::perror("data.csv"), 1);
	if (!ftxt.is_open())
		return (std::perror(argv[1]), ftxt.close(), 1);

	BitcoinExchange	btc;
	float	flo;
	int	i = 1;
	std::string	strcsv, strtxt;
	std::getline(fcsv,strcsv);
	if (strcsv.compare("date,exchange_rate"))
			return (std::cout << "First line is wrong, should be: date,exchange_rate\n", 1);
	while (std::getline(fcsv, strcsv))
	{
		i++;
		flo = 0;
		if (btc.dataParse(strcsv, &flo))
			btc.fillMap(strcsv.substr(0, strcsv.find(',')), flo);
		else
			return (std::cout << "Error in csv file in line " << i << std::endl, 1);
	}
	std::getline(ftxt,strtxt);
	if (strtxt.compare("date | value"))
			return (std::cout << "First line is wrong, should be: date | value\n", 1);
	while (std::getline(ftxt, strtxt))
	{
		flo = 0;
		if (btc.txtParse(strtxt, &flo))
			btc.print(strtxt.substr(0, strtxt.find('|')), flo);
	}
}
