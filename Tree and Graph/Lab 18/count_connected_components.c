#include <stdio.h>
#include <stdlib.h>

#define MAX 1000

int graph[MAX][MAX];
int visited[MAX];
int weights[MAX];
int n;

void dfs(int node) {
    visited[node] = 1;
    for (int i = 0; i < n; i++) {
        if (!visited[i] && graph[node][i]) {
            dfs(i);
        }
    }
}

int main() {
    int T;
    scanf("%d", &T);

    while (T--) {
        scanf("%d", &n);

        for (int i = 0; i < n; i++) {
            scanf("%d", &weights[i]);
        }

        // Clear the graph
        for (int i = 0; i < n; i++) {
            visited[i] = 0;
            for (int j = 0; j < n; j++) {
                graph[i][j] = 0;
            }
        }

        // Build the graph using the condition
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if ((j - i) != (weights[j] - weights[i])) {
                    graph[i][j] = 1;
                    graph[j][i] = 1;
                }
            }
        }

        // Count connected components using DFS
        int components = 0;
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                dfs(i);
                components++;
            }
        }

        printf("%d\n", components);
    }

    return 0;
}
