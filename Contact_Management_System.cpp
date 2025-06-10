#include<iostream>
#include<fstream>
#include<string>
#include <iomanip>
using namespace std;
class Contact_Management
{
    private:
        string name,mobile,email;
        fstream file,file1;
    public:
        void Create_Contact();
        void View_All_Contacts();
        void Search_Contact();
        void Update_Contact();
        void Delete_Contact();
}obj;
int main()
{
    char choice;
    cout<<"Press 1 for add contact        ::\n";
    cout<<"Press 2 for View all details   ::\n";
    cout<<"Press 3 for search any contact ::\n";
    cout<<"Press 4 for any Updation       ::\n";
    cout<<"Press 5 for deletion           ::\n";
    cout<<"Press 6 for Exit               ::\n";
    cin>>choice;
    switch(choice)
    {
        case '1':
            obj.Create_Contact();
            break;
        case '2':
            obj.View_All_Contacts();
            break;
        case '3':
            obj.Search_Contact();
            break;
        case '4':
            obj.Update_Contact();
            break;
        case '5':
            obj.Delete_Contact();
            break;
        case '6':
            return 0;
            break;
        default:
            cout<<"Invalid Selection...!";
    }
    cout<<endl;
    return 0;
}
void Contact_Management::Create_Contact()
{
    cin.ignore();
    cout<<"------------------------------------------------Create Account-------------------------------------------------------\n";
    cout<<"Enter your Name          ::";
    getline(cin,name);
    cout<<"Enter Your Mobile Number :: ";
    getline(cin,mobile);
    cout<<"Enter Your Email         :: ";
    getline(cin,email);
    file.open("saveData2.txt",ios :: out | ios :: app);
    file<<name<<"\t"<<mobile<<"\t"<<email<<endl;
    cout<<"------------------------------------------Your Data Has Successfully Saved----------------------------------------------\n";
    file.close();
}
void Contact_Management::View_All_Contacts()
{
    cin.ignore();
    file.open("saveData2.txt",ios :: in);
    cout<<"----------------------------------------------All Contact Detail's---------------------------------------------------------\n";
    cout<<left<<setw(25)<<"Name"<<setw(25)<<"Mobile Number"<<setw(25)<<"Email"<<endl;
    while(getline(file,name,'\t') && getline(file,mobile,'\t') && getline(file,email,'\n'))
    {
        cout<<left<<setw(25)<<name<<setw(25)<<mobile<<setw(25)<<email<<endl;
    }
    cout<<"----------------------------------------------------------------------------------------------------------------------------\n";
    file.close();
}
void Contact_Management::Search_Contact()
{
    cin.ignore();
    bool found=false;
    string searchName;
    cout<<"Enter Contact Name ::";
    getline(cin,searchName);
    file.open("saveData2.txt",ios :: in);
    cout<<"----------------------------------------------All Contact Detail's---------------------------------------------------------\n";
    cout<<left<<setw(25)<<"Name"<<setw(25)<<"Mobile Number"<<setw(25)<<"Email"<<endl;
    while(getline(file,name,'\t') && getline(file,mobile,'\t') && getline(file,email,'\n'))
    {
        if(searchName==name)
        {
            cout<<left<<setw(25)<<name<<setw(25)<<mobile<<setw(25)<<email<<endl;
            found=true;
        }
    }
    if(found==false)
    {
        cout<<"Not Found...!\n";
    }
    cout<<"----------------------------------------------------------------------------------------------------------------------------\n";
    file.close();
}
void Contact_Management::Update_Contact()
{
    cin.ignore();
    file.open("saveData2.txt",ios :: in);
    file1.open("tempData.txt",ios :: out | ios :: app);
    cout<<"--------------------------------------------Update Section-------------------------------------------------------------------\n";
    string SearchName;
    cout<<"Enter Name ::";
    getline(cin,SearchName);
    while(getline(file,name,'\t') && getline(file,mobile,'\t') && getline(file,email,'\n'))
    {
        if(SearchName==name)
        {
            char choice;
            cout<<"Press 1 For name update      :: ";
            cout<<"\nPress 2 For mobile no update :: ";
            cout<<"\nPress 3 For email Update     :: ";
            cin>>choice;
            cin.ignore();
            switch(choice)
            {
                case '1':
                    cout<<"Enter your Name ::";
                    getline(cin,name);
                    break;
                case '2':
                    cout<<"Enter Your Mobile No. :: ";
                    getline(cin,mobile);
                    break;
                case '3':
                    cout<<"Enter Your Email      :: ";
                    getline(cin,email);
                    break;
                default:
                    cout<<"Invalid Selection... please Try again";
            }
        }
        file1<<name<<"\t"<<mobile<<"\t"<<email<<endl;
    }
    cout<<"----------------------------------------------------Your Updation Has Successfully Completed----------------------------------------\n";
    file.close();
    file1.close();
    remove("saveData2.txt");
    rename("tempData.txt","saveData2.txt");
}
void Contact_Management::Delete_Contact()
{
    cin.ignore();
    cout<<"------------------------------------------------------Deletion Section------------------------------------------------------\n";
    string searchName;
    cout<<"Enter Name :: ";
    getline(cin,searchName);
    file.open("saveData2.txt",ios :: in);
    file1.open("tempData.txt",ios :: out | ios :: app);
    while(getline(file,name,'\t') && getline(file,mobile,'\t') && getline(file,email,'\n'))
    {
        if(searchName==name)
        {
            continue;
        }
        file1<<name<<"\t"<<mobile<<"\t"<<email<<endl;
    }
    cout<<"--------------------------------------Your Deletion Has Successfully Completed------------------------------------------------\n";
    file.close();
    file1.close();
    remove("saveData2.txt");
    rename("tempData.txt","saveData2.txt");
}