
--创建一个存储过程p_stu_grade,根据输入的学号，返回其选课及其成绩
create procedure p_stu_grade(@sno char(8)) as select * from sc where sno=@sno
go
