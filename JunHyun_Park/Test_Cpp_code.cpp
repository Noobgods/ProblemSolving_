#include <stdio.h>
 
#define INT_MAX 2147483647
#define TRUE 1
#define FALSE 0
#define MAX_VERTICES 20001
#define INF 1000 
 
int weight[MAX_VERTICES][MAX_VERTICES];
int distance[MAX_VERTICES]; 
int found[MAX_VERTICES];
 
int choose(int distance[], int n, int found[]){
  int i, min, minpos;
  min = INT_MAX;
  minpos = -1;
 
  for (i = 0; i < n; i++) {
    if (distance[i] < min && found[i] == FALSE) {
      min = distance[i];
 
      minpos = i;
    }
  }
  return minpos;
}
 
void shortest_path(int start, int n) {
  int u;
 
  for (int i = 0; i < n; i++){
    distance[i] = weight[start][i];
 
    found[i] = FALSE;
  }

  found[start] = TRUE;
  distance[start] = TRUE;
 
  for (int i = 0; i < n - 1; i++) {
    u = choose(distance, n, found);
    found[u] = TRUE;
 
    for (int w = 0; w < n; w++) {
      if (found[w] == FALSE) {
        if (distance[u] + weight[u][w] < distance[w]) {
          distance[w] = distance[u] + weight[u][w];
        }
      }
    }
  }
}
 
void main(){
    int N;
    scanf("%d", &N);
    shortest_path(0, N);
}