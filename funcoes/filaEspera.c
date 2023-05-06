void filaAdicionar(int medico, int codigoUtente) {    
    Medicos *temp = (Medicos *) calloc(1, sizeof(Medicos));

    atual_medico = primeiro_medico;

    do {
        if(atual_medico->codigo == medico)
            temp = atual_medico;

        atual_medico->proximo;
    } while(atual_medico->proximo != NULL);

    temp->fila->utentes[temp->fila->tam] = codigoUtente;

    temp->fila->tam++;
}

// void removerUtente(Medicos *medico) {
//     if (medico->fila.inicio == NULL) {
//         // A fila está vazia
//         printf("A fila de espera do médico está vazia.\n");
//         return;
//     }

//     Utentes *utenteRemovido = medico->fila.inicio;
//     medico->fila.inicio = medico->fila.inicio->proximo;
//     free(utenteRemovido);

//     if (medico->fila.inicio == NULL) {
//         // A fila ficou vazia, atualiza o ponteiro do fim da fila
//         medico->fila.fim = NULL;
//     }
// }

// void listarUtentes(Medico *medico) {
//     if (medico->fila.inicio == NULL) {
//         printf("A fila de espera do médico está vazia.\n");
//         return;
//     }

//     Utente *atual = medico->fila.inicio;
//     while (atual != NULL) {
//         printf("Código: %d, Nome: %s\n", atual->codigo, atual->nome);
//         atual = atual->proximo;
//     }
// }