//------------------------------------------------------------------+
//                                                                  |
// CuentaPar.c:  Cuenta aparaciones de un numero en un arreglo muy  |
//               grande. Version paralela simple                    |
//                           ESQUELETO                              |
//------------------------------------------------------------------+

#include <assert.h>
#include <sys/time.h>
#include <stdlib.h>
#include <stdio.h>

#include "mpi.h"

#define MAX_ENTERO      1000
#define NUM_VECTORES   10000  // Simula vector todavia mayor
#define NUM_BUSCADO        5

//--------------------------------------------------------------------
void esclavo(void) {


}

//--------------------------------------------------------------------
void maestro (int NumProcesos, int Cardinalidad) {

  int i, totalNumVeces;
  int *vector;
  struct timeval t0, tf, t;

  // Inicializar el vector

  assert((vector =(int *)malloc(sizeof(int)*Cardinalidad))!=NULL);

  for (i=0; i<Cardinalidad; i++)
    vector[i] = random() % MAX_ENTERO;

  assert (gettimeofday (&t0, NULL) == 0);

  // Repartir trabajo

  // Computar mi trozo

  // Recoger resultados

  assert (gettimeofday (&tf, NULL) == 0);

  timersub(&tf, &t0, &t);
  printf ("Numero de veces que aparece el %d = %d\n",
	  NUM_BUSCADO, totalNumVeces);
  printf ("tiempo total = %ld:%3ld\n", t.tv_sec, t.tv_usec/1000);
}

//--------------------------------------------------------------------
int main( int   argc, char *argv[] ) {
  int yo, numProcesos;

  if (argc != 2) {
    printf ("Uso: cuentaPar cardinalidad \n");
    return 0;
  }
  laCardinalidad = atoi(argv[1]);

  assert (laCardinalidad > 0);
  setbuf (stdout, NULL);
  MPI_Init (&argc, &argv);
  MPI_Comm_rank (MPI_COMM_WORLD, &yo);
  MPI_Comm_size (MPI_COMM_WORLD, &numProcesos);
  if (yo == 0) maestro(NumProcesos,laCardinalidad);
  else         esclavo();
  MPI_Finalize();
  return 0;
}