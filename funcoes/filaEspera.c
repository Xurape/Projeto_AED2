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

void imprimirFilaEspera(Medicos *medico)
{
    int i = 0;
    Utentes *utente = medico->fila->inicio;

    printf("Lista de espera do medico: %s\n", medico->nome);
    printf("------------------------------\n");

    while (utente != NULL)
    {
        i++;
        printf("Utente NR %d\n", utente->codigo);
        utente = utente->proximo;
    }

    printf("------------------------------\n       Total em espera: %d\n", i);

    system("pause");
}

void removerUltimoDaFilaEspera(Medicos *medico)
{
    if (medico->fila->inicio == NULL)
    {
        // A fila de espera está vazia
        return;
    }
    else if (medico->fila->inicio == medico->fila->fim)
    {
        // Há apenas um utente na fila de espera
        free(medico->fila->inicio);
        medico->fila->inicio = NULL;
        medico->fila->fim = NULL;
    }
    else
    {
        // Percorrer a fila até o penúltimo elemento
        Utentes *utente = medico->fila->inicio;
        while (utente->proximo != medico->fila->fim)
        {
            utente = utente->proximo;
        }

        // Remover o último utente
        free(medico->fila->fim);
        utente->proximo = NULL;
        medico->fila->fim = utente;
    }
}