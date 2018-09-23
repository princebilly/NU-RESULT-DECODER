#include<iostream>
#include<fstream>
#include<cctype>
#include<string>
using namespace std;

int main(int argc, char *argv[]){
    //Introduction
    cout<<"Created by Prince Billy Graham Karmoker"<<endl;

    //get directory
    cout<<"getting Directory..."<<endl;
    string SRC(argv[1]);
    string DIST=SRC.substr(SRC.find_last_of("/\\") + 1);
    string::size_type const p(DIST.find_last_of('.'));
    DIST=DIST.substr(0, p)+".csv";
    cout<<"src: "<<SRC<<endl;
    cout<<"destination: "<<DIST<<endl;
    cout<<"done"<<endl;

    //setting show cmd
    string cmdout= "gedit \'"+DIST+"\'";
    string cmdin= "gedit \'"+SRC+"\'";
    //declaring important varriable
    bool choice=true;
    char ok,r;
    int numberOfSubject;

    //attempting
    for(int count=1;choice;count++){
        cout<<"Attempt "<<count<<":"<<endl;
        cout<<"Please check your file before starting my job..."<<endl;
        system(cmdin.c_str());


        //opening file
        cout<<"opening file..."<<endl;
        ifstream src(SRC);
        //creating file
        cout<<"creating csv file..."<<endl;
        ofstream dist(DIST);
        cout<<"done"<<endl;


        if(count==1){
            cout<<"enter number of subject: ";
            cin>>numberOfSubject;
        }

         //Generating result
            cout<<"generating file..."<<endl;
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
            cout<<"done"<<endl;

            //Opening file
            cout<<"opening result..."<<endl;
            system(cmdout.c_str());
            cout<<"done"<<endl;

        cout<<"IS EVERY THING OK?(Y?N) ";
        cin>>ok;
        while(1){
            if(ok=='Y'||ok=='y'){
                choice=false;
                cout<<"Attempt "<<count<<" successful see you again goodbye"<<endl;
                break;
            }
            else if(ok=='N'||ok=='n'){
                cout<<"Attempt "<<count<<" failed"<<endl;
                break;
            }
            cout<<"Invalid"<<endl;
        }


    }

    return 0;
}
