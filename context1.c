#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char *argv[], char *envp[])
{
	int result;
	result = execle("/bin/cat", "/bin/cat", "otchet_16_04.txt", 0, envp);
	printf("Ошибка при выполнениее сстемного вызова execle()\n");
	exit(-1);
	return 0;
}

