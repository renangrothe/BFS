//
// IMPLEMENTAÇÃO DE MATRIZ DE ADJACÊNCIA (GRAFO) E BUSCA EM PROFUNDIDADE
// 04/08/2025 - 22:29
// Renan Suana Grothe Garcia

#ifndef GRAFO_H
#define GRAFO_H

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#define MAX_VERTICES 1000
#define INFINITO -1

typedef struct grafo {
    int num_vertices;
    int adj[MAX_VERTICES][MAX_VERTICES];
} Grafo;

static inline void inicializar_grafo(Grafo *g) {
	g->num_vertices = 0;
	memset(g->adj, 0, sizeof(g->adj));
}

static inline int grafo_insere_vertice(Grafo *g) {

	if(g->num_vertices >= MAX_VERTICES)
		return -1;
	int v = g->num_vertices++;
	return v;
}

static inline int grafo_insere_aresta(Grafo *g, int u, int v) {

	if (u < 0 || u >= g->num_vertices || v < 0 || v >= g->num_vertices) {
		return -1;
		perror("vértice não existe");
	}	
	g->adj[u][v]++;
	g->adj[v][u]++;

	return 0;
}

/*
 * Busca em Largura (BFS) a partir do vértice origem
 *
 * Preenche o array dist[] com distâncias, ou INFINITO
 * se não houver caminho.
 */

static inline void grafo_bfs(Grafo *g, int origem, int dist[]) {

	int fila[MAX_VERTICES];
	memset(fila, 0, sizeof(fila));
	
	int inicio = 0, fim = 0;

	// inicializando distâncias
	for (int i = 0; i < g->num_vertices; i++) {
		dist[i] = INFINITO;
	}

	dist[origem] = 0;
	fila[fim++] = origem;

	while (inicio < fim) {
		int u = fila[inicio++];
		for (int v = 0; v < g->num_vertices; ++v){
			if (g->adj[u][v] && dist[v] == INFINITO) {
				dist[v] = dist[u] + 1;
				fila[fim++] = v;
			}
		}
	}
}

#endif // GRAFO_H
