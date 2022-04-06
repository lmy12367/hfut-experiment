--查询没有选修“0002”课程的学生姓名
select sname from student where sno not in (select sno from sc where cno='0002')

