#include <stdio.h>
#include <unistd.h>

int main(void)
{
    if (daemon(0, 0)) {
        printf("Erro indo para background.\n");
        return 1;
    }

    printf("Esta mensagem nao deve ser impressa.\n");

    sleep(10); // Durma por dez segundos antes de sair

    return 0;
}


