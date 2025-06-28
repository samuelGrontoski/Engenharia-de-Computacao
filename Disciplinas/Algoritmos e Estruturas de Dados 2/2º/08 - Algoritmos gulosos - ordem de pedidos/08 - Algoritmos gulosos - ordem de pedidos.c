#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int cliente_id;
    int tempo_entrega;
} Pedido;

int compararPedidos(const void *a, const void *b) {
    Pedido *pedidoA = (Pedido *)a;
    Pedido *pedidoB = (Pedido *)b;

    if (pedidoA->tempo_entrega < pedidoB->tempo_entrega) {
        return -1;
    }
    if (pedidoA->tempo_entrega > pedidoB->tempo_entrega) {
        return 1;
    }

    if (pedidoA->cliente_id < pedidoB->cliente_id) {
        return -1;
    }
    if (pedidoA->cliente_id > pedidoB->cliente_id) {
        return 1;
    }

    return 0;
}

int main() {
    int n;
    scanf("%d", &n);

    Pedido pedidos[n];

    for (int i = 0; i < n; i++) {
        int nro_ordem, tempo_preparo;
        scanf("%d %d", &nro_ordem, &tempo_preparo);
        
        pedidos[i].cliente_id = i + 1;
        pedidos[i].tempo_entrega = nro_ordem + tempo_preparo;
    }

    qsort(pedidos, n, sizeof(Pedido), compararPedidos);

    for (int i = 0; i < n; i++) {
        printf("%d", pedidos[i].cliente_id);
        if (i < n - 1) {
            printf(" ");
        }
    }
    printf("\n");

    return 0;
}