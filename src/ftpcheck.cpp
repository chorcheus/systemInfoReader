#include "ftpcheck.h"

using namespace curlpp::options;

void download(string fileurl, string outfilename){
    curlpp::Cleanup myCleanup;
    ofstream os(outfilename.c_str(), ios::binary);
    os << curlpp::options::Url(fileurl);
}

string getContent(string stringurl){
	try
  	{
        curlpp::Cleanup myCleanup;
		curlpp::Easy myRequest;

    	// Set the URL.
    	myRequest.setOpt<Url>(stringurl);

    	std::ostringstream os;
    	curlpp::options::WriteStream ws(&os);
    	myRequest.setOpt(ws);
    	os << myRequest;
    	string content =  os.str();
    	return content;
  	}

  	catch(curlpp::RuntimeError & e)
  	{
    	std::cout << e.what() << std::endl;
		return "";
  	}

  	catch(curlpp::LogicError & e)
  	{
    	std::cout << e.what() << std::endl;
		return "";
  	}
}

double getVersion(string filename){
	return atof( getContent(filename).c_str() );
}

