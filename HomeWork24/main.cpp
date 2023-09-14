#include <iostream>
#include <cstdlib>
#include <ctime>


template <typename T>
void print_arr(T arr[], const int length) {
	std::cout << "{ ";
	for (int i = 0; i < length; i++)
		std::cout << arr[i] << ", ";
	std::cout << "\b\b }\n";
}

template <typename T>
void fill_arr(T arr[], const int length, int left, int right) {
	//srand(time(NULL));
	for (int i = 0; i < length; i++)
		arr[i] = rand() % (right - left) + left;
}

template <typename T>
void resize_arr(T*& arr, int& length, int size) {
	if (size <= 0 || length == size)
		return;
	T* tmp = new int[size] {};

	if (size < length) {
		for (int i = 0; i < size; i++)
			tmp[i] = arr[i];
	}
	else {
		for (int i = 0; i < length; i++)
			tmp[i] = arr[i];
	}

	delete[] arr;
	
	arr = tmp;
	length = size;
}



int main() {
	setlocale(LC_ALL, "Russian");
	int n, m;

	// Задача 1. Динамические массивы

	std::cout << "Задача 1.\nВведите размер массива А -> ";
	std::cin >> n;
	std::cout << "Введите размер массива B -> ";
	std::cin >> m;

	int* A = new int[n];
	int* B = new int[m];


	srand(time(NULL));

	std::cout << "Массив А: ";
	fill_arr(A, n, 1, 11);
	print_arr(A, n);

	std::cout << "Массив B: ";
	fill_arr(B, m, 1, 11);
	print_arr(B, m);

	int* C = new int[n + m];


	for (int i = 0; i < n + m; i++)
		if (i < n)
			C[i] = A[i];
		else
			C[i] = B[i - n];

	std::cout << "Массив C: ";
	print_arr(C, n + m);

	delete[] A;
	delete[] B;

	// Задача 2. Изменение размера динамического массива

	int size;
	std::cout << "Задача 2.\nВведите размер массива -> ";
	std::cin >> size;

	int* arr = new int[size];

	fill_arr(arr, size, 0, 10);
	std::cout << "Исходный массив: ";
	print_arr(arr, size);

	int new_size;
	std::cout << "Введите новый размер массива -> ";
	std::cin >> new_size;

	resize_arr(arr, size, new_size);

	std::cout << "Новый массив: ";
	print_arr(arr, size);


	delete[] C;

	delete[] arr;



	return 0;
}