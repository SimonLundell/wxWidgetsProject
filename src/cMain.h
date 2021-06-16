/*
Compile with: g++ files.cpp `wx-config --cxxflags --libs`
*/

#ifndef CMAIN_H
#define CMAIN_H

#include "wx/wx.h"
//#include "wx/grid.h"
//#include "cProcess.h"
#include "cParser.h"
#include <memory>


class cMain : public wxFrame {
    public:
      cMain();
      ~cMain();
      
      wxDECLARE_EVENT_TABLE();

      void OnButton1Clicked(wxCommandEvent &evt);
      void OnButton2Clicked(wxCommandEvent &evt2);
      void PopulateListBox();

      private:
        // wxWidget stuff
        std::unique_ptr<wxButton> m_btn1 = nullptr;
        std::unique_ptr<wxButton> m_btn2 = nullptr;
        std::unique_ptr<wxTextCtrl> m_txt1 = nullptr;
        std::unique_ptr<wxListBox> m_lstb1 = nullptr;

        // linux stuff
        std::unique_ptr<Parser> m_prs = nullptr;
};

#endif