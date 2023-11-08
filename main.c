#include <stdio.h>
#include <time.h>
#define max 5

void particao(int *v, int esq, int dir, int *i, int *j) {
  *i = esq;
  *j = dir;
  int pivo, aux;
  int mediana;
  int meio = (esq + 1 + dir) / 2;
  if (v[esq] > v[meio] && v[esq] < v[dir]) {
    mediana = esq + 1;
  } else {
    if (v[meio] > v[dir] && v[meio] < v[dir]) {
      mediana = meio;
    } else {
      mediana = dir;
    }
  } // mediana
  // pivo = v[(esq + dir) / 2]; //meio
  pivo = mediana + 1; // mediana
  // pivo = esq + 1; // inicio

  while (*i <= *j) {
    while (v[*i] < pivo && *i < dir) {
      (*i)++;
    }
    while (v[*j] > pivo && *j > esq) {
      (*j)--;
    }
    if (*i <= *j) {
      aux = v[*i];
      v[*i] = v[*j];
      v[*j] = aux;
      (*i)++;
      (*j)--;
    }
  }
}

void quickSort(int *v, int esq, int dir) {
  int i, j;
  particao(v, esq, dir, &i, &j);
  if (i < dir) {
    quickSort(v, i, dir);
  }
  if (j > esq) {
    quickSort(v, esq, j);
  }
}

void imprimeVetor(int *v) {
  for (int i = 0; i < max; i++) {
    printf("%d ", v[i]);
  }
  printf("\n");
}

int main() {
  int v[5] = {5, 2, 1, 3, 4};
  quickSort(v, 0, max - 1);
  imprimeVetor(v);
  return 0;
}
