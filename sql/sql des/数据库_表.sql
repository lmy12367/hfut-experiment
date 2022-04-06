create table staff(
	stanum char(8) primary key,
	staname varchar(20) not null,
	stasex char(2) check(stasex in ('ÄĞ','Å®')),
	dtnum char(4),
	wyear numeric(2,0) check(wyear>=1 and wyear<=99),
	wbk numeric(2,0) check(wbk>=1 and wbk<=10),
	depnum char(4)
);
create table department(
	depnum char(4) primary key,
	depname varchar(14) not null,
	mgnum char(8),
	mgname varchar(10)
);
create table attendance(
	stanum char(8) primary key,
	atd numeric(2,0) check(atd>=0 and atd<=30),
	otd numeric(2,0) check(otd>=0 and otd<=30),
	tdd numeric(2,0) check(tdd>=0 and tdd<=30)
);
create table duty(
	dtnum char(4) primary key,
	notp varchar(30)
);
create table wage(
	stanum char(8) primary key,
	bw int,
	allo float,
	whop float,
	pm float
);
create table users(
	users_name char(8),
	passwords varchar(10),
	aut numeric(2,0) check(aut>=1 and aut<=10),
	stanum char(8)
);