
--查询学生的总人数
select count(*) from student
 
--查询选修了课程的学生人数
select count(*) from (select sno from sc group by sno) as new
 
--查询课程的课程号和选修该课程的人数
select cno, count(*) from sc group by cno
 
--查询选修课程超过2 门课的学生学号和姓名
select student.sno, sname sname from student, (select sno from sc group by sno having count(cno)>2) as new where student.sno=new.sno;
