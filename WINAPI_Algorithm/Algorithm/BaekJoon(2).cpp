#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int re, di;

int fib(int n)
{
	if (n == 1 || n == 2)
	{
		re++;
		return 1;
	}
	else
		return (fib(n - 1) + fib(n - 2));
}

int fibonacchi(int n)
{
	int* f = new int[n];
	f[0] = 1;
	f[1] = 1;

	for (int i = 2; i < n; i++)
	{
		di++;
		f[i] = f[i - 1] + f[i - 2];
	}

	return f[n - 1];

}

int main()
{
	int num;
	cin >> num;

	fib(num);
	fibonacchi(num);

	cout << re << " " << di;

	return 0;
}