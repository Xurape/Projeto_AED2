void adicionarUtente(Medicos *medico, Utentes *utente)
{
    if (medico->fila->inicio == NULL)
    {
        medico->fila->inicio = utente;
        medico->fila->fim = utente;
    }
    else
    {
        medico->fila->fim->proximo = utente;
        medico->fila->fim = utente;
    }
}

void imprimirFilaEspera(Medicos *medico) {
  Utentes *utente = medico->fila->inicio;

  printf("Lista de espera do medico: %s\n", medico->nome);
  printf("------------------------------\n");

  while (utente != NULL) {
    printf("Utente NR %d\n", utente->codigo);
    utente = utente->proximo;
  }
  printf("------------------------------\n");

  system("pause");
}