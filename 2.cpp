#include <iostream>
#include <sstream>
#include <map>
#include <fstream>

int main( int argc, char **argv )
{
	try
	{
		if ( argc < 2 ) throw std::runtime_error( "please supply input file" );
		std::map< int64_t, int > frequency_count;
		int64_t total = 0;
		++frequency_count[ total ];
		std::string buf;
		for ( ;; )
		{
			const auto filename = argv[ 1 ];
			for ( std::ifstream input( filename ); std::getline( input, buf ); )
			{
				total += std::stoi( buf );
				if ( ++frequency_count[ total ] > 1 )
				{
					std::cout << total << std::endl;
					return 0;
				}
			}
		}
		std::cout << total << std::endl;
	}
	catch( const std::exception &err )
	{
		std::cerr << err.what() << std::endl;
		return 1;
	}
	return 0;
}
