from QualiaII.models import tblVenta, tblSurtido, tblProducto


def calculoInversion(listaProductos):
    productosCompras = {}
    inversionProductos = {}
    acumulador = 0

    for var2 in listaProductos:
        if tblSurtido.objects.filter(producto=var2).exists():
            apariciones = tblSurtido.objects.filter(producto=var2)
            for a in apariciones:
                acumulador = acumulador + a.cantidad
            productosCompras[var2] = acumulador
            acumulador = 0
        else:
            productosCompras[var2] = 0 #Ya tengo las compras totales de cada producto

    for cla, val in productosCompras.items():

        prodRecup = tblProducto.objects.get(id=cla)
        cosProd = prodRecup.costo
        inversionEnEste = cosProd*val
        inversionProductos[cla] = inversionEnEste

    return inversionProductos

def calculoGanancia(listaProductos):

    productosVentas = {}
    gananciaProductos = {}
    acumulador = 0

    for var2 in listaProductos:
        if tblVenta.objects.filter(producto=var2).exists():
            apariciones = tblVenta.objects.filter(producto=var2)
            for a in apariciones:
                acumulador = acumulador + a.cantidad
            productosVentas[var2] = acumulador
            acumulador = 0
        else:
            productosVentas[var2] = 0  # Ya tengo las ventas totales de cada producto

    for cla, val in productosVentas.items():
        prodRecup = tblProducto.objects.get(id=cla)
        preProd = prodRecup.precio
        gananciaEnEste = preProd * val
        gananciaProductos[cla] = gananciaEnEste

    return gananciaProductos

def calculoInversionAcumulada(listaProductos):
    productosCompras = {}
    acumulador = 0
    inversion = 0

    for var2 in listaProductos:
        if tblSurtido.objects.filter(producto=var2).exists():
            apariciones = tblSurtido.objects.filter(producto=var2)
            for a in apariciones:
                acumulador = acumulador + a.cantidad
            productosCompras[var2] = acumulador
            acumulador = 0
        else:
            productosCompras[var2] = 0 #Ya tengo las compras totales de cada producto

    for cla, val in productosCompras.items():

        prodRecup = tblProducto.objects.get(id=cla)
        cosProd = prodRecup.costo
        inversionEnEste = cosProd*val
        inversion = inversion + inversionEnEste

    return inversion

def calculoGananciaAcumulada(listaProductos):

    productosVentas = {}
    acumulador = 0
    ganancia = 0

    for var2 in listaProductos:
        if tblVenta.objects.filter(producto=var2).exists():
            apariciones = tblVenta.objects.filter(producto=var2)
            for a in apariciones:
                acumulador = acumulador + a.cantidad
            productosVentas[var2] = acumulador
            acumulador = 0
        else:
            productosVentas[var2] = 0  # Ya tengo las ventas totales de cada producto

    for cla, val in productosVentas.items():
        prodRecup = tblProducto.objects.get(id=cla)
        preProd = prodRecup.precio
        gananciaEnEste = preProd * val
        ganancia = ganancia + gananciaEnEste

    return ganancia