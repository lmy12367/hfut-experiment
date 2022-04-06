create procedure new_users
@users_name char(8),
@passwords varchar(10),
@aut numeric(2,0),
@stanum char(8)
as begin
	insert into users values (@users_name,@passwords,@aut,@stanum)
end