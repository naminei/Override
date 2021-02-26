struct message
{
	char username[40];
	char message[140];
	int message_len;
}

void	secret_backdoor()
{
	char	string[128];

	fgets(string, 128, stdin);
	system(string);
	return;
}

void	set_msg(struct message *msg)
{
	char	str[1024];

	bzero(str, 128 * 8);
	puts("Message @Unix-Dude");
	printf(">>: ");
	fgets(str, 1024, stdin);
	strncpy(msg->message, str, msg->message_len);
	return;
}


void	set_username(struct message *msg)
{
	char	str[128];

	bzero(str, 128);
	puts(">: Enter your username");
	printf( ">>: ");
	fgets(str, 128, stdin);

	for (int i = 0; i <= 40 && str[i]; i++)
            msg->username[i] = str[i];
	printf(">: Welcome, %s", msg->username);
	return;
}

void	handle_msg(void)
{
	struct message user_struct;

    bzero(user_struct->username, 40);
	user_struct->message_len = 140;

	set_username(&user_struct);
	set_msg(&user_struct);
	puts(">: Msg sent!");
	return;
}


int     main(int argc, char **argv, char **envp)
{
    welcome_text = "--------------------------------------------\n|   ~Welcome to l33t-m$n ~    v1337        |\n--------------------------------------------";

    puts(welcome_text);
    handle_msg();
    return (0);
}
