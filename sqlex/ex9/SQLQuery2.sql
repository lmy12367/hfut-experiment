
--�ڰ༶��class�����Ӱ༶������c_total���ֶ�
alter table class add c_total int default 0
go
 
--�޸�c_total��ֵ
update class set c_total=(select count(*) from student where class.clsNO=student.clsNO)
go
