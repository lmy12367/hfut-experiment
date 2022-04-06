use EDUC

delete
from student
where
	sAge < 20 and
	clsNO = 'CS02'

select * from student