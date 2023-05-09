#ifndef PMERGEME_H
# define PMERGEME_H

# include <iostream>
# include <string>
# include <deque>
# include <vector>
# include <algorithm>
# include <sstream>
# include <iterator>
# include <sys/time.h>

class   PmergeMe
{
	private:
		std::deque<int>	DQ;
		std::vector<int>	V;

	public:
		PmergeMe();
		PmergeMe(const PmergeMe &other);
		PmergeMe	&operator=(const PmergeMe &other);
		~PmergeMe();
	public:
		void	putV(std::string str);
		void	sortV(int beg, int end);
		void	insertSortV(int bed, int end);
		void	mergeV(int beg, int half, int end);
		void	printV();
		int	sizeV();
	public:
		void	putDQ(std::string str);
		void	sortDQ(int beg, int end);
		void	insertSortDQ(int bed, int end);
		void	mergeDQ(int beg, int half, int end);
		void	printDQ();
		int	sizeDQ();
};

#endif
