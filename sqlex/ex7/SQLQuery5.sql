--��ѯѡ�޿γ̳���2 �ſε�ѧ��ѧ�ź�����
select student.sno, sname sname from student, (select sno from sc group by sno having count(cno)>2) as new where student.sno=new.sno;