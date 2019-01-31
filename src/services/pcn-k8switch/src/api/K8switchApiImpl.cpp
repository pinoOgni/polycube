/**
* k8switch API
* Kubernetes HyperSwitch Service
*
* OpenAPI spec version: 2.0.0
*
* NOTE: This class is auto generated by the swagger code generator program.
* https://github.com/polycube-network/swagger-codegen.git
* branch polycube
*/


/* Do not edit this file manually */


#include "K8switchApiImpl.h"

namespace io {
namespace swagger {
namespace server {
namespace api {

using namespace io::swagger::server::model;

K8switchApiImpl::K8switchApiImpl() {}

/*
* These functions include a default basic implementation.  The user could
* extend adapt this implementation to his needs.
*/

std::shared_ptr<K8switch> K8switchApiImpl::get_cube(const std::string &name) {
  std::lock_guard<std::mutex> guard(cubes_mutex);
  auto iter = cubes.find(name);
  if (iter == cubes.end()) {
    throw std::runtime_error("Cube " + name + " does not exist");
  }

  return iter->second;
}

void K8switchApiImpl::create_k8switch_by_id(const std::string &name, const K8switchJsonObject &jsonObject) {
  {
    // check if name is valid before creating it
    std::lock_guard<std::mutex> guard(cubes_mutex);
    if (cubes.count(name) != 0) {
      throw std::runtime_error("There is already a cube with name " + name);
    }
  }
  auto ptr = std::make_shared<K8switch>(name, jsonObject, jsonObject.getType());
  std::unordered_map<std::string, std::shared_ptr<K8switch>>::iterator iter;
  bool inserted;

  std::lock_guard<std::mutex> guard(cubes_mutex);
  std::tie(iter, inserted) = cubes.emplace(name, std::move(ptr));

  if (!inserted) {
    throw std::runtime_error("There is already a cube with name " + name);
  }
}

void K8switchApiImpl::replace_k8switch_by_id(const std::string &name, const K8switchJsonObject &bridge){
  throw std::runtime_error("Method not supported!");
}

void K8switchApiImpl::delete_k8switch_by_id(const std::string &name) {
  std::lock_guard<std::mutex> guard(cubes_mutex);
  if (cubes.count(name) == 0) {
    throw std::runtime_error("Cube " + name + " does not exist");
  }
  cubes.erase(name);
}

std::string K8switchApiImpl::read_k8switch_uuid_by_id(const std::string &name) {
  auto m = get_cube(name);
  return m->getUuid();
}

std::vector<K8switchJsonObject> K8switchApiImpl::read_k8switch_list_by_id() {
  std::vector<K8switchJsonObject> jsonObject_vect;
  for(auto &i : cubes) {
    auto m = get_cube(i.first);
    jsonObject_vect.push_back(m->toJsonObject());
  }
  return jsonObject_vect;
}

std::vector<nlohmann::fifo_map<std::string, std::string>> K8switchApiImpl::read_k8switch_list_by_id_get_list() {
  std::vector<nlohmann::fifo_map<std::string, std::string>> r;
  for (auto &x : cubes) {
    nlohmann::fifo_map<std::string, std::string> m;
    m["name"] = x.first;
    r.push_back(std::move(m));
  }
  return r;
}

/*
* Ports list related functions
*/
void K8switchApiImpl::create_k8switch_ports_list_by_id(const std::string &name, const std::vector<PortsJsonObject> &ports) {
  auto m = get_cube(name);
  m->addPortsList(ports);
}

std::vector<PortsJsonObject> K8switchApiImpl::read_k8switch_ports_list_by_id(const std::string &name) {
  std::vector<PortsJsonObject> vect;
  auto m = get_cube(name);
  for (auto &i : m->getPortsList()) {
    vect.push_back(i->toJsonObject());
  }
  return vect;
}

void K8switchApiImpl::replace_k8switch_ports_list_by_id(const std::string &name, const std::vector<PortsJsonObject> &ports) {
  throw std::runtime_error("Method not supported");
}

void K8switchApiImpl::delete_k8switch_ports_list_by_id(const std::string &name) {
  auto m = get_cube(name);
  m->delPortsList();
}

std::vector<nlohmann::fifo_map<std::string, std::string>> K8switchApiImpl::read_k8switch_ports_list_by_id_get_list(const std::string &name) {
  std::vector<nlohmann::fifo_map<std::string, std::string>> r;
  auto m = get_cube(name);
  for(auto &i : m->getPortsList()){
    nlohmann::fifo_map<std::string, std::string> m;
    m["name"] = i->getName();
    r.push_back(std::move(m));
  }
  return r;
}

/*
* Ports related functions
*/
void K8switchApiImpl::create_k8switch_ports_by_id(const std::string &name, const std::string &portsName, const PortsJsonObject &ports) {
  auto m = get_cube(name);
  return m->addPorts(portsName, ports);
}

PortsJsonObject K8switchApiImpl::read_k8switch_ports_by_id(const std::string &name, const std::string &portsName) {
  auto m = get_cube(name);
  return m->getPorts(portsName)->toJsonObject();
}

void K8switchApiImpl::replace_k8switch_ports_by_id(const std::string &name, const std::string &portsName, const PortsJsonObject &ports) {
  auto m = get_cube(name);
  m->replacePorts(portsName, ports);
}

void K8switchApiImpl::delete_k8switch_ports_by_id(const std::string &name, const std::string &portsName) {
  auto m = get_cube(name);
  m->delPorts(portsName);
}

std::string K8switchApiImpl::read_k8switch_ports_peer_by_id(const std::string &name, const std::string &portsName) {
  auto m = get_cube(name);
  auto p = m->getPorts(portsName);
  return p->getPeer();
}

PortsStatusEnum K8switchApiImpl::read_k8switch_ports_status_by_id(const std::string &name, const std::string &portsName) {
  auto m = get_cube(name);
  auto p = m->getPorts(portsName);
  return p->getStatus();
}

std::string K8switchApiImpl::read_k8switch_ports_uuid_by_id(const std::string &name, const std::string &portsName) {
  auto m = get_cube(name);
  auto p = m->getPorts(portsName);
  return p->getUuid();
}

void K8switchApiImpl::update_k8switch_ports_peer_by_id(const std::string &name, const std::string &portsName, const std::string &peer) {
  auto m = get_cube(name);
  auto p = m->getPorts(portsName);
  p->setPeer(peer);
}


/**
* @brief   Create fwd-table by ID
*
* Create operation of resource: fwd-table*
*
* @param[in] name ID of name
* @param[in] address ID of address
* @param[in] value fwd-tablebody object
*
* Responses:
*
*/
void
K8switchApiImpl::create_k8switch_fwd_table_by_id(const std::string &name, const std::string &address, const FwdTableJsonObject &value) {
  auto k8switch = get_cube(name);

  k8switch->addFwdTable(address, value);
}




/**
* @brief   Create fwd-table by ID
*
* Create operation of resource: fwd-table*
*
* @param[in] name ID of name
* @param[in] value fwd-tablebody object
*
* Responses:
*
*/
void
K8switchApiImpl::create_k8switch_fwd_table_list_by_id(const std::string &name, const std::vector<FwdTableJsonObject> &value) {
  auto k8switch = get_cube(name);
  k8switch->addFwdTableList(value);
}


#ifdef IMPLEMENT_POLYCUBE_GET_LIST
std::vector<nlohmann::fifo_map<std::string, std::string>> K8switchApiImpl::create_k8switch_fwd_table_list_by_id_get_list(const std::string &name, const std::vector<FwdTableJsonObject> &value) {
  std::vector<nlohmann::fifo_map<std::string, std::string>> r;
  auto &&k8switch = get_cube(name);

  auto &&fwdTable = k8switch->addFwdTableList(value);
  for(auto &i : fwdTable) {
    r.push_back(i->getKeys());
  }
  return r;
}
#endif


/**
* @brief   Create backend by ID
*
* Create operation of resource: backend*
*
* @param[in] name ID of name
* @param[in] vip ID of vip
* @param[in] vport ID of vport
* @param[in] proto ID of proto
* @param[in] ip ID of ip
* @param[in] port ID of port
* @param[in] value backendbody object
*
* Responses:
*
*/
void
K8switchApiImpl::create_k8switch_service_backend_by_id(const std::string &name, const std::string &vip, const uint16_t &vport, const ServiceProtoEnum &proto, const std::string &ip, const uint16_t &port, const ServiceBackendJsonObject &value) {
  auto k8switch = get_cube(name);
  auto service = k8switch->getService(vip, vport, proto);

  service->addBackend(ip, port, value);
}




/**
* @brief   Create backend by ID
*
* Create operation of resource: backend*
*
* @param[in] name ID of name
* @param[in] vip ID of vip
* @param[in] vport ID of vport
* @param[in] proto ID of proto
* @param[in] value backendbody object
*
* Responses:
*
*/
void
K8switchApiImpl::create_k8switch_service_backend_list_by_id(const std::string &name, const std::string &vip, const uint16_t &vport, const ServiceProtoEnum &proto, const std::vector<ServiceBackendJsonObject> &value) {
  auto k8switch = get_cube(name);
  auto service = k8switch->getService(vip, vport, proto);
  service->addBackendList(value);
}


#ifdef IMPLEMENT_POLYCUBE_GET_LIST
std::vector<nlohmann::fifo_map<std::string, std::string>> K8switchApiImpl::create_k8switch_service_backend_list_by_id_get_list(const std::string &name, const std::string &vip, const uint16_t &vport, const ServiceProtoEnum &proto, const std::vector<ServiceBackendJsonObject> &value) {
  std::vector<nlohmann::fifo_map<std::string, std::string>> r;
  auto &&k8switch = get_cube(name);
  auto &&service = k8switch->getService(vip, vport, proto);

  auto &&backend = service->addBackendList(value);
  for(auto &i : backend) {
    r.push_back(i->getKeys());
  }
  return r;
}
#endif


/**
* @brief   Create service by ID
*
* Create operation of resource: service*
*
* @param[in] name ID of name
* @param[in] vip ID of vip
* @param[in] vport ID of vport
* @param[in] proto ID of proto
* @param[in] value servicebody object
*
* Responses:
*
*/
void
K8switchApiImpl::create_k8switch_service_by_id(const std::string &name, const std::string &vip, const uint16_t &vport, const ServiceProtoEnum &proto, const ServiceJsonObject &value) {
  auto k8switch = get_cube(name);

  k8switch->addService(vip, vport, proto, value);
}




/**
* @brief   Create service by ID
*
* Create operation of resource: service*
*
* @param[in] name ID of name
* @param[in] value servicebody object
*
* Responses:
*
*/
void
K8switchApiImpl::create_k8switch_service_list_by_id(const std::string &name, const std::vector<ServiceJsonObject> &value) {
  auto k8switch = get_cube(name);
  k8switch->addServiceList(value);
}


#ifdef IMPLEMENT_POLYCUBE_GET_LIST
std::vector<nlohmann::fifo_map<std::string, std::string>> K8switchApiImpl::create_k8switch_service_list_by_id_get_list(const std::string &name, const std::vector<ServiceJsonObject> &value) {
  std::vector<nlohmann::fifo_map<std::string, std::string>> r;
  auto &&k8switch = get_cube(name);

  auto &&service = k8switch->addServiceList(value);
  for(auto &i : service) {
    r.push_back(i->getKeys());
  }
  return r;
}
#endif


/**
* @brief   Delete fwd-table by ID
*
* Delete operation of resource: fwd-table*
*
* @param[in] name ID of name
* @param[in] address ID of address
*
* Responses:
*
*/
void
K8switchApiImpl::delete_k8switch_fwd_table_by_id(const std::string &name, const std::string &address) {
  auto k8switch = get_cube(name);

  k8switch->delFwdTable(address);
}




/**
* @brief   Delete fwd-table by ID
*
* Delete operation of resource: fwd-table*
*
* @param[in] name ID of name
*
* Responses:
*
*/
void
K8switchApiImpl::delete_k8switch_fwd_table_list_by_id(const std::string &name) {
  auto k8switch = get_cube(name);
  k8switch->delFwdTableList();
}


#ifdef IMPLEMENT_POLYCUBE_GET_LIST
std::vector<nlohmann::fifo_map<std::string, std::string>> K8switchApiImpl::delete_k8switch_fwd_table_list_by_id_get_list(const std::string &name) {
  std::vector<nlohmann::fifo_map<std::string, std::string>> r;
  auto &&k8switch = get_cube(name);

  auto &&fwdTable = k8switch->delFwdTableList();
  for(auto &i : fwdTable) {
    r.push_back(i->getKeys());
  }
  return r;
}
#endif


/**
* @brief   Delete backend by ID
*
* Delete operation of resource: backend*
*
* @param[in] name ID of name
* @param[in] vip ID of vip
* @param[in] vport ID of vport
* @param[in] proto ID of proto
* @param[in] ip ID of ip
* @param[in] port ID of port
*
* Responses:
*
*/
void
K8switchApiImpl::delete_k8switch_service_backend_by_id(const std::string &name, const std::string &vip, const uint16_t &vport, const ServiceProtoEnum &proto, const std::string &ip, const uint16_t &port) {
  auto k8switch = get_cube(name);
  auto service = k8switch->getService(vip, vport, proto);

  service->delBackend(ip, port);
}




/**
* @brief   Delete backend by ID
*
* Delete operation of resource: backend*
*
* @param[in] name ID of name
* @param[in] vip ID of vip
* @param[in] vport ID of vport
* @param[in] proto ID of proto
*
* Responses:
*
*/
void
K8switchApiImpl::delete_k8switch_service_backend_list_by_id(const std::string &name, const std::string &vip, const uint16_t &vport, const ServiceProtoEnum &proto) {
  auto k8switch = get_cube(name);
  auto service = k8switch->getService(vip, vport, proto);
  service->delBackendList();
}


#ifdef IMPLEMENT_POLYCUBE_GET_LIST
std::vector<nlohmann::fifo_map<std::string, std::string>> K8switchApiImpl::delete_k8switch_service_backend_list_by_id_get_list(const std::string &name, const std::string &vip, const uint16_t &vport, const ServiceProtoEnum &proto) {
  std::vector<nlohmann::fifo_map<std::string, std::string>> r;
  auto &&k8switch = get_cube(name);
  auto &&service = k8switch->getService(vip, vport, proto);

  auto &&backend = service->delBackendList();
  for(auto &i : backend) {
    r.push_back(i->getKeys());
  }
  return r;
}
#endif


/**
* @brief   Delete service by ID
*
* Delete operation of resource: service*
*
* @param[in] name ID of name
* @param[in] vip ID of vip
* @param[in] vport ID of vport
* @param[in] proto ID of proto
*
* Responses:
*
*/
void
K8switchApiImpl::delete_k8switch_service_by_id(const std::string &name, const std::string &vip, const uint16_t &vport, const ServiceProtoEnum &proto) {
  auto k8switch = get_cube(name);

  k8switch->delService(vip, vport, proto);
}




/**
* @brief   Delete service by ID
*
* Delete operation of resource: service*
*
* @param[in] name ID of name
*
* Responses:
*
*/
void
K8switchApiImpl::delete_k8switch_service_list_by_id(const std::string &name) {
  auto k8switch = get_cube(name);
  k8switch->delServiceList();
}


#ifdef IMPLEMENT_POLYCUBE_GET_LIST
std::vector<nlohmann::fifo_map<std::string, std::string>> K8switchApiImpl::delete_k8switch_service_list_by_id_get_list(const std::string &name) {
  std::vector<nlohmann::fifo_map<std::string, std::string>> r;
  auto &&k8switch = get_cube(name);

  auto &&service = k8switch->delServiceList();
  for(auto &i : service) {
    r.push_back(i->getKeys());
  }
  return r;
}
#endif


/**
* @brief   Read k8switch by ID
*
* Read operation of resource: k8switch*
*
* @param[in] name ID of name
*
* Responses:
* K8switchJsonObject
*/
K8switchJsonObject
K8switchApiImpl::read_k8switch_by_id(const std::string &name) {
  return get_cube(name)->toJsonObject();

}




/**
* @brief   Read client-subnet by ID
*
* Read operation of resource: client-subnet*
*
* @param[in] name ID of name
*
* Responses:
* std::string
*/
std::string
K8switchApiImpl::read_k8switch_client_subnet_by_id(const std::string &name) {
  auto k8switch = get_cube(name);
  return k8switch->getClientSubnet();

}




/**
* @brief   Read cluster-ip-subnet by ID
*
* Read operation of resource: cluster-ip-subnet*
*
* @param[in] name ID of name
*
* Responses:
* std::string
*/
std::string
K8switchApiImpl::read_k8switch_cluster_ip_subnet_by_id(const std::string &name) {
  auto k8switch = get_cube(name);
  return k8switch->getClusterIpSubnet();

}




/**
* @brief   Read fwd-table by ID
*
* Read operation of resource: fwd-table*
*
* @param[in] name ID of name
* @param[in] address ID of address
*
* Responses:
* FwdTableJsonObject
*/
FwdTableJsonObject
K8switchApiImpl::read_k8switch_fwd_table_by_id(const std::string &name, const std::string &address) {
  auto k8switch = get_cube(name);
  return k8switch->getFwdTable(address)->toJsonObject();

}




/**
* @brief   Read fwd-table by ID
*
* Read operation of resource: fwd-table*
*
* @param[in] name ID of name
*
* Responses:
* std::vector<FwdTableJsonObject>
*/
std::vector<FwdTableJsonObject>
K8switchApiImpl::read_k8switch_fwd_table_list_by_id(const std::string &name) {
  auto k8switch = get_cube(name);
  auto &&fwdTable = k8switch->getFwdTableList();
  std::vector<FwdTableJsonObject> m;
  for(auto &i : fwdTable)
    m.push_back(i->toJsonObject());
  return m;
}

#define IMPLEMENT_POLYCUBE_GET_LIST

#ifdef IMPLEMENT_POLYCUBE_GET_LIST
std::vector<nlohmann::fifo_map<std::string, std::string>> K8switchApiImpl::read_k8switch_fwd_table_list_by_id_get_list(const std::string &name) {
  std::vector<nlohmann::fifo_map<std::string, std::string>> r;
  auto &&k8switch = get_cube(name);

  auto &&fwdTable = k8switch->getFwdTableList();
  for(auto &i : fwdTable) {
    r.push_back(i->getKeys());
  }
  return r;
}
#endif

#undef IMPLEMENT_POLYCUBE_GET_LIST

/**
* @brief   Read mac by ID
*
* Read operation of resource: mac*
*
* @param[in] name ID of name
* @param[in] address ID of address
*
* Responses:
* std::string
*/
std::string
K8switchApiImpl::read_k8switch_fwd_table_mac_by_id(const std::string &name, const std::string &address) {
  auto k8switch = get_cube(name);
  auto fwdTable = k8switch->getFwdTable(address);
  return fwdTable->getMac();

}




/**
* @brief   Read port by ID
*
* Read operation of resource: port*
*
* @param[in] name ID of name
* @param[in] address ID of address
*
* Responses:
* std::string
*/
std::string
K8switchApiImpl::read_k8switch_fwd_table_port_by_id(const std::string &name, const std::string &address) {
  auto k8switch = get_cube(name);
  auto fwdTable = k8switch->getFwdTable(address);
  return fwdTable->getPort();

}




/**
* @brief   Read loglevel by ID
*
* Read operation of resource: loglevel*
*
* @param[in] name ID of name
*
* Responses:
* K8switchLoglevelEnum
*/
K8switchLoglevelEnum
K8switchApiImpl::read_k8switch_loglevel_by_id(const std::string &name) {
  auto k8switch = get_cube(name);
  return k8switch->getLoglevel();

}




/**
* @brief   Read type by ID
*
* Read operation of resource: type*
*
* @param[in] name ID of name
* @param[in] portsName ID of ports_name
*
* Responses:
* PortsTypeEnum
*/
PortsTypeEnum
K8switchApiImpl::read_k8switch_ports_type_by_id(const std::string &name, const std::string &portsName) {
  auto k8switch = get_cube(name);
  auto ports = k8switch->getPorts(portsName);
  return ports->getType();

}




/**
* @brief   Read backend by ID
*
* Read operation of resource: backend*
*
* @param[in] name ID of name
* @param[in] vip ID of vip
* @param[in] vport ID of vport
* @param[in] proto ID of proto
* @param[in] ip ID of ip
* @param[in] port ID of port
*
* Responses:
* ServiceBackendJsonObject
*/
ServiceBackendJsonObject
K8switchApiImpl::read_k8switch_service_backend_by_id(const std::string &name, const std::string &vip, const uint16_t &vport, const ServiceProtoEnum &proto, const std::string &ip, const uint16_t &port) {
  auto k8switch = get_cube(name);
  auto service = k8switch->getService(vip, vport, proto);
  return service->getBackend(ip, port)->toJsonObject();

}




/**
* @brief   Read backend by ID
*
* Read operation of resource: backend*
*
* @param[in] name ID of name
* @param[in] vip ID of vip
* @param[in] vport ID of vport
* @param[in] proto ID of proto
*
* Responses:
* std::vector<ServiceBackendJsonObject>
*/
std::vector<ServiceBackendJsonObject>
K8switchApiImpl::read_k8switch_service_backend_list_by_id(const std::string &name, const std::string &vip, const uint16_t &vport, const ServiceProtoEnum &proto) {
  auto k8switch = get_cube(name);
  auto service = k8switch->getService(vip, vport, proto);
  auto &&backend = service->getBackendList();
  std::vector<ServiceBackendJsonObject> m;
  for(auto &i : backend)
    m.push_back(i->toJsonObject());
  return m;
}

#define IMPLEMENT_POLYCUBE_GET_LIST

#ifdef IMPLEMENT_POLYCUBE_GET_LIST
std::vector<nlohmann::fifo_map<std::string, std::string>> K8switchApiImpl::read_k8switch_service_backend_list_by_id_get_list(const std::string &name, const std::string &vip, const uint16_t &vport, const ServiceProtoEnum &proto) {
  std::vector<nlohmann::fifo_map<std::string, std::string>> r;
  auto &&k8switch = get_cube(name);
  auto &&service = k8switch->getService(vip, vport, proto);

  auto &&backend = service->getBackendList();
  for(auto &i : backend) {
    r.push_back(i->getKeys());
  }
  return r;
}
#endif

#undef IMPLEMENT_POLYCUBE_GET_LIST

/**
* @brief   Read name by ID
*
* Read operation of resource: name*
*
* @param[in] name ID of name
* @param[in] vip ID of vip
* @param[in] vport ID of vport
* @param[in] proto ID of proto
* @param[in] ip ID of ip
* @param[in] port ID of port
*
* Responses:
* std::string
*/
std::string
K8switchApiImpl::read_k8switch_service_backend_name_by_id(const std::string &name, const std::string &vip, const uint16_t &vport, const ServiceProtoEnum &proto, const std::string &ip, const uint16_t &port) {
  auto k8switch = get_cube(name);
  auto service = k8switch->getService(vip, vport, proto);
  auto backend = service->getBackend(ip, port);
  return backend->getName();

}




/**
* @brief   Read weight by ID
*
* Read operation of resource: weight*
*
* @param[in] name ID of name
* @param[in] vip ID of vip
* @param[in] vport ID of vport
* @param[in] proto ID of proto
* @param[in] ip ID of ip
* @param[in] port ID of port
*
* Responses:
* uint16_t
*/
uint16_t
K8switchApiImpl::read_k8switch_service_backend_weight_by_id(const std::string &name, const std::string &vip, const uint16_t &vport, const ServiceProtoEnum &proto, const std::string &ip, const uint16_t &port) {
  auto k8switch = get_cube(name);
  auto service = k8switch->getService(vip, vport, proto);
  auto backend = service->getBackend(ip, port);
  return backend->getWeight();

}




/**
* @brief   Read service by ID
*
* Read operation of resource: service*
*
* @param[in] name ID of name
* @param[in] vip ID of vip
* @param[in] vport ID of vport
* @param[in] proto ID of proto
*
* Responses:
* ServiceJsonObject
*/
ServiceJsonObject
K8switchApiImpl::read_k8switch_service_by_id(const std::string &name, const std::string &vip, const uint16_t &vport, const ServiceProtoEnum &proto) {
  auto k8switch = get_cube(name);
  return k8switch->getService(vip, vport, proto)->toJsonObject();

}




/**
* @brief   Read service by ID
*
* Read operation of resource: service*
*
* @param[in] name ID of name
*
* Responses:
* std::vector<ServiceJsonObject>
*/
std::vector<ServiceJsonObject>
K8switchApiImpl::read_k8switch_service_list_by_id(const std::string &name) {
  auto k8switch = get_cube(name);
  auto &&service = k8switch->getServiceList();
  std::vector<ServiceJsonObject> m;
  for(auto &i : service)
    m.push_back(i->toJsonObject());
  return m;
}

#define IMPLEMENT_POLYCUBE_GET_LIST

#ifdef IMPLEMENT_POLYCUBE_GET_LIST
std::vector<nlohmann::fifo_map<std::string, std::string>> K8switchApiImpl::read_k8switch_service_list_by_id_get_list(const std::string &name) {
  std::vector<nlohmann::fifo_map<std::string, std::string>> r;
  auto &&k8switch = get_cube(name);

  auto &&service = k8switch->getServiceList();
  for(auto &i : service) {
    r.push_back(i->getKeys());
  }
  return r;
}
#endif

#undef IMPLEMENT_POLYCUBE_GET_LIST

/**
* @brief   Read name by ID
*
* Read operation of resource: name*
*
* @param[in] name ID of name
* @param[in] vip ID of vip
* @param[in] vport ID of vport
* @param[in] proto ID of proto
*
* Responses:
* std::string
*/
std::string
K8switchApiImpl::read_k8switch_service_name_by_id(const std::string &name, const std::string &vip, const uint16_t &vport, const ServiceProtoEnum &proto) {
  auto k8switch = get_cube(name);
  auto service = k8switch->getService(vip, vport, proto);
  return service->getName();

}




/**
* @brief   Read type by ID
*
* Read operation of resource: type*
*
* @param[in] name ID of name
*
* Responses:
* CubeType
*/
CubeType
K8switchApiImpl::read_k8switch_type_by_id(const std::string &name) {
  auto k8switch = get_cube(name);
  return k8switch->getType();

}




/**
* @brief   Read virtual-client-subnet by ID
*
* Read operation of resource: virtual-client-subnet*
*
* @param[in] name ID of name
*
* Responses:
* std::string
*/
std::string
K8switchApiImpl::read_k8switch_virtual_client_subnet_by_id(const std::string &name) {
  auto k8switch = get_cube(name);
  return k8switch->getVirtualClientSubnet();

}




/**
* @brief   Replace fwd-table by ID
*
* Replace operation of resource: fwd-table*
*
* @param[in] name ID of name
* @param[in] address ID of address
* @param[in] value fwd-tablebody object
*
* Responses:
*
*/
void
K8switchApiImpl::replace_k8switch_fwd_table_by_id(const std::string &name, const std::string &address, const FwdTableJsonObject &value) {
  auto k8switch = get_cube(name);

  k8switch->replaceFwdTable(address, value);
}




/**
* @brief   Replace fwd-table by ID
*
* Replace operation of resource: fwd-table*
*
* @param[in] name ID of name
* @param[in] value fwd-tablebody object
*
* Responses:
*
*/
void
K8switchApiImpl::replace_k8switch_fwd_table_list_by_id(const std::string &name, const std::vector<FwdTableJsonObject> &value) {
  throw std::runtime_error("Method not supported");
}


#ifdef IMPLEMENT_POLYCUBE_GET_LIST
std::vector<nlohmann::fifo_map<std::string, std::string>> K8switchApiImpl::replace_k8switch_fwd_table_list_by_id_get_list(const std::string &name, const std::vector<FwdTableJsonObject> &value) {
  std::vector<nlohmann::fifo_map<std::string, std::string>> r;
}
#endif


/**
* @brief   Replace backend by ID
*
* Replace operation of resource: backend*
*
* @param[in] name ID of name
* @param[in] vip ID of vip
* @param[in] vport ID of vport
* @param[in] proto ID of proto
* @param[in] ip ID of ip
* @param[in] port ID of port
* @param[in] value backendbody object
*
* Responses:
*
*/
void
K8switchApiImpl::replace_k8switch_service_backend_by_id(const std::string &name, const std::string &vip, const uint16_t &vport, const ServiceProtoEnum &proto, const std::string &ip, const uint16_t &port, const ServiceBackendJsonObject &value) {
  auto k8switch = get_cube(name);
  auto service = k8switch->getService(vip, vport, proto);

  service->replaceBackend(ip, port, value);
}




/**
* @brief   Replace backend by ID
*
* Replace operation of resource: backend*
*
* @param[in] name ID of name
* @param[in] vip ID of vip
* @param[in] vport ID of vport
* @param[in] proto ID of proto
* @param[in] value backendbody object
*
* Responses:
*
*/
void
K8switchApiImpl::replace_k8switch_service_backend_list_by_id(const std::string &name, const std::string &vip, const uint16_t &vport, const ServiceProtoEnum &proto, const std::vector<ServiceBackendJsonObject> &value) {
  throw std::runtime_error("Method not supported");
}


#ifdef IMPLEMENT_POLYCUBE_GET_LIST
std::vector<nlohmann::fifo_map<std::string, std::string>> K8switchApiImpl::replace_k8switch_service_backend_list_by_id_get_list(const std::string &name, const std::string &vip, const uint16_t &vport, const ServiceProtoEnum &proto, const std::vector<ServiceBackendJsonObject> &value) {
  std::vector<nlohmann::fifo_map<std::string, std::string>> r;
}
#endif


/**
* @brief   Replace service by ID
*
* Replace operation of resource: service*
*
* @param[in] name ID of name
* @param[in] vip ID of vip
* @param[in] vport ID of vport
* @param[in] proto ID of proto
* @param[in] value servicebody object
*
* Responses:
*
*/
void
K8switchApiImpl::replace_k8switch_service_by_id(const std::string &name, const std::string &vip, const uint16_t &vport, const ServiceProtoEnum &proto, const ServiceJsonObject &value) {
  auto k8switch = get_cube(name);

  k8switch->replaceService(vip, vport, proto, value);
}




/**
* @brief   Replace service by ID
*
* Replace operation of resource: service*
*
* @param[in] name ID of name
* @param[in] value servicebody object
*
* Responses:
*
*/
void
K8switchApiImpl::replace_k8switch_service_list_by_id(const std::string &name, const std::vector<ServiceJsonObject> &value) {
  throw std::runtime_error("Method not supported");
}


#ifdef IMPLEMENT_POLYCUBE_GET_LIST
std::vector<nlohmann::fifo_map<std::string, std::string>> K8switchApiImpl::replace_k8switch_service_list_by_id_get_list(const std::string &name, const std::vector<ServiceJsonObject> &value) {
  std::vector<nlohmann::fifo_map<std::string, std::string>> r;
}
#endif


/**
* @brief   Update k8switch by ID
*
* Update operation of resource: k8switch*
*
* @param[in] name ID of name
* @param[in] value k8switchbody object
*
* Responses:
*
*/
void
K8switchApiImpl::update_k8switch_by_id(const std::string &name, const K8switchJsonObject &value) {
  auto k8switch = get_cube(name);

  k8switch->update(value);
}




/**
* @brief   Update client-subnet by ID
*
* Update operation of resource: client-subnet*
*
* @param[in] name ID of name
* @param[in] value Range of IPs of pods in this node
*
* Responses:
*
*/
void
K8switchApiImpl::update_k8switch_client_subnet_by_id(const std::string &name, const std::string &value) {
  auto k8switch = get_cube(name);

  k8switch->setClientSubnet(value);
}




/**
* @brief   Update cluster-ip-subnet by ID
*
* Update operation of resource: cluster-ip-subnet*
*
* @param[in] name ID of name
* @param[in] value Range of VIPs where clusterIP services are exposed
*
* Responses:
*
*/
void
K8switchApiImpl::update_k8switch_cluster_ip_subnet_by_id(const std::string &name, const std::string &value) {
  auto k8switch = get_cube(name);

  k8switch->setClusterIpSubnet(value);
}




/**
* @brief   Update fwd-table by ID
*
* Update operation of resource: fwd-table*
*
* @param[in] name ID of name
* @param[in] address ID of address
* @param[in] value fwd-tablebody object
*
* Responses:
*
*/
void
K8switchApiImpl::update_k8switch_fwd_table_by_id(const std::string &name, const std::string &address, const FwdTableJsonObject &value) {
  auto k8switch = get_cube(name);
  auto fwdTable = k8switch->getFwdTable(address);

  fwdTable->update(value);
}




/**
* @brief   Update fwd-table by ID
*
* Update operation of resource: fwd-table*
*
* @param[in] name ID of name
* @param[in] value fwd-tablebody object
*
* Responses:
*
*/
void
K8switchApiImpl::update_k8switch_fwd_table_list_by_id(const std::string &name, const std::vector<FwdTableJsonObject> &value) {
  throw std::runtime_error("Method not supported");
}


#ifdef IMPLEMENT_POLYCUBE_GET_LIST
std::vector<nlohmann::fifo_map<std::string, std::string>> K8switchApiImpl::update_k8switch_fwd_table_list_by_id_get_list(const std::string &name, const std::vector<FwdTableJsonObject> &value) {
  std::vector<nlohmann::fifo_map<std::string, std::string>> r;
}
#endif


/**
* @brief   Update mac by ID
*
* Update operation of resource: mac*
*
* @param[in] name ID of name
* @param[in] address ID of address
* @param[in] value Destination MAC address
*
* Responses:
*
*/
void
K8switchApiImpl::update_k8switch_fwd_table_mac_by_id(const std::string &name, const std::string &address, const std::string &value) {
  auto k8switch = get_cube(name);
  auto fwdTable = k8switch->getFwdTable(address);

  fwdTable->setMac(value);
}




/**
* @brief   Update port by ID
*
* Update operation of resource: port*
*
* @param[in] name ID of name
* @param[in] address ID of address
* @param[in] value Port where this entry is present
*
* Responses:
*
*/
void
K8switchApiImpl::update_k8switch_fwd_table_port_by_id(const std::string &name, const std::string &address, const std::string &value) {
  auto k8switch = get_cube(name);
  auto fwdTable = k8switch->getFwdTable(address);

  fwdTable->setPort(value);
}




/**
* @brief   Update k8switch by ID
*
* Update operation of resource: k8switch*
*
* @param[in] value k8switchbody object
*
* Responses:
*
*/
void
K8switchApiImpl::update_k8switch_list_by_id(const std::vector<K8switchJsonObject> &value) {
  throw std::runtime_error("Method not supported");
}


#ifdef IMPLEMENT_POLYCUBE_GET_LIST
std::vector<nlohmann::fifo_map<std::string, std::string>> K8switchApiImpl::update_k8switch_list_by_id_get_list(const std::vector<K8switchJsonObject> &value) {
  std::vector<nlohmann::fifo_map<std::string, std::string>> r;
}
#endif


/**
* @brief   Update loglevel by ID
*
* Update operation of resource: loglevel*
*
* @param[in] name ID of name
* @param[in] value Defines the logging level of a service instance, from none (OFF) to the most verbose (TRACE)
*
* Responses:
*
*/
void
K8switchApiImpl::update_k8switch_loglevel_by_id(const std::string &name, const K8switchLoglevelEnum &value) {
  auto k8switch = get_cube(name);

  k8switch->setLoglevel(value);
}




/**
* @brief   Update ports by ID
*
* Update operation of resource: ports*
*
* @param[in] name ID of name
* @param[in] portsName ID of ports_name
* @param[in] value portsbody object
*
* Responses:
*
*/
void
K8switchApiImpl::update_k8switch_ports_by_id(const std::string &name, const std::string &portsName, const PortsJsonObject &value) {
  auto k8switch = get_cube(name);
  auto ports = k8switch->getPorts(portsName);

  ports->update(value);
}




/**
* @brief   Update ports by ID
*
* Update operation of resource: ports*
*
* @param[in] name ID of name
* @param[in] value portsbody object
*
* Responses:
*
*/
void
K8switchApiImpl::update_k8switch_ports_list_by_id(const std::string &name, const std::vector<PortsJsonObject> &value) {
  throw std::runtime_error("Method not supported");
}


#ifdef IMPLEMENT_POLYCUBE_GET_LIST
std::vector<nlohmann::fifo_map<std::string, std::string>> K8switchApiImpl::update_k8switch_ports_list_by_id_get_list(const std::string &name, const std::vector<PortsJsonObject> &value) {
  std::vector<nlohmann::fifo_map<std::string, std::string>> r;
}
#endif


/**
* @brief   Update type by ID
*
* Update operation of resource: type*
*
* @param[in] name ID of name
* @param[in] portsName ID of ports_name
* @param[in] value Type of the LB port (e.g. NODEPORT or DEFAULT)
*
* Responses:
*
*/
void
K8switchApiImpl::update_k8switch_ports_type_by_id(const std::string &name, const std::string &portsName, const PortsTypeEnum &value) {
  auto k8switch = get_cube(name);
  auto ports = k8switch->getPorts(portsName);

  ports->setType(value);
}




/**
* @brief   Update backend by ID
*
* Update operation of resource: backend*
*
* @param[in] name ID of name
* @param[in] vip ID of vip
* @param[in] vport ID of vport
* @param[in] proto ID of proto
* @param[in] ip ID of ip
* @param[in] port ID of port
* @param[in] value backendbody object
*
* Responses:
*
*/
void
K8switchApiImpl::update_k8switch_service_backend_by_id(const std::string &name, const std::string &vip, const uint16_t &vport, const ServiceProtoEnum &proto, const std::string &ip, const uint16_t &port, const ServiceBackendJsonObject &value) {
  auto k8switch = get_cube(name);
  auto service = k8switch->getService(vip, vport, proto);
  auto backend = service->getBackend(ip, port);

  backend->update(value);
}




/**
* @brief   Update backend by ID
*
* Update operation of resource: backend*
*
* @param[in] name ID of name
* @param[in] vip ID of vip
* @param[in] vport ID of vport
* @param[in] proto ID of proto
* @param[in] value backendbody object
*
* Responses:
*
*/
void
K8switchApiImpl::update_k8switch_service_backend_list_by_id(const std::string &name, const std::string &vip, const uint16_t &vport, const ServiceProtoEnum &proto, const std::vector<ServiceBackendJsonObject> &value) {
  throw std::runtime_error("Method not supported");
}


#ifdef IMPLEMENT_POLYCUBE_GET_LIST
std::vector<nlohmann::fifo_map<std::string, std::string>> K8switchApiImpl::update_k8switch_service_backend_list_by_id_get_list(const std::string &name, const std::string &vip, const uint16_t &vport, const ServiceProtoEnum &proto, const std::vector<ServiceBackendJsonObject> &value) {
  std::vector<nlohmann::fifo_map<std::string, std::string>> r;
}
#endif


/**
* @brief   Update name by ID
*
* Update operation of resource: name*
*
* @param[in] name ID of name
* @param[in] vip ID of vip
* @param[in] vport ID of vport
* @param[in] proto ID of proto
* @param[in] ip ID of ip
* @param[in] port ID of port
* @param[in] value name
*
* Responses:
*
*/
void
K8switchApiImpl::update_k8switch_service_backend_name_by_id(const std::string &name, const std::string &vip, const uint16_t &vport, const ServiceProtoEnum &proto, const std::string &ip, const uint16_t &port, const std::string &value) {
  auto k8switch = get_cube(name);
  auto service = k8switch->getService(vip, vport, proto);
  auto backend = service->getBackend(ip, port);

  backend->setName(value);
}




/**
* @brief   Update weight by ID
*
* Update operation of resource: weight*
*
* @param[in] name ID of name
* @param[in] vip ID of vip
* @param[in] vport ID of vport
* @param[in] proto ID of proto
* @param[in] ip ID of ip
* @param[in] port ID of port
* @param[in] value Weight of the backend in the pool
*
* Responses:
*
*/
void
K8switchApiImpl::update_k8switch_service_backend_weight_by_id(const std::string &name, const std::string &vip, const uint16_t &vport, const ServiceProtoEnum &proto, const std::string &ip, const uint16_t &port, const uint16_t &value) {
  auto k8switch = get_cube(name);
  auto service = k8switch->getService(vip, vport, proto);
  auto backend = service->getBackend(ip, port);

  backend->setWeight(value);
}




/**
* @brief   Update service by ID
*
* Update operation of resource: service*
*
* @param[in] name ID of name
* @param[in] vip ID of vip
* @param[in] vport ID of vport
* @param[in] proto ID of proto
* @param[in] value servicebody object
*
* Responses:
*
*/
void
K8switchApiImpl::update_k8switch_service_by_id(const std::string &name, const std::string &vip, const uint16_t &vport, const ServiceProtoEnum &proto, const ServiceJsonObject &value) {
  auto k8switch = get_cube(name);
  auto service = k8switch->getService(vip, vport, proto);

  service->update(value);
}




/**
* @brief   Update service by ID
*
* Update operation of resource: service*
*
* @param[in] name ID of name
* @param[in] value servicebody object
*
* Responses:
*
*/
void
K8switchApiImpl::update_k8switch_service_list_by_id(const std::string &name, const std::vector<ServiceJsonObject> &value) {
  throw std::runtime_error("Method not supported");
}


#ifdef IMPLEMENT_POLYCUBE_GET_LIST
std::vector<nlohmann::fifo_map<std::string, std::string>> K8switchApiImpl::update_k8switch_service_list_by_id_get_list(const std::string &name, const std::vector<ServiceJsonObject> &value) {
  std::vector<nlohmann::fifo_map<std::string, std::string>> r;
}
#endif


/**
* @brief   Update name by ID
*
* Update operation of resource: name*
*
* @param[in] name ID of name
* @param[in] vip ID of vip
* @param[in] vport ID of vport
* @param[in] proto ID of proto
* @param[in] value Service name related to the backend server of the pool is connected to
*
* Responses:
*
*/
void
K8switchApiImpl::update_k8switch_service_name_by_id(const std::string &name, const std::string &vip, const uint16_t &vport, const ServiceProtoEnum &proto, const std::string &value) {
  auto k8switch = get_cube(name);
  auto service = k8switch->getService(vip, vport, proto);

  service->setName(value);
}




/**
* @brief   Update virtual-client-subnet by ID
*
* Update operation of resource: virtual-client-subnet*
*
* @param[in] name ID of name
* @param[in] value Range where client&#39;s IPs are mapped into
*
* Responses:
*
*/
void
K8switchApiImpl::update_k8switch_virtual_client_subnet_by_id(const std::string &name, const std::string &value) {
  auto k8switch = get_cube(name);

  k8switch->setVirtualClientSubnet(value);
}




}
}
}
}
