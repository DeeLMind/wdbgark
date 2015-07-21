/*
    * WinDBG Anti-RootKit extension
    * Copyright � 2013-2015  Vyacheslav Rusakoff
    * 
    * This program is free software: you can redistribute it and/or modify
    * it under the terms of the GNU General Public License as published by
    * the Free Software Foundation, either version 3 of the License, or
    * (at your option) any later version.
    * 
    * This program is distributed in the hope that it will be useful,
    * but WITHOUT ANY WARRANTY; without even the implied warranty of
    * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    * GNU General Public License for more details.
    * 
    * You should have received a copy of the GNU General Public License
    * along with this program.  If not, see <http://www.gnu.org/licenses/>.

    * This work is licensed under the terms of the GNU GPL, version 3.  See
    * the COPYING file in the top-level directory.
*/

//////////////////////////////////////////////////////////////////////////
//  Include this after "#define EXT_CLASS WDbgArk" only
//////////////////////////////////////////////////////////////////////////

#if _MSC_VER > 1000
#pragma once
#endif

#ifndef DEVICE_HPP_
#define DEVICE_HPP_

#include <engextcpp.hpp>

#include <map>
#include <sstream>
#include <memory>

#include "symcache.hpp"
#include "objhelper.hpp"

namespace wa {

class WDbgArkDevice {
 public:
    explicit WDbgArkDevice(const std::shared_ptr<WDbgArkSymCache> &sym_cache);
    WDbgArkDevice() = delete;

    bool IsInited(void) const { return m_inited; }

 private:
    bool m_inited;
    std::map<unsigned __int64, ExtRemoteTyped> m_devices_list;  // offset : object
    std::shared_ptr<WDbgArkSymCache>           m_sym_cache;
    std::unique_ptr<WDbgArkObjHelper>          m_obj_helper;
    //////////////////////////////////////////////////////////////////////////
    // output streams
    //////////////////////////////////////////////////////////////////////////
    std::stringstream out;
    std::stringstream warn;
    std::stringstream err;
};

}   // namespace wa

#endif  // DEVICE_HPP_