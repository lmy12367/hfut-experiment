
--������ͼV_AVG_S_G������ͼ����ӳѧ��ѡ�޿γ̵�������ƽ���ɼ�
create view V_AVG_S_G(sno, count, avg) as select sno, count(*), avg(grade) from sc group by sno
go
