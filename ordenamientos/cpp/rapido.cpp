// Ordenamiento rapido (quick sort): O(n log n) en promedio, O(n^2) en el peor caso,
// que se da con la lista ya ordenada.
// Convencion del curso: el pivote es el mayor entre los primeros dos elementos diferentes.
#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>
using namespace std;

// Devuelve false si todos los elementos son iguales: el rango ya esta ordenado.
bool escogerPivote(const vector<int>& v, int izq, int der, int& pivote) {
    for (int k = izq + 1; k <= der; ++k) {
        if (v[k] != v[izq]) {
            pivote = max(v[izq], v[k]);
            return true;
        }
    }
    return false;
}

// Deja los menores en v[izq..l-1] y los mayores o iguales en v[l..der]. Devuelve l.
// El pivote no queda en su posicion final: queda en el grupo de la derecha.
int particion(vector<int>& v, int izq, int der, int pivote) {
    int l = izq, r = der;
    do {
        swap(v[l], v[r]);
        while (v[l] < pivote) ++l;
        while (v[r] >= pivote) --r;
    } while (l <= r);
    return l;
}

void quickSort(vector<int>& v, int izq, int der) {
    if (izq >= der) return;
    int pivote;
    if (!escogerPivote(v, izq, der, pivote)) return;
    int corte = particion(v, izq, der, pivote);
    quickSort(v, izq, corte - 1);
    quickSort(v, corte, der);  // incluye el corte: el pivote sigue en este grupo
}

void quickSort(vector<int>& v) {
    quickSort(v, 0, static_cast<int>(v.size()) - 1);
}

int main() {
    vector<int> v = {7, 7, 5, 8, 1, 9, 6, 8};
    quickSort(v);
    for (int x : v) cout << x << ' ';
    cout << '\n';
}
