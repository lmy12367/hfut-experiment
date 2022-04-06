create procedure c_new_staff
@stanum char(8),@staname varchar(10),@stasex char(2),@dtnum char(4),@wbk numeric(2,0),@depnum char(4),
@bw numeric(5,2)
as begin
	declare @notp varchar(14)
	select @notp=notp from duty where dtnum=@dtnum
	insert into staff values (@stanum,@staname,@stasex,@notp,@dtnum,'0',@wbk,@depnum)
	insert into wage values (@stanum,@notp,@bw,'0','0','0')
end