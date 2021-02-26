int main(int argc, char **argv) {
	char username[100];
	bzero(&username, 12);

    char tab_48[48];
    bzero(&tab_48, 5);

	char tab_112[112];
    bzero(&tab_112, 12);

	FILE *password_file;
    int size;

	password_file = fopen("/home/users/level03/.pass", "r");

	if (password_file == 0) {
		fwrite("ERROR: failed to open password file\n", 1, 36, stderr);
        exit(1);
	}

	size = fread(tab_48, 1, 41, password_file);
	tab_48[strcspn(tab_48, "\n")] = 0;
    if (size != 41)
	{
        fwrite("ERROR: failed to read password file\n", 1, 36, stderr);
        fwrite("ERROR: failed to read password file\n", 1, 36, stderr);
        exit(1);
	}
    fclose(file)
    puts("===== [ Secure Access System v1.0 ] =====");
    puts("/***************************************\\");
    puts("| You must login to access this system. |");
    puts("\\**************************************/");

    printf("--[ Username: ");
	fgets(username, 100, stdin);
	username[strcspn(username, "\n")] = 0;

	printf("--[ Password: ");
	fgets(tab_112, 100, stdin);
	tab_112[strcspn(tab_112, "\n")] = 0;
    
    puts("*****************************************");

	if (strncmp(tab_48, tab_112, 41) == 0) {
	    printf("Greetings, %s!\n", username);
        system("/bin/sh");
        return (0);
	}
	printf(username);
	puts(" does not have access!");
	exit(1);
}
