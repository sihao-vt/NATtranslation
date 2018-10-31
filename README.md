# NATtranslation

Essentially, this is a matching problem with two tweaks
1. matching an (IP address:port number) pair
2. dealing with asterisk(\*)
Therefore, the first thing comes to my mind is using an unordered_map. Next, I parse input (flow) pair, converting IP addressor or port number to \*, to find corresponding entry in translation table.

space complexity: O(n)
time complexity: O(n) (However, we need to check (IP address:port numer) pair at most three times)

Acutally, I saw lots of this matching problem in Network Simulator 3 (NS3) open-source library, including DNS searching or routing protocol. The normal way to deal with it is to build a pair<intput, output> list and then traverse this list to find the corresponding output item. The complexity is O(mn).
Here I assume you want me to optimize time complexity, so I choose unordered_map.

I can parse the (IP address: port number) pair into a pair<IP address, port number>, instead of a string, in unordered_map could make this code more elegent, but I am not familiar with building a hash function for unordered_map.

test my solution
I write a NAT file and FLOW file to test this code snippet, the output file is exactly what I expected.
