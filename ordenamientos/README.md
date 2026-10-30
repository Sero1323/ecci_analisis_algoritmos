# Algoritmos de ordenamiento

Implementaciones en C++ (`cpp/`) y Python (`python/`) de los algoritmos de ordenamiento
de CI-0116 (temas 18 a 21), basadas en las versiones de
[GeeksforGeeks](https://www.geeksforgeeks.org/).

| Archivo | Algoritmo | Tema | Mejor | Promedio | Peor | Espacio | Estable |
|---|---|---|---|---|---|---|---|
| `burbuja` | Burbuja | 18 | O(n) | O(n²) | O(n²) | O(1) | Sí |
| `seleccion` | Selección | 18 | O(n²) | O(n²) | O(n²) | O(1) | No |
| `insercion` | Inserción | 18 | O(n) | O(n²) | O(n²) | O(1) | Sí |
| `mezcla` | Mezcla (merge sort) | 19 | O(n log n) | O(n log n) | O(n log n) | O(n) | Sí |
| `rapido` | Rápido (quick sort) | 19 | O(n log n) | O(n log n) | O(n²) | O(n) | No |
| `monticulos` | Montículos (heap sort) | 20 | O(n) | O(n log n) | O(n log n) | O(log n) | No |
| `conteo` | Conteo (counting sort) | 21 | O(n + k) | O(n + k) | O(n + k) | O(n + k) | Sí |
| `residuos` | Residuos (radix sort) | 21 | O(d(n + b)) | O(d(n + b)) | O(d(n + b)) | O(n + b) | Sí |

El espacio de rápido y montículos corresponde a la pila de recursión de estas versiones.
Conteo y residuos solo aceptan enteros no negativos. El mejor caso de montículos se da
con todos los elementos iguales.

Dos puntos siguen las convenciones del curso:

- **Rápido:** el pivote es el mayor entre los primeros dos elementos diferentes y la
  partición usa dos señaladores (tema 19). El pivote no queda en su posición final.
- **Residuos:** además de la versión decimal, incluye la variante por grupos de 4 bits
  (tema 21).

Cada archivo se compila y ejecuta por separado:

```bash
g++ -std=c++17 -Wall -Wextra cpp/burbuja.cpp -o burbuja
./burbuja
```

```bash
python python/burbuja.py
```
