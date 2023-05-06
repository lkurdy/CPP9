#include "RPN.hpp"

int	main(int argc, char **argv)
{
	if (argc != 2)
		return (std::cout << "Invalid number of arguments\n", 1);
	RPN	rpn;
	std::string	str = argv[1];
	rpn.doDaTing(str);
	return (0);
}
