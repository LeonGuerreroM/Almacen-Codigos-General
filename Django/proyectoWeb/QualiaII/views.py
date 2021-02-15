import operator

from django.http import HttpResponseRedirect
from django.shortcuts import render

from QualiaII.metodosComplementarios import *
from .models import *
from .Formularios import *


def altaCliente(response):
    try:
        if response.method == "POST":
            formulario = fAltaCliente(response.POST) #Llama al formulario creado

            if formulario.is_valid():
                n = formulario.cleaned_data["nombre"]
                ap = formulario.cleaned_data["apellido"]
                t = formulario.cleaned_data["telefono"]
                clie = tblCliente(nombre=n, apellido=ap, telefono=t)
                clie.save()
                return HttpResponseRedirect("/MenuClientes/")
        else:
            formulario = fAltaCliente(response.POST)
        return render(response, "AltaClientes.html", {"forma": formulario}) #Manda esta vista al html
    except:
        return HttpResponseRedirect("/Error/")

def cambioCliente(response):
    try:
        if response.method == "POST":
            formulario = fCambiosCliente(response.POST)

            if formulario.is_valid():
                ccc = formulario.cleaned_data["cliente"]
                nombrev=formulario.cleaned_data["nombre"]
                ap=formulario.cleaned_data["apellido"]
                telefo = formulario.cleaned_data["telefono"]
                clie = tblCliente.objects.get(nombre=ccc)
                clie.nombre=nombrev
                clie.apellido=ap
                clie.telefono=telefo
                clie.save()
                return HttpResponseRedirect("/MenuClientes/")
        else:
            formulario = fCambiosCliente(response.POST)
        return render(response, "CambiosClientes.html", {"forma": formulario})
    except:
       return HttpResponseRedirect("/Error/")

def bajaCliente(response):
    try:
        if response.method == "POST":
            formulario =fBajasCliente(response.POST)

            if formulario.is_valid():
                ccc=formulario.cleaned_data["cliente"]
                clie=tblCliente.objects.get(nombre=ccc)
                clie.delete()
                return HttpResponseRedirect("/MenuClientes/")
        else:
            formulario =fBajasCliente(response.POST)
        return render(response, "BajasClientes.html", {"forma": formulario})
    except:
        return HttpResponseRedirect("/Error/")

def consultaCliente(response):
    consulta = tblCliente.objects.all()
    return render(response, "ConsultaClientes.html", {"consulta":consulta, "condicion":True})

def altaProductos(response):
    #try:
        if response.method == "POST":
            formulario = fAltaProducto(response.POST) #Llama al formulario creado

            if formulario.is_valid():
                #ido = tblProducto.objects.last()
                #idv = ido.id
                #ide = idv + 1

                n = formulario.cleaned_data["nombre1"]
                t = formulario.cleaned_data["tipo"]
                m = formulario.cleaned_data["marca"]
                c = formulario.cleaned_data["clase"]
                s = formulario.cleaned_data["subclase"]
                ta = formulario.cleaned_data["tamanio"]
                cos = formulario.cleaned_data["costo"]
                e = formulario.cleaned_data["existenciasm"]

                precioCalculado = round(int(cos) + (int(cos) * 0.15))


                prod = tblProducto(nombre=n, tipo=t, marca=m, clase=c, subclase=s, tamanio=ta, costo=cos, existenciasMinimas=e, precio=precioCalculado)
                prod.save()

                return HttpResponseRedirect("/MenuProductos/")
        else:
            formulario = fAltaProducto(response.POST)
        return render(response, "AltaProducto.html", {"forma": formulario}) #Manda esta vista al html
    #except:
        #return HttpResponseRedirect("/Error/")

def cambioProducto(response):
    try:
        if response.method == "POST":
            formulario = fCambioProducto(response.POST)

            if formulario.is_valid():
                idv=formulario.cleaned_data["producto"]
                nombrev=formulario.cleaned_data["nombre1"]
                cos = formulario.cleaned_data["costo"]
                p = formulario.cleaned_data["precio"]
                e = formulario.cleaned_data["existenciasm"]
                prod = tblProducto.objects.get(nombre=idv)
                prod.nombre = nombrev
                prod.costo = cos
                prod.precio = p
                prod.existenciasMinimas=e
                prod.save()
                return HttpResponseRedirect("/MenuProductos/")
        else:
            formulario = fCambioProducto(response.POST)
        return render(response, "CambiosProductos.html", {"forma": formulario})
    except:
        return HttpResponseRedirect("/Error/")

def bajaProducto(response):
    try:
        if response.method == "POST":
            formulario =fBajasProducto(response.POST)

            if formulario.is_valid():
                idv = formulario.cleaned_data["producto"]
                prod=tblProducto.objects.get(nombre=idv)
                prod.delete()
                return HttpResponseRedirect("/MenuProductos/")
        else:
            formulario =fBajasProducto(response.POST)
        return render(response, "BajaProductos.html", {"forma": formulario})
    except:
        return HttpResponseRedirect("/Error/")

def consultaProducto(response):
    consulta = tblProducto.objects.all()
    return render(response, "ConsultaProductos.html", {"consulta":consulta, "condicion":True})

def altaMovs(response):
    try:
        if response.method == "POST":
            formulario = fAltaMov(response.POST) #Llama al formulario creado

            if formulario.is_valid():
                c = formulario.cleaned_data["cantidad"]
                cc = formulario.cleaned_data["concepto"]
                tt = formulario.cleaned_data["tipoTransaccion"]
                ccc = formulario.cleaned_data["cliente"]
                #print("transaccion="+str(tt))
                mov = tblMovimiento(cantidad=c, concepto=cc, tipoTransaccion=tt, cliente=ccc)
                mov.save()

                clienteAAlterar= tblCliente.objects.get(nombre=ccc)
                #print(clienteAAlterar.nombre)
                cuentaCliente= clienteAAlterar.cuenta
                cuentaClienteI = int(cuentaCliente)
                #print("cuenta ="+str(cuentaClienteI))

                if str(tt) == "Pago":
                    cuentaClienteI = cuentaClienteI - int(c)
                else:
                    cuentaClienteI = cuentaClienteI + int(c)

                #print("cuentai NUEVA =" + str(cuentaClienteI))
                cuentaCliente = str(cuentaClienteI)
                #print("Cuenta nueva=" + cuentaCliente)

                clienteAAlterar.cuenta = cuentaCliente
                clienteAAlterar.save()
                return HttpResponseRedirect("/MenuMovimientos/")

        else:
            formulario = fAltaMov(response.POST)
        return render(response, "AltaMov.html", {"forma": formulario}) #Manda esta vista al html
    except:
        return HttpResponseRedirect("/Error/")

def consultaMovs(response):
    consulta = tblMovimiento.objects.all()
    return render(response, "ConsultaMovs.html", {"consulta":consulta, "condicion":True})

def saldosGenerales(response):
    consulta = tblCliente.objects.all()
    return render(response, "saldosGenerales.html", {"consulta": consulta, "condicion": True})


def inventario(response):
    consulta = tblProducto.objects.all()
    return render(response, "inventario.html", {"consulta": consulta, "condicion": True})

def surtido(response):
    try:
        if response.method == "POST":
            formulario = fSurtido(response.POST)

            if formulario.is_valid():
                nombrev=formulario.cleaned_data["nombrea"]
                s = formulario.cleaned_data["surtido"]
                prod = tblProducto.objects.get(nombre=nombrev)
                existenciasActuales = prod.cantidad
                nuevasExistencias = existenciasActuales + int(s)
                prod.cantidad=str(nuevasExistencias)
                prod.save()

                surti = tblSurtido(producto = nombrev, cantidad = s)
                surti.save()
                return HttpResponseRedirect("/MenuProductos/")

        else:
            formulario = fSurtido(response.POST)
        return render(response, "surtido.html", {"forma": formulario})
    except:
        return HttpResponseRedirect("/Error/")

def listaCompra(response):
    consulta = tblProducto.objects.last()
    idUltimo = consulta.id
    idConsultado = 0
    compras =  []
    comprasCantidad = []

    while(idConsultado<idUltimo):
        idConsultado = idConsultado+1

        if tblProducto.objects.filter(id=idConsultado).exists():
            consultaActual = tblProducto.objects.get(id=idConsultado)
            if consultaActual.cantidad < consultaActual.existenciasMinimas:
                compras.append(consultaActual)
                #cuantoComprar = consultaActual.existenciasMinimas - consultaActual.cantidad
                #comprasCantidad.append(cuantoComprar)

    return render(response, "listaCompra.html", {"compras": compras, "iCompras": True}) #envia una lista de objectos de consulta

def altaVentas(response):
    try:
        if response.method == "POST":
            formulario = fVentas(response.POST) #Llama al formulario creado

            if formulario.is_valid():
                n = formulario.cleaned_data["nombreb"]
                c = formulario.cleaned_data["cantidad"]
                cc = formulario.cleaned_data["clienteb"]

                produ = tblProducto.objects.get(nombre=n)
                if (produ.cantidad < c):
                    return HttpResponseRedirect("/noStock/")
                else:
                    vnt = tblVenta(producto=n, cantidad=c, cliente=cc)
                    vnt.save()

                    produ.cantidad = produ.cantidad - int(c)
                    produ.save()
                    return HttpResponseRedirect("/MenuVentas/")
        else:
            formulario = fVentas(response.POST)
        return render(response, "AltaVentas.html", {"forma": formulario}) #Manda esta vista al html
    except:
        return HttpResponseRedirect("/Error/")

def altaVentasC(response):
    try:
        if response.method == "POST":
            formulario = fVentas(response.POST) #Llama al formulario creado

            if formulario.is_valid():
                n = formulario.cleaned_data["nombreb"]
                c = formulario.cleaned_data["cantidad"]
                cc = formulario.cleaned_data["clienteb"]

                produ = tblProducto.objects.get(nombre=n)
                if (produ.cantidad < c):
                    return HttpResponseRedirect("/noStock/")
                else:
                    vnt = tblVenta(producto=n, cantidad=c, cliente=cc)
                    vnt.save()


                    produ.cantidad = produ.cantidad - int(c)
                    precP = produ.precio
                    produ.save()

                    clie = tblCliente.objects.get(nombre=cc)
                    clie.cuenta = int(clie.cuenta) + (int(c)*precP)
                    clie.save()
                    return HttpResponseRedirect("/MenuVentas/")

        else:
            formulario = fVentas(response.POST)
        return render(response, "AltaVentasC.html", {"forma": formulario}) #Manda esta vista al html
    except:
        return HttpResponseRedirect("/Error/")

#def consultaVentasporFecha(response, anio, mes, dia):
 #   consulta=tblVenta.objects.filter(fecha__gte=datetime.date(anio, mes, dia))

def consultaVentasPorCliente(response,clientep):
    consulta1 = tblVenta.objects.filter(cliente=clientep) #las llaves foraeas son ints de ids, aunque en los forms parezcan los strings. se debe asignar para su busqueda con id´s
    return render(response, "consultaVentasPorCliente.html", {"consulta": consulta1, "condicion": True})

def escogerCliente(response):
    if response.method == "POST":
        formulario = fseleccionaClienteparaVentas(response.POST) #Llama al formulario creado

        if formulario.is_valid():
            n = formulario.cleaned_data["clienteb"]
            con = tblCliente.objects.get(nombre=n)
            idae = con.id
            return HttpResponseRedirect("/cvpc/%i/" %idae)

    else:
        formulario = fseleccionaClienteparaVentas(response.POST)
    return render(response, "scpv.html", {"forma": formulario}) #Manda esta vista al html

def escogerProducto(response):
    if response.method == "POST":
        formulario = fescogeProducto(response.POST) #Llama al formulario creado

        if formulario.is_valid():
            n = formulario.cleaned_data["nombreb"]
            con = tblProducto.objects.get(nombre=n)
            idae = con.id
            return HttpResponseRedirect("/ventasPorProducto/%i/" %idae)

    else:
        formulario = fescogeProducto(response.POST)
    return render(response, "escogeProducto.html", {"forma": formulario}) #Manda esta vista al html

def consultaVentasPorProducto(response,idp):
    consulta = tblVenta.objects.filter(producto=idp)
    return render(response, "ventasPorProducto.html", {"consulta": consulta, "condicion": True})

def consultaListaNegra(response):
    listaProductos = []
    productosApariciones = {}
    productosAparicionesOrdenado = {}
    diccionarioOrdenado = {}
    acumulador = 0
    i = 0

    tblListaNegra.objects.all().delete()

#Obtenemos una lista con los ids de la tabla productos
    productos = tblProducto.objects.all()
    for var in productos:
        listaProductos.append(var.id) #Obtiene los id´s de la tabla productos

#Obtenemos un diccionario con los ids de los productos como clave y sus apariciones respectivas como item
    for var2 in listaProductos:
        if tblVenta.objects.filter(producto=var2).exists():
            apariciones = tblVenta.objects.filter(producto=var2)
            for a in apariciones:
                acumulador = acumulador + a.cantidad
            productosApariciones[var2] = acumulador
            acumulador = 0
        else:
            productosApariciones[var2] = 0

#Ordenamos el diccionario de menor a mayor por items
    productosAparicionesOrdenado = sorted(productosApariciones.items(), key=operator.itemgetter(1))

#productosAparicionesOrdenado resulta ser una lista de tuplas, la recorreremos para que se convierta
#en un diccionario

    for respuesta in productosAparicionesOrdenado:
        claveN = respuesta[0] #el valor 0 de las tupla son las claves
        valorN = respuesta[1] #el valor 1 de las tuplas son los valores
        diccionarioOrdenado[claveN] = valorN

#Guardamos los primeros 15 o mas bajos en venta dentro de la tabla lista negra,
#con sus datos ubicados en la tabla de producto

    for var3 in diccionarioOrdenado.keys():
        if(i<15):
            i = i + 1
            prodRecup = tblProducto.objects.get(id=var3)
            productitoMalVendido = tblListaNegra(producto=var3,nombre=prodRecup.nombre,tipo=prodRecup.tipo,marca=prodRecup.marca)
            productitoMalVendido.save()

            prodRecup2 = tblProducto.objects.get(id=var3)
            if prodRecup2.APC==1:
                prodRecup2.APC=0

            prodRecup2.LN = 1
            prodRecup2.save()

        else:
            #break
            prodRecup2 = tblProducto.objects.get(id=var3)
            prodRecup2.LN = 0

    consulta = tblListaNegra.objects.all()

    return render(response, "consultaListaNegra.html", {"consulta": consulta, "condicion": True})

def consultaAclamados(response):
    listaProductos = []
    productosApariciones = {}
    productosAparicionesOrdenado = {}
    diccionarioOrdenado = {}
    acumulador = 0
    i = 0

    tblAPC.objects.all().delete()

#Obtenemos una lista con los ids de la tabla productos
    productos = tblProducto.objects.all()
    for var in productos:
        listaProductos.append(var.id) #Obtiene los id´s de la tabla productos

#Obtenemos un diccionario con los ids de los productos como clave y sus apariciones respectivas en ventas como item
    for var2 in listaProductos:
        if tblVenta.objects.filter(producto=var2).exists():
            apariciones = tblVenta.objects.filter(producto=var2)
            for a in apariciones:
                acumulador = acumulador + a.cantidad
            productosApariciones[var2] = acumulador
            acumulador = 0
        else:
            productosApariciones[var2] = 0

#Ordenamos el diccionario de menor a mayor por items
    productosAparicionesOrdenado = sorted(productosApariciones.items(), key=operator.itemgetter(1))
    productosAparicionesOrdenado.reverse()
#productosAparicionesOrdenado resulta ser una lista de tuplas, la recorreremos para que se convierta
#en un diccionario

    for respuesta in productosAparicionesOrdenado:
        claveN = respuesta[0] #el valor 0 de las tupla son las claves
        valorN = respuesta[1] #el valor 1 de las tuplas son los valores
        diccionarioOrdenado[claveN] = valorN

#Guardamos los primeros 15 o mas bajos en venta dentro de la tabla lista negra,
#con sus datos ubicados en la tabla de producto

    for cla, val in diccionarioOrdenado.items():
        if(i<15):
            i = i + 1
            prodRecup = tblProducto.objects.get(id=cla)
            productitoMalVendido = tblAPC(producto=cla,nombre=prodRecup.nombre,tipo=prodRecup.tipo,marca=prodRecup.marca,ventas=val)
            productitoMalVendido.save()

            prodRecup2 = tblProducto.objects.get(id=cla)
            if prodRecup2.LN == 1:
                prodRecup2.LN = 0

            prodRecup2.APC = 1
            prodRecup2.save()

        else:
            #break
            prodRecup2 = tblProducto.objects.get(id=cla)
            prodRecup2.APC = 0

    consulta = tblAPC.objects.all()

    return render(response, "aclamados.html", {"consulta": consulta, "condicion": True})

def balanceProductos(response):

    listaProductos = []
    dicciInversion = {}
    dicciGanancia = {}
    ides = []
    inversiones = []
    ganancias = []

    tblBalances.objects.all().delete()



    productos = tblProducto.objects.all()
    for var in productos:
        listaProductos.append(var.id)  # Obtiene los id´s de la tabla productos

    dicciInversion = calculoInversion(listaProductos)
    dicciGanancia = calculoGanancia(listaProductos)

    for cla, val in dicciInversion.items():
        ides.append(cla)
        inversiones.append(val)

    #print("Van las listas de id, inversiones y ganancias")
    #print(ides)
    #print(inversiones)

    for g in dicciGanancia.values():
        ganancias.append(g)

    #print(ganancias)

    tamanio = len(ganancias)
    #print("tamaño="+str(tamanio))

    for var in range(tamanio):
        print("var ="+str(var))
        datosProd = tblProducto.objects.get(id=ides[var])
        balan = ganancias[var] - inversiones[var]
        obj = tblBalances(producto = ides[var], nombre = datosProd.nombre, tipo = datosProd.tipo, marca = datosProd.marca, inversion = inversiones[var], ganacia = ganancias[var], balance = balan)
        obj.save()

    consulta = tblBalances.objects.all()

    return render(response, "balanceProductos.html", {"consulta": consulta, "condicion": True})

def balanceNegocio(response):
    listaProductos = []

    productos = tblProducto.objects.all()
    for var in productos:
        listaProductos.append(var.id)

    inversion = calculoInversionAcumulada(listaProductos)
    ganancia =  calculoGananciaAcumulada(listaProductos)
    balance = ganancia - inversion

    if (ganancia<(inversion+0.02*inversion)):
        mensaje = "El negocio está teniendo pérdidas D:"
    elif (ganancia<(inversion+0.12*inversion)):
        mensaje = "El negocio tiene muy bajos rendimientos :("
    elif (ganancia<(inversion+0.20*inversion)):
        mensaje = "El negocio tiene buenos rendimientos :)"
    elif (ganancia>(inversion+0.20*inversion)):
        mensaje = "!El negocio tiene un excelente rendimiento! :D"
    else:
        mensaje = "El negocio tiene rendimientos promedio"

    return render(response, "balanceNegocio.html", {"balance": balance, "mensaje": mensaje, "inversion": inversion, "ganancia": ganancia})

# Retorno de Menús

def MenuPrincipal(response):
    return render(response, "MenuPrincipal.html", {})

def MenuClientes(response):
    return render(response, "MenuClientes.html", {})

def MenuProductos(response):
    return render(response, "MenuProductos.html", {})

def MenuMovimientos(response):
    return render(response, "MenuMovimientos.html", {})

def MenuInversiones(response):
    return render(response, "MenuInversiones.html", {})

def MenuVentas(response):
    return render(response, "MenuVentas.html", {})

def Error(response):
    return render(response, "Error.html", {})

def noStock(response):
    return render(response, "noSuficienteStock.html", {})

