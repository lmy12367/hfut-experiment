
--Ϊѧ����(student)����UPDATE������t_update_stu:��ĳѧ�����ڰ�ŷ����仯ʱ����������һ�༶�󣩣�����ԭ�����ڰ༶��������c_total����1�����µ���İ༶�༶��������c_total����1
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

