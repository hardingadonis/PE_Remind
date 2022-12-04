/*********************************************************************************
*                                                                                *
* MIT License                                                                    *
*                                                                                *
* Copyright (c) 2022 Minh Vương                                                  *
*                                                                                *
* Permission is hereby granted, free of charge, to any person obtaining a copy   *
* of this software and associated documentation files (the "Software"), to deal  *
* in the Software without restriction, including without limitation the rights   *
* to use, copy, modify, merge, publish, distribute, sublicense, and/or sell      *
* copies of the Software, and to permit persons to whom the Software is          *
* furnished to do so, subject to the following conditions:                       *
*                                                                                *
* The above copyright notice and this permission notice shall be included in all *
* copies or substantial portions of the Software.                                *
*                                                                                *
* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR     *
* IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,       *
* FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE    *
* AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER         *
* LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,  *
* OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE  *
* SOFTWARE.                                                                      *
*                                                                                *
*********************************************************************************/

#include <wx/statline.h>

#include <UI/MainPanel.hpp>

namespace EPR
{
	// IDs for the controls
	enum EPR_Button
	{
		EPR_Button_Start	= 11001,
		EPR_Button_Stop		= 11002
	};

	wxBEGIN_EVENT_TABLE(MainPanel, wxPanel)
		EVT_BUTTON(EPR_Button_Start, MainPanel::OnStartButtonPressed)
		EVT_BUTTON(EPR_Button_Stop, MainPanel::OnStopButtonPressed)
	wxEND_EVENT_TABLE()

	MainPanel::MainPanel(wxWindow* _parent) :
		wxPanel(_parent, wxID_ANY),
		m_timerValue(nullptr),
		m_startButton(nullptr),
		m_stopButton(nullptr),
		m_parent((wxFrameBase*)_parent)
	{
		CreateControls();
	}

	void MainPanel::OnStartButtonPressed(wxCommandEvent& _event)
	{
		m_parent->SetStatusText("Eyes Protection Reminder is still running...", 1);

		_event.Skip();
	}

	void MainPanel::OnStopButtonPressed(wxCommandEvent& _event)
	{
		m_parent->SetStatusText("Eyes Protection Reminder was stopped!", 1);

		_event.Skip();
	}

	void MainPanel::CreateControls()
	{
		// Create label to show the value of timer
		m_timerValue = new wxStaticText(this, wxID_ANY, "20:00");
		m_timerValue->SetFont(wxFont(90, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false));
		m_timerValue->SetToolTip("To show the timer...");

		// Create label to show the value of rested
		m_restedValue = new wxStaticText(this, wxID_ANY, "00:20");
		m_restedValue->SetFont(wxFont(20, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false));
		m_restedValue->SetToolTip("To show the rested time...");

		// Create start button
		m_startButton = new wxButton(this, EPR_Button_Start, "&Start");
		m_startButton->SetToolTip("To start the timer...");

		// Create stop button
		m_stopButton = new wxButton(this, EPR_Button_Stop, "&Stop");
		m_stopButton->SetToolTip("To stop the timer...");

		// Create static line
		wxStaticLine* _staticLine = new wxStaticLine(this, wxID_ANY, wxDefaultPosition, wxSize(455, 1), wxLI_HORIZONTAL);

		// Create flags
		wxSizerFlags _flags = wxSizerFlags().Border().Center();

		// Create bottom sizer
		wxSizer* _bottomSizer = new wxBoxSizer(wxHORIZONTAL);
		_bottomSizer->Add(m_startButton, 1, wxEXPAND | wxALL, 15);
		_bottomSizer->Add(m_stopButton, 1, wxEXPAND | wxALL, 15);

		// Create main sizer
		wxSizer* _mainSizer = new wxBoxSizer(wxVERTICAL);
		_mainSizer->Add(m_timerValue, _flags);
		_mainSizer->Add(m_restedValue, _flags);
		_mainSizer->Add(_staticLine, _flags);
		_mainSizer->Add(_bottomSizer, 1, wxEXPAND | wxALL);

		SetSizer(_mainSizer);
		Layout();
	}
}