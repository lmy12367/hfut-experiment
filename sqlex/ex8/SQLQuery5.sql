
--查询平均成绩为90分及以上的学生学号、姓名和成绩
select student.sno, sname, avg from student, V_AVG_S_G where student.sno=V_AVG_S_G.sno and V_AVG_S_G.avg>=90
 