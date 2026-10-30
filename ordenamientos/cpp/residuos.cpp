// Ordenamiento por residuos (radix sort): O(d * (n + b)), con d digitos en base b = 10.
// Requiere enteros no negativos.
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

// Ordena de forma estable segun el digito de valor posicional exp.
void ordenarPorDigito(vector<int>& v, long long exp) {
    vector<int> conteo(10, 0);
    for (int x : v) ++conteo[(x / exp) % 10];
    for (int d = 1; d < 10; ++d) conteo[d] += conteo[d - 1];

    vector<int> salida(v.size());
    for (int i = static_cast<int>(v.size()) - 1; i >= 0; --i) {
        salida[--conteo[(v[i] / exp) % 10]] = v[i];
    }
    v = salida;
}

void radixSort(vector<int>& v) {
    if (v.empty()) return;

    int mayor = *max_element(v.begin(), v.end());
    // long long: con valores cercanos a INT_MAX, exp no cabe en un int.
    for (long long exp = 1; mayor / exp > 0; exp *= 10) {
        ordenarPorDigito(v, exp);
    }
}

int main() {
    vector<int> v = {170, 45, 75, 90, 802, 24, 2, 66};
    radixSort(v);
    for (int x : v) cout << x << ' ';
    cout << '\n';
}
