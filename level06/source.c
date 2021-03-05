#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/ptrace.h>

int auth(char *login, unsigned int serial)
{
    int len;
    int hash;
    int i;

    login[strcspn(login, "\n")] = 0;
    len = strnlen(login, 32);
    if (len > 5)
    {
        if (ptrace(0, 0, 1, 0) == -1)
        {
            puts("[32m.---------------------------.");
            puts("[31m| !! TAMPERING DETECTED !!  |");
            puts("[32m'---------------------------'");
            return (1);
        }
        hash = (login[3] ^ 4919) + 6221293;
        i = 0;
        while (i < len)
        {
            if (login[i] <= 31)
                return (1);
            hash += hashing(login[i]);
            i++;
        }
    }
    if (hash != serial)
        return (1);
    return (0);
}

int main(int ac, char **av)
{
    char login[32];
    unsigned int serial;

    puts("***********************************");
    puts("*\t\tlevel06\t\t  *");
    puts("***********************************");
    printf("-> Enter Login: ");
    fgets(login, 32, stdin);
    puts("***********************************");
    puts("***** NEW ACCOUNT DETECTED ********");
    puts("***********************************");
    printf("-> Enter Serial:");
    scanf("%u", &serial);
    if (auth(login, serial) == 0)
    {
        puts("Authenticated!");
        system("/bin/sh");
        return (0);
    }
    return (1);
}
