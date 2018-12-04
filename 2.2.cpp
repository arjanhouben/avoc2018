#include <iostream>
#include <sstream>
#include <vector>
#include <fstream>
#include <tuple>
#include <algorithm>

std::string difference( const std::string &a, const std::string &b )
{
	std::string result;
	result.reserve( a.size() );
	for ( auto i = 0; i < a.size(); ++i )
	{
		if ( a[ i ] == b[ i ] )
		{
			result.push_back( a[ i ] );
		}
	}
	return result;
}

int main( int argc, char **argv )
{
	try
	{
		if ( argc < 2 ) throw std::runtime_error( "please supply input file" );

		std::vector< std::tuple< std::string, std::string > > diff;
		std::string buf;
		const auto filename = argv[ 1 ];
		for ( std::ifstream input( filename ); std::getline( input, buf ); )
		{
			diff.push_back( { buf, {} } );
		}

		for ( int a = 0; a < diff.size() - 1; ++a )
		{
			auto &word = diff[ a ];
			for ( int b = a + 1; b < diff.size(); ++b )
			{
				auto d = difference( std::get< 0 >( word ), std::get< 0 >( diff[ b ] ) );
				if ( d.size() > std::get< 1 >( word ).size() )
				{
					std::get< 1 >( word ) = d;
				}
			}
		}

		std::sort( diff.begin(), diff.end(), []( auto &a, auto &b ) { return std::get< 1 >( a ).size() > std::get< 1 >( b ).size(); } );

		std::cout << std::get< 1 >( diff.front() ) << std::endl;
	}
	catch( const std::exception &err )
	{
		std::cerr << err.what() << std::endl;
		return 1;
	}
	return 0;
}
