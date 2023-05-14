bool utenteExiste(int numero) {
    if(primeiro_utente == NULL)
        return false;

    atual_utente = primeiro_utente;

    do {
        if(atual_utente->codigo == numero)
            return true;

        atual_utente = atual_utente->proximo;

        if(atual_utente->codigo == numero)
            return true;
    } while(atual_utente->proximo != NULL);

    return false;
}

void registarUtente() {
    FILE *fp;
    int utente, medico;

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

    printf("Esse utente nao existe. \nPor favor, registe-o: \n\n");
    printf("Codigo de utente: ");
    scanf("%d", &utente);

    while(utenteExiste(utente)) {
        printf("\nEsse utente ja existe. Por favor, re-insira um codigo nao existente: ");
        scanf("%d", &utente);
    }

    novo_utente->codigo = utente;
    
    printf("Numero de medico de familia: ");
    scanf("%d", &medico);

    while(!medicoExiste(medico)) {
        printf("Esse medico nao existe! Por favor, insira o numero do seu medico.\n\n");
        printf("Numero de medico de familia: ");
        scanf("%d", &medico);
    }

    novo_utente->medicoFamilia = medico;

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

    system("pause");
}

void editarUtente() {
    system("cls");
    int utente, opcao, novo_codigo;
    bool existe = true;
    
    if(primeiro_utente == NULL) {
        printf("Nao existem utentes.\n");
        system("pause");
        return;
    }

    printf("Por favor, insira o numero de utente a editar: ");
    scanf("%d", &utente);

    atual_utente = primeiro_utente;
    while (atual_utente != NULL) {
        if(atual_utente->codigo == utente) {
            printf("Codigo: %d, Medico nr: %d\n\n", atual_utente->codigo, atual_utente->medicoFamilia);
            do {
                printf("O que deseja fazer?\n [1] Editar numero do medico\n\n > ");
                scanf("%d", &opcao);
            } while(opcao < 1 && opcao > 2);

            switch(opcao) {
                case 1:
                    existe = true;
                    do {
                        if(!existe) {
                            printf("Esse medico nao existe! Por favor, insira um medico existente.\n\n");
                        }    
                        printf("Qual o numero do medico? ");
                        scanf("%d", &novo_codigo);
                        existe = false;
                        existe = medicoExiste(novo_codigo);
                    } while(!existe);
                    atual_utente->medicoFamilia = novo_codigo;
                    printf("Codigo do medico de familia alterado com sucesso!\n");
                    system("pause");
                    break;

                case 2:
                    break;
            }
        }
        atual_utente = atual_utente->proximo;
    }
}

void consultarUtentes() {
    system("cls");
    int utente, opcao, novo_codigo;
    bool existe = true;

    if(primeiro_utente == NULL) {
        printf("Nao existem utentes.\n");
        system("pause");
        return;
    }

    printf("Por favor, insira o numero de utente a consultar: ");
    scanf("%d", &utente);

    while(!utenteExiste(utente)) {
        printf("Esse utente nao existe!\nPor favor, insira o numero de utente a consultar: ");
        scanf("%d", &utente);
    }

    atual_utente = primeiro_utente;
    while (atual_utente != NULL) {
        if(atual_utente->codigo == utente) {
            printf("Codigo: %d, NR do medico: %d\n\n", atual_utente->codigo, atual_utente->medicoFamilia);
        }

        atual_utente = atual_utente->proximo;
    }

    system("pause");
}

void removerUtente() {
    system("cls");
    int utente;

    if(primeiro_utente == NULL) {
        printf("Nao existem utentes.\n");
        system("pause");
        return;
    }

    atual_utente = primeiro_utente;
    while (atual_utente != NULL) {
        printf("Codigo: %d, Medico nr: %d\n", atual_utente->codigo, atual_utente->medicoFamilia);
        atual_utente = atual_utente->proximo;
    }

    printf("\n\nQual utente deseja remover? ");
    scanf("%d", &utente);

    while(!utenteExiste(utente)) {
        printf("\n\nEsse utente nao existe. Qual utente deseja remover? ");
        scanf("%d", &utente);
    }

    atual_utente = primeiro_utente;
    anterior_utente = NULL;
    
    while (atual_utente != NULL && atual_utente->codigo != utente) {
        anterior_utente = atual_utente;
        atual_utente = atual_utente->proximo;
    }

    if (atual_utente == NULL) {
        printf("O utente nao foi encontrado.\n");
        return;
    }

    if (anterior_utente == NULL) {
        primeiro_utente = atual_utente->proximo;
    } else {
        anterior_utente->proximo = atual_utente->proximo;
    }

    FILE *f_utentes, *tempFile;

    if (!(f_utentes = fopen("database/utentes.txt", "r")) || !(tempFile = fopen("database/utentes_temp.txt", "w")))
    {
        printf("Erro ao abrir ficheiro dos utentes. A sair..\n");
        fclose(f_utentes);
        fclose(tempFile);
        exit(1);
    }
    
    char linha[100];
    int i = 0;
    bool existe;

    while (!feof(f_utentes)) {
        int utenteCodigo, utenteMedico;

        fscanf(f_utentes, "%d,%d", &utenteCodigo, &utenteMedico);

        if (utenteCodigo == utente) {
            existe = true;
            continue; 
        }

        fprintf(tempFile, "%s%d,%d", (i == 0) ? "" : "\n", utenteCodigo, utenteMedico);

        i++;
    }

    fclose(f_utentes);
    fclose(tempFile);

    remove("database/utentes.txt");
    rename("database/utentes_temp.txt", "database/utentes.txt");

    free(atual_utente);

    system("pause");
}

void listarUtentes() {
    system("cls");
    
    if(primeiro_utente == NULL) {
        printf("Nao existem utentes.\n");
        system("pause");
        return;
    }

    atual_utente = primeiro_utente;
    while (atual_utente != NULL) {
        printf("Codigo: %d, Medico nr: %d\n\n", atual_utente->codigo, atual_utente->medicoFamilia);
        atual_utente = atual_utente->proximo;
    }

    system("pause");
}