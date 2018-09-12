#include<stdio.h>

#include<unistd.h>
#include<dirent.h>
#include<sys/types.h>
int main()
{   int i;
for(i=0;i<20;i++)
  printf("\014");
    
printf("\011\011\011File explorer\011\011\011\011\011");
  for(i=0;i<15;i++)
  printf("\014");
  //printf("\014");

   //ino_t fsrno;
   char a[100];
   char *p,*p2;
   struct dirent* dirpnt; 
   DIR *dir;
   p= getcwd(a,100);
   dir=opendir(p);
   while(dirpnt=readdir(dir))
   {
     printf("%s\n",dirpnt->d_name);
   }
   closedir(dir);
    int b;
   printf("\011\011 command mode:");
     scanf("%d",&b);
for(i=0;i<10;i++)
  printf("\014");
  
return 0;
}
