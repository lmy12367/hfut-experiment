
--为学生表(student)创建DELETE触发器t_dele_stu：删除一名学生时，若其班级编号非空，则将班级表（class）中相应班级的人数（c_total）自动减1
create trigger t_dele_stu
on student after delete as
begin
	declare @clsNO char(6);
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
go
