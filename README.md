# AlgebraAbstractaLb08_01
El algoritmo hace uso de las funciones WITNESS() y MILLER_RABIN(),para detectar números primos de tres cifras, sabemos que todo numero primo es impar a excepción del 2,
MILLER_RABIN(n,s), donde n lo igualo a 101 y aumento de 2 en 2, evaluando solo impares.

La función MILLER_RABIN(n,s) me pide un numero y las veces a evaluar, por cada evaluación tomara la función WITNESS(a,n) donde a es tomada aleatoriamente a[2 , n-1],si  WITNESS(a,n) retorna false, n es un posible primo, por el contrario si retorna true es un numero compuesto.

La función WITNESS(a,n) toma a y n y evalúa los valores de t y u, n-1 = 2^t *u, luego establece un caso base x0 = a^u mod n, si x0 es 1 o -1 retorna false, y es un posible primo, si no eleva al cuadrado el antecesor mod n, si este nuevo valor es igual a n-1, retornamos false y n es un posible primo, de lo contrario retornamos true y n es compuesto.
