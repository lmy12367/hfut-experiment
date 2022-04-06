
--定义一个反映学生出生年份的视图V_YEAR，该视图要求使用系统函数（YEAR(),GETDATE()）来获取当前日期及转换
create view V_YEAR(sno, birth) as select sno, year(getdate())-sage from student
go

