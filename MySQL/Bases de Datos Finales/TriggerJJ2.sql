
create database T2;

use T2;


create table rJJ(
idJJ int not null auto_increment,
idJuego int (6),
idJugador varchar (20),
Dinero int (11),
usuario varchar (50),
fecha datetime,
Primary Key (idJJ)
);

insert into rJJ values (1, 111111, 'jug', 2312397);

create table h1(
idH int not null auto_increment,
idJuegoH int (6),
idJugadorH varchar (20),
useri varchar (50),
fechaH datetime,
Primary Key (idH)
);


create trigger mpt after insert on rJJ
for each row
insert into h1 (idJuegoH, idJugadorH, useri, fechaH) values (new.idJuego, new.idJugador, USER(), NOW());

select * from rJJ;

insert into rJJ values (5, 171941, 'kjnjk', 2316789);

select * from h1;