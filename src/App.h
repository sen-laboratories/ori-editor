/*
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2024-2026 SEN Labs e.U.
 */
#pragma once

#include <Application.h>

class App : public BApplication
{
public:
							App();
	virtual					~App();
    virtual void            ArgvReceived(int32 argc, char ** argv);
	virtual void			AboutRequested();
    virtual	void            MessageReceived(BMessage* message);

private:
    status_t	        	LoadSettings(BMessage* settings);
    status_t		        SaveSettings(BMessage* settings);
    void                    ApplySettings(BMessage* settings);

    BMessage*               fSettings;
    int32                   fWindowCount;
};

