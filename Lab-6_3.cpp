#include <stdio.h>
#include "default_cfg.h"
#include "check_int.h"

int max, max_i = -1;
int max_k = 0;

void scan_massiv(int a[], int size); // просить користувача заповнити масив.
void printf_massiv(int a[], int size); // виводить масив, і виділяє знайдені елементи червоним кольором
void maximum(int a[], int size); // знаходить максивальне число, його індекс, та кількість таких чисел
void printf_result(); // виводить результат обчислеть (відповідь на завдання)

int main(void) {
	start_cfg();

	printf("\r\nВведіть розмір масиву:\n");
	int size = scanf_check_int("Розмір", 1); // просить користувача ввести розмір масива, цілим числом строго більше нуля
	int	a[size]; // масив "а"

	scan_massiv(a, size);
	maximum(a, size);

	printf_massiv(a, size);

	printf_result();
	
	end_cfg();
	return 0;
}


void scan_massiv(int a[], int size)
{
	printf("\n");
	for (int i = 0; i < size; i++)
	{
		a[i] = scanf_check_int("a", 0, 1, i); // елемент масиву може бути лише числом цілого типу, інакше виводить помилку, що користувач ступив
	}
}

void printf_massiv(int a[], int size)
{
	printf("\r\n\nВведений масив:\r\n");

	for (int i = 0; i < size; i++)
	{
		if (a[i] == max && max_i != -1) // якщо це максимальне число - виділяє його червоним кольором
		{
			SetColor(12,0);
			printf("\r\na[%d] = %d", i , a[i]);
			SetColor(10,0);
		} else printf("\r\na[%d] = %d", i , a[i]); // інакше просто виводить рядок масива на екран
	}
	printf("\r\n");
}

void maximum(int a[], int size)
{
	max = a[0]; // для початку обчислень максимальним числом виступає перший елемент масиву
		for (int i = 0; i < size; i++)
		{
			if (a[i]%2 != 0 && a[i] >= max) // якщо число непарше і більше або дорівнює максимальному
			{
				max = a[i]; // стає максимальним
				max_i = i; // його індекс
			}
		}
		
		for (int i = 0; i < size; i++)
		{
			if (a[i] == max)
			{
				max_k++; // кількість максимальних чисел у масиві
			}
		}
}

void printf_result()
{
	if (max_i == -1)
	{
		SetColor_RED(0, 0, "\r\nУ масиві тільки парні елементи\n");
	}
		else if (max_k == 1)
		{
			printf("\r\n\nНайбільший непарний елемент одновимірного масиву: a[%d] = ", max_i);
			SetColor_RED(1, max, 0, 1);
		}
			else
			{
				printf("\r\n\nЗнайдено найбільших непарних елементів одновимірного масиву: %d, із значенням: ", max_k);
				SetColor_RED(1, max, 0, 1);
			}
}