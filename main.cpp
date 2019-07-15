
#include <iostream>
#include <unordered_map>

using namespace std;
unordered_map<unsigned long long, unsigned long long> Fib;

unsigned long long fibo(int n)
{
	if (n < 2) return 1;
	if (Fib.find(n) != Fib.end()) return Fib[n];
	Fib[n] = (fibo((n + 1) / 2)*fibo(n / 2) + fibo((n - 1) / 2)*fibo((n - 2) / 2)) % 1000000007;
	return Fib[n];
}


int main()
{
	unsigned long long Ni;
	int tests;
	cin >> tests;
	for (int i = 0; i < tests; ++i) {
		cin >> Ni;
		cout << fibo(Ni-1)<< endl;
	}
	return 0;
}