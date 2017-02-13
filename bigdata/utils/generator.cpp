#include <iostream>
#include <vector>
#include <boost/algorithm/string.hpp>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;


int StringToInteger(string input)
{
	int value;
	stringstream ss;
	ss << input;
	ss >> value;
	return value;
}


int main()
{
//variables

int dimension[]={10,100};
int nbStorages[]={80,800};
int segments[]={10,1024};
int replication[]={3,500};
int cs[]={0,1000};
int nCapacity[]={2,2000};
int mtbf[]={1,1};
int mfd[]={1,1};
int nbAdmin[]={1,10};
int nbUser[]={10,100};
int nbFile[]={1,10};
int nbFailure[]={10,100};
int speed[]={10,1000};
int delay[]={1,10};
string consumerRequests[]={"uniform","exponential"};



ifstream infile("data.csv"); //All the combination for full factorial from R scrpit
ofstream script; // ndnSim script to run

string s;

string val;

script.open ("script.txt");

string dim, sto, seg, rep, css, cap, mtb, mfdd, adm, use, fil, fai, spe, del, con;
int num=0; //for the run number

while (infile)
  {

    if (!getline( infile, s )) break;

    vector<string> strs;


    boost::split(strs, s, boost::is_any_of(",")); //split the csv lines into vector

    //get the content of each variables.

      for (int i=0; i<strs.size(); i++){
       // script << strs.at(i) << " ";
        //script << endl;
        //val = strs.at(14);
        //string cmd =
         dim = std::to_string(dimension[StringToInteger(strs.at(0))]);
         sto = std::to_string(nbStorages[StringToInteger(strs.at(1))]);
         seg = std::to_string(segments[StringToInteger(strs.at(2))]);
         rep = std::to_string(replication[StringToInteger(strs.at(3))]);
         css = std::to_string(cs[StringToInteger(strs.at(4))]);
         cap = std::to_string(nCapacity[StringToInteger(strs.at(5))]);
         mtb = std::to_string(mtbf[StringToInteger(strs.at(6))]);
         mfdd = std::to_string(mfd[StringToInteger(strs.at(7))]);
         adm = std::to_string(nbAdmin[StringToInteger(strs.at(8))]);
         use = std::to_string(nbUser[StringToInteger(strs.at(9))]);
         fil = std::to_string(nbFile[StringToInteger(strs.at(10))]);
         fai = std::to_string(nbFailure[StringToInteger(strs.at(11))]);
         spe = std::to_string(speed[StringToInteger(strs.at(12))]);
         del = std::to_string(delay[StringToInteger(strs.at(13))]);
         con = consumerRequests[StringToInteger(strs.at(14))];

        /* script << std::string("NS_LOG=ndn.Admin:ndn.User:ndn.Storage") +
        std::string("./waf --run=\"data-scenario --dimension=") + std::to_string(dimension[StringToInteger(strs.at(0))]) +
        std::string(" --nbStorages=") + std::to_string(nbStorages[StringToInteger(strs.at(1))]) +
        std::string(" --segments=") + std::to_string(segments[StringToInteger(strs.at(2))]) +
        std::string(" --replication=") + std::to_string(replication[StringToInteger(strs.at(3))]) +
        std::string(" --cs=") + std::to_string(cs[StringToInteger(strs.at(4))]) +
        std::string(" --nCapacity=") + std::to_string(nCapacity[StringToInteger(strs.at(5))]) +
        std::string(" --mtbf=") + std::to_string(mtbf[StringToInteger(strs.at(6))]) +
        std::string(" --mfd=") + std::to_string(mfd[StringToInteger(strs.at(7))]) +
        std::string(" --nbAdmin=") + std::to_string(nbAdmin[StringToInteger(strs.at(8))]) +
        std::string(" --nbUser=") + std::to_string(nbUser[StringToInteger(strs.at(9))]) +
        std::string(" --nbFile=") + std::to_string(nbFile[StringToInteger(strs.at(10))]) +
        std::string(" --nbFailure=") + std::to_string(nbFailure[StringToInteger(strs.at(11))]) +
        std::string(" --speed=") + std::to_string(speed[StringToInteger(strs.at(12))]) +
        std::string(" --delay=") + std::to_string(delay[StringToInteger(strs.at(13))]) +
        std::string(" --consumerRequests=") + consumerRequests[StringToInteger(strs.at(14))] + std::string("\"");
//dimension[StringToInteger(strs.at(1))] */
//    script <<  cmd;
    }

//exclude incompatible combinations the number of node should be greater than the sum of different kind of nodes and the storage greater than the replication factor


    if(((StringToInteger(dim)*StringToInteger(dim))>(StringToInteger(sto)+StringToInteger(adm)+StringToInteger(use)))&&(StringToInteger(sto)>StringToInteger(rep))){


        script << std::string("NS_LOG=ndn.Admin:ndn.User:ndn.Storage ") +
            std::string("./waf --run=\"data-scenario --dimension=") + dim +
            std::string(" --nbStorages=") + sto +
            std::string(" --segments=") + seg +
            std::string(" --replication=") + rep +
            std::string(" --cs=") + css +
            std::string(" --nCapacity=") + cap +
            std::string(" --mtbf=") + mtb +
            std::string(" --mfd=") + mfdd +
            std::string(" --nbAdmin=") + adm +
            std::string(" --nbUser=") + use +
            std::string(" --nbFile=") + fil +
            std::string(" --nbFailure=") + fai +
            std::string(" --speed=") + spe +
            std::string(" --delay=") + del +
            std::string(" --consumerRequests=") + con + //std::string("\"");
            std::string(" --runNumber=") + std::to_string(num) + std::string("\"");
            script << endl;

            num++;
    }






}

    script.close();

    return 0;
}

