drop database if exists tienda;
create database if not  exists tienda;

use tienda;
select * from tblProducto;

##Catálogos

create table catClases(
idClase int (3) auto_increment,
clase varchar (20),
Primary Key(idClase)
)ENGINE=INNODB;

insert into catClases (clase) values ('Despensa');   
insert into catClases (clase) values ('Bebidas');   
insert into catClases (clase) values ('Baño');   
insert into catClases (clase) values ('Lavanderia');   

insert into tblCuenta (cuenta, cantidad) values ("Darcy,",1000);
insert into tblCuenta (cuenta, cantidad) values ("Marsault,",0);
insert into tblCuenta (cuenta, cantidad) values ("Clyde,",2000000);

##Tablas

create table tblProducto(
idProducto int (4) auto_increment,
nombre varchar (30),
tipo varchar (20),
marca varchar (30),
idClase int (3),
subclase varchar (30),
tamanio varchar (20),
cantidad int(3),
Primary Key (idProducto),
Foreign Key (idClase) references catClases (idClase) on update cascade on delete cascade
)ENGINE = INNODB;

create table tblProveedor(
idProveedor int (3) auto_increment,
proveedor varchar (50),
Primary Key (idProveedor)
)ENGINE=INNODB;

create table tblCuenta(
idCuenta int (2) auto_increment,
cuenta varchar (30),
cantidad int (6),
Primary Key (idCuenta)
)ENGINE=INNODB;

create table tblMovimiento(
idMovimiento int (10) auto_increment,
cantidad int (6),
concepto varchar (50),
fecha TIMESTAMP DEFAULT CURRENT_TIMESTAMP,  
idCuenta int (2),
Primary Key (idMovimiento),
foreign key (idCuenta) references tblCuenta (idCuenta) on update cascade on delete cascade
)ENGINE=INNODB;

##Relaciones
create table relProductoProveedor(
idPP int (6) auto_increment,
idProducto int (4),
idProveedor int (3),
precio int (4),
Primary Key(idPP),
foreign key (idProducto) references tblProducto (idProducto) on update cascade on delete cascade,
foreign key (idProveedor) references tblProveedor (idProveedor) on update cascade on delete cascade
)ENGINE=INNODB;

create table tblVenta(
idVenta int (10) auto_increment,
idPP int (6),
cantidad int (6),
fecha TIMESTAMP DEFAULT CURRENT_TIMESTAMP,  
idCuenta int (2),
Primary Key (idVenta),
foreign key (idPP) references relProductoProveedor (idPP) on update cascade on delete cascade,
foreign key (idCuenta) references tblCuenta (idCuenta) on update cascade on delete cascade
)ENGINE=INNODB;
