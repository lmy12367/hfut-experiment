--创建一个带有参数的存储过程p_stu_info2，实现对满足要求的学生基本信息的查询
create procedure p_stu_info2(@sno char(8)) as select * from student where sage=(select sage from student where sno=@sno)
go

