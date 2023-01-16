#include<bits/stdc++.h>
using namespace std;
void MainStart();
void ServerStart();
void ServerEnd();
void MainDestory();

/*BOOL CreateProcessA(
  LPCSTR                lpApplicationName,
  LPSTR                 lpCommandLine,
  LPSECURITY_ATTRIBUTES lpProcessAttributes,
  LPSECURITY_ATTRIBUTES lpThreadAttributes,
  BOOL                  bInheritHandles,
  DWORD                 dwCreationFlags,
  LPVOID                lpEnvironment,
  LPCSTR                lpCurrentDirectory,
  LPSTARTUPINFOA        lpStartupInfo,
  LPPROCESS_INFORMATION lpProcessInformation
);*/

int main(){
	MainStart();
	return 0;
}
void MainStart
(){
	cout<<"--------Minecraft Server Loader (V0.1)--------"<<endl;
	cout<<"Please rename your server's jar file into 'server.jar', then press enter."<<endl;
	system("pause");
	cout<<"MCSLoader has been ready."<<endl;
	cout<<"Press any key to start Minecraft Server at this directory."<<endl;
	system("pause");
	ServerStart();
}
void ServerStart(){
	printf("Minecraft Server will now start...\n");
	cout<<"JVM Output:\n";
	system("java -jar server-release.jar");
	ServerEnd();
}
void ServerEnd(){
	cout<<"Server has been off."<<endl;
	cout<<"Press any key to close."<<endl;
	system("pause<nul");
	MainDestory();
}
void MainDestory(){
	system("taskkill /f /im mcsloader.exe");
}
