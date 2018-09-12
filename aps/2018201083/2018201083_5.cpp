#include<iostream>
#include<stdlib.h>
#include<stdio.h>
using namespace std;
int minhsize=0,maxhsize=0;
int nomax=0;
int nomin=0;
//int maxarr[10000];
int getparent(int i);
void insertmaxh(int *maxarr,int x);
void insertminh(int *minarr,int x);
void insert(int* maxarr,int* minarr,int x);
void maxheapify(int *arr,int i,int n);
int deletemaxh(int* maxarr);
void minheapify(int *arr,int i,int n);
int deleteminh(int *minarr);

int getparent(int i)
{   
    if (i==0)
    return i;

    if(i%2==0)
    return i/2-1;
    
    else
    return i/2;

}

void insertmaxh(int *maxarr,int x)
{
    //static int no=0;
    
    maxarr[nomax]=x;
    int pos =nomax;
    //percolate up
    
    int parent;//=getparent(no);
    

    while(1)
    {

        parent=getparent(pos);

        if(maxarr[parent]<maxarr[pos])
            swap(maxarr[parent],maxarr[pos]);
        else
            break;

        pos=parent;

    }



   nomax++;
   maxhsize=nomax;
  // cout<<"maxhsize="<<maxhsize<<"\n";
   //return no;
}

void insertminh(int *minarr,int x)
{
    //static int no=0;

    minarr[nomin]=x;
    int pos =nomin;
    //percolate up
    
    int parent;//=getparent(no);
    

    while(1)
    {

        parent=getparent(pos);

        if(minarr[parent]>minarr[pos])
            swap(minarr[parent],minarr[pos]);
        else
            break;

        pos=parent;

    }



   nomin++;
   minhsize=nomin;
   //cout<<"minhsize="<<minhsize<<"\n";
   //return no;


}


void insert(int* maxarr,int* minarr,int x)
{ 

      if(maxhsize==0||x<maxarr[0])
          insertmaxh(maxarr,x);
      else
          insertminh(minarr,x);
  

}
void maxheapify(int *arr,int i,int n)
{  
     int left,right,maximum;
     
     left=2*i+1;
    right=2*i+2;

    if(left<n && arr[left]>arr[i])
        maximum=left;
    else
        maximum=i;

    if(right<n && arr[right]>arr[maximum])
        maximum=right;

    if(maximum!=i)
    {
        swap(arr[i],arr[maximum]);
        maxheapify(arr,maximum,n);
    }

}

int deletemaxh(int* maxarr)
{   int left,right;
    swap(maxarr[0],maxarr[maxhsize-1]);
    //cout<<"maxarr[0]= "<<maxarr[0]<<"\n";
    maxhsize--;              //remove element
    nomax--;
    maxheapify(maxarr,0,maxhsize);
    
     return maxarr[maxhsize];
}



void minheapify(int *arr,int i,int n)
{

  int left,right,minimum;
     
     left=2*i+1;
    right=2*i+2;

    if(left<n && arr[left]<arr[i])
        minimum=left;
    else
        minimum=i;

    if(right<n && arr[right]<arr[minimum])
        minimum=right;

    if(minimum!=i)
    {
        swap(arr[i],arr[minimum]);
        minheapify(arr,minimum,n);
    }


}



int deleteminh(int *minarr)
{
    int left,right;
    swap(minarr[0],minarr[minhsize-1]);
    
    minhsize--;              //remove element
    nomin--;

    minheapify(minarr,0,minhsize);
    
    return minarr[minhsize]; 
}


void arrangeheap(int *maxarr,int *minarr)
{

    if(maxhsize-minhsize>1)
    {
        int x=deletemaxh(maxarr);
        insertminh(minarr,x);
    }
    else if(minhsize-maxhsize>1)
    {
        int x= deleteminh(minarr);
        insertmaxh(maxarr,x);
    }
}

double find(int* maxarr,int* minarr)
{
    if(maxhsize==minhsize)
    {
        double x= (double)(maxarr[0]+minarr[0]) / 2;
        return x;
    }
    else if(maxhsize>minhsize)
        return maxarr[0];
    else
        return minarr[0];
}


int main()
{   
  
   int n;
   cin>>n;
   int arr[n],maxarr[n],minarr[n];
   double median[n];

  
    int i,j,c;
  

  for(i=0;i<n;i++)
      cin>>arr[i];

  //  for(i=0;i<n;i++)
  //   { insertminh(minarr,arr[i]);
  //     //cout<<"c= "<<c<<"\n";
  //   for(j=0;j<minhsize;j++)
  //       cout<<minarr[j]<<" ";
  //     cout<<"\n";
  //    } 

  // for(i=0;i<n;i++)
  // {
  //   deleteminh(minarr);
  //    for(j=0;j<minhsize;j++)
  //       cout<<minarr[j]<<" ";
  //     cout<<"\n";
  // }

  for(i=0;i<n;i++)
      {   
         insert(maxarr,minarr,arr[i]);
         // cout<<"before bal\n";
         // cout<<"maxh:";
         // for(j=0;j<maxhsize;j++)
      //       cout<<maxarr[j]<<" ";
      //     cout<<"\n";
      //    cout<<"minh:";
         // for(j=0;j<minhsize;j++)
      //       cout<<minarr[j]<<" ";
      //     cout<<"\n";
         arrangeheap(maxarr,minarr);
          
      //     cout<<"after balancing\n";
         // cout<<"maxh:";
         // for(j=0;j<maxhsize;j++)
      //       cout<<maxarr[j]<<" ";
      //     cout<<"\n";
      //    cout<<"minh:";
         // for(j=0;j<minhsize;j++)
      //       cout<<minarr[j]<<" ";
      //     cout<<"\n";
         median[i]=find(maxarr,minarr);
         printf("%0.1lf\n",median[i]);

    }

//cout<<maxhsize<<"\n";
//cout<<minhsize;

return 0;

}