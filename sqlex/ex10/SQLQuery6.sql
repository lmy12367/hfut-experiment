--����һ�����в����Ĵ洢����p_stu_info2��ʵ�ֶ�����Ҫ���ѧ��������Ϣ�Ĳ�ѯ
create procedure p_stu_info2(@sno char(8)) as select * from student where sage=(select sage from student where sno=@sno)
go

