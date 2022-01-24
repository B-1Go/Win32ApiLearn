﻿// Client.cpp : 애플리케이션에 대한 진입점을 정의합니다.
//

#include "framework.h"
#include "Client.h"

#define MAX_LOADSTRING 100

// 전역 변수:
HINSTANCE hInst;                                // 현재 인스턴스입니다.
WCHAR szTitle[MAX_LOADSTRING];                  // 제목 표시줄 텍스트입니다.
WCHAR szWindowClass[MAX_LOADSTRING];            // 기본 창 클래스 이름입니다.
HWND g_hWnd; // 메인 윈도우 핸들

// 이 코드 모듈에 포함된 함수의 선언을 전달합니다:
ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);

// 지역
// 전역
// 정적 (데이터 영역)
// 1. 함수 안에
// 2. 파일
// 3. 클래스 안에
// 외부
class CClass
{
private:
    int m_i;

public:
    static int m_iStatic; // 정적 멤버 함수 (데이터 영역) -> 따라서 CClass 객체가 생성될때 메모리 공간과 크기에 영향을 주지 않는다. 즉 CCalss는 int m_i 4바이트만 객체 생성시 stack 메모리에 올라감.
    
public:
    void func()
    {
        m_i = 0;
        m_iStatic = 0;
    }

    // 정적 멤버함수, 객체 없이 호출 가능, this 가 없다(멤버 접근 불가), 정적 멤버는 접근 가능
    static void FUNC()
    {
        m_iStatic = 0;
    }
};

int CClass::m_iStatic = 0; // pulic된 정적멤버는 반드시 초기화 해줘야한다. 이건 정적멤버의 문법이다.


// SAL 주석
int APIENTRY wWinMain(_In_ HINSTANCE hInstance, /*실행 된 프로세스의 시작 주소*/
                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPWSTR    lpCmdLine,
                     _In_ int       nCmdShow)
{
    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);

    // TODO: 여기에 코드를 입력합니다.

    // 전역 문자열을 초기화합니다.  
    LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
    LoadStringW(hInstance, IDC_CLIENT, szWindowClass, MAX_LOADSTRING);
    
    // 윈도우 정보 등록
    MyRegisterClass(hInstance);

    // 애플리케이션 초기화를 수행합니다: -> 윈도우 생성
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    // 단축키
    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_CLIENT));

    MSG msg;

    // GetMessage
    // 메세지큐에서 메세지 확인 될 때까지 대기
    // msg.message == WM_QUIT 인 경우 false 를 반환 -> 프로그램 종료
    // 기본 메시지 루프입니다:
    
    // PeekMessage
    // 메세지 유무와 관계없이 반환
    // 메세지큐에서 메세지를 확인한 경우 true, 메세지큐에 메세지가 없는 경우 false를 반환한다.
    while (true)
    {
        if (PeekMessage(&msg, nullptr, 0, 0, PM_REMOVE))
        {
            if (WM_QUIT == msg.message)
            {
                break;
            }
            if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
            {
                TranslateMessage(&msg);
                DispatchMessage(&msg);
            }
        }
        // 메세지가 발생하지 않는 대부분의 시간
        else
        {
            // Game 코드 수행
            // 디자인 패턴(설계 유형)
            // 싱글톤 패턴
        }
    }

    return (int) msg.wParam;
}



//
//  함수: MyRegisterClass()
//
//  용도: 창 클래스를 등록합니다.
//
ATOM MyRegisterClass(HINSTANCE hInstance)
{
    WNDCLASSEXW wcex;

    wcex.cbSize = sizeof(WNDCLASSEX);

    wcex.style          = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc    = WndProc;
    wcex.cbClsExtra     = 0;
    wcex.cbWndExtra     = 0;
    wcex.hInstance      = hInstance;
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_CLIENT));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_CLIENT);
    wcex.lpszClassName  = szWindowClass;
    wcex.hIconSm        = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

    return RegisterClassExW(&wcex);
}

//
//   함수: InitInstance(HINSTANCE, int)
//
//   용도: 인스턴스 핸들을 저장하고 주 창을 만듭니다.
//
//   주석:
//
//        이 함수를 통해 인스턴스 핸들을 전역 변수에 저장하고
//        주 프로그램 창을 만든 다음 표시합니다.
//
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
    hInst = hInstance; // 인스턴스 핸들을 전역 변수에 저장합니다.

    g_hWnd = CreateWindowW(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
        CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, nullptr, nullptr, hInstance, nullptr); // kernel object

    if (!g_hWnd)
    {
        return FALSE;
    }

    ShowWindow(g_hWnd, nCmdShow);
    UpdateWindow(g_hWnd);

    return TRUE;
}

//
//  함수: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  용도: 주 창의 메시지를 처리합니다.
//
//  WM_COMMAND  - 애플리케이션 메뉴를 처리합니다.
//  WM_PAINT    - 주 창을 그립니다.
//  WM_DESTROY  - 종료 메시지를 게시하고 반환합니다.
//
//

#include <vector>

using std::vector;

struct tObjInfo
{
    POINT g_ptObjPos;
    POINT g_ptObjScale;
};

vector<tObjInfo> g_vecInfo;

POINT g_ptLT; // 좌상단 좌표
POINT g_ptRB; // 우하단 좌표
bool bLbtnDown = false;

LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam) // 부가인자 WPARAM wParam(키보드입력), LPARAM lParam(마우스입력)
{
    switch (message)
    {
    case WM_COMMAND:
        {
            int wmId = LOWORD(wParam);
            // 메뉴 선택을 구문 분석합니다:
            switch (wmId)
            {
            case IDM_ABOUT:
                DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
                break;
            case IDM_EXIT:
                DestroyWindow(hWnd);
                break;
            default:
                return DefWindowProc(hWnd, message, wParam, lParam);
            }
        }
        break;
    case WM_PAINT: // 무효화 영역(Invalidate)이 발생한 경우 -> WM_PAINT 동작
        {
            PAINTSTRUCT ps;

            // Device Context 만들어서 kernel 에서 제공하는 window ID 를 반환
            HDC hdc = BeginPaint(hWnd, &ps); // Device Context (kernel object) - 그리기 관련
            // DC 의 목적지는 hwnd
            // DC 의 펜은 기본펜(Black)
            // DC 의 브러쉬는 기본 브러쉬(White)(사각형 안을 색칠함)

            // 직접 펜을 만들어서 DC에 제공
            HPEN hRedPen = CreatePen(PS_SOLID, 1, RGB(255, 0, 0));
            // HBRUSH hBlueBrush = GetStockObject(); // 자주 쓰는 오브젝트들 미리 만들어 놓음 -> 내가 만들게 아니기 때문에 삭제하면 안됨
            HBRUSH hBlueBrush = CreateSolidBrush(RGB(0, 0, 255));

            // 기본 펜 ID 값을 받아 둠
            HPEN hDefaultPen = (HPEN)SelectObject(hdc, hRedPen); // SelectObject는 범용적으로 쓰기 위해서 viod 함수이고 따라서 해당 목적에 맞에 캐스팅을 해줘야 한다. HPEN, HBRUSH etc.
            // 기본 Drush ID 값을 받아 둠
            HBRUSH hDefaultBrush = (HBRUSH)SelectObject(hdc, hBlueBrush);
            
            // 변경된 펜으로 사각형 그림
            if (bLbtnDown)
            {
                Rectangle(hdc
                    , g_ptLT.x, g_ptLT.y
                    , g_ptRB.x, g_ptRB.y);
            }

            // 추가된 사각형도 그려준다.
            for (int i = 0; i < g_vecInfo.size(); ++i)
            {
                Rectangle(hdc
                    , g_vecInfo[i].g_ptObjPos.x - g_vecInfo[i].g_ptObjScale.x / 2
                    , g_vecInfo[i].g_ptObjPos.y - g_vecInfo[i].g_ptObjScale.y / 2
                    , g_vecInfo[i].g_ptObjPos.x + g_vecInfo[i].g_ptObjScale.x / 2
                    , g_vecInfo[i].g_ptObjPos.y + g_vecInfo[i].g_ptObjScale.y / 2);
            }

            // DC 의 펜과 Bush 를 원래 펜으로 되돌림
            SelectObject(hdc, hDefaultPen);
            SelectObject(hdc, hDefaultBrush);

            // 다 쓴 Red펜 과 Brush 삭제 요청
            DeleteObject(hRedPen); // kernel 에서 관리하는 메모리 이므로 함스로 요청해야 된다.
            DeleteObject(hBlueBrush);

            // 그리기 종료
            EndPaint(hWnd, &ps);
        }
        break;
    case WM_KEYDOWN: // UINT message 에서 키보드 입력을 했을 때
    {
        switch (wParam) // WPARAM wParam 어떤 키보드를 눌렀는지 부가인자로 확인 가능
        {
        case VK_UP:
            //g_ptObjPos.y -= 10;
            InvalidateRect(hWnd, nullptr, true);
            break;
        case VK_DOWN:
            //g_ptObjPos.y += 10;
            InvalidateRect(hWnd, nullptr, true);
            break;
        case VK_LEFT:
            //g_ptObjPos.x -= 10;
            InvalidateRect(hWnd, nullptr, true);
            break;
        case VK_RIGHT:
            //g_ptObjPos.x += 10;
            InvalidateRect(hWnd, nullptr, true);
            break;
            break;
        }
    }
        break;
    case WM_LBUTTONDOWN:
        g_ptLT.x = LOWORD(lParam);
        g_ptLT.y = HIWORD(lParam);
        bLbtnDown = true;
        break;
    case WM_MOUSEMOVE:
        g_ptRB.x = LOWORD(lParam);
        g_ptRB.y = HIWORD(lParam);
        InvalidateRect(hWnd, nullptr, true);
        break;
    case WM_LBUTTONUP:
    {
        g_ptRB.x = LOWORD(lParam);
        g_ptRB.y = HIWORD(lParam);

        tObjInfo info = {};
        info.g_ptObjPos.x = (g_ptLT.x + g_ptRB.x) / 2;
        info.g_ptObjPos.y = (g_ptLT.y + g_ptRB.y) / 2;

        info.g_ptObjScale.x = abs(g_ptLT.x - g_ptRB.x);
        info.g_ptObjScale.y = abs(g_ptLT.y - g_ptRB.y);

        g_vecInfo.push_back(info);
        bLbtnDown = false;
        InvalidateRect(hWnd, nullptr, true);
    }
        break;
    case WM_TIMER:
        break;
    case WM_DESTROY:
        PostQuitMessage(0);
        break;
    default:
        return DefWindowProc(hWnd, message, wParam, lParam);
    }
    return 0;
}

// 정보 대화 상자의 메시지 처리기입니다.
INT_PTR CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
    UNREFERENCED_PARAMETER(lParam);
    switch (message)
    {
    case WM_INITDIALOG:
        return (INT_PTR)TRUE;

    case WM_COMMAND:
        if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL)
        {
            EndDialog(hDlg, LOWORD(wParam));
            return (INT_PTR)TRUE;
        }
        break;
    }
    return (INT_PTR)FALSE;
}