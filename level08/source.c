#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

void log_wrapper(FILE *log_f, char *str, char *file_name)
{
	char log[272];

	strcpy(log, str);
	snprintf(&log[strlen(log)], 254 - strlen(log), file_name);
	log[strcspn(log, "\n")] = 0;
	fprintf(log_f, "LOG: %s\n", log);
	return;
}

int	main(int argc, char **av)
{
	FILE *backup;
	FILE *arg_file;
	char buffer[99];
	int fd;
	char c;

	if (argc != 2)
		printf("Usage: %s file_name\n", av[0]);
	backup = fopen("./backups/.log", "w");
	if (backup == 0)
	{
		printf("ERROR: Failed to open %s\n", "./backups/.log");
		exit(1);
	}
	log_wrapper(backup, "Starting back up: ", av[1]);
	arg_file = fopen(av[1], "r");
	if (arg_file == 0)
	{
		printf("ERROR: Failed to open %s\n", av[1]);
		exit(1);
	}
	strcpy(buffer, "./backups/");
	strncat(buffer, av[1], 99 - (strlen(buffer)) - 1);
	fd = open(buffer, O_CREAT | O_EXCL | O_WRONLY, S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP);
	if (fd == 0)
	{
		printf("ERROR: Failed to open %s%s\n", "./backups/", av[1]);
		exit(1);
	}
	while ((c = fgetc(arg_file)) != EOF)
		write(fd, &c, 1);
	log_wrapper(backup, "Finished back up ", av[1]);
	fclose(arg_file);
	close(fd);
	return (0);
}