/*
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2024-2026 SEN Labs e.U.
 */

#pragma once

#include <GroupView.h>
#include <StringView.h>
#include <SupportDefs.h>
#include <TextControl.h>

#define OUTLINE_SEPARATOR "\xE2\x86\x92"

class StatusBar : public BView {

public:
                  StatusBar();
    virtual      ~StatusBar();
    void          UpdatePosition(int32 offset, int32 line, int32 column);
    void          UpdateSelection(int32 selectionStart, int32 selectionEnd);
    void          UpdateOutline(const BMessage* outline);

private:
    BTextControl *fLine;
    BTextControl *fColumn;
    BTextControl *fOffset;
    BTextControl *fSelection;
    // detail info on text outline from markup parser
    BStringView  *fOutline;
};
