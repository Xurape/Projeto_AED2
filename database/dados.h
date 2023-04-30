int utentes = 0, medicos = 0;

typedef struct {
  int codigo, medicoFamilia;
} Utentes;

typedef struct {
  int codigo, *filaEspera;
  char nome[75];
} Medicos;

typedef struct {
  int medico, *utentes;
} FilaEspera;

Utentes *utente = NULL;
Medicos *medico = NULL;

#include "dados.c"

