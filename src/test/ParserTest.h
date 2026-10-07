/*
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2025-2026 SEN Labs e.U.
 */

#pragma once

#include <Application.h>

class ParserTest : public BApplication
{
public:
							ParserTest();
	virtual					~ParserTest();

    void                    PrintSeparator(const char* title);
};
