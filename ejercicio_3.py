#pedimos fecha de nacimiento al usuario
fecha_nacimiento = input("Ingrese su fecha de nacimiento en formato dd/mm/aaaa: ")

#slices vistos en clase
dia = fecha_nacimiento[0:2]
mes = fecha_nacimiento[3:5]
anio = fecha_nacimiento[6:]

#imprimir resultados
print("dia:", dia)
print("mes:", mes)
print("anio:", anio)