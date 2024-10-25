
// 5-1 학생 카드View.h: CMy51학생카드View 클래스의 인터페이스
//

#pragma once


class CMy51학생카드View : public CView
{
protected: // serialization에서만 만들어집니다.
	CMy51학생카드View() noexcept;
	DECLARE_DYNCREATE(CMy51학생카드View)

// 특성입니다.
public:
	CMy51학생카드Doc* GetDocument() const;

// 작업입니다.
public:

// 재정의입니다.
public:
	virtual void OnDraw(CDC* pDC);  // 이 뷰를 그리기 위해 재정의되었습니다.
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// 구현입니다.
public:
	virtual ~CMy51학생카드View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 생성된 메시지 맵 함수
protected:
	DECLARE_MESSAGE_MAP()
public:
	bool m_bHobboy;
	bool m_dSex;
	afx_msg void OnRButtonDown(UINT nFlags, CPoint point);
	CString m_strDept[10];
	CString m_strName[10];
	CString m_strSex[10];
	CString m_strHobby[10];
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	CPoint m_point[10];
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	int m_Count =0;
};

#ifndef _DEBUG  // 5-1 학생 카드View.cpp의 디버그 버전
inline CMy51학생카드Doc* CMy51학생카드View::GetDocument() const
   { return reinterpret_cast<CMy51학생카드Doc*>(m_pDocument); }
#endif

/*

1. 왼쪽 마우스 버튼 눌린 위치에 학생 카드를 삽입
2. 오른쪽 마우스 버튼 누르면 최근 입력한 카드를 삭제
3. 최대 10개의 학생 카드를 입력할 수 있도록 하라
*/