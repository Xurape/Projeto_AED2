bool medicoExiste(int numero) {
    if(primeiro_medico == NULL)
        return false;

    atual_medico = primeiro_medico;

    do {
        if(atual_medico->codigo == numero)
            return true;

        atual_medico->proximo;
    } while(atual_medico->proximo != NULL);

    return false;
}