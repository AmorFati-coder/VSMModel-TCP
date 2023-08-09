#include "DsimModel.h"

INT DsimModel::isdigital (CHAR *pinname)
{
	return TRUE;							// Indicates this is a digital model
}

VOID DsimModel::setup (IINSTANCE *instance, IDSIMCKT *dsimckt)
{
	
	inst = instance;
	ckt = dsimckt;
	pin1 = inst->getdsimpin("Pin1", true);
	pin2 = inst->getdsimpin("Pin2", true);
	pin3 = inst->getdsimpin("Pin3", true);
	pin4 = inst->getdsimpin("Pin4", true);
	pin5 = inst->getdsimpin("Pin5", true);
	pin6 = inst->getdsimpin("Pin6", true);
	pin7 = inst->getdsimpin("Pin7", true);

	
}

VOID DsimModel::runctrl (RUNMODES mode)
{
}

VOID DsimModel::actuate (REALTIME time, ACTIVESTATE newstate)
{
}

BOOL DsimModel::indicate (REALTIME time, ACTIVEDATA *data)
{
	return FALSE;
}

VOID sendData(SOCKET s, const char* buf)
{
	send(s, buf, strlen(buf) + 1, 0);
	
}

VOID DsimModel::simulate(ABSTIME time, DSIMMODES mode) {
	WORD wVersion = MAKEWORD(2, 2);

	WSADATA dwVersionInfo;

	int status = WSAStartup(wVersion, &dwVersionInfo);
	if (status != 0)
	{

		WSACleanup();
	}
	if (HIBYTE(dwVersionInfo.wVersion) != 2 || LOBYTE(dwVersionInfo.wVersion) != 2)
	{

		WSACleanup();
	}


	SOCKET sockClient = socket(AF_INET, SOCK_STREAM, 0);
	SOCKADDR_IN addrSrv;
	addrSrv.sin_addr.s_addr = inet_addr("192.168.3.22");
	addrSrv.sin_family = AF_INET;
	addrSrv.sin_port = htons(6800);

	//三次握手建立通信
	connect(sockClient, (SOCKADDR*)&addrSrv, sizeof(SOCKADDR));

	if (ishigh(pin1->istate()))
	{
		sendData(sockClient, "w");
	}
	else if (ishigh(pin2->istate()))
	{
		sendData(sockClient, "s");
	}
	else if (ishigh(pin3->istate()))
	{
		sendData(sockClient, "a");
	}
	else if (ishigh(pin4->istate()))
	{
		sendData(sockClient, "d");
	}
	else if (ishigh(pin5->istate()))
	{
		sendData(sockClient, "q");
	}
	else if (ishigh(pin6->istate()))
	{
		sendData(sockClient, "e");
	}
	else if (ishigh(pin7->istate()))
	{
		sendData(sockClient, "r");
	}
	else {
		sendData(sockClient, "cancel");
	}

	closesocket(sockClient);
	WSACleanup();
	
}

VOID DsimModel::callback (ABSTIME time, EVENTID eventid){
	
}


