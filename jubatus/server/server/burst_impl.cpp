// This file is auto-generated from burst.idl(0.4.5-405-gf5f59de) with jenerator version 0.4.5-418-gd2d5f04/follow-up-0.5.x
// *** DO NOT EDIT ***

#include <map>
#include <string>
#include <vector>
#include <utility>
#include "jubatus/util/lang/shared_ptr.h"

#include "../../server/framework.hpp"
#include "burst_serv.hpp"

namespace jubatus {
namespace server {

class burst_impl : public jubatus::server::common::mprpc::rpc_server {
 public:
  explicit burst_impl(const jubatus::server::framework::server_argv& a):
    rpc_server(a.timeout),
    p_(new jubatus::server::framework::server_helper<burst_serv>(a, true)) {

    rpc_server::add<bool(std::string, std::vector<st_document>)>(
        "add_documents", jubatus::util::lang::bind(&burst_impl::add_documents,
        this, jubatus::util::lang::_2));
    rpc_server::add<st_window(std::string, std::string)>("get_result",
        jubatus::util::lang::bind(&burst_impl::get_result, this,
        jubatus::util::lang::_2));
    rpc_server::add<st_window(std::string, std::string, double)>(
        "get_result_at", jubatus::util::lang::bind(&burst_impl::get_result_at,
        this, jubatus::util::lang::_2, jubatus::util::lang::_3));
    rpc_server::add<std::map<std::string, st_window>(std::string)>(
        "get_all_bursted_results", jubatus::util::lang::bind(
        &burst_impl::get_all_bursted_results, this));
    rpc_server::add<std::map<std::string, st_window>(std::string, double)>(
        "get_all_bursted_results_at", jubatus::util::lang::bind(
        &burst_impl::get_all_bursted_results_at, this,
        jubatus::util::lang::_2));
    rpc_server::add<std::vector<st_keyword>(std::string)>("get_all_keywords",
        jubatus::util::lang::bind(&burst_impl::get_all_keywords, this));
    rpc_server::add<bool(std::string, st_keyword)>("add_keyword",
        jubatus::util::lang::bind(&burst_impl::add_keyword, this,
        jubatus::util::lang::_2));
    rpc_server::add<bool(std::string, std::string)>("remove_keyword",
        jubatus::util::lang::bind(&burst_impl::remove_keyword, this,
        jubatus::util::lang::_2));
    rpc_server::add<bool(std::string)>("remove_all_keywords",
        jubatus::util::lang::bind(&burst_impl::remove_all_keywords, this));

    rpc_server::add<std::string(std::string)>("get_config",
        jubatus::util::lang::bind(&burst_impl::get_config, this));
    rpc_server::add<bool(std::string, std::string)>("save",
        jubatus::util::lang::bind(&burst_impl::save, this,
        jubatus::util::lang::_2));
    rpc_server::add<bool(std::string, std::string)>("load",
        jubatus::util::lang::bind(&burst_impl::load, this,
        jubatus::util::lang::_2));
    rpc_server::add<std::map<std::string, std::map<std::string, std::string> >(
        std::string)>("get_status", jubatus::util::lang::bind(
        &burst_impl::get_status, this));
  }

  bool add_documents(const std::vector<st_document>& data) {
    JWLOCK_(p_);
    return get_p()->add_documents(data);
  }

  st_window get_result(const std::string& keyword_txt) {
    JRLOCK_(p_);
    return get_p()->get_result(keyword_txt);
  }

  st_window get_result_at(const std::string& keyword_txt, double pos) {
    JRLOCK_(p_);
    return get_p()->get_result_at(keyword_txt, pos);
  }

  std::map<std::string, st_window> get_all_bursted_results() {
    JRLOCK_(p_);
    return get_p()->get_all_bursted_results();
  }

  std::map<std::string, st_window> get_all_bursted_results_at(double pos) {
    JRLOCK_(p_);
    return get_p()->get_all_bursted_results_at(pos);
  }

  std::vector<st_keyword> get_all_keywords() {
    JRLOCK_(p_);
    return get_p()->get_all_keywords();
  }

  bool add_keyword(const st_keyword& keyword) {
    JWLOCK_(p_);
    return get_p()->add_keyword(keyword);
  }

  bool remove_keyword(const std::string& keyword_txt) {
    JWLOCK_(p_);
    return get_p()->remove_keyword(keyword_txt);
  }

  bool remove_all_keywords() {
    JWLOCK_(p_);
    return get_p()->remove_all_keywords();
  }

  std::string get_config() {
    JRLOCK_(p_);
    return get_p()->get_config();
  }

  bool save(const std::string& id) {
    JWLOCK_(p_);
    return get_p()->save(id);
  }

  bool load(const std::string& id) {
    JWLOCK_(p_);
    return get_p()->load(id);
  }

  std::map<std::string, std::map<std::string, std::string> > get_status() {
    JRLOCK_(p_);
    return p_->get_status();
  }

  int run() { return p_->start(*this); }
  jubatus::util::lang::shared_ptr<burst_serv> get_p() { return p_->server(); }

 private:
  jubatus::util::lang::shared_ptr<jubatus::server::framework::server_helper<burst_serv> > p_;
};

}  // namespace server
}  // namespace jubatus

int main(int argc, char* argv[]) {
  return
    jubatus::server::framework::run_server<jubatus::server::burst_impl>
      (argc, argv, "burst");
}
