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

// void inserirNaFilaEspera(int utente) {
//     int medico;
//     Medicos *temp = (Medicos *) calloc(1, sizeof(Medicos));

//     if(primeiro_utente == NULL || primeiro_medico == NULL)
//         return;

//     atual_utente = primeiro_utente;
//     atual_medico = primeiro_medico;

//     do {
//         if(atual_utente->codigo == utente)
//             medico = atual_utente->medicoFamilia;

//         atual_utente->proximo;
//     } while(atual_utente->proximo != NULL);

//     do {
//         if(atual_medico->codigo == medico)
//             temp = atual_medico;

//         atual_medico->proximo;
//     } while(atual_medico->proximo != NULL);

//     free(temp);
// }