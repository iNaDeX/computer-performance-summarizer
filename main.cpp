#include <iostream>
#include <string>
#include <cstdio>
#include <vector>
#include <unordered_map>
#include <cstring>

using namespace std;

class ProcessInfo // class to store/organize a process's statistics
{
private:
    unsigned long _pid;
    unsigned long _ppid;
    unsigned long _pgid;
    unsigned long _real_user_ID;
    unsigned long _effective_user_ID;
    unsigned long _real_group_ID;
    unsigned long _effective_group_ID;
    time_t _start_time; // (timespec.tv_sec)
    float _cpu_user_time; //(floating number in seconds)
    float _cpu_system_time; // (floating number in seconds)
    unsigned long _resident_set_size; // (in bytes)
    unsigned long _text_memory_size; // (in bytes)
    unsigned long _data_memory_size;// (in bytes)
    unsigned long _shared_memory_size;// (in bytes)
    unsigned long _library_memory_size;// (in bytes)
    unsigned long _major_faults;
    unsigned long _minor_faults;
    unsigned long _read_bytes;
    unsigned long _write_bytes;
    string _full_command;
public:
    ProcessInfo (); // empty constructor
    void ParseInput(string line); // parses a line of input and stores it in an instance of ProcessInfo
    string GetKey(); // returns a key identifying a process uniquely (combination of PID and start_time
    void PrintInfo(); // prints the process information
    void setPid(unsigned long pid) { _pid = pid; }
    void setPpid(unsigned long ppid) { _ppid = ppid; }
    void setPgid(unsigned long pgid) { _pgid = pgid; }
    void setRealUserID(unsigned long real_user_ID) {_real_user_ID = real_user_ID; }
    void setEffectiveUserID(unsigned long effective_user_ID) {_effective_user_ID = effective_user_ID; }
    void setRealGroupID(unsigned long real_group_ID) {_real_group_ID = real_group_ID; }
    void setEffectiveGroupID(unsigned long effective_group_ID) { _effective_group_ID = effective_group_ID; }
    void setStartTime(unsigned long start_time) { _start_time = start_time; }
    void setCpuUserTime(float cpu_user_time) { _cpu_user_time = cpu_user_time; }
    void setCpuSystemTime(float cpu_system_time) { _cpu_system_time = cpu_system_time; }
    void setResidentSetSize(unsigned long resident_set_size) { _resident_set_size = resident_set_size; }
    void setTextMemorySize(unsigned long text_memory_size) {  _text_memory_size = text_memory_size; }
    void setDataMemorySize(unsigned long data_memory_size) {  _data_memory_size = data_memory_size; }
    void setSharedMemorySize(unsigned long shared_memory_size) { _shared_memory_size = shared_memory_size; }
    void setLibraryMemorySize(unsigned long library_memory_size) { _library_memory_size = library_memory_size; }
    void setMajorFaults(unsigned long major_faults) {  _major_faults = major_faults; }
    void setMinorFaults(unsigned long minor_faults)  {  _minor_faults = minor_faults;  }
    void setReadBytes(unsigned long read_bytes) { _read_bytes = read_bytes; }
    void setWriteBytes(unsigned long write_bytes) {  _write_bytes = write_bytes; }
    void setCommand(string command) { _full_command = command; }
    unsigned long getPid() { return _pid;}
    unsigned long getPpid() { return _ppid;}
    unsigned long getPgid() {return _pgid;}
    unsigned long getRealUserID() {return _real_user_ID;}
    unsigned long getEffectiveUserID() { return _effective_user_ID;}
    unsigned long getRealGroupID() { return _real_group_ID;}
    unsigned long getEffectiveGroupID() { return _effective_group_ID;}
    time_t getStartTime() { return _start_time;}
    float getCpuUserTime() { return _cpu_user_time;}
    float getCpuSystemTime() { return _cpu_system_time;}
    unsigned long getResidentSetSize() { return _resident_set_size;}
    unsigned long getTextMemorySize() { return _text_memory_size;}
    unsigned long getDataMemorySize() { return _data_memory_size;}
    unsigned long getSharedMemorySize() { return _shared_memory_size;}
    unsigned long getLibraryMemorySize() { return _library_memory_size;}
    unsigned long getMajorFaults() { return _major_faults;}
    unsigned long getMinorFaults() { return _minor_faults;}
    unsigned long getReadBytes() { return _read_bytes;}
    unsigned long getWriteBytes() { return _write_bytes;}
    string getFullCommand() { return _full_command;}
};

// prints the process information
void ProcessInfo::PrintInfo()
{
    printf("%lu, %lu, %lu, %lu, %lu, %lu, %lu, %lu, %f, %f, %lu, %lu, %lu, %lu, %lu, %lu, %lu, %lu, %lu, %s\n",
           _pid,
           _ppid,
           _pgid,
           _real_user_ID,
           _effective_user_ID,
           _real_group_ID,
           _effective_group_ID,
           _start_time,
           _cpu_user_time,
           _cpu_system_time,
           _resident_set_size,
           _text_memory_size,
           _data_memory_size,
           _shared_memory_size,
           _library_memory_size,
           _major_faults,
           _minor_faults,
           _read_bytes,
           _write_bytes,
           _full_command.c_str());
}

// empty constructor
ProcessInfo::ProcessInfo() : _pid(0), _ppid(0), _pgid(0), _real_user_ID(0), _effective_user_ID(0), _real_group_ID(0), _effective_group_ID(0),
    _start_time(0), _cpu_user_time(0), _cpu_system_time(0), _resident_set_size(0), _text_memory_size(0), _data_memory_size(0), _shared_memory_size(0), _library_memory_size(0), _major_faults(0), _minor_faults(0), _read_bytes(0), _write_bytes(0) {}

// parses a line of input and stores it in an instance of ProcessInfo
void ProcessInfo::ParseInput(string line)
{
    char tmp[1024];
    tmp[0] = '\0';
    sscanf(line.c_str(),"%lu,%lu,%lu,%lu,%lu,%lu,%lu,%lu,%f,%f,%lu,%lu,%lu,%lu,%lu,%lu,%lu,%lu,%lu,%s",&_pid,
           &_ppid,&_pgid,&_real_user_ID,&_effective_user_ID,&_real_group_ID,
           &_effective_group_ID,&_start_time,&_cpu_user_time,&_cpu_system_time,&_resident_set_size,&_text_memory_size,&_data_memory_size,&_shared_memory_size,
           &_library_memory_size,&_major_faults,&_minor_faults,&_read_bytes,&_write_bytes,tmp);

    _full_command = tmp;
}

// returns a key identifying a process uniquely (combination of PID and start_time
string ProcessInfo::GetKey()
{
    return "" + std::to_string(_pid) + " "+ std::to_string(_start_time);
}


int main ()
{
    std::unordered_map<string, std::vector<ProcessInfo>> processMap; // map to store all samples, keyed by process
    std::string line; // input line
    std::string infoLine("SAMPLE TIME:"); // info lines start like that
    std::string sysInfo, realInfoLineStart, realInfoLineEnd; // store start & end timestamps

    //read entire process list and build table
    std::getline(std::cin, sysInfo); // get sys info
    std::getline(std::cin, realInfoLineStart); // get first timestamp
    while (std::getline(std::cin, line)) // while the input has lines
    {
        ProcessInfo tmp;
        if(strncmp(line.c_str(), infoLine.c_str(), infoLine.size()) != 0)   // if not 'SAMPLE TIME' line
        {
            tmp.ParseInput(line); // parse input to get the information
            if(processMap.find(tmp.GetKey()) == processMap.end())   // if there was no previous element here, create vector
            {
                processMap.insert(std::make_pair<std::string,std::vector<ProcessInfo>>(tmp.GetKey(), std::vector<ProcessInfo>()));
            }
            processMap[tmp.GetKey()].push_back(tmp); // insert process info into correct vector
        } else {
        	// we are dealing with a timestamp info line
        	realInfoLineEnd = line;
        }
    }

    // Compute & output aggregation
    ProcessInfo aggregate;
    unsigned long nbSamples = 0;
    float diffCpuUserTime = 0;
    float diffCpuSystemTime = 0;
    unsigned long avgResidentSetSize = 0;
    unsigned long avgTextMemorySize = 0;
    unsigned long avgDataMemorySize = 0;
    unsigned long avgSharedMemorySize = 0;
    unsigned long avgLibraryMemorySize = 0;
    unsigned long diffMajorFaults = 0;
    unsigned long diffMinorFaults = 0;
    unsigned long diffReadBytes = 0;
    unsigned long diffWriteBytes = 0;

    // print map contents
    /*for ( auto it = processMap.begin(); it != processMap.end(); ++it )
    {
        std::cout << "Key: " << it->first << std::endl;
        for (std::vector<ProcessInfo>::iterator it2 = it->second.begin() ; it2 != it->second.end(); ++it2)
        {
            (*it2).PrintInfo();
        }
        std::cout << endl << endl;
    }
    std::cout << endl << endl << endl;
    */

    // echo first line of output, containing start & end timestamps of summary
    std::cout << "Interval: " + realInfoLineStart.substr(realInfoLineStart.find(":")+1) + ", "
    		+ realInfoLineEnd.substr(realInfoLineEnd.find(":")+1) << std::endl;
    for ( auto it = processMap.begin(); it != processMap.end(); ++it ) // for each process
    {
    	// set all the stable information that doesn't change with each sample (consider effective IDs will not change)
        aggregate.setPid( (*(it->second.begin())).getPid() );
        aggregate.setPpid( (*(it->second.begin())).getPpid() );
        aggregate.setPgid( (*(it->second.begin())).getPgid() );
        aggregate.setRealUserID( (*(it->second.begin())).getRealUserID() );
        aggregate.setEffectiveUserID( (*(it->second.begin())).getEffectiveUserID() );
        aggregate.setRealGroupID( (*(it->second.begin())).getRealGroupID() );
        aggregate.setEffectiveGroupID( (*(it->second.begin())).getEffectiveGroupID() );
        aggregate.setCommand( (*(it->second.begin())).getFullCommand() );
        aggregate.setStartTime( (*(it->second.begin())).getStartTime() );

        // init aggregate temporary variables
        nbSamples = 0;
        diffCpuUserTime = 0;
        diffCpuSystemTime = 0;
        avgResidentSetSize = 0;
        avgTextMemorySize = 0;
        avgDataMemorySize = 0;
        avgSharedMemorySize = 0;
        avgLibraryMemorySize = 0;
        diffMajorFaults = 0;
        diffMinorFaults = 0;
        diffReadBytes = 0;
        diffWriteBytes = 0;

        // handle the information that needs to be substracted between samples
        if(it->second.size() > 1) { // if we have at least two samples for the process
            diffCpuUserTime = it->second.back().getCpuUserTime() - it->second.front().getCpuUserTime();
            diffCpuSystemTime = it->second.back().getCpuSystemTime() - it->second.front().getCpuSystemTime();
            diffMajorFaults = it->second.back().getMajorFaults() - it->second.front().getMajorFaults();
            diffMinorFaults = it->second.back().getMinorFaults() - it->second.front().getMinorFaults();
            diffReadBytes = it->second.back().getReadBytes() - it->second.front().getReadBytes();
            diffWriteBytes = it->second.back().getWriteBytes() - it->second.front().getWriteBytes();
        } else {
        	// handle the case where we only have one sample for that process
            diffCpuUserTime = it->second.front().getCpuUserTime();
            diffCpuSystemTime = it->second.front().getCpuSystemTime();
            diffMajorFaults = it->second.front().getMajorFaults();
            diffMinorFaults = it->second.front().getMinorFaults();
            diffReadBytes = it->second.front().getReadBytes();
            diffWriteBytes = it->second.front().getWriteBytes();
        }

        // handle the information that needs to be averaged between samples
        for (std::vector<ProcessInfo>::iterator it2 = it->second.begin() ; it2 != it->second.end(); ++it2) // foreach sample
        {
            nbSamples++;
            avgResidentSetSize+= (*it2).getResidentSetSize();
            avgTextMemorySize+= (*it2).getTextMemorySize();
            avgDataMemorySize+= (*it2).getDataMemorySize();
            avgSharedMemorySize+= (*it2).getSharedMemorySize();
            avgLibraryMemorySize+= (*it2).getLibraryMemorySize();
        }
        aggregate.setCpuUserTime(diffCpuUserTime);
        aggregate.setCpuSystemTime(diffCpuSystemTime);
        aggregate.setResidentSetSize(avgResidentSetSize/nbSamples);
        aggregate.setTextMemorySize(avgTextMemorySize/nbSamples);
        aggregate.setDataMemorySize(avgDataMemorySize/nbSamples);
        aggregate.setSharedMemorySize(avgSharedMemorySize/nbSamples);
        aggregate.setLibraryMemorySize(avgLibraryMemorySize/nbSamples);
        aggregate.setMajorFaults(diffMajorFaults);
        aggregate.setMinorFaults(diffMinorFaults);
        aggregate.setReadBytes(diffReadBytes);
        aggregate.setWriteBytes(diffWriteBytes);

        aggregate.PrintInfo(); // output final summary for this process
    }

    return 0;
}
