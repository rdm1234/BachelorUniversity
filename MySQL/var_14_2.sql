drop database if exists var_14_2;
create database var_14_2;
use var_14_2;

drop table if exists Продукты;
drop table if exists Список_продуктов;
drop table if exists Накладные;

create table Продукты(
Номенклатурный_номер int primary key auto_increment,
Наименование_продукта varchar(20),
Единицы_измерения varchar(10)
);

alter table Продукты auto_increment = 100;

create table Накладные(
Номер_накладной int primary key,
Дата_оформления date,
Кому_Должность varchar(20),
Кому_ФИО varchar(30),
От_Должность varchar(20),
От_ФИО varchar(30)
);

create table Список_продуктов(
Номер_накладной int,
Номенклатурный_номер int,
Количество int,
Цена_за_ед int,
primary key (Номер_накладной, Номенклатурный_номер),
foreign key (Номенклатурный_номер) references Продукты(Номенклатурный_номер) on update cascade on delete cascade,
foreign key (Номер_накладной) references  Накладные(Номер_накладной) on update cascade on delete cascade
);

insert into Продукты(Наименование_продукта, Единицы_измерения)
values
('Картошка', 'кг'),
('Морковка', 'кг'),
('Свёкла', 'кг'),
('Сигареты', 'пачки'),
('Сок виноградный', 'литры'),
('Яблоки', 'кг');

insert into Накладные(Номер_накладной, Дата_оформления, Кому_должность, Кому_ФИО, От_должность, От_ФИО)
values
(1001, '2013-12-20', 'Зав.складом', 'Иванова С.П', 'Шеф повар', 'Сидоров П.В'),
(1002, '2014-01-23', 'Экспедитор', 'Фролов Ю.Б.', 'Зав.складом', 'Иванова С.П.');

insert into Список_продуктов(Номер_накладной, Номенклатурный_номер, Количество, Цена_за_ед)
values
(1001, 100, 20, 25),
(1001, 101, 5, 28),
(1001, 104, 12, 45),
(1001, 102, 3, 18),
(1002, 100, 120, 28),
(1002, 103, 100, 200);

drop user if exists 'administrator';
drop user if exists 'director';
drop user if exists 'worker';
drop user if exists 'visitor';

create user 'administrator' identified by 'adm_pass';
create user 'director' identified by 'dir_pass';
create user 'worker' identified by 'wor_pass';
create user 'visitor' identified by 'vis_pass';

grant all privileges on var_14_2.* to 'administrator';
revoke grant option on var_14_2.* from 'administrator';

grant all privileges on var_14_2.* to 'director';
revoke create, update, drop on var_14_2.* from 'director';

grant insert, delete, update, select on var_14_2.Продукты to 'visitor';
grant insert, delete, update, select on var_14_2.Накладные to 'visitor';

flush privileges;