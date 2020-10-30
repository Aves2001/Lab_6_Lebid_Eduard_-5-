#include <stdio.h>
#include "default_cfg.h"
#include "check_int.h"

bool Even(int k); // повертає True, якщо цілий параметр k є парним, і False в протилежному випадку.
void scan_massiv(int a[], int size); // просить користувача заповнити масив.
void printf_massiv(int a[], int size, int k = 0); // виводить масив, і відображає кількість парних чисел.

int main(void) {
	start_cfg();

	int size = 10; // розмір масива
	int	a[size]; // масив "а"

	scan_massiv(a, size);
	printf_massiv(a, size);

	end_cfg();
	return 0;
}


bool Even(int k)
{
	if (k%2 == 0)
	{
		return true; // true - це то саме шо "1"
	} else return false; // false - це то саме шо "0"
}

void scan_massiv(int a[], int size)
{
	printf("\r\nВведіть масив \"a\" розміром %d цілих чисел:\r\n\n", size);

	for (int i = 0; i < size; i++)
	{
		a[i] = scanf_check_int ("a", 0, 1, i); // елемент масиву може бути лише числом цілого типу, інакше виводить помилку, що користувач ступив
	}
}

void printf_massiv(int a[], int size, int k)
{
	printf("\r\n\n\nВведений масив:\r\n");

	for (int i = 0; i < size; i++)
	{
		if (Even(a[i])) // Якщо функція Even повернула true, виводить число червоним кольором.
		{
			printf("\r\na[%d] = ", i);
			SetColor_RED(1, a[i]);
			k++;
		}else printf("\r\na[%d] = %d", i , a[i]); // Інакше виводить число стандартним кольором
	}	
		if (k > 0) // перевіряє чи в масиві взагалі були парні числа чи ні.
		{
			printf("\r\n\nКількість парних чисел серед елементів масиву: ");
			SetColor_RED(1, k, 0, 1); // виводить кількість червоним кольором.
		} else printf("\r\n\nПарних чисел серед елементів масиву немає\n");
		
}