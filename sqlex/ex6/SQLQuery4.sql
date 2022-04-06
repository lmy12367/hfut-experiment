--查询选修课程“0001”且成绩在80～90 之间的学生学号和成绩，并将成绩乘以系数0.75 输出
select sno, grade*0.75 from sc where cno='0001' and grade between 80 and 90