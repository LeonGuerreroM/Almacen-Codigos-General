from django.db import models

# Create your models here.
class catClases(models.Model):
    clase = models.CharField(max_length=30)

    def __str__(self):
        return self.clase

class catTipoTransaccion(models.Model):
    tipo = models.CharField(max_length=2)

    def __str__(self):
        return self.tipo


class tblProducto(models.Model):
    nombre = models.CharField(max_length=30)
    tipo = models.CharField(max_length=20)
    marca = models.CharField(max_length=30)
    clase = models.ForeignKey(catClases, on_delete=models.CASCADE)
    subclase = models.CharField(max_length=30)
    tamanio = models.CharField(max_length=20)
    cantidad = models.IntegerField(default = 0)
    costo = models.IntegerField(default=0)
    precio = models.IntegerField(default=0)
    existenciasMinimas = models.IntegerField()
    LN = models.IntegerField(default=0)
    APC = models.IntegerField(default=0)

    def __str__(self):
        return self.nombre

    #def __str__(self):
    #    return self.nombre+" "+self.tipo+" "+self.marca

class tblCliente(models.Model):
    nombre = models.CharField(max_length=30)
    apellido = models.CharField(max_length=30)
    telefono = models.IntegerField()
    cuenta = models.IntegerField(default=0)

    def __str__(self):
        return self.nombre


class tblMovimiento(models.Model):
    cantidad = models.IntegerField()
    concepto = models.CharField(max_length=50)
    fecha = models.DateField(auto_now_add=True)
    tipoTransaccion = models.ForeignKey(catTipoTransaccion, on_delete=models.CASCADE)
    cliente = models.ForeignKey(tblCliente, on_delete=models.CASCADE)

class tblVenta(models.Model):
    producto = models.ForeignKey(tblProducto, on_delete=models.CASCADE)
    cantidad = models.IntegerField()
    fecha = models.DateField(auto_now_add=True)
    cliente = models.ForeignKey(tblCliente, on_delete=models.CASCADE)

class tblAPC(models.Model):
    producto = models.IntegerField()
    nombre = models.CharField(max_length=30, default="---")
    tipo = models.CharField(max_length=20, default="---")
    marca = models.CharField(max_length=30, default="---")
    ventas = models.IntegerField(default=0)

class tblListaNegra(models.Model):
    producto = models.IntegerField()
    nombre = models.CharField(max_length=30, default="---")
    tipo = models.CharField(max_length=20, default="---")
    marca = models.CharField(max_length=30, default="---")

class tblSurtido(models.Model):
    producto = models.ForeignKey(tblProducto, on_delete=models.CASCADE)
    cantidad = models.IntegerField()
    fecha = models.DateField(auto_now_add=True)

class tblBalances(models.Model):
    producto = models.IntegerField()
    nombre = models.CharField(max_length=30)
    tipo = models.CharField(max_length=20)
    marca = models.CharField(max_length=30)
    inversion = models.IntegerField()
    ganacia = models.IntegerField()
    balance = models.IntegerField()


