#define SRC "src/test.txt";
#define DISTCSV "src/test.txt";
#define DISTSSQL "dist/resultsql.sql";

#include<iostream>
#include<fstream>
#include<cstdio>
using namespace std;


int main(){
    ifstream src("src/test.txt");
    ofstream dist("dist/test.txt");\
    char r;
    int numberOfSubject;
    cout<<"Enter number of subject: ";
    cin>>numberOfSubject;
    //*
    while(!src.eof()){
        if(src.get()=='|'){
            src.get();

            //Roll No
            while((r=src.get())!=' ')
                dist.put(r);
            dist.put(',');

            while((r=src.get())!='|');
            src.get();

            //Reg No.
            while((r=src.get())!=' ')
                dist.put(r);
            dist.put(',');

            while((r=src.get())!='|');
            src.get();

            //Session.
            while((r=src.get())!=' ')
                dist.put(r);
            dist.put(',');

            while((r=src.get())!='|');
            src.get();

            //Examines
            while((r=src.get())!='|')
                dist.put(r);
            dist.put(',');

            src.get();

            //Grades
            for(int i=0;i<numberOfSubject;i++){
                //*
                while((r=src.get())!=' ')
                    dist.put(r);
                if(i!=numberOfSubject-1)
                    dist.put(',');
                while((r=src.get())!='|');
                //*/
                /*
                dist<<src;
                src.get();src.get();dist.put(',');
                //*/
            }
            dist.put('\n');

        }
    }
    //*/

    dist.close();
    src.close();
    system("gedit dist/test.txt");

    return 0;
}
