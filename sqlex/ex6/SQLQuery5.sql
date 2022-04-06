--查询“计算机应用”和“数学”专业的姓“王”的学生的信息。
select student.*,Sname from student,class where student.clsNO=class.clsNO and Specialty
in ('计算机应用' , '数学')and sname like '王%';
