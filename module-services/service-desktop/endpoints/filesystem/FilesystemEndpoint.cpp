// Copyright (c) 2017-2021, Mudita Sp. z.o.o. All rights reserved.
// For licensing, see https://github.com/mudita/MuditaOS/LICENSE.md

#include <endpoints/filesystem/FilesystemEndpoint.hpp>
#include <endpoints/filesystem/FS_Helper.hpp>
#include <endpoints/message/Sender.hpp>
#include <log/log.hpp>

namespace sdesktop::endpoints
{
    using sender::putToSendQueue;

    auto FilesystemEndpoint::handle(Context &context) -> void
    {
        const auto &[sent, response] = helper->process(context.getMethod(), context);

        if (sent == sent::delayed) {
            LOG_DEBUG("There is no proper delayed serving mechanism - depend on invisible context caching");
        }
        if (sent == sent::no) {
            if (not response) {
                LOG_ERROR("Response not sent & response not created : respond with error");
                context.setResponseStatus(http::Code::NotAcceptable);
            }
            else {
                context.setResponse(response.value());
            }

            sender::putToSendQueue(context.createSimpleResponse());
        }
        if (sent == sent::yes and response) {
            LOG_ERROR("Response set when we already handled response in handler");
        }
    }

} // namespace sdesktop::endpoints
