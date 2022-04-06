create database lmydb
on
(name=EDUC,
filename='D:\2018214937liumingyuan\lmy.mdf',
size=10,
maxsize=60,
filegrowth=5%)
log on
(name=EDUC_log,
filename='D:\2018214937liumingyuan\lmy.ldf',
size=4,
maxsize=10,
filegrowth=1)
