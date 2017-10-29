#Notes
Packet analyzer
---------------

A frame's contents look like:

1. Ethernet Header (is 14 bytes in size)
2. IP Header (usually and is 20 bytes in size)
3. Protocol Header (usually ICMP,UDP or TCP)
4. Payload(optional)

###Part 1
####Ethernet header

* First six bytes are destination mac address
* Next six bytes are source mac address
* Last two are type fileds

>Example of protocols
>
>* 0x0800 IP(v4), Internet Protocol version 4
>* 0x0806 ARP, Address Resolution Protocol
>* 0x8137 IPX, Internet Packet eXchange (Novell)
>* 0x86dd IPv6, Internet Protocol version 6 

###IP header

* 10th bit is protocol field (06 is TCP, 11 is UDP, ICMP 01)
* Source ip is 13-16
* Destination ip is 17-20

###Protocol header

* For TCP and UDP, first 2 are source port, next two are destination port


References
------------
<https://www.pacificsimplicity.ca/blog/reading-packet-hex-dumps-manually-no-wireshark>
<https://wiki.wireshark.org/Ethernet#Type_.2F_Length_field>


####Compiled by
Ashwin Vaidya