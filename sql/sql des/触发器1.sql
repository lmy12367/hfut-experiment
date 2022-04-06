create trigger att_insert
on attendance for insert
as
begin
    if exists(select*from inserted 
	where atd<tdd)
	begin
	raiserror('²»ÔÊĞí²åÈë',16,8)
	rollback tran
	end
end