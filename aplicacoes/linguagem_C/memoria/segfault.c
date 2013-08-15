 #include <stdlib.h>
 int main(void)
 {
   char *p = NULL;   /* p é um apontador do tipo char que aponta agora para NULL */
   *p = 'x';         /* Tenta gravar o caracter 'x' no endereço 0 (o endereco apontado por NULL) */
   return 0;
 }

