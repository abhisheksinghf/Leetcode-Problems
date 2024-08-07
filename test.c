#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_NODES 100005

int A[MAX_NODES];           // Values written on each node
int P[MAX_NODES];           // Parent node references
int parent[MAX_NODES];      // Parent array used in union-find
int rank[MAX_NODES];        // Rank array for union-find
bool visited[MAX_NODES];    // Visited array to track visited nodes
int freq[MAX_NODES];        // Frequency array for checking distinct values

// Find function for union-find with path compression
int find(int x) {
    if (parent[x] != x) {
        parent[x] = find(parent[x]);
    }
    return parent[x];
}

// Union function for union-find by rank
void unionSets(int x, int y) {
    int rootX = find(x);
    int rootY = find(y);
    
    if (rootX != rootY) {
        if (rank[rootX] > rank[rootY]) {
            parent[rootY] = rootX;
        } else if (rank[rootX] < rank[rootY]) {
            parent[rootX] = rootY;
        } else {
            parent[rootY] = rootX;
            rank[rootX]++;
        }
    }
}

int main() {
    int n, i, j, rootI, goodEdges;
    bool distinct;
    
    scanf("%d", &n);
    
    // Initialize union-find arrays
    for (i = 0; i < n; i++) {
        parent[i] = i;
        rank[i] = 0;
        visited[i] = false;
    }
    
    // Input the values of A array
    for (i = 0; i < n; i++) {
        scanf("%d", &A[i]);
    }
    
    // Input the parent array P
    for (i = 0; i < n; i++) {
        scanf("%d", &P[i]);
        if (P[i] != 0) {
            unionSets(i, P[i] - 1);
        }
    }
    
    goodEdges = 0;
    
    // Count good edges
    for (i = 0; i < n; i++) {
        rootI = find(i);
        if (!visited[rootI]) {
            distinct = true;
            
            // Reset frequency array
            for (j = 0; j < MAX_NODES; j++) {
                freq[j] = 0;
            }
            
            // Check if all values in this component are distinct
            for (j = 0; j < n; j++) {
                if (find(j) == rootI) {
                    if (freq[A[j]] > 0) {
                        distinct = false;
                        break;
                    }
                    freq[A[j]]++;
                }
            }
            
            if (distinct) {
                for (j = 0; j < n; j++) {
                    if (P[j] != 0 && find(j) == rootI) {
                        goodEdges++;
                    }
                }
            }
            visited[rootI] = true;
        }
    }
    
    printf("%d\n", goodEdges);
    
    return 0;
}
