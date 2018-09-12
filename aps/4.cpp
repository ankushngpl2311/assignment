#include<iostream>
#include<stdio.h>
#include<stdlib.h>
using namespace std;

class vector 
{
	public:
        int *arr;
        int sizev,filled;

        vector()
        {
        	sizev=2;
        	filled=0;
        	arr =(int*)malloc(sizeof(int)*2);
        }
		vector(int n,int x)
		{    

             arr =(int*)malloc(sizeof(int)*n);
             int i;
              
             for(i=0;i<n;i++)
             	arr[i]=x;
               
               sizev=n;
               filled=n;


		}


		int size()
		{
			return filled;
		}
    

        void push_back(int x)
        {
            float load=1.5;
            int s;
            
            s= load * sizev;
        	if(filled==sizev)
        	{ 
                int *p2=(int*)malloc(sizeof(int)*s);

                int i;
                for(i=0;i<sizev;i++)
                {
                	p2[i]=arr[i];
                }
                
                p2[sizev]=x;         
                
                arr=p2;
                
                filled= sizev+1;
                
                sizev=s;
                // cout<<"in push ";
                // cout<<sizev<<"\n";

        	}
             
             else
             {
             	arr[filled]=x;
             	 filled++;
             }

        }

        void pop_back()
        {
        	filled--;
        }

        
        void insert(int index,int x)
        {
             float load=1.5;
            int s;
            
            s= load * sizev;
        	if(filled==sizev)
        	{ 
                int *p2=(int*)malloc(sizeof(int)*s);

                int i;
                for(i=0;i<sizev;i++)
                {
                	p2[i]=arr[i];
                }
                
                p2[sizev]=x;         
                
                arr=p2;
                
                filled= sizev+1;
                
                sizev=s;
                // cout<<"in push ";
                // cout<<sizev<<"\n";

        	}

           else
             {
             	arr[filled]=x;
             	 filled++;
             }
            

           int i;

           for(i=filled-1;i>index;i--)
           {
           	  arr[i]=arr[i-1];
           }

           arr[index]=x;


        }
       

       void erase(int index)
       {

       	  int i;

       	  for(i=index;i<filled-1;i++)
       	  {
       	  	arr[i]=arr[i+1];
       	  }

       	  filled--;
       }

    int front()
    {
    	return arr[0];
    }

    int back()
    {
    	return arr[filled-1];
    }


    int &operator[](int i) 
    {
         
         return arr[i];
     }

};

int main()
{   
    
  //    vector v(5,1);
  //     int i;
	 //  for(i=0;i<5;i++)
  //            	cout<<v.arr[i]<<" ";
	 
  // cout<<"\n";
    //vector v2(6,8);

   //       for(i=0;i<5;i++)
   //           	cout<<v2.arr[i]<<" ";
	
//   int i;
// 	vector v;
// 	cout<<v.size()<<"\n";

// 	v.push_back(9);
//     v.push_back(8);
//     v.push_back(10);
//     v.push_back(91);
//     v.push_back(81);
//     v.push_back(101);
// 	cout<<v.size();
// cout<<"\n";

// for(i=0;i<v.size();i++)
//              	cout<<v.arr[i]<<" ";
	 
//   cout<<"\n";
//   cout<<"sizev ";
//   cout<<v.sizev;
//    cout<<"\n";
//   v.pop_back();
// v.insert(2,5);
// v.insert(2,7);
// v.insert(2,1);
// v.insert(2,2);
// v.insert(2,3);
// v.insert(2,4);

//   for(i=0;i<v.size();i++)
//              	cout<<v.arr[i]<<" ";
//  v.erase(2);
//  cout<<"\n";
//  for(i=0;i<v.size();i++)
//              	cout<<v.arr[i]<<" ";

//              cout<<v.front()<<"\n";
//              cout<<v.back()<<"\n";

//     cout<<v[0];
 
}