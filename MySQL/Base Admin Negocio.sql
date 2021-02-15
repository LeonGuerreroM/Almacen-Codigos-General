drop database if exists adminNegocio;
create database if not  exists adminNegocio;

use adminNegocio;

##Catálogos

create table catClases(
idClase int (3) auto_increment,
clase varchar (20),
Primary Key(idClase)
);

create table catTipoTransaccion(
idTT int (3) auto_increment,
tipo char (1),
Primary Key(idTT)
);

create table catTipoUsuarios(
idTU int (1) auto_increment,
tipo varchar (20),
Primary Key (idTU)
);

insert into catClases (clase) values ('Despensa');   
insert into catClases (clase) values ('Bebidas');   
insert into catClases (clase) values ('Baño');   
insert into catClases (clase) values ('Lavanderia');   

insert into catTipoTransaccion (tipo) values ('+');
insert into catTipoTransaccion (tipo) values ('-');

insert into catTipoUsuarios (tipo) values ('Administrador');
insert into catTipoUsuarios (tipo) values ('Vendedor');

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
precio int(6),
Primary Key (idProducto),
Foreign Key (idClase) references catClases (idClase) on update cascade on delete cascade
);

create table tblProveedor(
idProveedor int (3) auto_increment,
proveedor varchar (50),
ubicacion varchar (50),
Primary Key (idProveedor)
);

create table tblCliente(
idCliente int (2) auto_increment,
nombre varchar (30),
apellido varchar (30),
telefono int (10),
cantidad int (6),
Primary Key (idCliente)
);

create table tblMovimiento(
idMovimiento int (10) auto_increment,
cantidad int (6),
concepto varchar (50),
fecha TIMESTAMP DEFAULT CURRENT_TIMESTAMP,  
idTT int(3),
idCliente int (2),
Primary Key (idMovimiento),
foreign key (idCliente) references tblCliente (idCliente) on update cascade on delete cascade,
foreign key (idTT) references catTipoTransaccion (idTT) on update cascade on delete cascade
);

create table tblUsuario(
idUsuario int(3) auto_increment,
nombre varchar(50),
contrasenna varchar(50),
idTU int(1),
Primary Key (idUsuario),
foreign key (idTU) references catTipoUsuarios (idTU) on update cascade on delete cascade
);

create table tblVenta(
idVenta int (10) auto_increment,
idProducto int (4),
cantidad int (6),
fecha TIMESTAMP DEFAULT CURRENT_TIMESTAMP,  
idCliente int (2),
idTT int (3),
Primary Key (idVenta),
foreign key (idProducto) references tblProducto (idProducto) on update cascade on delete cascade,
foreign key (idCliente) references tblCliente (idCliente) on update cascade on delete cascade,
foreign key (idTT) references catTipoTransaccion (idTT) on update cascade on delete cascade
)ENGINE=INNODB;

create table tblHistPrecios(
idHP int(6) auto_increment,
idProducto int (4),
precio int(6),
fecha TIMESTAMP DEFAULT CURRENT_TIMESTAMP,
Primary key (idHP),
foreign key (idProducto) references tblProducto (idProducto) on update cascade on delete cascade
);

create table tblSurtido(
idSurtido int (6) auto_increment,
idProveedor int (3),
idProducto int (3),
cantidad int (6),
fecha TIMESTAMP DEFAULT CURRENT_TIMESTAMP,
Primary key (idSurtido),
foreign key (idProveedor) references tblProveedor(idProveedor),
foreign key (idProducto) references tblProducto(idProducto)
);

create table tblAPC(
idAPC int(3) auto_increment,
idProducto int(3),
Primary key (idAPC),
foreign key (idProducto) references tblProducto(idProducto)
);

create table tblListaNegra(
idListaN int(3) auto_increment,
idProducto int(3),
Primary key (idListaN),
foreign key (idProducto) references tblProducto(idProducto)
);

#create table tblRentables(
#idR int (3) auto_increment,
#idProducto int (3),
#Primary key (idR),
#foreign key (idProducto) references tblProducto(idProducto)
#);

##Relaciones
create table relProductoProveedor(
idPP int (6) auto_increment,
idProducto int (4),
idProveedor int (3),
precio int (6),
Primary Key(idPP),
foreign key (idProducto) references tblProducto (idProducto) on update cascade on delete cascade,
foreign key (idProveedor) references tblProveedor (idProveedor) on update cascade on delete cascade
)ENGINE=INNODB;


