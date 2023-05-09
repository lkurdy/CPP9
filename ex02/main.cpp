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

	struct timeval start, end;

	std::cout << "Before: ";
	pm.printV();
	std::cout << std::endl;

	gettimeofday(&start, NULL);

	pm.sortV(0, pm.sizeV() - 1);

	gettimeofday(&end, NULL);

	std::cout << "After: ";
	pm.printV();
	std::cout << std::endl;
	double	time = (end.tv_sec - start.tv_sec) + (end.tv_usec - start.tv_usec);
	std::cout << "Processed " << pm.sizeV() << " ints in a std::vector in " << time << " us\n";


	std::cout << "Before: ";
	pm.printDQ();
	std::cout << std::endl;

	gettimeofday(&start, NULL);

	pm.sortDQ(0, pm.sizeDQ() - 1);

	gettimeofday(&end, NULL);

	std::cout << "After: ";
	pm.printDQ();
	std::cout << std::endl;
	time = (end.tv_sec - start.tv_sec) + (end.tv_usec - start.tv_usec);
	std::cout << "Processed " << pm.sizeDQ() << " ints in a std::deque in " << time << " us\n";
	return (0);
}

