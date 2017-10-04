#include <iostream>
#include <stdio.h>
#include <string.h>

#include "RoboteqDevice.h"
#include "ErrorCodes.h"
#include "Constants.h"

using namespace std;

int main(int argc, char *argv[])
{
  string response = "";
  RoboteqDevice device;
  int status = device.Connect("/dev/ttyUSB0");

  if(status != RQ_SUCCESS)
  {
    cout<<"Error connecting to device: "<<status<<"."<<endl;
    return 1;
  }

  cout<<"- SetConfig(_DINA, 1, 1)...";
  if((status = device.SetConfig(_DINA, 1, 1)) != RQ_SUCCESS)
    cout<<"failed --> "<<status<<endl;
  else
    cout<<"succeeded."<<endl;

  //Wait 10 ms before sending another command to device
  sleepms(10);

  int result;

  // Normal non-id command
  cout<<"- SetCommand(_GO, 1, 1)...";
  if((status = device.SetCommand(_GO, 1, 1)) != RQ_SUCCESS)
    cout<<"failed --> "<<status<<endl;
  else
    cout<<"succeeded."<<endl;

  //Wait 10 ms before sending another command to device
  sleepms(10);

  // Command with Ids (For RoboCAN networked controllers)
  if((status = device.SetCommandId(2, _VAR, 1, 1)) != RQ_SUCCESS)
    cout<<"failed --> "<<status<<endl;
  else
    cout<<"succeeded."<<endl;


  device.Disconnect();
  return 0;
}
