
--��student���Sname���Ͻ�����ͨ��������Stusname
create index Stusname on student(sname desc)
 
--��course���Cname���Ͻ���Ψһ����Coucname
create unique index Coucname on course(cname)
 
--��sc���Sno(����), Cno(����)��grade (����)�����Ͻ���һ����ͨ����SCno
create index SCno on sc(Sno asc, Cno asc, grade desc)
 
--��鴴��������������
SELECT * FROM sys.sysindexes
