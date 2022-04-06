--查询“计算机应用”专业的学生学号和姓名
select sno, sname from student, class where student.clsNO=class.clsNo and class.Specialty='计算机应用'
 
--查询选修了课程的学生学号
select sno from sc where sno is not null

--查询选修课程“0001”且成绩在80～90 之间的学生学号和成绩，并将成绩乘以系数0.75 输出
select sno, grade*0.75 from sc where cno='0001' and grade between 80 and 90

--查询“计算机应用”和“数学”专业的姓“张”的学生的信息。
select *from student,class
	where sname like '张'and
		student.clsNO=class.clsNO and
		(Specialty = '计算机应用' or Specialty ='数学')
--查询“0001”课程的成绩高于“张三”的学生学号和成绩
select sno, grade from sc where cno='0001' and grade>(select grade from sc, student where sc.sno=student.sno and student.sname='李杰' and sc.cno='0001')
 
--查询没有选修“0002”课程的学生姓名
select sname from student where sno not in (select sno from sc where cno='0002')
