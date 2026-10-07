/*
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2025-2026 SEN Labs e.U.
 */

#pragma once

#include <Entry.h>
#include <sys/types.h>

 class SenConnector {
    public:
        static status_t QueryForSenId(entry_ref *ref, const char *senId);
 };
