--查询选修了课程的学生人数
select count(*) from (select sno from sc group by sno) as new
 