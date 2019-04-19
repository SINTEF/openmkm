/**
 *  @file ZerodReactor.h
 *  Header for all functions that read the reactor parameters 
 *  from YAML input file and run the given ZeroD Reactor type
 *  with the supplied parameters
 */

// This file is part of hetero_ct. See License.txt in the top level directory

#ifndef HTRCT_ZEROD_REACTOR_H
#define HTRCT_ZEROD_REACTOR_H

#include <vector>
#include <memory>
#include <yaml-cpp/yaml.h>
#include "cantera/IdealGasMix.h"
#include "cantera/InterfaceLatInt.h"

namespace HeteroCt
{

enum RctrType {
    BATCH,
    CSTR,
    PFR_0D,
    PFR
};

std::map<std::string, RctrType> RctrTypeMap = {{"batch", BATCH}, 
                                               {"cstr", CSTR}, 
                                               {"pfr_0d", PFR_0D}, 
                                               {"pfr", PFR}}; 



void run_0d_reactor(YAML::Node& tube_node,
                    std::shared_ptr<Cantera::IdealGasMix> gas, 
                    std::vector<std::shared_ptr<Cantera::InterfaceInteractions>> surfaces);

}

#endif 
