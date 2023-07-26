puntuacion = float(input("Ingrese la puntuación del empleado: "))
dinero= 2400 #cantidad dinero euros
if puntuacion == 0.0:   #inaceptable
    cantidad_dinero = 0
    print("Nivel: Inaceptable / "+ str(cantidad_dinero)+ "€")
elif puntuacion == 0.4:     #aceptable
    cantidad_dinero = dinero * 0.4
    print("Nivel: Aceptable / "+ str(cantidad_dinero)+ "€")
elif puntuacion == 0.6:   #meritorio
    cantidad_dinero = dinero * 0.6
    print("Nivel: Meritorio / "+ str(cantidad_dinero)+ "€")
else:
    print("No se pudo calcular")

