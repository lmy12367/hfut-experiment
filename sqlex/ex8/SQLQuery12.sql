
--查询2000年出生的学生学号和姓名
select student.sno, sname from student, V_YEAR where student.sno=V_YEAR.sno and V_YEAR.birth=2000
