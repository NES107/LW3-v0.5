#include "cpp_3_05_header.h"


void mean(struct results *resultss)
{
    resultss->average = accumulate(resultss->hwm.begin(),resultss->hwm.end(),0.0)/resultss->hwm.size();
    resultss->fpointsa = resultss->examm*0.6+resultss->average*0.4;
}
void median(struct results *resultss)
{
    if (resultss->hwm.size()%2!=0) resultss->fpointsm = 0.4*resultss->hwm[resultss->hwm.size()/2]+0.6*resultss->examm;
    else resultss->fpointsm = 0.4*((resultss->hwm[resultss->hwm.size()/2-1] + resultss->hwm[resultss->hwm.size()/2])/2)+0.6*resultss->examm;
}
bool sortfm(const results &a, const results &b)
{
    return a.fpointsa > b.fpointsa;
}
int firstntp(deque <results> &students)
{
    int found;
    for(int i=students.size()-1; i>=0; i--)
    {
        if(students[i].fpointsa<5)
        {
            found=i;
        }
    }
    return found;
}
void filegen(string fname,deque <results> &students,struct results resultss,int linenumber)
{
    ofstream stud;
    stud.open(fname);
    stud<<"Surname"<<setw(15)<<cout.fill(' ')<<right<<"Name"<<setw(15)<<cout.fill(' ')<<left
    <<"HW1"<<setw(2)<<cout.fill(' ')<<left<<"HW2"<<setw(2)<<cout.fill(' ')<<left
    <<"HW3"<<setw(2)<<cout.fill(' ')<<left<<"HW4"<<setw(2)<<cout.fill(' ')<<left
    <<"HW5"<<setw(2)<<cout.fill(' ')<<left<<"EXAM"<<setw(2)<<cout.fill(' ')<<left
    <<"Final points(Average / Median)"<<endl;
    for(int i=0; i<105; i++)stud<<"-";
    stud<<endl;
    for(int i=1; i<=linenumber; i++)
    {
        stud<<students[i-1].surname<<setw(22-students[i-1].surname.size())<<cout.fill(' ')<<left<<
        students[i-1].name<<setw(16-students[i-1].name.size())<<cout.fill(' ')<<right;
        for(int p=0;p<5;p++)
        {
            stringstream ss;
            ss<<students[i-1].hwm[p];
            stud<<setw(5-ss.str().size())<<cout.fill(' ')<<left<<students[i-1].hwm[p];
        }
        stringstream ss;
        ss<<students[i-1].examm;
        stud<<setw(6-ss.str().size())<<cout.fill(' ')<<left<<students[i-1].examm;
        stringstream ss1;
        ss1<<students[i-1].fpointsa;
        stud<<setw(15-ss1.str().size())<<cout.fill(' ')<<left<<setprecision(3)<<students[i-1].fpointsa;
        stringstream ss2;
        ss2<<students[i-1].fpointsm;
        stud<<setw(15-ss2.str().size())<<cout.fill(' ')<<left<<setprecision(3)<<students[i-1].fpointsm<<endl;
    }
    stud.close();
}
void vsplitting(deque <results> &students, struct results &resultss, string &fname1, string &fname2, string &fname3, int linenumber)
{
    auto start1 = std::chrono::steady_clock::now();
    sort(students.begin(),students.end(),sortfm);
    int i = firstntp(students);
    deque <results> passed (students.begin(),students.begin()+i);
    deque <results> notpassed (students.begin()+i+1,students.end());
    filegen(fname2,passed,resultss,passed.size());
    filegen(fname3,notpassed,resultss,notpassed.size());
    students.resize(0);
    auto start4 = std::chrono::steady_clock::now();
    double elapsed_time_total = double(std::chrono::duration_cast <std::chrono::nanoseconds> (start4-start1).count());
    cout<<"Speed of program(MBps): "<<((sizeof(results)*students.size())/(elapsed_time_total/1e9)/1e6)<<endl;
}
