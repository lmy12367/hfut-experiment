create trigger att_insert
on attendance for insert
as
begin
    if exists(select*from inserted 
	where atd<tdd)
	begin
	raiserror('���������',16,8)
	rollback tran
	end
end