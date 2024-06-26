#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

int main()
{
	int *array; //указатель на массив, расположенный в разделяемой памяти
	int shmid; //идентификатор области разделенной памятЫи
	int new = 1; //признак необходимости создания нового массива
	char pathname[] = "forftok.ipc"; //файл, необходимый для генерации ключа ipc
	key_t key; //переменная для хранения ключа
	//попытка генерации ключа
	if ((key = ftok(pathname, 0)) < 0)
	{
		printf("Не удалось сгенерировать ipc-ключ\n");
		exit(-1);
	}
	//попытка создания области  разделяемой памяти
	if((shmid = shmget(key, 3*sizeof(int), 0666|IPC_CREAT|IPC_EXCL)) < 0)
	{
		//проверяет, что ошибка при создании области разделяемой памяти не связана с тем, что область уже существует
		if(errno != EEXIST)
		{
			printf("Не удается создать область разделяемой памяти\n");
			exit(-1);
		}
		//получение идентификатора области раздляемой памяти, если область уже существует
		else
		{
			if((shmid = shmget(key, 3*sizeof(int), 0)) <0)
			{
				printf("Не удается найти область разделяемой памяти\n");
				exit(-1);
			}
			new = 0; //установка признака уже существующей области разделяемой памяти
		}
	}
	//влючение разделяемой памяти в адресное пространство текущего процесса
	if((array = (int *)shmat(shmid, NULL,0)) == (int *)(-1))
	{
		printf("Не удалось добавить разделяемую память в адресное пространство процесса\n");
		exit(-1);
	}
	//операции над вновь созданным массивом
	if(new)
	{
		array[0] = 1;
		array[1] = 0;
		array[2] = 1;
	}
	else
	//операции над уже существующим массивом
	{
		array[0] += 1;
		array[2] += 1;

	}
	printf("Программа 1 была запущена %d раз(а), программа 2 -  %d раз(а), всего -  %d\n", array[0], array[1], array[2]);
	//исключение области разделяемой памяти из адресного пространства текущего процесса
	if(shmdt(array) < 0)
	{
		printf("Не удается исключить разделяемую память из адресного пространства процесса\n");
		exit(-1);
	}
	return 0;
}


