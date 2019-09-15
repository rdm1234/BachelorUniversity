drop database if exists db_1_1;
create database db_1_1;
use db_1_1;

drop table if exists Книги;
drop table if exists Книги1;
drop table if exists Заказы;
drop table if exists Книги_заказа;

# 1
create table Книги(
	ISBN varchar(20) primary key,
	`ФИО автора` varchar(30) not null,
	`Название книги` varchar(30) not null,
	`Год издания` int not null,
	`Цена, руб.` int not null
);

create table Книги1 like Книги;

create table Заказы(
	`Номер заказа` int primary key,
	`Адрес доставки` varchar(100) not null,
	`Дата заказа` date not null,
	`Дата выполнения заказа` date
);

create table Книги_заказа(
	`Номер заказа` int,
	ISBN varchar(20),
	primary key (`Номер заказа`, ISBN),
	foreign key (`Номер заказа`) references Заказы(`Номер заказа`) on update cascade on delete no action,
	foreign key(ISBN) references Книги(ISBN) on update cascade on delete no action
);

# 3
insert into Книги(ISBN,`ФИО автора`, `Название книги`, `Год издания`, `Цена, руб.`)
values
	('978-5-388-00003', 'Иванов Сергей Степанович', 'Самоучитель JAVA', 2019, 300),
	('978-5-699-58103', 'Сидорова Ольга Юрьевна', 'JAVA за 21 день', 2019, 600);

insert into Книги1(ISBN,`ФИО автора`, `Название книги`, `Год издания`, `Цена, руб.`)
values
	('758-3-004-87105', 'Петров Иван Петрович', 'Сопрмат', 2018, 350),
	('758-3-057-37854', 'Иванов Сергей Степанович', 'Механика', 2018, 780),
	('675-3-423-00375', 'Петров Иван Петрович', 'Физика', 2017, 450);

insert into Заказы(`Номер заказа`, `Адрес доставки`, `Дата заказа`, `Дата выполнения заказа`)
values
	(123456, 'Малая Арнаутская ул., д.9, кв.16 Иванов Игорь', '2017-09-20', '2017-09-22'),
	(222334, 'Курчатов бульвар, д.33, кв.9, Петрова Светлана', '2017-09-21', null),
	(432152, 'Нахимовский проспект, д.12, кв.89 Васин Иван', '2018-09-21', '2018-03-23');

# 4 (находится здесь, поскольку Книги_заказа ссылаются (внешний ключ) 
# именно на Книги, а не на Книги1)
insert into Книги select * from Книги1;

# 3 продолжение
insert into Книги_заказа(`Номер заказа`, ISBN)
values
	(123456, '978-5-388-00003'),
	(123456, '978-5-699-58103'),
	(432152, '978-5-388-00003'),
	(222334, '978-5-388-00003'),
	(222334, '675-3-423-00375');

# 5
drop table Книги1;

# 6
update Заказы
	set `Дата заказа` = ADDDATE(`Дата заказа`, INTERVAL +1 YEAR)
	where YEAR(`Дата заказа`) = 2017;
	update Заказы
	set `Дата выполнения заказа` = ADDDATE(`Дата выполнения заказа`, INTERVAL +1 YEAR)
	where YEAR(`Дата выполнения заказа`) = 2017;

# 7
delete from Книги_заказа where `Номер заказа` = 432152;
delete from Заказы where `Номер заказа` = 432152;

# 8
select ISBN, `ФИО автора`, `Название книги`, `Цена, руб.`
	from Книги
	where `Цена, руб.` between 400 and 600;

# 9
set @num = 123456;
	select A.`Номер заказа`, A.`Адрес доставки`, A.`Дата заказа`, A.`Дата выполнения заказа`, B.ISBN, C.`Название книги`, C.`Цена, руб.`
	from Заказы as A
	inner join Книги_заказа as B on A.`Номер заказа` = B.`Номер заказа`
	inner join Книги as C on B.ISBN = C.ISBN
	where A.`Номер заказа` = @num;

# 10
select `Адрес доставки`, `Дата заказа`
	from Заказы 
	where `Дата выполнения заказа` is null;

# 11
select `ФИО автора`, count(*) as `Количество написанных книг`
	from Книги
	group by `ФИО автора`;

# 12
select (sum(days)/count(days)) as `Среднее время, дней`
	from (select DATEDIFF(`Дата выполнения заказа`, `Дата заказа`) as days from Заказы) as A;

# 13
select A.ISBN, `Название книги`, `Цена, руб.`, count(*) as `Количество заказов`
	from Книги_заказа as A
	inner join Книги as B on A.ISBN = B.ISBN
	group by A.ISBN;

# 14
select ISBN, `ФИО автора`, `Название книги`, max(`Цена, руб.`)
	from Книги;