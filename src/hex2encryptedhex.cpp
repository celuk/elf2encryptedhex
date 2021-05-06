#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

int gcd(int a, int b) {
   int t;
   while(1) {
      t= a % b;
      if(t ==0 )
      return b;
      a = b;
      b = t;
   }
}

int hexCharToInt(char a){
    if(a>='0' && a<='9')
        return (a-48);
    else if(a>='a' && a<='f')
        return (a-87);
    else return 0;
}

char hexIntToChar(int b){

int a = b%16;
    if(a >= 0 && a <= 9)
        return (char)(a + 48);
    else if(a >= 10 && a <= 15)
        return (char)(a + 87);
    else return 'Z';

/*
switch(a){

case 0: return '0';
case 1: return '1';
case 2: return '2';
case 3: return '3';
case 4: return '4';
case 5: return '5';
case 6: return '6';
case 7: return '7';
case 8: return '8';
case 9: return '9';
case 10: return 'a';
case 11: return 'b';
case 12: return 'c';
case 13: return 'd';
case 14: return 'e';
case 15: return 'f';
default: return 'Z';

}
*/
}


int main(int argc, char *argv[]){
    int counter = 0;
    int mm;

//char* name;
//for(int i=0;i!='\0';i++) name[i] = argv[i];

    string filename = string(argv[1]);
    ifstream read(filename+ ".hex");
    ofstream write1(filename + "encrypted.hex");
    ofstream write2(filename + "decyrpted.hex");

    char character;

    if (read.is_open()){

        while (read >> character){

            double p = atoi(argv[3]);
            double q = atoi(argv[4]);
            double e = atoi(argv[5]);
            double n = p * q;
            double track;
            double phi = (p - 1) * (q - 1);

            while(e<phi) {
               track = gcd(e,phi);
               if(track==1)
                  break;
               else
                  e++;
            }

            double d1 = 1/e;
            double d = fmod(d1,phi);
            double message = hexCharToInt(character);
            double c = pow(message,e);
            double m = pow(c,d);
            c=fmod(c,n);
            m=fmod(m,n);
            mm = (int)(ceil(m));

//cout<<hexIntToChar(c);
//cout<<mm;

            write1<<hexIntToChar(c);
            write2<<hexIntToChar(mm);

            counter++;
            if(counter == ( atoi(argv[2]) / 4) ){
                write1<<"\n";
                write2<<"\n";
                counter = 0;
            }
        }
    read.close();
    write1.close();
    write2.close();
    }

  return 0;
}
