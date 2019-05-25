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
int firstntpV(vector <results> &students)
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
int firstntpD(deque <results> &students)
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
int firstntpL(list <results> &students)
{
    int found;
    for(list<results>::reverse_iterator it = students.rbegin(); it!=students.rend(); ++it)
    {
        int index;
        if(it->fpointsa<5)
        {
            index =students.size() - std::distance(students.rbegin(), it);
        }
        found = *index;
    }
    return found;
}
void filegenV(string fname,vector <results> &students,struct results resultss, int linenumber)
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
void vsplittingV(vector <results> &students, struct results &resultss, string &fname1, string &fname2, string &fname3, int linenumber)
{
    auto start1 = std::chrono::steady_clock::now();
    sort(students.begin(),students.end(),sortfm);
    int i = firstntpV(students);
    vector <results> passed (students.begin(),students.begin()+i);
    vector <results> notpassed (students.begin()+i+1,students.end());
    filegenV(fname2,passed,resultss,passed.size());
    filegenV(fname3,notpassed,resultss,notpassed.size());
    auto start4 = std::chrono::steady_clock::now();
    double elapsed_time_total = double(std::chrono::duration_cast <std::chrono::milliseconds> (start4-start1).count());
    cout<<setprecision(3)<<"Speed of program(MBps): "<<(((sizeof(results)*students.size())/1e6)/(elapsed_time_total/1e3))<<endl;
	cout<<setprecision(3)<<"Time elapsed(s): "<<(elapsed_time_total/1e3)<<endl;
	students.resize(0);
}
void filegenD(string fname,deque <results> &students,struct results resultss, int linenumber)
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
void vsplittingD(deque <results> &students, struct results &resultss, string &fname1, string &fname2, string &fname3, int linenumber)
{
    auto start1 = std::chrono::steady_clock::now();
    sort(students.begin(),students.end(),sortfm);
    int i = firstntpD(students);
    deque <results> passed (students.begin(),students.begin()+i);
    deque <results> notpassed (students.begin()+i+1,students.end());
    filegenD(fname2,passed,resultss,passed.size());
    filegenD(fname3,notpassed,resultss,notpassed.size());
    auto start4 = std::chrono::steady_clock::now();
    double elapsed_time_total = double(std::chrono::duration_cast <std::chrono::milliseconds> (start4-start1).count());
    cout<<setprecision(3)<<"Speed of program(MBps): "<<(((sizeof(results)*students.size())/1e6)/(elapsed_time_total/1e3))<<endl;
	cout<<setprecision(3)<<"Time elapsed(s): "<<(elapsed_time_total/1e3)<<endl;
	students.resize(0);
}
void filegenL(string fname,list <results> &students,struct results resultss)
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
    //for(list<results>::iterator it = students.begin(); it!=students.end(); ++it)
    for(auto const& i : students)
    {
        stud<<i.surname<<setw(22-i.surname.size())<<cout.fill(' ')<<left<<
        i.name<<setw(16-i.name.size())<<cout.fill(' ')<<right;
        for(int p=0;p<5;p++)
        {
            stringstream ss;
            ss<<i.hwm[p];
            stud<<setw(5-ss.str().size())<<cout.fill(' ')<<left<<i.hwm[p];
        }
        stringstream ss;
        ss<<i.examm;
        stud<<setw(6-ss.str().size())<<cout.fill(' ')<<left<<i.examm;
        stringstream ss1;
        ss1<<i.fpointsa;
        stud<<setw(15-ss1.str().size())<<cout.fill(' ')<<left<<setprecision(3)<<i.fpointsa;
        stringstream ss2;
        ss2<<i.fpointsm;
        stud<<setw(15-ss2.str().size())<<cout.fill(' ')<<left<<setprecision(3)<<i.fpointsm<<endl;
    }
    stud.close();
}
void vsplittingL(list <results> &students, struct results &resultss, string &fname1, string &fname2, string &fname3, int linenumber)
{
    auto start1 = std::chrono::steady_clock::now();
    sort(students.begin(),students.end(),sortfm);
    int i = firstntpL(students);

    //list<int>::reverse_iterator it = std::find(students.rbegin(), students.rend(), 5);
    //int i = students.size()-(std::distance(students.rbegin(), it));

    list <results> passed (students.begin(),students.begin()+i);
    list <results> notpassed (students.begin()+i+1,students.end());
    filegenL(fname2,passed,resultss,passed.size());
    filegenL(fname3,notpassed,resultss,notpassed.size());
    auto start4 = std::chrono::steady_clock::now();
    double elapsed_time_total = double(std::chrono::duration_cast <std::chrono::milliseconds> (start4-start1).count());
    cout<<setprecision(3)<<"Speed of program(MBps): "<<(((sizeof(results)*students.size())/1e6)/(elapsed_time_total/1e3))<<endl;
	cout<<setprecision(3)<<"Time elapsed(s): "<<(elapsed_time_total/1e3)<<endl;
	students.resize(0);
}
