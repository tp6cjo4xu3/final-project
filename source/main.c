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
	printf("=                �п�J�Q�^�U����O���(�褸�~���)              =\n");
	printf("=                                                                =\n");
	printf("==================================================================\n");
	printf("========>");
	scanf("%s", name);
	diary = fopen(name, "r");
	if (diary == NULL)
	{
		printf("====================���ѵL��O�O���A�Э��s���==================== \n");
		read();
	}
	else
	{
		printf("=====================\n");
		printf("=  �ɶ� : %s =\n", name);
		printf("=====================\n\n");
		printf("==>>�H�U����O���e<<== \n\n");
		while ((ch = getc(diary)) != EOF)
		{
			printf("%c", ch);
			i++;
			if (i % 50 == 0)printf("\n");
		}
		fclose(diary);
		printf("\n------------------------------��O����------------------------------\n");

	}

}

void write(void)
{
	FILE *diary;
	char content[MAX];
	printf("=====================\n");
	printf("=  �ɶ� : %s =\n", timeget());
	printf("=====================\n");
	printf("==>>��O���e<<== \n");
	printf("======>");
	diary = fopen(timeget(), "a");
	scanf("%s", content);
	fprintf(diary, "%s\n", content);
	fclose(diary);
	printf("\n------------------------------��O����------------------------------\n");
}
int main(void)
{
	int function;
	do{
		printf("==================================================================\n");
		printf("=                                                                =\n");
		printf("=                           �g��O�n��                           =\n");
		printf("=  �g��O�п�J[1]                            �^�U��O�п�J[2]  =\n");
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
