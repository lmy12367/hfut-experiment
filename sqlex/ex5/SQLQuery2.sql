
--在student表的Sname列上建立普通降序索引Stusname
create index Stusname on student(sname desc)
 
--在course表的Cname列上建立唯一索引Coucname
create unique index Coucname on course(cname)
 
--在sc表的Sno(升序), Cno(升序)和grade (降序)三列上建立一个普通索引SCno
create index SCno on sc(Sno asc, Cno asc, grade desc)
 
--检查创建索引的完成情况
SELECT * FROM sys.sysindexes
