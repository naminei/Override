#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>

void decrypt(int mask){
	char str[17] = "Q}|u`sfg~sf{}|a3"; //Concatenation de 4 string de 4 char chacune
	int len = strlen(str);
	int i = 0;

	while(i < len)
	{
		str[i] = str[i] ^ mask;
		i++;
	}
	if (strncmp(str, "Congratulations!", 17) == 0)
		system("/bin/sh");
	else
		puts("\nInvalid Password");
	return ;
}

void test(int nb1, int nb2)
{
	nb1 = nb2 - nb1;
	if (nb1 <= 21)
		decrypt(nb1);
	else
		decrypt(rand());
	return ;
}

int main(void)
{
	int pass;

	srand(time(0));
	puts("***********************************");
	puts("*\t\tlevel03\t\t**");
	puts("***********************************");
	printf("Password:");
	scanf("%d", &pass);
	test(pass, 322424845);
	return(0);
}