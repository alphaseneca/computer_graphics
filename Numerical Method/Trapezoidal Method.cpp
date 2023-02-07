
#include<stdio.h>
#include<math.h>
 
/* Define the function to be integrated here: */
double f(double x){
	double in = 1/(1+x*x);
  return in;
}
 
/*Program begins*/
main(){
  int n,i;
  float a,b,h,x,sum=0,integral;
  /*Ask the user for necessary input */
  printf("\nEnter the no. of sub-intervals: ");
  scanf("%d",&n);
  printf("\nEnter the initial limit: ");
  scanf("%f",&a);
  printf("\nEnter the final limit: ");
  scanf("%f",&b);
  /*Begin Trapezoidal Method: */
  h=fabs(b-a)/n;
  
  for(i=1;i<n;i++){
    x=a+i*h;
    sum=sum+f(x);
  }
  
  integral=(h/2)*(f(a)+f(b)+2*sum);
  //Print the answer
  printf("\nThe integral is: %f\n",integral);
}
  

