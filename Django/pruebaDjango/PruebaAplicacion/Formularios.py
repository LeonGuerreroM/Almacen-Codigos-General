from django import forms

class fOrganizacion(forms.Form):
    nombre =forms.CharField(label="Nombre de la Organizacion", max_length=200)
    nAgentes = forms.CharField(label = "Numero de Agentes", max_length=9)

class formaupdateOrganizacion(forms.Form):
    id = forms.IntegerField(label="Id de la organizacion")
    nombre = forms.CharField(label="Nombre de la Organizacion", max_length=200)
    nAgentes = forms.CharField(label="Numero de Agentes", max_length=9)
