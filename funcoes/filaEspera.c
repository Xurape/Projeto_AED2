void inicializarFilaEspera(FilaEspera *fila) {
  fila->primeiro = fila->ultimo = -1;
  fila->proximo = NULL;
}

int filaVazia(FilaEspera *fila) {
  return fila->primeiro == -1;
}

void adicionarUtente(FilaEspera *fila, int codigoUtente) {
  if (fila->ultimo == 99) { // a fila já está cheia
    printf("A fila de espera está cheia.\n");
    return;
  }
  if (fila->primeiro == -1) { // a fila está vazia
    fila->primeiro = fila->ultimo = 0;
  } else {
    fila->ultimo++;
  }
  fila->codigoUtente[fila->ultimo] = codigoUtente;
}

int removerUtente(FilaEspera *fila) {
  if (filaVazia(fila)) {
    printf("A fila de espera está vazia.\n");
    return -1;
  }
  int codigoUtente = fila->codigoUtente[fila->primeiro];
  if (fila->primeiro == fila->ultimo) { // se houver apenas um elemento na fila
    fila->primeiro = fila->ultimo = -1;
  } else {
    fila->primeiro++;
  }
  return codigoUtente;
}