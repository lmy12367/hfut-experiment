
--����һ����ӳѧ��������ݵ���ͼV_YEAR������ͼҪ��ʹ��ϵͳ������YEAR(),GETDATE()������ȡ��ǰ���ڼ�ת��
create view V_YEAR(sno, birth) as select sno, year(getdate())-sage from student
go

