#include "cpp_3_05_header.h"
#include "cpp_3_05_header.cpp"

int main()
{
    deque <results> students;
    results resultss;

    ifstream student_list;
    string fname1;
    cout<<"Enter file name(example: name.txt): ";
    cin>>fname1;
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
        students.push_back (resultss);
        resultss.hwm.resize(0);
        linenumber++;
    }
    student_list.close();
    string fname2 = "students_passed.txt";
    string fname3 = "students_notpassed.txt";
    vsplitting(students, resultss, fname1, fname2, fname3, linenumber);

    return 0;
}
