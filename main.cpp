#include<iostream>
#include<fstream>
#include<cctype>
#include<string>
using namespace std;

int main(int argc, char *argv[]){
    //Introduction
    cout<<"Created by Prince Billy Graham Karmoker"<<endl;

    //get directory
    cout<<"Getting Directory..."<<endl;
    string SRC(argv[1]);
    string DIST=SRC.substr(SRC.find_last_of("/\\") + 1);
    string::size_type const p(DIST.find_last_of('.'));
    DIST=DIST.substr(0, p)+".csv";
    cout<<"src: "<<SRC<<endl;
    cout<<"destination: "<<DIST<<endl;

    //opening file
    cout<<"Opening file..."<<endl;
    ifstream src(SRC);
    //creating file
    cout<<"Creating csv file..."<<endl;
    ofstream dist(DIST);

    char r;
    int numberOfSubject;
    cout<<"Enter number of subject: ";
    cin>>numberOfSubject;

    //Generating result
    cout<<"Generating file..."<<endl;
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

    //Opening file
    cout<<"opening result"<<endl;
    string cmd= "gedit "+DIST;
    system(cmd.c_str());

    return 0;
}
