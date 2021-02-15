from django.db import models


# Create your models here.

class Organizacion(models.Model):
    nombre = models.CharField(max_length=100)
    nAgentes = models.IntegerField()


class Agente(models.Model):
    nombre = models.CharField(max_length=100)
    organizacion = models.ForeignKey(Organizacion, on_delete=models.CASCADE)
    fechaIngreso = models.DateField()
    activo = models.BooleanField()


