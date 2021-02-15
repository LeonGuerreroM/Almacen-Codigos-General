"""proyectoWeb URL Configuration

The `urlpatterns` list routes URLs to views. For more information please see:
    https://docs.djangoproject.com/en/2.2/topics/http/urls/
Examples:
Function views
    1. Add an import:  from my_app import views
    2. Add a URL to urlpatterns:  path('', views.home, name='home')
Class-based views
    1. Add an import:  from other_app.views import Home
    2. Add a URL to urlpatterns:  path('', Home.as_view(), name='home')
Including another URLconf
    1. Import the include() function: from django.urls import include, path
    2. Add a URL to urlpatterns:  path('blog/', include('blog.urls'))
"""
from django.contrib import admin
from django.urls import path
from django.urls import path, include
from RegistroUsuarios.views import *
from QualiaII.views import *


urlpatterns = [
    path('admin/', admin.site.urls),
    path('registroUsuario/', registro),
    path('cerrarSesion/', cerrarSesion),

    path('altaClientes/', altaCliente),
    path('cambioClientes/', cambioCliente),
    path("bajaClientes/", bajaCliente),
    path("consultaClientes/", consultaCliente),
    path("altaProductos/", altaProductos),
    path('cambioProductos/', cambioProducto),
    path("bajaProductos/", bajaProducto),
    path("consultaProductos/", consultaProducto),
    path("altaMovs/", altaMovs),
    path("consultaMovs/", consultaMovs),
    path("saldosGenerales/", saldosGenerales),
    path("inventario/", inventario),
    path("surtido/", surtido),
    path("listaCompra/", listaCompra),
    path("altaVentas/", altaVentas),
    path("altaVentasC/", altaVentasC),
    path("cvpc/<int:clientep>/", consultaVentasPorCliente),
    path("escogerCliente/", escogerCliente),
    path("escogerProducto/", escogerProducto),
    path("ventasPorProducto/<int:idp>/", consultaVentasPorProducto),
    path("listaNegra/", consultaListaNegra),
    path("aclamados/", consultaAclamados),
    path("balanceProductos/", balanceProductos),
    path("balanceNegocio/", balanceNegocio),

    path("MenuPrincipal/", MenuPrincipal),
    path("MenuClientes/", MenuClientes),
    path("MenuProductos/", MenuProductos),
    path("MenuMovimientos/", MenuMovimientos),
    path("MenuInversiones/", MenuInversiones),
    path("MenuVentas/", MenuVentas),
    path("Error/", Error),
    path("noStock/", noStock),

    path("Main/", main),
    path('', include("django.contrib.auth.urls")),


]
