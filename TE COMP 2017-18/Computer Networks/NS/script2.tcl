set ns [new Simulator]

set nf [open out.nam w]

$ns namtrace-all $nf

$ns color 1 Blue
$ns color 2 Red

set n0 [$ns node]
set n1 [$ns node]
set n2 [$ns node]
set n3 [$ns node]
set n4 [$ns node]
set n5 [$ns node]

$ns duplex-link $n0 $n2 2Mb 10ms DropTail
$ns duplex-link $n1 $n2 1Mb 10ms DropTail
$ns duplex-link $n2 $n3 0.3Mb 100ms DropTail
$ns duplex-link $n3 $n4 0.5Mb 30ms DropTail
$ns duplex-link $n3 $n5 0.5Mb 40ms DropTail

#Define a 'finish' procedure
proc finish {} {
        global ns nf
        $ns flush-trace
	#Close the trace file
        close $nf
	#Execute nam on the trace file
        exec nam out.nam &
        exit 0
}


# Insert your own code for topology creation
# and agent definitions, etc. here
set tcp1 [new Agent/TCP]
$tcp1 set class_ 1
$ns attach-agent $n0 $tcp1
set sink1 [new Agent/TCPSink]
$ns attach-agent $n4 $sink1
$ns connect $tcp1 $sink1

set ftp [new Application/FTP]
$ftp attach-agent $tcp1
$ftp set type_ FTP

set udp1 [new Agent/UDP]
$udp1 set class_ 2
$ns attach-agent $n1 $udp1
set null [new Agent/Null]
$ns attach-agent $n5 $null
$ns connect $udp1 $null
set cbr [new Application/Traffic/CBR]
$cbr attach-agent $udp1
$cbr set type_ cbr
$cbr set packet_size_ 100
$cbr set rate_ 0.1Mb
 

#Call the finish procedure after 5 seconds simulation time
$ns at 5.0 "finish"
$ns at 0.1 "$ftp start"
$ns at 4.5 "$ftp stop"
$ns at 0.5 "$cbr start"
$ns at 4.5 "$cbr stop"
#Run the simulation
$ns run