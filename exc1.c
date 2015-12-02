#include <stdio.h>
#include <string.h>
//#define 1000 100
char filename[20];
int i=0;
int n[3]={0,0,0};//各专业人数 
int comtotal=0,nettotal=0,objtotal=0;//各专业各科目成绩 

struct student
{
	char name[20];
	char majorname[20];
	int englishgrade;
	int linegrade;
	int cgrade;
	int totalgrade;
 };
struct student pstudents[1000];
 
 
 
 
int ReadStudentInfo(char filename[20],struct student pstudents[1000])
{
 	int k=0; 
 	FILE * fp;
 	fp=fopen(filename,"r");
 	
 	if((fp=fopen(filename,"r")) == NULL)//打开操作不成功
{
    puts("The file can not be opened.\n");
}

while(!feof(fp))
{
	fscanf(fp,"%s %s %d %d %d",&pstudents[k].name,&pstudents[k].majorname,&pstudents[k].englishgrade,&pstudents[k].linegrade,&pstudents[k].cgrade);
	k++;i++;
 } 
 
fclose(fp);
printf("人数%d",i);
return i;
}

//#define A1 "通信"//(if(pstudents[j].majorname=="通信"))
//#define A2 "网络"//(elseif(pstudents[j].majorname=="网络"))
//#define A3 "物联网"//(elseif(pstudents[j].majorname=="物联网"))
void Count(struct student pStudents[],int num)
{ int j; 
	for(j=0;j<num;j++)
	{
		
		 
		pstudents[j].totalgrade=pstudents[j].cgrade+pstudents[j].englishgrade+pstudents[j].linegrade;
		if(strcmp(pstudents[j].majorname,"通信")==0)
		{
			
			comtotal=comtotal+pstudents[j].totalgrade;
			n[0]++;
		}
		else if(strcmp(pstudents[j].majorname,"网络")==0)
		{
			nettotal+=pstudents[j].totalgrade;
			n[1]++;
		}
		else if(strcmp(pstudents[j].majorname,"物联网")==0)
		{
			objtotal+=pstudents[j].totalgrade;
			n[2]++;
	    }
	    }

	    {
	    	comtotal=comtotal/n[0];
	    	nettotal=nettotal/n[1];
	    	objtotal=objtotal/n[2];
		}
}

void output(struct student pstudents[1000],int num)
{
	int k;
	printf("学生信息：\n-----------------------------------------------------\n");
	printf("序号  姓    名  专业名称  英语成绩  线性代数成绩  C成绩  总成绩\n");
	for(k=0;k<num;k++) 
	{
		
		printf("%4d  %8s  %8s  %8d  %12d  %5d  %6d\n",k+1,pstudents[k].name,pstudents[k].majorname,pstudents[k].englishgrade,pstudents[k].linegrade,pstudents[k].cgrade,pstudents[k].totalgrade);
		 
	}
	
	printf("统计信息：\n-----------------------------------------------------\n");
    printf("序号 专业名称 学生人数 平均成绩\n");
    printf("   1     通信 %8d %8d\n",n[0],comtotal);
    printf("   2     网络 %8d %8d\n",n[1],nettotal);
    printf("   3   物联网 %8d %8d\n",n[2],objtotal);
    
     
} 

int main()
{   
 	
    scanf("%s",&filename);
 	if(ReadStudentInfo(filename,pstudents)==-1)
 	{
 	  printf("error");
	  return 0;	
    } 
    
   Count(pstudents,i);
    
    output(pstudents,i);
    
}
