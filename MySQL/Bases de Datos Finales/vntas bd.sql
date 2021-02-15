create database vntas;

use vntas;

create table productos(
idProducto int (11) zerofill auto_increment,
producto varchar (50),
costo float not null,
Primary Key (idProducto)
);

insert into productos values (1, 'libro', 500.25);
insert into productos values (2, 'celular', 6000.50);