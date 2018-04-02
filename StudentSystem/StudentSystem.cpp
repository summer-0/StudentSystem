# include <stdio.h>
# include <conio.h>
# include <stdlib.h>
# include <windows.h>
# include <malloc.h>
# include <string.h>

//函数声明部分*************************
void MainOperate(); //主界面
void AdminLoginFace();  //管理员主界面
void AdminRegister(struct Adminer * );//管理员注册
void AdminLogin(struct Adminer * );  //管理员登录
void AdminSucceed();  //管理员登录成功

void StudentLoginFace();//学生主界面
void StudentLogin(struct Studenter * );//学生登录
void StudentRegister(struct Studenter * );//学生注册
void StudentSucceed(char str[]);  //学生登录成功

void StudentScoreEnter();      //学生成绩录入
void StudentScoreManage();    //学生成绩管理

void addScore();   //添加学生成绩
void deleteScore(); //删除学生成绩
void modifyScore(); //修改学生成绩
void lookAllScore(); //查看所有学生成绩
void sortScore();   //成绩排序

void scoreSeek(char str[]);      //成绩查询(学生部分)
void gpaSeek(char str[]);    //绩点查询(学生部分)

struct Adminer * ReadAdmin();//读取管理者信息
struct Studenter * ReadStudent(); //读取学生信息
struct StudentScore * ReadStudentScore();//读取学生成绩信息
void MainOperateDecorate();  //所有界面修饰
void ScoreLayout();  //成绩显示布局
void gpaLayout();   //绩点显示布局
void CleanAll();  //清除界面所有
void CleanArea(); //清除部分界面
void HideCursor(); //隐藏控制台光标
void DisplayCursor();  //显示控制台光标
void Setxy(int x, int y); //定义光标的位置
//函数声明部分*************************


//结构体****************************
typedef struct Adminer{
    char usrname[20];
	char password[20];
    struct Adminer * Next; //指针域
}Admin;
typedef struct Studenter{
    char usrname[20];
	char password[20];
    struct Studenter * Next; //指针域
}Student;

typedef struct StudentScore{  //学生成绩结构体
    char ID[20]; //学号
	char Name[20];//姓名
    float Math, English, Computer, JavaP, PE,total,GPA;  //GPA 绩点
	struct StudentScore * Next;  //指针域

}StScore;
//结构体****************************




int main(){
   system("color 20");  //设置控制台颜色
   HideCursor();       //隐藏光标
   system("mode con cols=80 lines=30"); //设置控制台宽高
   MainOperate();     //主界面函数
   
   getchar();
   return 0;
}


/***************主界面***************/
void MainOperate(){

	CleanAll();  //清除界面所有
	MainOperateDecorate();   //所有界面修饰
	Setxy(30,2);
	printf("欢迎使用本系统");
	Setxy(30,11);
	printf("1. 管理员登录\n");
	Setxy(30,13);
	printf("2. 学生登录\n");
	Setxy(30,15);
	printf("3. 退出\n");

	while(1){
		char opt;
		opt = _getch();
		switch(opt){
		  case '1':
			AdminLoginFace();   //管理员登录主界面
			break;
		  case '2':
			StudentLoginFace();  //学生登录主界面
			break;
		  case '3':
			  Setxy(10,25);
			  exit(0);       //退出
			break;
		  default:
			  break;
		}
	}
	return;
	
}
/***************管理员主界面***************/
void AdminLoginFace(){
    CleanAll();	  //清除界面所有
	MainOperateDecorate();   //所有界面修饰
	
    Setxy(30,2);
	printf("管理员首页");
	Setxy(30,10);
	printf("1. 登录\n");
	Setxy(30,12);
	printf("2. 注册\n");
	Setxy(30,14);
	printf("3. 返回主界面\n");
	Setxy(30,16);
	printf("4. 退出\n");

	
	while(1){
       Admin * admin = NULL;
	   char opt;
	   opt = _getch();
	   switch(opt){
	      case '1':
			  AdminLogin(admin);  //管理员登录
			  break;
		  case '2':
			  AdminRegister(admin);  //管理员注册
			  break;
		  case '3':
			  MainOperate();    //主界面函数
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

/***************管理员登录***************/
void AdminLogin(struct Adminer * p){
    CleanAll();	   //清除界面所有
	MainOperateDecorate();  //所有界面修饰
	DisplayCursor();    //显示控制台光标
	
	Setxy(30,2);
	printf("管理员登录");
	Setxy(30,11);
	printf("用户名：\n");   
	Setxy(30,13);
	printf("密  码：\n"); 
	Setxy(28,16);
	printf("取消(N)");
	Setxy(38,16);
	printf("登录(Y)");
	FILE * fp ;
	Admin * q = NULL;
	p = (Admin *)malloc(sizeof(Admin));

	Setxy(38,11);
	scanf("%s",p->usrname);
	Setxy(38,13);
	scanf("%s",p->password);
	HideCursor();   //隐藏控制台光标
	if((fp = fopen("admin.txt","ab")) == NULL){
		fclose(fp);
		if((fp = fopen("admin.txt","wb")) == NULL){
		    Setxy(32, 15);
			printf("文件出错！");
			Setxy(30, 18);
			printf("请按任意键返回!");
			_getch();
			CleanAll();
			AdminLoginFace();
			return ;
		}
	 
	}
	q = ReadAdmin();
	
    /*管理员登录密码匹配部分**/
   	while(1){
		    int i=0;
			char opt;
			opt = _getch();
			if('n' == opt || 'N' == opt){
				AdminLoginFace();
			}

			else if('y' == opt || 'Y' == opt){
				
				
				  
					while(q != NULL){
					
					
					if(strcmp(p->usrname,q->usrname) == 0 && strcmp(p->password,q->password) == 0) //判断用户名和密码是否匹配
					{

				      CleanAll();  //清除界面所有
				      AdminSucceed();  //管理员登录成功
					  return;
					}
					q = q->Next;
					i++;
					Setxy(40,22);
					printf("%d",i);

					}
				     Setxy(26,17);
					 printf("用户不存在或密码错误!");  
					 Setxy(30,18);
					 printf("按任意键返回!");  /*用户不存在或密码错误返回管理员登录主界面**/
					 _getch();
					 AdminLoginFace();   //管理员登录主界面
			     
			}else{
				Setxy(32,18);
				printf("请输入Y/N");
				Setxy(30,19);
				printf("按任意键返回!");
				_getch();
				AdminLogin(p);
			}
	}
	fclose(fp);
}

/***************管理员注册***************/
void AdminRegister(struct Adminer * p){
    CleanAll();	 //清除界面所有
	MainOperateDecorate();  //所有界面修饰
    DisplayCursor();  //显示控制台光标
	Setxy(30,2);
	printf("管理员注册");

    FILE * fp ;
	Admin * q = NULL;	
    p = (Admin *)malloc(sizeof(Admin));

	if((fp = fopen("admin.txt","ab")) == NULL){
		fclose(fp);
		if((fp = fopen("admin.txt","wb")) == NULL){
		    Setxy(32, 15);
			printf("文件出错！");
			Setxy(30, 18);
			printf("请按任意键返回!");
			_getch();
			CleanAll();  //清除界面所有
			AdminLoginFace();  //管理员登录主界面

			return ;
		}
	 
	}

	Setxy(30,11);
	printf("用户名：\n");  
	Setxy(30,13);
	printf("密  码：\n");   
	Setxy(28,16);
	printf("取消(N)");
	Setxy(38,16);
	printf("注册(Y)");
	Setxy(38,11);
	scanf("%s",&p->usrname);
	Setxy(38,13);
	scanf("%s",&p->password);
	HideCursor(); 
	q = ReadAdmin();
	/*判断用户是否已注册部分**/
	while(q != NULL){
	   if(strcmp(p->usrname,q->usrname) == 0){
		 
		 Setxy(30,17);
		 printf("该用户已注册!");
		 Setxy(30,18);
		 printf("按任意键返回!");
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
			printf("管理员注册");
			Setxy(32,13);
			printf("注册成功！");
			Setxy(30,17);
			printf("按任意键返回!");
			_getch();
            AdminLoginFace();
		}else{
		    Setxy(32,18);
			printf("请输入Y/N");
			Setxy(30,19);
			printf("按任意键返回!");
			_getch();
            AdminRegister(p);
		}

	}

}
/***************管理员登录成功***************/
void AdminSucceed(){
    CleanAll();  //清除界面所有
    MainOperateDecorate(); //所有界面修饰
	Setxy(30,2);
    printf("管理员登录成功");
	Setxy(30,11);
	printf("1. 学生成绩录入\n");
	Setxy(30,13);
	printf("2. 学生成绩管理\n");
	Setxy(30,15);
	printf("3. 返回主界面\n");
	Setxy(30,17);
	printf("4. 退出\n");
	HideCursor(); //隐藏控制台光标

	while(1){
		StScore * score = NULL;
		char opt;
		opt = _getch();
		switch(opt){
		  case '1':
			StudentScoreEnter();      //学生成绩录入
			break; 
		  case '2':
			StudentScoreManage();    //学生成绩管理
			break;
		  case '3':
			 MainOperate(); //主界面
			break;
		  case '4':
			Setxy(10,25);
			exit(0);   //退出
			break;
		  default:
			  break;
		}
	}
}
/***************学生成绩录入***************/
void StudentScoreEnter(){
	int count, i;
	FILE* fp = NULL;
	struct StudentScore* p = NULL;
    CleanAll();
    MainOperateDecorate();	
	CleanArea();  //清除部分界面
	DisplayCursor(); 
	Setxy(30,2);
    printf("学生成绩管理");
	Setxy(5,6);
	printf("请输入您要录入学生的个数：");
    Setxy(32,6);
	scanf("%d",&count);
	if(count <= 0 || count>15){
	    Setxy(40,6);
		printf("请输入有效个数! (1~15)");
		Setxy(40,7);
		printf("请按任意键返回!");
		_getch();
        AdminSucceed();
	    return;
	}
	ScoreLayout();
    if((fp = fopen("score.txt","ab")) == NULL){
	   fclose(fp);//关闭文件指针
	   if((fp = fopen("score.txt","wb")) == NULL){
	      Setxy(30,15);
		  printf("文件出错！");
		  Setxy(30,18);
		  printf("请按任意键返回！");
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
		   printf("学生信息创建失败！");
		   Setxy(30,19);
		   printf("按任意键返回！");
		   _getch();
           AdminSucceed();
		   return;
		}
        Setxy(1,12+i);
		scanf("%s",&(p->Name));  //姓名

		Setxy(10,12+i);
		scanf("%s",&(p->ID));  //学号
		Setxy(23,12+i);
		scanf("%f",&(p->Math));  //高数
		Setxy(30,12+i);
		scanf("%f",&(p->English));  //大英
		Setxy(39,12+i);
		scanf("%f",&(p->Computer));  //数据结构
		Setxy(48,12+i);
		scanf("%f",&(p->JavaP));  //java
		Setxy(54,12+i);
		scanf("%f",&(p->PE));  //体育
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
	printf("添加成功!");
	fclose(fp);
	Setxy(40,7);
	printf("请按任意键返回!");
	_getch();
	AdminSucceed();

	return;
}
/***************学生成绩管理***************/
void StudentScoreManage(){
    CleanAll();
    MainOperateDecorate();
	HideCursor();
	Setxy(30,2);
    printf("学生成绩管理");
	Setxy(30,10);
	printf("1. 查看成绩\n");
	Setxy(30,11);
	printf("2. 添加成绩\n");
	Setxy(30,12);
	printf("3. 成绩排序\n");
	Setxy(30,13);
	printf("4. 修改成绩\n");
	Setxy(30,14);
	printf("5. 删除成绩\n");
	Setxy(30,15);
	printf("6. 返回上一层\n");
	Setxy(30,16);
	printf("7. 返回主界面\n");
	Setxy(30,17);
	printf("8. 退出\n");
	//Setxy(30,18);
	//printf("9. 退出\n");
	while(1){
		StScore*  score = NULL;
		char opt;
		opt = _getch();
		switch(opt){
		  case '1':
			lookAllScore();//查看成绩
			break; 
		  case '2':
			addScore();    //添加成绩
			break;
		  case '3':
			sortScore();          //成绩排序
			break;
			case '4':
			modifyScore();    //修改成绩
			break;
		  case '5':                  
			deleteScore();         //删除成绩  
			break;
			case '6':
			AdminSucceed();     //返回上一层
			break;
		  case '7':
			MainOperate();          //返回主界面
			break;
		  case '8':
			Setxy(10,25);           //退出
			exit(0);         
			break;
		  default:
			  break;
		}
	}
}


/***************学生主界面***************/
void StudentLoginFace(){
    CleanAll();	
	MainOperateDecorate();
	
    Setxy(32,2);
	printf("学生登录");
	Setxy(30,10);
	printf("1. 登录\n");
	Setxy(30,12);
	printf("2. 注册\n");
	Setxy(30,14);
	printf("3. 返回主界面\n");
	Setxy(30,16);
	printf("4. 退出\n");
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
/***************学生登录***************/
void StudentLogin(struct Studenter * p){
    CleanAll();	
	MainOperateDecorate();
	DisplayCursor(); //隐藏光标
	Setxy(32,2);
	printf("学生登录");
	Setxy(30,11);
	printf("学  号：\n");   
	Setxy(30,13);
	printf("密  码：\n"); 
	Setxy(28,16);
	printf("取消(N)");
	Setxy(38,16);
	printf("登录(Y)");
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
			printf("文件出错！");
			Setxy(30, 18);
			printf("请按任意键返回!");
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
					
					
					if(strcmp(p->usrname,q->usrname) == 0 && strcmp(p->password,q->password) == 0) //判断用户名和密码是否匹配
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
					 printf("用户不存在或密码错误!");
					 Setxy(30,18);
					 printf("按任意键返回!"); 
					 _getch();
					 StudentLoginFace();
			     
			}else{
				Setxy(32,18);
				printf("请输入Y/N");
				Setxy(30,19);
				printf("按任意键返回!");
				_getch();
				StudentLogin(p);
			}
	}
	fclose(fp);
}
/***************学生注册***************/
void StudentRegister(struct Studenter * p){
    CleanAll();	
	MainOperateDecorate();
	FILE * fp =NULL ;
	struct Studenter * q = NULL;
	DisplayCursor();
	Setxy(32,2);
	printf("学生注册");
	
    p = (Student *)malloc(sizeof(Student));
	if((fp = fopen("student.txt","ab")) == NULL){
		fclose(fp);
		if((fp = fopen("student.txt","wb")) == NULL){
		    Setxy(32, 15);
			printf("文件出错！");
			Setxy(30, 18);
			printf("请按任意键返回!");
			_getch();
			CleanAll();
			StudentLoginFace();

			return ;
		}
	 
	}
	
	Setxy(30,11);
	printf("学  号：\n");  
	Setxy(30,13);
	printf("密  码：\n");   
	Setxy(28,16);
	printf("取消(N)");
	Setxy(38,16);
	printf("注册(Y)");
	Setxy(38,11);
	scanf("%s",&p->usrname);
	Setxy(38,13);
	scanf("%s",&p->password);
	HideCursor();
    q = ReadStudent();
	   
    while(q != NULL){
	   if(strcmp(p->usrname,q->usrname) == 0){
		 
		 Setxy(30,17);
		 printf("该用户已注册!");
		 Setxy(30,18);
		 printf("按任意键返回!");
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
			printf("学生注册");
			Setxy(32,13);
			printf("注册成功！");
			Setxy(30,17);
			printf("按任意键返回!");
			_getch();
            StudentLoginFace();
		}else{
		    Setxy(32,18);
			printf("请输入Y/N");
			Setxy(30,19);
			printf("按任意键返回!");
			_getch();
            StudentRegister(p);
		}

	}

}
/***************学生登录成功***************/
void StudentSucceed(char str[]){
	//char str[20];
    CleanAll();
    MainOperateDecorate();
	Setxy(30,2);
    printf("学生登录成功");
	
	Setxy(30,11);
	printf("1. 成绩查询\n");
	Setxy(30,13);
	printf("2. 绩点查询\n");
	Setxy(30,15);
	printf("3. 返回主界面\n");
	Setxy(30,17);
	printf("4. 退出\n");

	while(1){
		char opt;
		opt = _getch();
		switch(opt){
		  case '1':
			scoreSeek(str);      //成绩查询
			break; 
		  case '2':
			gpaSeek(str);    //绩点查询
			break;
		  case '3':
			 MainOperate();      //返回主界面
			break;
		  case '4':
			Setxy(10,25);         //退出
			exit(0); 
			break;
		  default:
			  break;
		}
	}
}
/***************读取管理者信息***************/
struct Adminer * ReadAdmin(){
    FILE * fp = NULL;
	struct Adminer * H = NULL, *p = NULL;
	struct Adminer * p1 = NULL;
	int i = 0;
	p1 = (struct Adminer*)malloc(sizeof(struct Adminer));
	if((fp = fopen("admin.txt","rb")) == NULL){
	   Setxy(70,16);
	   printf("文件操作失败!");
       fclose(fp);
	   Setxy(30,18);
	   printf("按任意键返回!");
       AdminLoginFace();
	   return NULL;
	}
	while(!feof(fp))
	{
		
	   p = (struct Adminer*)malloc(sizeof(struct Adminer));
       //开始读操作
	   fscanf(fp,"%s",&p->usrname); //用户名
	   fscanf(fp,"%s",&p->password);//密码
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
/***************读取学生信息***************/
struct Studenter * ReadStudent(){
    FILE * fp = NULL;
	struct Studenter * H = NULL, *p = NULL;
	struct Studenter * p1 = NULL;
	int i = 0;
	p1 = (struct Studenter*)malloc(sizeof(struct Studenter));
	if((fp = fopen("student.txt","rb")) == NULL){
	   Setxy(70,16);
	   printf("文件操作失败!");
       fclose(fp);
	   Setxy(30,18);
	   printf("按任意键返回!");
       StudentLoginFace();
	   return NULL;
	}
	while(!feof(fp))
	{
		
	   p = (struct Studenter*)malloc(sizeof(struct Studenter));
       //开始读操作
	   fscanf(fp,"%s",&p->usrname); //用户名
	   fscanf(fp,"%s",&p->password);//密码
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
/***************查看所有学生成绩***************/
void lookAllScore(){
    CleanAll();
    MainOperateDecorate();	
	CleanArea();
	Setxy(30,2);
    printf("所有学生成绩");
	ScoreLayout();
	struct StudentScore *q = NULL;
	FILE* fp = NULL;
    if((fp = fopen("score.txt","ab")) == NULL){
		fclose(fp);
		if((fp = fopen("score.txt","wb")) == NULL){
		    Setxy(32, 15);
			printf("文件出错！");
			Setxy(30, 18);
			printf("请按任意键返回!");
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
		printf("%s",q->Name);  //姓名
		Setxy(10,12+i);
		printf("%s",q->ID);  //学号
		Setxy(23,12+i);
		printf("%.f",q->Math);  //高数
		Setxy(30,12+i);
		printf("%.f",q->English);  //大英
		Setxy(39,12+i);
		printf("%.f",q->Computer);  //数据结构
		Setxy(48,12+i);
		printf("%.f",q->JavaP);  //java
		Setxy(54,12+i);
		printf("%.f",q->PE);    //体育
		Setxy(60,12+i);
		printf("%.f",q->total);  //总分
		Setxy(68,12+i);
		printf("%.2f",q->GPA);  //绩点
		q = q->Next;
		i++;
		}
	Setxy(2,6);
	printf("%d",i);
	fclose(fp);
	Setxy(31, 6);
	printf("请按任意键返回!");
	_getch();
	StudentScoreManage();	
	
}
/***************添加学生成绩***************/
void addScore(){
    int count, i;
	FILE* fp = NULL;
	struct StudentScore* p = NULL;
    CleanAll();
    MainOperateDecorate();	
	CleanArea();
	DisplayCursor();
	Setxy(30,2);
    printf("添加成绩");
	Setxy(5,6);
	printf("请输入您要添加学生的个数：");
    Setxy(32,6);
	scanf("%d",&count);
	if(count <= 0 || count>15){
	    Setxy(40,6);
		printf("请输入有效个数! (1~15)");
		Setxy(40,7);
		printf("请按任意键返回!");
		_getch();
        StudentScoreManage();
	    return;
	}
	ScoreLayout();
    if((fp = fopen("score.txt","ab")) == NULL){
	   fclose(fp);//关闭文件指针
	   if((fp = fopen("score.txt","wb")) == NULL){
	      Setxy(30,15);
		  printf("文件出错！");
		  Setxy(30,18);
		  printf("请按任意键返回！");
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
		   printf("学生信息创建失败！");
		   Setxy(30,19);
		   printf("按任意键返回！");
		   _getch();
           StudentScoreManage();
		   return;
		}
        Setxy(1,12+i);
		scanf("%s",&(p->Name));  //姓名

		Setxy(10,12+i);
		scanf("%s",&(p->ID));  //学号
		Setxy(23,12+i);
		scanf("%f",&(p->Math));  //高数
		Setxy(30,12+i);
		scanf("%f",&(p->English));  //大英
		Setxy(39,12+i);
		scanf("%f",&(p->Computer));  //数据结构
		Setxy(48,12+i);
		scanf("%f",&(p->JavaP));  //java
		Setxy(54,12+i);
		scanf("%f",&(p->PE));  //体育
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
	printf("添加成功!");
	fclose(fp);
	Setxy(40,7);
	printf("请按任意键返回!");
	_getch();
	StudentScoreManage();
}
/***************删除学生成绩***************/
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
    printf("删除学生成绩");
	ScoreLayout();  
	
	FILE* fp = NULL;
	char str[20];
    if((fp = fopen("score.txt","ab")) == NULL){
		fclose(fp);
		if((fp = fopen("score.txt","wb")) == NULL){
		    Setxy(32, 15);
			printf("文件出错！");
			Setxy(30, 18);
			printf("请按任意键返回!");
			_getch();
			CleanAll();
			StudentScoreManage();
			return ;
		}
	 
	}
	
    int i=0,j=0;
	while(q != NULL){
		Setxy(1,12+i);
		printf("%s",q->Name);  //姓名
		Setxy(10,12+i);
		printf("%s",q->ID);  //学号
		Setxy(23,12+i);
		printf("%.f",q->Math);  //高数
		Setxy(30,12+i);
		printf("%.f",q->English);  //大英
		Setxy(39,12+i);
		printf("%.f",q->Computer);  //数据结构
		Setxy(48,12+i);
		printf("%.f",q->JavaP);  //java
		Setxy(54,12+i);
		printf("%.f",q->PE);    //体育
		Setxy(60,12+i);
		printf("%.f",q->total);  //总分
		Setxy(68,12+i);
		printf("%.2f",q->GPA);  //绩点
		q = q->Next;
		i++;
		}
	q = p;
	Setxy(2,6);
	printf("%d",i);
	fclose(fp);
	Setxy(31, 6);
	printf("请输入您要删除学生的学号:");
	Setxy(58,6);
	scanf("%s",str);
	while(1){
	   if(strcmp(str,p->ID) == 0 ){
	       break;
	   }
	   else{
		   if(p->Next == NULL){
			  Setxy(35,7);
			  printf("无此学生!按任意键返回!");
			  _getch();
              StudentScoreManage();
		      return;
		   }
	       p=p->Next;
	   }
	}
	/**************************************************************/    //删除学生成绩然后输出屏幕中
	if(strcmp(str,n->ID) == 0)
	{
		q = n->Next;
        h = n->Next;
        
		while(q != NULL){
		Setxy(1,20+j);
		printf("%s",q->Name);  //姓名
		Setxy(10,20+j);
		printf("%s",q->ID);  //学号
		Setxy(23,20+j);
		printf("%.f",q->Math);  //高数
		Setxy(30,20+j);
		printf("%.f",q->English);  //大英
		Setxy(39,20+j);
		printf("%.f",q->Computer);  //数据结构
		Setxy(48,20+j);
		printf("%.f",q->JavaP);  //java
		Setxy(54,20+j);
		printf("%.f",q->PE);    //体育
		Setxy(60,20+j);
		printf("%.f",q->total);  //总分
		Setxy(68,20+j);
		printf("%.2f",q->GPA);  //绩点
		q = q->Next;
		j++;
		}
       if((fp = fopen("score.txt","wb")) == NULL){
		   fclose(fp);//关闭文件指针
		   if((fp = fopen("score.txt","wb")) == NULL){
			  Setxy(30,15);
			  printf("文件出错！");
			  Setxy(30,18);
			  printf("请按任意键返回！");
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
	   printf("学生成绩已删除!按任意键返回!");
	  
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
				printf("%s",q->Name);  //姓名
				Setxy(10,20+j);
				printf("%s",q->ID);  //学号
				Setxy(23,20+j);
				printf("%.f",q->Math);  //高数
				Setxy(30,20+j);
				printf("%.f",q->English);  //大英
				Setxy(39,20+j);
				printf("%.f",q->Computer);  //数据结构
				Setxy(48,20+j);
				printf("%.f",q->JavaP);  //java
				Setxy(54,20+j);
				printf("%.f",q->PE);    //体育
				Setxy(60,20+j);
				printf("%.f",q->total);  //总分
				Setxy(68,20+j);
				printf("%.2f",q->GPA);  //绩点
				q = q->Next;
				j++;
				}
			  if((fp = fopen("score.txt","wb")) == NULL){
				   fclose(fp);//关闭文件指针
				   if((fp = fopen("score.txt","wb")) == NULL){
					  Setxy(30,15);
					  printf("文件出错！");
					  Setxy(30,18);
					  printf("请按任意键返回！");
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
			  printf("学生成绩已删除!按任意键返回!");
			  _getch();
			  StudentScoreManage();
			  return;
			}

				

		}while(n->Next != NULL);
	}
	

	

	////////删除后重新写入
	/*if((fp = fopen("score.txt","ab")) == NULL){
	   fclose(fp);//关闭文件指针
	   if((fp = fopen("score.txt","wb")) == NULL){
	      Setxy(30,15);
		  printf("文件出错！");
		  Setxy(30,18);
		  printf("请按任意键返回！");
		  _getch();
         StudentScoreManage();
		 return;
	   }
	}*/

	 /*while(q != NULL){
		Setxy(1,18+j);
		printf("%s",q->Name);  //姓名
		Setxy(10,18+j);
		printf("%s",q->ID);  //学号
		Setxy(23,18+j);
		printf("%.f",q->Math);  //高数
		Setxy(30,18+j);
		printf("%.f",q->English);  //大英
		Setxy(39,18+j);
		printf("%.f",q->Computer);  //数据结构
		Setxy(48,18+j);
		printf("%.f",q->JavaP);  //java
		Setxy(54,18+j);
		printf("%.f",q->PE);    //体育
		Setxy(60,18+j);
		printf("%.f",q->total);  //总分
		Setxy(68,18+j);
		printf("%.f",q->GPA);  //绩点
		q = q->Next;
		j++;
		}*/


//	_getch();
//	StudentScoreManage();	
}
/***************修改学生成绩***************/
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
    printf("修改成绩");
	ScoreLayout();
	while(q != NULL){
		Setxy(1,12+k);
		printf("%s",q->Name);  //姓名
		Setxy(10,12+k);
		printf("%s",q->ID);  //学号
		Setxy(23,12+k);
		printf("%.f",q->Math);  //高数
		Setxy(30,12+k);
		printf("%.f",q->English);  //大英
		Setxy(39,12+k);
		printf("%.f",q->Computer);  //数据结构
		Setxy(48,12+k);
		printf("%.f",q->JavaP);  //java
		Setxy(54,12+k);
		printf("%.f",q->PE);    //体育
		Setxy(60,12+k);
		printf("%.f",q->total);  //总分
		Setxy(68,12+k);
		printf("%.2f",q->GPA);
		q = q->Next;
		k++;
		}
	Setxy(31, 6);
	printf("请输入您要修改学生的学号:");
	Setxy(58,6);
	scanf("%s",str);
	while(1){
	   if(strcmp(str,p->ID) == 0 ){
	       break;
	   }
	   else{
		   if(p->Next == NULL){
			  Setxy(35,7);
			  printf("无此学生!按任意键返回!");
			  _getch();
              StudentScoreManage();
		      return;
		   }
	       p=p->Next;
	   }
	}
	Setxy(5,22);
	printf("请重新输入学生成绩:");
	Setxy(1,23);
	scanf("%s",&(p->Name));  //姓名
	Setxy(10,23);
	scanf("%s",&(p->ID));  //学号
	Setxy(23,23);
	scanf("%f",&(p->Math));  //高数
	Setxy(30,23);
	scanf("%f",&(p->English));  //大英
	Setxy(39,23);
	scanf("%f",&(p->Computer));  //数据结构
	Setxy(48,23);
	scanf("%f",&(p->JavaP));  //java
	Setxy(54,23);
	scanf("%f",&(p->PE));  //体育
	sum = p->Computer + p->English + p->JavaP + p->Math + p->PE;
	gpa = (sum/5 - 60)/10 + 1;
	p->GPA = gpa;
	p->total = sum;
	Setxy(62,23);
	printf("%.f",p->total);
	Setxy(68,23);
	printf("%.2f",p->GPA);
	Setxy(15,24);
	printf("成绩已修改!请按任意键返回!");
	if((fp = fopen("score.txt","wb")) == NULL){
	   fclose(fp);//关闭文件指针
	   if((fp = fopen("score.txt","wb")) == NULL){
		  Setxy(30,15);
		  printf("文件出错！");
		  Setxy(30,18);
		  printf("请按任意键返回！");
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

/***************学生成绩排序***************/
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
    printf("成绩排序");
	ScoreLayout();  //成绩显示布局
	FILE * fp = NULL;
	if((fp = fopen("score.txt","ab")) == NULL){
		fclose(fp);
		if((fp = fopen("score.txt","wb")) == NULL){
		    Setxy(32, 15);
			printf("文件出错！");
			Setxy(30, 18);
			printf("请按任意键返回!");
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
				strcpy(str1,m->Name);  //换姓名
				strcpy(m->Name,n->Name);
				strcpy(n->Name,str1);
				strcpy(str2,m->ID);  //换学号
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
		printf("%s",q->Name);  //姓名
		Setxy(10,12+k);
		printf("%s",q->ID);  //学号
		Setxy(23,12+k);
		printf("%.f",q->Math);  //高数
		Setxy(30,12+k);
		printf("%.f",q->English);  //大英
		Setxy(39,12+k);
		printf("%.f",q->Computer);  //数据结构
		Setxy(48,12+k);
		printf("%.f",q->JavaP);  //java
		Setxy(54,12+k);
		printf("%.f",q->PE);    //体育
		Setxy(60,12+k);
		printf("%.f",q->total);  //总分
		Setxy(68,12+k);
		printf("%.2f",q->GPA);
		q = q->Next;
		//len++;
		k++;

		}		
	
	fclose(fp);
	Setxy(12, 6);
	printf("请按任意键返回!");
	_getch();
	StudentScoreManage();  //学生成绩管理


}
/***************成绩查询(学生部分)***************/
void scoreSeek(char str[]){  
    struct StudentScore *q = NULL;
	q = ReadStudentScore();
    CleanAll();
    MainOperateDecorate();	
	CleanArea();
	Setxy(34,2);
    printf("成绩查询");
	ScoreLayout();
    while(1){
	   if(strcmp(str,q->ID) == 0 ){
		   //p = q;
	       break;
	   }
	   else{
		   if(q->Next == NULL){
			  Setxy(35,7);
			  printf("暂无成绩!按任意键返回!");
			  _getch();
              StudentSucceed(str);
		      return;
		   }
	       q=q->Next;
	   }
	}
	Setxy(1,12);
	printf("%s",q->Name);  //姓名
	Setxy(10,12);
	printf("%s",q->ID);  //学号
	Setxy(23,12);
	printf("%.f",q->Math);  //高数
	Setxy(30,12);
	printf("%.f",q->English);  //大英
	Setxy(39,12);
	printf("%.f",q->Computer);  //数据结构
	Setxy(48,12);
	printf("%.f",q->JavaP);  //java
	Setxy(54,12);
	printf("%.f",q->PE);    //体育
	Setxy(60,12);
	printf("%.f",q->total);  //总分
	Setxy(66,12);
	printf("%.2f",q->GPA);   //绩点
	Setxy(30,18);
	printf("请按任意键返回!");
	_getch();
	StudentSucceed(str);

}
/***************绩点查询(学生部分)***************/
void gpaSeek(char str[]){
   struct StudentScore *q = NULL;
	q = ReadStudentScore();
    CleanAll();
    MainOperateDecorate();	
	CleanArea();
	Setxy(34,2);
    printf("绩点查询");
	gpaLayout();
    while(1){
	   if(strcmp(str,q->ID) == 0 ){
	       break;
	   }
	   else{
		   if(q->Next == NULL){
			  Setxy(35,7);
			  printf("暂无成绩!按任意键返回!");
			  _getch();
              StudentSucceed(str);
		      return;
		   }
	       q=q->Next;
	   }
	}
	Setxy(1,12);
	printf("%s",q->Name);  //姓名
	Setxy(10,12);
	printf("%s",q->ID);  //学号
	Setxy(23,12);
	printf("%.2f",(q->Math-60)/10+1);  //高数
	Setxy(30,12);
	printf("%.2f",(q->English-60)/10+1);  //大英
	Setxy(39,12);
	printf("%.2f",(q->Computer-60)/10+1);  //数据结构
	Setxy(46,12);
	printf("%.2f",(q->JavaP-60)/10+1);  //java
	Setxy(54,12);
	printf("%.2f",(q->PE-60)/10+1);    //体育
	Setxy(60,12);
	printf("%.2f",q->GPA);  //总绩点
	Setxy(30,18);
	printf("请按任意键返回!");
	_getch();
	StudentSucceed(str);

}    
/***************读取学生成绩***************/
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
	   printf("文件操作失败!");
       fclose(fp);
	   Setxy(30,18);
	   printf("按任意键返回!");
       StudentScoreManage();
	   return NULL;
	}

	if((ft = fopen("score.txt","rb")) == NULL){
	   Setxy(70,16);
	   printf("文件操作失败!");
       fclose(ft);
	   Setxy(30,18);
	   printf("按任意键返回!");
       StudentScoreManage();
	   return NULL;
	}


	while(!feof(fp))
	 {
	   p = (struct StudentScore*)malloc(sizeof(struct StudentScore));
       //开始读操作
	   
	   fscanf(fp,"%s",&p->Name); //姓名
	   fscanf(fp,"%s",&p->ID);   //学号
	   fscanf(fp,"%f",&p->Math); //高数
	   fscanf(fp,"%f",&p->English);   //大英
	   fscanf(fp,"%f",&p->Computer); //数据结构
	   fscanf(fp,"%f",&p->JavaP);   //java
	   fscanf(fp,"%f",&p->PE); //体育
	   fscanf(fp,"%f",&p->total);   //总分
	   fscanf(fp,"%f",&p->GPA);    //绩点
       
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
       //开始读操作
	   
	   fscanf(ft,"%s",&p->Name); //姓名
	   fscanf(ft,"%s",&p->ID);   //学号
	   fscanf(ft,"%f",&p->Math); //高数
	   fscanf(ft,"%f",&p->English);   //大英
	   fscanf(ft,"%f",&p->Computer); //数据结构
	   fscanf(ft,"%f",&p->JavaP);   //java
	   fscanf(ft,"%f",&p->PE); //体育
	   fscanf(ft,"%f",&p->total);   //总分
       fscanf(ft,"%f",&p->GPA);    //绩点
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
/***************成绩显示布局***************/
void ScoreLayout(){
    Setxy(1,8);
	printf("******************************************************************************");
	Setxy(1,10);
	printf("******************************************************************************");
	Setxy(1,9);
	printf("姓名");
	Setxy(11,9);
	printf("学号");
	Setxy(22,9);
	printf("高数");
	Setxy(29,9);
	printf("大英");
	Setxy(36,9);
	printf("数据结构");
	Setxy(47,9);
	printf("Java");
	Setxy(53,9);
	printf("体育");
	Setxy(59,9);
	printf("总分");
	Setxy(66,9);
	printf("绩点");

}
/***************绩点显示布局***************/
void gpaLayout(){
    Setxy(1,8);
	printf("******************************************************************************");
	Setxy(1,10);
	printf("******************************************************************************");
	Setxy(1,9);
	printf("姓名");
	Setxy(11,9);
	printf("学号");
	Setxy(22,9);
	printf("高数");
	Setxy(29,9);
	printf("大英");
	Setxy(36,9);
	printf("数据结构");
	Setxy(47,9);
	printf("Java");
	Setxy(53,9);
	printf("体育");
	Setxy(59,9);
	printf("平均绩点");
	

}
/***************清除控制台***************/
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
/***************所有界面修饰***************/
void MainOperateDecorate(){
    int m, k;
	int n;
	   for(n = 0; n<80; n=n+2){
		   Setxy(n,4);
		   printf("▆");
		}
	for(k = 24; k<48; k=k+2){
	   Setxy(k,8);
	   printf("▆");
	   Setxy(k,20);
       printf("▆");
	}
	
	for (m = 8; m <= 20; m++)
	{
		Setxy(24, m);
		printf("▆");
		Setxy(48, m);
		printf("▆");
	}
}

/***************隐藏控制台光标***************/
void HideCursor()
{
	CONSOLE_CURSOR_INFO cursor_info = {1, 0};
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor_info);
}
/***************不隐藏控制台光标***************/
void DisplayCursor()
{
	CONSOLE_CURSOR_INFO cursor_info = {20, 1};
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor_info);
}
/***************定义光标的位置***************/
void Setxy(int x, int y){
	COORD coord = {x,y};
   SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}