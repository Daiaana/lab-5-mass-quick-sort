#include <stdio.h>  //положительные по убыванию, нули, отрицательные по возрастанию
#include <conio.h>
#include <math.h>
#include <locale>
#define SIZE 100

void input(double *mass, int N);
void output(double *mass, int N);
void sortQuickIncrease(double* mass, int N);
void qsIncrease(double* mass, int first, int last);
void sortQuickDecrease(double* mass, int N);
void qsDecrease(double* mass, int first, int last);
void swap(double *u, double *v);
int negativeCounter(double* mass, int N);

int main()
{
	setlocale(LC_ALL, "RUS");
	int n, negative;
	double massiv[SIZE] = { 1 };
	printf_s("введите n\n");
	scanf_s("%d", &n);
	if (n <= 0 || n > SIZE) {
		printf("Некорректные данные");
	}
	else {
		input(massiv, n);
		output(massiv, n);
		sortQuickDecrease(massiv, n);
		negative = negativeCounter(massiv, n);
		sortQuickIncrease(massiv + n - negative, negative);
		output(massiv, n);
	}
	_getch();
	return 0;
}

void input(double *mass, int N)
{
	printf_s("введите элементы массива\n");
	for (int i = 0; i < N; i++) {
		printf_s("элемент с индексом %d = ", i);
		scanf_s("%lf", mass + i);
	}
}

void output(double *mass, int N)
{
	printf_s("массив:\n");
	for (int i = 0; i < N; i++) {
		printf_s("%.2lf ", *(mass + i));
	}
	printf_s("\n");
}

void sortQuickIncrease(double *mass, int N) //быстрая, по возрастанию
{
	qsIncrease(mass, 0, N - 1);
}

void qsIncrease(double *mass, int first, int last) 
{
	int i = first, j = last, x = *(mass + (first + last) / 2);
	do {
		while (*(mass + i) < x) {
			i++;
		}
		while (*(mass + j) > x) {
			j--;
		}
		if (i <= j) {
			if (*(mass + i) > *(mass + j)) {
				swap(mass + i, mass + j);
			}
			i++;
			j--;
		}
	} while (i <= j);
	if (i < last)
		qsIncrease(mass, i, last);
	if (first < j)
		qsIncrease(mass, first, j);
}

void sortQuickDecrease(double* mass, int N) //быстрая, по убыванию
{
	qsDecrease(mass, 0, N - 1);
}

void qsDecrease(double* mass, int first, int last) 
{
	int i = first, j = last, x = *(mass + (first + last) / 2);
	do {
		while (*(mass + i) > x) {
			i++;
		}
		while (*(mass + j) < x) {
			j--;
		}
		if (i <= j) {
			if (*(mass + i) < *(mass + j)) {
				swap(mass + i, mass + j);
			}
			i++;
			j--;
		}
	} while (i <= j);
	if (i < last)
		qsDecrease(mass, i, last);
	if (first < j)
		qsDecrease(mass, first, j);
}

void swap(double *u, double *v)
{
	int tmp = *u;
	*u = *v;
	*v = tmp;
}

int negativeCounter(double *mass, int N)
{
	int counter = 0;
	for (int i = 0; i < N; i++) {
		if (*(mass + i) < 0) {
			counter++;
		}
	}
	return counter;
}