from django.shortcuts import render, redirect
from django.contrib.auth import login, authenticate
from django.contrib.auth.forms import UserCreationForm

# Create your views here.

def registro(response):
    if response.method == "POST":
        forma =UserCreationForm(response.POST)
        if forma.is_valid():
            forma.save()
    else:
        forma = UserCreationForm()
    return render(response, "RegistroNuevoUsuario.html", {"forma":forma})

def main(response):
    return render(response, "main.html", {})

def cerrarSesion(response):
    return render(response, "cerrarSesion.html", {})