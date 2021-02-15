use tienda;

--Consultas Empleados
--create view ConsultarPlantilla as
Select Em.Id_Empleado, Em.Nombre, Em.Edad, Em.Direccion, ni.Descripcion as Nivel
from Empleados as Em
inner join nivel as ni
on Em.Id_Nivel=ni.Id_Nivel
order by Em.Id_Nivel

use tienda2;
--create view EmpleadosDestacados as
select top 10 v.Id_Empleado, Em.Nombre, count(v.Id_Empleado) as NoVentas
from Ventas as v
inner join Empleados as Em
on v.Id_Empleado=Em.Id_Empleado 
group by v.Id_Empleado, Em.Nombre
order by NoVentas desc

--Consultas Productos
create view CatalogoDeProductos as
Select Pr.Codigo, Pr.Descripcion, Pr.Presentacion, Pr.PrecioUnitarioVenta
from Productos as Pr
	
--create view ProductosMasVendidos as
select top 10 Dv.Codigo_Producto, Pr.Descripcion as Producto, SUM(Dv.Cantidad) as NoVentas 
from Detalle_Ventas as Dv
inner join Productos as Pr
on Dv.Codigo_Producto=Pr.Codigo
group by Dv.Codigo_Producto, Pr.Descripcion
order by NoVentas desc

--create view ProductosMenosVendidos as
select top 10 Dv.Codigo_Producto, Pr.Descripcion as Producto, sum(Dv.Cantidad) as NoVentas 
from Detalle_Ventas as Dv
inner join Productos as Pr
on Dv.Codigo_Producto=Pr.Codigo
group by Dv.Codigo_Producto, Pr.Descripcion
order by NoVentas asc

create view Inventario as
Select Pr.Descripcion, Pr.Existencias
from Productos as Pr

create view ListaDePrecios as
Select Pr.Descripcion, Pr.PrecioUnitarioVenta
from Productos as Pr

--create view ListaDeCompra as
select Pr.Codigo, Pr.Descripcion, Pr.Existencias, Pv.Nombre as Proveedor, Pv.Telefono
from Productos as Pr
left outer join Proveedores as Pv
on Pr.Id_Proveedor=Pv.Id_Proveedor
where Pr.Existencias<40
order by Existencias asc

/*create view GananciasPorProducto as
Select dp.CodigoProducto, sum(dp.PrecioUnitarioCompra*CantidadSurtida) as Gasto, 0, 0
from Detalle_Pedidos as dp
group by dp.CodigoProducto
union
Select dv.Codigo_Producto, 0, sum(dv.PrecioUnitarioVenta*Cantidad) as Ganancia, (Ganancia-Gasto) as GananciaNeta
from Detalle_Ventas as dv
group by dv.Codigo_Producto*/

--drop table #tempo1
--select * into #tempo1 from(
create view GananciasPorProducto as
Select dp.CodigoProducto, sum(dp.PrecioUnitarioCompra*CantidadSurtida) as Gasto, 0 as Ganancia into #tempo1
from Detalle_Pedidos as dp
group by dp.CodigoProducto
union
Select dv.Codigo_Producto, 0 as Gasto, sum(dv.PrecioUnitarioVenta*Cantidad) as Ganancia --into #temp2
from Detalle_Ventas as dv
group by dv.Codigo_Producto 

select *, (tp.Ganancia-tp.Gasto) as GananciaNeta 
from #tempo1 as tp

--Consultas Proveedores
create view Contactos as
Select Pr.Id_Proveedor, Pr.Nombre as Proveedor, Pr.Telefono
from Proveedores as Pr

--create view ListaDeProductos as
Select Pr.Descripcion as Producto, Pr2.Nombre as Proveedor
from Productos as Pr
inner join Proveedores as Pr2
on Pr.Id_Proveedor=Pr2.Id_Proveedor
order by Pr.Id_Proveedor

--create view ListaDeVendedores as
select ve.Nombre as Vendedor, Pr.Nombre as Proveedor, TV.Descripcion as TipoVendedor
from Vendedores as ve 
inner join Proveedores as Pr
on ve.Id_Proveedor=Pr.Id_Proveedor
inner join TiposVendedores as TV
on TV.Id_Tipo_Vendedor = ve.Id_Tipo_Vendedor
order by Pr.Id_Proveedor

--create view RankingDeProveedores as 
select top 5 Pr2.Nombre as Proveedor, Count(Pr.Id_Proveedor) as NoProductos
from Productos as Pr
inner join Proveedores as Pr2
on Pr.Id_Proveedor=Pr2.Id_Proveedor
group by Pr.Id_Proveedor, Pr2.Nombre
order by NoProductos desc

--Consultas Vendedores
--create view ListaDeVendedores2 as
select ve.Id_Vendedor, ve.Nombre as Vendedor, Pr.Nombre as Proveedor, TV.Descripcion as TipoVendedor
from Vendedores as ve 
inner join Proveedores as Pr
on ve.Id_Proveedor=Pr.Id_Proveedor
inner join TiposVendedores as TV
on TV.Id_Tipo_Vendedor = ve.Id_Tipo_Vendedor
order by ve.Id_Tipo_Vendedor

--consultas usuarios
--create view ListaDeUsuarios as
select Em.Id_Empleado, Em.Nombre, usr.Usuario, usr.Passwd, ni.Descripcion as Nivel
from Usuarios as usr
inner join Empleados as em
on usr.Id_Empleado=em.Id_Empleado
inner join Nivel as ni
on ni.Id_Nivel=em.Id_Nivel
order by Em.Id_Nivel

--consultas Pedidos
--create view PedidosPorProveedor as
select Pe.Id_Pedido, Pr.Nombre as Proveedor, ve.Nombre as Vendedor, Pe.FechaPedido, Pe.FechaEsperada, sp.Descripcion as [Status] 
from Pedidos as Pe
inner join Proveedores as Pr
on Pe.Id_Proveedor=Pr.Id_Proveedor
inner join Vendedores as ve
on Pe.Id_Vendedor=ve.Id_Vendedor
inner join Status_Pedidos as sp
on pe.Id_Status=sp.Id_Status
order by Pe.Id_Proveedor

--create view PedidosPorFechaEsperada as --pedidos abiertos 
select Pe.Id_Pedido, Pe.FechaPedido, Pe.FechaEsperada
from Pedidos as Pe
where pe.Id_Status=1
order by Pe.FechaEsperada

--create view PedidosPorProductos as
select  Pe.Id_Pedido, DP.CodigoProducto, P.Descripcion as Producto, DP.CantidadSolicitada, sp.Descripcion as [Status]
from Pedidos as Pe
inner join Detalle_Pedidos as DP
on Pe.Id_Pedido=DP.Id_Pedido
inner join Productos as P
on DP.CodigoProducto=P.Codigo
inner join Status_Pedidos as sp
on pe.Id_Status=sp.Id_Status
order by Pe.Id_Status

--create view HistorialDePedidos as --pedidos cerrados
Select Pe.Id_Pedido, Pr.Nombre as Proveedor, ven.Nombre as Vendedor, Pe.FechaPedido, Pe.FechaRecibido
from Pedidos as Pe
left outer join Proveedores as Pr
on Pe.Id_Proveedor=Pr.Id_Proveedor
left outer join Vendedores as ven
on Pe.Id_Vendedor=ven.Id_Vendedor
where Pe.Id_Status=3
order by Pe.Id_Pedido

--create view PedidosEnPuerta as --pedidos abiertos
select Pe.Id_Pedido, Pe.FechaEsperada, Pr.Nombre as Proveedor, ven.Nombre as Vendedor
from Pedidos as Pe
left outer join Proveedores as Pr
on Pe.Id_Proveedor=Pr.Id_Proveedor
left outer join Vendedores as ven
on Pe.Id_Vendedor=ven.Id_Vendedor
where Pe.Id_Status=1
order by Pe.FechaEsperada desc

--create view PedidosConProblemas as
Select Pe.Id_Pedido, p.Nombre as Proveedor, sp.Descripcion as [Status]
from Pedidos as Pe
inner join Status_Pedidos as sp
on Pe.Id_Status=sp.Id_Status
inner join Proveedores as p
on Pe.Id_Proveedor=p.Id_Proveedor
where Pe.Id_Status = 4 OR Pe.Id_Status = 2
order by Pe.Id_Proveedor

--create view DiasDeVisita as
select p.Nombre as Proveedor, tp.Descripcion as TipoVendedor, di.Dia
from DiasVisita as di
inner join Proveedores as p
on di.Id_Proveedor=p.Id_Proveedor
inner join TiposVendedores as tp
on tp.Id_Tipo_Vendedor=di.Id_Tipo_Vendedor
order by p.Id_Proveedor


--Consultas Ventas

/*create view GananciasPorVentas as
select ven.Id_Venta, SUM(ven.TotalVenta) as GananciaTotal
from Ventas as ven
group by ven.Id_Venta*/

create view GananciasPorVentas as
select ven.Id_Venta, ven.TotalVenta as GananciaTotal
from Ventas as ven

/*create function Ticket (@vent int)
returns table
as
return(
select dv.Codigo_Producto, Pr.Descripcion as Producto, dv.Cantidad, ven.TotalVenta as Subtotal
from Ventas as ven
inner join Detalle_Ventas as dv
on ven.Id_Venta=dv.Id_Venta
inner join Productos as Pr
on Pr.Codigo=dv.Codigo_Producto
where ven.Id_Venta=(@vent));*/

create function Ticket (@vent int)
returns table
as
return(
select dv.Codigo_Producto, Pr.Descripcion as Producto, dv.Cantidad, (dv.Cantidad*dv.PrecioUnitarioVenta) as Subtotal
from Ventas as ven
inner join Detalle_Ventas as dv
on ven.Id_Venta=dv.Id_Venta
inner join Productos as Pr
on Pr.Codigo=dv.Codigo_Producto
where ven.Id_Venta=(@vent));

use tienda;
create view GananciasPorDia as
select convert(date, ven.FechaHora) as fecha, sum(ven.TotalVenta) as Ganancias
from Ventas as ven
group by convert(date, ven.FechaHora) --fecha-- no admite agrupar usando alias de algo casteado

--create view MejoresDias as
select top 10 cast(ven.FechaHora as date) as fecha, sum(ven.TotalVenta) as Ganancias
from Ventas as ven
group by cast(ven.FechaHora as date)
order by Ganancias desc
