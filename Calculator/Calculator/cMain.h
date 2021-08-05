#pragma once
#include "wx/wx.h"
#include "wx/wxchar.h"

class cMain: public wxFrame
{
public:
	cMain();
	~cMain();

public:
	wxButton *m_btn1 = nullptr;
	wxButton *m_btn2 = nullptr;
	wxButton *m_btn3 = nullptr;
	wxButton *m_btn4 = nullptr;
	wxButton *m_btn5 = nullptr;
	wxButton *m_btn6 = nullptr;
	wxButton *m_btn7 = nullptr;
	wxButton *m_btn8 = nullptr;
	wxButton *m_btn9 = nullptr;
	wxButton *m_btn0 = nullptr;
	wxButton *m_btnplus = nullptr;
	wxButton *m_btnminus = nullptr;
	wxButton *m_btntimes = nullptr;
	wxButton *m_btndivide = nullptr;
	wxButton *m_btnequal = nullptr;
	wxButton *m_btnclear = nullptr;
	wxTextCtrl *m_txt1 = nullptr;

	void OnButtonClicked(wxCommandEvent &evt);
	void OnButtonClicked2(wxCommandEvent &evt);
	void OnButtonClicked3(wxCommandEvent &evt);
	void OnButtonClicked4(wxCommandEvent &evt);
	void OnButtonClicked5(wxCommandEvent &evt);
	void OnButtonClicked6(wxCommandEvent &evt);
	void OnButtonClicked7(wxCommandEvent &evt);
	void OnButtonClicked8(wxCommandEvent &evt);
	void OnButtonClicked9(wxCommandEvent &evt);
	void OnButtonClicked0(wxCommandEvent &evt);
	void OnButtonClickedPlus(wxCommandEvent &evt);
	void OnButtonClickedMinus(wxCommandEvent &evt);
	void OnButtonClickedTimes(wxCommandEvent &evt);
	void OnButtonClickedDivide(wxCommandEvent &evt);
	void OnButtonClickedEqual(wxCommandEvent &evt);
	void OnButtonClickedClear(wxCommandEvent &evt);

	wxDECLARE_EVENT_TABLE();
};

