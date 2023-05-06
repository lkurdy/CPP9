#ifndef RPN_H
# define RPN_H

# include <iostream>
# include <string>
# include <stack>
# include <sstream>
# include <cstdlib>

class   RPN
{
	private:
		std::stack<int>	S;

	public:
		RPN();
		RPN(const RPN &other);
		RPN	&operator=(const RPN &other);
		~RPN();
	public:
		void	doDaTing(std::string str);
};

#endif
