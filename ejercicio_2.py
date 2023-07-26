# funcion area circulo
def area_circulo(radio):
    return 3.1416 * radio ** 2

# funcion volumen cilindro
def volumen_cilindro():
    volumen = area_circulo(5) * 10
    print("El volumen del cilindro es:"+ str(volumen))

#se llama la funcion volumen_cilindro y se imprime en pantalla
volumen_cilindro()