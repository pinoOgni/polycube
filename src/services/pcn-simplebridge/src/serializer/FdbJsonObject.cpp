/**
* simplebridge API
* Simple L2 Bridge Service
*
* OpenAPI spec version: 1.0.0
*
* NOTE: This class is auto generated by the swagger code generator program.
* https://github.com/polycube-network/swagger-codegen.git
* branch polycube
*/


/* Do not edit this file manually */



#include "FdbJsonObject.h"
#include <regex>

namespace io {
namespace swagger {
namespace server {
namespace model {

FdbJsonObject::FdbJsonObject() : 
  m_agingTimeIsSet(false),
  m_entryIsSet(false) { }

FdbJsonObject::FdbJsonObject(nlohmann::json &val) : 
  m_agingTimeIsSet(false),
  m_entryIsSet(false) { 
  if (val.count("aging-time")) {
    setAgingTime(val.at("aging-time").get<uint32_t>());
  }

  m_entry.clear();
  for (auto& item : val["entry"]) { 
    FdbEntryJsonObject newItem { item };
    m_entry.push_back(newItem);
  }
  m_entryIsSet = !m_entry.empty();
  
}

nlohmann::json FdbJsonObject::toJson() const {
  nlohmann::json val = nlohmann::json::object();

  if (m_agingTimeIsSet) {
    val["aging-time"] = m_agingTime;
  }

  {
    nlohmann::json jsonArray;
    for (auto& item : m_entry) {
      jsonArray.push_back(JsonObjectBase::toJson(item));
    }
    if (jsonArray.size() > 0) {
      val["entry"] = jsonArray;
    }
  }

  return val;
}

nlohmann::json FdbJsonObject::helpKeys() {
  nlohmann::json val = nlohmann::json::object();


  return val;
}

nlohmann::json FdbJsonObject::helpElements() {
  nlohmann::json val = nlohmann::json::object();

  val["aging-time"]["name"] = "aging-time";
  val["aging-time"]["type"] = "leaf"; // Suppose that type is leaf
  val["aging-time"]["simpletype"] = "integer";
  val["aging-time"]["description"] = R"POLYCUBE(Aging time of the filtering database (in seconds))POLYCUBE";
  val["aging-time"]["example"] = R"POLYCUBE(300)POLYCUBE";
  val["entry"]["name"] = "entry";
  val["entry"]["type"] = "leaf"; // Suppose that type is leaf
  val["entry"]["type"] = "list";
  val["entry"]["description"] = R"POLYCUBE(Entry associated with the filtering database)POLYCUBE";
  val["entry"]["example"] = R"POLYCUBE()POLYCUBE";

  return val;
}

nlohmann::json FdbJsonObject::helpWritableLeafs() {
  nlohmann::json val = nlohmann::json::object();

  val["aging-time"]["name"] = "aging-time";
  val["aging-time"]["simpletype"] = "integer";
  val["aging-time"]["description"] = R"POLYCUBE(Aging time of the filtering database (in seconds))POLYCUBE";
  val["aging-time"]["example"] = R"POLYCUBE(300)POLYCUBE";

  return val;
}

nlohmann::json FdbJsonObject::helpComplexElements() {
  nlohmann::json val = nlohmann::json::object();

  val["entry"]["name"] = "entry";
  val["entry"]["type"] = "list";
  val["entry"]["description"] = R"POLYCUBE(Entry associated with the filtering database)POLYCUBE";
  val["entry"]["example"] = R"POLYCUBE()POLYCUBE";

  return val;
}

std::vector<std::string> FdbJsonObject::helpActions() {
  std::vector<std::string> val;
  val.push_back("flush");
  return val;
}

uint32_t FdbJsonObject::getAgingTime() const {
  return m_agingTime;
}

void FdbJsonObject::setAgingTime(uint32_t value) {
  m_agingTime = value;
  m_agingTimeIsSet = true;
}

bool FdbJsonObject::agingTimeIsSet() const {
  return m_agingTimeIsSet;
}

void FdbJsonObject::unsetAgingTime() {
  m_agingTimeIsSet = false;
}



const std::vector<FdbEntryJsonObject>& FdbJsonObject::getEntry() const{
  return m_entry;
}

void FdbJsonObject::addFdbEntry(FdbEntryJsonObject value) {
  m_entry.push_back(value);
}


bool FdbJsonObject::entryIsSet() const {
  return m_entryIsSet;
}

void FdbJsonObject::unsetEntry() {
  m_entryIsSet = false;
}




}
}
}
}

