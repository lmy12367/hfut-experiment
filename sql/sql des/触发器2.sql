create trigger att_update
on attendance for update
as
begin
    if exists(select*from deleted where atd<tdd)
	begin
	raiserror('不允许更新',16,8)
	rollback tran
	end
end