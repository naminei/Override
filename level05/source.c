int	main(int argc,char **argv)
{
	int i= 0;
	char str[100];

	fgets( str, 100, stdin);
	while (strlen(str) < i)
	{
		if ( str[i] > 64)
		{
			if (str[i] <= 90)
			{
				lowercase(str[i]);
			}
			i++;
		}
	}
	printf(str);
	exit(0);
}
