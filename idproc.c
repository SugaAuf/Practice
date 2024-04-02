#include <sys/types.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
int main()
{
	pid_t getpid;
//системный вызов возвращающий идентификатор текущего процесса
	pid_t getppid;
//системный вызов возвращающий идентификатор процесса-родителя
	currproc = getpid();
	fathproc = getppid();
	printf("Идентификатор текущего процесса: %d\n", currproc);
	printf("Идентификатор родительского процесса: %d\n", fathproc);
	return 0;
}
