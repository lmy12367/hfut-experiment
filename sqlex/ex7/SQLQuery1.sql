
--��ѯѧ����������
select count(*) from student
 
--��ѯѡ���˿γ̵�ѧ������
select count(*) from (select sno from sc group by sno) as new
 
--��ѯ�γ̵Ŀγ̺ź�ѡ�޸ÿγ̵�����
select cno, count(*) from sc group by cno
 
--��ѯѡ�޿γ̳���2 �ſε�ѧ��ѧ�ź�����
select student.sno, sname sname from student, (select sno from sc group by sno having count(cno)>2) as new where student.sno=new.sno;
