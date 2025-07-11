#include <ipc.h>
#include <proc.h>
#include <string.h>

using namespace Novanix;

int Novanix::IPCSend(int dest, int type, unsigned int arg1, unsigned int arg2, unsigned int arg3, unsigned int arg4, unsigned int arg5, unsigned int arg6)
{
    //Create IPCMessage
    IPCMessage message;
    message.dest = dest;
    message.type = type;
    message.source = Process::ID;
    
    //Copy args
    message.arg1 = arg1;
    message.arg2 = arg2;
    message.arg3 = arg3;
    message.arg4 = arg4;
    message.arg5 = arg5;
    message.arg6 = arg6;
    
    return IPCSend(message);
}

int Novanix::IPCSend(IPCMessage message)
{
    return DoSyscall(SYSCALL_IPC_SEND, (uint32_t)&message);
}

int Novanix::IPCAvailable()
{
    return DoSyscall(SYSCALL_IPC_AVAILABLE);
}

IPCMessage Novanix::ICPReceive(int fromID, int* errOut, int type)
{
    IPCMessage result;
    DoSyscall(SYSCALL_IPC_RECEIVE, (uint32_t)&result, fromID, (uint32_t)errOut, type);
    return result;
}