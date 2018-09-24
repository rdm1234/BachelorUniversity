// Рождественский, задание 1_4
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

void fill(int **, int, int);
void fill(int **arr, int n, int m) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) arr[i][j] = rand() % 10;
	}
}

void print(int **, int, int);
void print(int **arr, int n, int m) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) cout << arr[i][j] << "\t";
		cout << endl;
	}
}

void move_right(int **, int, int);
void move_right(int **arr, int n, int m) {
	int a;
	for (int i = 0; i < n; i++) {
		a = arr[i][m-1];
		for (int j = m-1; j > 0; j--) {
			arr[i][j] = arr[i][j-1];
		}
		arr[i][0] = a;
	}
}

int main() {
	setlocale(LC_ALL, "ru");
	srand(time(0));

	int **arr, n, m;
	cout << "Введите размерность матрицы" << endl;
	cin >> n >> m;
	arr = new int*[n];
	for (int i = 0; i < n; i++) arr[i] = new int[m];
	fill(arr, n, m);
	print(arr, n, m);
	move_right(arr, n, m);
	cout << "После преобразования:" << endl;
	print(arr, n, m);

	for (int i = 0; i < n; i++) delete[]arr[i];
	delete[]arr;
	system("pause");
	return 0;
}
