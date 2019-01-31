/**
* lbrp API
* LoadBalancer Reverse-Proxy Service
*
* OpenAPI spec version: 2.0.0
*
* NOTE: This class is auto generated by the swagger code generator program.
* https://github.com/polycube-network/swagger-codegen.git
* branch polycube
*/


/* Do not edit this file manually */



#include "ArpEntryJsonObject.h"
#include <regex>

namespace io {
namespace swagger {
namespace server {
namespace model {

ArpEntryJsonObject::ArpEntryJsonObject() {

  m_addressIsSet = false;

  m_macIsSet = false;
}

ArpEntryJsonObject::~ArpEntryJsonObject() {}

void ArpEntryJsonObject::validateKeys() {

  if (!m_addressIsSet) {
    throw std::runtime_error("Variable address is required");
  }
}

void ArpEntryJsonObject::validateMandatoryFields() {

  if (!m_macIsSet) {
    throw std::runtime_error("Variable mac is required");
  }
}

void ArpEntryJsonObject::validateParams() {

}

nlohmann::json ArpEntryJsonObject::toJson() const {
  nlohmann::json val = nlohmann::json::object();

  if (m_addressIsSet) {
    val["address"] = m_address;
  }

  val["mac"] = m_mac;

  return val;
}

void ArpEntryJsonObject::fromJson(nlohmann::json& val) {
  for(nlohmann::json::iterator it = val.begin(); it != val.end(); ++it) {
    std::string key = it.key();
    bool found = (std::find(allowedParameters_.begin(), allowedParameters_.end(), key) != allowedParameters_.end());
    if (!found) {
      throw std::runtime_error(key + " is not a valid parameter");
      return;
    }
  }

  if (val.find("address") != val.end()) {
    setAddress(val.at("address"));
  }

  if (val.find("mac") != val.end()) {
    setMac(val.at("mac"));
  }
}

nlohmann::json ArpEntryJsonObject::helpKeys() {
  nlohmann::json val = nlohmann::json::object();

  val["address"]["name"] = "address";
  val["address"]["type"] = "key";
  val["address"]["simpletype"] = "string";
  val["address"]["description"] = R"POLYCUBE(Destination IP address)POLYCUBE";
  val["address"]["example"] = R"POLYCUBE(123.13.34.0)POLYCUBE";

  return val;
}

nlohmann::json ArpEntryJsonObject::helpElements() {
  nlohmann::json val = nlohmann::json::object();

  val["mac"]["name"] = "mac";
  val["mac"]["type"] = "leaf"; // Suppose that type is leaf
  val["mac"]["simpletype"] = "string";
  val["mac"]["description"] = R"POLYCUBE(Destination MAC address)POLYCUBE";
  val["mac"]["example"] = R"POLYCUBE(C5:13:2D:36:27:9B)POLYCUBE";

  return val;
}

nlohmann::json ArpEntryJsonObject::helpWritableLeafs() {
  nlohmann::json val = nlohmann::json::object();

  val["mac"]["name"] = "mac";
  val["mac"]["simpletype"] = "string";
  val["mac"]["description"] = R"POLYCUBE(Destination MAC address)POLYCUBE";
  val["mac"]["example"] = R"POLYCUBE(C5:13:2D:36:27:9B)POLYCUBE";

  return val;
}

nlohmann::json ArpEntryJsonObject::helpComplexElements() {
  nlohmann::json val = nlohmann::json::object();


  return val;
}

std::vector<std::string> ArpEntryJsonObject::helpActions() {
  std::vector<std::string> val;
  return val;
}

std::string ArpEntryJsonObject::getAddress() const {
  return m_address;
}

void ArpEntryJsonObject::setAddress(std::string value) {
  m_address = value;
  m_addressIsSet = true;
}

bool ArpEntryJsonObject::addressIsSet() const {
  return m_addressIsSet;
}

void ArpEntryJsonObject::unsetAddress() {
  m_addressIsSet = false;
}



std::string ArpEntryJsonObject::getMac() const {
  return m_mac;
}

void ArpEntryJsonObject::setMac(std::string value) {
  m_mac = value;
  m_macIsSet = true;
}

bool ArpEntryJsonObject::macIsSet() const {
  return m_macIsSet;
}

void ArpEntryJsonObject::unsetMac() {
  m_macIsSet = false;
}




}
}
}
}
