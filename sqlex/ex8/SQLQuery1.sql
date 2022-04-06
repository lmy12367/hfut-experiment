create view V_sc_g
as 
select student.sno,sname,sc.cno,cname,grade from sc,student,course
	where sc.sno = student.sno and sc.cno=course.cno