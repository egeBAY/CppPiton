#include "cMain.h"

wxBEGIN_EVENT_TABLE(cMain, wxFrame)
	EVT_BUTTON(10001, OnButtonClicked)
	EVT_BUTTON(10002, OnButtonClicked2)
	EVT_BUTTON(10003, OnButtonClicked3)
	EVT_BUTTON(10004, OnButtonClicked4)
	EVT_BUTTON(10005, OnButtonClicked5)
	EVT_BUTTON(10006, OnButtonClicked6)
	EVT_BUTTON(10007, OnButtonClicked7)
	EVT_BUTTON(10008, OnButtonClicked8)
	EVT_BUTTON(10009, OnButtonClicked9)
	EVT_BUTTON(10000, OnButtonClicked0)
	EVT_BUTTON(10010, OnButtonClickedPlus)
	EVT_BUTTON(10011, OnButtonClickedMinus)
	EVT_BUTTON(10012, OnButtonClickedTimes)
	EVT_BUTTON(10013, OnButtonClickedDivide)
	EVT_BUTTON(10014, OnButtonClickedEqual)
	EVT_BUTTON(10015, OnButtonClickedClear)
wxEND_EVENT_TABLE()

cMain::cMain(): wxFrame(nullptr, wxID_ANY, "Calculator App", wxPoint(30,30), wxSize(800,600))
{
	m_txt1 = new wxTextCtrl(this, wxID_ANY, "", wxPoint(10, 10), wxSize(700, 150));
	m_btn1 = new wxButton(this, 10001, "1", wxPoint(10, 300), wxSize(100, 50));
	m_btn2 = new wxButton(this, 10002, "2", wxPoint(110, 300), wxSize(100, 50));
	m_btn3 = new wxButton(this, 10003, "3", wxPoint(210, 300), wxSize(100, 50));
	m_btn4 = new wxButton(this, 10004, "4", wxPoint(10, 350), wxSize(100, 50));
	m_btn5 = new wxButton(this, 10005, "5", wxPoint(110, 350), wxSize(100, 50));
	m_btn6 = new wxButton(this, 10006, "6", wxPoint(210, 350), wxSize(100, 50));
	m_btn7 = new wxButton(this, 10007, "7", wxPoint(10, 400), wxSize(100, 50));
	m_btn8 = new wxButton(this, 10008, "8", wxPoint(110, 400), wxSize(100, 50));
	m_btn9 = new wxButton(this, 10009, "9", wxPoint(210, 400), wxSize(100, 50));
	m_btn0 = new wxButton(this, 10000, "0", wxPoint(110, 450), wxSize(100, 50));
	m_btnplus = new wxButton(this, 10010, "+", wxPoint(310, 300), wxSize(100, 50));
	m_btnminus = new wxButton(this, 10011, "-", wxPoint(310, 350), wxSize(100, 50));
	m_btntimes = new wxButton(this, 10012, "x", wxPoint(310, 400), wxSize(100, 50));
	m_btndivide = new wxButton(this, 10013, "/", wxPoint(310, 450), wxSize(100, 50));
	m_btnequal = new wxButton(this, 10014, "=", wxPoint(210, 450), wxSize(100, 50));
	m_btnclear = new wxButton(this, 10015, "CE", wxPoint(10, 450), wxSize(100, 50));
}


cMain::~cMain()
{
}

wxString fast, last, Res;
int Operand1, Operand2, Operators;
float Answer;

void cMain::OnButtonClicked(wxCommandEvent &evt)
{
	if(m_txt1->GetValue() == "0")
	{
		m_txt1->SetValue(m_btn1->GetLabel());
	}
	else
	{
		m_txt1->AppendText(m_btn1->GetLabel());
	}
}
void cMain::OnButtonClicked2(wxCommandEvent &evt)
{
	if (m_txt1->GetValue() == "0")
	{
		m_txt1->SetValue(m_btn2->GetLabel());
	}
	else
	{
		m_txt1->AppendText(m_btn2->GetLabel());
	}
}
void cMain::OnButtonClicked3(wxCommandEvent &evt)
{
	if (m_txt1->GetValue() == "0")
	{
		m_txt1->SetValue(m_btn3->GetLabel());
	}
	else
	{
		m_txt1->AppendText(m_btn3->GetLabel());
	}

}
void cMain::OnButtonClicked4(wxCommandEvent &evt)
{
	if (m_txt1->GetValue() == "0")
	{
		m_txt1->SetValue(m_btn4->GetLabel());
	}
	else
	{
		m_txt1->AppendText(m_btn4->GetLabel());
	}
}
void cMain::OnButtonClicked5(wxCommandEvent &evt)
{
	if (m_txt1->GetValue() == "0")
	{
		m_txt1->SetValue(m_btn5->GetLabel());
	}
	else
	{
		m_txt1->AppendText(m_btn5->GetLabel());
	}
}
void cMain::OnButtonClicked6(wxCommandEvent &evt)
{
	if (m_txt1->GetValue() == "0")
	{
		m_txt1->SetValue(m_btn6->GetLabel());
	}
	else
	{
		m_txt1->AppendText(m_btn6->GetLabel());
	}
}
void cMain::OnButtonClicked7(wxCommandEvent &evt)
{
	if (m_txt1->GetValue() == "0")
	{
		m_txt1->SetValue(m_btn7->GetLabel());
	}
	else
	{
		m_txt1->AppendText(m_btn7->GetLabel());
	}
}
void cMain::OnButtonClicked8(wxCommandEvent &evt)
{
	if (m_txt1->GetValue() == "0")
	{
		m_txt1->SetValue(m_btn8->GetLabel());
	}
	else
	{
		m_txt1->AppendText(m_btn8->GetLabel());
	}
}
void cMain::OnButtonClicked9(wxCommandEvent &evt)
{
	if (m_txt1->GetValue() == "0")
	{
		m_txt1->SetValue(m_btn9->GetLabel());
	}
	else
	{
		m_txt1->AppendText(m_btn9->GetLabel());
	}
}
void cMain::OnButtonClicked0(wxCommandEvent &evt)
{
	if (m_txt1->GetValue() == "0")
	{
		m_txt1->SetValue(m_btn0->GetLabel());
	}
	else
	{
		m_txt1->AppendText(m_btn0->GetLabel());
	}
}
void cMain::OnButtonClickedPlus(wxCommandEvent &evt)
{
	fast = m_txt1->GetValue();
	Operand1 = wxAtoi(fast);
	Operators = 1; // +
	m_txt1->SetValue("0");
}
void cMain::OnButtonClickedMinus(wxCommandEvent &evt)
{
	fast = m_txt1->GetValue();
	Operand1 = wxAtoi(fast);
	Operators = 2; // -
	m_txt1->SetValue("0");
}
void cMain::OnButtonClickedTimes(wxCommandEvent &evt)
{
	fast = m_txt1->GetValue();
	Operand1 = wxAtoi(fast);
	Operators = 3; // x
	m_txt1->SetValue("0");
}
void cMain::OnButtonClickedDivide(wxCommandEvent &evt)
{
	fast = m_txt1->GetValue();
	Operand1 = wxAtoi(fast);
	Operators = 4; // /
	m_txt1->SetValue("0");
}
void cMain::OnButtonClickedEqual(wxCommandEvent &evt)
{
	last = m_txt1->GetValue();
	Operand2 = wxAtoi(last);
	switch (Operators)
	{
	case 1:
		Answer = float(Operand1) + float(Operand2);
		Res = wxString::Format(wxT("%g"), Answer);
		m_txt1->SetValue(Res);
		break;
	case 2:
		Answer = float(Operand1) - float(Operand2);
		Res = wxString::Format(wxT("%g"), Answer);
		m_txt1->SetValue(Res);
		break;
	case 3:
		Answer = float(Operand1) * float(Operand2);
		Res = wxString::Format(wxT("%g"), Answer);
		m_txt1->SetValue(Res);
		break;
	case 4:
		Answer = float(Operand1) / float(Operand2);
		Res = wxString::Format(wxT("%g"), Answer);
		m_txt1->SetValue(Res);
		break;
	}
}
void cMain::OnButtonClickedClear(wxCommandEvent &evt)
{
	m_txt1->Clear();
}