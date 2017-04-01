#include <iostream>
#include <math.h>
using namespace std;

int main()
{
    cout<<"  ----------------  Regula Falsi Method --------------\n";

   float a=0,b=0.5;
   cout<<"\nGiven , a = "<<a<<" b = "<<b<<endl<<endl;
   cout<<"f(x) = 4*sin(x) - e^x \n\n";
   float f_a=4*sin(a)-pow(exp(1),a),f_b=4*sin(b)-pow(exp(1),b);
   float formula1=(a*f_b-b*f_a)/(f_b-f_a),formula2=(b*f_a-a*f_b)/(f_a-f_b),formula=formula1;
   float calc[100];calc[0]=0;
   int check=-1;
   if(f_a<0){
    formula=formula2;check=0;
   }
   int i=0;
   for(i=0;;i++){
    calc[i]=formula;
    calc[i]=floor(calc[i]*1000000)/1000000;
    if(check==0){
            a=calc[i];f_a=4*sin(a)-pow(exp(1),a);
    formula2=(b*f_a-a*f_b)/(f_a-f_b);
    formula=formula2;
    }
    else{
            b=calc[i];f_b=4*sin(b)-pow(exp(1),b);
    formula1=(a*f_b-b*f_a)/(f_b-f_a);formula=formula1;
    }
    if(i>0 && calc[i-1]==calc[i]){break;}
   }
   cout<<" Thus \n Answer = "<<calc[i]<<endl;
   return 0;
}
