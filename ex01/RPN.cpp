#include "RPN.hpp"

RPN::RPN()
{
	return ;
}

RPN::RPN(const RPN &other)
{
	*this = other;
	return ;
}

RPN	&RPN::operator=(const RPN &other)
{
	this->S = other.S;
	return (*this);
}

RPN::~RPN()
{
	return ;
}

void	RPN::doDaTing(std::string str)
{
	std::istringstream	iss(str);
	int	a, b;
	char	c;

	while (iss >> c)
	{
		if (std::isdigit(c))
		{
//			iss.putback(c);
//			iss >> a;
			a = c - '0';
			S.push(a);
		}
		/*
		else if (c == '-' && std::isdigit(iss.peek()))
		{
			iss >> a;
			a *= -1;
			S.push(a);
		}
		*/
		else if (c == '+' || c == '-' || c == '*' || c == '/')
		{
			if (S.size() < 2)
			{
				std::cout << "Invalid input\n";
				exit(1);
			}
			b = S.top();
			S.pop();
			a = S.top();
			S.pop();
			switch (c)
			{
				case '+': a = a + b; break;
				case '-': a = a - b; break;
				case '*': a = a * b; break;
				case '/': a = a / b; break;
			}
			S.push(a);
		}
		else
		{
			std::cout << "Invalid input\n";
			exit(1);
		}
	}
	if (S.size() != 1)
	{
		std::cout << "Invalid input\n";
		exit(1);
	}
	std::cout << S.top() << std::endl;
}
