#include "FourRow.hpp"

#include <iostream>
#include <string>
#include <cstdlib>

int	main()
{
	std::string		cmd;
	FourRow		f;

	std::cout << "\\\\\\ Welcome to Four-in-a-row game!! ///" << std::endl;
	std::cout << "Available commands: new, exit" << std::endl;
	while (1)
	{
		std::cout << "> ";
		if (!std::getline(std::cin, cmd))
		{
			std::cout << std::endl;
			std::exit(1);
		}
		if (cmd.compare("new") == 0) {
			f.newGame();
			break;
		}
		else if (cmd.compare("exit") == 0)
			break;
		else
			std::cout << "Available commands: new, exit" << std::endl;
	}
	return 0;
}
