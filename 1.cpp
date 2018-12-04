#include <iostream>
#include <sstream>

int main()
{
	int64_t total = 0;
	std::string buf;
	while ( std::getline( std::cin, buf ) )
	{
		total += std::stoi( buf );
	}
	std::cout << total << std::endl;
	return 0;
}
