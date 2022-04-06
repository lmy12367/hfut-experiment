--查询选修课程超过2 门课的学生学号和姓名
select student.sno, sname sname from student, (select sno from sc group by sno having count(cno)>2) as new where student.sno=new.sno;