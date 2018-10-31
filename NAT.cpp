#include <iostream>
#include <fstream>
#include <string>
#include <unordered_map>
using namespace std;

int main()
{
	//open all files
	ifstream natFile("NATFile.txt");
	ifstream flowFile("FLOWFile.txt");
	ofstream outputFile("OUTPUTFile.txt");

	unordered_map<string, string> natTable;

	//load NAT translation table
	string line;
	while (getline(natFile, line))
	{
		if (line.size() == 0) continue;
		int pos = line.find(',');
		string inputPair = line.substr(0, pos);
		string outputPair = line.substr(pos + 1);
		natTable[inputPair] = outputPair;
	}

	//map each input address:pair with entries
	string inputLine;
	while (getline(flowFile, inputLine))
	{
		if (!inputLine.size()) continue;
		vector<string> potentialPair;
		size_t pos = inputLine.find(':');
		if(pos==string::npos) outputFile << "No nat match for " + inputLine + "\n\n"; //bad input
		potentialPair.push_back(inputLine);
		potentialPair.push_back("*" + inputLine.substr(pos));
		potentialPair.push_back(inputLine.substr(0, pos + 1) + "*");
		int i;
		for (i = 0; i < 3; i++)
		{
			auto it = natTable.find(potentialPair[i]);
			if (it != natTable.end())
			{
				outputFile << it->first + " -> " + it->second + "\n\n";
				break;
			}
		}
		if (i == 3)
			outputFile << "No nat match for " + inputLine + "\n\n";
	}

	//close all files
	natFile.close();
	flowFile.close();
	outputFile.close();
    return 0;
}

