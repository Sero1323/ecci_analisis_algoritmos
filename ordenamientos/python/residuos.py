# Ordenamiento por residuos (radix sort): O(d * (n + b)), con d digitos en base b = 10.
# Requiere enteros no negativos.


def ordenar_por_digito(v, exp):
    """Ordena de forma estable segun el digito de valor posicional exp."""
    conteo = [0] * 10
    for x in v:
        conteo[(x // exp) % 10] += 1
    for d in range(1, 10):
        conteo[d] += conteo[d - 1]

    salida = [0] * len(v)
    for x in reversed(v):
        d = (x // exp) % 10
        conteo[d] -= 1
        salida[conteo[d]] = x
    v[:] = salida


def radix_sort(v):
    if not v:
        return

    mayor = max(v)
    exp = 1
    while mayor // exp > 0:
        ordenar_por_digito(v, exp)
        exp *= 10


def ordenar_por_grupo(v, p):
    """Variante por bits: ordena de forma estable segun el grupo de 4 bits en la posicion p."""
    conteo = [0] * 16
    for x in v:
        conteo[(x >> (4 * p)) & 0xF] += 1
    for g in range(1, 16):
        conteo[g] += conteo[g - 1]

    salida = [0] * len(v)
    for x in reversed(v):
        g = (x >> (4 * p)) & 0xF
        conteo[g] -= 1
        salida[conteo[g]] = x
    v[:] = salida


def radix_sort_bits(v):
    """Un corrimiento y una mascara en vez de una division y un modulo."""
    if not v:
        return

    mayor = max(v)
    p = 0
    while mayor >> (4 * p) > 0:
        ordenar_por_grupo(v, p)
        p += 1


if __name__ == "__main__":
    v = [170, 45, 75, 90, 802, 24, 2, 66]
    w = list(v)

    radix_sort(v)
    print(*v)

    radix_sort_bits(w)
    print(*w)
