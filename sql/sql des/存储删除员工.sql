create procedure delete_stanum
@stanum char(8)
as begin
	delete from attendance where attendance.stanum=@stanum
	delete from staff where staff.stanum=@stanum
	delete from users where users.stanum=@stanum
	delete from wage where wage.stanum=@stanum
end