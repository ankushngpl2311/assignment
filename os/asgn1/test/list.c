#include<stdio.h>
#include<unistd.h>
#include<dirent.h>
#include<sys/types.h>
int main()
{  ino_t fsrno;
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
  // printf("cwd =%s\n",p);
  // printf("dir=== %s",d.d_name);

}
