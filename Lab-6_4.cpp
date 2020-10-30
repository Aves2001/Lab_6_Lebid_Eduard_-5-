#include <stdio.h>
#include "default_cfg.h"
#include "check_int.h"
#include <time.h>

#define _N 3 // Кількість рядків
#define _M 4 // Кількість стовпців

const int n = _N, m = _M;
int Low = -100, High = 100;

void scan_massiv(int n, int m, int a[][_M]);
void printf_massiv(int n, int m, int a[][_M]);
void sort_massiv(int n, int m, int a[][_M]);

int main(void) {
	start_cfg();
	
	int a[n][m];

	scan_massiv(_N, _M, a);

	printf("\r\nМасив:\n\n");
	printf_massiv(_N, _M, a);

	sort_massiv(_N, _M, a);

	printf("\r\n\n\nМасив відсортований по зростанню значень елементiв рядка:\n\n");
	printf_massiv(_N, _M, a);

	end_cfg();
	return 0;
}



void scan_massiv(int n, int m, int a[][_M])
{
	srand(time(0));
	for (int i = 0; i < n; i++)
	for (int j = 0; j < m; j++)
	{
		a[i][j] = Low+rand()%(High - Low + 1);
	}printf("\r\n");
}

void printf_massiv(int n, int m, int a[][_M])
{
	for (int i = 0; i < n; i++){
		for (int j = 0; j < m; j++)
		{
			printf(" a[%d][%d] = %d\t", i, j, a[i][j]);
		}
	printf("\n");
	}
}

void sort_massiv(int n, int m, int a[][_M])
{
	int tmp;
	for (int k = 0; k < n*m; k++)
	{
		for (int i = 0; i < n; i++)
		{	
			for (int j = 1; j < m; j++)
			{	
				if (a[i][j] < a[i][j-1])
				{
					tmp = a[i][j];
					a[i][j] = a[i][j-1];
					a[i][j-1] = tmp;
				}
			}
		}
	}
}
