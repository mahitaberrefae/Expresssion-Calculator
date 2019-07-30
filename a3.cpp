#include <iostream>
#include "stack.h"
#include <string.h>
#include <string>
#include <fstream>
#include<iomanip>

using namespace std;

    Stack<double>NUMB;
    Stack<char>CHAR;
int main(int argc, char*argv[])
{
     if(argc!=2)
{
    double n=0;
    cout<<fixed<<setprecision(2)<<n;
    return 0;
}
int j=0;
int Cbra=0;
int Brac=0;
int r=0;
double op1, op2;
char op;
while(j<strlen(argv[1]))
        {
        if(argv[1][j]==40)
            Brac++;
        j++;
        }
while(r<strlen(argv[1]))
            {
            if(argv[1][r]==41)
                Cbra++;
            r++;
            }

   if(Cbra!=Brac)
    {
        cout<<"Invalid Expression";
        return 0;
    }
    int y, w;
    char Exp;

    double RZLT;
    double elem;
    char Mychar;
    double Mynum;
    char popednaw;
    int leng;
    leng =strlen(argv[1]);

    for(int i=0; i<strlen(argv[1]);i++)
    {
       if(argv[1][i]==47 && argv[1][i+1]==40 && argv[1][i+3]==45 && (argv[1][i+2]==argv[1][i+4]))
       {
             cout<<"Invalid Expression";
                return 0;
       }
       if(argv[1][i]==47 && argv[1][i+2]==45 && (argv[1][i+1]==argv[1][i+3]))
       {

             cout<<"Invalid Expression";
                return 0;
       }


        if(argv[1][0]==43 || argv[1][0]==47 || argv[1][0]==41 || argv[1][0]==120)
    {

                cout<<"Invalid Expression";
                return 0;
    }
    if(argv[1][0]==45 && argv[1][1]==45)
    {

                cout<<"Invalid Expression";
                return 0;
    }
    if(argv[1][leng]==43 || argv[1][leng]==47 || argv[1][leng]==40 || argv[1][leng]==45 || argv[1][leng]==120)

        {
               cout<<"Invalid Expression";
                return 0;
        }

        if(argv[1][i]==40)
        {
            if(argv[1][i+1]==41 || argv[1][i+1]==120 || argv[1][i+1]==43  || argv[1][i+1]==47)
            {
                cout<<"Invalid Expression";
                return 0;
            }
            //else
            CHAR.push(argv[1][i]);
        }
        else if(argv[1][i]==120 || argv[1][i]==43  || argv[1][i]==47 || argv[1][i]==45)
        {
            if(argv[1][i]==45)
            {
                if( argv[1][i+1]==120 || argv[1][i+1]==47 || argv[1][i+1]==43 ||argv[1][i+1]=='\0' || argv[1][i+1]== 41)
                {
                    cout<<"Invalid Expression";
                    return 0;
                }
                 else if((argv[1][i-1]==120 || argv[1][i-1]==47  || argv[1][i-1]==43 || argv[1][i-1]==45 || argv[1][i-1]==40)  && (argv[1][i+1]>=48 && argv[1][i+1]<=57))
                {
                   elem=(argv[1][i+1]-48);
                   i++;
                while(argv[1][i+1]!=120 && argv[1][i+1]!=47 && argv[1][i+1]!= 43 &&argv[1][i+1]!=45 &&argv[1][i+1]!=40 &&argv[1][i+1]!=41 && argv[1][i+1]!='\0')
           {
             elem=(elem*10)+(argv[1][i+1]-48);
              i++;
           }

           NUMB.push(-elem);
           i++;

                }

            }
        else if(argv[1][i]==120 || argv[1][i]==47 || argv[1][i]==43 )
            {
                if( argv[1][i+1]==120 || argv[1][i+1]==47 || argv[1][i+1]==43 ||argv[1][i+1]=='\0' || argv[1][i+1]== 41)
        {
            cout<<"Invalid Expression";
        return 0;
        }
        }

            if(argv[1][i]==120 || argv[1][i]==47)
                y=1;
            else if(argv[1][i]==43 || argv[1][i]==45)
                y=0;
            CHAR.top(Mychar);
            if(CHAR.isEmpty()|| Mychar==40)
            {
                CHAR.push(argv[1][i]);
            }
           else
            {
                if(Mychar==120 || Mychar==47 )
                    w=1;
                if(Mychar==43 || Mychar==45)
                    w=0;
                if(w==y || argv[1][i]<Mychar)
                {
                    CHAR.pop(op);
                    CHAR.push(argv[1][i]);
                    NUMB.pop(op2);
                    NUMB.pop(op1);
                    if(op==43)
                    {
                      RZLT=op1+op2;
                      NUMB.push(RZLT);
                    }
                    else if(op==45)
                    {
                        RZLT=op1-op2;
                        NUMB.push(RZLT);
                    }
                    else if(op==47)
                    {
                        if(op2==48)
                        {
                            cout<<"Invalid Expression";
                            return 0;
                        }
                        RZLT=op1/op2;
                        NUMB.push(RZLT);
                    }
                  else if(op==120)
                    {
                        RZLT=op1*op2;
                        NUMB.push(RZLT);
                    }


                }
                else
                    CHAR.push(argv[1][i]);
            }
        }

        else if(argv[1][i]>=48 && argv[1][i]<=57)
        {
            elem=(argv[1][i]-48);
            while(argv[1][i+1]!=120 && argv[1][i+1]!=47 && argv[1][i+1]!= 43 &&argv[1][i+1]!=45 &&argv[1][i+1]!=40 &&argv[1][i+1]!=41 && argv[1][i+1]!='\0')
           {
             elem=(elem*10)+(argv[1][i+1]-48);
               i++;

           }


            NUMB.push(elem); //222

        }


      else if(argv[1][i]==41)
      {
           if(argv[1][i+1]==40)
            {
                cout<<"Invalid Expression";
                return 0;
            }
            CHAR.top(popednaw);
            while(popednaw!=40)
            {
                CHAR.pop(op);
                NUMB.pop(op2);
                NUMB.pop(op1);
                if(op==43)
                {
                  RZLT=op1+op2;
                  NUMB.push(RZLT);
                }
                else if(op==45)
               {
                RZLT=op1-op2;
                NUMB.push(RZLT);
               }
               else if(op==47)
              {
                if(op2==48)
                  {
                 cout<<"Invalid Expression";
              return 0;
                  }
                   RZLT=op1/op2;
                  NUMB.push(RZLT);
              }


                  else if(op==120)
                  {
                    RZLT=op1*op2;
                  NUMB.push(RZLT);

                    }

              CHAR.top(popednaw);
         }
          char x;
         CHAR.pop(x);
}

else
        {
            cout<<"Invalid Expression";
       return 0;
        }
}

if(CHAR.isEmpty())
          {
              double oops;
              NUMB.pop(oops);
              cout<<fixed<<setprecision(2)<<oops;
          }

   else {

              CHAR.pop(op);
              NUMB.pop(op2);
              NUMB.pop(op1);
             if(op==43)
              {
                  RZLT=op1+op2;
                  NUMB.push(RZLT);
                  }
             else if(op==45)
              {
                   RZLT=op1-op2;
                  NUMB.push(RZLT);
              }
              else if(op==47)
              {
                   RZLT=op1/op2;
                  NUMB.push(RZLT);
              }
                  else if(op==120)
                    {
                        RZLT=op1*op2;
                  NUMB.push(RZLT);
                    }


    while(!(CHAR.isEmpty()))
        {

             CHAR.pop(op);
              NUMB.pop(op2);
              NUMB.pop(op1);
             if(op==43)
              {
                  RZLT=op1+op2;
                  NUMB.push(RZLT);
                  }
             else if(op==45)
              {
                   RZLT=op1-op2;
                  NUMB.push(RZLT);
              }
              else if(op==47)
              {
                   RZLT=op1/op2;
                  NUMB.push(RZLT);
              }
                  else if(op==120)
                    {
                        RZLT=op1*op2;
                  NUMB.push(RZLT);
                    }
      }
      cout<<fixed<<setprecision(2)<<RZLT;

}

    return 0;
}
