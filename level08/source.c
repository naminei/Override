#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

void	log_wrapper(FILE *log_f, char *str, char *file_name)
{
	char	log[264];
	strcpy(log, str);
	snprintf(&log[strlen(log)], 254 - strlen(log), file_name);
	log[strcspn(log, "\n")] = 0;
	fprintf(log_f, "LOG: %s\n", log);
	return ;
}

int	main(int argc, char **av)
{
	char	file_name[110];
	int		fd;
	int		nb;

	if (argc != 2)
		printf("Usage: %s file_name\n", av[0]);

	FILE	*log_f = fopen("./backups/.log", "w");

	if (log_f == 0)
	{
		printf("ERROR: Failed to open %s\n", "./backups/.log");
		exit(1);
	}
	
	log_wrapper(log_f, "Starting back up: ", av[1]);
	FILE	*arg_file = fopen(av[1], "r");

	if (arg_file == 0)
	{
		printf("ERROR: Failed to open %s\n", av[1]);
		exit(1);
	}

	strcpy(file_name, "./backups/");
	strncat(file_name, av[1], 99 - (strlen(file_name)) - 1);
	fd = open(file_name, 193, 432);

	if (fd < 0)
	{
		printf("ERROR: Failed to open %s%s\n", "./backups/", av[1]);
		exit(1);
	}

	while ((nb = fgetc(arg_file)) != EOF)
		write(fd, &nb, 1);

	log_wrapper(log_f, "Finished back up ", av[1]);
	fclose(arg_file);
	close(fd);
	return (0);
}
