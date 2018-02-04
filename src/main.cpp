#include "ftpcheck.h"
#include "strjob.h"
#include <cstdlib>
#include <ctime>
#include <stdlib.h>
#include <unistd.h>
//sw version
string const version = ("1.024");

/*
 *      Main function
 *      1. checks if it has all needed privileges
 *      2. deletes all old files
 *      3. checks version and updates if neccessary
 *      4. runs the app core
 */
int main(int argc, char** argv) {

    uid_t euid = geteuid();
    if(euid != 0){
	    cout << "You need to run this program as root.\nTry 'sudo " << argv[0] << "'\n";
	    return 0;
    }

    //deletes script folder
    system("rm scripts/ -r 2> /dev/null");
    
    cout << "System Info Reader, version " << version << "\n";
    
    //Check for updates
    cout << "Checking for updates...\n";
    double remoteVersion = getVersion("https://raw.githubusercontent.com/chorcheus/systemInfoReader/master/version.txt");


    //if newer version available
    if(remoteVersion>atof(version.c_str())) {
        cout << "Newer version available (" << remoteVersion << ")\n";
      
        //files to download
        vector<string> files = splitlines(getContent("https://raw.githubusercontent.com/chorcheus/systemInfoReader/master/todown.txt"));
      
        //create temporary folders
        system("mkdir include && mkdir src && mkdir scripts");

        for(int i(0); i!= files.size(); ++i){
            cout << "Downloading file " << i+1 << "/" << files.size() << "\n";
	        string file = files[i];
            download("https://raw.githubusercontent.com/chorcheus/systemInfoReader/master/"+file, file);
	    }

        system("chmod +x scripts/cmakeconf.sh && scripts/cmakeconf.sh &");
        //exit myself
        exit(0);
       
    }
    
    //if app is up to date
    else {
        cout << "Application is up to date\n";
      
        //time for output file name
        time_t now = time(0);
        char* dt = ctime(&now);
      
        system("echo CPU info'\n' > general.txt");
        system("lscpu >> general.txt && echo =========='\n'RAM info'\n' >> general.txt");
        system("cat /proc/meminfo >> general.txt && echo =========='\n'DMIDECODE info'\n' >> general.txt");
        system("sudo dmidecode >> general.txt");//sudo
      
        vector<string> general = getLines("general.txt");

        //delete all temporary files
        system("rm general.txt");
      
        ofstream out;
      
        //make output directory in home folder if it does not exists
        system("mkdir ~/System\\ Info\\ Reader 2> /dev/null");
      
        //write to output file
        string f = "sysinfo"+edited(dt)+".txt";
        out.open(f.c_str());
        write(out,general);
        out.close();
      
        //move output file to output folder
        string c = "mv sysinfo"+edited(dt)+".txt ~/System\\ Info\\ Reader &> /dev/null"; 
        system(c.c_str());


        //good bye message
        c = "echo Report file saved to ~/System\\ Info\\ Reader/sysinfo"+edited(dt)+".txt";
        system(c.c_str());
    }    
    return 0;
}
