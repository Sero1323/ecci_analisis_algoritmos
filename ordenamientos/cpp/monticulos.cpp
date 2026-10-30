// Ordenamiento por monticulos (heap sort): O(n log n) siempre, en el mismo arreglo.
#include <iostream>
#include <utility>
#include <vector>
using namespace std;

// Baja v[i] hasta restaurar el monticulo maximal en v[0..n-1].
void bajar(vector<int>& v, int n, int i) {
    int mayor = i;
    int izq = 2 * i + 1;
    int der = 2 * i + 2;

    if (izq < n && v[izq] > v[mayor]) mayor = izq;
    if (der < n && v[der] > v[mayor]) mayor = der;

    if (mayor != i) {
        swap(v[i], v[mayor]);
        bajar(v, n, mayor);
    }
}

void heapSort(vector<int>& v) {
    int n = v.size();
    for (int i = n / 2 - 1; i >= 0; --i) bajar(v, n, i);  // construir el monticulo

    for (int fin = n - 1; fin > 0; --fin) {
        swap(v[0], v[fin]);  // el mayor va al final
        bajar(v, fin, 0);    // el monticulo se achica en uno
    }
}

int main() {
    vector<int> v = {9, 4, 3, 8, 10, 2, 5};
    heapSort(v);
    for (int x : v) cout << x << ' ';
    cout << '\n';
}
