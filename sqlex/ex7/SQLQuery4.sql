--查询课程的课程号和选修该课程的人数
select cno, count(*) from sc group by cno
 