/*
* Рождественский, ИВТ-21
* Для того, чтобы вывести все комбинации факториала надо
* в начале программы ввести 0 и затем число
* Но функции можно использовать для вывода всех комбинаций любых
* других данных (здесь в main() написал только выбор между тем,
* чтобы вводить строки и int числа самому, но можно что угодно добавить)
*/

#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

template <class T> 
void combinations(T *arr, const int size);
template <class T> 
void print_combination(T *arr, int *n_arr, int size);
template <class T>
void comb_cycle(T *arr, int *n_arr, int size, int n);

bool were_before(int *, int, int);

int main() {
	setlocale(LC_ALL, "ru");

	int n, type;
	string *arr_str = nullptr;
	int *arr_int = nullptr;
	cout << "Вывести комбинации n! - 0, или выберите тип данных и введите в массив вручную: 1 - string, 2 - int" << endl;
	cin >> type;
	
	switch (type) {
	case 0:
		cout << "Введите n:" << endl;
		cin >> n;
		arr_int = new int[n];
		for (int i = 0; i < n; i++) arr_int[i] = i + 1;
		combinations(arr_int, n);
		delete[]arr_int;
		break;
	case 1:
		cout << "Введите количество слов:" << endl;
		cin >> n;
		arr_str = new string[n];
		cout << "Введите все слова" << endl;
		for (int i = 0; i < n; i++) {
			cout << "Введите слово " << i + 1 << endl;
			cin >> arr_str[i];
		}
		combinations(arr_str, n);
		delete[]arr_str;
		break;
	case 2:
		cout << "Введите количество чисел:" << endl;
		cin >> n;
		arr_int = new int[n];
		cout << "Введите все цифры" << endl;
		for (int i = 0; i < n; i++) cin >> arr_int[i];
		combinations(arr_int, n);
		delete[]arr_int;
		break;
	default:
		cout << "Введено неверное число" << endl;
	}
	system("pause");
	return 0;
}

/* Основная функция вывода, в ней создаётся массив чисел, который определяет
* последовательность вывода данных из введённого массива, в ней же происходит
* изменение первого элемета комбинации и вызов функции comb_cycle, отвечающей за
* перебор всех остальных элементов комбинации
*/
template <class T>
void combinations(T *arr, const int size) {
	int *nums_arr = new int[size];
	//for (int i = 0; i < size; i++) nums_arr[i] = i;
	for (int i = 0; i < size; i++) {
		nums_arr[0] = i;
		comb_cycle(arr, nums_arr, size, size - 1);
	}

	delete[]nums_arr;
}

// Использую, чтобы изменять все, кроме первого, элементы от 0 до n, исключая
// те элементы, которые присутсвуют в комбинации до данного элемента
template <class T>
void comb_cycle(T *arr, int *n_arr, int size, int n) {
	if (n == 1) {
		for (int i = 0; i < size; i++) {
			if (!were_before(n_arr, i, size - n)) {
				n_arr[size-n] = i;
			}
		}
		print_combination(arr, n_arr, size);
	}
	else {
		for (int i = 0; i < size; i++) {
			if (!were_before(n_arr, i, size-n)) {
				n_arr[size-n] = i;
				comb_cycle(arr, n_arr, size, n - 1);
			}
		}
	}
}

// Проверяет был ли использован элемент до этого места в комбинации (1 - был, 0 - нет)
bool were_before(int *n_arr, int number, int position){
	for (int i = 0; i < position; i++)
		if (n_arr[i] == number)
			return true;
	return false;
}

// Выводит одну комбинацию
template <class T>
void print_combination(T *arr, int *n_arr, int size) {
	static int comb_number = 0;
	int l;
	cout << "Комбинация номер " << ++comb_number << ":" << endl;
	for (int i = 0; i < size; i++) {
		cout << arr[n_arr[i]] << " ";
	}
	cout << endl;
}
