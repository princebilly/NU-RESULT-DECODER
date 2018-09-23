#define SRC "src/test.txt"
#define DISTCSV "dist/test.csv"
#define DISTSSQL "dist/resultsql.sql"

#include<iostream>
#include<fstream>
#include<cctype>
using namespace std;


int main(){
    ifstream src(SRC);
    ofstream dist(DISTCSV);
    char r;
    int numberOfSubject;
    cout<<"Enter number of subject: ";
    cin>>numberOfSubject;
    //*
    while(!src.eof()){
        if(src.get()=='|'){
            src.get();
            for(int i=0;i<3;i++){
                //Roll No Reg Session
                while((r=src.get())!=' ')
                    dist.put(r);
                dist.put(',');

                while((r=src.get())!='|');
                src.get();
            }
            //Examines
            while((r=src.get())!='|')
                dist.put(r);
            dist.put(',');

            //Grades
            //*
            for(int i=0;i<numberOfSubject;i++){
                //*
                src.get();
                src.get();
                while((r=src.get())!=' '){
                    dist.put(r);
                }
                if(i!=numberOfSubject-1)
                        dist.put(',');
                while((r=src.get())!='|');
                //*/
            }
            //*/
            dist.put('\n');
        }
    }
    //*/
    dist.close();
    src.close();
    system("gedit dist/test.csv");

    return 0;
}
