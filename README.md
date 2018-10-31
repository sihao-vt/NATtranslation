# NAT translation

## Thinking Process
Essentially, this is a matching problem with two tweaks
1. matching an (IP address:port number) pair
2. dealing with asterisk(\*)
Therefore, the first thing comes to my mind is using an unordered_map. Next, I parse input (flow) pair, converting IP address or port number to \*, to find corresponding entry in translation table.

## Complexity Analysis
space complexity: O(n)
time complexity: O(n) (However, we need to check (IP address:port numer) pair at most three times)

## Test
I write a NAT file and FLOW file to test this code snippet, the output file is exactly what I expected. Here I assume the translation table is well-formatted. If the input pair is not formatted, I assume the input is bad and return NOT FOUND.

## Some thoughts
Acutally, I saw lots of this matching problem in Network Simulator 3 (NS3) open-source library, including DNS searching and routing protocol. The normal way in NS3 is to build a pair<intput, output> list and then traverse this list to find the corresponding output item. The complexity is O(mn).
Here I assume you want me to optimize time complexity, so I choose unordered_map.
I can parse the (IP address: port number) to a pair<IP address, port number> ( one string to pair<string, string>) in unordered_map, this could make this code more elegent, but I never built a hash function for unordered_map before. I googled this hash function problem, it seems a little tricky, so I did not implement it. Or there might be a solution that builds a hash function to make (192.168.0.1:5005) and (192.168.0.1:\*) generate the same hash number.
