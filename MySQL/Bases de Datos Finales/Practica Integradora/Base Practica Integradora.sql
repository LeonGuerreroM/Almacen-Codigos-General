drop database if exists PI2;
create database if not  exists PI2;

use PI2;

##catalogos

create table catZonas(
idZona int (1) auto_increment,
zona varchar (20),
Primary Key (idZona)
)ENGINE = INNODB;
	insert into catZonas (zona) values ('Centro');
    insert into catZonas (zona) values ('Norte');
    insert into catZonas (zona) values ('Sur');
    insert into catZonas (zona) values ('Este');
    insert into catZonas (zona) values ('Oeste');
create table catTipoMov(
idTipoMov int (1) auto_increment,
movimiento varchar (10),
Primary Key (idTipoMov)
)ENGINE = INNODB;
	insert into catTipoMov (movimiento) values ('Venta');
    insert into catTipoMov (movimiento) values ('Renta');
create table catColor(
idColor int (2) auto_increment,
color varchar (20),
Primary Key (idColor)
)ENGINE = INNODB;
	insert into catColor (color) values ('Blanco');
    insert into catColor (color) values ('Negro');
    insert into catColor (color) values ('Rojo');
    insert into catColor (color) values ('Gris');
    insert into catColor (color) values ('Cafe');
    insert into catColor (color) values ('Azul');
    insert into catColor (color) values ('Verde');
    insert into catColor (color) values ('Amarillo');
    insert into catColor (color) values ('Plateado');
    insert into catColor (color) values ('Beige');
create table catEstado(
idEstado int (1) auto_increment,
estado varchar (20),
Primary Key (idEstado)
)ENGINE = INNODB;
	insert into catEstado (estado) values ('Disponible');
    insert into catEstado (estado) values ('No Disponible');
create table catDepartamento(
idDepartamento int (1) auto_increment,
dept varchar (20),
Primary Key (idDepartamento) 
)ENGINE = INNODB;
	insert into catDepartamento (dept) values ('ventas');
    insert into catDepartamento (dept) values ('rentas');
create table catTipoCliente(
idTipo int (1) auto_increment,
tipo varchar (50),
Primary Key (idTipo)
)ENGINE = INNODB;
	insert into catTipoCliente (tipo) values ('Nuevo');
    insert into catTipoCliente (tipo) values ('Frecuente');
create table catMarcaModelo(
idMM int (2) auto_increment,
marca varchar (50),
modelo varchar (50),
Primary Key (idMM)
)ENGINE = INNODB;
	insert into catMarcaModelo (marca, modelo) values ('VW', 'Jetta');
    insert into catMarcaModelo (marca, modelo) values ('VW', 'Bora');
    insert into catMarcaModelo (marca, modelo) values ('VW', 'Vento');
    insert into catMarcaModelo (marca, modelo) values ('VW', 'Passat');
    insert into catMarcaModelo (marca, modelo) values ('VW', 'Golf');
    insert into catMarcaModelo (marca, modelo) values ('Nissan', 'Platina');
    insert into catMarcaModelo (marca, modelo) values ('Nissan', 'Versa');
    insert into catMarcaModelo (marca, modelo) values ('Nissan', 'Sentra');
    insert into catMarcaModelo (marca, modelo) values ('Honda', 'Civic');
    insert into catMarcaModelo (marca, modelo) values ('Honda', 'City');
    insert into catMarcaModelo (marca, modelo) values ('Ford', 'Fiesta');
    insert into catMarcaModelo (marca, modelo) values ('Ford', 'Focus');
    insert into catMarcaModelo (marca, modelo) values ('Chevrolet', 'Spark');
    insert into catMarcaModelo (marca, modelo) values ('Chevrolet', 'Cruze');
    insert into catMarcaModelo (marca, modelo) values ('Chevrolet', 'Camaro');
    insert into catMarcaModelo (marca, modelo) values ('Toyata', 'Yaris');
    insert into catMarcaModelo (marca, modelo) values ('Toyata', 'Corolla');
    insert into catMarcaModelo (marca, modelo) values ('Chevrolet', 'Mustang');
    insert into catMarcaModelo (marca, modelo) values ('Audi', 'TT5');
    insert into catMarcaModelo (marca, modelo) values ('Mercedes Benz', 'AMG');
create table catEstados(
idEstado int (1) auto_increment,
estado varchar (50),
zona int (1),
Primary Key (idEstado),
foreign key (zona) references catZonas (idZona)
)ENGINE = INNODB;
	insert into catEstados (estado, zona) values ('DF', 1);   
    insert into catEstados (estado, zona) values ('Aguascalientes', 1);   
    insert into catEstados (estado, zona) values ('Guanajuato', 1);   
    insert into catEstados (estado, zona) values ('San Luis Potosi', 1);   
    insert into catEstados (estado, zona) values ('Zacatecas', 1);   
    insert into catEstados (estado, zona) values ('Queretaro', 1);   
    insert into catEstados (estado, zona) values ('Morelos', 1);   
    insert into catEstados (estado, zona) values ('Edo Mex', 1); 
    insert into catEstados (estado, zona) values ('Baja California', 2);
    insert into catEstados (estado, zona) values ('Baja California Sur', 2);
    insert into catEstados (estado, zona) values ('Chihuahua', 2);
    insert into catEstados (estado, zona) values ('Durango', 2);
    insert into catEstados (estado, zona) values ('Sinaloa', 2);
    insert into catEstados (estado, zona) values ('Sonora', 2);
    insert into catEstados (estado, zona) values ('Coahuila', 2);
    insert into catEstados (estado, zona) values ('Nuevo Leon', 2);
    insert into catEstados (estado, zona) values ('Tamaulipas', 2);
    insert into catEstados (estado, zona) values ('Guerrero', 3);
    insert into catEstados (estado, zona) values ('Oaxaca', 3);
    insert into catEstados (estado, zona) values ('Chiapas', 3);
    insert into catEstados (estado, zona) values ('Tabasco', 3);
    insert into catEstados (estado, zona) values ('Campeche', 3);
    insert into catEstados (estado, zona) values ('Quintana Roo', 3);
    insert into catEstados (estado, zona) values ('Yucatan', 3);
    insert into catEstados (estado, zona) values ('Puebla', 4);
    insert into catEstados (estado, zona) values ('Veracruz', 4);
    insert into catEstados (estado, zona) values ('Tlaxcala', 4);
    insert into catEstados (estado, zona) values ('Hidalgo', 4);
    insert into catEstados (estado, zona) values ('Nayarit', 5);
    insert into catEstados (estado, zona) values ('Jalisco', 5);
    insert into catEstados (estado, zona) values ('Colima', 5);
    insert into catEstados (estado, zona) values ('Michoacan', 5);
    
create table catComision(
idComision int (1) auto_increment,
comision varchar (10),
Primary key (idComision)
);
	insert into catComision (comision) values ('18%');
    insert into catComision (comision) values ('20%');
    
##tablas entidades
create table sucursales(
idSucursal int (4) auto_increment,
nombre varchar (50),
estado int (2),
Primary Key (idSucursal),
foreign key (estado) references catEstados (idEstado) on update cascade on delete cascade
)ENGINE = INNODB;

create table empleados(
idEmpleado int (4) auto_increment,
nombre varchar (50),
apat varchar (50),
amat varchar (50),
Primary Key (idEmpleado)
)ENGINE = INNODB;

create table autos(
placa int (10) auto_increment,
mm int (2),
color int (2),
estado int (1),
dept int (1),
Primary Key (placa),
foreign key (mm) references catMarcaModelo (idMM) on update cascade on delete cascade,
foreign key (color) references catColor (idColor) on update cascade on delete cascade,
foreign key (estado) references catEstado (idEstado) on update cascade on delete cascade,
foreign key (dept) references catDepartamento (idDepartamento) on delete cascade on update cascade
)ENGINE = INNODB;

create table clientes(
idCliente int (6) auto_increment,
nombre varchar (50),
apat varchar (50),
edad int (3),
telefono int (10),
tipo int (1),
Primary Key (idCliente),
foreign key (tipo) references catTipoCliente (idTipo) on update cascade on delete cascade
)ENGINE = INNODB;

create table movimientos(
idMov int (20) auto_increment,
fechaMov date,
tipoMov int (1),
plazo varchar (50),
fechaEntrega date,
cliente int (6),
auto int (10),
empleado int (4),
comision int (1),
Primary Key (idMov),
foreign key (tipoMov) references catTipoMov (idTipoMov) on update cascade on delete cascade,
foreign key (cliente) references clientes (idCliente) on update cascade on delete cascade,
foreign key (auto) references autos (placa) on update cascade on delete cascade,
foreign key (empleado) references empleados (idEmpleado) on update cascade on delete cascade,
foreign key (comision) references catComision (idComision) on update cascade on delete cascade
)ENGINE = INNODB;

##relaciones
create table relSucursalesEmpleados(
idSE int (7) auto_increment,
sucursal int (4),
empleado int (4),
Primary Key (idSE),
foreign key (sucursal) references sucursales (idSucursal) on update cascade on delete cascade,
foreign key (empleado) references empleados (idEmpleado) on delete cascade on update cascade
)ENGINE = INNODB;

create table relSucursalesAutos(
idSA int (7) auto_increment,
sucursal int (4),
auto int  (10),
Primary Key (idSA),
foreign key (sucursal) references sucursales (idSucursal) on update cascade on delete cascade,
foreign key (auto) references autos (placa) on update cascade on delete cascade
)ENGINE = INNODB;

##Procedimientos almacenados
	#catalogos
		-- catMarcaModelo
delimiter **
create procedure insertaMM (in m varchar (50), mo varchar (50) )
begin 
insert into catMarcaModelo (marca, modelo) values (m, mo);
end **
delimiter ;

delimiter **
create procedure eliminaMM (in MM int (2) )
begin 
delete from catMarcaModelo where idMM=MM;
end **
delimiter ;

		-- catColor
delimiter **
create procedure insertaColor (in colorM varchar (50) )
begin 
insert into catColor (color) values (colorM);
end **
delimiter ;

delimiter **
create procedure eliminaColor (in col int (2) )
begin 
delete from catColor where idColor=col;
end **
delimiter ;
	#Entidades
		-- sucursales
delimiter **
create procedure insertaSucursal (in nombreM varchar (50), estadoM int (2) )
begin 
insert into sucursales (nombre, estado) values (nombreM, estadoM);
end **
delimiter ;

call insertaSucursal ('AutoMundo', 1);
call insertaSucursal ('Kioto', 1);
call insertaSucursal ('AutosElegantes', 1);

delimiter **
create procedure eliminaSucursal (in suc int (4) )
begin 
delete from sucursales where idSucursal=suc;
end **
delimiter ;

delimiter **
create procedure modificaSucursal (in suc int (4), n varchar (50), e int (2) )
begin 
update sucursales
set nombre=n, estado=e
where idSucursal=suc;
end **
delimiter ;
		-- Empleados
delimiter **
create procedure insertaEmpleado (in nombreM varchar (50), ap varchar (50), am varchar (50) )
begin 
insert into empleados (nombre, apat, amat) values (nombreM, ap, am);
end **
delimiter ;

call insertaEmpleado ('Romeo', 'Montesco', 'Dubante');
call insertaEmpleado('Sherlock', 'Holmes', 'Knig');
call insertaEmpleado ('Robbinson', 'Crusoe', 'swift');

delimiter **
create procedure eliminaEmpleado (in emp int (4) )
begin 
delete from empleados where idEmpleado=emp;
end **
delimiter ;

delimiter **
create procedure modificaEmpleado (in emp int (4), n varchar (50), ap varchar (50), am varchar (50) )
begin 
update empleados
set nombre=n, apat=ap, amat=am
where idEmpleado=emp;
end **
delimiter ;
		-- autos
delimiter **
create procedure insertaAuto (in mm1 int (2), color1 int (2), estado1 int (1), dept1 int (1) )
begin 
insert into autos (mm, color, estado, dept) values (mm1, color1, estado1, dept1);
end **
delimiter ;

call insertaAuto (1, 3, 2, 1);
call insertaAuto (15, 6, 1, 2);
call insertaAuto (20, 9, 1, 1);

delimiter **
create procedure eliminaAuto (in aut int (10) )
begin 
delete from autos where placa=aut;
end **
delimiter ;

delimiter **
create procedure modificaAuto (in aut int (10), mm1 int (2), color1 int (2), estado1 int (1), dept1 int (1) )
begin 
update autos
set mm=mm1, color=color1, estado=estado1, dept=dept1
where placa=aut;
end **
delimiter ;
		-- clientes
delimiter **
create procedure insertaCliente (in n varchar (50), ap varchar (50), e int (3), tel int (10), tip int (1) )
begin 
insert into clientes (nombre, apat, edad, telefono, tipo) values (n, ap, e, tel, tip);
end **
delimiter ;

call insertaCliente ('Oscar', 'Wilde', 50, 1010101011, 2 );
call insertaCliente ('Henry David', 'Thoreau', 34, 1919191028, 1);
call insertaCliente ('Nicolas', 'Maquiavelo', 70, 2020483028, 2);

delimiter **
create procedure eliminaCliente (in clt int (6) )
begin 
delete from clientes where idCliente=clt;
end **
delimiter ;

delimiter **
create procedure modificaCliente (in clt int (6), n varchar (50), ap varchar (50), e int (3), tel int (10), tip int (1))
begin 
update clientes
set nombre=n, apat=ap, edad=e, telefono=tel, tipo=tip
where idCliente=clt;
end **
delimiter ;
		-- Movimientos
delimiter **
create procedure insertaMovimiento (in fv date, tm int (1), plazoa varchar (50), fe date, clt int (6), aut int (10), em int (4), c varchar (10) )
begin 
insert into sucursales (fechaMov, tipoMov, plazo, fechaEntrega, cliente, auto, empleado, comision) values (fv, tm, plazoa, fe, clt, aut, em, c);
end **
delimiter ;

##call insertaMovimiento ('', , '', '', , , ); para insertar movimientos


delimiter **
create procedure eliminaMovimiento (in mo int (20) )
begin 
delete from movimientos where idMov=mo;
end **
delimiter ;

delimiter **
create procedure modificaMovimiento (in mo int (20), fv date, tm int (1), plazoa varchar (50), fe date, clt int (6), aut int (10), em int (4), c varchar (10))
begin 
update movimientos
set fechaMov=fv, tipoMov=tm, plazo=plazoa, fechaEntrega=fe, cliente=clt, auto=aut, empleado=em, comision=c
where idMov=mov;
end **
delimiter ;
	#relaciones
		-- relacionSE
delimiter **
create procedure insertarSE (in suc int (4), emp int (4))
begin 
insert into relSucursalesEmpleados (sucursal, empleado) values (suc, emp);
end **
delimiter ;

##call insertarSE ( , , ,);##para inseratar realcion


delimiter **
create procedure eliminaSE (in se int (7) )
begin 
delete from relSucursalesEmpleados where idSE=se;
end **
delimiter ;

delimiter **
create procedure modificaSE (in se int (7), suc int (4), emp int (4))
begin 
update relSucursalesEmpleados
set sucursal=suc, empleado=emp 
where idSE=se;
end **
delimiter ;
		-- relacionSA
delimiter **
create procedure insertarSA (in suc int (4), aut int (10))
begin 
insert into relSucursalesAutos (sucursal, auto) values (suc, aut);
end **
delimiter ;

##call insertarSA ( , , ,); para inseratr relaciones

delimiter **
create procedure eliminaSA (in sa int (7) )
begin 
delete from relSucursalesAutos where idSA=sa;
end **
delimiter ;

delimiter **
create procedure modificaSA (in sa int (7), suc int (4), aut int (10))
begin 
update relSucursalesAutos
set sucursal=suc, auto=aut 
where idSA=sa;
end **
delimiter ;





##Trigger
create table historialEmpleadosDespedidos(
idHist1 int (4) auto_increment,
idEmp int (4),
nombre1 varchar (50),
ap varchar (50),
primary key (idHist1),
foreign key (idEmp) references empleados (idEmpleado)
);

create trigger empeli before delete on empleados
for each row
insert intohistorialEmpleadosDespedidos (idEmp, nombre1, ap) values (old.idEmpleado, old.nombre, old.apat);

##Nuevo usuario
create user iliana identified by 'n0m3l0nu3v0';

grant all privileges on PI2.* to 'iliana' with grant option;

create user vendedor identified by 'amomitrabajo';

grant insert, update, select on PI2.movimientos to 'vendedor' with grant option;

