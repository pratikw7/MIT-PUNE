# Create simulator object
set ns [new Simulator]

# used for nam trace data
# nf is file handle
set nf [open out.nam w] 
#wirtes simulation data
$ns namtrace-all $nf
#animation

set n0 [$ns node]
set n1 [$ns node]
$ns color 1 Blue
$ns color 2 Red
$ns duplex-link $n0 $n1 1Mb 10ms DropTail

#Create a UDP agent and attach it to node n0
set udp0 [new Agent/UDP]
$ns attach-agent $n0 $udp0
$udp0 set class_ 1

set udp1 [new Agent/UDP]
$ns attach-agent $n1 $udp1
$udp1 set class_ 2

# Create a CBR traffic source and attach it to udp0
set cbr0 [new Application/Traffic/CBR]
$cbr0 set packetSize_ 500
$cbr0 set interval_ 0.05
$cbr0 attach-agent $udp0

set cbr1 [new Application/Traffic/CBR]
$cbr1 set packetSize_ 400
$cbr1 set interval_ 0.005
$cbr1 attach-agent $udp1

set null0 [new Agent/Null] 
$ns attach-agent $n1 $null0

set null1 [new Agent/Null]
$ns attach-agent $n0 $null1

#Connect the traffic source with the traffic sink
$ns connect $udp0 $null0  
$ns connect $udp1 $null1

$ns at 0.5 "$cbr0 start"
$ns at 0.5 "$cbr1 start"
$ns at 4.5 "$cbr0 stop"
$ns at 4.5 "$cbr1 stop"

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


#Call the finish procedure after 5 seconds simulation time
$ns at 5.0 "finish"

#Run the simulation
$ns run