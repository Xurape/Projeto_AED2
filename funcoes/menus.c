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

void menuUtente() {
    int utente;

    system("cls");

    if(primeiro_medico == NULL) {
        printf("Nao existem medicos disponiveis a sair...\n");
        return;
    }

    printf("Por favor, insira o código de utente: ");
    scanf("%d", &utente);

    if(!utenteExiste(utente))
        registarUtente();

    inserirNaFilaEspera(utente);

    system("pause");
}

void menuMedico() {
    system("cls");
}

void menuAdministrar() {
    system("cls");

    int opcao, gerirUtentes, gerirMedicos;

    while(opcao != 0) {
        system("cls");
        printf("\n\n");
        printf("\t   O que deseja fazer?\n");
        printf(" [1] Gerir utentes\n");
        printf(" [2] Gerir medicos\n");
        printf(" [0] Voltar atras\n\nOpcao > ");
        scanf("%d", &opcao);
        switch(opcao) {
            case 1:
                    while(gerirUtentes != 0) {
                        system("cls");
                        printf("\n\n");
                        printf("\t   O que deseja fazer?\n");
                        printf(" [1] Inserir utente\n");
                        printf(" [2] Editar utente\n");
                        printf(" [3] Consultar utentes\n");
                        printf(" [4] Remover utente\n");
                        printf(" [5] Listar utentes\n");
                        printf(" [0] Voltar atras\n\nOpcao > ");
                        scanf("%d", &gerirUtentes);
                        switch(gerirUtentes) {
                            case 1:
                                
                                break;
                        }
                    }
                break;

            case 2:
                menuMedico();
                break;
        }
    }

}

void menuPrincipal() {
    int opcao;

    while(opcao != 0) {
        system("cls");
        printf("\n\n");
        printf("\tBem-vindo ao centro de saude!");
        printf("\n\t   E medico ou utente?\n\n");
        printf(" [1] Utente\n");
        printf(" [2] Medico\n");
        printf(" [3] Administrar\n");
        printf(" [0] Sair\n\nOpcao > ");
        scanf("%d", &opcao);
        switch(opcao) {
            case 1:
                menuUtente();
                break;

            case 2:
                menuMedico();
                break;

            case 3:
                menuAdministrar();
                break;
        }
    }
}