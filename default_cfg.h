#include <windows.h>
// #include <conio.h>

int chcp, chcpOut; // start_cfg  |  end_cfg


void SetColor(int text, int background)
{
   HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
   SetConsoleTextAttribute(hStdOut, (WORD)((background << 4) | text));
}

void SetColor_RED(bool k = 1, int a = 0, const char b[] = "0", int n = 0)
{
	SetColor(12,0); // червоний колір

	if (k)
	{
		printf("%d", a);
	} else printf("%s", b);

	SetColor(10,0); // зелений колір


	if (n > 0)
	{
		for (int i = 0; i < n; i++)
		{
			printf("\r\n");
		}
	}
}

void Error_RED()
{
	SetColor(12,0);
	printf("\r\n\a[Error] ");
	SetColor(10,0);
}

void start_cfg()
{
	system("color 0a"); // встановлює зелений текст і чорний фон

// Збереження значення chcp
	chcp = GetConsoleCP();
	chcpOut = GetConsoleOutputCP();

//------------UTF-8--------------
	SetConsoleCP(65001);
	SetConsoleOutputCP(65001);
//-------------------------------
}

void end_cfg()
{
	// Повернення значення chcp яке було до запуску програми
	SetConsoleCP(chcp);
	SetConsoleOutputCP(chcpOut);
	// getch();
	printf("\r\n\n");
	system("pause");
}