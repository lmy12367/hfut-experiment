
--����һ���洢����p_stu_info3,���������ѧ�ţ���ѯĳѧ���Ļ�����Ϣ
create procedure p_stu_info3(@sno char(8)) as select * from student where sno=@sno
go
