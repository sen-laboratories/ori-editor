/**
 * @author Gregor Rosenauer <gregor.rosenauer@gmail.com>
 * All Rights Reserved.
 * Distributed under the terms of the MIT License.
 */

#include <Message.h>
#include <Messenger.h>
#include <spdlog/spdlog.h>
#include <sen/Sen.h>
#include "SenConnector.h"

status_t SenConnector::QueryForSenId(entry_ref *ref, const char *senId)
{
    status_t result;
    spdlog::debug("query for SEN:ID for ref {}", ref->name);

    BMessage query(sen::cmd::kQueryIdForRef);
    query.AddRef("refs", ref);
    query.AddBool("createIfMissing", true);

    BMessenger messenger(sen::kServerSignature);
    BMessage reply;

    if (messenger.SendMessage(&query, &reply) == B_OK) {
        result = reply.FindString("ids", &senId);
        if (result != B_OK) {
            spdlog::warn("failed to get SEN:ID for ref {}: {}", ref->name, strerror(result));
            return B_ENTRY_NOT_FOUND;
        }
        spdlog::debug("got SEN:ID {} for ref {}.", senId, ref->name);
    } else {
        spdlog::debug("SEN server is not running, no SEN:ID available.");
        return B_ENTRY_NOT_FOUND;
    }

    return B_OK;
}

