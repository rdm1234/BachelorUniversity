// Рождественский, задание 1_3
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

// c_ij = sum(a_in*b_nj)

void multiply(int **, int, int, int **, int, int);
void multiply(int **matrix_1, int n_1, int m_1, int **matrix_2, int n_2, int m_2) {
	int a;
	if (m_1 == n_2) {
		for (int i = 0; i < n_1; i++) {
			for (int j = 0; j < m_2; j++) {
				a = 0;
				for (int n = 0; n < m_1; n++) a += matrix_1[i][n] * matrix_2[n][j];
				cout << a << "\t";
			}
			cout << endl;
		}
	}
	else cout << "Число столбцов первой матрицы не равно числу строк второй" << endl;
}

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

int main() {
	setlocale(LC_ALL, "ru");
	srand(time(0));

	int n_1, m_1, n_2, m_2, n_3, m_3;
	int **matrix_1, **matrix_2, **matrix_3;
	cout << "Введите размерность матрицы 1" << endl;
	cin >> n_1 >> m_1;
	cout << "Введите размерность матрицы 2" << endl;
	cin >> n_2 >> m_2;
	cout << "Введите размерность матрицы 3" << endl;
	cin >> n_3 >> m_3;
	matrix_1 = new int *[n_1];
	for (int i = 0; i < n_1; i++) matrix_1[i] = new int[m_1];
	matrix_2 = new int *[n_2];
	for (int i = 0; i < n_2; i++) matrix_2[i] = new int[m_2];
	matrix_3 = new int *[n_3];
	for (int i = 0; i < n_3; i++) matrix_3[i] = new int[m_3];
	fill(matrix_1, n_1, m_1);
	fill(matrix_2, n_2, m_2);
	fill(matrix_3, n_3, m_3);
	cout << "Матрица 1:" << endl;
	print(matrix_1, n_1, m_1);
	cout << "Матрица 2:" << endl;
	print(matrix_2, n_2, m_2);
	cout << "Матрица 3:" << endl;
	print(matrix_3, n_3, m_3);

	cout << "Матрица 1 * Матрица 2" << endl;
	multiply(matrix_1, n_1, m_1, matrix_2, n_2, m_2);
	cout << endl << "Матрица 2 * Матрица 3" << endl;
	multiply(matrix_2, n_2, m_2, matrix_3, n_3, m_3);

	system("pause");
	return 0;
}
