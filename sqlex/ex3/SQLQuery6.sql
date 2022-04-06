use EDUC

update student
set clsNO = 'CS02'
where
	clsNO = 'CS01' and
	sAge < 20

select * from student