#include <iostream>

using namespace std;


class stack
{
private:
	int n;      // rozmiar tablicy
	int sptr;   // wskaźnik stosu
	int * S;    // tablica dynamiczna

public:
	stack(int x); // konstruktor
	~stack();     // destruktor
	bool empty(void);
	void  top(void);
	void push(int v);
	void pop(void);
};

stack::stack(int x)
{
	n = x;
	S = new int[x];
	sptr = 0;
}

stack::~stack()
{
  delete [] S;
}

bool stack::empty(void)
{
	return !sptr;
}

void stack::top(void)
{
	if (sptr) cout<< S[sptr - 1]<<endl;

}

void stack::push(int v)
{
	if (sptr < n)
	{
		S[sptr++] = v;
		cout << ":)" << endl;
	}
	else cout << ":(" << endl;
}

void stack::pop(void)
{
	if (sptr)
	{
		sptr--;
	}
	else
		cout << ":(" << endl;
}


int main()
{
	stack S(10);
	int x;
	char c;
		while (cin >> c)
		{
			switch (c)
			{
			case '+':
				cin >> x;
				S.push(x);
				break;
			case '-':
				S.top();
				S.pop();
				break;
			}
		}
}
