// Ordenamiento rapido (quick sort): O(n log n) en promedio, O(n^2) en el peor caso.
// Particion de Lomuto con el ultimo elemento como pivote.
#include <iostream>
#include <utility>
#include <vector>
using namespace std;

// Deja el pivote en su posicion final y devuelve ese indice.
int particion(vector<int>& v, int izq, int der) {
    int pivote = v[der];
    int i = izq - 1;  // ultimo elemento de la zona de menores
    for (int j = izq; j < der; ++j) {
        if (v[j] < pivote) {
            ++i;
            swap(v[i], v[j]);
        }
    }
    swap(v[i + 1], v[der]);
    return i + 1;
}

void quickSort(vector<int>& v, int izq, int der) {
    if (izq >= der) return;
    int corte = particion(v, izq, der);
    quickSort(v, izq, corte - 1);
    quickSort(v, corte + 1, der);
}

void quickSort(vector<int>& v) {
    quickSort(v, 0, static_cast<int>(v.size()) - 1);
}

int main() {
    vector<int> v = {10, 7, 8, 9, 1, 5};
    quickSort(v);
    for (int x : v) cout << x << ' ';
    cout << '\n';
}
