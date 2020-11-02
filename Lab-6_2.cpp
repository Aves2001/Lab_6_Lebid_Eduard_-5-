#include <stdio.h>
#include "default_cfg.h"
#include "check_int.h"
#include <time.h>

int Low = -100, High = 100; // діапазон в якому генеруються випадкові числа

void scan_massiv(int a[], int size); // заповнення масива за допомогою rand() в діапазоні (Low, High)
void printf_massiv(int a[], int size); // виводить згенерований масив на екран
void dobutock(int a[], int size, long long int resut_dobutock = 1); // обчислює добуток всіх чисел масиву відмінних від нуля
void summ_abs(int a[], int size); // обчислює суму модулів елементів масиву розташованих після першого відємного числа, та виводить результат на екран

int main(void) {
	start_cfg();

	printf("\r\nВведіть розмір масиву:\n");
	int size = scanf_check_int("Розмір", 1); // просить користувача ввести розмір масива, цілим числом строго більше нуля
	int	a[size]; // масив "а"

	scan_massiv(a, size);
	printf_massiv(a, size);

	dobutock(a, size);
	summ_abs(a, size);

	end_cfg();
	return 0;
}


void scan_massiv(int a[], int size)
{
	srand(time(0)); // для генерації нових чисел кожного разу при запуску програми
	
	for (int i = 0; i < size; i++)
	{
		a[i] = Low+rand()%(High - Low + 1); // заповнення масива випадковими числами в діапазоні від Low до High
	}
}

void printf_massiv(int a[], int size)
{
	printf("\r\n\nВведений масив:\r\n");

	for (int i = 0; i < size; i++)
	{
		printf("\r\na[%d] = %d", i , a[i]);
	}
	printf("\r\n");
}

void dobutock(int a[], int size, long long int resut_dobutock)
{
	for (int i = 0; i < size; i++)
	{
		if (a[i] != 0) // якщо число не допівнює нулю
		{
			resut_dobutock *= a[i]; // тоді домножити його до resut_dobutock, першого разу виконується множення на одиницю
		}
	}
		if (resut_dobutock == 0) // така собі перевірка, але вроді працює
		{
			SetColor_RED(0, 0, "\r\n 1) Щось пішло не так, програма споробувала порахувати добуток, \n    але трішки не витримала");
			return;
		} 
			else 
			{
				printf("\r\n 1) добуток ненульових елементів масиву: ");
				SetColor(14,0); // жовтий текст
				printf("%lld \n", resut_dobutock);
				SetColor(10,0); // зелений текст
				return;
			}
}

void summ_abs(int a[], int size)
{
	unsigned int summ = 0;
	int k = 0;

	for (int i = 0; i < size; i++)
	{
		if (a[i] < 0)
		{
			k = i+1; // зберігання індекса елемента, який знаходиться після першого відємного числа
			break;
		}
	}

		if (k == 0)
		{
			printf("\r\n 2) У масиві немає відємних чисел.\n");
		}
			else if (k == size)
			{
				printf("\r\n 2) У масиві тільки одне відємне число, і воно останнє.\n");
			}
				else
				{
					for (int i = k; i < size; i++)
					{
						summ += abs(a[i]);
					}
					printf("\r\n 2) Сума модулів елементів масиву,\n    розташованих після першого \n    від’ємного елемента = ");
					SetColor(14,0); // жовтий текст
					printf("%d\r\n\n    %d", summ, summ);
					SetColor(10,0); // зелений текст
					printf(" результат обчислення діапазона: a[%d] -- a[%d]", k, --size);
				}
}