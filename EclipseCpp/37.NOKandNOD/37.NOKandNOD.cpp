#include<iostream>

using namespace std;

int euclidean_NOK(int M, int N)

{

   while (M!=N)
   {
	   if (M>N)
	   {
		   M-=N;
	   }
	   else
	   {
		   N-=M;
	   }

   }

return M;

}


int euclid_I(int M, int N)

{

  while (M!=N)//dokato razlikata mevdu chislata e <> 0

   { cout<<"Namirane chrez izvajdane: "<<M<<":"<<N<<endl;

        if (M>N) M-=N; else N-=M;


   }

return M;

}//euclid



int main()

{
	int M,N;



  cout<<"Enter a number [3..1001]: ";
  cin>>M;

  cout<<"Enter a number [3..1001]: ";
  cin>>N;


  cout << "NOD is: " << euclid_I(M, N)<<endl;
  cout << "NOK is: " << euclidean_NOK(M, N);


 return 0;

}
