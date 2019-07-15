
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

bool thirdCase(float x, float y)
{
	return x < y;
}

bool secondCase(float x, float y, float sx, float sy)
{
	return (x == y) ? thirdCase(sx,sy) : x < y;
}

bool firstCase(float x, float y, float sx, float sy, float tx, float ty)
{
	return (x == y) ? secondCase(sx, sy, tx, ty) : x < y;
}

void sortrows(std::vector<std::vector<float>>& matrix, vector<short> &columns) {
	int i = columns.size() - 1;
	std::sort(matrix.begin(),
		matrix.end(),
		[columns, i](const std::vector<float>& lhs, const std::vector<float>& rhs) {
		short f = columns[2], s = columns[1], t = columns[0];
		switch (i)
		{
		case 2:
			return firstCase(lhs[f], rhs[f], lhs[s], rhs[s], lhs[t], rhs[t]);
			break;
		case 1:
			return secondCase(lhs[s], rhs[s], lhs[t], rhs[t]);
			break;
		case 0:
			return thirdCase(lhs[t], rhs[t]);
			break;

		}

	});
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	vector<short> columnsV;
	vector<vector<float>> matrix;
	short n;
	cin >> n;
	short m;
	cin >> m;
	for (size_t i = 0; i < m; ++i)
	{
		short num;
		cin >> num;
		columnsV.push_back(num - 1);
	}
	int counter = 0;
	float number;
	vector<float> row;
	while (cin >> number)
	{
		row.push_back(number);
		counter++;
		if (counter % n == 0)
		{
			matrix.push_back(row);
			row.clear();
			counter = 0;
		}
	}

	sortrows(matrix, columnsV);

	for (size_t i = 0; i < matrix.size(); ++i)
	{
		for (size_t j = 0; j < n; ++j)
		{
			cout << matrix[i][j] << " ";
		}
		cout << "\n";
	}
	return 0;
}