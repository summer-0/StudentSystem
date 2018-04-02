# include <stdio.h>
# include <conio.h>
# include <stdlib.h>
# include <windows.h>
# include <malloc.h>
# include <string.h>

//������������*************************
void MainOperate(); //������
void AdminLoginFace();  //����Ա������
void AdminRegister(struct Adminer * );//����Աע��
void AdminLogin(struct Adminer * );  //����Ա��¼
void AdminSucceed();  //����Ա��¼�ɹ�

void StudentLoginFace();//ѧ��������
void StudentLogin(struct Studenter * );//ѧ����¼
void StudentRegister(struct Studenter * );//ѧ��ע��
void StudentSucceed(char str[]);  //ѧ����¼�ɹ�

void StudentScoreEnter();      //ѧ���ɼ�¼��
void StudentScoreManage();    //ѧ���ɼ�����

void addScore();   //���ѧ���ɼ�
void deleteScore(); //ɾ��ѧ���ɼ�
void modifyScore(); //�޸�ѧ���ɼ�
void lookAllScore(); //�鿴����ѧ���ɼ�
void sortScore();   //�ɼ�����

void scoreSeek(char str[]);      //�ɼ���ѯ(ѧ������)
void gpaSeek(char str[]);    //�����ѯ(ѧ������)

struct Adminer * ReadAdmin();//��ȡ��������Ϣ
struct Studenter * ReadStudent(); //��ȡѧ����Ϣ
struct StudentScore * ReadStudentScore();//��ȡѧ���ɼ���Ϣ
void MainOperateDecorate();  //���н�������
void ScoreLayout();  //�ɼ���ʾ����
void gpaLayout();   //������ʾ����
void CleanAll();  //�����������
void CleanArea(); //������ֽ���
void HideCursor(); //���ؿ���̨���
void DisplayCursor();  //��ʾ����̨���
void Setxy(int x, int y); //�������λ��
//������������*************************


//�ṹ��****************************
typedef struct Adminer{
    char usrname[20];
	char password[20];
    struct Adminer * Next; //ָ����
}Admin;
typedef struct Studenter{
    char usrname[20];
	char password[20];
    struct Studenter * Next; //ָ����
}Student;

typedef struct StudentScore{  //ѧ���ɼ��ṹ��
    char ID[20]; //ѧ��
	char Name[20];//����
    float Math, English, Computer, JavaP, PE,total,GPA;  //GPA ����
	struct StudentScore * Next;  //ָ����

}StScore;
//�ṹ��****************************




int main(){
   system("color 20");  //���ÿ���̨��ɫ
   HideCursor();       //���ع��
   system("mode con cols=80 lines=30"); //���ÿ���̨���
   MainOperate();     //�����溯��
   
   getchar();
   return 0;
}


/***************������***************/
void MainOperate(){

	CleanAll();  //�����������
	MainOperateDecorate();   //���н�������
	Setxy(30,2);
	printf("��ӭʹ�ñ�ϵͳ");
	Setxy(30,11);
	printf("1. ����Ա��¼\n");
	Setxy(30,13);
	printf("2. ѧ����¼\n");
	Setxy(30,15);
	printf("3. �˳�\n");

	while(1){
		char opt;
		opt = _getch();
		switch(opt){
		  case '1':
			AdminLoginFace();   //����Ա��¼������
			break;
		  case '2':
			StudentLoginFace();  //ѧ����¼������
			break;
		  case '3':
			  Setxy(10,25);
			  exit(0);       //�˳�
			break;
		  default:
			  break;
		}
	}
	return;
	
}
/***************����Ա������***************/
void AdminLoginFace(){
    CleanAll();	  //�����������
	MainOperateDecorate();   //���н�������
	
    Setxy(30,2);
	printf("����Ա��ҳ");
	Setxy(30,10);
	printf("1. ��¼\n");
	Setxy(30,12);
	printf("2. ע��\n");
	Setxy(30,14);
	printf("3. ����������\n");
	Setxy(30,16);
	printf("4. �˳�\n");

	
	while(1){
       Admin * admin = NULL;
	   char opt;
	   opt = _getch();
	   switch(opt){
	      case '1':
			  AdminLogin(admin);  //����Ա��¼
			  break;
		  case '2':
			  AdminRegister(admin);  //����Աע��
			  break;
		  case '3':
			  MainOperate();    //�����溯��
			  break;
		  case '4':
			  Setxy(10,25);
			  exit(0);
			  break;
	      default:
			  break;

	   }	
	}
}

/***************����Ա��¼***************/
void AdminLogin(struct Adminer * p){
    CleanAll();	   //�����������
	MainOperateDecorate();  //���н�������
	DisplayCursor();    //��ʾ����̨���
	
	Setxy(30,2);
	printf("����Ա��¼");
	Setxy(30,11);
	printf("�û�����\n");   
	Setxy(30,13);
	printf("��  �룺\n"); 
	Setxy(28,16);
	printf("ȡ��(N)");
	Setxy(38,16);
	printf("��¼(Y)");
	FILE * fp ;
	Admin * q = NULL;
	p = (Admin *)malloc(sizeof(Admin));

	Setxy(38,11);
	scanf("%s",p->usrname);
	Setxy(38,13);
	scanf("%s",p->password);
	HideCursor();   //���ؿ���̨���
	if((fp = fopen("admin.txt","ab")) == NULL){
		fclose(fp);
		if((fp = fopen("admin.txt","wb")) == NULL){
		    Setxy(32, 15);
			printf("�ļ�����");
			Setxy(30, 18);
			printf("�밴���������!");
			_getch();
			CleanAll();
			AdminLoginFace();
			return ;
		}
	 
	}
	q = ReadAdmin();
	
    /*����Ա��¼����ƥ�䲿��**/
   	while(1){
		    int i=0;
			char opt;
			opt = _getch();
			if('n' == opt || 'N' == opt){
				AdminLoginFace();
			}

			else if('y' == opt || 'Y' == opt){
				
				
				  
					while(q != NULL){
					
					
					if(strcmp(p->usrname,q->usrname) == 0 && strcmp(p->password,q->password) == 0) //�ж��û����������Ƿ�ƥ��
					{

				      CleanAll();  //�����������
				      AdminSucceed();  //����Ա��¼�ɹ�
					  return;
					}
					q = q->Next;
					i++;
					Setxy(40,22);
					printf("%d",i);

					}
				     Setxy(26,17);
					 printf("�û������ڻ��������!");  
					 Setxy(30,18);
					 printf("�����������!");  /*�û������ڻ�������󷵻ع���Ա��¼������**/
					 _getch();
					 AdminLoginFace();   //����Ա��¼������
			     
			}else{
				Setxy(32,18);
				printf("������Y/N");
				Setxy(30,19);
				printf("�����������!");
				_getch();
				AdminLogin(p);
			}
	}
	fclose(fp);
}

/***************����Աע��***************/
void AdminRegister(struct Adminer * p){
    CleanAll();	 //�����������
	MainOperateDecorate();  //���н�������
    DisplayCursor();  //��ʾ����̨���
	Setxy(30,2);
	printf("����Աע��");

    FILE * fp ;
	Admin * q = NULL;	
    p = (Admin *)malloc(sizeof(Admin));

	if((fp = fopen("admin.txt","ab")) == NULL){
		fclose(fp);
		if((fp = fopen("admin.txt","wb")) == NULL){
		    Setxy(32, 15);
			printf("�ļ�����");
			Setxy(30, 18);
			printf("�밴���������!");
			_getch();
			CleanAll();  //�����������
			AdminLoginFace();  //����Ա��¼������

			return ;
		}
	 
	}

	Setxy(30,11);
	printf("�û�����\n");  
	Setxy(30,13);
	printf("��  �룺\n");   
	Setxy(28,16);
	printf("ȡ��(N)");
	Setxy(38,16);
	printf("ע��(Y)");
	Setxy(38,11);
	scanf("%s",&p->usrname);
	Setxy(38,13);
	scanf("%s",&p->password);
	HideCursor(); 
	q = ReadAdmin();
	/*�ж��û��Ƿ���ע�Ჿ��**/
	while(q != NULL){
	   if(strcmp(p->usrname,q->usrname) == 0){
		 
		 Setxy(30,17);
		 printf("���û���ע��!");
		 Setxy(30,18);
		 printf("�����������!");
		 _getch();
		 AdminLoginFace();
		 return;
	   }
	   q = q->Next;
	}
    	
	while(1){
	   char opt;
		opt = _getch();
		if('n' == opt || 'N' == opt){
		    AdminLoginFace();
		}
		else if('y' == opt || 'Y' == opt){
	
			fprintf(fp,"%s %s",p->usrname,p->password);
			fputs("\r\n",fp);
			fclose(fp);
			CleanAll();
            MainOperateDecorate();
			Setxy(30,2);
			printf("����Աע��");
			Setxy(32,13);
			printf("ע��ɹ���");
			Setxy(30,17);
			printf("�����������!");
			_getch();
            AdminLoginFace();
		}else{
		    Setxy(32,18);
			printf("������Y/N");
			Setxy(30,19);
			printf("�����������!");
			_getch();
            AdminRegister(p);
		}

	}

}
/***************����Ա��¼�ɹ�***************/
void AdminSucceed(){
    CleanAll();  //�����������
    MainOperateDecorate(); //���н�������
	Setxy(30,2);
    printf("����Ա��¼�ɹ�");
	Setxy(30,11);
	printf("1. ѧ���ɼ�¼��\n");
	Setxy(30,13);
	printf("2. ѧ���ɼ�����\n");
	Setxy(30,15);
	printf("3. ����������\n");
	Setxy(30,17);
	printf("4. �˳�\n");
	HideCursor(); //���ؿ���̨���

	while(1){
		StScore * score = NULL;
		char opt;
		opt = _getch();
		switch(opt){
		  case '1':
			StudentScoreEnter();      //ѧ���ɼ�¼��
			break; 
		  case '2':
			StudentScoreManage();    //ѧ���ɼ�����
			break;
		  case '3':
			 MainOperate(); //������
			break;
		  case '4':
			Setxy(10,25);
			exit(0);   //�˳�
			break;
		  default:
			  break;
		}
	}
}
/***************ѧ���ɼ�¼��***************/
void StudentScoreEnter(){
	int count, i;
	FILE* fp = NULL;
	struct StudentScore* p = NULL;
    CleanAll();
    MainOperateDecorate();	
	CleanArea();  //������ֽ���
	DisplayCursor(); 
	Setxy(30,2);
    printf("ѧ���ɼ�����");
	Setxy(5,6);
	printf("��������Ҫ¼��ѧ���ĸ�����");
    Setxy(32,6);
	scanf("%d",&count);
	if(count <= 0 || count>15){
	    Setxy(40,6);
		printf("��������Ч����! (1~15)");
		Setxy(40,7);
		printf("�밴���������!");
		_getch();
        AdminSucceed();
	    return;
	}
	ScoreLayout();
    if((fp = fopen("score.txt","ab")) == NULL){
	   fclose(fp);//�ر��ļ�ָ��
	   if((fp = fopen("score.txt","wb")) == NULL){
	      Setxy(30,15);
		  printf("�ļ�����");
		  Setxy(30,18);
		  printf("�밴��������أ�");
		  _getch();
         AdminSucceed();
		 return;
	   }
	}
	for(i=0; i<count; i++){
		float sum,gpa=0;
	    p = (struct StudentScore*)malloc(sizeof(struct StudentScore));
		if(p == NULL){
		   Setxy(30,16);
		   printf("ѧ����Ϣ����ʧ�ܣ�");
		   Setxy(30,19);
		   printf("����������أ�");
		   _getch();
           AdminSucceed();
		   return;
		}
        Setxy(1,12+i);
		scanf("%s",&(p->Name));  //����

		Setxy(10,12+i);
		scanf("%s",&(p->ID));  //ѧ��
		Setxy(23,12+i);
		scanf("%f",&(p->Math));  //����
		Setxy(30,12+i);
		scanf("%f",&(p->English));  //��Ӣ
		Setxy(39,12+i);
		scanf("%f",&(p->Computer));  //���ݽṹ
		Setxy(48,12+i);
		scanf("%f",&(p->JavaP));  //java
		Setxy(54,12+i);
		scanf("%f",&(p->PE));  //����
		sum = p->Computer + p->English + p->JavaP + p->Math + p->PE;
		gpa = (sum/5 - 60)/10 + 1;
        p->GPA = gpa;
		p->total = sum;
		Setxy(62,12+i);
		printf("%.f",p->total);
		Setxy(68,12+i);
		printf("%.2f",p->GPA);
		    
		fprintf(fp,"%s %s %.f %.f %.f %.f %.f %.f %.2f",p->Name, p->ID, p->Math, p->English, p->Computer, p->JavaP, p->PE, p->total,p->GPA);
		fputs("\r\n",fp);

	}
	Setxy(40,6);
	printf("��ӳɹ�!");
	fclose(fp);
	Setxy(40,7);
	printf("�밴���������!");
	_getch();
	AdminSucceed();

	return;
}
/***************ѧ���ɼ�����***************/
void StudentScoreManage(){
    CleanAll();
    MainOperateDecorate();
	HideCursor();
	Setxy(30,2);
    printf("ѧ���ɼ�����");
	Setxy(30,10);
	printf("1. �鿴�ɼ�\n");
	Setxy(30,11);
	printf("2. ��ӳɼ�\n");
	Setxy(30,12);
	printf("3. �ɼ�����\n");
	Setxy(30,13);
	printf("4. �޸ĳɼ�\n");
	Setxy(30,14);
	printf("5. ɾ���ɼ�\n");
	Setxy(30,15);
	printf("6. ������һ��\n");
	Setxy(30,16);
	printf("7. ����������\n");
	Setxy(30,17);
	printf("8. �˳�\n");
	//Setxy(30,18);
	//printf("9. �˳�\n");
	while(1){
		StScore*  score = NULL;
		char opt;
		opt = _getch();
		switch(opt){
		  case '1':
			lookAllScore();//�鿴�ɼ�
			break; 
		  case '2':
			addScore();    //��ӳɼ�
			break;
		  case '3':
			sortScore();          //�ɼ�����
			break;
			case '4':
			modifyScore();    //�޸ĳɼ�
			break;
		  case '5':                  
			deleteScore();         //ɾ���ɼ�  
			break;
			case '6':
			AdminSucceed();     //������һ��
			break;
		  case '7':
			MainOperate();          //����������
			break;
		  case '8':
			Setxy(10,25);           //�˳�
			exit(0);         
			break;
		  default:
			  break;
		}
	}
}


/***************ѧ��������***************/
void StudentLoginFace(){
    CleanAll();	
	MainOperateDecorate();
	
    Setxy(32,2);
	printf("ѧ����¼");
	Setxy(30,10);
	printf("1. ��¼\n");
	Setxy(30,12);
	printf("2. ע��\n");
	Setxy(30,14);
	printf("3. ����������\n");
	Setxy(30,16);
	printf("4. �˳�\n");
	while(1){
	   Student * student = NULL;
	   char opt;
	   opt = _getch();
	   switch(opt){
	      case '1':
			  StudentLogin(student);
			  break;
		  case '2':
			  StudentRegister(student);
			  break;
		  case '3':
			  MainOperate();
			  break;
		  case '4':
			  Setxy(10,25);
			  exit(0);
			  break;
	      default:
			  break;

	   }	
	}
}
/***************ѧ����¼***************/
void StudentLogin(struct Studenter * p){
    CleanAll();	
	MainOperateDecorate();
	DisplayCursor(); //���ع��
	Setxy(32,2);
	printf("ѧ����¼");
	Setxy(30,11);
	printf("ѧ  �ţ�\n");   
	Setxy(30,13);
	printf("��  �룺\n"); 
	Setxy(28,16);
	printf("ȡ��(N)");
	Setxy(38,16);
	printf("��¼(Y)");
	FILE * fp ;
	Student * q = NULL;
	p = (Student *)malloc(sizeof(Student));

	Setxy(38,11);
	scanf("%s",p->usrname);
	Setxy(38,13);
	scanf("%s",p->password);
	HideCursor();
	
	if((fp = fopen("student.txt","ab")) == NULL){
		fclose(fp);
		if((fp = fopen("student.txt","wb")) == NULL){
		    Setxy(32, 15);
			printf("�ļ�����");
			Setxy(30, 18);
			printf("�밴���������!");
			_getch();
			CleanAll();
			StudentLoginFace();
			return ;
		}
	 
	}
	q = ReadStudent();
	/*if(q == NULL){
        
 	    return ;
    }*/		 
   	while(1){
		    int i=0;
			char opt;
			opt = _getch();
			if('n' == opt || 'N' == opt){
				StudentLoginFace();
			}

			else if('y' == opt || 'Y' == opt){
				
				
				  
					while(q != NULL){
					
					
					if(strcmp(p->usrname,q->usrname) == 0 && strcmp(p->password,q->password) == 0) //�ж��û����������Ƿ�ƥ��
					{

				      CleanAll();
				      StudentSucceed(p->usrname);
					  return;
					}
					q = q->Next;
					i++;
					Setxy(40,22);
					printf("%d",i);

					}
				     Setxy(26,17);
					 printf("�û������ڻ��������!");
					 Setxy(30,18);
					 printf("�����������!"); 
					 _getch();
					 StudentLoginFace();
			     
			}else{
				Setxy(32,18);
				printf("������Y/N");
				Setxy(30,19);
				printf("�����������!");
				_getch();
				StudentLogin(p);
			}
	}
	fclose(fp);
}
/***************ѧ��ע��***************/
void StudentRegister(struct Studenter * p){
    CleanAll();	
	MainOperateDecorate();
	FILE * fp =NULL ;
	struct Studenter * q = NULL;
	DisplayCursor();
	Setxy(32,2);
	printf("ѧ��ע��");
	
    p = (Student *)malloc(sizeof(Student));
	if((fp = fopen("student.txt","ab")) == NULL){
		fclose(fp);
		if((fp = fopen("student.txt","wb")) == NULL){
		    Setxy(32, 15);
			printf("�ļ�����");
			Setxy(30, 18);
			printf("�밴���������!");
			_getch();
			CleanAll();
			StudentLoginFace();

			return ;
		}
	 
	}
	
	Setxy(30,11);
	printf("ѧ  �ţ�\n");  
	Setxy(30,13);
	printf("��  �룺\n");   
	Setxy(28,16);
	printf("ȡ��(N)");
	Setxy(38,16);
	printf("ע��(Y)");
	Setxy(38,11);
	scanf("%s",&p->usrname);
	Setxy(38,13);
	scanf("%s",&p->password);
	HideCursor();
    q = ReadStudent();
	   
    while(q != NULL){
	   if(strcmp(p->usrname,q->usrname) == 0){
		 
		 Setxy(30,17);
		 printf("���û���ע��!");
		 Setxy(30,18);
		 printf("�����������!");
		 _getch();
		 AdminLoginFace();
		 return;
	   }
	   q = q->Next;
	}
	
	
	while(1){
	   char opt;
		opt = _getch();
		if('n' == opt || 'N' == opt){
		    StudentLoginFace();
		}
		else if('y' == opt || 'Y' == opt){
		    //p->Next = p;
			fprintf(fp,"%s %s",p->usrname,p->password);
			fputs("\r\n",fp);
			fclose(fp);
			CleanAll();
            MainOperateDecorate();
			Setxy(30,2);
			printf("ѧ��ע��");
			Setxy(32,13);
			printf("ע��ɹ���");
			Setxy(30,17);
			printf("�����������!");
			_getch();
            StudentLoginFace();
		}else{
		    Setxy(32,18);
			printf("������Y/N");
			Setxy(30,19);
			printf("�����������!");
			_getch();
            StudentRegister(p);
		}

	}

}
/***************ѧ����¼�ɹ�***************/
void StudentSucceed(char str[]){
	//char str[20];
    CleanAll();
    MainOperateDecorate();
	Setxy(30,2);
    printf("ѧ����¼�ɹ�");
	
	Setxy(30,11);
	printf("1. �ɼ���ѯ\n");
	Setxy(30,13);
	printf("2. �����ѯ\n");
	Setxy(30,15);
	printf("3. ����������\n");
	Setxy(30,17);
	printf("4. �˳�\n");

	while(1){
		char opt;
		opt = _getch();
		switch(opt){
		  case '1':
			scoreSeek(str);      //�ɼ���ѯ
			break; 
		  case '2':
			gpaSeek(str);    //�����ѯ
			break;
		  case '3':
			 MainOperate();      //����������
			break;
		  case '4':
			Setxy(10,25);         //�˳�
			exit(0); 
			break;
		  default:
			  break;
		}
	}
}
/***************��ȡ��������Ϣ***************/
struct Adminer * ReadAdmin(){
    FILE * fp = NULL;
	struct Adminer * H = NULL, *p = NULL;
	struct Adminer * p1 = NULL;
	int i = 0;
	p1 = (struct Adminer*)malloc(sizeof(struct Adminer));
	if((fp = fopen("admin.txt","rb")) == NULL){
	   Setxy(70,16);
	   printf("�ļ�����ʧ��!");
       fclose(fp);
	   Setxy(30,18);
	   printf("�����������!");
       AdminLoginFace();
	   return NULL;
	}
	while(!feof(fp))
	{
		
	   p = (struct Adminer*)malloc(sizeof(struct Adminer));
       //��ʼ������
	   fscanf(fp,"%s",&p->usrname); //�û���
	   fscanf(fp,"%s",&p->password);//����
	   fputs("\r\n",fp);
       
	   if(i==0){
	      H = p;
		  p1= p;
	   }else{
	      p1->Next = p;

	   }
	   p1 = p;
	   
	   i++;	  
	   
	}
	p1->Next = p;
	p1 = p;
	p1->Next = p;
	p->Next = NULL;
	//Setxy(40,22);
//	printf("%d",i);
	fclose(fp);
	return H;
}
/***************��ȡѧ����Ϣ***************/
struct Studenter * ReadStudent(){
    FILE * fp = NULL;
	struct Studenter * H = NULL, *p = NULL;
	struct Studenter * p1 = NULL;
	int i = 0;
	p1 = (struct Studenter*)malloc(sizeof(struct Studenter));
	if((fp = fopen("student.txt","rb")) == NULL){
	   Setxy(70,16);
	   printf("�ļ�����ʧ��!");
       fclose(fp);
	   Setxy(30,18);
	   printf("�����������!");
       StudentLoginFace();
	   return NULL;
	}
	while(!feof(fp))
	{
		
	   p = (struct Studenter*)malloc(sizeof(struct Studenter));
       //��ʼ������
	   fscanf(fp,"%s",&p->usrname); //�û���
	   fscanf(fp,"%s",&p->password);//����
	   fputs("\r\n",fp);
       
	   if(i==0){
	      H = p;
		  p1= p;
	   }else{
	      p1->Next = p;

	   }
	   p1 = p;
	   
	   i++;	  
	   //Setxy(12,22+i);
	   //printf("%s %s",p->password,p->usrname);
	}
	p1->Next = p;
	p1 = p;
	p1->Next = p;
	p->Next = NULL;
	//Setxy(40,22);
//	printf("%d",i);
	fclose(fp);
	return H;
}
/***************�鿴����ѧ���ɼ�***************/
void lookAllScore(){
    CleanAll();
    MainOperateDecorate();	
	CleanArea();
	Setxy(30,2);
    printf("����ѧ���ɼ�");
	ScoreLayout();
	struct StudentScore *q = NULL;
	FILE* fp = NULL;
    if((fp = fopen("score.txt","ab")) == NULL){
		fclose(fp);
		if((fp = fopen("score.txt","wb")) == NULL){
		    Setxy(32, 15);
			printf("�ļ�����");
			Setxy(30, 18);
			printf("�밴���������!");
			_getch();
			CleanAll();
			StudentScoreManage();
			return ;
		}
	 
	}
	q = ReadStudentScore();		 
   
    int i=0;
	
	while(q != NULL){
		Setxy(1,12+i);
		printf("%s",q->Name);  //����
		Setxy(10,12+i);
		printf("%s",q->ID);  //ѧ��
		Setxy(23,12+i);
		printf("%.f",q->Math);  //����
		Setxy(30,12+i);
		printf("%.f",q->English);  //��Ӣ
		Setxy(39,12+i);
		printf("%.f",q->Computer);  //���ݽṹ
		Setxy(48,12+i);
		printf("%.f",q->JavaP);  //java
		Setxy(54,12+i);
		printf("%.f",q->PE);    //����
		Setxy(60,12+i);
		printf("%.f",q->total);  //�ܷ�
		Setxy(68,12+i);
		printf("%.2f",q->GPA);  //����
		q = q->Next;
		i++;
		}
	Setxy(2,6);
	printf("%d",i);
	fclose(fp);
	Setxy(31, 6);
	printf("�밴���������!");
	_getch();
	StudentScoreManage();	
	
}
/***************���ѧ���ɼ�***************/
void addScore(){
    int count, i;
	FILE* fp = NULL;
	struct StudentScore* p = NULL;
    CleanAll();
    MainOperateDecorate();	
	CleanArea();
	DisplayCursor();
	Setxy(30,2);
    printf("��ӳɼ�");
	Setxy(5,6);
	printf("��������Ҫ���ѧ���ĸ�����");
    Setxy(32,6);
	scanf("%d",&count);
	if(count <= 0 || count>15){
	    Setxy(40,6);
		printf("��������Ч����! (1~15)");
		Setxy(40,7);
		printf("�밴���������!");
		_getch();
        StudentScoreManage();
	    return;
	}
	ScoreLayout();
    if((fp = fopen("score.txt","ab")) == NULL){
	   fclose(fp);//�ر��ļ�ָ��
	   if((fp = fopen("score.txt","wb")) == NULL){
	      Setxy(30,15);
		  printf("�ļ�����");
		  Setxy(30,18);
		  printf("�밴��������أ�");
		  _getch();
         StudentScoreManage();
		 return;
	   }
	}
	for(i=0; i<count; i++){
		float sum,gpa;
	    p = (struct StudentScore*)malloc(sizeof(struct StudentScore));
		if(p == NULL){
		   Setxy(30,16);
		   printf("ѧ����Ϣ����ʧ�ܣ�");
		   Setxy(30,19);
		   printf("����������أ�");
		   _getch();
           StudentScoreManage();
		   return;
		}
        Setxy(1,12+i);
		scanf("%s",&(p->Name));  //����

		Setxy(10,12+i);
		scanf("%s",&(p->ID));  //ѧ��
		Setxy(23,12+i);
		scanf("%f",&(p->Math));  //����
		Setxy(30,12+i);
		scanf("%f",&(p->English));  //��Ӣ
		Setxy(39,12+i);
		scanf("%f",&(p->Computer));  //���ݽṹ
		Setxy(48,12+i);
		scanf("%f",&(p->JavaP));  //java
		Setxy(54,12+i);
		scanf("%f",&(p->PE));  //����
		sum = p->Computer + p->English + p->JavaP + p->Math + p->PE;
		gpa = (sum/5 - 60)/10 + 1;
        p->GPA = gpa;
		p->total = sum;
		Setxy(62,12+i);
		printf("%.f",p->total);
		Setxy(68,12+i);
		printf("%.2f",p->GPA);
		fprintf(fp,"%s %s %.f %.f %.f %.f %.f %.f %.2f",p->Name, p->ID, p->Math, p->English, p->Computer, p->JavaP, p->PE, p->total,p->GPA);
		fputs("\r\n",fp);

	}
	Setxy(40,6);
	printf("��ӳɹ�!");
	fclose(fp);
	Setxy(40,7);
	printf("�밴���������!");
	_getch();
	StudentScoreManage();
}
/***************ɾ��ѧ���ɼ�***************/
void deleteScore(){
	struct StudentScore *q = NULL;
	struct StudentScore* p = NULL;
	struct StudentScore* t = NULL;
	struct StudentScore* m = NULL;
	struct StudentScore* n = NULL;
	struct StudentScore* k = NULL;
	struct StudentScore* h = NULL;
	q = ReadStudentScore();	
	p = ReadStudentScore();   
    m=q;
	n=q;
    t=q;
    CleanAll();
    MainOperateDecorate();	
	CleanArea();
	DisplayCursor();
	Setxy(30,2);
    printf("ɾ��ѧ���ɼ�");
	ScoreLayout();  
	
	FILE* fp = NULL;
	char str[20];
    if((fp = fopen("score.txt","ab")) == NULL){
		fclose(fp);
		if((fp = fopen("score.txt","wb")) == NULL){
		    Setxy(32, 15);
			printf("�ļ�����");
			Setxy(30, 18);
			printf("�밴���������!");
			_getch();
			CleanAll();
			StudentScoreManage();
			return ;
		}
	 
	}
	
    int i=0,j=0;
	while(q != NULL){
		Setxy(1,12+i);
		printf("%s",q->Name);  //����
		Setxy(10,12+i);
		printf("%s",q->ID);  //ѧ��
		Setxy(23,12+i);
		printf("%.f",q->Math);  //����
		Setxy(30,12+i);
		printf("%.f",q->English);  //��Ӣ
		Setxy(39,12+i);
		printf("%.f",q->Computer);  //���ݽṹ
		Setxy(48,12+i);
		printf("%.f",q->JavaP);  //java
		Setxy(54,12+i);
		printf("%.f",q->PE);    //����
		Setxy(60,12+i);
		printf("%.f",q->total);  //�ܷ�
		Setxy(68,12+i);
		printf("%.2f",q->GPA);  //����
		q = q->Next;
		i++;
		}
	q = p;
	Setxy(2,6);
	printf("%d",i);
	fclose(fp);
	Setxy(31, 6);
	printf("��������Ҫɾ��ѧ����ѧ��:");
	Setxy(58,6);
	scanf("%s",str);
	while(1){
	   if(strcmp(str,p->ID) == 0 ){
	       break;
	   }
	   else{
		   if(p->Next == NULL){
			  Setxy(35,7);
			  printf("�޴�ѧ��!�����������!");
			  _getch();
              StudentScoreManage();
		      return;
		   }
	       p=p->Next;
	   }
	}
	/**************************************************************/    //ɾ��ѧ���ɼ�Ȼ�������Ļ��
	if(strcmp(str,n->ID) == 0)
	{
		q = n->Next;
        h = n->Next;
        
		while(q != NULL){
		Setxy(1,20+j);
		printf("%s",q->Name);  //����
		Setxy(10,20+j);
		printf("%s",q->ID);  //ѧ��
		Setxy(23,20+j);
		printf("%.f",q->Math);  //����
		Setxy(30,20+j);
		printf("%.f",q->English);  //��Ӣ
		Setxy(39,20+j);
		printf("%.f",q->Computer);  //���ݽṹ
		Setxy(48,20+j);
		printf("%.f",q->JavaP);  //java
		Setxy(54,20+j);
		printf("%.f",q->PE);    //����
		Setxy(60,20+j);
		printf("%.f",q->total);  //�ܷ�
		Setxy(68,20+j);
		printf("%.2f",q->GPA);  //����
		q = q->Next;
		j++;
		}
       if((fp = fopen("score.txt","wb")) == NULL){
		   fclose(fp);//�ر��ļ�ָ��
		   if((fp = fopen("score.txt","wb")) == NULL){
			  Setxy(30,15);
			  printf("�ļ�����");
			  Setxy(30,18);
			  printf("�밴��������أ�");
			  _getch();
			 StudentScoreManage();
			 return;
		   }
		}
		while(h != NULL){
		   fprintf(fp,"%s %s %.f %.f %.f %.f %.f %.f %.2f",h->Name, h->ID, h->Math, h->English, h->Computer, h->JavaP, h->PE, h->total,h->GPA);
		   fputs("\r\n",fp);
		   h = h->Next;
		}
		fclose(fp);
       Setxy(35,7);
	   printf("ѧ���ɼ���ɾ��!�����������!");
	  
	  _getch();
      StudentScoreManage();
	  return;	
	}

	if(n->Next != NULL)
	{
		q = n;
		h = n;
		do
		{
			m = n;
			n = n->Next;
			if(strcmp(str,n->ID) == 0)
			{
				m->Next = n->Next;
				free(n);

				while(q != NULL){
				Setxy(1,20+j);
				printf("%s",q->Name);  //����
				Setxy(10,20+j);
				printf("%s",q->ID);  //ѧ��
				Setxy(23,20+j);
				printf("%.f",q->Math);  //����
				Setxy(30,20+j);
				printf("%.f",q->English);  //��Ӣ
				Setxy(39,20+j);
				printf("%.f",q->Computer);  //���ݽṹ
				Setxy(48,20+j);
				printf("%.f",q->JavaP);  //java
				Setxy(54,20+j);
				printf("%.f",q->PE);    //����
				Setxy(60,20+j);
				printf("%.f",q->total);  //�ܷ�
				Setxy(68,20+j);
				printf("%.2f",q->GPA);  //����
				q = q->Next;
				j++;
				}
			  if((fp = fopen("score.txt","wb")) == NULL){
				   fclose(fp);//�ر��ļ�ָ��
				   if((fp = fopen("score.txt","wb")) == NULL){
					  Setxy(30,15);
					  printf("�ļ�����");
					  Setxy(30,18);
					  printf("�밴��������أ�");
					  _getch();
					 StudentScoreManage();
					 return;
				   }
				}
				while(h != NULL){
				   fprintf(fp,"%s %s %.f %.f %.f %.f %.f %.f %.2f",h->Name, h->ID, h->Math, h->English, h->Computer, h->JavaP, h->PE, h->total,h->GPA);
				   fputs("\r\n",fp);
				   h = h->Next;
				}
				fclose(fp);
			  Setxy(35,7);
			  printf("ѧ���ɼ���ɾ��!�����������!");
			  _getch();
			  StudentScoreManage();
			  return;
			}

				

		}while(n->Next != NULL);
	}
	

	

	////////ɾ��������д��
	/*if((fp = fopen("score.txt","ab")) == NULL){
	   fclose(fp);//�ر��ļ�ָ��
	   if((fp = fopen("score.txt","wb")) == NULL){
	      Setxy(30,15);
		  printf("�ļ�����");
		  Setxy(30,18);
		  printf("�밴��������أ�");
		  _getch();
         StudentScoreManage();
		 return;
	   }
	}*/

	 /*while(q != NULL){
		Setxy(1,18+j);
		printf("%s",q->Name);  //����
		Setxy(10,18+j);
		printf("%s",q->ID);  //ѧ��
		Setxy(23,18+j);
		printf("%.f",q->Math);  //����
		Setxy(30,18+j);
		printf("%.f",q->English);  //��Ӣ
		Setxy(39,18+j);
		printf("%.f",q->Computer);  //���ݽṹ
		Setxy(48,18+j);
		printf("%.f",q->JavaP);  //java
		Setxy(54,18+j);
		printf("%.f",q->PE);    //����
		Setxy(60,18+j);
		printf("%.f",q->total);  //�ܷ�
		Setxy(68,18+j);
		printf("%.f",q->GPA);  //����
		q = q->Next;
		j++;
		}*/


//	_getch();
//	StudentScoreManage();	
}
/***************�޸�ѧ���ɼ�***************/
void modifyScore(){
	FILE * fp = NULL;
    struct StudentScore *q = NULL;
	struct StudentScore *p = NULL;
	struct StudentScore *h = NULL;
	q = ReadStudentScore();
	p = ReadStudentScore();
	h = p;
	int k = 0;
	float sum=0,gpa = 0;
	char str[20];
    CleanAll();
    MainOperateDecorate();	
	CleanArea();
	DisplayCursor();
	Setxy(34,2);
    printf("�޸ĳɼ�");
	ScoreLayout();
	while(q != NULL){
		Setxy(1,12+k);
		printf("%s",q->Name);  //����
		Setxy(10,12+k);
		printf("%s",q->ID);  //ѧ��
		Setxy(23,12+k);
		printf("%.f",q->Math);  //����
		Setxy(30,12+k);
		printf("%.f",q->English);  //��Ӣ
		Setxy(39,12+k);
		printf("%.f",q->Computer);  //���ݽṹ
		Setxy(48,12+k);
		printf("%.f",q->JavaP);  //java
		Setxy(54,12+k);
		printf("%.f",q->PE);    //����
		Setxy(60,12+k);
		printf("%.f",q->total);  //�ܷ�
		Setxy(68,12+k);
		printf("%.2f",q->GPA);
		q = q->Next;
		k++;
		}
	Setxy(31, 6);
	printf("��������Ҫ�޸�ѧ����ѧ��:");
	Setxy(58,6);
	scanf("%s",str);
	while(1){
	   if(strcmp(str,p->ID) == 0 ){
	       break;
	   }
	   else{
		   if(p->Next == NULL){
			  Setxy(35,7);
			  printf("�޴�ѧ��!�����������!");
			  _getch();
              StudentScoreManage();
		      return;
		   }
	       p=p->Next;
	   }
	}
	Setxy(5,22);
	printf("����������ѧ���ɼ�:");
	Setxy(1,23);
	scanf("%s",&(p->Name));  //����
	Setxy(10,23);
	scanf("%s",&(p->ID));  //ѧ��
	Setxy(23,23);
	scanf("%f",&(p->Math));  //����
	Setxy(30,23);
	scanf("%f",&(p->English));  //��Ӣ
	Setxy(39,23);
	scanf("%f",&(p->Computer));  //���ݽṹ
	Setxy(48,23);
	scanf("%f",&(p->JavaP));  //java
	Setxy(54,23);
	scanf("%f",&(p->PE));  //����
	sum = p->Computer + p->English + p->JavaP + p->Math + p->PE;
	gpa = (sum/5 - 60)/10 + 1;
	p->GPA = gpa;
	p->total = sum;
	Setxy(62,23);
	printf("%.f",p->total);
	Setxy(68,23);
	printf("%.2f",p->GPA);
	Setxy(15,24);
	printf("�ɼ����޸�!�밴���������!");
	if((fp = fopen("score.txt","wb")) == NULL){
	   fclose(fp);//�ر��ļ�ָ��
	   if((fp = fopen("score.txt","wb")) == NULL){
		  Setxy(30,15);
		  printf("�ļ�����");
		  Setxy(30,18);
		  printf("�밴��������أ�");
		  _getch();
		 StudentScoreManage();
		 return;
	   }
	}
	while(h != NULL){
	   fprintf(fp,"%s %s %.f %.f %.f %.f %.f %.f %.2f",h->Name, h->ID, h->Math, h->English, h->Computer, h->JavaP, h->PE, h->total,h->GPA);
	   fputs("\r\n",fp);
	   h = h->Next;
	}
	fclose(fp);
	_getch();
    StudentScoreManage();
}

/***************ѧ���ɼ�����***************/
void sortScore(){
	struct StudentScore *q = NULL;
    struct StudentScore *H = NULL;
	struct StudentScore *m = NULL;
	struct StudentScore *n = NULL;
	struct StudentScore *t = NULL;
    CleanAll();
    MainOperateDecorate();	
	CleanArea();
	Setxy(30,2);
    printf("�ɼ�����");
	ScoreLayout();  //�ɼ���ʾ����
	FILE * fp = NULL;
	if((fp = fopen("score.txt","ab")) == NULL){
		fclose(fp);
		if((fp = fopen("score.txt","wb")) == NULL){
		    Setxy(32, 15);
			printf("�ļ�����");
			Setxy(30, 18);
			printf("�밴���������!");
			_getch();
			CleanAll();
			StudentScoreManage();
			return ;
		}
	 
	}
	
	q = ReadStudentScore();
	H = q;
	int i,j;
	int k = 0; 
	float M,E,C,J,P,T,G;
	char str1[20], str2[20];
    int len=1;
	while(H->Next != NULL){
		H = H->Next;
		len++;
		}
	Setxy(2,6);
	printf("%d",len);
		
    for(i=0, m=q; i<len-1; i++, m=m->Next){
		for(j=i+1, n=m->Next; j<len; j++, n=n->Next){
		    /*if(n->Next  == NULL){
			   break;
			}
			if((m->total) < (n->total)){
                //Setxy(11,15+i);
				//printf("%d",len);
			   t = m;
			   m = n;
			   n = t;
			}*/
			
			if((m->total) < (n->total)){
				strcpy(str1,m->Name);  //������
				strcpy(m->Name,n->Name);
				strcpy(n->Name,str1);
				strcpy(str2,m->ID);  //��ѧ��
				strcpy(m->ID,n->ID);
				strcpy(n->ID,str2);
                M = m->Math, E = m->English, C = m->Computer, J=m->JavaP, P=m->PE, T=m->total,G=m->GPA;
				m->Math=n->Math, m->English=n->English, m->Computer=n->Computer, m->JavaP=n->JavaP, m->PE = n->PE, m->total=n->total, m->GPA=n->GPA;
                n->Math=M, n->English=E, n->Computer=C, n->JavaP=J, n->PE=P, n->total=T, n->GPA=G;
			}
				
		}
	}
	while(q != NULL){
		Setxy(1,12+k);
		printf("%s",q->Name);  //����
		Setxy(10,12+k);
		printf("%s",q->ID);  //ѧ��
		Setxy(23,12+k);
		printf("%.f",q->Math);  //����
		Setxy(30,12+k);
		printf("%.f",q->English);  //��Ӣ
		Setxy(39,12+k);
		printf("%.f",q->Computer);  //���ݽṹ
		Setxy(48,12+k);
		printf("%.f",q->JavaP);  //java
		Setxy(54,12+k);
		printf("%.f",q->PE);    //����
		Setxy(60,12+k);
		printf("%.f",q->total);  //�ܷ�
		Setxy(68,12+k);
		printf("%.2f",q->GPA);
		q = q->Next;
		//len++;
		k++;

		}		
	
	fclose(fp);
	Setxy(12, 6);
	printf("�밴���������!");
	_getch();
	StudentScoreManage();  //ѧ���ɼ�����


}
/***************�ɼ���ѯ(ѧ������)***************/
void scoreSeek(char str[]){  
    struct StudentScore *q = NULL;
	q = ReadStudentScore();
    CleanAll();
    MainOperateDecorate();	
	CleanArea();
	Setxy(34,2);
    printf("�ɼ���ѯ");
	ScoreLayout();
    while(1){
	   if(strcmp(str,q->ID) == 0 ){
		   //p = q;
	       break;
	   }
	   else{
		   if(q->Next == NULL){
			  Setxy(35,7);
			  printf("���޳ɼ�!�����������!");
			  _getch();
              StudentSucceed(str);
		      return;
		   }
	       q=q->Next;
	   }
	}
	Setxy(1,12);
	printf("%s",q->Name);  //����
	Setxy(10,12);
	printf("%s",q->ID);  //ѧ��
	Setxy(23,12);
	printf("%.f",q->Math);  //����
	Setxy(30,12);
	printf("%.f",q->English);  //��Ӣ
	Setxy(39,12);
	printf("%.f",q->Computer);  //���ݽṹ
	Setxy(48,12);
	printf("%.f",q->JavaP);  //java
	Setxy(54,12);
	printf("%.f",q->PE);    //����
	Setxy(60,12);
	printf("%.f",q->total);  //�ܷ�
	Setxy(66,12);
	printf("%.2f",q->GPA);   //����
	Setxy(30,18);
	printf("�밴���������!");
	_getch();
	StudentSucceed(str);

}
/***************�����ѯ(ѧ������)***************/
void gpaSeek(char str[]){
   struct StudentScore *q = NULL;
	q = ReadStudentScore();
    CleanAll();
    MainOperateDecorate();	
	CleanArea();
	Setxy(34,2);
    printf("�����ѯ");
	gpaLayout();
    while(1){
	   if(strcmp(str,q->ID) == 0 ){
	       break;
	   }
	   else{
		   if(q->Next == NULL){
			  Setxy(35,7);
			  printf("���޳ɼ�!�����������!");
			  _getch();
              StudentSucceed(str);
		      return;
		   }
	       q=q->Next;
	   }
	}
	Setxy(1,12);
	printf("%s",q->Name);  //����
	Setxy(10,12);
	printf("%s",q->ID);  //ѧ��
	Setxy(23,12);
	printf("%.2f",(q->Math-60)/10+1);  //����
	Setxy(30,12);
	printf("%.2f",(q->English-60)/10+1);  //��Ӣ
	Setxy(39,12);
	printf("%.2f",(q->Computer-60)/10+1);  //���ݽṹ
	Setxy(46,12);
	printf("%.2f",(q->JavaP-60)/10+1);  //java
	Setxy(54,12);
	printf("%.2f",(q->PE-60)/10+1);    //����
	Setxy(60,12);
	printf("%.2f",q->GPA);  //�ܼ���
	Setxy(30,18);
	printf("�밴���������!");
	_getch();
	StudentSucceed(str);

}    
/***************��ȡѧ���ɼ�***************/
struct StudentScore * ReadStudentScore(){
    FILE * fp = NULL;
	FILE * ft = NULL;
	struct StudentScore  *p = NULL;
	struct StudentScore * H =NULL ;
	struct StudentScore * p1 = NULL;
	

	int i = 0;
	int j = 0;
	p1 = (struct StudentScore*)malloc(sizeof(struct StudentScore));
	if((fp = fopen("score.txt","rb")) == NULL){
	   Setxy(70,16);
	   printf("�ļ�����ʧ��!");
       fclose(fp);
	   Setxy(30,18);
	   printf("�����������!");
       StudentScoreManage();
	   return NULL;
	}

	if((ft = fopen("score.txt","rb")) == NULL){
	   Setxy(70,16);
	   printf("�ļ�����ʧ��!");
       fclose(ft);
	   Setxy(30,18);
	   printf("�����������!");
       StudentScoreManage();
	   return NULL;
	}


	while(!feof(fp))
	 {
	   p = (struct StudentScore*)malloc(sizeof(struct StudentScore));
       //��ʼ������
	   
	   fscanf(fp,"%s",&p->Name); //����
	   fscanf(fp,"%s",&p->ID);   //ѧ��
	   fscanf(fp,"%f",&p->Math); //����
	   fscanf(fp,"%f",&p->English);   //��Ӣ
	   fscanf(fp,"%f",&p->Computer); //���ݽṹ
	   fscanf(fp,"%f",&p->JavaP);   //java
	   fscanf(fp,"%f",&p->PE); //����
	   fscanf(fp,"%f",&p->total);   //�ܷ�
	   fscanf(fp,"%f",&p->GPA);    //����
       
	   if(i==0){
	      H = p;
		  p1= p;
	   }else{
	      p1->Next = p;

	   }
	   p1 = p;	   
	   i++;	  
	}

	while(!feof(ft))
	{
		if(j == i-1)
		{
			break;
		}
	   p = (struct StudentScore*)malloc(sizeof(struct StudentScore));
       //��ʼ������
	   
	   fscanf(ft,"%s",&p->Name); //����
	   fscanf(ft,"%s",&p->ID);   //ѧ��
	   fscanf(ft,"%f",&p->Math); //����
	   fscanf(ft,"%f",&p->English);   //��Ӣ
	   fscanf(ft,"%f",&p->Computer); //���ݽṹ
	   fscanf(ft,"%f",&p->JavaP);   //java
	   fscanf(ft,"%f",&p->PE); //����
	   fscanf(ft,"%f",&p->total);   //�ܷ�
       fscanf(ft,"%f",&p->GPA);    //����
	   fputs("\r\n",ft);
       
	   if(j==0){
	      H = p;
		  p1= p;
	   }else{
	      p1->Next = p;

	   }
	   p1 = p;	   
	   j++;	  
	}

	//p1->Next = p;
//	p1 = p;
	//p1->Next = p;
	p1->Next = NULL;
	//Setxy(40,22);
    //	printf("%d",i);
	fclose(fp);
	fclose(ft);
	return H;
}
/***************�ɼ���ʾ����***************/
void ScoreLayout(){
    Setxy(1,8);
	printf("******************************************************************************");
	Setxy(1,10);
	printf("******************************************************************************");
	Setxy(1,9);
	printf("����");
	Setxy(11,9);
	printf("ѧ��");
	Setxy(22,9);
	printf("����");
	Setxy(29,9);
	printf("��Ӣ");
	Setxy(36,9);
	printf("���ݽṹ");
	Setxy(47,9);
	printf("Java");
	Setxy(53,9);
	printf("����");
	Setxy(59,9);
	printf("�ܷ�");
	Setxy(66,9);
	printf("����");

}
/***************������ʾ����***************/
void gpaLayout(){
    Setxy(1,8);
	printf("******************************************************************************");
	Setxy(1,10);
	printf("******************************************************************************");
	Setxy(1,9);
	printf("����");
	Setxy(11,9);
	printf("ѧ��");
	Setxy(22,9);
	printf("����");
	Setxy(29,9);
	printf("��Ӣ");
	Setxy(36,9);
	printf("���ݽṹ");
	Setxy(47,9);
	printf("Java");
	Setxy(53,9);
	printf("����");
	Setxy(59,9);
	printf("ƽ������");
	

}
/***************�������̨***************/
void CleanAll(){
   int x, y ;
   for(x=0; x<=80; x++)
	   for(y=0; y<=28; y++)
	   {
	      Setxy(x,y);
		  printf(" ");
	   }
}
void CleanArea(){
    int x, y;
	for(x=0; x<=80; x++)
		for(y=5; y<=28; y++){
		   Setxy(x,y);
		   printf(" ");
		}
}
/***************���н�������***************/
void MainOperateDecorate(){
    int m, k;
	int n;
	   for(n = 0; n<80; n=n+2){
		   Setxy(n,4);
		   printf("�}");
		}
	for(k = 24; k<48; k=k+2){
	   Setxy(k,8);
	   printf("�}");
	   Setxy(k,20);
       printf("�}");
	}
	
	for (m = 8; m <= 20; m++)
	{
		Setxy(24, m);
		printf("�}");
		Setxy(48, m);
		printf("�}");
	}
}

/***************���ؿ���̨���***************/
void HideCursor()
{
	CONSOLE_CURSOR_INFO cursor_info = {1, 0};
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor_info);
}
/***************�����ؿ���̨���***************/
void DisplayCursor()
{
	CONSOLE_CURSOR_INFO cursor_info = {20, 1};
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor_info);
}
/***************�������λ��***************/
void Setxy(int x, int y){
	COORD coord = {x,y};
   SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}