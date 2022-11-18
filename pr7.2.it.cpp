#include <iostream>
#include <iomanip>
#include <time.h>
using namespace std;
void Create(int** a, const int n, const int l, const int Low, const int High);
void Print(int** a, const int n, const int l);
void CalcMax(int** a, const int n, const int l, int& max, int& sum);
int main()
{
	srand((unsigned)time(NULL));
	int Low = -23;
	int High = 26;
	int n, l;
	cout << "k = "; cin >> l;
	cout << "n = "; cin >> n;	
	int** a = new int* [n];
	for (int i = 0; i < n; i++)
	a[i] = new int[n];
	Create(a, n, l, Low, High);
	Print(a, n, l);
	int max;
	int sum = 0;
	CalcMax(a, n, l, max, sum);	
	cout << "Sum of max = " << sum;
		for (int i = 0; i < n; i++)
			delete[] a[i];
	delete[] a;
	return 0;
}

void Create(int** a, const int n, const int l, const int Low, const int High)
{
	for (int i = 0; i < l; i++)
		for (int j = 0; j < n; j++)
			a[i][j] = Low + rand() % (High - Low + 1);
}

void Print(int** a, const int n, const int l)
{
	cout << endl;
	for (int i = 0; i < l; i++)
	{
		for (int j = 0; j < n; j++)
			cout << setw(4) << a[i][j];
		cout << endl;
	}
	cout << endl;
}

void CalcMax(int** a, const int n, const int l, int& max, int& sum)
{
	for (int i = 0; i < n; i += 2) {
		max = a[0][i];
		for (int j = 0; j < l; j++) {
			if (a[j][i] > max)
				max = a[j][i];
		}
		sum += max;
	}
}