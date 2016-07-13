#include"student.h"
#include<iostream>
using namespace std;

float Student::CalculateAvg(Student s[],int n,int present)
{
	float average =0;
	for(int i=0;i<n;i++)
	{
		if(s[i].status=='p')
			average+=s[i].marks;
	}
	average /= present;
	return average;
}
int Student::CalcPresent(Student s[],int n)
{
	int present=0;
	for(int i=0;i<n;i++)
		if(s[i].status=='p')
			present++;
	return present;
}
int Student::CalcHigh(Student s[],int n)
{
	int highScore = s[0].marks;
	for(int i=0;i<n;i++)
		{
			if(s[i].status=='p' && s[i].marks >highScore)
				highScore=s[i].marks;
		}
	return highScore;
}
int Student::CalcLow(Student s[],int n)
{
	int lowScore = s[0].marks;
	for(int i=0;i<n;i++)
		{
			if(s[i].status=='p' && s[i].marks <lowScore)
				lowScore=s[i].marks;
		}
	return lowScore;
}
void Student::ListAbsentees(Student s[], int n)
{
	cout<<endl<<"List of students who were absent:\n";
	for(int i=0;i<n;i++)
		if(s[i].status=='a')
		{
			cout<<"-"<<s[i].name<<endl;
		}
}
int Student::ModeofMarks(Student s[],int n)
{
	int lsOfNo[100];
	//Initialize all numbers to zero
	for(int i=0; i<100;i++)
		lsOfNo[i] =0;
	for(int i=0; i<n;i++)
	{
		if(s[i].status=='p'&&s[i].marks >0)
			lsOfNo[s[i].marks]+=1;
	}
	int maxOfMarks=0,b=0;
	for(int i=0; i<100; i++)
		if(b<lsOfNo[i])
		{
			b =lsOfNo[i];
			maxOfMarks = i;
		}
return maxOfMarks;
}

void Student::GetDetails(Student s[], int n)
{
	for(int i=0; i<n; i++)
		{
			cout<<"Enter Student"<<1+i<<"'s name:\n";
			cin>>s[i].name;
			cout<<"Enter roll number of student: \n";
			cin>>s[i].rollNo;
			int flag =1;
			while(flag)
			{
				cout<<"Whether present or absent for test (a/p): ";
							cin>>s[i].status;
			if(s[i].status =='p')
			{
				int valid =1;
					while(valid)
						{
							cout<<"Enter Student"<<1+i<<"'s marks:\n";
							cin>> s[i].marks;
							if(s[i].marks<=100&&s[i].marks >=0)
							{
								valid=0;
							}
							else{
								cout<<"Enter marks within 0-100\n";
								valid=1;
							}
						}
			flag =0;
			}
			else if(s[i].status =='a')
			{
				s[i].marks =0;
				flag =0;
			}
			else
			{
				cout<<"Enter a valid status\n";
				flag=1;
			}
			}

		}
}
void Student::ShowDetails(Student s[], int n,int present)
{
	if(present>0)
	{
	cout<<"Name\t\tRoll No.\tMarks\t\tAb/P\n";
	for(int i=0;i<n;i++)
	{
		cout<<s[i].name<<"\t\t"<<s[i].rollNo<<"\t\t"<<s[i].marks<<"\t\t"<<s[i].status<<endl;
	}
	}
	else
		cout<<endl<<"All were absent"<<endl;
}
