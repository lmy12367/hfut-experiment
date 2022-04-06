
--在班级表class中增加班级人数（c_total）字段
alter table class add c_total int default 0
go
 
--修改c_total的值
update class set c_total=(select count(*) from student where class.clsNO=student.clsNO)
go
