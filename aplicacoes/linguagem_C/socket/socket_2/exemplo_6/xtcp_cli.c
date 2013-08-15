#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include "/usr/local/include/libsx/libsx.h"

/**************************************************************
 libsx is "The Simple X Library", version 1.1 is available at 
   sunsite.unc.edu/pub/Linux/X11/devel/libsx-shared-1.1.tar.gz
***************************************************************/


Widget quitB, connectB, getB, textW;

void do_quit(Widget w, void *data);
void do_connect(Widget w, void *data);
void do_get(Widget w, void *data);
Bool connected=FALSE;

#define BUFF_LEN 1024

struct sockaddr_in target;
int sock, adl=sizeof(target);
struct hostent *server;
char dataSize, buffer[BUFF_LEN];
char defHostName[81], defFileName[81];

void main(int argc, char **argv)
{

    *defHostName=0;
    *defFileName=0;
    argv[0]="Sample TCP client";
    if(OpenDisplay(argc, argv)==FALSE) exit(1);

    quitB=	MakeButton("Exit", do_quit, NULL);
    connectB=	MakeToggle("Connect", FALSE, NULL, do_connect, NULL);
    getB=	MakeButton("Get File", do_get, NULL);
    textW=	MakeTextWidget(NULL,FALSE,FALSE,300,100);
    
    SetWidgetPos(connectB,PLACE_RIGHT,quitB,NO_CARE,NULL);
    SetWidgetPos(getB,PLACE_RIGHT,connectB,NO_CARE,NULL);
    SetWidgetPos(textW,PLACE_UNDER,getB,NO_CARE,NULL);
    ShowDisplay();
    SetWidgetState(getB,FALSE);
    MainLoop();  
}

/********** Exit Callback ********************/

void do_quit(Widget w, void *data)
{
    if(!GetYesNo("Quit ?")) return;
    if(connected) close(sock);
    exit(0);
}

/********** Connect Callback ********************/

void do_connect(Widget w, void *data)
{
    char *host;
    if(connected && GetToggleState(connectB)) return;
    if(!connected && !GetToggleState(connectB)) return;
    if(connected)
    {
       if(!GetYesNo("Disconnect ?")) {SetToggleState(connectB,TRUE);return;}
       close(sock);connected=FALSE;SetWidgetState(getB,FALSE);return;
    }

    host=GetString("Type Server Name",defHostName);
    if(!host)
    {
        SetToggleState(connectB,FALSE);
        return;
    }

    strcpy(defHostName,host);
    server=gethostbyname(host);
    if(!server)
    {
       GetYesNo("Unknown Host");
       SetToggleState(connectB,FALSE);
       return;
    }

    sock=socket(AF_INET,SOCK_STREAM,0);
    bzero((char *)&target,adl);
    target.sin_family=AF_INET;
    target.sin_port=htons(8450);
    target.sin_addr=*(struct in_addr *) *server->h_addr_list;

    if(-1==connect(sock,(struct sockaddr *)&target,adl))
    {
       GetYesNo("Connect Failed");
       SetToggleState(connectB,FALSE);close(sock);
       return;
    }
    connected=TRUE;
    SetWidgetState(getB,TRUE);
}

/********* Get File Callback ***************/

void conGonef(void)
{
    GetYesNo("Sorry, connection gone.");
    close(sock);
    connected=FALSE;
    SetToggleState(connectB,FALSE);
    SetWidgetState(getB,FALSE);
}

#define conGone() {conGonef();return;}

void do_get(Widget w, void *data)
{
    char *fileName, *aux, overFlow, linha[81];

    fileName=GetString("Type Filename",defFileName);
    if(!fileName) return;
    strcpy(defFileName,fileName);
    dataSize=strlen(fileName)+1;

    if(write(sock,&dataSize,1)!=1) conGone();
    if(write(sock,fileName,dataSize)!=dataSize) conGone();
    aux=buffer;overFlow=0;

    if(read(sock,&dataSize,1)!=1) conGone();

    while(dataSize)
    {
       if(read(sock,linha,dataSize)!=dataSize) conGone();
       if(aux-buffer+dataSize > BUFF_LEN) overFlow=1;
       else {strcpy(aux,linha);aux=aux+dataSize-1;*aux='\n';aux++;}
       if(read(sock,&dataSize,1)!=1) conGone();
    }
    
    *aux=0;
    SetTextWidgetText(textW,buffer,FALSE);
    if(overFlow) GetYesNo("File Too Big - Truncated");
}
