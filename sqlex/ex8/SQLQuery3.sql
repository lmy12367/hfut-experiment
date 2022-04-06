
--定义视图V_AVG_S_G：该视图将反映学生选修课程的门数及平均成绩
create view V_AVG_S_G(sno, count, avg) as select sno, count(*), avg(grade) from sc group by sno
go
