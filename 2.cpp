#include <iostream>
#include <sstream>
#include <map>
#include <fstream>

int main( int argc, char **argv )
{
	try
	{
		if ( argc < 2 ) throw std::runtime_error( "please supply input file" );
		int twice = 0, thrice = 0;
		std::string buf;
		const auto filename = argv[ 1 ];
		for ( std::ifstream input( filename ); std::getline( input, buf ); )
		{
			std::map< std::string::value_type, int > frequency_count;
			for ( auto c : buf )
			{
				++frequency_count[ c ];
			}
			int twice_add = 1, thrice_add = 1;
			for ( auto &key_value : frequency_count )
			{
				switch ( key_value.second )
				{
					case 2:
						twice += twice_add;
						twice_add = 0;
						break;
					case 3:
						thrice += thrice_add;
						thrice_add = 0;
						break;
					default:
						break;
				}
			}
		}
		std::cout << twice * thrice << std::endl;
	}
	catch( const std::exception &err )
	{
		std::cerr << err.what() << std::endl;
		return 1;
	}
	return 0;
}
