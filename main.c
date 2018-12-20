#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <stdlib.h>

void attrs(int procc, FILE *file)
{
    char *name;
    switch (procc)
    {

        case 0:
            name = "Предок";
            break;
        case 1:
            name = "Потомок1";
            break;
        case 2:
            name = "Потомок2";
            break;
        default:
            printf("ошибка вывода атрибутов");
            return;

    }
    fprintf(file, "%s %s %d %s %d\n",name, " идентификатор процесса: ", getpid(), "Процесс № ", procc);
    fprintf(file, "%s %s %d %s %d\n",name, " идентификатор группы процессов: ", getpgid(getpid()), "Процесс № ", procc);
    fprintf(file, "%s %s %d %s %d\n",name, " идентификатор сеанса процесса: ", getsid(getpid()), "Процесс № ", procc);
    fprintf(file, "%s %s %d %s %d\n",name, " идентификатор предка: ", getppid(), "Процесс № ", procc);

}

int main(int argc, char * argv[]) {

    FILE *f = fopen(argv[1], "a");
    sleep(atoi(argv[2]));
    attrs(2, f);
    fclose(f);
    printf("Внутри процесса 2\n");
    return 0;
}