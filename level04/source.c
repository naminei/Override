#include <unistd.h>
#include <signal.h>
#include <sys/wait.h>
#include <string.h>
#include <stdio.h>
#include <sys/prctl.h>

int main()
{
  pid_t proc = fork(); ac
  char buff[32];

  memset(buff, 0, 32)
  int var1 = 0; a8
  int var2 = 0; 1c
  if (proc == 0)
  {
    pcrtl(1, 1);
    ptrace(0, 0, 0, 0);
    puts("Give me some shellcode, k");
    gets(buff);
  }
  else
  {
    while(true)
    {
      wait(var2);
      if ((var2 & 127) == 0)
      {
        puts("child is exiting...");
      }
      else if ((var2 & 127 + 1) / 2 > 0)
      {
        if (ptrace(0, proc, 44, 3) == 11)
        {
          puts("No exec() for you");
          kill(proc);
          break ;
        }
      }
    }
  }
  return 0
}
