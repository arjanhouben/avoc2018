#include <iostream>
#include <sstream>
#include <fstream>
#include <map>

int main( int argc, char **argv )
{
	try
	{
		if ( argc < 2 ) throw std::runtime_error( "please supply input file" );

		std::ifstream input( argv[ 1 ] );

		struct claim_t
		{
			int count;
			std::string id;
		};

		std::map< int, std::map< int, claim_t > > claims;

		std::string tmp_s, id;
		char tmp_c;
		int x,y,w,h;
		std::map< std::string, bool > valid_claims;
		while ( input >> id >> tmp_c >> x >> tmp_c >> y >> tmp_c >> w >> tmp_c >> h )
		{
			for ( int y_coord = y; y_coord < y + h; ++y_coord )
			{
				for ( int x_coord = x; x_coord < x + w; ++x_coord )
				{
					auto &claim = claims[ x_coord ][ y_coord ];
					if ( ++claim.count == 1 )
					{
						claim.id = id;
						auto found_claim = valid_claims.find( id );
						if ( found_claim == valid_claims.end() )
						{
							valid_claims[ id ] = true;
						}
					}
					else
					{
						valid_claims[ claim.id ] = false;
						valid_claims[ id ] = false;
					}
				}
			}
		}

		for ( auto &c : valid_claims )
		{
			if ( c.second )
			{
				std::cout << c.first << std::endl;
				return 0;
			}
		}
	}
	catch( const std::exception &err )
	{
		std::cerr << err.what() << std::endl;
		return 1;
	}
	return 0;
}
