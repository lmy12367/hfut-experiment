
create unique index staffex on staff(stanum)
create unique index departmentex on department(depnum)
create unique index attendanceex on attendance(stanum)
create unique index dutyex on duty( dtnum)
create unique index wageex on wage(stanum)
create unique index usersex on users(users_name)

SELECT * FROM sys.sysindexes
