
#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#include <iomanip>
using namespace std;

class uczen
{
public:
	int kolejnosc;
	double nne;
	string imie;
	string nazwisko;
	uczen(int kolejnosc, float nne, string imie, string nazwisko);
};

uczen::uczen(int kolejnosc, float nne, string imie, string nazwisko)
{
	this->kolejnosc = kolejnosc;
	this->nne = nne;
	this->imie = imie;
	this->nazwisko = nazwisko;
}

void sortrows(std::vector<uczen>& lista) {
		std::sort(lista.begin(),
			lista.end(),
			[](const uczen& lhs, const uczen& rhs) {

			return lhs.nazwisko == rhs.nazwisko ? (lhs.imie == rhs.imie ? lhs.nne < rhs.nne : lhs.imie < rhs.imie ) : lhs.nazwisko < rhs.nazwisko;
		});
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	vector<uczen> lista;
	int kolejnosc;
	float nne;
	string imie, nazwisko;
	while (cin >> kolejnosc >> nne >> imie >> nazwisko)
	{
		uczen n(kolejnosc, nne, imie, nazwisko);
		lista.push_back(n);
	}
	sortrows(lista);

	for (int i = 0; i < lista.size(); ++i)
	{
		cout << i + 1 << " " << lista[i].nazwisko << " " << lista[i].imie << " "<< lista[i].nne<< " " << lista[i].kolejnosc << "\n";
	}
	return 0;
}