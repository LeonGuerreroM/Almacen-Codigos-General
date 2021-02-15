from django.shortcuts import render
from .models import Organizacion, Agente
from .Formularios import *


# Create your views here.
def crearOrganizacion(response):
    if response.method == "POST":
        formulario = fOrganizacion(response.POST)

        if formulario.is_valid():
            n=formulario.cleaned_data["nombre"]
            na=formulario.cleaned_data["nAgentes"]
            org=Organizacion(nombre=n,nAgentes=na)
            org.save()
    else:
        formulario = fOrganizacion(response.POST)
    return render(response, "formulario1.html", {"forma": formulario})

def eliminarOrganizacion(response):
    if response.method == "POST":
        formulario =fOrganizacion(response.POST)

        if formulario.is_valid():
            n=formulario.cleaned_data["nombre"]
            na=formulario.cleaned_data["nAgentes"]
            org=Organizacion.objects.get(nombre=n, nAgentes=na)
            org.delete()
    else:
        formulario = fOrganizacion(response.POST)
    return render(response, "formBorrarOrganizacion.html", {"forma": formulario})

def vActualizarOrganizacion(response):
    if response.method == "POST":
        formulario =formaupdateOrganizacion(response.POST)

        if formulario.is_valid():
            idv=formulario.cleaned_data["id"]
            nombrev=formulario.cleaned_data["nombre"]
            nagentesv=formulario.cleaned_data["nAgentes"]
            org = Organizacion.objects.get(id=idv)
            org.nombre=nombrev
            org.nAgentes=nagentesv
            org.save()
    else:
        formulario =formaupdateOrganizacion(response.POST)
    return render(response, "formUpdateOrg.html", {"forma": formulario})

def vMostrarOrganizaciones(response):
    consulta=Organizacion.objects.filter(nombre="microsoft")
    print(consulta)
    return render(response, "consulta.html", {"consulta":consulta, "condicion":True})


