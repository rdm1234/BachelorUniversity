drop database if exists var_14_3;
create database var_14_3;
use var_14_3;

drop table if exists Трассы;
drop table if exists Водители;
drop table if exists Результаты;
drop table if exists temp;

create table Трассы(
	Номер int primary key auto_increment,
	Месторасположение varchar(30) not null,
	Протяженность int not null
);

create table Водители(
	Номер int primary key auto_increment,
	ФИО varchar(50) not null,
	Марка_автомобиля varchar(40) not null
);

create table Результаты(
	#Номер int primary key auto_increment,
	Номер_водителя int,
	Номер_трассы int,
	Время_прохождения_трассы int,
primary key (Номер_водителя, Номер_трассы),
foreign key (Номер_водителя) references Водители(Номер) on update cascade on delete no action,
foreign key (Номер_трассы) references Трассы(Номер) on update cascade on delete no action
);

insert into Трассы(Месторасположение, Протяженность) values
	('Карелия', 60),
	('Тверь', 40),
	('Московская область', 30);

insert into Водители(ФИО, Марка_автомобиля) values
	('Семен Варламов', 'Гран Чекори'),
	('Евгений Мальчиков', 'ЛендКрузер'),
	('Вячеслав Войнов', 'Шевроле Нива'),
	('Дмитрий Мальчиков', 'РенджРовер'),
	('Роман Граборенко', 'ЛендКрузер');

insert into Результаты(Номер_водителя, Номер_трассы, Время_прохождения_трассы) values
	(1, 1, 169),
	(3, 1, 178),
	(4, 1, 185),
	(2, 2, 131),
	(4, 2, 123),
	(1, 3, 118),
	(2, 3, 124),
	(3, 3, 119),
	(4, 3, 125);

create view temp as select 
T.Номер as `№ трассы`, T.Месторасположение as `Месторасположение трассы`, T.Протяженность as `Протяженность км`, V.Номер as `№ водителя`, V.ФИО as `ФИО Водители`, V.Марка_автомобиля as `Марка автомобиля`, R.Время_прохождения_трассы as `Время прохождения трассы, мин`
from (Результаты as R
inner join Трассы as T on R.Номер_трассы = T.Номер)
right join Водители as V on R.Номер_водителя = V.Номер
order by  R.Номер_трассы, V.Номер;
select * from temp;