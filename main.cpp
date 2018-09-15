

#include <iostream>

#include "printNum.hpp"

// g++ runs 3 things in sequence
//  1. it runs preprocessor (-E), which expands the preprocessor statements, such as #include, #define etc.
//  2. then it compiles (-c)
//  3. then it links (ld)

int  main()
{
    int number;
    std::cout << "Enter any positive Number Less than 99 Crores : ";
    if ( std::cin >> number ) {
		printWords( number );
		std::cout << std::endl;
    } else {
		//print error
	}

}
