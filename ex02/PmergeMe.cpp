#include "PmergeMe.hpp"

PmergeMe::PmergeMe()
{
	return ;
}

PmergeMe::PmergeMe(const PmergeMe &other)
{
	*this = other;
	return ;
}

PmergeMe	&PmergeMe::operator=(const PmergeMe &other)
{
	this->DQ = other.DQ;
	this->V = other.V;
	return (*this);
}

PmergeMe::~PmergeMe()
{
	return ;
}

void	PmergeMe::putV(std::string str)
{
	std::istringstream	iss(str);
	char	c;
	int	a;

	while (iss >> c)
	{
		if (std::isdigit(c))
		{
			iss.putback(c);
			iss >> a;
			std::vector<int>::iterator it = std::find(V.begin(), V.end(), a);
			if (it == V.end())
				V.push_back(a);
		}
		else if (!std::isspace(c))
		{
			std::cout << "Wrong input\n";
			exit(1);
		}
	}
}

void	PmergeMe::mergeV(int beg, int half, int end)
{
	int	i, j, k;
	int a = half - beg + 1;
	int b = end - half;
	std::vector<int> Va(a), Vb(b);

	for (i = 0; i < a; i++)
		Va[i] = V[beg + i];
	for (i = 0; i < b; i++)
		Vb[i] = V[half + 1 + i];
	i = 0;
	j = 0;
	k = beg;
	while (i < a && j < b)
	{
		if (Va[i] <= Vb[j])
			V[k] = Va[i++];
		else
			V[k] = Vb[j++];
		k++;
	}
	while (i < a)
		V[k++] = Va[i++];
	while (j < b)
		V[k++] = Vb[j++];
}

void	PmergeMe::insertSortV(int beg, int end)
{
	for (int i = beg + 1; i <= end; i++)
	{
		int	k = V[i];
		int	j = i - 1;

		while (j >= beg && V[j] > k)
		{
			V[j + 1] = V[j];
			j--;
		}
		V[j + 1] = k;
	}
}

void	PmergeMe::sortV(int beg, int end)
{
	if (beg >= end)
		return ;
	if (end - beg + 1 < 10)
		insertSortV(beg, end);
	else
	{
		int	half = beg + (end - beg) / 2;
		sortV(beg, half);
		sortV(half + 1, end);
		mergeV(beg, half, end);
	}
}

int	PmergeMe::sizeV()
{
	return (V.size());
}

void	PmergeMe::printV()
{
	for (int i = 0; i < (int)V.size(); i++)
		std::cout << V[i] << " ";
}

void	PmergeMe::putDQ(std::string str)
{
	std::istringstream	iss(str);
	char	c;
	int	a;

	while (iss >> c)
	{
		if (std::isdigit(c))
		{
			iss.putback(c);
			iss >> a;
			std::deque<int>::iterator it = std::find(DQ.begin(), DQ.end(), a);
			if (it == DQ.end())
				DQ.push_back(a);
		}
		else if (!std::isspace(c))
		{
			std::cout << "Wrong input\n";
			exit(1);
		}
	}
}

void	PmergeMe::mergeDQ(int beg, int half, int end)
{
	int	i, j, k;
	int a = half - beg + 1;
	int b = end - half;
	std::deque<int> DQa(a), DQb(b);

	for (i = 0; i < a; i++)
		DQa[i] = DQ[beg + i];
	for (i = 0; i < b; i++)
		DQb[i] = DQ[half + 1 + i];
	i = 0;
	j = 0;
	k = beg;
	while (i < a && j < b)
	{
		if (DQa[i] <= DQb[j])
			DQ[k] = DQa[i++];
		else
			DQ[k] = DQb[j++];
		k++;
	}
	while (i < a)
		DQ[k++] = DQa[i++];
	while (j < b)
		DQ[k++] = DQb[j++];
}

void	PmergeMe::insertSortDQ(int beg, int end)
{
	for (int i = beg + 1; i <= end; i++)
	{
		int	k = DQ[i];
		int	j = i - 1;

		while (j >= beg && DQ[j] > k)
		{
			DQ[j + 1] = DQ[j];
			j--;
		}
		DQ[j + 1] = k;
	}
}

void	PmergeMe::sortDQ(int beg, int end)
{
	if (beg >= end)
		return ;
	if (end - beg + 1 < 10)
		insertSortDQ(beg, end);
	else
	{
		int	half = beg + (end - beg) / 2;
		sortDQ(beg, half);
		sortDQ(half + 1, end);
		mergeDQ(beg, half, end);
	}
}

int	PmergeMe::sizeDQ()
{
	return (DQ.size());
}

void	PmergeMe::printDQ()
{
	for (int i = 0; i < (int)DQ.size(); i++)
		std::cout << DQ[i] << " ";
}