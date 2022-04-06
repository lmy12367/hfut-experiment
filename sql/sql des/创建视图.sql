create view e_xo_ne(stanum,depnum,atd,otd,tdd,bw,allo,whop,pm)
as
select staff.stanum,department.depnum,attendance.atd,attendance.otd,attendance.tdd,duty.bw,wage.allo,wage.whop,wage.pm
from staff,department,attendance,duty,wage

