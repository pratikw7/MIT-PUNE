#	Ashwin Vaidya
#	302098
#	TE 1


import sys
from sys import argv
import math

def invalid_ip(ip_check):
    if(len(ip_check)!=4):            #if more than one dot characters were entered
        raise(ValueError)
    for i in ip_check:
        int(i)                       #if ip contains an alphabet
        if(int(i)>255 or int(i)<0): #if ip is out of bounds
            raise(ValueError)

def binaryToDecimal(b):                        ##converting a contiguous binary number to decimal
    p=7
    d=0
    while(p>=0):
        if(b!=0):
            d+=(2**p)
            b-=1
        p-=1
    return d
def subnets():
    print("Enter a ip address: ")
    ip = sys.stdin.readline()
    no_of_subnets = input("Enter number of subnets: ")
    ipaddr = ip.split(".")                    
    try:
        invalid_ip(ipaddr)                    
    except ValueError:
        print("Enter a valid IP")
        sys.exit()

    x=0
    subnet=""
    n=math.ceil(math.log(int(no_of_subnets))/math.log(2))             #number of subnet masks = 2 ^ n
    if(int(ipaddr[0])>=0 and int(ipaddr[0])<=127):                #class A
        x=24
        subnet="255"
    if(int(ipaddr[0])>=128 and int(ipaddr[0])<=191):                #class B
        x=16
        subnet="255.255"
    if(int(ipaddr[0])>=192 and int(ipaddr[0])<=223):                #class C
        x=8
        subnet="255.255.255"

    while(x>0):
        subnet+="."
        if(n>8):
            n-=8
            subnet+=str(binaryToDecimal(8))
        else:
            subnet+=str(binaryToDecimal(n))
            n=0
        x-=8
    range_of_subnets = 256/no_of_subnets
    i =0
    k=0
    while (i<no_of_subnets):
      j=k+range_of_subnets
      print("Subnet "+str(i)+" is from "+str(k)+" to "+ str(j-1))
      k=j
      i+=1
    print("Subnet mask is:",subnet)





if __name__ == "__main__":
    sys.exit(subnets())
