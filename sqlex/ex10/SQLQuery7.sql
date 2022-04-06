
--创建一个存储过程p_stu_info3,根据输入的学号，查询某学生的基本信息
create procedure p_stu_info3(@sno char(8)) as select * from student where sno=@sno
go
