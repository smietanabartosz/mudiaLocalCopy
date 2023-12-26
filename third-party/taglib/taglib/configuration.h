/***************************************************************************
    copyright            : (C) 2023 Mudita sp. z o.o.
 ***************************************************************************/

/***************************************************************************
 *   This library is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU Lesser General Public License version   *
 *   2.1 as published by the Free Software Foundation.                     *
 *                                                                         *
 *   This library is distributed in the hope that it will be useful, but   *
 *   WITHOUT ANY WARRANTY; without even the implied warranty of            *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU     *
 *   Lesser General Public License for more details.                       *
 *                                                                         *
 *   You should have received a copy of the GNU Lesser General Public      *
 *   License along with this library; if not, write to the Free Software   *
 *   Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA         *
 *   02110-1301  USA                                                       *
 *                                                                         *
 *   Alternatively, this file is available under the Mozilla Public        *
 *   License Version 1.1.  You may obtain a copy of the License at         *
 *   http://www.mozilla.org/MPL/                                           *
 ***************************************************************************/

#ifndef TAGLIB_CONFIGURATION_H
#define TAGLIB_CONFIGURATION_H

#include <limits>

namespace TagLib {

  struct Configuration
  {
    Configuration() :
      readOnly(false), limitMemoryUsage(false), maxTagSize(std::numeric_limits<std::size_t>::max())
    {}

    explicit Configuration(bool readOnly) :
      readOnly(readOnly), limitMemoryUsage(false), maxTagSize(std::numeric_limits<std::size_t>::max())
    {}

    Configuration(bool readOnly, bool limitMemoryUsage, std::size_t maxTagSize) :
      readOnly(readOnly), limitMemoryUsage(limitMemoryUsage), maxTagSize(maxTagSize)
    {}

    const bool readOnly;
    const bool limitMemoryUsage;
    const std::size_t maxTagSize;
  };

} // namespace TagLib

#endif
