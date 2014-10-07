#include <iostream>
#include <string>
#include <fstream>

int main(int argc, char* argv[])
{
	std::cout << "\nBetterErrors Version 1.3 - Developed by megatron_\n\n";

	bool Warnings, Functions, Output;
	Warnings = Functions = Output = 0;
	char* file;

	if(argc > 1)
	{
		for(int i = 1; i < argc; i++)
		{
			if(argv[i][0] == '-')
			{
				switch(argv[i][1])
				{
					case 'W':
					case 'w':
						Warnings = 1;
						break;
					case 'F':
					case 'f':
						Functions = 1;
						break;
					case 'O':
					case 'o':
						Output = 1;
						break;
					default: std::cout << "\nErrorParser: Incorrect switch " << argv[i] << "\n";
				}
			}
			else if(Output) file = argv[i];
		}
	}

	std::string line; line = "";
	int Number; Number = 0;
	std::ofstream ofs;
	if(Output) ofs.open(file);
	
	while(std::getline(std::cin, line))
	{
		if(line.find("error:") != std::string::npos)
		{
			if(line.find("within this") != std::string::npos) std::cout << line << "\n\n";
			else
			{
				std::cout << line << "\n";
				Number++;
			}
		}
		if(line.find(".text+") != std::string::npos)
		{
			std::cout << line << "\n";
			Number++;
		}
		if(line.find("warning:") != std::string::npos && Warnings) std::cout << line << "\n";
		if(line.find("In function") != std::string::npos && Functions) std::cout << line << "\n\n";
		if(Output) ofs << line << "\n";
	}
	std::cout << "\nCompilation finished: I count " << Number << " errors. Fix 'em.\n";
	return 0;
}
