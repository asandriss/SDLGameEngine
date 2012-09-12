#include "CApp.h"
 
CApp::CApp() {
}
 
int CApp::OnExecute() {
    return 0;
}
 
int main(int argc, char* argv[]) {
    CApp theApp;
 
    return theApp.OnExecute();
}