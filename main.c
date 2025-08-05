#include "grafo.h"
#include <stdlib.h>
#include <stdio.h>

int main(void) {

	Grafo g;
	inicializar_grafo(&g);

	int n_vertices = 0;

	scanf("%d", &n_vertices);

	// adicionar vértices ao grafo
	for (int i = 0; i < n_vertices; i++)
		grafo_insere_vertice(&g);

	// le arestas no formato i,j até "0,0"
	int u, v;

	while (scanf("%d,%d", &u, &v) == 2 && (u != 0 || v != 0)) {
		if (u >= 1 && u <= n_vertices && v >= 1 && v <= n_vertices) {
			grafo_insere_aresta(&g, u - 1, v - 1); //indices base 0
		}
	} 

	int origem;
	scanf("%d", &origem);

	if (origem < 1 || origem > n_vertices) {
		fprintf(stderr, "Vértice inicial inválido\n");
		return 1;
	}

	int dist[MAX_VERTICES];
	grafo_bfs(&g, origem - 1, dist);

	printf("Origem da busca %d\n", origem);
	printf("Vértices alcançados e distâncias:\n");

	for (int i = 0; i < g.num_vertices; i++) {
		if (dist[i] != INFINITO)
			printf("%d %d\n", i + 1, dist[i]); //de indice 0 para indice 1
	}

	return 0;
}

