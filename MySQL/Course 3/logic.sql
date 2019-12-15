drop database if exists logic;
create database logic;
use logic;

create table var12_bool(
	A boolean null,
	B boolean null,
	C boolean null,
	F boolean null
);

create table var12_char(
	A varchar(1),
	B varchar(1),
	C varchar(1),
	F varchar(1)
);

delimiter $$

# Процедура для преобразования boolean null к char(1) (0, 1, null -> F, T, U)
create procedure 3boolToChar(in value boolean, inout newValue char(1))
begin
	if value = 0 then set newValue = 'F';
	elseif value = 1 is true then set newValue = 'T';
	else set newValue = 'U';
	end if;
end $$

# Процедура для заполнения таблиц
create procedure fillABC()
begin
	DECLARE a boolean;
	DECLARE b boolean;
	DECLARE c boolean;
	DECLARE f boolean;
	DECLARE aCh char(1);
	DECLARE bCh char(1);
	DECLARE cCh char(1);
	DECLARE fCh char(1);
	# Используются для инкрементации
	set @i = 0;
	set @j = 0;
	set @t = 0;
	WHILE (@i < 27) DO
		# от 0 до 9: a = False
		IF @i < 9
			THEN set a = false;
		# от 9 до 18: a = True
		ELSEIF @i >= 9 AND @i < 18
			THEN set a = true;
		# от 9 до 27: a = NULL (Unknown)
		ELSE
			set a = NULL;
		END IF;

		# от 0 до 3: b = False
		IF @j < 3
			THEN set b = false;
		# от 3 до 6: b = True
		ELSEIF (@j >= 3 AND @j < 6)
			THEN set b = true;
		# от 6 до 9: b = NULL (Unknown)
		ELSEIF (@j >= 6 AND @j < 8) THEN
			set b = NULL;
		ELSE
			set b = NULL;
			set @j = -1;
		END IF;

		# если t == 0: c = False
		IF @t < 1 then 
			set c = false;
		# если t == 1: c = True
		ELSEIF (@t < 2) then 
		    set c = true;
	    # если t == 2: c = NULL (Unknown)
		ELSE
			set c = NULL;
			set @t = -1;
		END IF;

		# вычисление F
        set f = (a && b && (not c));

		insert into var12_bool(A, B, C, F) values (a, b, c, f);

		# приведение bool значений к виду T, F, U
		call 3boolToChar(a, aCh);
		call 3boolToChar(b, bCh);
		call 3boolToChar(c, cCh);
		call 3boolToChar(f, fCh);

		insert into var12_char(A, B, C, F) values (aCh, bCh, cCh, fCh);

		SET @i = @i + 1;
		SET @j = @j + 1;
		SET @t = @t + 1;
	END WHILE;
end $$

delimiter ;

call fillABC();

select * from var12_bool;
select * from var12_char;

# Онлайн тест данного кода
# https://paiza.io/projects/5ljeCkt_KVY5RFwkFSo33w?language=mysql