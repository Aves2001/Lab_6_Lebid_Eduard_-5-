#include <math.h>

// char debug = 1;

int scanf_check_int (const char printf_x[], char bil_0 = 0, char lvl = 0, int massiv_i = 0, int massiv_j = 0)
{
#define _SIZES_N 13

char int_max[10] = {'2', '1', '4', '7','4','8','3','6','4','7'};
char int_min[11] = {'-', '2', '1', '4', '7','4','8','3','6','4','8'};


		// for (int i = 0; i < 10; i++)
		// {
		// 	printf("--------------|int_max[%d] = %c\n", i, int_max[i]);
		// }
		// printf("\n\n\n");
		// for (int i = 0; i < 11; i++)
		// {
		// 	printf("--------------|int_min[%d] =  %c\n", i, int_min[i]);
		// }

char error = 0;
char s[_SIZES_N] = "";
int scan_sum = 0;
int minus = 0;
int result = 0;
int k = 0;

do{
error = 0;
scan_sum = 0;
minus = 0;

if (lvl == 0)
{
	printf("%s = ", printf_x);

} else	if (lvl == 1)
		{
			printf("%s[%d] = ", printf_x, massiv_i);

		}else printf("%s[%d][%d] = ", printf_x, massiv_i, massiv_j);


fgets(s, _SIZES_N, stdin);
fflush(stdin);

if (bil_0 == 1 && (s[0] == '0' || s[0] == '-'))
	{
		Error_RED();
		printf("\"%s\" не може дорівнювати, або бути меншим нулю!\r\n\n", printf_x);
		error = 1;
		continue;
	}

if (s[0] == '\n')
{
	Error_RED();
	printf("Введіть хоть щось будьласка\r\n\n");
	error = 1;
	continue;
} else	if (s[0] == '-' && s[1] == '\n')
		{
			Error_RED();
			printf("Просто мінус? Серйозно!?\r\n\n");
			error = 1;
			continue;
		}

for (int i = 0; i < _SIZES_N; i++)
{
	if (s[i] == '.' || s[i] == ',')
	{
		if (lvl == 0)
		{
			Error_RED();
			printf("Ви ввели неправильне значення. \"%s\" Має бути цілим числом\r\n\n", printf_x);
			error = 1;
			break;

		} else	if (lvl == 1)
				{
					Error_RED();
					printf("Ви ввели неправильне значення. \"%s[%d]\" Має бути цілим числом\r\n\n", printf_x, massiv_i);
					error = 1;
					break;
				
				} else	if (lvl == 2)
						{
							Error_RED();
							printf("Ви ввели неправильне значення. %s[%d][%d] Має бути цілим числом\r\n\n", printf_x, massiv_i, massiv_j);
							error = 1;
							break;
						}
	}

	if (s[i] == '-')
	{
		minus++;

	}

	if (s[i] == '\n')
	{
		break;

	} else scan_sum++;
}

// printf("-------|Кількість мінусів = %d |---------\n", minus); //debug
// printf("---------|Кількість введених символів| %d |-------\r\n", scan_sum); //debug

	if (scan_sum > 9)
	{
		if (s[0] == '-')
		{
			for (int i = 1; i < scan_sum; i++)
			{
				if (s[i] > int_min[i])
				{
					Error_RED();
					printf("Програма не розрахована на обчислення таких великих чисел\r\n\n");
					error = 1;
					break;
				}
			}
		} else	for (int i = 0; i < scan_sum; i++)
				{
					if (s[i] > int_max[i])
					{
						Error_RED();
						printf("Програма не розрахована на обчислення таких великих чисел\r\n\n");
						error = 1;
						break;
					}
				}

		if (error == 1)
		{
			continue;
		}
		
	}

if (s[0] == '-')
{
	k = 1;
} else k = 0;

	for (; k < scan_sum; k++)
	{

		if (s[k] == ' ')
		{
			Error_RED();
			printf("Пробіл був лишнім введіть нормально будьласка!\r\n\n");
			error = 1;
			break;
					//45 = -				//від 0 до 9		// не більше 1-го мінуса
		} else  if (s[k] >= 48 && s[k] <= 57)
				{
				// printf("\r\ns[%d] = %d ---| Добре |---\r\n\n", k, s[k]); //debug
				
				} else if (lvl == 0)
						{
							Error_RED();
							printf("Ви ввели неправильне значення \"%s\"\r\n\n", printf_x);
							error = 1;
							break;

						} else	if (lvl == 1)
								{
									// printf("\r\ns[%d] = %d |%c|---| НЕ Добре |---\r\n\n", k, s[k], s[k]); //debug
									Error_RED();
									printf("Ви ввели неправильне значення \"%s[%d]\"\r\n\n", printf_x, massiv_i);
									error = 1;
									break;
								
								} else	if (lvl == 2)
										{
											Error_RED();
											printf("Ви ввели неправильне значення %s[%d][%d]\r\n\n", printf_x, massiv_i, massiv_j);
											error = 1;
											break;
										}
	}


// printf("result %d--------\n", result); //debug
// printf("bil_0 %d--------\n", bil_0); //debug

}while (error == 1);

result = atoi(s);
// printf("\r\n\n"); //debug
// for (int i = 0; i < _SIZES_N; i++) //debug
// { //debug
	// printf("---------| s[%d] = %d [%c]|-------\r\n", i, s[i], s[i]); //debug
// } //debug
// printf("\r\n\n"); //debug

// printf("----|scanf_check_int| result = %d |-----\n", result); //debug

return result;
}
