set ns [new Simulator]

$ns color 1 Blue
$ns color 2 Red

set nf [open s1.nam w]
$ns namtrace-all $nf

set nf1 [open s1.tr w]
$ns trace-all $nf1

proc finish {} {
global ns nf nf1
$ns flush-trace

close $nf
close $nf1

exec nam s1.nam &
exit 0
}

set n0 [$ns node]
set n1 [$ns node]
set n2 [$ns node]
set n3 [$ns node]
set n4 [$ns node]
set n5 [$ns node]


$ns duplex-link $n0 $n2 2Mb 10ms DropTail
$ns duplex-link $n1 $n2 2Mb 10ms DropTail
$ns simplex-link $n2 $n3 0.3Mb 100ms DropTail
$ns simplex-link $n3 $n2 0.3Mb 100ms DropTail
$ns duplex-link $n3 $n4 0.5Mb 40ms DropTail
$ns duplex-link $n3 $n5 0.5Mb 30ms DropTail
$ns duplex-link-op $n2 $n3 queuePos 0.5

#$ns duplex-link-op $n0 $n2 orient right-down
#$ns duplex-link-op $n1 $n2 orient right-up
#$ns simplex-link-op $n2 $n3 orient right
#$ns simplex-link-op $n3 $n2 orient left
#$ns duplex-link-op $n3 $n4 orient right-up
#$ns duplex-link-op $n3 $n5 orient right-down

set udp0 [new Agent/UDP]
$udp0 set class_ 1
$ns attach-agent $n1 $udp0

set cbr0 [new Application/Traffic/CBR]


$cbr0 attach-agent $udp0
$cbr0 set packetSize_ 500
$cbr0 set interval_ 0.005
$cbr0 set random_ false

set null0 [new Agent/Null]
$ns attach-agent $n5 $null0

$ns connect $udp0 $null0

set tcp [new Agent/TCP/Newreno]
$tcp set class_ 2
$ns attach-agent $n0 $tcp
set sink [new Agent/TCPSink/DelAck]
$ns attach-agent $n4 $sink

$ns connect $tcp $sink
$tcp set fid_ 2
$tcp set window_ 8000
$tcp set packetSize_ 552

set ftp [new Application/FTP]
$ftp attach-agent $tcp
#$ftp set type_ FTP

$ns at 0.5 "$ftp start"
$ns at 1.0 "$cbr0 start"
$ns at 4.5 "$cbr0 stop"
$ns at 4.5 "$ftp stop"

$ns at 5.0 "finish"

$ns run
