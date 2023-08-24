
void inverter_fila(Fila *f)
{
    Pilha *p;

    if (f != NULL)
    {
        p = criar_pilha();

        while (!fila_vazia(f))
            empilhar(p, desenfileirar(f));
        
        while (!pilha_vazia(p))
            enfileirar(f, desempilhar(p));

            liberar_pilha(p);
    }
}