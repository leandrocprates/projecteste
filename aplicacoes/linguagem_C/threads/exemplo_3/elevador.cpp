#include <pthread.h>
#include <semaphore.h>
#include <iostream>
#include <unistd.h>
#include "Thread.h"

using namespace std;

// Classe Andares, com botoes externos compartilhados pelas pessoas e elevador //
class Andares
{
   private:
      int tam_buff;
      pthread_mutex_t mut; //para garantir exclusao mutua dos botoes
      pthread_mutex_t mut2; //para garantir exclusao mutua dos botoes
      pthread_mutex_t entra; //para garantir exclusao mutua dos botoes
      sem_t botao_apertado;
      sem_t porta_aberta;
      sem_t porta_fechada;
      sem_t sai;

   public:
      int botao_externo[5];    //botoes dos 4 andares
      int botao_interno[5];    //botoes

      //Contrutor
      Andares(int n);

      //Destrutor
      ~Andares();

      //Metodos
      void AbrePorta();
      void LigaBotao(int andar);
      void apertaBotaoExterno(int andar);
      void Entra();
      void apertaBotaoInterno(int andar);
      void Sai();
      void FechaPorta();
      void DesligaBotaoExterno(int andar);
      void DesligaBotaoInterno(int andar);
      void Sobe();
      void Desce();
      void Afasta();
};

Andares::Andares(int n)
{
   tam_buff = n;

   //inicializa mutex e semaforos
   pthread_mutex_init(&mut, NULL);
   pthread_mutex_init(&mut2, NULL);
   pthread_mutex_init(&entra, NULL);
   sem_init(&botao_apertado, 0, 1);
   sem_init(&porta_aberta, 0, 2);
   sem_init(&porta_fechada, 0, 1);
   sem_init(&sai, 0, 0);

   //iniciliza botoes apagados
   for (int i=0; i < 5; i++) {
      botao_externo[i] = 0;
      botao_interno[i] = 0;
   }
}
Andares::~Andares()
{
   pthread_mutex_destroy(&mut);
   pthread_mutex_destroy(&mut2);
   pthread_mutex_destroy(&entra);
   sem_destroy(&botao_apertado);
   sem_destroy(&porta_aberta);
   sem_destroy(&porta_fechada);
   sem_destroy(&sai);
}
void Andares::AbrePorta()
{
   sem_wait(&botao_apertado);         //espera alguem apertar botao
   sem_post(&porta_aberta);           //abre porta
}
void Andares::apertaBotaoExterno(int andar)
{
   pthread_mutex_lock(&mut);
   botao_externo[andar] = 1;
   sem_post(&botao_apertado);         //aperta botao externo
   pthread_mutex_unlock(&mut);
}
void Andares::Entra()
{
   sleep(1);                          // aguarda elevador abrir porta
   sem_wait(&porta_aberta);
}
void Andares::apertaBotaoInterno(int andar)
{
   pthread_mutex_lock(&mut2);
   botao_interno[andar] = 1;
   sem_post(&botao_apertado);
   pthread_mutex_unlock(&mut2);
}
void Andares::Sai()
{
   sem_wait(&porta_aberta);           //espera abrir porta
   sem_post(&sai);                    //sai
}
void Andares::Afasta()
{
   sleep(1);
   sem_wait(&sai);
}
void Andares::FechaPorta()
{
   sleep(1);
   sem_post(&porta_fechada);
}
void Andares::Sobe()
{
   sleep(1);                     //aguarda elevador fechar porta
   sem_wait(&porta_fechada);
}
void Andares::Desce()
{
   sleep(1);                     //aguarda elevador fechar porta
   sem_wait(&porta_fechada);
}
void Andares::DesligaBotaoExterno(int andar)
{
   botao_externo[andar] = 0;
}
void Andares::DesligaBotaoInterno(int andar)
{
   botao_interno[andar] = 0;
}

class Elevador : public Runnable
{
   private:
      int tam_buffer;
      int inicio;
      int fim;
      int botao_interno[5];
      int botao_externo[5];
      Andares *andar;
   public:
      int posicao_atual;

      //Contrutor
      Elevador(int usos, Andares *a);

      //Metodos
      void Abre();  //elevador abriu porta em <andar>
      void Fecha(); //elevador fechou porta em <andar>
      void Sobe();  //elevador subiu um andar
      void Desce(); //elevador desceu um andar

      void run();
};

Elevador::Elevador(int usos, Andares *a)
{
   tam_buffer = usos;
   inicio = 0;
   posicao_atual = 0; //terreo
   andar = a;

   // inicializacao das variaveis
   for(int i=0; i < 5; i++) {
      botao_interno[i] = 0;
      botao_externo[i] = 0;
   }
}
void Elevador::Abre()
{
   andar->AbrePorta();
   andar->DesligaBotaoInterno(posicao_atual);
   cout << "apaga externo" << posicao_atual << endl;
   cout << "abre " << posicao_atual << endl;
}
void Elevador::Fecha()
{
   andar->FechaPorta();
   andar->DesligaBotaoExterno(posicao_atual);
   cout << "fecha " << posicao_atual << endl;
}
void Elevador::Sobe()
{
   posicao_atual++;
   andar->Sobe();
   cout << "sobe" << endl;
}
void Elevador::Desce()
{
   posicao_atual--;
   andar->Desce();
   cout << "desce" << endl;
}
void Elevador::run()
{
   for (int n=0; n < tam_buffer; n++) {
      for (int i=0; i < 5; i++) { //sobe
         if (andar->botao_externo[i] == 1 || andar->botao_interno[i] == 1) {
            Abre();
            Fecha();
         }
         Sobe();
      }
      for (int i=4; i >= 0; i--) { //desce
         if (andar->botao_externo[i] == 1 || andar->botao_interno[i] == 1) {
            Abre();
            Fecha();
         }
         Desce();

      }
   }
}

// Classe Pessoa //
class Pessoa : public Runnable
{
   private:
      int posicao_atual;
      int posicao_destino;
      int *destinos;
      int *tempos;
      int usos;
      int id;

   public:
      Andares *andar;
      Elevador *elevador;

      //Contrutor
      Pessoa(int i, Andares *a, Elevador *e, int u, int *des, int *temp);

      //Metodos
      void Aproxima();      // pessoa p<n> se aproximou do elevador em <andar>
      void ApertaExterno(); // pessoa p<n> apertou botao externo em <andar>  // MUTEX
      void Entra();         // pessoa p<n> entrou no elevador em <andar>
      void ApertaInterno(int botao);  // pessoa p<n> apertou botao interno para ir para <andar>
      void Sai();           // pessoa p<n> saiu do elevador em <andar>
      void Afasta();        // pessoa p<n> se afastou do elevador em <andar>

      int getId();

      void run();
};

Pessoa::Pessoa(int i, Andares *a, Elevador *e, int u, int *des, int *temp)
{
   id = i;
   usos = u;
   destinos = des;
   tempos = temp;
   andar = a;
   elevador = e;
   posicao_atual = 0;   //terreo
   posicao_destino = destinos[0];
}
int Pessoa::getId()
{
   return id;
}
void Pessoa::Aproxima()
{
   cout << "aprox p" << getId() << " " << posicao_atual << endl;
}
void Pessoa::ApertaExterno()
{
   andar->apertaBotaoExterno(0);
   cout << "botao p" << getId() << " externo" << posicao_atual << endl;
}
void Pessoa::Entra()
{
   if (elevador->posicao_atual == posicao_atual) { //se o eleveador esta no andar q ele esta
      andar->Entra();
      cout << "entra p" << getId() << " " << posicao_atual << endl;
   }
}
void Pessoa::ApertaInterno(int botao)
{
   posicao_destino = *(destinos);
   andar->apertaBotaoInterno(posicao_destino);
   cout << "botao p" << getId() << " interno " << posicao_destino << endl;
}
void Pessoa::Sai()
{
   if (elevador->posicao_atual == posicao_destino) { //se o elevador esta no andar desejado
      posicao_atual = posicao_destino;
      andar->Sai();
      cout << "sai p" << getId() << " " << posicao_atual << endl;
   }
}
void Pessoa::Afasta()
{
   andar->Afasta();
   cout << "afasta p" << getId() << " " << posicao_atual << endl;
   destinos++;
   posicao_destino = *(destinos);
   int tempo = *(tempos);
   sleep(tempo);
   tempos++;
}
void Pessoa::run()
{
   for (int n=0; n < usos; n++) {
      Aproxima();
      ApertaExterno();
      Entra();
      ApertaInterno(posicao_destino);
      Sai();
      Afasta();
   }
}

int main(int argc, char **argv)
{
   Andares a(5);
   Elevador e(2, &a);

   int destinos[3];
   destinos[0] = 3;
   destinos[1] = 2;
   destinos[2] = 0;

   int tempos[3];
   tempos[0] = 2;
   tempos[1] = 1;
   tempos[2] = 0;
   Pessoa p1(1, &a, &e, 3, destinos, tempos);

   int destinos2[3] = {1, 3, 0};
   int tempos2[3] = {7, 1, 0};

   Pessoa p2(2, &a, &e, 3, destinos2, tempos2);

   Thread t1(p1);
   Thread t2(p2);
   Thread t3(e);

   t1.start();
   t2.start();
   t3.start();

   t1.join();
   t2.join();
   t3.join();

   return 0;
}

