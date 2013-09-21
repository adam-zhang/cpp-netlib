// Copyright (C) 2013 by Glyn Matthews
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#ifndef __NETWORK_HTTP_V2_CLIENT_CONNECTION_RESOLVER_DELEGATE_INC__
#define __NETWORK_HTTP_V2_CLIENT_CONNECTION_RESOLVER_DELEGATE_INC__

#include <cstdint>
#include <string>
#include <functional>
#include <utility>
#include <future>
#include <boost/asio/ip/tcp.hpp>

namespace network {
  namespace http {
    namespace v2 {
      /**
       * \class resolver_delegate network/http/v2/client/connection/resolver_delegate.hpp
       * \brief Resolver delegate.
       */
      class resolver_delegate {

        resolver_delegate(const resolver_delegate &) = delete;
        resolver_delegate &operator = (const resolver_delegate &) = delete;

      public:

        /**
         * \brief resolver
         */
        typedef boost::asio::ip::tcp::resolver resolver;

        /**
         * \brief resolver_iterator
         */
        typedef resolver::iterator resolver_iterator;

        /**
         * \brief callback_fn
         */
        typedef std::function<void (const boost::system::error_code&,
                                    resolver_iterator)> callback_fn;

        /**
         * \brief Constructor.
         */
        resolver_delegate() = default;

        /**
         * \brief Destructor.
         */
        virtual ~resolver_delegate() noexcept { }

        /**
         * \brief Resolves a host.
         * \param host The host name.
         * \param port The port number.
         * \param callback Invoked after the host has been resolved.
         */
        virtual void async_resolve(const std::string &host, std::uint16_t port, callback_fn callback) = 0;

        virtual void clear_resolved_cache() = 0;

      };
    } // namespace v2
  } // namespace http
} // namespace network

#endif // __NETWORK_HTTP_V2_CLIENT_CONNECTION_RESOLVER_DELEGATE_INC__
