#pragma once
#include "DNSBase.hpp"
#include "LatencyTest.hpp"
#include "base/QvBase.hpp"

#include <type_traits>
namespace Qvmessocket::components::latency::tcping
{
    class TCPing : public DNSBase<TCPing>
    {
      public:
        using DNSBase<TCPing>::DNSBase;
        void start();
        ~TCPing() override;

      protected:
      private:
        void ping() override;
        void notifyTestHost();
    };
}
