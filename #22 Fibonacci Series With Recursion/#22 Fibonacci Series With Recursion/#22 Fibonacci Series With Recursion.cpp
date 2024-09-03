#include <iostream>
#include <vector>
using namespace std;

// fib(10)
// 1 + 1 + 2 + 3 + 5 + 8 + 13 + 21 + 34 + 55

void PrintFibonacciUsingRecursion(short Number, short Prev1, short Prev2)
{
	int FibNumber = 0;

	if (Number > 0)
	{
		FibNumber = Prev1 + Prev2;
		Prev2 = Prev1;
		Prev1 = FibNumber;
		cout << FibNumber << "   ";
		PrintFibonacciUsingRecursion(Number - 1, Prev1, Prev2);
	}
}

int main()
{
	PrintFibonacciUsingRecursion(10,0,1);

	system("pause>0");
}