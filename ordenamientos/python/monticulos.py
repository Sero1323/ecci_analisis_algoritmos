# Ordenamiento por monticulos (heap sort): O(n log n) siempre, en el mismo arreglo.


def bajar(v, n, i):
    """Baja v[i] hasta restaurar el monticulo maximal en v[0..n-1]."""
    mayor = i
    izq = 2 * i + 1
    der = 2 * i + 2

    if izq < n and v[izq] > v[mayor]:
        mayor = izq
    if der < n and v[der] > v[mayor]:
        mayor = der

    if mayor != i:
        v[i], v[mayor] = v[mayor], v[i]
        bajar(v, n, mayor)


def heap_sort(v):
    n = len(v)
    for i in range(n // 2 - 1, -1, -1):  # construir el monticulo
        bajar(v, n, i)

    for fin in range(n - 1, 0, -1):
        v[0], v[fin] = v[fin], v[0]  # el mayor va al final
        bajar(v, fin, 0)  # el monticulo se achica en uno


if __name__ == "__main__":
    v = [9, 4, 3, 8, 10, 2, 5]
    heap_sort(v)
    print(*v)
