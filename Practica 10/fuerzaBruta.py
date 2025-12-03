from string import digits
from itertools import product
from time import time

caracteres = digits   # Solo números del 0 al 9


def fuerza_bruta(con):
    n = len(con)

    # Verificar si el tamaño es válido
    if n not in [4, 8, 10]:
        print("La contraseña debe tener 4, 8 o 10 dígitos.")
        return

    archivo = open(f"combinaciones_{n}.txt", "w")

    # Generar combinaciones del tamaño exacto
    for comb in product(caracteres, repeat=n):
        intento = "".join(comb)
        archivo.write(intento + "\n")

        if intento == con:        # Contraseña encontrada
            print(f"Contraseña encontrada: {intento}")
            archivo.close()
            return

    archivo.close()
    print("La contraseña no está en las combinaciones generadas.")


# ------------------------------
# Ejemplo de uso
# ------------------------------
t0 = time()
from string import digits
from itertools import product
from time import time

caracteres = digits

def fuerza_bruta(con):
    n = len(con)

    for comb in product(caracteres, repeat=n):
        intento = "".join(comb)
        if intento == con:
            print("Contraseña encontrada:", intento)
            return


# ------------------------------
# PRUEBA CON 4, 8 Y 10 DÍGITOS
# ------------------------------

t0 = time()
con = "3265"
print(f"Contraseña {len(con)} dígitos")
fuerza_bruta(con)
print(f"Tiempo de ejecución {len(con)} dígitos: {round(time() - t0, 6)}")


t0 = time()
con = "39076265"
print(f"\nContraseña {len(con)} dígitos")
fuerza_bruta(con)
print(f"Tiempo de ejecución {len(con)} dígitos: {round(time() - t0, 6)}")


t0 = time()
con = "3541290265"
print(f"\nContraseña {len(con)} dígitos")
fuerza_bruta(con)
print(f"Tiempo de ejecución {len(con)} dígitos: {round(time() - t0, 6)}")


