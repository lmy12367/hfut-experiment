--��ѯ�������Ӧ�á�רҵ��ѧ��ѧ�ź�����
select sno, sname from student, class where student.clsNO=class.clsNo and class.Specialty='�����Ӧ��'
 
--��ѯѡ���˿γ̵�ѧ��ѧ��
select sno from sc where sno is not null

--��ѯѡ�޿γ̡�0001���ҳɼ���80��90 ֮���ѧ��ѧ�źͳɼ��������ɼ�����ϵ��0.75 ���
select sno, grade*0.75 from sc where cno='0001' and grade between 80 and 90

--��ѯ�������Ӧ�á��͡���ѧ��רҵ���ա��š���ѧ������Ϣ��
select *from student,class
	where sname like '��'and
		student.clsNO=class.clsNO and
		(Specialty = '�����Ӧ��' or Specialty ='��ѧ')
--��ѯ��0001���γ̵ĳɼ����ڡ���������ѧ��ѧ�źͳɼ�
select sno, grade from sc where cno='0001' and grade>(select grade from sc, student where sc.sno=student.sno and student.sname='���' and sc.cno='0001')
 
--��ѯû��ѡ�ޡ�0002���γ̵�ѧ������
select sname from student where sno not in (select sno from sc where cno='0002')
