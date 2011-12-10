
// This file is auto-generated from stat.idl
// *** DO NOT EDIT ***

#ifndef STAT_SERVER_HPP_
#define STAT_SERVER_HPP_


#include "stat_types.hpp"
#include <pficommon/network/mprpc.h>
#include <pficommon/lang/bind.h>


namespace jubatus {

namespace server {

template <class Impl>
class stat : public pfi::network::mprpc::rpc_server {
public:
  stat(double timeout_sec): rpc_server(timeout_sec) {

    rpc_server::add<int32_t(std::string, std::string, double) >("push", pfi::lang::bind(&Impl::push, static_cast<Impl*>(this), pfi::lang::_1, pfi::lang::_2, pfi::lang::_3));
    rpc_server::add<double(std::string, std::string, int32_t) >("sum", pfi::lang::bind(&Impl::sum, static_cast<Impl*>(this), pfi::lang::_1, pfi::lang::_2, pfi::lang::_3));
    rpc_server::add<double(std::string, std::string, int32_t) >("stddev", pfi::lang::bind(&Impl::stddev, static_cast<Impl*>(this), pfi::lang::_1, pfi::lang::_2, pfi::lang::_3));
    rpc_server::add<double(std::string, std::string, int32_t) >("max", pfi::lang::bind(&Impl::max, static_cast<Impl*>(this), pfi::lang::_1, pfi::lang::_2, pfi::lang::_3));
    rpc_server::add<double(std::string, std::string, int32_t) >("min", pfi::lang::bind(&Impl::min, static_cast<Impl*>(this), pfi::lang::_1, pfi::lang::_2, pfi::lang::_3));
    rpc_server::add<double(std::string, std::string, int32_t) >("entropy", pfi::lang::bind(&Impl::entropy, static_cast<Impl*>(this), pfi::lang::_1, pfi::lang::_2, pfi::lang::_3));
    rpc_server::add<double(std::string, std::string, int32_t) >("moment", pfi::lang::bind(&Impl::moment, static_cast<Impl*>(this), pfi::lang::_1, pfi::lang::_2, pfi::lang::_3));
    rpc_server::add<int32_t(std::string, std::string) >("save", pfi::lang::bind(&Impl::save, static_cast<Impl*>(this), pfi::lang::_1, pfi::lang::_2));
    rpc_server::add<int32_t(std::string, std::string) >("load", pfi::lang::bind(&Impl::load, static_cast<Impl*>(this), pfi::lang::_1, pfi::lang::_2));
  }
};

} // namespace server

} // namespace jubatus



#endif // STAT_SERVER_HPP_
