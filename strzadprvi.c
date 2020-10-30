
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct {
	char ime[20];
	char prez[20];
	int bod;
}STUDENT;


int main()
{
	FILE* fp = NULL;
	char str[20], ch;
	STUDENT* stu;
	int i, n = 0, max = 0;

	printf("upisi ime datoteke: ");
	scanf(" %s", str);

	fp = fopen(str, "r");
	if (fp == NULL)
	{
		printf("Greska pri otvaranju datoteke!");
	}

	while (!feof(fp))
	{
		ch = fgetc(fp);
		if (ch == '\n') ++n;
	}

	stu = (STUDENT*)malloc(n * sizeof(STUDENT));

	rewind(fp);

	for (i = 0; i < n; i++)
	{
		fscanf(fp, " %s %s %d", stu[i].ime, stu[i].prez, &stu[i].bod);
		if (stu[i].bod > max)
			max = stu[i].bod;

	}

	printf("IME\t PREZIME\t APSOLUTNO\t RELATIVNO\n\n");
	for (i = 0; i < n; i++)
	{
		printf("%s    %s    %d    %.2f\n", stu[i].ime, stu[i].prez, stu[i].bod, (float)stu[i].bod / max * 100);
	}
	return 0;
}