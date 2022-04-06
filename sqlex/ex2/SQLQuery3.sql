--´´½¨course±í
create table course(
cno char(4) primary key,
cname varchar(16) not null,
cpno char(4) references course(cno),
Ccredit numeric(2, 1))
