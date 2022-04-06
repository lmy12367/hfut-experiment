create view v_avg_c_g
as 
select cname,count(sno) cnum,avg(grade) c_grade from sc,course
where sc.cno =course.cno
group by cname