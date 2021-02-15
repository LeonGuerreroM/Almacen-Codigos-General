
create database T1;

use T1;


create table rJJ(
idJJ int (1),
idJuego int (6),
idJugador varchar (20),
Dinero int (11),
Primary Key (idJJ)
);

insert into rJJ values (1, 111111, 'jug', 2312397);

create table h1(
idH int not null auto_increment,
idJuegoH int (6),
idJugadorH varchar (20),
Primary Key (idH)
);


create trigger mpt after insert on rJJ
for each row
insert into h1 (idJuegoH, idJugadorH) values (new.idJuego, new.idJugador);

insert into rJJ values (5, 171941, 'kjnjk', 2316789);

select * from h1;