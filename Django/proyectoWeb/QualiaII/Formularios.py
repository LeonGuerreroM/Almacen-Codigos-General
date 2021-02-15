from django import forms

from QualiaII.models import *


class fAltaCliente(forms.Form):
    nombre = forms.CharField(label="Nombre(s) del Cliente", max_length=30)
    apellido = forms.CharField(label="Apellido(s) del Cliente", max_length=30)
    telefono = forms.IntegerField(label="Telefono", help_text="Numero de 10 digitos")

class fCambiosCliente(forms.Form):
    cliente = forms.ModelChoiceField(label="Cliente a modificar", queryset=tblCliente.objects.all())
    nombre = forms.CharField(label="Nombre(s) del Cliente", max_length=30)
    apellido = forms.CharField(label="Apellido(s) del Cliente", max_length=30)
    telefono = forms.CharField(label="Telefono", max_length=10, help_text="Numero de 10 digitos")


class fBajasCliente(forms.Form):
    cliente = forms.ModelChoiceField(label="Nombre(s) del Cliente", queryset=tblCliente.objects.all())

class fAltaProducto(forms.Form):
    nombre1 = forms.CharField(label="Nombre", max_length=30)
    tipo = forms.CharField(label="Tipo", max_length=20, help_text="Ejm. lata, fresa, bebible")
    marca = forms.CharField(label="Marca", max_length=20)
    clase = forms.ModelChoiceField(label="Clase", queryset=catClases.objects.all())
    subclase = forms.CharField(label="Subclase", max_length=30, help_text="Ejm. Lacteos, Cocina, Alcoholicas")
    tamanio = forms.CharField(label="Tamaño", max_length=20)
    costo = forms.IntegerField(label="Costo", label_suffix=": $")
    existenciasm = forms.IntegerField(label="Existencias minimas")

class fProductoPrecio(forms.Form):
    precio = forms.CharField(label="Precio", max_length=30, label_suffix=": $")

class fCambioProducto(forms.Form):
    producto = forms.ModelChoiceField(label="Producto a modificar", queryset=tblProducto.objects.all())
    nombre1 = forms.CharField(label="Nuevo(s) nombre(s)", max_length=30)
    precio = forms.IntegerField(label="Precio", label_suffix=": $")
    costo = forms.IntegerField(label="Costo", label_suffix=": $")
    existenciasm = forms.IntegerField(label="Existencias minimas")

class fBajasProducto(forms.Form):
    producto = forms.ModelChoiceField(label="Producto", queryset=tblProducto.objects.all())

class fAltaMov(forms.Form):
    concepto = forms.CharField(label="Concepto", max_length=50)
    cantidad = forms.IntegerField(label="Cantidad", label_suffix=": $")
    tipoTransaccion = forms.ModelChoiceField(label="TipoTransaccion", queryset=catTipoTransaccion.objects.all())
    cliente = forms.ModelChoiceField(label="Cliente", queryset=tblCliente.objects.all())

class fSurtido(forms.Form):
    nombrea = forms.ModelChoiceField(label="Nombre", queryset=tblProducto.objects.all())
    surtido = forms.IntegerField(label="Cantidad a surtir")

class fVentas(forms.Form):
    nombreb = forms.ModelChoiceField(label="Producto", queryset=tblProducto.objects.all())
    cantidad = forms.IntegerField(label="Cantidad")
    clienteb = forms.ModelChoiceField(label="Cliente", queryset=tblCliente.objects.all())

class fseleccionaClienteparaVentas(forms.Form):
    clienteb = forms.ModelChoiceField(label="Cliente", queryset=tblCliente.objects.all())

class fescogeProducto(forms.Form):
    nombreb = forms.ModelChoiceField(label="Producto", queryset=tblProducto.objects.all())


