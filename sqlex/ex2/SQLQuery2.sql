
create table student(
sno char(8) primary key,
sname varchar(10) not null,
ssex  char(2) check(ssex in ('ÄÐ', 'Å®')),
clsNO char(6) references class(clsNo),
saddr varchar(20),
sage int check(sage between 10 and 30),
height numeric(4, 2))