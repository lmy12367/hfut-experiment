create trigger wage_update
on wage for update
as
begin
    if exists(select*from deleted
	where allo<whop)
	begin
	raiserror('���������',16,8)
	rollback tran
	end
end