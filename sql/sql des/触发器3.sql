create trigger wage_update
on wage for update
as
begin
    if exists(select*from deleted
	where allo<whop)
	begin
	raiserror('不允许更新',16,8)
	rollback tran
	end
end