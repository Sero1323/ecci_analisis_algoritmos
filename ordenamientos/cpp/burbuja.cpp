// Ordenamiento burbuja: O(n^2) en promedio y peor caso, O(n) si ya esta ordenado.
#include <iostream>
#include <utility>
#include <vector>
using namespace std;

void bubbleSort(vector<int>& v) {
    int n = v.size();
    for (int i = 0; i < n - 1; ++i) {
        bool hubo_cambio = false;
        for (int j = 0; j < n - 1 - i; ++j) {
            if (v[j] > v[j + 1]) {
                swap(v[j], v[j + 1]);
                hubo_cambio = true;
            }
        }
        if (!hubo_cambio) break;  // pasada sin cambios: ya esta ordenado
    }
}

int main() {
    vector<int> v = {64, 34, 25, 12, 22, 11, 90};
    bubbleSort(v);
    for (int x : v) cout << x << ' ';
    cout << '\n';
}
