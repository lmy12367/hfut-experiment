--向course中插入数据
insert into course values('0001', '高等数学', Null, 6)
insert into course values('0002', '计算机基础', '0001', 3)
insert into course values('0003', '物理', '0001', 4)
insert into course values('0004', '数据结构', '0001', 4)
insert into course values('0005', 'java', '0002', 4)
insert into course values('0006', '汇编', '0003', 4)
insert into course values('0007', '大学物理', '0008', 4)
insert into course values('0009', '毛概', '0001', 4)
insert into course values('0008', '近代史', '0001', 4)
insert into course values('0010', '计租', '0001', 4)
insert into course values('0011', '操作系统', '0001', 4)
insert into course values('0012', '数据库', '0001', 4)
insert into course values('0013', '用户节', '0001', 4)


 
--检验插入效果
select * from course
