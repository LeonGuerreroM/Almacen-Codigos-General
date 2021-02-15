create database mascotas2;

use mascotas2; 

create table animales (
		idMascota int (3), 
        idDueño int (3),
        nombre varchar (20),
        tipo varchar (20),
        raza varchar (20), 
        peso float (4,2), 
        sexo varchar (20), 
        color varchar (20),
        precioCompra float (4,1),
        foreign key (idDueño) references dueños (idDueño),
        primary key (idMascota)
        );
        
create table vacunas(
		 idVacuna int (2), 
         idMascota int (3),
         fechaVac date,
         descripción varchar (20), 
         veterinario varchar (20),
         primary key (idVacuna),
         foreign key (idMascota) references animales (idMascota));
         
create table dueños(
		idDueño int not null auto_increment,
        idMascota int (3),
        nombre varchar (50),
        clave varchar (50),
        edad int (2),
        Primary Key (idDueño)
        );
        
   call InsertaDueño ('Fer','hola1', 17); 
   call InsertaDueño ('Eli','hola', 19);
   select * from dueños;
        
delimiter **
create procedure InsertaDueño (in nombre1 varchar (50) , clave1 varchar (50), edad1 int (2))
begin
insert into dueños (nombre, clave, edad) values (nombre1, md5('clave1'), edad1);
end
 **

call InsertaDueño ('Eli','hola', 19);

delimiter **
create procedure MostrarDueño (in nombre1 varchar (50), clave1 varchar (50))
begin
select * from dueños where nombre=nombre1 and clave=md5('clave1');
end
**

call MostrarDueño ('Fer', 'Hola2');
