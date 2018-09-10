
#include <string>

std::string const Ones[] = {"Zero","One","Two","Three","Four","Five","Six","Seven","Eight","Nine"};

std::string const Tens[] = {"Eleven","Twelve","Thirteen","Forteen","Fifteen","Sixteen","Seventeen","Eighteen","Nineteen"};

std::string const specialTens[] = {"Twenty","Thirty","Forty","Fifty","Sixty","Seventy","Eighty","Ninety"};

void print99999(int);
void primitiveClassify(int);
void print99(int);
void print999(int);
void printLakh(int);
void printCrore(int);
void printArab(int);

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
        std::cout<<"Ten";
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
        std::cout << " lakh " ;

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

