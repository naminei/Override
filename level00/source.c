int main(void) {

    int passwd;

    puts("***********************************");
    puts("*            -Level00-            *");
    puts("***********************************");
    printf("Password:");
    scanf("%d", passwd);
    if (passwd == 5276)
    {
        puts("\nAuthenticated!");
        system("/bin/sh");
    }
    else
    {
        puts("\nInvalid Password!");
    }
    return 0;
}
