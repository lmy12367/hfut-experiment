create index attone on attendance(stanum desc)
create index dutyone on duty(dtnum desc)
create index staffone on staff(stanum desc)
create index dephone on department(depnum desc)
create index wageone on wage(stanum desc)
create index userone on users(users_name desc)
SELECT * FROM sys.sysindexes