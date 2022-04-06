--查询“计算机应用”专业的学生学号和姓名
select sno, sname from student, class where student.clsNO=class.clsNo and class.Specialty='计算机应用'
 