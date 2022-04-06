
--创建一个不带参数的存储过程p_stu_info1，实现对满足要求的学生基本信息的查询
create procedure p_stu_info1 as select * from student where sage<21
go
