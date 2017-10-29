//------------------Ashwin Vaidya------------------
#include <stdlib.h> //for strtol()
#include <iostream>
#include <vector>
#include <fstream>
using namespace std;


vector<vector<string>> all_packets; //Used to store all the packets. Here 1 packet is a vector. So, essentially this is a vector of vectors

void PrintPacketData(int position)
{
	std::vector<string> curr_paket = all_packets[position];

	cout<<"Destination MAC address";
	for (int i = 0; i < 6; ++i)
	{
		cout<<":"<<curr_paket[i];
	}
	cout<<endl;
	cout<<"Source MAC address";
	for (int i = 6; i < 12; ++i)
	{
		cout<<":"<<curr_paket[i];
	}
	cout<<endl;
	cout<<"IP Protocol: ";
	if(curr_paket[12]=="08")
	{
		if(curr_paket[13]=="00")
			cout<<"IPv4";
		else if(curr_paket[13]=="06")
			cout<<"ARP";
	}
	else if(curr_paket[12]=="81"&&curr_paket[13]=="37")
	{
		cout<<"IPX";
	}
	else if(curr_paket[12]=="86"&&curr_paket[13]=="dd")
	{
		cout<<"IPv6";
	}
	cout<<endl;
	cout<<"Protocol: ";
	if(curr_paket[13+10]=="06")
		cout<<"TCP";
	else if(curr_paket[13+10]=="11")
		cout<<"UDP";
	else if(curr_paket[13+10]=="01")
		cout<<"ICMP";
	cout<<endl;
	if(curr_paket[13+10]=="11"||curr_paket[13+10]=="06")//print data for tcp or udp
	{
		//strtol - string to long, defined in stdlib.h converts string to long. Base is 16 here
		cout<<"Source IP: "<<strtol(curr_paket[13+13].c_str(),NULL,16)<<"."<<strtol(curr_paket[13+14].c_str(),NULL,16)<<"."
		<<strtol(curr_paket[13+15].c_str(),NULL,16)<<"."<<strtol(curr_paket[13+16].c_str(),NULL,16)<<endl;
		cout<<"Destination IP: "<<strtol(curr_paket[13+17].c_str(),NULL,16)<<"."<<strtol(curr_paket[13+18].c_str(),NULL,16)<<"."
		<<strtol(curr_paket[13+19].c_str(),NULL,16)<<"."<<strtol(curr_paket[13+20].c_str(),NULL,16)<<endl;
		string source_port = curr_paket[13+21]+curr_paket[13+22]; 
		cout<<"Source port: "<<strtol(source_port.c_str(),NULL,16)<<endl;
		string destination_port = curr_paket[13+23]+curr_paket[13+24]; 
		cout<<"Destination port: "<<strtol(destination_port.c_str(),NULL,16)<<endl;
	}
	cout<<"----------------------"<<endl;
}
void PrintTCPData()
{
	for (int i = 0; i < all_packets.size(); ++i)
	{
		vector<string> packet = all_packets[i];
		if(packet[23]=="06")
			PrintPacketData(i);
	}
}
void PrintUDPData()
{
	for (int i = 0; i < all_packets.size(); ++i)
	{
		vector<string> packet = all_packets[i];
		if(packet[23]=="11")
			PrintPacketData(i);
	}
}
void PrintAllData()
{
	for (int i = 0; i < all_packets.size(); ++i)
	{
		PrintPacketData(i);
	}
}


int main(int argc, char const *argv[])
{
	fstream packet_file ("packets",ios::in);
	string inp;
	vector<string> packet_data;
	//To store packet data in a vector
	while(!packet_file.eof())
	{
		packet_file>>inp;
		if(inp.compare(";")!=0)	//; is used in the packets file to mark end of packet
			packet_data.push_back(inp);
		else
		{
			all_packets.push_back(packet_data);
			packet_data.clear();
		}
	}
	//To display packet data from the vector
	//This is for reference. Not needed in final code
	for (int j = 0; j < all_packets.size(); ++j)
	{
		packet_data = all_packets[j];
		for (int i = 0; i < packet_data.size(); ++i)
		{
			cout<<packet_data[i];
		}
		cout<<endl;
	}
	//Start analysis
	char choice;
	do
	{
		//I don't know what sir wants but you can use this as the template
		cout<<"1. To show TCP packets\n";
		cout<<"2. To show UDP packets\n";
		cout<<"3. To show all packets\n";
		cin>>choice;
		switch(choice)
		{
			case '1':
				PrintTCPData();
				break;
			case '2':
				PrintUDPData();
				break;
			case '3':
				PrintAllData();
				break;
		}
		cout<<"Do you want to continue?(y)";
		cin>>choice;
	}while(choice=='y');
	return 0;
}
