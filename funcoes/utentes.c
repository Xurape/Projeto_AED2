bool utenteExiste(int numero) {
    if(primeiro_utente == NULL)
        return false;

    atual_utente = primeiro_utente;

    do {
        if(atual_utente->codigo == numero)
            return true;

        atual_utente->proximo;
    } while(atual_utente->proximo != NULL);

    return false;
}

void registarUtente() {
    FILE *fp;

    system("cls");

    novo_utente = (Utentes *)calloc(1, sizeof(Utentes));

    if (!(fp = fopen("database/utentes.txt", "a")))
    {
        printf("Erro ao abrir ficheiro dos utentes. A sair..\n");
        exit(1);
    }

    if (novo_utente == NULL)
    {
      printf("Alocação de memória sem sucesso...\n");
      exit(1);
    }

    novo_utente->codigo = utentes + 1;

    printf("Codigo de utente atribuido: %d\n", utentes + 1);
    printf("Por favor, complete os seguintes dados.. \n\n");
    printf("Numero de medico de familia: ");
    scanf("%d", &novo_utente->medicoFamilia);

    while(novo_utente->medicoFamilia > medicos) {
        printf("Esse medico nao existe! Por favor, insira o numero do seu medico.\n\n");
        printf("Numero de medico de familia: ");
        scanf("%d", &novo_utente->medicoFamilia);
    }

    if (primeiro_utente == NULL) {
      primeiro_utente = novo_utente;
    } else {
      atual_utente = primeiro_utente;

      while (atual_utente->proximo != NULL) {
        atual_utente = atual_utente->proximo;
      }

      atual_utente->proximo = novo_utente;
    }
  
    fprintf(fp, "\n%d,%d", novo_utente->codigo,novo_utente->medicoFamilia);
    fclose(fp);
    utentes++;

    system("cls");

    printf("Utente registado com sucesso.. A retomar..\n");
}

void listarUtentes() {
    system("cls");

    atual_utente = primeiro_utente;
    while (atual_utente != NULL) {
        printf("Codigo: %d, Medico nr: %d\n\n", atual_utente->codigo, atual_utente->medicoFamilia);
        atual_utente = atual_utente->proximo;
    }

    system("pause");
}