select sno,sc.cno,grade,c_grade from v_avg_c_g,sc,course
where sc.cno = course.cno and
	course.cname =v_avg_c_g.cname
	and sc.grade>v_avg_c_g.c_grade