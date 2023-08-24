
void ordenar_pilha(Pilha *p){
    Pilha *p1, *p2;

    if (p != NULL)
    {
        p1 = criar_pilha();
        p2 = criar_pilha();

        while (!pilha_vazia(p))
        {
            if ((obter_topo(p) <= obter_topo(p1)) || pilha_vazia(p1))
                empilhar(p1, desempilhar(p));
            else
            {
                while ((!pilha_vazia(p1)) && (obter_topo(p1) > obter_topo(p)))
                    empilhar(p2, desempilhar(p1));

                empilhar(p1, desempilhar(p));

                while (!pilha_vazia(p2))
                    empilhar(p1, desempilhar(p2));
            }  
        }
        liberar_pilha(p);

        p = p1;

        liberar_pilha(p)2;
        
    }
}