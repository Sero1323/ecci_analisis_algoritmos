// Ordenamiento por conteo (counting sort): O(n + k), con k el valor maximo. Estable.
// Requiere enteros no negativos.
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

void countingSort(vector<int>& v) {
    if (v.empty()) return;

    int k = *max_element(v.begin(), v.end());
    vector<int> conteo(k + 1, 0);
    for (int x : v) ++conteo[x];

    // Suma acumulada: conteo[x] es la posicion donde termina x en la salida.
    for (int x = 1; x <= k; ++x) conteo[x] += conteo[x - 1];

    // Se recorre de atras hacia adelante para conservar la estabilidad.
    vector<int> salida(v.size());
    for (int i = static_cast<int>(v.size()) - 1; i >= 0; --i) {
        salida[--conteo[v[i]]] = v[i];
    }
    v = salida;
}

int main() {
    vector<int> v = {2, 5, 3, 0, 2, 3, 0, 3};
    countingSort(v);
    for (int x : v) cout << x << ' ';
    cout << '\n';
}
