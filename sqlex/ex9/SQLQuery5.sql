
--为学生表(student)创建UPDATE触发器t_update_stu:当某学生所在班号发生变化时（即调到另一班级后），将其原先所在班级的人数（c_total）减1，将新调入的班级班级的人数（c_total）加1
create trigger t_update_stu
on student after update as
begin
	declare @clsNO char(6);
	declare cur cursor fast_forward for select clsNO from inserted;
	open cur;
	fetch next from cur into @clsNO;
	while @@fetch_status=0
	begin
		if(@clsNO is not null)
			update class set c_total=c_total+1 where clsNO=@clsNO;
		fetch next from cur into @clsNO;
	end
	close cur;
	deallocate cur;
	declare cur cursor fast_forward for select clsNO from deleted;
	open cur;
	fetch next from cur into @clsNO;
	while @@fetch_status=0
	begin
		if(@clsNO is not null)
			update class set c_total=c_total-1 where clsNO=@clsNO;
		fetch next from cur into @clsNO;
	end
	close cur;
	deallocate cur;
end

