
#include <iostream>
#include <string>

// Explore: 
// 	- pragma once
// 	- internal linkage and external linkage
// 		- every .cpp file (called `source` file) creates an object file (.o file)
// 			- objects contain symbols definitions
// 		- when linker encounters an undefined symbol in one object file (say a.o), it searches the definition in
// 		  other objects file AND shared library AND static library.. and wherever it finds it, it links!
// 		- all the symbols in an object file do NOT have same visibility.
// 			- some symbols are visible outside the object file (these are said to have `external` linkage)
// 			- other are not; they're internal to the object file (these are said to have `internal` linkage)
// 		- explore also `nm` command line
//

static std::string const Ones[] = {"Zero","One","Two","Three","Four","Five","Six","Seven","Eight","Nine"};
static std::string const Tens[] = {"Eleven","Twelve","Thirteen","Forteen","Fifteen","Sixteen","Seventeen","Eighteen","Nineteen"};
static std::string const specialTens[] = {"Twenty","Thirty","Forty","Fifty","Sixty","Seventy","Eighty","Ninety"};

static void print99999(int);
static void primitiveClassify(int);
static void print99(int);
static void print999(int);
static void printLakh(int);
static void printCrore(int);
static void printArab(int);

void printWords(int number) {
	printArab(number);
}

void primitiveClassify(int number)
{
    assert(number < 20);
    if (number<10)
    {
       std::cout << Ones[number];
    }
    else if (number>10)
    {
        number-=11;
        std::cout << Tens[number];
    }
    else
    {
        std::cout<<" Ten ";
    }
}

void print99(int number)
{
    assert(number<100);
    
    if(number < 20)
    {
       primitiveClassify(number);
    }
    else
	{
		int tens = number / 10;
		int ones = number % 10;

		std::cout<<specialTens[tens-2];

		if (number!=0)
		{
			std::cout <<Ones[ones];
		}
	}
}

void print999(int number)
{
	assert(number<1000);

	if (number < 20)
	{
		primitiveClassify(number);
	}
	else if(number > 19 and number <100)
	{
		print99(number);
	}
	else
	{
		int hundreds= number/100;
		int rest= number%100;
		
		std::cout<< Ones[hundreds];
		std::cout<< " Hundred ";
		
		if (rest)
		{
			printWords(rest);
		}
	}		

} 

void print99999(int number)
{	
	assert(number <100000 );

	if (number<1000)
	{
		print999(number);
	}
	else
	{
		int thousands = number / 1000;
		int rest = number %1000;

		printWords(thousands);
		std::cout<<" Thousand ";

		if(rest)
		{
			printWords(rest);
		}
	}
}
void printLakh(int number)
{
     if (number<100000)
     {
        print99999(number);
     }
     else
     {
        int lakhs = number/100000;
        int rest = number%100000;
        
        printWords(lakhs);
        std::cout << " Lakh " ;

        if (rest)
        {
            printWords(rest);
        }
     }
}
        
void printCrore(int number)
{
     if (number<10000000)
     {
        printLakh(number);

     }
     else
     {
        int crores = number/10000000;
        int rest = number%10000000;

        printWords(crores);
        std::cout<<" Crore ";

        if (rest)
        {
            printWords(rest);
        }
     }
}

void printArab(int number)
{
     if(number<1000000000)
     {
         printCrore(number);

     }
     else
     {
        int arabs  = number / 1000000000;
        int rest = number  % 1000000000;
        
        printWords(arabs);
        std::cout << " Arabs ";

        if(rest)
        {
           printWords(rest);
        }
     }
}

