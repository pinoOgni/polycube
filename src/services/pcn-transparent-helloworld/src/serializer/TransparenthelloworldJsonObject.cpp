/**
* transparenthelloworld API
* transparenthelloworld API generated from transparenthelloworld.yang
*
* OpenAPI spec version: 1.0.0
*
* NOTE: This class is auto generated by the swagger code generator program.
* https://github.com/polycube-network/swagger-codegen.git
* branch polycube
*/


/* Do not edit this file manually */



#include "TransparenthelloworldJsonObject.h"
#include <regex>

namespace io {
namespace swagger {
namespace server {
namespace model {

TransparenthelloworldJsonObject::TransparenthelloworldJsonObject() {
  m_nameIsSet = false;
  m_ingressAction = TransparenthelloworldIngressActionEnum::PASS;
  m_ingressActionIsSet = true;
  m_egressAction = TransparenthelloworldEgressActionEnum::PASS;
  m_egressActionIsSet = true;
}

TransparenthelloworldJsonObject::TransparenthelloworldJsonObject(const nlohmann::json &val) :
  JsonObjectBase(val) {
  m_nameIsSet = false;
  m_ingressActionIsSet = false;
  m_egressActionIsSet = false;


  if (val.count("name")) {
    setName(val.at("name").get<std::string>());
  }

  if (val.count("ingress-action")) {
    setIngressAction(string_to_TransparenthelloworldIngressActionEnum(val.at("ingress-action").get<std::string>()));
  }

  if (val.count("egress-action")) {
    setEgressAction(string_to_TransparenthelloworldEgressActionEnum(val.at("egress-action").get<std::string>()));
  }
}

nlohmann::json TransparenthelloworldJsonObject::toJson() const {
  nlohmann::json val = nlohmann::json::object();
  if (!getBase().is_null()) {
    val.update(getBase());
  }

  if (m_nameIsSet) {
    val["name"] = m_name;
  }

  if (m_ingressActionIsSet) {
    val["ingress-action"] = TransparenthelloworldIngressActionEnum_to_string(m_ingressAction);
  }

  if (m_egressActionIsSet) {
    val["egress-action"] = TransparenthelloworldEgressActionEnum_to_string(m_egressAction);
  }

  return val;
}

std::string TransparenthelloworldJsonObject::getName() const {
  return m_name;
}

void TransparenthelloworldJsonObject::setName(std::string value) {
  m_name = value;
  m_nameIsSet = true;
}

bool TransparenthelloworldJsonObject::nameIsSet() const {
  return m_nameIsSet;
}



TransparenthelloworldIngressActionEnum TransparenthelloworldJsonObject::getIngressAction() const {
  return m_ingressAction;
}

void TransparenthelloworldJsonObject::setIngressAction(TransparenthelloworldIngressActionEnum value) {
  m_ingressAction = value;
  m_ingressActionIsSet = true;
}

bool TransparenthelloworldJsonObject::ingressActionIsSet() const {
  return m_ingressActionIsSet;
}

void TransparenthelloworldJsonObject::unsetIngressAction() {
  m_ingressActionIsSet = false;
}

std::string TransparenthelloworldJsonObject::TransparenthelloworldIngressActionEnum_to_string(const TransparenthelloworldIngressActionEnum &value){
  switch(value) {
    case TransparenthelloworldIngressActionEnum::DROP:
      return std::string("drop");
    case TransparenthelloworldIngressActionEnum::PASS:
      return std::string("pass");
    case TransparenthelloworldIngressActionEnum::SLOWPATH:
      return std::string("slowpath");
    default:
      throw std::runtime_error("Bad Transparenthelloworld ingressAction");
  }
}

TransparenthelloworldIngressActionEnum TransparenthelloworldJsonObject::string_to_TransparenthelloworldIngressActionEnum(const std::string &str){
  if (JsonObjectBase::iequals("drop", str))
    return TransparenthelloworldIngressActionEnum::DROP;
  if (JsonObjectBase::iequals("pass", str))
    return TransparenthelloworldIngressActionEnum::PASS;
  if (JsonObjectBase::iequals("slowpath", str))
    return TransparenthelloworldIngressActionEnum::SLOWPATH;
  throw std::runtime_error("Transparenthelloworld ingressAction is invalid");
}
TransparenthelloworldEgressActionEnum TransparenthelloworldJsonObject::getEgressAction() const {
  return m_egressAction;
}

void TransparenthelloworldJsonObject::setEgressAction(TransparenthelloworldEgressActionEnum value) {
  m_egressAction = value;
  m_egressActionIsSet = true;
}

bool TransparenthelloworldJsonObject::egressActionIsSet() const {
  return m_egressActionIsSet;
}

void TransparenthelloworldJsonObject::unsetEgressAction() {
  m_egressActionIsSet = false;
}

std::string TransparenthelloworldJsonObject::TransparenthelloworldEgressActionEnum_to_string(const TransparenthelloworldEgressActionEnum &value){
  switch(value) {
    case TransparenthelloworldEgressActionEnum::DROP:
      return std::string("drop");
    case TransparenthelloworldEgressActionEnum::PASS:
      return std::string("pass");
    case TransparenthelloworldEgressActionEnum::SLOWPATH:
      return std::string("slowpath");
    default:
      throw std::runtime_error("Bad Transparenthelloworld egressAction");
  }
}

TransparenthelloworldEgressActionEnum TransparenthelloworldJsonObject::string_to_TransparenthelloworldEgressActionEnum(const std::string &str){
  if (JsonObjectBase::iequals("drop", str))
    return TransparenthelloworldEgressActionEnum::DROP;
  if (JsonObjectBase::iequals("pass", str))
    return TransparenthelloworldEgressActionEnum::PASS;
  if (JsonObjectBase::iequals("slowpath", str))
    return TransparenthelloworldEgressActionEnum::SLOWPATH;
  throw std::runtime_error("Transparenthelloworld egressAction is invalid");
}

}
}
}
}

