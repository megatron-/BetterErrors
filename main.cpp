#include <iostream>
#include <string>

int main()
{
	std::string line;
	while(std::getline(std::cin, line)) // while the file is open
	{
		if(line.find("within this") != std::string::npos) continue;
		if(line.find("error:") != std::string::npos) std::cout << line << "\n";
	}
	return 0;
}
