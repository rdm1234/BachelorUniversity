drop database if exists var_14_3;
create database var_14_3;
use var_14_3;

drop table if exists Трассы;
drop table if exists Водители;
drop table if exists Результаты;
drop table if exists not_normalized;

create table Трассы(
	Номер int primary key auto_increment,
	Месторасположение varchar(30),
	Протяженность int
);

create table Водители(
	Номер int primary key auto_increment,
	ФИО varchar(50),
	Марка_автомобиля varchar(40)
);

create table Результаты(
	Номер_водителя int,
	Номер_трассы int,
	primary key(Номер_водителя, Номер_трассы),
	Время_прохождения_трассы int,
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

create table not_normalized as select 
T.Номер as `№ трассы`, T.Месторасположение as `Месторасположение трассы`, T.Протяженность as `Протяженность км`, V.Номер as `№ водителя`, V.ФИО as `ФИО Водители`, V.Марка_автомобиля as `Марка автомобиля`, R.Время_прохождения_трассы as `Время прохождения трассы, мин`
from (Результаты as R
inner join Трассы as T on R.Номер_трассы = T.Номер)
right join Водители as V on R.Номер_водителя = V.Номер
order by R.Номер_трассы, V.Номер;

select * from not_normalized;
delete from Результаты;
delete from Трассы;
delete from Водители;

# заданеие 4
DELIMITER // ;

CREATE PROCEDURE FILL()
BEGIN
	DECLARE is_end INT DEFAULT 0;
	DECLARE `№ трассы1` int;
	DECLARE `Месторасположение трассы1` varchar(30);
	DECLARE `Протяженность км1` int;
	DECLARE `№ водителя1` int;
	DECLARE `ФИО Водители1` varchar(50);
	DECLARE `Марка автомобиля1` varchar(40);
	DECLARE `Время прохождения трассы, мин1` int;

	DECLARE CURFILL CURSOR FOR SELECT * FROM not_normalized;
	DECLARE CONTINUE HANDLER FOR NOT FOUND SET is_end = 1;

	OPEN CURFILL;
	DELETE FROM Водители;
	wet : LOOP
		FETCH CURFILL INTO `№ трассы1`, `Месторасположение трассы1`, `Протяженность км1`, `№ водителя1`, `ФИО Водители1`, `Марка автомобиля1`, `Время прохождения трассы, мин1`;
		IF is_end THEN LEAVE wet;
		END IF;
		DELETE FROM Водители WHERE `№ водителя1` = Водители.Номер and `ФИО Водители1`=Водители.ФИО and `Марка автомобиля1`=Водители.Марка_автомобиля;
		INSERT INTO Водители VALUES (`№ водителя1`, `ФИО Водители1`, `Марка автомобиля1`);



		#DELETE FROM not_normalized WHERE `№ трассы1` = `№ трассы` and `Месторасположение трассы1` = `Месторасположение трассы` and `Протяженность км` = `Протяженность км1`;
		#DELETE FROM Трассы WHERE `№ трассы1` = Трассы.Номер and `Месторасположение трассы1` = Трассы.Месторасположение and `Протяженность км1` = Трассы.Протяженность;
		#INSERT INTO Трассы VALUES (`№ трассы1`, `Месторасположение трассы1`, `Протяженность км1`);

		#DELETE FROM not_normalized WHERE `№ водителя1` = `№ водителя` and `№ трассы1` = `№ трассы` and `Время прохождения трассы, мин1` = `Время прохождения трассы, мин`;
		#INSERT INTO Результаты VALUES (`№ водителя1`, `№ трассы1`, `Время прохождения трассы, мин1`);
		#DELETE FROM not_normalized WHERE `№ водителя` = `№ водителя1` and `ФИО Водители1`=`ФИО Водители` and `Марка автомобиля1`=`Марка автомобиля`;
		

	END LOOP wet;
END//

CALL FILL()//
select * from not_normalized;

SELECT *FROM Трассы//
SELECT *FROM Водители//
SELECT *FROM Результаты//
