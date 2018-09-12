#include<stdio.h>
#include<iostream>
#include<string>
#include<vector>
#include<string.h>
#include<algorithm>
using namespace std;

vector <int> va;
vector <int> vb;
vector <int> res;


void makelen(string &a,string &b)
{
	 int la=a.length();
     int lb=b.length();
     
     
     va.clear();
     vb.clear();
     res.clear();

     int i,j;

     for(i=0;i<la;i++)
     	va.push_back(a[i]-'0');

     for(i=0;i<lb;i++)
     	vb.push_back(b[i]-'0');




   int lva=va.size();
   int lvb=vb.size();
   int diff=abs(lva-lvb);
  
   
   if(lva>lvb)                                    //if one of the vector has more digits append 0 at begg make both of same len. 
   {  for(j=0;j<diff;j++)           
   	  vb.insert(vb.begin(),0);
   }
   
   if(lva<lvb)
   {
   	  for(j=0;j<diff;j++)
   	  va.insert(va.begin(),0);
   }
    
}
void add(string a , string b )    //for both +ve and both -ve integers
{  
   int i,la,lb,flag=0;
    
    
   
     
    if(a[0]=='-'&&b[0]=='-')
    	{
    		flag=1;
    	    a.erase(0,1);
    	    b.erase(0,1);
    	}	

    	makelen(a,b);
    	//cout<<"a[0]="<<a[0];
    	//cout<<"b[0]="<<b[0];

  /*  	la= a.length();
        lb=  b.length();
   
    va.clear();
    vb.clear();
    res.clear();

    for(i=0;i<la;i++)
    {
    	va.push_back(a[i]-'0');
    }
    
     for(i=0;i<lb;i++)
    {
    	vb.push_back(b[i]-'0');
    }
    





   int lva=va.size();
   int lvb=vb.size();
   int diff=abs(lva-lvb);
   int j;
   
   if(lva>lvb)                                    //if one of the vector has more digits append 0 at begg make both of same len. 
   {  for(j=0;j<diff;j++)           
   	  vb.insert(vb.begin(),0);
   }
   
   if(lva<lvb)
   {
   	  for(j=0;j<diff;j++)
   	  va.insert(va.begin(),0);
   }
   */
   int lva=va.size();
   int lvb=vb.size();
   int carry=0;
   int x;
   
   for(i=lva-1;i>=0;i--)
   {  
      x=va[i]+vb[i]+carry;
      if(x>9)
      {
      	res.push_back(x%10);
      	carry=x/10;
      }
      else
      {
      	res.push_back(x);
      	carry=0;
      }


   }
   
   reverse(res.begin(),res.end());
   
   if(carry!=0)
   {
   	res.insert(res.begin(),carry);
   }

       
    int l=res.size();
   

    if(flag==1)
    	cout<<"-";
    for(i=0;i<l;i++)
    	cout<<res[i];


}




void sub(string a,string b)
{
     /*int la=a.length();
     int lb=b.length();
     
     
     va.clear();
     vb.clear();
     res.clear();

     int i,j;

     for(i=0;i<la;i++)
     	va.push_back(a[i]-'0');

     for(i=0;i<lb;i++)
     	vb.push_back(b[i]-'0');




   int lva=va.size();
   int lvb=vb.size();
   int diff=abs(lva-lvb);
  
   
   if(lva>lvb)                                    //if one of the vector has more digits append 0 at begg make both of same len. 
   {  for(j=0;j<diff;j++)           
   	  vb.insert(vb.begin(),0);
   }
   
   if(lva<lvb)
   {
   	  for(j=0;j<diff;j++)
   	  va.insert(va.begin(),0);
   }
    */
    makelen(a,b);

    int flag=0;
   if(vb[0]>va[0])               //if vb is larger swap with va
   	{va.swap(vb);
       flag=1;
   }

   int lva=va.size();
   int lvb=vb.size();
   int i,j;

  /* for(i=0;i<lva;i++)
     	cout<<va[i];
 cout<<"\n";
     for(i=0;i<lvb;i++)
     	cout<<vb[i];
     	cout<<"\n";*/
     for(i=lva-1;i>=0;i--)
     {
         if(va[i]>=vb[i])
         	res.push_back(va[i]-vb[i]);
          
         else
         {
         	j=i-1;

         	while(va[j]==0)
         	  j--;

         	while(j!=i)
         	{
         		va[j]--;
         		va[j+1]+=10;
         		j++;

         	}
            
           //cout<<i<<" "<<va[i]<<" "<<vb[i]<<"\n";
          res.push_back(va[i]-vb[i]);


         }
     }
     

     reverse(res.begin(),res.end());

     int lres=res.size();
    // cout<<"len= "<<lres<<endl;
      
      for(i=0;i<lres-1;i++)
      {
      	if(res[i]==0)  
        	res.erase(res.begin());
            
         
        else
        	break;

      }
      
      lres=res.size();
     if(flag==1)
     	cout<<"-";
     for(i=0;i<lres;i++)
     	cout<<res[i];



}

void subvector(vector <int> a,vector <int> b,vector <int> &result)
{

   //        int flag=0;
   // if(b[0]>a[0])               //if vb is larger swap with va
   // 	{a.swap(b);
   //     flag=1;
   // }

   int la=a.size();
   int lb=b.size();
   int i,j;


   //   int lva=va.size();
   // int lvb=vb.size();
   

   //make same len
//****************************************
   int diff=abs(la-lb);
  
   
   if(la>lb)                                    //if one of the vector has more digits append 0 at begg make both of same len. 
   {  for(j=0;j<diff;j++)           
   	  b.insert(b.begin(),0);
   }
   
   if(la<lb)
   {
   	  for(j=0;j<diff;j++)
   	  a.insert(a.begin(),0);
   }
//*****************************************************************
    

    la=a.size();
    lb=b.size();

  /* for(i=0;i<lva;i++)
     	cout<<va[i];
 cout<<"\n";
     for(i=0;i<lvb;i++)
     	cout<<vb[i];
     	cout<<"\n";*/
     for(i=la-1;i>=0;i--)
     {
         if(a[i]>=b[i])
         	result.push_back(a[i]-b[i]);
          
         else
         {
         	j=i-1;

         	while(a[j]==0)
         	  j--;

         	while(j!=i)
         	{
         		a[j]--;
         		a[j+1]+=10;
         		j++;

         	}
            
           //cout<<i<<" "<<va[i]<<" "<<vb[i]<<"\n";
          result.push_back(a[i]-b[i]);


         }
     }
     

     reverse(result.begin(),result.end());

     int lres=result.size();
    // cout<<"len= "<<lres<<endl;
      
      for(i=0;i<lres-1;i++)
      {
      	if(result[i]==0)  
        	result.erase(result.begin());
            
         
        else
        	break;

      }
      
      lres=result.size();
     // if(flag==1)
     // 	cout<<"-";
     // for(i=0;i<lres;i++)
     // 	cout<<result[i];
     // cout<<"\n";


}


vector <int> b1;


void multi(vector <int> &va,int b)
{
    int lva=va.size();
    b1.clear();
    int i;
    int x;
    int carry=0;
    
    for(i=lva-1;i>=0;i--)
    {
       x= va[i]*b+carry;

        b1.push_back(x%10);
        carry = x/10;  

    }
    if(carry!=0)
      {	b1.push_back(carry);
        carry=0;
      }

      reverse(b1.begin(),b1.end());

}
void multiply(string a,string b,int flag)
{
	
	
    
    int la=a.length();
    int lb=b.length();
     
   //      make len funtion without leading zeroes (convert to vector)
//****************************************************************
     va.clear();
     vb.clear();
     res.clear();

     int i;

     for(i=0;i<la;i++)
     	va.push_back(a[i]-'0');

     for(i=0;i<lb;i++)
     	vb.push_back(b[i]-'0');
//*******************************************************************
	

	//erase leading zeroes
//*******************************************************************
	while(va[0]==0&&va.size()!=1)
     {   
        va.erase(va.begin());
     }
     while(vb[0]==0&&vb.size()!=1)
     {   
        vb.erase(vb.begin());
     }
//***************************************************************
    int lva=va.size();
    int lvb=vb.size();
    

    

     if(lvb>lva)               //if vb is larger swap with va
   	  va.swap(vb);
     
   
    
    vector <int> b2;
	b2.clear();
	b2.push_back(0); 


    //int i,j=0,k;
    int j,k,nozeros=0;
    for(i=lvb-1;i>=0;i--)
    {     
        multi(va,vb[i]);          //result in b1
        
        int lb1=b1.size();
     //    for(j=0;j<lb1;j++)
    	// cout<<b1[j];
    
     // cout<<"\n";

        for(k=0;k<nozeros;k++)
        	b1.push_back(0);
        
        nozeros++;

   

  //make b1 and b2 of same len to add
//****************************************************************
        lb1=b1.size();  //int
       int lb2=b2.size();
       int diff=abs(lb1-lb2);
  
       
       if(lb1>lb2)                                    //if one of the vector has more digits append 0 at begg make both of same len. 
       {  for(j=0;j<diff;j++)           
   	      b2.insert(b2.begin(),0);
       }
   
       if(lb1<lb2)
       {
   	      for(j=0;j<diff;j++)
   	        b1.insert(b1.begin(),0);
       }
        

  

//**********************************************************
 
//add  store result in "result" vector
//***********************************************************
   lb1=b1.size();
   lb2=b2.size();
   int carry=0;
   int x;
   vector <int> result;
   result.clear();
     for(j=lb1-1;j>=0;j--)
     {  
        x=b1[j]+b2[j]+carry;
        if(x>9)
        {
      	  result.push_back(x%10);
      	  carry=x/10;
        }
        else
        {
      	  result.push_back(x);
      	  carry=0;
        }


      }
   
     reverse(result.begin(),result.end());
   
     if(carry!=0)
     {
   	  result.insert(result.begin(),carry);
     }

      result.swap(b2);   //b2=b1+b2
      
     
        
   }


   // int lb2=b2.size();
    

   //  for(j=0;j<lb2;j++)
   //  	cout<<b2[j];

   //erase leading zeros from result
  //*******************************************************
     while(b2[0]==0&&b2.size()!=1)
     {   
        b2.erase(b2.begin());
     }
    int lb2=b2.size();
    // cout<<"\n";
   
   if(flag==1&&b2[0]!=0)            // no negative sign when result is 0 i.e no -0;
   	cout<<"-";
    for(j=0;j<lb2;j++)
    	cout<<b2[j];



}


void addone(vector <int> a,vector <int> b,vector <int> &cresult)
{


	int la=a.size();
   int lb=b.size();
   int carry=0;
   int x;
   
   int i,j;


   //make same len
//****************************************
   int diff=abs(la-lb);
  
   
   if(la>lb)                                    //if one of the vector has more digits append 0 at begg make both of same len. 
   {  for(j=0;j<diff;j++)           
   	  b.insert(b.begin(),0);
   }
   
   if(la<lb)
   {
   	  for(j=0;j<diff;j++)
   	  a.insert(a.begin(),0);
   }
//*****************************************************************
    

   for(i=la-1;i>=0;i--)
   {  
      x=a[i]+b[i]+carry;
      if(x>9)
      {
      	cresult.push_back(x%10);
      	carry=x/10;
      }
      else
      {
      	cresult.push_back(x);
      	carry=0;
      }


   }
   
   reverse(cresult.begin(),cresult.end());
   
   if(carry!=0)
   {
   	cresult.insert(cresult.begin(),carry);
   }

       
    // int l=res.size();
   

    // if(flag==1)
    // 	cout<<"-";
    // for(i=0;i<l;i++)
    // 	cout<<res[i];

}

int gt(vector <int> a, vector <int> b)
{
       int la=a.size();
   int lb=b.size();
   int i,j;


   //   int lva=va.size();
   // int lvb=vb.size();
   

   //make same len
//****************************************
   int diff=abs(la-lb);
  
   
   if(la>lb)                                    //if one of the vector has more digits append 0 at begg make both of same len. 
   {  for(j=0;j<diff;j++)           
   	  b.insert(b.begin(),0);
   }
   
   if(la<lb)
   {
   	  for(j=0;j<diff;j++)
   	  a.insert(a.begin(),0);
   }
//*****************************************************************
    

    la=a.size();
    lb=b.size();

    if(a[0]>=b[0])    // equal to also included 
    	return 1;
    else
    	return 0;


}
int gtgcd(vector <int> a,vector <int> b)
{
	       int la=a.size();
   int lb=b.size();
   int i,j;


   //   int lva=va.size();
   // int lvb=vb.size();
   

   //make same len
//****************************************
   int diff=abs(la-lb);
  
   
   if(la>lb)                                    //if one of the vector has more digits append 0 at begg make both of same len. 
   {  for(j=0;j<diff;j++)           
   	  b.insert(b.begin(),0);
   }
   
   if(la<lb)
   {
   	  for(j=0;j<diff;j++)
   	  a.insert(a.begin(),0);
   }
//*****************************************************************
    

    la=a.size();
    lb=b.size();

    if(a[0]>b[0])    // equal not to also included 
    	return 1;
    else
    	return 0;

}
void divide(string a,string b,int flag)
{



     int la=a.length();
    int lb=b.length();
     
   //      make len funtion without leading zeroes (convert to vector)
//****************************************************************
     va.clear();
     vb.clear();
     res.clear();

     int i;

     for(i=0;i<la;i++)
     	va.push_back(a[i]-'0');

     for(i=0;i<lb;i++)
     	vb.push_back(b[i]-'0');
//*******************************************************************
	

	//erase leading zeroes
//*******************************************************************
	while(va[0]==0&&va.size()!=1)
     {   
        va.erase(va.begin());
     }
     while(vb[0]==0&&vb.size()!=1)
     {   
        vb.erase(vb.begin());
     }
//***************************************************************
    int lva=va.size();
    int lvb=vb.size();
    
    
    

     // if(lvb>lva)               //if vb is larger swap with va
   	 //  va.swap(vb);
     
     // if(lvb==lva&&vb[0]>va[0])
     // 	va.swap(vb);
    
    vector <int> result;
    vector <int> count;
    vector <int> ones;
    vector <int> cresult;

    count.push_back(0);
    ones.push_back(1);

    while(gt(va,vb))      //check if va > vb 
    {   
    	result.clear();
    	cresult.clear();
    	subvector(va,vb,result);
       
        //count++;
        addone(count,ones,cresult);   //count++;
        count.swap(cresult);

        va.swap(result);    //va=result;
    	


    }

    int lcount=count.size();
      
    int j;
    if(flag==1&&count[0]!=0)
    	cout<<"-";
    for(j=0;j<lcount;j++)
    	cout<<count[j];
         





}

void gcd(string a,string b)
{


      
     int la=a.length();
    int lb=b.length();
     
   //      make len funtion without leading zeroes (convert to vector)
//****************************************************************
     va.clear();
     vb.clear();
     res.clear();

     int i;

     for(i=0;i<la;i++)
     	va.push_back(a[i]-'0');

     for(i=0;i<lb;i++)
     	vb.push_back(b[i]-'0');
//*******************************************************************
	

	//erase leading zeroes
//*******************************************************************
	while(va[0]==0&&va.size()!=1)
     {   
        va.erase(va.begin());
     }
     while(vb[0]==0&&vb.size()!=1)
     {   
        vb.erase(vb.begin());
     }
//***************************************************************
   int zeroflag=0;
   vector <int> result;
   while(gtgcd(va,vb)||gtgcd(vb,va))     //while(va!=vb)
   {   //cout<<"va[0] "<<va[0]<<"\n";

   	    //cout<<"vb[0] "<<vb[0]<<"\n";
     if(va[0]==0&&vb[0]!=0)
     {  //res.clear(); 
     	res=vb;
     	zeroflag=1;
    	//res.push_back(0);
    	break;
     } 
    if(vb[0]==0&&va[0]!=0)
    {   //res.clear();
    	res=va;
    	zeroflag=1;
    	break;

    } 
       if(gtgcd(va,vb))
       {   result.clear();  
       	   //cout<<"a>b\n";
       	  subvector(va,vb,result);
       	   va.swap(result);
       	//va=va-vb;
       }
       else
       {  result.clear();
       	//cout<<"b>a\n";
       	  subvector(vb,va,result);

       	  result.swap(vb);
       	//vb=vb-va;
       }

   }


   if(zeroflag==0) 
   res=va;
   int lres= res.size();
  //cout<<"size= "<<lres<<"\n";
   for(i=0;i<lres;i++)
   	cout<<res[i];

}

int main()
{   
    int t;
    cin>>t;
    while(t)
   {
	string a,b;
	//cout<<"enter a b\n";
	cin>>a>>b;
    
    int k;
    //cout<<"enter k\n";
    cin>>k;
      
      //gcd(a,b);
     //divide(a,b);
    //multiply(a,b);

    int flag=0;

    
    if((a[0]>='0'&&a[0]<='9')&&(b[0]>='0'&&b[0]<='9'))
    	flag=1;
    if(a[0]=='-'&&b[0]=='-')
    	flag=2;
    if((a[0]>='0'&&a[0]<='9')&&(b[0]=='-'))
    	flag=3;
    if((a[0]=='-')&&(b[0]>='0'&&b[0]<='9'))
    	flag=4;

    //cout<<"flag= "<<flag<<"\n";
   if(k==1)
   {
      if(flag==0||flag==1||flag==2)
      	add(a,b);
      if(flag==3)
      	{ b.erase(0,1);
          //cout<<a<<" "<<b<<endl;
          sub(a,b);
         }
      if(flag==4)
      	{   a.erase(0,1);
      		sub(b,a);
      	}

   }
   else if(k==2)
   {
   	if(flag==0||flag==1)
   		sub(a,b);
   	if(flag==2)
   	{   //cout<<"flag="<<flag<<"\n";
   		a.erase(0,1);
   		b.erase(0,1);
   		sub(b,a);
   	}
   	if(flag==3)
   	{   b.erase(0,1);
   		add(a,b);
   	}
   	if(flag==4)
   	{
   		b.insert(0,"-");
   		add(a,b);
   	}
   }

  else if(k==3)
  {
       if(flag==1)
         multiply(a,b,0);

       if(flag==2)
       {  a.erase(0,1);
   		  b.erase(0,1);
          multiply(a,b,0);
       }

       if(flag==3)
       {
       	   b.erase(0,1);
       	   multiply(a,b,1);
       }
       if(flag==4)
       {
       	  a.erase(0,1);
       	  multiply(a,b,1);
       }

       


  }
  else if(k==4)
  {

  	if(flag==1)
  		divide(a,b,0);
  	if(flag==2)
  	{
  		a.erase(0,1);
  		b.erase(0,1);
  		divide(a,b,0);
  	}

  	if(flag==3)
  	{
  		b.erase(0,1);
  		divide(a,b,1);
  	}
  	if(flag==4)
  	{
  		a.erase(0,1);
  		divide(a,b,1);
  	}
  }
  else if(k==5)
  {
  	if(flag==1)
  		gcd(a,b);
  	if(flag==2)
  	{
  		a.erase(0,1);
  		b.erase(0,1);
  		gcd(a,b);
  	}
  	if(flag==3)
  	{
  		b.erase(0,1);
  		gcd(a,b);
  	}
  	if(flag==4)
  	{
  		a.erase(0,1);
  		gcd(a,b);
  	}
  }


   t--;
   cout<<"\n";
}
	//add(a,b);
    //sub(a,b);


    //va.push_back(0);
    //vb.push_back(0);
  /*  int i,la,lb,j,flag=0;
    
    
   
     
    if(a[0]=='-'&&b[0]=='-')
    	{
    		flag=1;
    	    a.erase(0,1);
    	    b.erase(0,1);
    	}	
    	//cout<<"a[0]="<<a[0];
    	//cout<<"b[0]="<<b[0];

    	la= a.length();
        lb=  b.length();
   
    for(i=0;i<la;i++)
    {
    	va.push_back(a[i]-'0');
    }
    
     for(i=0;i<lb;i++)
    {
    	vb.push_back(b[i]-'0');
    }
      
      add(va,vb,res);
   
    int l=res.size();
   

    if(flag==1)
    	cout<<"-";
    for(i=0;i<l;i++)
    	cout<<res[i];
    	*/
	//add(a,b);
}