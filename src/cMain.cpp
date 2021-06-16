#include "cMain.h"
#include <iostream>
#include <string>


wxBEGIN_EVENT_TABLE(cMain, wxFrame)
    EVT_BUTTON(10001, cMain::OnButton1Clicked)
    EVT_BUTTON(10002, cMain::OnButton2Clicked)
wxEND_EVENT_TABLE()

cMain::cMain() : wxFrame(nullptr, wxID_ANY, "wxWidgets - 800x600", wxPoint(30,30), wxSize(800,600)) {

    m_btn1 = std::make_unique<wxButton>(this, 10001, "Add value", wxPoint(10,10), wxSize(80,30));
    m_btn2 = std::make_unique<wxButton>(this, 10002, "Clear values", wxPoint(90, 10), wxSize(130,30));
    m_txt1 = std::make_unique<wxTextCtrl>(this, wxID_ANY, "", wxPoint(10,40), wxSize(300,30));
    m_lstb1 = std::make_unique<wxListBox>(this, wxID_ANY, wxPoint(10, 70), wxSize(600,300));
    
    m_prs = std::make_unique<Parser>();
    PopulateListBox();
}

void cMain::OnButton1Clicked(wxCommandEvent &evt) {
    m_lstb1->AppendString(m_txt1->GetValue());
    evt.Skip();
}

void cMain::OnButton2Clicked(wxCommandEvent &evt2) {
    int selection = m_lstb1->GetSelection();
    m_lstb1->Delete(selection);
    evt2.Skip();
}

void cMain::PopulateListBox() {
    for (const auto &process : m_prs->getProcesses()) m_lstb1->AppendString(process.getProcessInformation()); 
}

cMain::~cMain() {
    std::cout << "Collecting garbage and closing" << std::endl;
}
