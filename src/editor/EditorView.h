/*
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2024-2026 SEN Labs e.U.
 */

#pragma once

#include <GroupView.h>
#include <ScrollView.h>
#include <SupportDefs.h>

#include "../common/ColorDefs.h"
#include "EditorTextView.h"
#include "StatusBar.h"

class EditorView : public BView {

public:
                    EditorView(BHandler* parent);
    virtual         ~EditorView();
    virtual void    MessageReceived(BMessage* message);

    void            SetText(BFile *file, size_t size);
    void            SetText(const char* text);

private:
    BHandler*       fParentHandler;
    EditorTextView* fTextView;
    BScrollView*	fScrollView;
    StatusBar*      fStatusBar;
    ColorDefs*      fColorDefs;
};
