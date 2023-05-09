#include "PmergeMe.hpp"

int	main(int argc, char **argv)
{
	if (argc < 2)
		return (std::cout << "Put some numbers\n", 1);
	PmergeMe	pm;
	for (int i = 1; argv[i]; i++)
		pm.putV(argv[i]);
	for (int i = 1; argv[i]; i++)
		pm.putDQ(argv[i]);

	clock_t	start, end;
	std::cout << "Before: ";
	pm.printV();
	std::cout << std::endl;

	start = clock();

	pm.sortV(0, pm.sizeV() - 1);

	end = clock();

	std::cout << "After: ";
	pm.printV();
	std::cout << std::endl;
	double	time = static_cast<double> (end - start) / CLOCKS_PER_SEC * 1000000;
	std::cout << "Processed " << pm.sizeV() << " ints in a std::vector in " << time << " us\n";


	std::cout << "Before: ";
	pm.printDQ();
	std::cout << std::endl;

	start = clock();

	pm.sortDQ(0, pm.sizeDQ() - 1);

	end = clock();

	std::cout << "After: ";
	pm.printDQ();
	std::cout << std::endl;
	time = static_cast<double> (end - start) / CLOCKS_PER_SEC * 1000000;
	std::cout << "Processed " << pm.sizeDQ() << " ints in a std::deque in " << time << " us\n";
	return (0);
}

