
--����һ���洢����p_stu_grade,���������ѧ�ţ�������ѡ�μ���ɼ�
create procedure p_stu_grade(@sno char(8)) as select * from sc where sno=@sno
go
