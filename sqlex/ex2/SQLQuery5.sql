create table student1(
sno char(8) primary key,
sname varchar(10) not null,
ssex  char(2) check(ssex in ('ÄĞ', 'Å®')),
clsNO char(6) references class(clsNo),
saddr varchar(20),
sage int check(sage between 10 and 40),
height numeric(4, 2))
alter table student1 add s_entrance datetime
alter table student1 alter column saddr varchar(40)
