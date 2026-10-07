/*
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2024-2026 SEN Labs e.U.
 */
#pragma once

#include <FilePanel.h>
#include <MenuBar.h>
#include <MenuItem.h>
#include <TextControl.h>
#include <Window.h>

#include "editor/EditorView.h"
#include "panels/outline/OutlinePanel.h"

class MainWindow : public BWindow
{
public:
							MainWindow(const BMessage* settings);
	virtual					~MainWindow();

	virtual void			MessageReceived(BMessage* msg);
    virtual bool            QuitRequested();

    BMessage*               GetWindowSettings() { return fSettings; };

private:
    void                    ApplySettings(BMessage* settings);
    BMenuBar*		        BuildMenu();

    BMessage*               fSettings;
    BMenuItem*		        fSaveMenuItem;
    // panels
    BMenuItem*              fOutlinePanelItem;

    BFilePanel*		        fOpenPanel;
    BFilePanel*		        fSavePanel;
    OutlinePanel*           fOutlinePanel;

    EditorView*             fEditorView;
};
