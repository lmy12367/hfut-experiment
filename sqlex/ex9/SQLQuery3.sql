
--Ϊѧ����(student)����INSERT������t_inst_stu������һ��ѧ��ʱ������༶��ŷǿգ��򽫰༶��class������Ӧ�༶��������c_total���Զ���1
create trigger t_inst_stu
on student after insert as
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
end
go

