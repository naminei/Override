*a_user_name;

int verify_user_name(void)
{
    puts("verifying username....\n");
    return (strcmp(a_user_name, "dat_wil"));
}

int verify_user_pass(char *passwd)
{
    return (strcmp(passwd, "admin"));
}

int main(void)
{
    char passwd[16];
    int ret;

    memset(passwd, 0, 16)
    puts("********* ADMIN LOGIN PROMPT *********");
    printf("Enter Username: ");
    fgets(a_user_name, 256, stdin);
    ret = verify_user_name();
    if (ret != 0)
    {
        puts("nope, incorrect username...\n");
        return 1;
    }
    puts("Enter password: ");
    fgets(passwd, 100, stdin);
    ret = verify_user_pass(passwd);
    if (ret == 0)
    {
        puts("nope, incorrect password...\n");
        return 1;
    }
    return 0;
}
