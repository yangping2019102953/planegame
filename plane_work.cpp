#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<windows.h>
//����ȫ�ֱ���
//���÷ɻ��˶���Χ
int bord_x;
int bord_y;
//����ɻ�λ��
int flay_x;
int flay_y;
//�����ӵ�λ��
int zidan_x;
int zidan_y;
//�л�λ��
int diji_x;
int diji_y;
//����
int score=0;
//�ٶ�
int  speed=-1;
void gotoxy(int x, int y) {  //����ƶ���{x,y}
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD pos ;
	pos.X=x;
	pos.Y=y;
    SetConsoleCursorPosition(handle, pos);
}
void HideCursor(){
	CONSOLE_CURSOR_INFO cursor_info={1,0}; //�ڶ�ֵΪ0��ʾ���ع��
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE),&cursor_info);
}
void inst(){
     bord_x=20;
	 bord_y=20;
	 flay_x=bord_x/2;
	 flay_y=bord_y/2;
     zidan_x=flay_x;
	 zidan_y=-1;
	 diji_y=0;
	 diji_x=rand()%20;
}
void show(){
	gotoxy(0, 0);
	int i=0;
	int j=0;
	for(i=0;i<bord_y;i++)
	{
		for(j=0;j<bord_x;j++)
		{
			if((i==flay_y)&&(j==flay_x)){//��ʾ�ɻ�
                  printf("*");
			}
			else if((i==zidan_y)&&(j==zidan_x)){//��ʾ�ӵ�
                  printf("|");
			}
		    else if((i==diji_y)&&(j==diji_x)){	//��ʾ�л�
                  printf("@");
			}
			else{
				printf(" ");
			}
		}
		printf("\n");
	}
	printf("����ǰ�÷�Ϊ:%d",score);
	//Sleep(400);	
}
void userinput(){
	char input;
	if(kbhit()){
		input=getch();
	//���Ʒɻ��ƶ�
	if(input=='a'){
		flay_x--;
	}
	if(input=='d'){
		flay_x++;
	}
	if(input=='w'){
		flay_y--;
	}
	if(input=='x'){
		flay_y++;
	}
	if(input==' '){
	    zidan_y=flay_y-1;
        zidan_x=flay_x;

	}
	}
}
void movebyself(){

	  //�ӵ��ƶ�
      zidan_y=zidan_y--;
	  
	  if(speed<5)
	  {
		  speed++;
	  }
	  if(speed==5){
	  //�л��߽���
	  if((diji_y>bord_y))
	  {
         diji_y=0;
	     diji_x=rand()%20;
	  }
	  else
		  diji_y=diji_y++;
	  speed=0;
	  }
	  //���ел��ӷ�
	  if((diji_x==zidan_x)&&(diji_y==zidan_y))
	  {
		  diji_y=0;
	      diji_x=rand()%20;
		  score=score+10;
	  }
	  //���л�����
	  if((diji_x==flay_x)&&(diji_y==flay_y))
	  {
		  
		  score=score-10;
		  diji_y=0;
	      diji_x=rand()%20;
		  if(score>0)
		  {
		  printf("\n");
		  printf("����c��������Ϸ������e��������Ϸ����ѡ��c����e");
		  char cha;
		  cha=getch();
       	  if(cha=='c')
		  {
			  movebyself();
		  }
		  if(cha=='e')
		  {
			  exit(0);
             
		  }
		}
		  
		  


	  }
	  //�ɻ������߽���
	  if(flay_x<0)
		  flay_x=0;
	  if(flay_x>bord_x)
		  flay_x=bord_x-1;
	  if(flay_y<0)
		  flay_y=0;
	  if(flay_y>bord_y)
		  flay_y=bord_y-1;

	 
}

int main(){
	system("cls");
	HideCursor();
	inst();
	while(1){
		if(score<0)
			exit(0);
		system("cls");
    	show();
		userinput();
		movebyself();

	}
    	return 0;
}