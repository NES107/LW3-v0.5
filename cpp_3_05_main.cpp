#include "cpp_3_05_header.h"
#include "cpp_3_05_header.cpp"


int main()
{
    vector <results> students;
    results resultss;

    cout<<"1 - file generation using DEQUE"<<endl<<"2 - file generation using LIST"<<endl<<"-> ";
    int path;
    cin>>path;
    while(path !=1 && path !=2)
        {
            try
            {
                throw runtime_error("Error in input!(1,2)");
            }catch(const runtime_error &e)
            {
                cout<<e.what();
                cin.ignore(256,'\n');
                cout<<"Enter one more time:"<<endl<<"-> ";
                cin>>path;
            }
        }
    if(path==1)    //Reading from a file
    {
        cout<<"1 - 100 students"<<endl<<"2 - 1000 students"<<endl
        <<"3 - 10000 students"<<endl<<"4 - 100000 students"<<endl<<"-> ";
        int path2;
        cin>>path2;
        if(path2==1)    //100 students
        {
            string fname1 = "100_students.txt";
            string fname2 = "100_students_passed.txt";
            string fname3 = "100_students_notpassed.txt";
            int number = 100;
            vsplitting(students,resultss,fname1,fname2,fname3,number);
        }
        else if(path2==2)   //1000 students
        {
            string fname1 = "1000_students.txt";
            string fname2 = "1000_students_passed.txt";
            string fname3 = "1000_students_notpassed.txt";
            int number = 1000;
            vsplitting(students,resultss,fname1,fname2,fname3,number);
        }
        else if(path2==3)    //10000 students
        {
            string fname1 = "10000_students.txt";
            string fname2 = "10000_students_passed.txt";
            string fname3 = "10000_students_notpassed.txt";
            int number = 10000;
            vsplitting(students,resultss,fname1,fname2,fname3,number);
        }
        else if(path2==4)    //100000 students
        {
            string fname1 = "100000_students.txt";
            string fname2 = "100000_students_passed.txt";
            string fname3 = "100000_students_notpassed.txt";
            int number = 100000;
            vsplitting(students,resultss,fname1,fname2,fname3,number);
        }
        while(path2 !=1 && path2 !=2 && path2 !=3 && path2 !=4)
        {
            try
            {
                throw runtime_error("Error in input!(1,2,3,4)");
            }catch(const runtime_error &e)
            {
                cout<<e.what();
                cin.ignore(256,'\n');
                cout<<"Enter one more time:"<<endl<<"-> ";
                cin>>path2;
            }
        }
    }
    else if(path==2)    //File Generation
    {
        cout<<"1 - 100 students"<<endl<<"2 - 1000 students"<<endl
        <<"3 - 10000 students"<<endl<<"4 - 100000 students"<<endl<<"-> ";
        int path2;
        cin>>path2;
        if(path2==1)    //100 students
        {
            string fname1 = "100_students.txt";
            string fname2 = "100_students_passed.txt";
            string fname3 = "100_students_notpassed.txt";
            int number = 100;
            vsplitting(students,resultss,fname1,fname2,fname3,number);
        }
        else if(path2==2)   //1000 students
        {
            string fname1 = "1000_students.txt";
            string fname2 = "1000_students_passed.txt";
            string fname3 = "1000_students_notpassed.txt";
            int number = 1000;
            vsplitting(students,resultss,fname1,fname2,fname3,number);
        }
        else if(path2==3)    //10000 students
        {
            string fname1 = "10000_students.txt";
            string fname2 = "10000_students_passed.txt";
            string fname3 = "10000_students_notpassed.txt";
            int number = 10000;
            vsplitting(students,resultss,fname1,fname2,fname3,number);
        }
        else if(path2==4)    //100000 students
        {
            string fname1 = "100000_students.txt";
            string fname2 = "100000_students_passed.txt";
            string fname3 = "100000_students_notpassed.txt";
            int number = 100000;
            vsplitting(students,resultss,fname1,fname2,fname3,number);
        }
        while(path2 !=1 && path2 !=2 && path2 !=3 && path2 !=4)
        {
            try
            {
                throw runtime_error("Error in input!(1,2,3,4)");
            }catch(const runtime_error &e)
            {
                cout<<e.what();
                cin.ignore(256,'\n');
                cout<<"Enter one more time:"<<endl<<"-> ";
                cin>>path2;
            }
        }
    }
    return 0;
}

