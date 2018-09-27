// Рождественский, стек структуры
#include <iostream>
#include <cstdlib>

using namespace std;

struct lst {
	int data;
};

void fill_lst(lst *, int);
void fill_lst(lst *arr, int size) {
	for (int i = 0; i < size; i++) arr[i].data = rand() % 100;
}

void print_lst(lst *, int);
void print_lst(lst *arr, int size) {
	for (int i = 0; i < size; i++) cout << arr[i].data << "\t";
	cout << endl;
}

void push(lst *&arr, int &size, int value) {
	lst *newArr = new lst[size + 1];
	for (int i = 0; i < size; i++) newArr[i].data = arr[i].data;
	newArr[size].data = value;

	delete[]arr;
	arr = newArr;
	size++;
}

int pop(lst *&arr, int &size) {
	int c;
	if (size == 1) return -1;
	lst *newArr = new lst[size - 1];
	for (int i = 0; i < size - 1; i++) newArr[i].data = arr[i].data;
	c = arr[size - 1].data;
	delete[]arr;
	arr = newArr;
	size--;
	return c;
}

int main() {
	setlocale(LC_ALL, "ru");
	int size, c;
	string choice;
	cout << "Введите изначальный размер списка" << endl;
	cin >> size;
	lst *arr = new lst[size];
	fill_lst(arr, size);
	
	print_lst(arr, size);
	cout << "pop: " << pop(arr, size) << endl;
	print_lst(arr, size);
	cout << "push 13: " << endl;
	push(arr, size, 13);
	print_lst(arr, size);

	delete[]arr;
	system("pause");
	return 0;
}
