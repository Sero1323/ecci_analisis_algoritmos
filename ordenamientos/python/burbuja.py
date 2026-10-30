# Ordenamiento burbuja: O(n^2) en promedio y peor caso, O(n) si ya esta ordenado.


def bubble_sort(v):
    n = len(v)
    for i in range(n - 1):
        hubo_cambio = False
        for j in range(n - 1 - i):
            if v[j] > v[j + 1]:
                v[j], v[j + 1] = v[j + 1], v[j]
                hubo_cambio = True
        if not hubo_cambio:  # pasada sin cambios: ya esta ordenado
            break


if __name__ == "__main__":
    v = [64, 34, 25, 12, 22, 11, 90]
    bubble_sort(v)
    print(*v)
