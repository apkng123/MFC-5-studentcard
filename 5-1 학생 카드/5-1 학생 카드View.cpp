
// 5-1 학생 카드View.cpp: CMy51학생카드View 클래스의 구현
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS는 미리 보기, 축소판 그림 및 검색 필터 처리기를 구현하는 ATL 프로젝트에서 정의할 수 있으며
// 해당 프로젝트와 문서 코드를 공유하도록 해 줍니다.
#ifndef SHARED_HANDLERS
#include "5-1 학생 카드.h"
#endif

#include "5-1 학생 카드Doc.h"
#include "5-1 학생 카드View.h"
#include "CCardDlg.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMy51학생카드View

IMPLEMENT_DYNCREATE(CMy51학생카드View, CView)

BEGIN_MESSAGE_MAP(CMy51학생카드View, CView)
	// 표준 인쇄 명령입니다.
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_RBUTTONDOWN()
	ON_WM_LBUTTONDOWN()
	ON_WM_MOUSEMOVE()
	ON_WM_LBUTTONUP()
END_MESSAGE_MAP()

// CMy51학생카드View 생성/소멸

CMy51학생카드View::CMy51학생카드View() noexcept
{
	// TODO: 여기에 생성 코드를 추가합니다.

}

CMy51학생카드View::~CMy51학생카드View()
{
}

BOOL CMy51학생카드View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.

	return CView::PreCreateWindow(cs);
}

// CMy51학생카드View 그리기

void CMy51학생카드View::OnDraw(CDC* pDC)
{
	CMy51학생카드Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 여기에 원시 데이터에 대한 그리기 코드를 추가합니다.
	for (int i = 0; i <= 9; i++)
	{

		pDC->TextOut(m_point[i].x, m_point[i].y, m_strDept[i]);
		pDC->TextOut(m_point[i].x, m_point[i].y + 30, m_strName[i]);
		pDC->TextOut(m_point[i].x, m_point[i].y + 60, m_strSex[i]);
		pDC->TextOut(m_point[i].x, m_point[i].y + 90, m_strHobby[i]);
	}
}


// CMy51학생카드View 인쇄

BOOL CMy51학생카드View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 기본적인 준비
	return DoPreparePrinting(pInfo);
}

void CMy51학생카드View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄하기 전에 추가 초기화 작업을 추가합니다.
}

void CMy51학생카드View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄 후 정리 작업을 추가합니다.
}


// CMy51학생카드View 진단

#ifdef _DEBUG
void CMy51학생카드View::AssertValid() const
{
	CView::AssertValid();
}

void CMy51학생카드View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMy51학생카드Doc* CMy51학생카드View::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy51학생카드Doc)));
	return (CMy51학생카드Doc*)m_pDocument;
}
#endif //_DEBUG


// CMy51학생카드View 메시지 처리기


void CMy51학생카드View::OnRButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	
	if (m_Count >=1)
	{
		m_strHobby[m_Count -1].Empty();
		m_strName[m_Count - 1].Empty();
		m_strSex[m_Count - 1].Empty();
		m_strDept[m_Count - 1].Empty();
		m_Count--;

	}
	else if(m_Count<1){
		
	
		AfxMessageBox(_T("삭제할 텍스트가 없습니다"));
	}
	CView::OnRButtonDown(nFlags, point);
	Invalidate();
}


void CMy51학생카드View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	int i=m_Count;
	CView::OnLButtonDown(nFlags, point);
	m_point[i].x = point.x;
	m_point[i].y = point.y;


	CCardDlg* pCard = new CCardDlg;
	m_strHobby[i].Empty();
	if (pCard->DoModal() == IDOK) {
		if (i <= 9)
		{
			m_strDept[i] = pCard->m_strDept;
			m_strName[i] = pCard->m_strName;




			if (pCard->m_bSex == true)
			{
				m_strSex[i] = _T("남자");

			}
			else {
				m_strSex[i] = _T("여자");
			}
			if (pCard->m_bHobby[0])
				m_strHobby[i] += _T("독서");
			if (pCard->m_bHobby[1])
				m_strHobby[i] += _T("운동");
			if (pCard->m_bHobby[2])
				m_strHobby[i] += _T("낚시");
		}
	}
	m_Count++;
	Invalidate();
	
}


void CMy51학생카드View::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	

	CView::OnMouseMove(nFlags, point);
}


void CMy51학생카드View::OnLButtonUp(UINT nFlags, CPoint point)
{
	

	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.

	CView::OnLButtonUp(nFlags, point);
}
