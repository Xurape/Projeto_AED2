int utentes = 0, medicos = 0;

bool dadosImportados = false;

typedef struct utentes {
  int codigo, medicoFamilia;
  struct utentes *proximo;
} Utentes;

typedef struct filaEspera {
  int *utentes, tam;
} FilaEspera;

typedef struct medicos {
  int codigo;
  char nome[75];
  struct medicos *proximo;
  FilaEspera *fila;
} Medicos;

Medicos *primeiro_medico = NULL, *atual_medico, *novo_medico;
Utentes *primeiro_utente = NULL, *atual_utente, *novo_utente;