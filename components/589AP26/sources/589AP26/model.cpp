// Copyright 2022 ICS8-64 and ICS8-65
//
//    Licensed under the Apache License, Version 2.0 (the "License");
//    you may not use this file except in compliance with the License.
//    You may obtain a copy of the License at
//
//        http://www.apache.org/licenses/LICENSE-2.0
//
//    Unless required by applicable law or agreed to in writing, software
//    distributed under the License is distributed on an "AS IS" BASIS,
//    WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
//    See the License for the specific language governing permissions and
//    limitations under the License.

#include <589AP26/model.hpp>

INT I3000_589AP26_Model::isdigital(CHAR* pinname) {
    return 1;
}

VOID I3000_589AP26_Model::setup(IINSTANCE* instance, IDSIMCKT* dsim) {
    this->_instance = instance;

    _pin_DI0 = instance->getdsimpin("DI0", true);
    _pin_DI1 = instance->getdsimpin("DI1", true);
    _pin_DI2 = instance->getdsimpin("DI2", true);
    _pin_DI3 = instance->getdsimpin("DI3", true);
    _pin_DO0 = instance->getdsimpin("DO0", true);
    _pin_DO1 = instance->getdsimpin("DO1", true);
    _pin_DO2 = instance->getdsimpin("DO2", true);
    _pin_DO3 = instance->getdsimpin("DO3", true);
    _pin_DB0 = instance->getdsimpin("DB0", true);
    _pin_DB1 = instance->getdsimpin("DB1", true);
    _pin_DB2 = instance->getdsimpin("DB2", true);
    _pin_DB3 = instance->getdsimpin("DB3", true);
    _pin_DCE = instance->getdsimpin("DCE", true);
    _pin_CS  = instance->getdsimpin("CS", true);

    _pin_DB0->setstate(SLO);
    _pin_DB1->setstate(SLO);
    _pin_DB2->setstate(SLO);
    _pin_DB3->setstate(SLO);
    _pin_DO0->setstate(SLO);
    _pin_DO1->setstate(SLO);
    _pin_DO2->setstate(SLO);
    _pin_DO3->setstate(SLO);
}

VOID I3000_589AP26_Model::runctrl(RUNMODES mode) {}

VOID I3000_589AP26_Model::actuate(REALTIME time, ACTIVESTATE newstate) {}

BOOL I3000_589AP26_Model::indicate(REALTIME time, ACTIVEDATA* newstate) {
    return FALSE;
}

VOID I3000_589AP26_Model::simulate(ABSTIME time, DSIMMODES mode) {
    
}

VOID I3000_589AP26_Model::callback(ABSTIME time, EVENTID eventid) {}

VOID I3000_589AP26_Model::SET_STATE(bool condition, IDSIMPIN2 *pin, ABSTIME time) {
    condition ? pin->setstate(time, details::DELAY, SHI) : pin->setstate(time, details::DELAY, SLO);
}