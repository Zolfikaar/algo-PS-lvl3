#include <iostream>
#include <vector>
using namespace std;

// fib(10)
// 1 + 1 + 2 + 3 + 5 + 8 + 13 + 21 + 34 + 55

void PrintFibonacciUsingLoop(short Number)
{
	int FibNumber = 0;

	int Prev1 = 1, Prev2 = 0;
	cout << "1   ";

	for (short i = 2; i <= Number; ++i)
	{
		FibNumber = Prev1 + Prev2;
		cout << FibNumber << "   ";
		Prev2 = Prev1;
		Prev1 = FibNumber;
	}
}

int main()
{
	PrintFibonacciUsingLoop(10);

	system("pause>0");
}