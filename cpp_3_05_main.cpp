#include "cpp_3_05_header.h"
#include "cpp_3_05_header.cpp"

int main()
{
    vector <results> studentsv;
    deque <results> studentsd;
    list <results> studentsl;
    results resultss;

    ifstream student_list;
    string fname1;
    do
    {
        try
        {
            cout<<"Enter file name(example: name.txt): ";
            cin>>fname1;
            throw runtime_error("Error in input!\n");
        }catch(const runtime_error &e)
        {
            cout<<e.what();
			cin.clear();
			cin.ignore(256,'\n');
			cout<<"Enter one more time"<<endl<<"-> ";
			cin>>fname1;
        }

    }while(cin.fail()==true);

    student_list.open(fname1);
    if(!student_list.is_open())
    {
        cerr<<"Error Opening File"<<endl;
        exit(EXIT_FAILURE);
    }
    student_list.ignore( 1000, '\n' );
    int linenumber=-1;
    while(!student_list.eof())
    {
        student_list>>resultss.surname;
        student_list>>resultss.name;
        for(int i=0; i<5; i++)
        {
            float mark;
            student_list>>mark;
            resultss.hwm.push_back(mark);
        }
        student_list>>resultss.examm;
        mean(&resultss);
        median(&resultss);
        studentsv.push_back (resultss);
        studentsd.push_back (resultss);
        studentsl.push_back (resultss);
        resultss.hwm.resize(0);
        linenumber++;
    }
    student_list.close();
    string fname2 = "students_passed.txt";
    string fname3 = "students_notpassed.txt";
    cout<<endl<<"Vector parameters: "<<endl;
    vsplittingV(studentsv, resultss, fname1, fname2, fname3, linenumber);
    cout<<endl<<"Deque parameters: "<<endl;
    vsplittingD(studentsd, resultss, fname1, fname2, fname3, linenumber);
    cout<<endl<<"List parameters: "<<endl;
    vsplittingL(studentsl, resultss, fname1, fname2, fname3, linenumber);

    return 0;
}
