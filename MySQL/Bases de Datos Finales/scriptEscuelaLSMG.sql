##Leon Sergio Mora Guerrero 4IM9






create database escuela;

create table alumnos(
idAlumno int (11),
nombre varchar (50),
paterno varchar (50),
fecreg DATETIME default "2016-04-16 00:00:00",
Primary Key (idAlumno));

create table tipoContactos(
idContacto int (11),
contacto varchar (50),
Primary Key (idContacto));

create table relAlumnoContacto(
idRel int (11),
Primary Key (idRel),
foreign key (idAlumno) references alumnos,
foreign key (idContacto) references tipoContactos);



##Procesos de tabla Alumnos
Delimiter //
create procedure altalumnos (in idAlumnoM int (11), nombreM varchar (50), paternoM varchar (50), fecha datetime )
begin
insert into alumnos (idAlumno, nombre, paterno, fecreg) values (idAlumnoM, nombreM, paternoM, fecha);
end
//

Delimiter //
create procedure actualumnos (in idAlumnoM int (11), nombreM varchar (50), paternoM varchar (50), fecha datetime)
begin
	update alumnos
	set nombre= nombreM, paterno = paternoM, fecreg = fecha
    where idAlumno = idAlumnoM;
end
//

Delimiter //
create procedure borralumnos (in idAlumnoM int)
begin
   delete from alumnos where idAlumno=idAlumnoM;
end
//


call altalumnos (123456789, 'itzel', 'teran', '2000-05-12 01:11:24');
call altalumnos (910111213, 'Monica', 'alvarez', '2000-05-12 01:11:14');
select * from alumnos;

call actualumnos (1234567890, 'Yessica', 'santana', '2016-01-28');
select * from alumnos;

call borralumnos (1234567890);
select * from alumnos;


##Procesos Contacto
Delimiter //
create procedure altacontacto (in idContactoM int (11), contactoM varchar (50))
begin
	insert into tipoContactos (idContacto, contacto) values (idContactoM, contactoM);
end
//

Delimiter //
create procedure actualicon (in idContactoM int (11), contactoM varchar (50))
begin
	update tipoContactos
	set contacto = contactoM
    where idContacto = idContactoM;
end
//

Delimiter //
create procedure borracon (in idContactoM int)
begin
   delete from tipoContactos where idContacto = idContactoM;
end
//


call altacontacto (222222222, 'CA');
call altacontacto (333333333, 'CB');
select * from tipoContactos;

call actualicon (222222222, 'Contacto CC');
select * from tipoContactos;

call borracon (222222222);
select * from tipoContactos;



##Procesos de relacion

Delimiter //
create procedure newRel (in idRelM int (11), idAlumnoM int (11), idContactoM int (11))
begin
	insert into relAlumnoContacto (idRel, idAlumno, idContacto) values (idRelM, idAlumnoM, idContactoM);
end
//

Delimiter //
create procedure actualizarel (in idRelM int (11), idAlumnoM int (11), idContactoM int (11))
begin
	update relAlumnoContacto
	set idAlumno = idAlumnoM, idContacto = idContactoM
    where idRel = idRelM;
end
//

Delimiter //
create procedure borel (in idRelM int)
begin
   delete from relAlumnoContacto where idRel = idRelM;
end
//


call newrel (000000001, 123456789, 222222222);
call newrel (000000002, 910111213, 333333333);
select * from relAlumnoContacto;

call actualizarel (000000003, 910111213, 222222222);
select * from relAlumnoContacto;

call borel (000000002);
select * from relAlumnoContacto;

