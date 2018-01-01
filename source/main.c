#include <stdio.h>
#include <stdio.h>
#include <time.h>
#include <conio.h>
#define MAX 2000

char* timeget(void)
{
	time_t t = time(NULL);
	struct tm *nPtr = localtime(&t);
	static char now[30];
	strftime(now, 30, "%Y%m%d ", nPtr);
	return now;
}

void read(void)
{
	FILE *diary;
	char str[MAX], name[10],ch;
	int i = 0;
	printf("==================================================================\n");
	printf("=                                                                =\n");
	printf("=                請輸入想回顧之日記日期(西元年月日)              =\n");
	printf("=                                                                =\n");
	printf("==================================================================\n");
	printf("========>");
	scanf("%s", name);
	diary = fopen(name, "r");
	if (diary == NULL)
	{
		printf("====================此天無日記記錄，請重新選擇==================== \n");
		read();
	}
	else
	{
		printf("=====================\n");
		printf("=  時間 : %s =\n", name);
		printf("=====================\n\n");
		printf("==>>以下為日記內容<<== \n\n");
		while ((ch = getc(diary)) != EOF)
		{
			printf("%c", ch);
			i++;
			if (i % 50 == 0)printf("\n");
		}
		fclose(diary);
		printf("\n------------------------------日記結束------------------------------\n");

	}

}

void write(void)
{
	FILE *diary;
	char content[MAX];
	printf("=====================\n");
	printf("=  時間 : %s =\n", timeget());
	printf("=====================\n");
	printf("==>>日記內容<<== \n");
	printf("======>");
	diary = fopen(timeget(), "a");
	scanf("%s", content);
	fprintf(diary, "%s\n", content);
	fclose(diary);
	printf("\n------------------------------日記結束------------------------------\n");
}
int main(void)
{
	int function;
	do{
		printf("==================================================================\n");
		printf("=                                                                =\n");
		printf("=                           寫日記軟體                           =\n");
		printf("=  寫日記請輸入[1]                            回顧日記請輸入[2]  =\n");
		printf("==================================================================\n");
		printf("========>");
		scanf("%d", &function);
	} while (function != 1 && function != 2);
	switch (function)
	{
	case 1:
		write();
		break;
	case 2:
		read();
		break;
	default :
		break;
	}
	system("pause");
	return 0;
}
