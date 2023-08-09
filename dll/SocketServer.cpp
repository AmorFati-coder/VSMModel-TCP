//// SocketServer.cpp : Defines the class behaviors for the application.
////
//
//#include "stdafx.h"
//#include "SocketHandle.h"
//#include "SocketServer.h"
//
//#ifdef _DEBUG
//#define new DEBUG_NEW
//#endif
//
//
//// CSocketServerApp
//
//BEGIN_MESSAGE_MAP(CSocketServerApp, CWinApp)
//    ON_COMMAND(ID_HELP, &CWinApp::OnHelp)
//END_MESSAGE_MAP()
//
//
//// CSocketServerApp construction
//
//CSocketServerApp::CSocketServerApp()
//{
//    // TODO: add construction code here,
//    // Place all significant initialization in InitInstance
//    m_nLinkMode = 0; // server
//}
//
//
//// The one and only CSocketServerApp object
//
//CSocketServerApp theApp;
//
//
//// CSocketServerApp initialization
//
//BOOL CSocketServerApp::InitInstance()
//{
//    // InitCommonControlsEx() is required on Windows XP if an application
//    // manifest specifies use of ComCtl32.dll version 6 or later to enable
//    // visual styles.  Otherwise, any window creation will fail.
//    INITCOMMONCONTROLSEX InitCtrls;
//    InitCtrls.dwSize = sizeof(InitCtrls);
//    // Set this to include all the common control classes you want to use
//    // in your application.
//    InitCtrls.dwICC = ICC_WIN95_CLASSES;
//    InitCommonControlsEx(&InitCtrls);
//
//    CSocketHandle::InitLibrary(MAKEWORD(2, 2));
//
//    CWinApp::InitInstance();
//
//    AfxEnableControlContainer();
//
//    // Standard initialization
//    // If you are not using these features and wish to reduce the size
//    // of your final executable, you should remove from the following
//    // the specific initialization routines you do not need
//    // Change the registry key under which our settings are stored
//    // TODO: You should modify this string to be something appropriate
//    // such as the name of your company or organization
//    SetRegistryKey(_T("Local AppWizard-Generated Applications"));
//
//    ParseCommandLineArgs();
//
//    CSocketServerDlg dlg1;
//    CSocketClientDlg dlg2;
//    switch (m_nLinkMode)
//    {
//    case 1:
//        m_pMainWnd = &dlg2; // Client
//        break;
//    case 0:
//    default:
//        m_pMainWnd = &dlg1; // Server
//        break;
//    }
//    INT_PTR nResponse = ((CDialog*)m_pMainWnd)->DoModal();
//    if (nResponse == IDOK)
//    {
//        // TODO: Place code here to handle when the dialog is
//        //  dismissed with OK
//    }
//    else if (nResponse == IDCANCEL)
//    {
//        // TODO: Place code here to handle when the dialog is
//        //  dismissed with Cancel
//    }
//
//    CSocketHandle::ReleaseLibrary();
//
//    // Since the dialog has been closed, return FALSE so that we exit the
//    //  application, rather than start the application's message pump.
//    return FALSE;
//}
//
//void CSocketServerApp::ParseCommandLineArgs()
//{
//    CString strCmdLine = m_lpCmdLine;
//    if (!strCmdLine.IsEmpty())
//    {
//        strCmdLine.MakeUpper();
//        while (!strCmdLine.IsEmpty())
//        {
//            CString strCurrent = strCmdLine;
//            int nNextPos = strCmdLine.Find(TCHAR(' '));
//            if (nNextPos > 0)
//            {
//                strCurrent = strCmdLine.Left(nNextPos);
//                strCmdLine.Delete(0, nNextPos + 1);
//            }
//            else
//            {
//                strCurrent = strCmdLine;
//                strCmdLine = _T("");
//            }
//
//            if (strCurrent == _T("/SERVER") || strCurrent == _T("/S"))
//                m_nLinkMode = 0;
//            else if (strCurrent == _T("/CLIENT") || strCurrent == _T("/C"))
//                m_nLinkMode = 1;
//
//        }
//
//    }
//}
//
