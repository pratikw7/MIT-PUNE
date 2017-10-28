///copy the first hexstream & paste as it is
//when copying second hexstream got to newline give a space and paste the hexstream ,similarly do the same thing for all the next hexstream

#include<iostream>
#include<fstream>
#include<string.h>
#include<stdio.h>
using namespace std;
void converter()
{
	ifstream in;
	char ch;
	char no[2];
	int j=0;
//	int k=0;
	int k=0;
	int n=0;
	int ct=0;
	char ft[2];
	int srcip[4];
	int desip[4];
	string frame;
	int dest[6];
	int src[6];
	string type;
	string atype;
	int flag=0;
	int fl=0;
	int ipc=0;
	char port[4];
	int srcport;
	int desport;
	int pc=0;
	int flag1=0;
	//char ch;
	//char no[2];
	in.open("input",ios::binary);
//	int m=0;
	while(!in.eof())
	{
		for(int i=0;i<2;i++)
		in.get(no[i]);
		int x,y;
		if(no[0]=='\n' || no[1]=='\n')
			flag1=1;
		if(flag1==0)
		{

			if(no[0]>='a' && no[0]<='f')
				x=no[0]-87;
			else
				x=no[0]-48;
			if(no[1]>='a' && no[1]<='f')
				y=no[1]-87;
			else
				y=no[1]-48;
			//cout<<" "<<x<<" "<<y<<endl;
			int z=16*x+y;
			//cout<<no[0]<<no[1]<<"=>"<<z<<" "<<k<<endl;
			if(k>=0 && k<6)
				{
						dest[n]=z;
						n++;;

				}
			if(k==6)
					{
						n=0;
					}
			if(k>=6 && k<12)
					{
						src[n]=z;
						n++;
					}
			if(k==12)
					{
						n=0;
					}
			if(k>=12 && k<14)
			{

				ft[ct]=z;
				ct++;

			}

			if(k>=26 && k<30)
					{
						srcip[ipc]=z;
							ipc++;
					}

			if(k==29)
					ipc=0;
			if(k>=30 && k<34)
				{
					//cout<<"    "<<z<<endl;
					desip[ipc]=z;
					//cout<<desip<<"   "<<endl;
						ipc++;
				}
			if(k==33)
				ipc=0;
			if(k==34 || k==35)
					{
						port[pc]=no[0];
						port[pc+1]=no[1];
						pc=pc+2;

						if(pc==4)
						{
							int portid[4];
							for(int i=0;i<4;i++)
							{
								if(port[i]>='a' && port[i]<='f')
									portid[i]=port[i]-87;
								else
									portid[i]=port[i]-48;
							}
							pc=0;
							srcport=4092*portid[0]+256*portid[1]+16*portid[2]+portid[3];

						}
					}
			if(k==36 || k==37)
					{
						port[pc]=no[0];
						port[pc+1]=no[1];
						pc=pc+2;
						if(pc==4)
						{
							int portid[4];
							for(int i=0;i<4;i++)
							{
								if(port[i]>='a' && port[i]<='f')
									portid[i]=port[i]-87;
								else
									portid[i]=port[i]-48;
							}
							pc=0;
							desport=4092*portid[0]+256*portid[1]+16*portid[2]+portid[3];

						}
					}
			if(ct==2)
					{
			//			if(ft[0]>='a' && ft[0]<='f')
			//				x=ft[0]-87;
			//			else
			//				x=ft[0]-48;
			//			if(ft[1]>='a' && ft[1]<='f')
			//				y=ft[1]-87;
			//			else
			//				y=ft[1]-48;


						if(ft[0]==8 && ft[1]==0)
						{
							frame="IP";
							fl=1;
						}
						if(ft[0]==8 && ft[1]==6)
									{
										frame="ARP";
									}
						if(ft[0]==128 && ft[1]==53)
									{
										frame="RARP";
									}
						if(ft[0]==129 && ft[1]==55)
									{
										frame="IPX";
									}
						ct=0;
					}
		if(k==23 and fl==1)
					{
						flag=1;
						if(z==6)
							type="TCP";
						if(z==17)
							type="UDP";
						fl=0;
					}
		if(k==33 && flag==1)
					{
						if(z==21)
							atype="FTP";
						if(z==23)
							atype="Telnet";
						if(z==25)
							atype="SMTP";
						if(z==42)
							atype="DNS";
						if(z==80)
							atype="HTTP";
						if(z==513)
							atype="RLogin";
						flag=0;
					}





	//flag=0;

		}
		k++;
		if(no[0]=='\n' || no[1]=='\n')
		{
			cout<<"Destination MAC:"<<dest[0]<<":"<<dest[1]<<":"<<dest[2]<<":"<<dest[3]<<":"<<dest[4]<<":"<<dest[5]<<endl;
			cout<<"Source MAC:"<<src[0]<<":"<<src[1]<<":"<<src[2]<<":"<<src[3]<<":"<<src[4]<<":"<<src[5]<<endl;
			if(frame=="IP")
			{
				cout<<"Source IP:"<<srcip[0]<<"."<<srcip[1]<<"."<<srcip[2]<<"."<<srcip[3]<<endl;
				cout<<"Destination IP:"<<desip[0]<<"."<<desip[1]<<"."<<desip[2]<<"."<<desip[3]<<endl;
			}
			cout<<"Source Port:"<<srcport<<endl;

			cout<<"Destination Port:"<<desport<<endl;
			cout<<"Frame Type:"<<frame<<"\n";
			if(type=="TCP" || type=="UDP")
			cout<<"Service Used:"<<type<<"\n";
			//if(atype=="FTP" || atype=="Telnet" || atype=="SMTP" || atype=="DNS" || atype=="HTTP" || atype=="RLogin")
			if(type=="TCP")
			{
				if(desport==80)
					cout<<"Application:HTTP";
				if(desport==21 || srcport==21)
					cout<<"Application:FTP";
				if(desport==23)
					cout<<"Application:Telnet";
				if(desport==25)
					cout<<"Application:SMTP";
				if(desport==513)
					cout<<"Application:RLogin";
			}
			if(type=="UDP")
			{
				if(desport==53)
					cout<<"Application:DNS(Query)";
				if(srcport==53)
					cout<<"Application:DNS(Response)";
			}
			cout<<"\n\n";
			no[0]='\0';
			no[1]='\0';
			k=0;
			flag1=0;
			//continue;
		}


	}
}

int main() {

	converter();
	//	char c = 's';
//
//	printf("0x%x\n",c);
	return 0;
}
