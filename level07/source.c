int	read_number(tab_number)
{
	index = 0;

	printf(" Index: ");
	index = get_unum();

	printf(" Number at data[%u] is %u\n", index, tab_number[index * 4]);
	return 0;
}

int32_t	get_unum()
{
	int32_t	number;

	fflush(stdout);
	scanf("%u", &number);
	clear_stdin();

	return number;
}

int	store_number(tab_number)
{
	number = 0;
	index = 0;

	printf(" Number: ");
	number = get_unum();

	printf(" Index: ");
	index = get_unum();

	if (ch % 3 == 0 || index >> 24 == 183) 
	{
		puts(" *** ERROR! ***");
		puts("   This index is reserved for wil!");
		puts(" *** ERROR! ***");
		return 1;
	}

	tab_number[index * 4] = number;

	return 0;
}

int	main(char **argv, char **envp)
{

	1b4h = 0;
	1b8h = 0;
	1bch = 0;
	1c0h = 0;
	1c4h = 0;
	1c8h = 0;
	tab_number[100] = {};

	while (**argv)
	      memset(*argv, 0, strlen(*argv++));
	while (**envp)
              memset(*envp, 0, strlen(*envp++));
	puts("----------------------------------------------------\n  Welcome to wil's crappy number storage service!   \n----------------------------------------------------\n Commands:                                          \n    store - store a number into the data storage    \n    read  - read a number from the data storage     \n    quit  - exit the program                        \n----------------------------------------------------\n   wil has reserved some storage :>                 \n----------------------------------------------------\n");

	while (1)
	{
		printf("Input command: ");
		fgets(1b8h, 20, stdin);
		1b8h[strlen(1b8h) - 1] = 0;


		if (!strncmp("store", 1b8h, 5))
		   1b4h = store_number(tab_number);
		else if (!strncmp("read", 1b8h, 4))
		   1b4h = read_number(tab_number);
		else if (!strncmp("quit", 1b8h, 4))
		   return 0;
		else
		   1b4h = 1;

		if (!1b4h)
		   printf(" Completed %s command successfully\n", 1b8h);
		else
		   printf(" Failed to do %s command\n", 1b8h);

		1b8h = 0;
		1bch = 0;
		1c0h = 0;
		1c4h = 0;
		1c8h = 0;
	}
	return 0;
}
