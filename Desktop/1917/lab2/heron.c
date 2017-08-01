#include <stdio.h>
#include <math.h>
int main (int argc, char *argv[]) {

   double a = 0;
   double b = 0;
   double c = 0;
   double area = 0;
   double s = 0;

   printf("Enter side lengths of a triangle:\n");
   scanf("%lf %lf %lf\n", &a, &b, &c);
   
	if(a > b + c || b > a + c || c > a + b) {

		printf("Sorry, cannot compute (Triangle Inequality).");
	}else {

		s = (a + b + c)/2;
   		area = sqrt(s*(s-a)*(s-b)*(s-c));
   		printf("Area = %.2lf", area);
	}
   return 0;

}
