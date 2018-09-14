awk 'BEGIN{max=0;min=100;sum=0;
 printf("​ *** Grade Report for the ABC course ***\n");
 printf("Name   Grade\n"); }

{ if(NR>1) 
  {
   x=$3+$4+$5;
   if(x>max)
   {
     max=x;
   }
   if(min<x)
   {
     min=x;
    }

   sum=sum+x;
  
  
  
  if(x>=95&&x<=100)
  {
    printf("   %s   %s\n",$1,"A");
   }
  else if(x>=90&&x<95)
  {
   printf("   %s   %s\n",$1,"A-");
  }
   else if(x>=85&&x<90)
  {
   printf("   %s   %s\n",$1,"B");
  }
   else if(x>=80&&x<85)
  {
   printf("   %s   %s\n",$1,"B-");
  }
   else if(x>=75&&x<80)
  {
   printf("   %s   %s\n",$1,"C");
  }
   else if(x>=70&&x<75)
  {
   printf("   %s   %s\n",$1,"C-");
  }
   else if(x>=60&&x<70)
  {
   printf("   %s   %s\n",$1,"D");
  }
   else
  {
   printf("   %s   %s\n",$1,"F");
  }
 }
}

END{
printf("Total Students = %d\n",NR-1);
printf("Highest marks  = %d\n",max);
printf("Lowest marks   = %d\n",min);
avg=sum/(NR-1);
printf("Average marks  = %0.2f\n",avg);


printf("​***End of Grade Report***\n");}'  marks.txt
